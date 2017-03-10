#include "EventAction.hh"
#include "FMSlargeHit.hh"
#include "FMSsmallHit.hh"
#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4TrajectoryContainer.hh"
#include "Trajectory.hh"
#include "G4ios.hh"
#include "stdio.h"
#include "TTree.h"



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::EventAction(FILE* fp0,TFile* tf0, TTree* geotr)
{
  fp=fp0;hi="hi";
  G4cout<<hi<<" from Event Action Construction"<<G4endl;
  ph1EL=0;
  ph1ES=0;
  pFile=tf0;
  zPhL=0;
  zPhS=0;
  pgeotr=geotr;

  pss = new PostSim();

  pgeotr->Branch("row",&rowg,"row/I");
  pgeotr->Branch("col",&colg,"col/I");
  pgeotr->Branch("nstb",&nstbg,"nstb/I");
  pgeotr->Branch("gain",&gaing,"gain/F");
  pgeotr->Branch("corr",&corrg,"corr/F");

  /*
  G4String colName;
  G4SDManager * SDman = G4SDManager::GetSDMpointer();
  collectionIDL = SDman->GetCollectionID(colName="FMSlargeColl");
  collectionIDS = SDman->GetCollectionID(colName="FMSsmallColl");
  printf("[+] collectionIDL @ %p: %d\n",(void*) &collectionIDL,collectionIDL);
  printf("[+] collectionIDS @ %p: %d\n",(void*) &collectionIDS,collectionIDS);
  */

  //evnumL_=-1; // these are incremented at beginning
  //evnumS_=-1; //   of EndOfEventAction method (before gtre* filled)
  evnum_=-1;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

EventAction::~EventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event*)
{
  fprintf(fp,"begin event \n");
  /*
  static int calledFirst = 1;
  if(calledFirst)
  {
    printf("<<<>>> EventAction::BeginOfEventAction called\n");
    calledFirst = 0;
  };
  */
  G4cout << ">>> begin event "<< G4endl;
  if(ph1EL)delete ph1EL;
  if(ph1ES)delete ph1ES;
  ph1EL=new TH1F("ph1EL","ph1EL",100,0,10);
  ph1ES=new TH1F("ph1ES","ph1ES",100,0,10);
  if(zPhL)delete zPhL;
  if(zPhS)delete zPhS;
  zPhL=new TH1F("zPhL","zPhL",30,-25,25);
  zPhS=new TH1F("zPhS","zPhS",30,-25,25);
  // break
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* evt)
{
  evnum_++;
  pFile->cd();
  G4int event_id = evt->GetEventID();

  // get number of stored trajectories
  //
  G4TrajectoryContainer* trajectoryContainer = evt->GetTrajectoryContainer();
  G4int n_trajectories = 0;
  if (trajectoryContainer) n_trajectories = trajectoryContainer->entries();

  // periodic printing
  //
  if (event_id < 100 || event_id%100 == 0) {
    G4cout << ">>> Event " << evt->GetEventID() << G4endl;
    G4cout << "    " << n_trajectories 
      << " trajectories stored in this event." << G4endl;
  }

  G4String colName;
  G4SDManager * SDman = G4SDManager::GetSDMpointer();
  collectionIDL = SDman->GetCollectionID(colName="FMSlargeColl");
  collectionIDS = SDman->GetCollectionID(colName="FMSsmallColl");
  printf("[+] collectionIDL @ %p: %d\n",(void*) &collectionIDL,collectionIDL);
  printf("[+] collectionIDS @ %p: %d\n",(void*) &collectionIDS,collectionIDS);

  G4HCofThisEvent* HCofEvent = evt->GetHCofThisEvent();
  FMSlargeHitsCollection* myCollectionL = 0;
  FMSsmallHitsCollection* myCollectionS = 0;
  if(HCofEvent)
  {
    //printf("<<<>>> Getting Collections...\n");
    myCollectionL = (FMSlargeHitsCollection*)(HCofEvent->GetHC(collectionIDL));
    myCollectionS = (FMSsmallHitsCollection*)(HCofEvent->GetHC(collectionIDS));
  }
  G4cout<<"Try to Print Hits"<<G4endl;
  printf("[+] myCollectionL @ %p\n",(void*) myCollectionL);
  printf("[+] myCollectionS @ %p\n",(void*) myCollectionS);
  G4cout<<"name (large) = "<< myCollectionL->GetName()<<G4endl;
  G4cout<<"name (small) = "<< myCollectionS->GetName()<<G4endl;

  G4double FpdE[1000];
  G4int nCer[1000];
  G4double Esum,nCerenkov;
  G4int nL,nS;

  /* large cell action */
  if(myCollectionL)
  {
    nL=myCollectionL->entries();
    G4cout<<"Try to Print " << nL <<" Large Cell Hits"<<G4endl;
    for(G4int jj=0;jj<1000;jj++){FpdE[jj]=0;nCer[jj]=0;};
    Esum=0; 
    nCerenkov=0;
    for(G4int jj=0;jj<nL;jj++)
    {
      pss->isOpt=0;
      if((*myCollectionL)[jj]->IsOptical())pss->isOpt=1;     
      pss->isHit=0;
      if((*myCollectionL)[jj]->IsHit())pss->isHit=1;

      int jc=(*myCollectionL)[jj]->GetCellNb();
      pss->nstb = cellgeo->GetNstb(jc,1);
      pss->row = cellgeo->GetRow(jc,1);
      pss->col = cellgeo->GetCol(jc,1);
      pss->gain = cellgeo->GetGain(pss->nstb,pss->row,pss->col);
      pss->corr = cellgeo->GetCorr(pss->nstb,pss->row,pss->col);
      pss->en = (*myCollectionL)[jj]->GetEdep()/GeV;
      pss->tot_en = (*myCollectionL)[jj]->GetTdep()/GeV;
      pss->kin = (*myCollectionL)[jj]->GetKinE()/GeV;
      if(pss->isOpt==0) FpdE[jc]+=pss->en;
      ph1EL->Fill((*myCollectionL)[jj]->GetEdep()/eV);
      if(pss->isOpt==1) nCer[jc]+=1;
      Esum+=(*myCollectionL)[jj]->GetEdep()/GeV;
      if(pss->isOpt==1)nCerenkov+=1;
      pss->verx = (*myCollectionL)[jj]->GetPos().x()/cm;
      pss->very = (*myCollectionL)[jj]->GetPos().y()/cm;
      pss->verz = (*myCollectionL)[jj]->GetPos().z()/cm;
      pss->px = (*myCollectionL)[jj]->GetMom().x();
      pss->py = (*myCollectionL)[jj]->GetMom().y();
      pss->pz = (*myCollectionL)[jj]->GetMom().z();
      sprintf(pss->name,"%s",(*myCollectionL)[jj]->GetName().data());

      zPhL->Fill(pss->verz);

      pss->trNum = (*myCollectionL)[jj]->GetTrackNo();
      pss->cosTh = (*myCollectionL)[jj]->GetCosTh();
      pss->NCer = (*myCollectionL)[jj]->GetnCerenkov();
      pss->gtime = (*myCollectionL)[jj]->GetGlobalTime()/ns;
      pss->ltime = (*myCollectionL)[jj]->GetLocalTime()/ns;

      pss->evnum = evnum_;
      pss->FillMatrices();

    };
    for(G4int j1=0;j1<7;j1++)
    {
      for(G4int j2=0;j2<7;j2++)
      {
        G4int  jj=j1*7+j2;
        G4double BremWtE=1.*nCer[jj]/(nCerenkov+.01);
        G4cout<< jj<<" ->"<<BremWtE<<"(d="<<FpdE[jj]<<" c="<<nCer[jj]/913.<<") ";
        //	 fprintf(fp,"%f,",FpdE[jj]);
        fprintf(fp,"%f,",BremWtE);
      };
      G4cout<<G4endl;
    };
    G4cout<< "Esum=->"<<Esum<<" Ncerenkov="<<nCerenkov<<"("<<1.*nCerenkov/Esum<<" photons/GeV)"<<G4endl;
    fprintf(fp,"\nEsum=%f \n",Esum);
    if(evnum_==1)
    {
      ph1EL->Write();
      zPhL->Write();
      char fadc_write[4][16];
      char edep_write[4][16];
      char hits_write[4][16];
      char nopt_write[4][16];
      char ncer_write[4][16];
      for(int n=0; n<4; n++)
      {
        sprintf(fadc_write[n],"fadc_arr_n%d",n+1);
        sprintf(edep_write[n],"edep_arr_n%d",n+1);
        sprintf(hits_write[n],"hits_arr_n%d",n+1);
        sprintf(nopt_write[n],"nopt_arr_n%d",n+1);
        sprintf(ncer_write[n],"ncer_arr_n%d",n+1);
        /*
        pss->fadc_arr[n]->Write(fadc_write[n],TObject::kSingleKey);
        pss->edep_arr[n]->Write(edep_write[n],TObject::kSingleKey);
        pss->hits_arr[n]->Write(hits_write[n],TObject::kSingleKey);
        pss->nopt_arr[n]->Write(nopt_write[n],TObject::kSingleKey);
        pss->ncer_arr[n]->Write(ncer_write[n],TObject::kSingleKey);
        */
      };
    };
    if(Esum>60) printf("unusually high edep (large): evnum=%d edep=%f\n",evnum_,Esum);
  };

  /* small cell action */
  if(myCollectionS)
  {
    nS=myCollectionS->entries();
    G4cout<<"Try to Print " << nS <<" Small Cell Hits"<<G4endl;
    for(G4int jj=0;jj<1000;jj++){FpdE[jj]=0;nCer[jj]=0;};
    Esum=0; 
    nCerenkov=0;
    for(G4int jj=0;jj<nS;jj++)
    {
      pss->isOpt = 0;
      if((*myCollectionS)[jj]->IsOptical())pss->isOpt = 1;     
      int jc=(*myCollectionS)[jj]->GetCellNb();
      pss->isHit = 0;
      if((*myCollectionS)[jj]->IsHit())pss->isHit = 1;

      pss->nstb = cellgeo->GetNstb(jc,0);
      pss->row = cellgeo->GetRow(jc,0);
      pss->col = cellgeo->GetCol(jc,0);
      pss->gain = cellgeo->GetGain(pss->nstb,pss->row,pss->col);
      pss->corr = cellgeo->GetCorr(pss->nstb,pss->row,pss->col);
      pss->en = (*myCollectionS)[jj]->GetEdep()/GeV;
      pss->tot_en = (*myCollectionS)[jj]->GetTdep()/GeV;
      pss->kin = (*myCollectionS)[jj]->GetKinE()/GeV;
      if(pss->isOpt==0) FpdE[jc]+=pss->en;
      ph1ES->Fill((*myCollectionS)[jj]->GetEdep()/eV);
      if(pss->isOpt==1) nCer[jc]+=1;
      Esum+=(*myCollectionS)[jj]->GetEdep()/GeV;
      if(pss->isOpt==1)nCerenkov+=1;
      pss->verx = (*myCollectionS)[jj]->GetPos().x()/cm;
      pss->very = (*myCollectionS)[jj]->GetPos().y()/cm;
      pss->verz = (*myCollectionS)[jj]->GetPos().z()/cm;
      pss->px = (*myCollectionS)[jj]->GetMom().x();
      pss->py = (*myCollectionS)[jj]->GetMom().y();
      pss->pz = (*myCollectionS)[jj]->GetMom().z();
      sprintf(pss->name,"%s",(*myCollectionS)[jj]->GetName().data());
      zPhS->Fill(pss->verz);

      pss->trNum = (*myCollectionS)[jj]->GetTrackNo();
      pss->cosTh = (*myCollectionS)[jj]->GetCosTh();
      pss->NCer = (*myCollectionS)[jj]->GetnCerenkov();
      pss->gtime = (*myCollectionS)[jj]->GetGlobalTime()/ns;
      pss->ltime = (*myCollectionS)[jj]->GetLocalTime()/ns;

      pss->evnum = evnum_;
      pss->FillMatrices();

    };
    for(G4int j1=0;j1<7;j1++)
    {
      for(G4int j2=0;j2<7;j2++)
      {
        G4int  jj=j1*7+j2;
        G4double BremWtE=1.*nCer[jj]/(nCerenkov+.01);
        G4cout<< jj<<" ->"<<BremWtE<<"(d="<<FpdE[jj]<<" c="<<nCer[jj]/913.<<") ";
        //	 fprintf(fp,"%f,",FpdE[jj]);
        fprintf(fp,"%f,",BremWtE);
      };
      G4cout<<G4endl;
    };
    G4cout<< "Esum=->"<<Esum<<" Ncerenkov="<<nCerenkov<<"("<<1.*nCerenkov/Esum<<" photons/GeV)"<<G4endl;
    fprintf(fp,"\nEsum=%f \n",Esum);
    if(evnum_==1)
    {
      ph1ES->Write();
      zPhS->Write();
      char fadc_write[4][16];
      char edep_write[4][16];
      char hits_write[4][16];
      char nopt_write[4][16];
      char ncer_write[4][16];
      char adc_write[4][16];
      for(int n=0; n<4; n++)
      {
        sprintf(fadc_write[n],"fadc_arr_n%d",n+1);
        sprintf(edep_write[n],"edep_arr_n%d",n+1);
        sprintf(hits_write[n],"hits_arr_n%d",n+1);
        sprintf(nopt_write[n],"nopt_arr_n%d",n+1);
        sprintf(ncer_write[n],"ncer_arr_n%d",n+1);
        sprintf(adc_write[n],"adc_arr_n%d",n+1);
        /*
        pss->fadc_arr[n]->Write(fadc_write[n],TObject::kSingleKey);
        pss->edep_arr[n]->Write(edep_write[n],TObject::kSingleKey);
        pss->hits_arr[n]->Write(hits_write[n],TObject::kSingleKey);
        pss->nopt_arr[n]->Write(nopt_write[n],TObject::kSingleKey);
        pss->ncer_arr[n]->Write(ncer_write[n],TObject::kSingleKey);
        pss->adc_arr[n]->Write(adc_write[n],TObject::kSingleKey);
        */
      };
    };
    if(Esum>60) printf("unusually high edep (small): evnum=%d edep=%f\n",evnum_,Esum);
  };

  // get HT and digitise; fill ttr & hsimu; then zero matrices
  pss->GetHT();
  printf("HT (n%d,r%d,c%d)\n",pss->nstb_ht,pss->row_ht,pss->col_ht);
  for(int n=0; n<4; n++) pss->Digitise(n);
  pss->ZeroMatrices();
  


  G4int lim=476;
  G4int det=0;

  while(1)
  {
    for(G4int i=0; i<lim; i++)
    {
      nstbg = cellgeo->GetNstb(i,det);
      rowg = cellgeo->GetRow(i,det);
      colg = cellgeo->GetCol(i,det);
      gaing = cellgeo->GetGain(nstbg,rowg,colg);
      corrg = cellgeo->GetCorr(nstbg,rowg,colg);
      pgeotr->Fill();
    };
    if(lim==476) { lim=788; det=1; }
    else if(lim==788) break;
    else break;
  };

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
