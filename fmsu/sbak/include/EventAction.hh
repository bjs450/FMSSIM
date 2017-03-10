#ifndef EventAction_h
#define EventAction_h 1
#include "TString.h"
#include "TH1F.h"
#include "TFile.h"
#include "TTree.h"
#include "G4UserEventAction.hh"
#include "G4SDManager.hh"
#include "G4RunManager.hh"
#include "G4HCofThisEvent.hh"
#include "FMSlargeHit.hh"
#include "FMSsmallHit.hh"
#include "CellGeo.hh"
#include "StackingAction.hh"
#include "PostSim.hh"

class G4Event;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class EventAction : public G4UserEventAction
{
  public:
  EventAction(FILE* fp0,TFile* p0file,TTree* geotr);
  ~EventAction();

  public:
    void BeginOfEventAction(const G4Event*);
    void EndOfEventAction(const G4Event*);
    FILE* fp;
    TString hi;
    TH1F* ph1EL;
    TH1F* ph1ES;
    TH1F* zPhL;
    TH1F* zPhS;
    TFile* pFile;
    TTree* pgeotr;
    int evnum_;
    int rowg;
    int colg;
    int nstbg;
    float gaing;
    float corrg;

    PostSim * pss;

  private:
    G4int collectionIDL;
    G4int collectionIDS;
    G4int verboseLevel;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
