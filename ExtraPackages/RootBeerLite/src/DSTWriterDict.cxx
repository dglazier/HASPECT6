// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME srcdIDSTWriterDict

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
#include "include/TDSTWriter.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void delete_TDSTWriter(void *p);
   static void deleteArray_TDSTWriter(void *p);
   static void destruct_TDSTWriter(void *p);
   static void streamer_TDSTWriter(TBuffer &buf, void *obj);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TDSTWriter*)
   {
      ::TDSTWriter *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::TDSTWriter >(0);
      static ::ROOT::TGenericClassInfo 
         instance("TDSTWriter", ::TDSTWriter::Class_Version(), "include/TDSTWriter.h", 15,
                  typeid(::TDSTWriter), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::TDSTWriter::Dictionary, isa_proxy, 16,
                  sizeof(::TDSTWriter) );
      instance.SetDelete(&delete_TDSTWriter);
      instance.SetDeleteArray(&deleteArray_TDSTWriter);
      instance.SetDestructor(&destruct_TDSTWriter);
      instance.SetStreamerFunc(&streamer_TDSTWriter);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TDSTWriter*)
   {
      return GenerateInitInstanceLocal((::TDSTWriter*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TDSTWriter*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr TDSTWriter::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *TDSTWriter::Class_Name()
{
   return "TDSTWriter";
}

//______________________________________________________________________________
const char *TDSTWriter::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDSTWriter*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int TDSTWriter::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::TDSTWriter*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *TDSTWriter::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDSTWriter*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *TDSTWriter::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::TDSTWriter*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void TDSTWriter::Streamer(TBuffer &R__b)
{
   // Stream an object of class TDSTWriter.

   TObject::Streamer(R__b);
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_TDSTWriter(void *p) {
      delete ((::TDSTWriter*)p);
   }
   static void deleteArray_TDSTWriter(void *p) {
      delete [] ((::TDSTWriter*)p);
   }
   static void destruct_TDSTWriter(void *p) {
      typedef ::TDSTWriter current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around a custom streamer member function.
   static void streamer_TDSTWriter(TBuffer &buf, void *obj) {
      ((::TDSTWriter*)obj)->::TDSTWriter::Streamer(buf);
   }
} // end of namespace ROOT for class ::TDSTWriter

namespace {
  void TriggerDictionaryInitialization_DSTWriterDict_Impl() {
    static const char* headers[] = {
"include/TDSTWriter.h",
0
    };
    static const char* includePaths[] = {
"/mnt/share/cern_CentOS7/root/v6.14.04/include",
"/home/dglazier/Dropbox/HaSpect/dev/HASPECT6/ExtraPackages/RootBeerLite/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "DSTWriterDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$include/TDSTWriter.h")))  TDSTWriter;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DSTWriterDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "include/TDSTWriter.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"TDSTWriter", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DSTWriterDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DSTWriterDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DSTWriterDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DSTWriterDict() {
  TriggerDictionaryInitialization_DSTWriterDict_Impl();
}
