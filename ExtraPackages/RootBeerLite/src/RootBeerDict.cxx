// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME srcdIRootBeerDict

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
#include "include/TRootBeer.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_TRootBeer(void *p = 0);
   static void *newArray_TRootBeer(Long_t size, void *p);
   static void delete_TRootBeer(void *p);
   static void deleteArray_TRootBeer(void *p);
   static void destruct_TRootBeer(void *p);
   static void streamer_TRootBeer(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRootBeer*)
   {
      ::TRootBeer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TRootBeer >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TRootBeer", ::TRootBeer::Class_Version(), "include/TRootBeer.h", 24,
                  typeid(::TRootBeer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TRootBeer::Dictionary, isa_proxy, 16,
                  sizeof(::TRootBeer) );
      instance.SetNew(&new_TRootBeer);
      instance.SetNewArray(&newArray_TRootBeer);
      instance.SetDelete(&delete_TRootBeer);
      instance.SetDeleteArray(&deleteArray_TRootBeer);
      instance.SetDestructor(&destruct_TRootBeer);
      instance.SetStreamerFunc(&streamer_TRootBeer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRootBeer*)
   {
      return GenerateInitInstanceLocal((::TRootBeer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRootBeer*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TRootBeer::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TRootBeer::Class_Name()
{
   return "TRootBeer";
}

//______________________________________________________________________________
const char *TRootBeer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRootBeer*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TRootBeer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TRootBeer*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TRootBeer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRootBeer*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TRootBeer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TRootBeer*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TRootBeer::Streamer(TBuffer &R__b)
{
   // Stream an object of class TRootBeer.

   TObject::Streamer(R__b);
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRootBeer(void *p) {
      return  p ? new(p) ::TRootBeer : new ::TRootBeer;
   }
   static void *newArray_TRootBeer(Long_t nElements, void *p) {
      return p ? new(p) ::TRootBeer[nElements] : new ::TRootBeer[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRootBeer(void *p) {
      delete ((::TRootBeer*)p);
   }
   static void deleteArray_TRootBeer(void *p) {
      delete [] ((::TRootBeer*)p);
   }
   static void destruct_TRootBeer(void *p) {
      typedef ::TRootBeer current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TRootBeer(TBuffer &buf, void *obj) {
      ((::TRootBeer*)obj)->::TRootBeer::Streamer(buf);
   }
} // end of namespace ROOT for class ::TRootBeer

namespace {
  void TriggerDictionaryInitialization_RootBeerDict_Impl() {
    static const char* headers[] = {
"include/TRootBeer.h",
0
    };
    static const char* includePaths[] = {
"/mnt/share/cern_CentOS7/root/v6.14.04/include",
"/home/dglazier/Dropbox/HaSpect/dev/HASPECT6/ExtraPackages/RootBeerLite/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "RootBeerDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$include/TRootBeer.h")))  TRootBeer;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "RootBeerDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "include/TRootBeer.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"TRootBeer", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("RootBeerDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_RootBeerDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_RootBeerDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_RootBeerDict() {
  TriggerDictionaryInitialization_RootBeerDict_Impl();
}
