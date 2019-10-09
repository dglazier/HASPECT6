// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME dIhomedIdglazierdIannikadIHASPECT6dIhsfitdIsPlot_C_ACLiC_dict

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
#include "/home/dglazier/annika/HASPECT6/hsfit/sPlot.C"

// Header files passed via #pragma extra_include

namespace HS {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *HS_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("HS", 0 /*version*/, "PdfParser.h", 16,
                     ::ROOT::Internal::DefineBehavior((void*)0,(void*)0),
                     &HS_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *HS_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}

namespace HS {
   namespace FIT {
   namespace ROOT {
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance();
      static TClass *HScLcLFIT_Dictionary();

      // Function generating the singleton type initializer
      inline ::ROOT::TGenericClassInfo *GenerateInitInstance()
      {
         static ::ROOT::TGenericClassInfo 
            instance("HS::FIT", 0 /*version*/, "Setup.h", 29,
                     ::ROOT::Internal::DefineBehavior((void*)0,(void*)0),
                     &HScLcLFIT_Dictionary, 0);
         return &instance;
      }
      // Insure that the inline function is _not_ optimized away by the compiler
      ::ROOT::TGenericClassInfo *(*_R__UNIQUE_DICT_(InitFunctionKeeper))() = &GenerateInitInstance;  
      // Static variable to force the class initialization
      static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstance(); R__UseDummy(_R__UNIQUE_DICT_(Init));

      // Dictionary for non-ClassDef classes
      static TClass *HScLcLFIT_Dictionary() {
         return GenerateInitInstance()->GetClass();
      }

   }
}
}

namespace ROOT {
   static void *new_HScLcLFITcLcLsPlot(void *p = 0);
   static void *newArray_HScLcLFITcLcLsPlot(Long_t size, void *p);
   static void delete_HScLcLFITcLcLsPlot(void *p);
   static void deleteArray_HScLcLFITcLcLsPlot(void *p);
   static void destruct_HScLcLFITcLcLsPlot(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HS::FIT::sPlot*)
   {
      ::HS::FIT::sPlot *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HS::FIT::sPlot >(0);
      static ::ROOT::TGenericClassInfo 
         instance("HS::FIT::sPlot", ::HS::FIT::sPlot::Class_Version(), "sPlot.h", 23,
                  typeid(::HS::FIT::sPlot), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::HS::FIT::sPlot::Dictionary, isa_proxy, 4,
                  sizeof(::HS::FIT::sPlot) );
      instance.SetNew(&new_HScLcLFITcLcLsPlot);
      instance.SetNewArray(&newArray_HScLcLFITcLcLsPlot);
      instance.SetDelete(&delete_HScLcLFITcLcLsPlot);
      instance.SetDeleteArray(&deleteArray_HScLcLFITcLcLsPlot);
      instance.SetDestructor(&destruct_HScLcLFITcLcLsPlot);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HS::FIT::sPlot*)
   {
      return GenerateInitInstanceLocal((::HS::FIT::sPlot*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HS::FIT::sPlot*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

namespace HS {
   namespace FIT {
//______________________________________________________________________________
atomic_TClass_ptr sPlot::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *sPlot::Class_Name()
{
   return "HS::FIT::sPlot";
}

//______________________________________________________________________________
const char *sPlot::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HS::FIT::sPlot*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int sPlot::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HS::FIT::sPlot*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *sPlot::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HS::FIT::sPlot*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *sPlot::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HS::FIT::sPlot*)0x0)->GetClass(); }
   return fgIsA;
}

} // namespace HS::FIT
} // namespace HS::FIT
namespace HS {
   namespace FIT {
//______________________________________________________________________________
void sPlot::Streamer(TBuffer &R__b)
{
   // Stream an object of class HS::FIT::sPlot.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(HS::FIT::sPlot::Class(),this);
   } else {
      R__b.WriteClassBuffer(HS::FIT::sPlot::Class(),this);
   }
}

} // namespace HS::FIT
} // namespace HS::FIT
namespace ROOT {
   // Wrappers around operator new
   static void *new_HScLcLFITcLcLsPlot(void *p) {
      return  p ? new(p) ::HS::FIT::sPlot : new ::HS::FIT::sPlot;
   }
   static void *newArray_HScLcLFITcLcLsPlot(Long_t nElements, void *p) {
      return p ? new(p) ::HS::FIT::sPlot[nElements] : new ::HS::FIT::sPlot[nElements];
   }
   // Wrapper around operator delete
   static void delete_HScLcLFITcLcLsPlot(void *p) {
      delete ((::HS::FIT::sPlot*)p);
   }
   static void deleteArray_HScLcLFITcLcLsPlot(void *p) {
      delete [] ((::HS::FIT::sPlot*)p);
   }
   static void destruct_HScLcLFITcLcLsPlot(void *p) {
      typedef ::HS::FIT::sPlot current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HS::FIT::sPlot

namespace ROOT {
   static TClass *vectorlEpairlETStringcOfloatgRsPgR_Dictionary();
   static void vectorlEpairlETStringcOfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEpairlETStringcOfloatgRsPgR(void *p = 0);
   static void *newArray_vectorlEpairlETStringcOfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEpairlETStringcOfloatgRsPgR(void *p);
   static void deleteArray_vectorlEpairlETStringcOfloatgRsPgR(void *p);
   static void destruct_vectorlEpairlETStringcOfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<pair<TString,float> >*)
   {
      vector<pair<TString,float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<pair<TString,float> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<pair<TString,float> >", -2, "vector", 210,
                  typeid(vector<pair<TString,float> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEpairlETStringcOfloatgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<pair<TString,float> >) );
      instance.SetNew(&new_vectorlEpairlETStringcOfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEpairlETStringcOfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEpairlETStringcOfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEpairlETStringcOfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEpairlETStringcOfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<pair<TString,float> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<pair<TString,float> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEpairlETStringcOfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<pair<TString,float> >*)0x0)->GetClass();
      vectorlEpairlETStringcOfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEpairlETStringcOfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEpairlETStringcOfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<pair<TString,float> > : new vector<pair<TString,float> >;
   }
   static void *newArray_vectorlEpairlETStringcOfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<pair<TString,float> >[nElements] : new vector<pair<TString,float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEpairlETStringcOfloatgRsPgR(void *p) {
      delete ((vector<pair<TString,float> >*)p);
   }
   static void deleteArray_vectorlEpairlETStringcOfloatgRsPgR(void *p) {
      delete [] ((vector<pair<TString,float> >*)p);
   }
   static void destruct_vectorlEpairlETStringcOfloatgRsPgR(void *p) {
      typedef vector<pair<TString,float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<pair<TString,float> >

namespace {
  void TriggerDictionaryInitialization_sPlot_C_ACLiC_dict_Impl() {
    static const char* headers[] = {
"/home/dglazier/annika/HASPECT6/hsfit/sPlot.C",
0
    };
    static const char* includePaths[] = {
"/mnt/share/cern_CentOS7/root/v6.14.04b/include",
"/mnt/share/cern_CentOS7/root/v6.14.04b/etc",
"/mnt/share/cern_CentOS7/root/v6.14.04b/etc/cling",
"/mnt/share/cern_CentOS7/root/v6.14.04b/include",
"/usr/include/freetype2",
"/home/dglazier/annika/PolMoments/",
"/home/dglazier/annika/HASPECT6//hsfit",
"/home/dglazier/annika/HASPECT6//hsdata",
"/home/dglazier/annika/louise/",
"/home/dglazier/annika/HASPECT6/tutorials/RooFitExamples/Generators/",
"/mnt/share/cern_CentOS7/root/v6.14.04b/include",
"/home/dglazier/annika/HASPECT6/tutorials/RooFitExamples/Generators/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "sPlot_C_ACLiC_dict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$TString.h")))  __attribute__((annotate("$clingAutoload$/home/dglazier/annika/HASPECT6/hsfit/sPlot.C")))  TString;
namespace std{template <class _T1, class _T2> struct __attribute__((annotate("$clingAutoload$bits/stl_pair.h")))  __attribute__((annotate("$clingAutoload$string")))  pair;
}
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
namespace HS{namespace FIT{class __attribute__((annotate(R"ATTRDUMP(file_name@@@/home/dglazier/annika/HASPECT6/hsfit/sPlot.h)ATTRDUMP"))) __attribute__((annotate(R"ATTRDUMP(pattern@@@*)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$sPlot.h")))  __attribute__((annotate("$clingAutoload$/home/dglazier/annika/HASPECT6/hsfit/sPlot.C")))  sPlot;}}
namespace HS{namespace FIT{using splot_uptr __attribute__((annotate("$clingAutoload$sPlot.h")))  __attribute__((annotate("$clingAutoload$/home/dglazier/annika/HASPECT6/hsfit/sPlot.C")))  = std::unique_ptr<RooStats::SPlot>;}}
namespace HS{namespace FIT{using weights_ptr __attribute__((annotate("$clingAutoload$sPlot.h")))  __attribute__((annotate("$clingAutoload$/home/dglazier/annika/HASPECT6/hsfit/sPlot.C")))  = std::shared_ptr<HS::Weights>;}}
namespace HS{namespace FIT{using weights_uptr __attribute__((annotate("$clingAutoload$sPlot.h")))  __attribute__((annotate("$clingAutoload$/home/dglazier/annika/HASPECT6/hsfit/sPlot.C")))  = std::unique_ptr<HS::Weights>;}}
namespace HS{namespace FIT{using tree_uptr __attribute__((annotate("$clingAutoload$sPlot.h")))  __attribute__((annotate("$clingAutoload$/home/dglazier/annika/HASPECT6/hsfit/sPlot.C")))  = std::unique_ptr<TTree>;}}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "sPlot_C_ACLiC_dict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef __ACLIC__
  #define __ACLIC__ 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "/home/dglazier/annika/HASPECT6/hsfit/sPlot.C"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"", payloadCode, "@",
"HS::FIT::sPlot", payloadCode, "@",
"HS::FIT::sPlot::fgIsA", payloadCode, "@",
"HS::FIT::splot_uptr", payloadCode, "@",
"HS::FIT::tree_uptr", payloadCode, "@",
"HS::FIT::weights_ptr", payloadCode, "@",
"HS::FIT::weights_uptr", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("sPlot_C_ACLiC_dict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_sPlot_C_ACLiC_dict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_sPlot_C_ACLiC_dict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_sPlot_C_ACLiC_dict() {
  TriggerDictionaryInitialization_sPlot_C_ACLiC_dict_Impl();
}
