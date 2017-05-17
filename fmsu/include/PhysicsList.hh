#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

class G4Cerenkov;
class G4Scintillation;
class G4OpAbsorption;
class G4OpRayleigh;
class G4OpBoundaryProcess;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

class PhysicsList: public G4VUserPhysicsList
{
  public:
    PhysicsList();
   ~PhysicsList();

  protected:
    // Construct particle and physics
    void ConstructParticle();
    void ConstructProcess();
 
    void SetCuts();

   
  protected:
    // these methods Construct particles 
    void ConstructBosons();
    void ConstructLeptons();
    void ConstructMesons();
    void ConstructBaryons();
    void ConstructOp();

  protected:
  // these methods Construct physics processes and register them
    void ConstructGeneral();
    void ConstructEM();
    void AddStepMax();    
  void SetNbOfPhotonsCerenkov(G4int);

  private:
  G4Cerenkov*          theCerenkovProcess;
  G4Scintillation*     theScintillationProcess;
  G4OpAbsorption*      theAbsorptionProcess;
  G4OpRayleigh*        theRayleighScatteringProcess;
  G4OpBoundaryProcess* theBoundaryProcess;
    
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

 
