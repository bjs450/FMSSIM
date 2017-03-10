#ifndef FMSlarge_h
#define FMSlarge_h 1

#include "G4VSensitiveDetector.hh"
#include "FMSlargeHit.hh"
#include "CellGeo.hh"

class G4Step;
class G4HCofThisEvent;


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class FMSlarge : public G4VSensitiveDetector
{
  public:
      FMSlarge(G4String);
     ~FMSlarge();

      void Initialize(G4HCofThisEvent*);
      G4bool ProcessHits(G4Step*, G4TouchableHistory*);
      void EndOfEvent(G4HCofThisEvent*);

  private:
      FMSlargeHitsCollection* hitsCollection;
      G4int HCID;
      

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

