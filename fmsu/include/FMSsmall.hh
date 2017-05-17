#ifndef FMSsmall_h
#define FMSsmall_h 1

#include "G4VSensitiveDetector.hh"
#include "FMSsmallHit.hh"

class G4Step;
class G4HCofThisEvent;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class FMSsmall : public G4VSensitiveDetector
{
  public:
      FMSsmall(G4String);
     ~FMSsmall();

      void Initialize(G4HCofThisEvent*);
      G4bool ProcessHits(G4Step*, G4TouchableHistory*);
      void EndOfEvent(G4HCofThisEvent*);

  private:
      FMSsmallHitsCollection* hitsCollection;
      G4int HCID;
      

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

