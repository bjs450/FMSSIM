
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "StackingAction.hh"

#include "G4ParticleDefinition.hh"
#include "G4ParticleTypes.hh"
#include "G4Track.hh"
#include "G4ios.hh"
#include "Randomize.hh"
#include "CellGeo.hh"
#include "SteppingAction.hh"


#include "TrackInformation.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

StackingAction * stackaction;

  StackingAction::StackingAction()
: gammaCounter(0),otherCounter(0),statCounter(0),stage(0),cnt(0)
{
  G4double PcathEff0[32]=
  {0.025,0.030,0.038,0.046,0.054,0.062,0.070,0.081,0.092,
    0.103,0.114,0.125,0.136,0.147,0.158,0.169,0.180,0.188,
    0.193,0.200,0.195,0.190,0.178,0.166,0.145,
    0.114,0.082,0.055,0.028,0.005,0.004,0.002};

  G4double Esteps0[32]=  
  { 2.034*eV, 2.068*eV, 2.103*eV, 2.139*eV,
    2.177*eV, 2.216*eV, 2.256*eV, 2.298*eV,
    2.341*eV, 2.386*eV, 2.433*eV, 2.481*eV,
    2.532*eV, 2.585*eV, 2.640*eV, 2.697*eV,
    2.757*eV, 2.820*eV, 2.885*eV, 2.954*eV,
    3.026*eV, 3.102*eV, 3.181*eV, 3.265*eV,
    3.353*eV, 3.446*eV, 3.545*eV, 3.649*eV,
    3.760*eV, 3.877*eV, 4.002*eV, 4.136*eV };

  for(int n=0;n<32;n++)PcathEff[n]=PcathEff0[n];
  for(int n=0;n<32;n++)Esteps[n]=Esteps0[n];


  evnum_=-1; // incremented at ProcessNewEvent, first event is 0

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

StackingAction::~StackingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  G4ClassificationOfNewTrack
StackingAction::ClassifyNewTrack(const G4Track * aTrack)
{
  if(aTrack->GetParentID()==0)
  {
    TrackInformation* trackInfo = new TrackInformation(aTrack);
    trackInfo->SetTrackingStatus(1);
    G4Track* theTrack = (G4Track*)aTrack;
    theTrack->SetUserInformation(trackInfo);
    return fUrgent; //Primary particles always put into UrgentStack
  }
  if(aTrack->GetDefinition() == G4OpticalPhoton::OpticalPhotonDefinition())
  { 
    gammaCounter++;
    G4double ene=aTrack->GetTotalEnergy();

    G4int ebin=0;
    G4int jbin=0;
    while(ebin==0 && jbin<32)
    {
      if(ene<Esteps[jbin]){ebin=jbin;};
      jbin++;
    }

    G4double rnum=G4UniformRand();

    G4bool cut_cathode_eff=true;
    if(cut_cathode_eff)
    {
      if(ebin<1 || ebin>31){ return fKill;}
      if( rnum > PcathEff[ebin])
      {
	return fKill; //cut based on cathode efficieny before tracking begins. Note that energy is not stored by default, need to impliment a method if you want to check total energy
      }
    }
  }

  if(stage==0)
  {
    return fWaiting;
  }
  else
  {
    return fUrgent;
  }

}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void StackingAction::NewStage()
{
  stage++;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void StackingAction::PrepareNewEvent()
{
  stage=0;
  gammaCounter = 0;
  evnum_++;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
