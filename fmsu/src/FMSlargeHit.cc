#include "FMSlargeHit.hh"
#include "G4UnitsTable.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"

G4Allocator<FMSlargeHit> FMSlargeHitAllocator;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

FMSlargeHit::FMSlargeHit() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

FMSlargeHit::~FMSlargeHit() {}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

FMSlargeHit::FMSlargeHit(const FMSlargeHit& right)
  : G4VHit()
{
  trackID    = right.trackID;
  CellNb     = right.CellNb;
  edep       = right.edep;
  pos        = right.pos;
  mom        = right.mom;
  nCerenkov  = right.nCerenkov;
  isOptical  = right.isOptical;
  trackNo    = right.trackNo;
  cosTh      = right.cosTh;
  LocalTime  = right.LocalTime;
  GlobalTime = right.GlobalTime;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

const FMSlargeHit& FMSlargeHit::operator=(const FMSlargeHit& right)
{
  trackID   = right.trackID;
  CellNb = right.CellNb;
  edep      = right.edep;
  pos       = right.pos;
  mom       = right.mom;
  nCerenkov = right.nCerenkov;
  isOptical = right.isOptical;
  trackNo   = right.trackNo;
  cosTh     = right.cosTh;
  LocalTime = right.LocalTime;
  GlobalTime = right.GlobalTime;

  return *this;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4int FMSlargeHit::operator==(const FMSlargeHit& right) const
{
  return (this==&right) ? 1 : 0;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void FMSlargeHit::Draw()
{
  G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();
  if(pVVisManager)
  {
    G4Circle circle(pos);
    circle.SetScreenSize(2.);
    circle.SetFillStyle(G4Circle::filled);
    G4Colour colour(1.,0.,0.);
    G4VisAttributes attribs(colour);
    circle.SetVisAttributes(attribs);
    pVVisManager->Draw(circle);
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void FMSlargeHit::Print()
{
  G4cout << "  trackID: " << trackID << "  CellNb: " << CellNb
    << "  energy deposit: " << G4BestUnit(edep,"Energy")
    << "  position: " << G4BestUnit(pos,"Length") << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

