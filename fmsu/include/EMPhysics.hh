#ifndef EMPhysics_h
#define EMPhysics_h 1

#include "G4VPhysicsConstructor.hh"


class EMPhysics : public G4VPhysicsConstructor
{
  public:
    EMPhysics(const G4String& name ="EM");
    ~EMPhysics();

  public:
    // This method will be invoked in the Construct() method.
    // each particle type will be instantiated
    virtual void ConstructParticle(){;};

    // This method will be invoked in the Construct() method.
    // each physics process will be instantiated and
    // registered to the process manager of each particle type
    virtual void ConstructProcess();

  protected:

};

#endif
