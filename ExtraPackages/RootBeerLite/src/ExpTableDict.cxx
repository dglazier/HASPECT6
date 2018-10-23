// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME srcdIExpTableDict

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
#include "include/TExpTable.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void delete_TExpTable(void *p);
   static void deleteArray_TExpTable(void *p);
   static void destruct_TExpTable(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TExpTable*)
   {
      ::TExpTable *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TExpTable >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TExpTable", ::TExpTable::Class_Version(), "include/TExpTable.h", 26,
                  typeid(::TExpTable), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TExpTable::Dictionary, isa_proxy, 4,
                  sizeof(::TExpTable) );
      instance.SetDelete(&delete_TExpTable);
      instance.SetDeleteArray(&deleteArray_TExpTable);
      instance.SetDestructor(&destruct_TExpTable);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TExpTable*)
   {
      return GenerateInitInstanceLocal((::TExpTable*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TExpTable*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TExpTable::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TExpTable::Class_Name()
{
   return "TExpTable";
}

//______________________________________________________________________________
const char *TExpTable::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TExpTable*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TExpTable::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TExpTable*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TExpTable::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TExpTable*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TExpTable::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TExpTable*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TExpTable::Streamer(TBuffer &R__b)
{
   // Stream an object of class TExpTable.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(TExpTable::Class(),this);
   } else {
      R__b.WriteClassBuffer(TExpTable::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TExpTable(void *p) {
      delete ((::TExpTable*)p);
   }
   static void deleteArray_TExpTable(void *p) {
      delete [] ((::TExpTable*)p);
   }
   static void destruct_TExpTable(void *p) {
      typedef ::TExpTable current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TExpTable

namespace {
  void TriggerDictionaryInitialization_ExpTableDict_Impl() {
    static const char* headers[] = {
"include/TExpTable.h",
0
    };
    static const char* includePaths[] = {
"/mnt/share/cern_CentOS7/root/v6.14.04/include",
"/home/dglazier/Dropbox/HaSpect/dev/HASPECT6/ExtraPackages/RootBeerLite/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "ExpTableDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$include/TExpTable.h")))  TExpTable;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "ExpTableDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "include/TExpTable.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"TExpTable", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ExpTableDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ExpTableDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ExpTableDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ExpTableDict() {
  TriggerDictionaryInitialization_ExpTableDict_Impl();
}
