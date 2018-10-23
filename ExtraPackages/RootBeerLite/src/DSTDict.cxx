// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME srcdIDSTDict

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
#include "include/TDST.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void delete_TDST(void *p);
   static void deleteArray_TDST(void *p);
   static void destruct_TDST(void *p);
   static void streamer_TDST(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TDST*)
   {
      ::TDST *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TDST >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TDST", ::TDST::Class_Version(), "include/TDST.h", 19,
                  typeid(::TDST), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TDST::Dictionary, isa_proxy, 16,
                  sizeof(::TDST) );
      instance.SetDelete(&delete_TDST);
      instance.SetDeleteArray(&deleteArray_TDST);
      instance.SetDestructor(&destruct_TDST);
      instance.SetStreamerFunc(&streamer_TDST);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TDST*)
   {
      return GenerateInitInstanceLocal((::TDST*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TDST*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TDST::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TDST::Class_Name()
{
   return "TDST";
}

//______________________________________________________________________________
const char *TDST::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDST*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TDST::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDST*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TDST::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDST*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TDST::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDST*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TDST::Streamer(TBuffer &R__b)
{
   // Stream an object of class TDST.

   TRootBeer::Streamer(R__b);
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TDST(void *p) {
      delete ((::TDST*)p);
   }
   static void deleteArray_TDST(void *p) {
      delete [] ((::TDST*)p);
   }
   static void destruct_TDST(void *p) {
      typedef ::TDST current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TDST(TBuffer &buf, void *obj) {
      ((::TDST*)obj)->::TDST::Streamer(buf);
   }
} // end of namespace ROOT for class ::TDST

namespace {
  void TriggerDictionaryInitialization_DSTDict_Impl() {
    static const char* headers[] = {
"include/TDST.h",
0
    };
    static const char* includePaths[] = {
"/mnt/share/cern_CentOS7/root/v6.14.04/include",
"/home/dglazier/Dropbox/HaSpect/dev/HASPECT6/ExtraPackages/RootBeerLite/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "DSTDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$include/TDST.h")))  TDST;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DSTDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "include/TDST.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"TDST", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DSTDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DSTDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DSTDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DSTDict() {
  TriggerDictionaryInitialization_DSTDict_Impl();
}
