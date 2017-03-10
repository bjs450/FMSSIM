// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME G4QTDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "G4QT.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_G4QT(void *p = 0);
   static void *newArray_G4QT(Long_t size, void *p);
   static void delete_G4QT(void *p);
   static void deleteArray_G4QT(void *p);
   static void destruct_G4QT(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::G4QT*)
   {
      ::G4QT *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::G4QT >(0);
      static ::ROOT::TGenericClassInfo 
         instance("G4QT", ::G4QT::Class_Version(), "G4QT.h", 6,
                  typeid(::G4QT), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::G4QT::Dictionary, isa_proxy, 4,
                  sizeof(::G4QT) );
      instance.SetNew(&new_G4QT);
      instance.SetNewArray(&newArray_G4QT);
      instance.SetDelete(&delete_G4QT);
      instance.SetDeleteArray(&deleteArray_G4QT);
      instance.SetDestructor(&destruct_G4QT);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::G4QT*)
   {
      return GenerateInitInstanceLocal((::G4QT*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::G4QT*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr G4QT::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *G4QT::Class_Name()
{
   return "G4QT";
}

//______________________________________________________________________________
const char *G4QT::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::G4QT*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int G4QT::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::G4QT*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *G4QT::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::G4QT*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *G4QT::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::G4QT*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void G4QT::Streamer(TBuffer &R__b)
{
   // Stream an object of class G4QT.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(G4QT::Class(),this);
   } else {
      R__b.WriteClassBuffer(G4QT::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_G4QT(void *p) {
      return  p ? new(p) ::G4QT : new ::G4QT;
   }
   static void *newArray_G4QT(Long_t nElements, void *p) {
      return p ? new(p) ::G4QT[nElements] : new ::G4QT[nElements];
   }
   // Wrapper around operator delete
   static void delete_G4QT(void *p) {
      delete ((::G4QT*)p);
   }
   static void deleteArray_G4QT(void *p) {
      delete [] ((::G4QT*)p);
   }
   static void destruct_G4QT(void *p) {
      typedef ::G4QT current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::G4QT

namespace ROOT {
   static TClass *vectorlEG4QTgR_Dictionary();
   static void vectorlEG4QTgR_TClassManip(TClass*);
   static void *new_vectorlEG4QTgR(void *p = 0);
   static void *newArray_vectorlEG4QTgR(Long_t size, void *p);
   static void delete_vectorlEG4QTgR(void *p);
   static void deleteArray_vectorlEG4QTgR(void *p);
   static void destruct_vectorlEG4QTgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<G4QT>*)
   {
      vector<G4QT> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<G4QT>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<G4QT>", -2, "vector", 214,
                  typeid(vector<G4QT>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEG4QTgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<G4QT>) );
      instance.SetNew(&new_vectorlEG4QTgR);
      instance.SetNewArray(&newArray_vectorlEG4QTgR);
      instance.SetDelete(&delete_vectorlEG4QTgR);
      instance.SetDeleteArray(&deleteArray_vectorlEG4QTgR);
      instance.SetDestructor(&destruct_vectorlEG4QTgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<G4QT> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<G4QT>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEG4QTgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<G4QT>*)0x0)->GetClass();
      vectorlEG4QTgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEG4QTgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEG4QTgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<G4QT> : new vector<G4QT>;
   }
   static void *newArray_vectorlEG4QTgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<G4QT>[nElements] : new vector<G4QT>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEG4QTgR(void *p) {
      delete ((vector<G4QT>*)p);
   }
   static void deleteArray_vectorlEG4QTgR(void *p) {
      delete [] ((vector<G4QT>*)p);
   }
   static void destruct_vectorlEG4QTgR(void *p) {
      typedef vector<G4QT> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<G4QT>

namespace {
  void TriggerDictionaryInitialization_G4QTDict_Impl() {
    static const char* headers[] = {
"G4QT.h",
0
    };
    static const char* includePaths[] = {
"/home/bsumma/builds/root60802-build/include",
"/home/bsumma/simulations/geant/fmsu/myRootClass/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "G4QTDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$G4QT.h")))  G4QT;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "G4QTDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "G4QT.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"G4QT", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("G4QTDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_G4QTDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_G4QTDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_G4QTDict() {
  TriggerDictionaryInitialization_G4QTDict_Impl();
}
