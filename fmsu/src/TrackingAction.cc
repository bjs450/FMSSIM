#include "TrackingAction.hh"
#include "G4TrackingManager.hh"
#include "G4Track.hh"
#include "Trajectory.hh"
#include "TrackInformation.hh"
#include "FMSlarge.hh"
#include "FMSlargeHit.hh"
#include <vector>
#include <iostream>

TrackingAction::TrackingAction()
{
}

void TrackingAction::PreUserTrackingAction(const G4Track* aTrack)
{
  TrackInformation* trackInfo = (TrackInformation*)(aTrack->GetUserInformation());

  if(!trackInfo) 
  {
    G4cout<<"ERROR: Pre Trackinfo returned zero "<<G4endl;
    fpTrackingManager->SetStoreTrajectory(false); 
  }
  else
  {
    if(trackInfo->GetTrackingStatus() > 0)
    {
      fpTrackingManager->SetStoreTrajectory(true);
      fpTrackingManager->SetTrajectory(new Trajectory(aTrack));
      trackInfo->SetSourceTrackInformation(aTrack);
    }
    else
    { 
      fpTrackingManager->SetStoreTrajectory(false); }
  };
}

void TrackingAction::PostUserTrackingAction(const G4Track* aTrack)
{
  G4TrackVector* secondaries = fpTrackingManager->GimmeSecondaries();
  Trajectory *myTrajectory =(Trajectory*) fpTrackingManager->GimmeTrajectory();
  TrackInformation* info = (TrackInformation*)(aTrack->GetUserInformation());

  /*
  if (info) 
  {
    if(info->GetOrigNstb() != 0 && myTrajectory)
    {
      myTrajectory->SetNstb( (Int_t) info->GetOrigNstb() );
      myTrajectory->SetRow( (Int_t) info->GetOrigRow() );
      myTrajectory->SetCol( (Int_t) info->GetOrigCol() );
    }
  }
  */
  if(secondaries)
  {
    size_t nSeco = secondaries->size(); 
    for(size_t i=0;i<nSeco;i++)
    { 
      TrackInformation* infoNew = new TrackInformation(info);

      ////////Turn secondary tracking on only if daughter of primary uncharged meson 
      if(nSeco>0 && !( aTrack->GetParticleDefinition()->GetParticleType().compareTo("meson") ) && aTrack->GetParentID()==0 && aTrack->GetParticleDefinition()->GetPDGCharge()==0)
      {
	infoNew->SetTrackingStatus(1);
      }
      else
      {
	infoNew->SetTrackingStatus(0);
      }
      //////////////////////////////////

      if(info->GetTrackingStatus()==1)
      {
	(infoNew->particle_ances).push_back(aTrack->GetTrackID());
      }

      //BS See Steeping action for description of what this is used for/why needed
//      infoNew->SetHasCoordinates( info->GetHasCoordinates() );

      (*secondaries)[i]->SetUserInformation(infoNew);
    }
  }
}
