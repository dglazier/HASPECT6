// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME extra_packagesdIeloss_rbdIelossDict

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
#include "extra_packages/eloss_rb/eLoss.h"

// Header files passed via #pragma extra_include

namespace {
  void TriggerDictionaryInitialization_elossDict_Impl() {
    static const char* headers[] = {
"extra_packages/eloss_rb/eLoss.h",
0
    };
    static const char* includePaths[] = {
"/mnt/share/cern_CentOS7/root/v6.14.04/include",
"/home/dglazier/Dropbox/HaSpect/dev/HASPECT6/ExtraPackages/RootBeerLite/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "elossDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "elossDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "extra_packages/eloss_rb/eLoss.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"eLoss", payloadCode, "@",
"initELoss", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("elossDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_elossDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_elossDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_elossDict() {
  TriggerDictionaryInitialization_elossDict_Impl();
}
