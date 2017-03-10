// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME SimGenDict

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
#include "Particle.h"
#include "HashKF.h"
#include "EventLoop.h"
#include "Analysis.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_Particle(void *p = 0);
   static void *newArray_Particle(Long_t size, void *p);
   static void delete_Particle(void *p);
   static void deleteArray_Particle(void *p);
   static void destruct_Particle(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Particle*)
   {
      ::Particle *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Particle >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Particle", ::Particle::Class_Version(), "Particle.h", 10,
                  typeid(::Particle), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Particle::Dictionary, isa_proxy, 4,
                  sizeof(::Particle) );
      instance.SetNew(&new_Particle);
      instance.SetNewArray(&newArray_Particle);
      instance.SetDelete(&delete_Particle);
      instance.SetDeleteArray(&deleteArray_Particle);
      instance.SetDestructor(&destruct_Particle);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Particle*)
   {
      return GenerateInitInstanceLocal((::Particle*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Particle*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_HashKF(void *p);
   static void deleteArray_HashKF(void *p);
   static void destruct_HashKF(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HashKF*)
   {
      ::HashKF *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HashKF >(0);
      static ::ROOT::TGenericClassInfo 
         instance("HashKF", ::HashKF::Class_Version(), "HashKF.h", 21,
                  typeid(::HashKF), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::HashKF::Dictionary, isa_proxy, 4,
                  sizeof(::HashKF) );
      instance.SetDelete(&delete_HashKF);
      instance.SetDeleteArray(&deleteArray_HashKF);
      instance.SetDestructor(&destruct_HashKF);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HashKF*)
   {
      return GenerateInitInstanceLocal((::HashKF*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::HashKF*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_EventLoop(void *p);
   static void deleteArray_EventLoop(void *p);
   static void destruct_EventLoop(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EventLoop*)
   {
      ::EventLoop *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EventLoop >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EventLoop", ::EventLoop::Class_Version(), "EventLoop.h", 19,
                  typeid(::EventLoop), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::EventLoop::Dictionary, isa_proxy, 4,
                  sizeof(::EventLoop) );
      instance.SetDelete(&delete_EventLoop);
      instance.SetDeleteArray(&deleteArray_EventLoop);
      instance.SetDestructor(&destruct_EventLoop);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EventLoop*)
   {
      return GenerateInitInstanceLocal((::EventLoop*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EventLoop*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_Analysis(void *p);
   static void deleteArray_Analysis(void *p);
   static void destruct_Analysis(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Analysis*)
   {
      ::Analysis *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Analysis >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Analysis", ::Analysis::Class_Version(), "Analysis.h", 28,
                  typeid(::Analysis), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Analysis::Dictionary, isa_proxy, 4,
                  sizeof(::Analysis) );
      instance.SetDelete(&delete_Analysis);
      instance.SetDeleteArray(&deleteArray_Analysis);
      instance.SetDestructor(&destruct_Analysis);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Analysis*)
   {
      return GenerateInitInstanceLocal((::Analysis*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Analysis*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr Particle::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Particle::Class_Name()
{
   return "Particle";
}

//______________________________________________________________________________
const char *Particle::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Particle*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Particle::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Particle*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Particle::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Particle*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Particle::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Particle*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr HashKF::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *HashKF::Class_Name()
{
   return "HashKF";
}

//______________________________________________________________________________
const char *HashKF::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HashKF*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int HashKF::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HashKF*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HashKF::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HashKF*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HashKF::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HashKF*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr EventLoop::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *EventLoop::Class_Name()
{
   return "EventLoop";
}

//______________________________________________________________________________
const char *EventLoop::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventLoop*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int EventLoop::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EventLoop*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EventLoop::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventLoop*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EventLoop::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EventLoop*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Analysis::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Analysis::Class_Name()
{
   return "Analysis";
}

//______________________________________________________________________________
const char *Analysis::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Analysis*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Analysis::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Analysis*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Analysis::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Analysis*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Analysis::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Analysis*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void Particle::Streamer(TBuffer &R__b)
{
   // Stream an object of class Particle.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Particle::Class(),this);
   } else {
      R__b.WriteClassBuffer(Particle::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Particle(void *p) {
      return  p ? new(p) ::Particle : new ::Particle;
   }
   static void *newArray_Particle(Long_t nElements, void *p) {
      return p ? new(p) ::Particle[nElements] : new ::Particle[nElements];
   }
   // Wrapper around operator delete
   static void delete_Particle(void *p) {
      delete ((::Particle*)p);
   }
   static void deleteArray_Particle(void *p) {
      delete [] ((::Particle*)p);
   }
   static void destruct_Particle(void *p) {
      typedef ::Particle current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Particle

//______________________________________________________________________________
void HashKF::Streamer(TBuffer &R__b)
{
   // Stream an object of class HashKF.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(HashKF::Class(),this);
   } else {
      R__b.WriteClassBuffer(HashKF::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_HashKF(void *p) {
      delete ((::HashKF*)p);
   }
   static void deleteArray_HashKF(void *p) {
      delete [] ((::HashKF*)p);
   }
   static void destruct_HashKF(void *p) {
      typedef ::HashKF current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HashKF

//______________________________________________________________________________
void EventLoop::Streamer(TBuffer &R__b)
{
   // Stream an object of class EventLoop.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EventLoop::Class(),this);
   } else {
      R__b.WriteClassBuffer(EventLoop::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_EventLoop(void *p) {
      delete ((::EventLoop*)p);
   }
   static void deleteArray_EventLoop(void *p) {
      delete [] ((::EventLoop*)p);
   }
   static void destruct_EventLoop(void *p) {
      typedef ::EventLoop current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EventLoop

//______________________________________________________________________________
void Analysis::Streamer(TBuffer &R__b)
{
   // Stream an object of class Analysis.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Analysis::Class(),this);
   } else {
      R__b.WriteClassBuffer(Analysis::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_Analysis(void *p) {
      delete ((::Analysis*)p);
   }
   static void deleteArray_Analysis(void *p) {
      delete [] ((::Analysis*)p);
   }
   static void destruct_Analysis(void *p) {
      typedef ::Analysis current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Analysis

namespace {
  void TriggerDictionaryInitialization_SimGenDict_Impl() {
    static const char* headers[] = {
"Particle.h",
"HashKF.h",
"EventLoop.h",
"Analysis.h",
0
    };
    static const char* includePaths[] = {
"/home/bsumma/builds/root60802-build/include",
"/home/bsumma/simulations/geant/fmsu/simgen/src/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "SimGenDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$Particle.h")))  Particle;
class __attribute__((annotate("$clingAutoload$HashKF.h")))  HashKF;
class __attribute__((annotate("$clingAutoload$EventLoop.h")))  EventLoop;
class __attribute__((annotate("$clingAutoload$Analysis.h")))  Analysis;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "SimGenDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "Particle.h"
#include "HashKF.h"
#include "EventLoop.h"
#include "Analysis.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"Analysis", payloadCode, "@",
"EventLoop", payloadCode, "@",
"HashKF", payloadCode, "@",
"Particle", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("SimGenDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_SimGenDict_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_SimGenDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_SimGenDict() {
  TriggerDictionaryInitialization_SimGenDict_Impl();
}
