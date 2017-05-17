#include "FMSsmall.hh"

#include "FMSsmallHit.hh"
#include "G4HCofThisEvent.hh"
#include "G4Step.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "G4Track.hh"
#include "G4ProcessManager.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "CellGeo.hh"
#include "TrackInformation.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

FMSsmall::FMSsmall(G4String name)
  :G4VSensitiveDetector(name)
{
  G4String HCname;
  collectionName.insert(HCname="FMSsmallColl");
  HCID = -1;
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

FMSsmall::~FMSsmall(){ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void FMSsmall::Initialize(G4HCofThisEvent* HCE)
{
  hitsCollection = new FMSsmallHitsCollection
    (SensitiveDetectorName,collectionName[0]);
  if(HCID<0)
  {
    HCID = G4SDManager::GetSDMpointer()->GetCollectionID(hitsCollection);
  };
  HCE->AddHitsCollection(HCID,hitsCollection);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4bool FMSsmall::ProcessHits(G4Step* aStep,G4TouchableHistory*)
{ 
  G4bool Optical=(aStep->GetTrack()->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition());  

  G4bool isHit=true;

  if(Optical && (aStep->GetTrack()->GetVolume()->GetName()=="physiPhotoCS"))
  {
    isHit=false;
    return false;
  }

  G4TouchableHandle theTouchable =aStep->GetPreStepPoint()->GetTouchableHandle();
  //  G4int copyNo = theTouchable->GetCopyNumber();
  G4int motherCopyNo = theTouchable->GetCopyNumber(2);
  //  G4int gmotherCopyNo= theTouchable->GetCopyNumber(3);

  G4StepPoint* 	sPoint=aStep->GetPreStepPoint();

  G4int ecopy=motherCopyNo;

  G4double TrackKEnergy=aStep->GetTrack()->GetKineticEnergy();

  //BS CHANGE, not sure if this does anything at curent moment. Check on this
  aStep->GetTrack()->SetBelowThresholdFlag();

  FMSsmallHit* newHit = new FMSsmallHit();
  newHit->SetTrackID  (aStep->GetTrack()->GetTrackID());
  newHit->SetCellNb(ecopy);
  newHit->SetIsOptical(Optical);
  newHit->SetIsHit(isHit);

  newHit->SetGlobalTime(sPoint->GetGlobalTime());
  newHit->SetLocalTime(sPoint->GetLocalTime());
  newHit->SetKinE(TrackKEnergy);
  newHit->SetTotalTrackLength( aStep->GetTrack()->GetTrackLength() /cm );

  newHit->SetTdep(aStep->GetTrack()->GetTotalEnergy());
  newHit->SetEdep(aStep->GetTotalEnergyDeposit());
  newHit->SetKinE(aStep->GetPreStepPoint()->GetKineticEnergy());
  newHit->SetnCerenkov(0);
  newHit->SetPos(aStep->GetTrack()->GetVertexPosition());
  newHit->SetMom(aStep->GetTrack()->GetVertexMomentumDirection());
  newHit->SetName(aStep->GetTrack()->GetParticleDefinition()->GetParticleName());
  aStep->GetTrack()->SetGoodForTrackingFlag(false);
  newHit->SetCosTh(aStep->GetTrack()->GetVertexMomentumDirection().cosTheta());

  newHit->SetTrackNo(aStep->GetTrack()->GetTrackID());

  TrackInformation * info=(TrackInformation*) (aStep->GetTrack()->GetUserInformation());

  if(info)
  {
    newHit->SetOriginalID(info->GetOriginalTrackID());
    newHit->SetAncestors(info->particle_ances);
  } 

  hitsCollection->insert( newHit );

  return true;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void FMSsmall::EndOfEvent(G4HCofThisEvent*)
{
  if (verboseLevel>0) 
  { 
    G4int NbHits = hitsCollection->entries();
    G4cout << "\n-------->Hits Collection: in this event they are " << NbHits 
      << " hits in the small FMS cells: " << G4endl;
    //for (G4int i=0;i<NbHits;i++) (*hitsCollection)[i]->Print(); //++
  } 
}

//....oooOO0OOooo........oooOO0OOxsooo........oooOO0OOooo........oooOO0OOooo......

