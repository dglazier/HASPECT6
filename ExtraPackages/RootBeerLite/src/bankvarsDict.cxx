// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME srcdIbankvarsDict

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
#include "include/bankvars.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *BEAM_t_Dictionary();
   static void BEAM_t_TClassManip(TClass*);
   static void *new_BEAM_t(void *p = 0);
   static void *newArray_BEAM_t(Long_t size, void *p);
   static void delete_BEAM_t(void *p);
   static void deleteArray_BEAM_t(void *p);
   static void destruct_BEAM_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::BEAM_t*)
   {
      ::BEAM_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::BEAM_t));
      static ::ROOT::TGenericClassInfo 
         instance("BEAM_t", "include/bankheader.h", 8,
                  typeid(::BEAM_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &BEAM_t_Dictionary, isa_proxy, 0,
                  sizeof(::BEAM_t) );
      instance.SetNew(&new_BEAM_t);
      instance.SetNewArray(&newArray_BEAM_t);
      instance.SetDelete(&delete_BEAM_t);
      instance.SetDeleteArray(&deleteArray_BEAM_t);
      instance.SetDestructor(&destruct_BEAM_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::BEAM_t*)
   {
      return GenerateInitInstanceLocal((::BEAM_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::BEAM_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *BEAM_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::BEAM_t*)0x0)->GetClass();
      BEAM_t_TClassManip(theClass);
   return theClass;
   }

   static void BEAM_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *BMPR_t_Dictionary();
   static void BMPR_t_TClassManip(TClass*);
   static void *new_BMPR_t(void *p = 0);
   static void *newArray_BMPR_t(Long_t size, void *p);
   static void delete_BMPR_t(void *p);
   static void deleteArray_BMPR_t(void *p);
   static void destruct_BMPR_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::BMPR_t*)
   {
      ::BMPR_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::BMPR_t));
      static ::ROOT::TGenericClassInfo 
         instance("BMPR_t", "include/bankheader.h", 14,
                  typeid(::BMPR_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &BMPR_t_Dictionary, isa_proxy, 0,
                  sizeof(::BMPR_t) );
      instance.SetNew(&new_BMPR_t);
      instance.SetNewArray(&newArray_BMPR_t);
      instance.SetDelete(&delete_BMPR_t);
      instance.SetDeleteArray(&deleteArray_BMPR_t);
      instance.SetDestructor(&destruct_BMPR_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::BMPR_t*)
   {
      return GenerateInitInstanceLocal((::BMPR_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::BMPR_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *BMPR_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::BMPR_t*)0x0)->GetClass();
      BMPR_t_TClassManip(theClass);
   return theClass;
   }

   static void BMPR_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *BREP_t_Dictionary();
   static void BREP_t_TClassManip(TClass*);
   static void *new_BREP_t(void *p = 0);
   static void *newArray_BREP_t(Long_t size, void *p);
   static void delete_BREP_t(void *p);
   static void deleteArray_BREP_t(void *p);
   static void destruct_BREP_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::BREP_t*)
   {
      ::BREP_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::BREP_t));
      static ::ROOT::TGenericClassInfo 
         instance("BREP_t", "include/bankheader.h", 20,
                  typeid(::BREP_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &BREP_t_Dictionary, isa_proxy, 0,
                  sizeof(::BREP_t) );
      instance.SetNew(&new_BREP_t);
      instance.SetNewArray(&newArray_BREP_t);
      instance.SetDelete(&delete_BREP_t);
      instance.SetDeleteArray(&deleteArray_BREP_t);
      instance.SetDestructor(&destruct_BREP_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::BREP_t*)
   {
      return GenerateInitInstanceLocal((::BREP_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::BREP_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *BREP_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::BREP_t*)0x0)->GetClass();
      BREP_t_TClassManip(theClass);
   return theClass;
   }

   static void BREP_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CALB_t_Dictionary();
   static void CALB_t_TClassManip(TClass*);
   static void *new_CALB_t(void *p = 0);
   static void *newArray_CALB_t(Long_t size, void *p);
   static void delete_CALB_t(void *p);
   static void deleteArray_CALB_t(void *p);
   static void destruct_CALB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CALB_t*)
   {
      ::CALB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CALB_t));
      static ::ROOT::TGenericClassInfo 
         instance("CALB_t", "include/bankheader.h", 58,
                  typeid(::CALB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CALB_t_Dictionary, isa_proxy, 0,
                  sizeof(::CALB_t) );
      instance.SetNew(&new_CALB_t);
      instance.SetNewArray(&newArray_CALB_t);
      instance.SetDelete(&delete_CALB_t);
      instance.SetDeleteArray(&deleteArray_CALB_t);
      instance.SetDestructor(&destruct_CALB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CALB_t*)
   {
      return GenerateInitInstanceLocal((::CALB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CALB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CALB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CALB_t*)0x0)->GetClass();
      CALB_t_TClassManip(theClass);
   return theClass;
   }

   static void CALB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CALL_t_Dictionary();
   static void CALL_t_TClassManip(TClass*);
   static void *new_CALL_t(void *p = 0);
   static void *newArray_CALL_t(Long_t size, void *p);
   static void delete_CALL_t(void *p);
   static void deleteArray_CALL_t(void *p);
   static void destruct_CALL_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CALL_t*)
   {
      ::CALL_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CALL_t));
      static ::ROOT::TGenericClassInfo 
         instance("CALL_t", "include/bankheader.h", 72,
                  typeid(::CALL_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CALL_t_Dictionary, isa_proxy, 0,
                  sizeof(::CALL_t) );
      instance.SetNew(&new_CALL_t);
      instance.SetNewArray(&newArray_CALL_t);
      instance.SetDelete(&delete_CALL_t);
      instance.SetDeleteArray(&deleteArray_CALL_t);
      instance.SetDestructor(&destruct_CALL_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CALL_t*)
   {
      return GenerateInitInstanceLocal((::CALL_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CALL_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CALL_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CALL_t*)0x0)->GetClass();
      CALL_t_TClassManip(theClass);
   return theClass;
   }

   static void CALL_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CC01_t_Dictionary();
   static void CC01_t_TClassManip(TClass*);
   static void *new_CC01_t(void *p = 0);
   static void *newArray_CC01_t(Long_t size, void *p);
   static void delete_CC01_t(void *p);
   static void deleteArray_CC01_t(void *p);
   static void destruct_CC01_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CC01_t*)
   {
      ::CC01_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CC01_t));
      static ::ROOT::TGenericClassInfo 
         instance("CC01_t", "include/bankheader.h", 77,
                  typeid(::CC01_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CC01_t_Dictionary, isa_proxy, 0,
                  sizeof(::CC01_t) );
      instance.SetNew(&new_CC01_t);
      instance.SetNewArray(&newArray_CC01_t);
      instance.SetDelete(&delete_CC01_t);
      instance.SetDeleteArray(&deleteArray_CC01_t);
      instance.SetDestructor(&destruct_CC01_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CC01_t*)
   {
      return GenerateInitInstanceLocal((::CC01_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CC01_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CC01_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CC01_t*)0x0)->GetClass();
      CC01_t_TClassManip(theClass);
   return theClass;
   }

   static void CC01_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CC1_t_Dictionary();
   static void CC1_t_TClassManip(TClass*);
   static void *new_CC1_t(void *p = 0);
   static void *newArray_CC1_t(Long_t size, void *p);
   static void delete_CC1_t(void *p);
   static void deleteArray_CC1_t(void *p);
   static void destruct_CC1_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CC1_t*)
   {
      ::CC1_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CC1_t));
      static ::ROOT::TGenericClassInfo 
         instance("CC1_t", "include/bankheader.h", 82,
                  typeid(::CC1_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CC1_t_Dictionary, isa_proxy, 0,
                  sizeof(::CC1_t) );
      instance.SetNew(&new_CC1_t);
      instance.SetNewArray(&newArray_CC1_t);
      instance.SetDelete(&delete_CC1_t);
      instance.SetDeleteArray(&deleteArray_CC1_t);
      instance.SetDestructor(&destruct_CC1_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CC1_t*)
   {
      return GenerateInitInstanceLocal((::CC1_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CC1_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CC1_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CC1_t*)0x0)->GetClass();
      CC1_t_TClassManip(theClass);
   return theClass;
   }

   static void CC1_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CC_t_Dictionary();
   static void CC_t_TClassManip(TClass*);
   static void *new_CC_t(void *p = 0);
   static void *newArray_CC_t(Long_t size, void *p);
   static void delete_CC_t(void *p);
   static void deleteArray_CC_t(void *p);
   static void destruct_CC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CC_t*)
   {
      ::CC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CC_t));
      static ::ROOT::TGenericClassInfo 
         instance("CC_t", "include/bankheader.h", 87,
                  typeid(::CC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CC_t_Dictionary, isa_proxy, 0,
                  sizeof(::CC_t) );
      instance.SetNew(&new_CC_t);
      instance.SetNewArray(&newArray_CC_t);
      instance.SetDelete(&delete_CC_t);
      instance.SetDeleteArray(&deleteArray_CC_t);
      instance.SetDestructor(&destruct_CC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CC_t*)
   {
      return GenerateInitInstanceLocal((::CC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CC_t*)0x0)->GetClass();
      CC_t_TClassManip(theClass);
   return theClass;
   }

   static void CC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CCDI_t_Dictionary();
   static void CCDI_t_TClassManip(TClass*);
   static void *new_CCDI_t(void *p = 0);
   static void *newArray_CCDI_t(Long_t size, void *p);
   static void delete_CCDI_t(void *p);
   static void deleteArray_CCDI_t(void *p);
   static void destruct_CCDI_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CCDI_t*)
   {
      ::CCDI_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CCDI_t));
      static ::ROOT::TGenericClassInfo 
         instance("CCDI_t", "include/bankheader.h", 92,
                  typeid(::CCDI_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CCDI_t_Dictionary, isa_proxy, 0,
                  sizeof(::CCDI_t) );
      instance.SetNew(&new_CCDI_t);
      instance.SetNewArray(&newArray_CCDI_t);
      instance.SetDelete(&delete_CCDI_t);
      instance.SetDeleteArray(&deleteArray_CCDI_t);
      instance.SetDestructor(&destruct_CCDI_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CCDI_t*)
   {
      return GenerateInitInstanceLocal((::CCDI_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CCDI_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CCDI_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CCDI_t*)0x0)->GetClass();
      CCDI_t_TClassManip(theClass);
   return theClass;
   }

   static void CCDI_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CCH_t_Dictionary();
   static void CCH_t_TClassManip(TClass*);
   static void *new_CCH_t(void *p = 0);
   static void *newArray_CCH_t(Long_t size, void *p);
   static void delete_CCH_t(void *p);
   static void deleteArray_CCH_t(void *p);
   static void destruct_CCH_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CCH_t*)
   {
      ::CCH_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CCH_t));
      static ::ROOT::TGenericClassInfo 
         instance("CCH_t", "include/bankheader.h", 99,
                  typeid(::CCH_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CCH_t_Dictionary, isa_proxy, 0,
                  sizeof(::CCH_t) );
      instance.SetNew(&new_CCH_t);
      instance.SetNewArray(&newArray_CCH_t);
      instance.SetDelete(&delete_CCH_t);
      instance.SetDeleteArray(&deleteArray_CCH_t);
      instance.SetDestructor(&destruct_CCH_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CCH_t*)
   {
      return GenerateInitInstanceLocal((::CCH_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CCH_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CCH_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CCH_t*)0x0)->GetClass();
      CCH_t_TClassManip(theClass);
   return theClass;
   }

   static void CCH_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CCMT_t_Dictionary();
   static void CCMT_t_TClassManip(TClass*);
   static void *new_CCMT_t(void *p = 0);
   static void *newArray_CCMT_t(Long_t size, void *p);
   static void delete_CCMT_t(void *p);
   static void deleteArray_CCMT_t(void *p);
   static void destruct_CCMT_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CCMT_t*)
   {
      ::CCMT_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CCMT_t));
      static ::ROOT::TGenericClassInfo 
         instance("CCMT_t", "include/bankheader.h", 113,
                  typeid(::CCMT_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CCMT_t_Dictionary, isa_proxy, 0,
                  sizeof(::CCMT_t) );
      instance.SetNew(&new_CCMT_t);
      instance.SetNewArray(&newArray_CCMT_t);
      instance.SetDelete(&delete_CCMT_t);
      instance.SetDeleteArray(&deleteArray_CCMT_t);
      instance.SetDestructor(&destruct_CCMT_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CCMT_t*)
   {
      return GenerateInitInstanceLocal((::CCMT_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CCMT_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CCMT_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CCMT_t*)0x0)->GetClass();
      CCMT_t_TClassManip(theClass);
   return theClass;
   }

   static void CCMT_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CCPB_t_Dictionary();
   static void CCPB_t_TClassManip(TClass*);
   static void *new_CCPB_t(void *p = 0);
   static void *newArray_CCPB_t(Long_t size, void *p);
   static void delete_CCPB_t(void *p);
   static void deleteArray_CCPB_t(void *p);
   static void destruct_CCPB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CCPB_t*)
   {
      ::CCPB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CCPB_t));
      static ::ROOT::TGenericClassInfo 
         instance("CCPB_t", "include/bankheader.h", 117,
                  typeid(::CCPB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CCPB_t_Dictionary, isa_proxy, 0,
                  sizeof(::CCPB_t) );
      instance.SetNew(&new_CCPB_t);
      instance.SetNewArray(&newArray_CCPB_t);
      instance.SetDelete(&delete_CCPB_t);
      instance.SetDeleteArray(&deleteArray_CCPB_t);
      instance.SetDestructor(&destruct_CCPB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CCPB_t*)
   {
      return GenerateInitInstanceLocal((::CCPB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CCPB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CCPB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CCPB_t*)0x0)->GetClass();
      CCPB_t_TClassManip(theClass);
   return theClass;
   }

   static void CCPB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CCPE_t_Dictionary();
   static void CCPE_t_TClassManip(TClass*);
   static void *new_CCPE_t(void *p = 0);
   static void *newArray_CCPE_t(Long_t size, void *p);
   static void delete_CCPE_t(void *p);
   static void deleteArray_CCPE_t(void *p);
   static void destruct_CCPE_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CCPE_t*)
   {
      ::CCPE_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CCPE_t));
      static ::ROOT::TGenericClassInfo 
         instance("CCPE_t", "include/bankheader.h", 125,
                  typeid(::CCPE_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CCPE_t_Dictionary, isa_proxy, 0,
                  sizeof(::CCPE_t) );
      instance.SetNew(&new_CCPE_t);
      instance.SetNewArray(&newArray_CCPE_t);
      instance.SetDelete(&delete_CCPE_t);
      instance.SetDeleteArray(&deleteArray_CCPE_t);
      instance.SetDestructor(&destruct_CCPE_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CCPE_t*)
   {
      return GenerateInitInstanceLocal((::CCPE_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CCPE_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CCPE_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CCPE_t*)0x0)->GetClass();
      CCPE_t_TClassManip(theClass);
   return theClass;
   }

   static void CCPE_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CCRC_t_Dictionary();
   static void CCRC_t_TClassManip(TClass*);
   static void *new_CCRC_t(void *p = 0);
   static void *newArray_CCRC_t(Long_t size, void *p);
   static void delete_CCRC_t(void *p);
   static void deleteArray_CCRC_t(void *p);
   static void destruct_CCRC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CCRC_t*)
   {
      ::CCRC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CCRC_t));
      static ::ROOT::TGenericClassInfo 
         instance("CCRC_t", "include/bankheader.h", 130,
                  typeid(::CCRC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CCRC_t_Dictionary, isa_proxy, 0,
                  sizeof(::CCRC_t) );
      instance.SetNew(&new_CCRC_t);
      instance.SetNewArray(&newArray_CCRC_t);
      instance.SetDelete(&delete_CCRC_t);
      instance.SetDeleteArray(&deleteArray_CCRC_t);
      instance.SetDestructor(&destruct_CCRC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CCRC_t*)
   {
      return GenerateInitInstanceLocal((::CCRC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CCRC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CCRC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CCRC_t*)0x0)->GetClass();
      CCRC_t_TClassManip(theClass);
   return theClass;
   }

   static void CCRC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CCS_t_Dictionary();
   static void CCS_t_TClassManip(TClass*);
   static void *new_CCS_t(void *p = 0);
   static void *newArray_CCS_t(Long_t size, void *p);
   static void delete_CCS_t(void *p);
   static void deleteArray_CCS_t(void *p);
   static void destruct_CCS_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CCS_t*)
   {
      ::CCS_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CCS_t));
      static ::ROOT::TGenericClassInfo 
         instance("CCS_t", "include/bankheader.h", 144,
                  typeid(::CCS_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CCS_t_Dictionary, isa_proxy, 0,
                  sizeof(::CCS_t) );
      instance.SetNew(&new_CCS_t);
      instance.SetNewArray(&newArray_CCS_t);
      instance.SetDelete(&delete_CCS_t);
      instance.SetDeleteArray(&deleteArray_CCS_t);
      instance.SetDestructor(&destruct_CCS_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CCS_t*)
   {
      return GenerateInitInstanceLocal((::CCS_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CCS_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CCS_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CCS_t*)0x0)->GetClass();
      CCS_t_TClassManip(theClass);
   return theClass;
   }

   static void CCS_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CHI2_t_Dictionary();
   static void CHI2_t_TClassManip(TClass*);
   static void *new_CHI2_t(void *p = 0);
   static void *newArray_CHI2_t(Long_t size, void *p);
   static void delete_CHI2_t(void *p);
   static void deleteArray_CHI2_t(void *p);
   static void destruct_CHI2_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CHI2_t*)
   {
      ::CHI2_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CHI2_t));
      static ::ROOT::TGenericClassInfo 
         instance("CHI2_t", "include/bankheader.h", 242,
                  typeid(::CHI2_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CHI2_t_Dictionary, isa_proxy, 0,
                  sizeof(::CHI2_t) );
      instance.SetNew(&new_CHI2_t);
      instance.SetNewArray(&newArray_CHI2_t);
      instance.SetDelete(&delete_CHI2_t);
      instance.SetDeleteArray(&deleteArray_CHI2_t);
      instance.SetDestructor(&destruct_CHI2_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CHI2_t*)
   {
      return GenerateInitInstanceLocal((::CHI2_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CHI2_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CHI2_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CHI2_t*)0x0)->GetClass();
      CHI2_t_TClassManip(theClass);
   return theClass;
   }

   static void CHI2_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CL01_t_Dictionary();
   static void CL01_t_TClassManip(TClass*);
   static void *new_CL01_t(void *p = 0);
   static void *newArray_CL01_t(Long_t size, void *p);
   static void delete_CL01_t(void *p);
   static void deleteArray_CL01_t(void *p);
   static void destruct_CL01_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CL01_t*)
   {
      ::CL01_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CL01_t));
      static ::ROOT::TGenericClassInfo 
         instance("CL01_t", "include/bankheader.h", 248,
                  typeid(::CL01_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CL01_t_Dictionary, isa_proxy, 0,
                  sizeof(::CL01_t) );
      instance.SetNew(&new_CL01_t);
      instance.SetNewArray(&newArray_CL01_t);
      instance.SetDelete(&delete_CL01_t);
      instance.SetDeleteArray(&deleteArray_CL01_t);
      instance.SetDestructor(&destruct_CL01_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CL01_t*)
   {
      return GenerateInitInstanceLocal((::CL01_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CL01_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CL01_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CL01_t*)0x0)->GetClass();
      CL01_t_TClassManip(theClass);
   return theClass;
   }

   static void CL01_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CLST_t_Dictionary();
   static void CLST_t_TClassManip(TClass*);
   static void *new_CLST_t(void *p = 0);
   static void *newArray_CLST_t(Long_t size, void *p);
   static void delete_CLST_t(void *p);
   static void deleteArray_CLST_t(void *p);
   static void destruct_CLST_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CLST_t*)
   {
      ::CLST_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CLST_t));
      static ::ROOT::TGenericClassInfo 
         instance("CLST_t", "include/bankheader.h", 262,
                  typeid(::CLST_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CLST_t_Dictionary, isa_proxy, 0,
                  sizeof(::CLST_t) );
      instance.SetNew(&new_CLST_t);
      instance.SetNewArray(&newArray_CLST_t);
      instance.SetDelete(&delete_CLST_t);
      instance.SetDeleteArray(&deleteArray_CLST_t);
      instance.SetDestructor(&destruct_CLST_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CLST_t*)
   {
      return GenerateInitInstanceLocal((::CLST_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CLST_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CLST_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CLST_t*)0x0)->GetClass();
      CLST_t_TClassManip(theClass);
   return theClass;
   }

   static void CLST_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CPED_t_Dictionary();
   static void CPED_t_TClassManip(TClass*);
   static void *new_CPED_t(void *p = 0);
   static void *newArray_CPED_t(Long_t size, void *p);
   static void delete_CPED_t(void *p);
   static void deleteArray_CPED_t(void *p);
   static void destruct_CPED_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CPED_t*)
   {
      ::CPED_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CPED_t));
      static ::ROOT::TGenericClassInfo 
         instance("CPED_t", "include/bankheader.h", 265,
                  typeid(::CPED_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CPED_t_Dictionary, isa_proxy, 0,
                  sizeof(::CPED_t) );
      instance.SetNew(&new_CPED_t);
      instance.SetNewArray(&newArray_CPED_t);
      instance.SetDelete(&delete_CPED_t);
      instance.SetDeleteArray(&deleteArray_CPED_t);
      instance.SetDestructor(&destruct_CPED_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CPED_t*)
   {
      return GenerateInitInstanceLocal((::CPED_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CPED_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CPED_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CPED_t*)0x0)->GetClass();
      CPED_t_TClassManip(theClass);
   return theClass;
   }

   static void CPED_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *CSQL_t_Dictionary();
   static void CSQL_t_TClassManip(TClass*);
   static void *new_CSQL_t(void *p = 0);
   static void *newArray_CSQL_t(Long_t size, void *p);
   static void delete_CSQL_t(void *p);
   static void deleteArray_CSQL_t(void *p);
   static void destruct_CSQL_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CSQL_t*)
   {
      ::CSQL_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::CSQL_t));
      static ::ROOT::TGenericClassInfo 
         instance("CSQL_t", "include/bankheader.h", 272,
                  typeid(::CSQL_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &CSQL_t_Dictionary, isa_proxy, 0,
                  sizeof(::CSQL_t) );
      instance.SetNew(&new_CSQL_t);
      instance.SetNewArray(&newArray_CSQL_t);
      instance.SetDelete(&delete_CSQL_t);
      instance.SetDeleteArray(&deleteArray_CSQL_t);
      instance.SetDestructor(&destruct_CSQL_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CSQL_t*)
   {
      return GenerateInitInstanceLocal((::CSQL_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::CSQL_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *CSQL_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::CSQL_t*)0x0)->GetClass();
      CSQL_t_TClassManip(theClass);
   return theClass;
   }

   static void CSQL_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DC0_t_Dictionary();
   static void DC0_t_TClassManip(TClass*);
   static void *new_DC0_t(void *p = 0);
   static void *newArray_DC0_t(Long_t size, void *p);
   static void delete_DC0_t(void *p);
   static void deleteArray_DC0_t(void *p);
   static void destruct_DC0_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DC0_t*)
   {
      ::DC0_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DC0_t));
      static ::ROOT::TGenericClassInfo 
         instance("DC0_t", "include/bankheader.h", 295,
                  typeid(::DC0_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DC0_t_Dictionary, isa_proxy, 0,
                  sizeof(::DC0_t) );
      instance.SetNew(&new_DC0_t);
      instance.SetNewArray(&newArray_DC0_t);
      instance.SetDelete(&delete_DC0_t);
      instance.SetDeleteArray(&deleteArray_DC0_t);
      instance.SetDestructor(&destruct_DC0_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DC0_t*)
   {
      return GenerateInitInstanceLocal((::DC0_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DC0_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DC0_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DC0_t*)0x0)->GetClass();
      DC0_t_TClassManip(theClass);
   return theClass;
   }

   static void DC0_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DC1_t_Dictionary();
   static void DC1_t_TClassManip(TClass*);
   static void *new_DC1_t(void *p = 0);
   static void *newArray_DC1_t(Long_t size, void *p);
   static void delete_DC1_t(void *p);
   static void deleteArray_DC1_t(void *p);
   static void destruct_DC1_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DC1_t*)
   {
      ::DC1_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DC1_t));
      static ::ROOT::TGenericClassInfo 
         instance("DC1_t", "include/bankheader.h", 299,
                  typeid(::DC1_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DC1_t_Dictionary, isa_proxy, 0,
                  sizeof(::DC1_t) );
      instance.SetNew(&new_DC1_t);
      instance.SetNewArray(&newArray_DC1_t);
      instance.SetDelete(&delete_DC1_t);
      instance.SetDeleteArray(&deleteArray_DC1_t);
      instance.SetDestructor(&destruct_DC1_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DC1_t*)
   {
      return GenerateInitInstanceLocal((::DC1_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DC1_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DC1_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DC1_t*)0x0)->GetClass();
      DC1_t_TClassManip(theClass);
   return theClass;
   }

   static void DC1_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DCDW_t_Dictionary();
   static void DCDW_t_TClassManip(TClass*);
   static void *new_DCDW_t(void *p = 0);
   static void *newArray_DCDW_t(Long_t size, void *p);
   static void delete_DCDW_t(void *p);
   static void deleteArray_DCDW_t(void *p);
   static void destruct_DCDW_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DCDW_t*)
   {
      ::DCDW_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DCDW_t));
      static ::ROOT::TGenericClassInfo 
         instance("DCDW_t", "include/bankheader.h", 303,
                  typeid(::DCDW_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DCDW_t_Dictionary, isa_proxy, 0,
                  sizeof(::DCDW_t) );
      instance.SetNew(&new_DCDW_t);
      instance.SetNewArray(&newArray_DCDW_t);
      instance.SetDelete(&delete_DCDW_t);
      instance.SetDeleteArray(&deleteArray_DCDW_t);
      instance.SetDestructor(&destruct_DCDW_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DCDW_t*)
   {
      return GenerateInitInstanceLocal((::DCDW_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DCDW_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DCDW_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DCDW_t*)0x0)->GetClass();
      DCDW_t_TClassManip(theClass);
   return theClass;
   }

   static void DCDW_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DCGM_t_Dictionary();
   static void DCGM_t_TClassManip(TClass*);
   static void *new_DCGM_t(void *p = 0);
   static void *newArray_DCGM_t(Long_t size, void *p);
   static void delete_DCGM_t(void *p);
   static void deleteArray_DCGM_t(void *p);
   static void destruct_DCGM_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DCGM_t*)
   {
      ::DCGM_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DCGM_t));
      static ::ROOT::TGenericClassInfo 
         instance("DCGM_t", "include/bankheader.h", 308,
                  typeid(::DCGM_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DCGM_t_Dictionary, isa_proxy, 0,
                  sizeof(::DCGM_t) );
      instance.SetNew(&new_DCGM_t);
      instance.SetNewArray(&newArray_DCGM_t);
      instance.SetDelete(&delete_DCGM_t);
      instance.SetDeleteArray(&deleteArray_DCGM_t);
      instance.SetDestructor(&destruct_DCGM_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DCGM_t*)
   {
      return GenerateInitInstanceLocal((::DCGM_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DCGM_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DCGM_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DCGM_t*)0x0)->GetClass();
      DCGM_t_TClassManip(theClass);
   return theClass;
   }

   static void DCGM_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DCGW_t_Dictionary();
   static void DCGW_t_TClassManip(TClass*);
   static void *new_DCGW_t(void *p = 0);
   static void *newArray_DCGW_t(Long_t size, void *p);
   static void delete_DCGW_t(void *p);
   static void deleteArray_DCGW_t(void *p);
   static void destruct_DCGW_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DCGW_t*)
   {
      ::DCGW_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DCGW_t));
      static ::ROOT::TGenericClassInfo 
         instance("DCGW_t", "include/bankheader.h", 331,
                  typeid(::DCGW_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DCGW_t_Dictionary, isa_proxy, 0,
                  sizeof(::DCGW_t) );
      instance.SetNew(&new_DCGW_t);
      instance.SetNewArray(&newArray_DCGW_t);
      instance.SetDelete(&delete_DCGW_t);
      instance.SetDeleteArray(&deleteArray_DCGW_t);
      instance.SetDestructor(&destruct_DCGW_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DCGW_t*)
   {
      return GenerateInitInstanceLocal((::DCGW_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DCGW_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DCGW_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DCGW_t*)0x0)->GetClass();
      DCGW_t_TClassManip(theClass);
   return theClass;
   }

   static void DCGW_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DCH_t_Dictionary();
   static void DCH_t_TClassManip(TClass*);
   static void *new_DCH_t(void *p = 0);
   static void *newArray_DCH_t(Long_t size, void *p);
   static void delete_DCH_t(void *p);
   static void deleteArray_DCH_t(void *p);
   static void destruct_DCH_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DCH_t*)
   {
      ::DCH_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DCH_t));
      static ::ROOT::TGenericClassInfo 
         instance("DCH_t", "include/bankheader.h", 341,
                  typeid(::DCH_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DCH_t_Dictionary, isa_proxy, 0,
                  sizeof(::DCH_t) );
      instance.SetNew(&new_DCH_t);
      instance.SetNewArray(&newArray_DCH_t);
      instance.SetDelete(&delete_DCH_t);
      instance.SetDeleteArray(&deleteArray_DCH_t);
      instance.SetDestructor(&destruct_DCH_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DCH_t*)
   {
      return GenerateInitInstanceLocal((::DCH_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DCH_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DCH_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DCH_t*)0x0)->GetClass();
      DCH_t_TClassManip(theClass);
   return theClass;
   }

   static void DCH_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DCMN_t_Dictionary();
   static void DCMN_t_TClassManip(TClass*);
   static void *new_DCMN_t(void *p = 0);
   static void *newArray_DCMN_t(Long_t size, void *p);
   static void delete_DCMN_t(void *p);
   static void deleteArray_DCMN_t(void *p);
   static void destruct_DCMN_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DCMN_t*)
   {
      ::DCMN_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DCMN_t));
      static ::ROOT::TGenericClassInfo 
         instance("DCMN_t", "include/bankheader.h", 356,
                  typeid(::DCMN_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DCMN_t_Dictionary, isa_proxy, 0,
                  sizeof(::DCMN_t) );
      instance.SetNew(&new_DCMN_t);
      instance.SetNewArray(&newArray_DCMN_t);
      instance.SetDelete(&delete_DCMN_t);
      instance.SetDeleteArray(&deleteArray_DCMN_t);
      instance.SetDestructor(&destruct_DCMN_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DCMN_t*)
   {
      return GenerateInitInstanceLocal((::DCMN_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DCMN_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DCMN_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DCMN_t*)0x0)->GetClass();
      DCMN_t_TClassManip(theClass);
   return theClass;
   }

   static void DCMN_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DCPB_t_Dictionary();
   static void DCPB_t_TClassManip(TClass*);
   static void *new_DCPB_t(void *p = 0);
   static void *newArray_DCPB_t(Long_t size, void *p);
   static void delete_DCPB_t(void *p);
   static void deleteArray_DCPB_t(void *p);
   static void destruct_DCPB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DCPB_t*)
   {
      ::DCPB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DCPB_t));
      static ::ROOT::TGenericClassInfo 
         instance("DCPB_t", "include/bankheader.h", 408,
                  typeid(::DCPB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DCPB_t_Dictionary, isa_proxy, 0,
                  sizeof(::DCPB_t) );
      instance.SetNew(&new_DCPB_t);
      instance.SetNewArray(&newArray_DCPB_t);
      instance.SetDelete(&delete_DCPB_t);
      instance.SetDeleteArray(&deleteArray_DCPB_t);
      instance.SetDestructor(&destruct_DCPB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DCPB_t*)
   {
      return GenerateInitInstanceLocal((::DCPB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DCPB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DCPB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DCPB_t*)0x0)->GetClass();
      DCPB_t_TClassManip(theClass);
   return theClass;
   }

   static void DCPB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DCV1_t_Dictionary();
   static void DCV1_t_TClassManip(TClass*);
   static void *new_DCV1_t(void *p = 0);
   static void *newArray_DCV1_t(Long_t size, void *p);
   static void delete_DCV1_t(void *p);
   static void deleteArray_DCV1_t(void *p);
   static void destruct_DCV1_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DCV1_t*)
   {
      ::DCV1_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DCV1_t));
      static ::ROOT::TGenericClassInfo 
         instance("DCV1_t", "include/bankheader.h", 423,
                  typeid(::DCV1_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DCV1_t_Dictionary, isa_proxy, 0,
                  sizeof(::DCV1_t) );
      instance.SetNew(&new_DCV1_t);
      instance.SetNewArray(&newArray_DCV1_t);
      instance.SetDelete(&delete_DCV1_t);
      instance.SetDeleteArray(&deleteArray_DCV1_t);
      instance.SetDestructor(&destruct_DCV1_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DCV1_t*)
   {
      return GenerateInitInstanceLocal((::DCV1_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DCV1_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DCV1_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DCV1_t*)0x0)->GetClass();
      DCV1_t_TClassManip(theClass);
   return theClass;
   }

   static void DCV1_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DCV2_t_Dictionary();
   static void DCV2_t_TClassManip(TClass*);
   static void *new_DCV2_t(void *p = 0);
   static void *newArray_DCV2_t(Long_t size, void *p);
   static void delete_DCV2_t(void *p);
   static void deleteArray_DCV2_t(void *p);
   static void destruct_DCV2_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DCV2_t*)
   {
      ::DCV2_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DCV2_t));
      static ::ROOT::TGenericClassInfo 
         instance("DCV2_t", "include/bankheader.h", 430,
                  typeid(::DCV2_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DCV2_t_Dictionary, isa_proxy, 0,
                  sizeof(::DCV2_t) );
      instance.SetNew(&new_DCV2_t);
      instance.SetNewArray(&newArray_DCV2_t);
      instance.SetDelete(&delete_DCV2_t);
      instance.SetDeleteArray(&deleteArray_DCV2_t);
      instance.SetDestructor(&destruct_DCV2_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DCV2_t*)
   {
      return GenerateInitInstanceLocal((::DCV2_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DCV2_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DCV2_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DCV2_t*)0x0)->GetClass();
      DCV2_t_TClassManip(theClass);
   return theClass;
   }

   static void DCV2_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DCV3_t_Dictionary();
   static void DCV3_t_TClassManip(TClass*);
   static void *new_DCV3_t(void *p = 0);
   static void *newArray_DCV3_t(Long_t size, void *p);
   static void delete_DCV3_t(void *p);
   static void deleteArray_DCV3_t(void *p);
   static void destruct_DCV3_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DCV3_t*)
   {
      ::DCV3_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DCV3_t));
      static ::ROOT::TGenericClassInfo 
         instance("DCV3_t", "include/bankheader.h", 446,
                  typeid(::DCV3_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DCV3_t_Dictionary, isa_proxy, 0,
                  sizeof(::DCV3_t) );
      instance.SetNew(&new_DCV3_t);
      instance.SetNewArray(&newArray_DCV3_t);
      instance.SetDelete(&delete_DCV3_t);
      instance.SetDeleteArray(&deleteArray_DCV3_t);
      instance.SetDestructor(&destruct_DCV3_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DCV3_t*)
   {
      return GenerateInitInstanceLocal((::DCV3_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DCV3_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DCV3_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DCV3_t*)0x0)->GetClass();
      DCV3_t_TClassManip(theClass);
   return theClass;
   }

   static void DCV3_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DDLY_t_Dictionary();
   static void DDLY_t_TClassManip(TClass*);
   static void *new_DDLY_t(void *p = 0);
   static void *newArray_DDLY_t(Long_t size, void *p);
   static void delete_DDLY_t(void *p);
   static void deleteArray_DDLY_t(void *p);
   static void destruct_DDLY_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DDLY_t*)
   {
      ::DDLY_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DDLY_t));
      static ::ROOT::TGenericClassInfo 
         instance("DDLY_t", "include/bankheader.h", 453,
                  typeid(::DDLY_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DDLY_t_Dictionary, isa_proxy, 0,
                  sizeof(::DDLY_t) );
      instance.SetNew(&new_DDLY_t);
      instance.SetNewArray(&newArray_DDLY_t);
      instance.SetDelete(&delete_DDLY_t);
      instance.SetDeleteArray(&deleteArray_DDLY_t);
      instance.SetDestructor(&destruct_DDLY_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DDLY_t*)
   {
      return GenerateInitInstanceLocal((::DDLY_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DDLY_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DDLY_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DDLY_t*)0x0)->GetClass();
      DDLY_t_TClassManip(theClass);
   return theClass;
   }

   static void DDLY_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DGEO_t_Dictionary();
   static void DGEO_t_TClassManip(TClass*);
   static void *new_DGEO_t(void *p = 0);
   static void *newArray_DGEO_t(Long_t size, void *p);
   static void delete_DGEO_t(void *p);
   static void deleteArray_DGEO_t(void *p);
   static void destruct_DGEO_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DGEO_t*)
   {
      ::DGEO_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DGEO_t));
      static ::ROOT::TGenericClassInfo 
         instance("DGEO_t", "include/bankheader.h", 458,
                  typeid(::DGEO_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DGEO_t_Dictionary, isa_proxy, 0,
                  sizeof(::DGEO_t) );
      instance.SetNew(&new_DGEO_t);
      instance.SetNewArray(&newArray_DGEO_t);
      instance.SetDelete(&delete_DGEO_t);
      instance.SetDeleteArray(&deleteArray_DGEO_t);
      instance.SetDestructor(&destruct_DGEO_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DGEO_t*)
   {
      return GenerateInitInstanceLocal((::DGEO_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DGEO_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DGEO_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DGEO_t*)0x0)->GetClass();
      DGEO_t_TClassManip(theClass);
   return theClass;
   }

   static void DGEO_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DHCL_t_Dictionary();
   static void DHCL_t_TClassManip(TClass*);
   static void *new_DHCL_t(void *p = 0);
   static void *newArray_DHCL_t(Long_t size, void *p);
   static void delete_DHCL_t(void *p);
   static void deleteArray_DHCL_t(void *p);
   static void destruct_DHCL_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DHCL_t*)
   {
      ::DHCL_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DHCL_t));
      static ::ROOT::TGenericClassInfo 
         instance("DHCL_t", "include/bankheader.h", 468,
                  typeid(::DHCL_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DHCL_t_Dictionary, isa_proxy, 0,
                  sizeof(::DHCL_t) );
      instance.SetNew(&new_DHCL_t);
      instance.SetNewArray(&newArray_DHCL_t);
      instance.SetDelete(&delete_DHCL_t);
      instance.SetDeleteArray(&deleteArray_DHCL_t);
      instance.SetDestructor(&destruct_DHCL_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DHCL_t*)
   {
      return GenerateInitInstanceLocal((::DHCL_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DHCL_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DHCL_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DHCL_t*)0x0)->GetClass();
      DHCL_t_TClassManip(theClass);
   return theClass;
   }

   static void DHCL_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DITM_t_Dictionary();
   static void DITM_t_TClassManip(TClass*);
   static void *new_DITM_t(void *p = 0);
   static void *newArray_DITM_t(Long_t size, void *p);
   static void delete_DITM_t(void *p);
   static void deleteArray_DITM_t(void *p);
   static void destruct_DITM_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DITM_t*)
   {
      ::DITM_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DITM_t));
      static ::ROOT::TGenericClassInfo 
         instance("DITM_t", "include/bankheader.h", 486,
                  typeid(::DITM_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DITM_t_Dictionary, isa_proxy, 0,
                  sizeof(::DITM_t) );
      instance.SetNew(&new_DITM_t);
      instance.SetNewArray(&newArray_DITM_t);
      instance.SetDelete(&delete_DITM_t);
      instance.SetDeleteArray(&deleteArray_DITM_t);
      instance.SetDestructor(&destruct_DITM_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DITM_t*)
   {
      return GenerateInitInstanceLocal((::DITM_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DITM_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DITM_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DITM_t*)0x0)->GetClass();
      DITM_t_TClassManip(theClass);
   return theClass;
   }

   static void DITM_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DOCA_t_Dictionary();
   static void DOCA_t_TClassManip(TClass*);
   static void *new_DOCA_t(void *p = 0);
   static void *newArray_DOCA_t(Long_t size, void *p);
   static void delete_DOCA_t(void *p);
   static void deleteArray_DOCA_t(void *p);
   static void destruct_DOCA_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DOCA_t*)
   {
      ::DOCA_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DOCA_t));
      static ::ROOT::TGenericClassInfo 
         instance("DOCA_t", "include/bankheader.h", 489,
                  typeid(::DOCA_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DOCA_t_Dictionary, isa_proxy, 0,
                  sizeof(::DOCA_t) );
      instance.SetNew(&new_DOCA_t);
      instance.SetNewArray(&newArray_DOCA_t);
      instance.SetDelete(&delete_DOCA_t);
      instance.SetDeleteArray(&deleteArray_DOCA_t);
      instance.SetDestructor(&destruct_DOCA_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DOCA_t*)
   {
      return GenerateInitInstanceLocal((::DOCA_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DOCA_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DOCA_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DOCA_t*)0x0)->GetClass();
      DOCA_t_TClassManip(theClass);
   return theClass;
   }

   static void DOCA_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DPCP_t_Dictionary();
   static void DPCP_t_TClassManip(TClass*);
   static void *new_DPCP_t(void *p = 0);
   static void *newArray_DPCP_t(Long_t size, void *p);
   static void delete_DPCP_t(void *p);
   static void deleteArray_DPCP_t(void *p);
   static void destruct_DPCP_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DPCP_t*)
   {
      ::DPCP_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DPCP_t));
      static ::ROOT::TGenericClassInfo 
         instance("DPCP_t", "include/bankheader.h", 493,
                  typeid(::DPCP_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DPCP_t_Dictionary, isa_proxy, 0,
                  sizeof(::DPCP_t) );
      instance.SetNew(&new_DPCP_t);
      instance.SetNewArray(&newArray_DPCP_t);
      instance.SetDelete(&delete_DPCP_t);
      instance.SetDeleteArray(&deleteArray_DPCP_t);
      instance.SetDestructor(&destruct_DPCP_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DPCP_t*)
   {
      return GenerateInitInstanceLocal((::DPCP_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DPCP_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DPCP_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DPCP_t*)0x0)->GetClass();
      DPCP_t_TClassManip(theClass);
   return theClass;
   }

   static void DPCP_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DPSP_t_Dictionary();
   static void DPSP_t_TClassManip(TClass*);
   static void *new_DPSP_t(void *p = 0);
   static void *newArray_DPSP_t(Long_t size, void *p);
   static void delete_DPSP_t(void *p);
   static void deleteArray_DPSP_t(void *p);
   static void destruct_DPSP_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DPSP_t*)
   {
      ::DPSP_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DPSP_t));
      static ::ROOT::TGenericClassInfo 
         instance("DPSP_t", "include/bankheader.h", 508,
                  typeid(::DPSP_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DPSP_t_Dictionary, isa_proxy, 0,
                  sizeof(::DPSP_t) );
      instance.SetNew(&new_DPSP_t);
      instance.SetNewArray(&newArray_DPSP_t);
      instance.SetDelete(&delete_DPSP_t);
      instance.SetDeleteArray(&deleteArray_DPSP_t);
      instance.SetDestructor(&destruct_DPSP_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DPSP_t*)
   {
      return GenerateInitInstanceLocal((::DPSP_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DPSP_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DPSP_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DPSP_t*)0x0)->GetClass();
      DPSP_t_TClassManip(theClass);
   return theClass;
   }

   static void DPSP_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DSPC_t_Dictionary();
   static void DSPC_t_TClassManip(TClass*);
   static void *new_DSPC_t(void *p = 0);
   static void *newArray_DSPC_t(Long_t size, void *p);
   static void delete_DSPC_t(void *p);
   static void deleteArray_DSPC_t(void *p);
   static void destruct_DSPC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DSPC_t*)
   {
      ::DSPC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DSPC_t));
      static ::ROOT::TGenericClassInfo 
         instance("DSPC_t", "include/bankheader.h", 513,
                  typeid(::DSPC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DSPC_t_Dictionary, isa_proxy, 0,
                  sizeof(::DSPC_t) );
      instance.SetNew(&new_DSPC_t);
      instance.SetNewArray(&newArray_DSPC_t);
      instance.SetDelete(&delete_DSPC_t);
      instance.SetDeleteArray(&deleteArray_DSPC_t);
      instance.SetDestructor(&destruct_DSPC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DSPC_t*)
   {
      return GenerateInitInstanceLocal((::DSPC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DSPC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DSPC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DSPC_t*)0x0)->GetClass();
      DSPC_t_TClassManip(theClass);
   return theClass;
   }

   static void DSPC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DSPS_t_Dictionary();
   static void DSPS_t_TClassManip(TClass*);
   static void *new_DSPS_t(void *p = 0);
   static void *newArray_DSPS_t(Long_t size, void *p);
   static void delete_DSPS_t(void *p);
   static void deleteArray_DSPS_t(void *p);
   static void destruct_DSPS_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DSPS_t*)
   {
      ::DSPS_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DSPS_t));
      static ::ROOT::TGenericClassInfo 
         instance("DSPS_t", "include/bankheader.h", 523,
                  typeid(::DSPS_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DSPS_t_Dictionary, isa_proxy, 0,
                  sizeof(::DSPS_t) );
      instance.SetNew(&new_DSPS_t);
      instance.SetNewArray(&newArray_DSPS_t);
      instance.SetDelete(&delete_DSPS_t);
      instance.SetDeleteArray(&deleteArray_DSPS_t);
      instance.SetDestructor(&destruct_DSPS_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DSPS_t*)
   {
      return GenerateInitInstanceLocal((::DSPS_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DSPS_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DSPS_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DSPS_t*)0x0)->GetClass();
      DSPS_t_TClassManip(theClass);
   return theClass;
   }

   static void DSPS_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DSTC_t_Dictionary();
   static void DSTC_t_TClassManip(TClass*);
   static void *new_DSTC_t(void *p = 0);
   static void *newArray_DSTC_t(Long_t size, void *p);
   static void delete_DSTC_t(void *p);
   static void deleteArray_DSTC_t(void *p);
   static void destruct_DSTC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DSTC_t*)
   {
      ::DSTC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DSTC_t));
      static ::ROOT::TGenericClassInfo 
         instance("DSTC_t", "include/bankheader.h", 528,
                  typeid(::DSTC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DSTC_t_Dictionary, isa_proxy, 0,
                  sizeof(::DSTC_t) );
      instance.SetNew(&new_DSTC_t);
      instance.SetNewArray(&newArray_DSTC_t);
      instance.SetDelete(&delete_DSTC_t);
      instance.SetDeleteArray(&deleteArray_DSTC_t);
      instance.SetDestructor(&destruct_DSTC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DSTC_t*)
   {
      return GenerateInitInstanceLocal((::DSTC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DSTC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DSTC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DSTC_t*)0x0)->GetClass();
      DSTC_t_TClassManip(theClass);
   return theClass;
   }

   static void DSTC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DTCP_t_Dictionary();
   static void DTCP_t_TClassManip(TClass*);
   static void *new_DTCP_t(void *p = 0);
   static void *newArray_DTCP_t(Long_t size, void *p);
   static void delete_DTCP_t(void *p);
   static void deleteArray_DTCP_t(void *p);
   static void destruct_DTCP_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DTCP_t*)
   {
      ::DTCP_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DTCP_t));
      static ::ROOT::TGenericClassInfo 
         instance("DTCP_t", "include/bankheader.h", 539,
                  typeid(::DTCP_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DTCP_t_Dictionary, isa_proxy, 0,
                  sizeof(::DTCP_t) );
      instance.SetNew(&new_DTCP_t);
      instance.SetNewArray(&newArray_DTCP_t);
      instance.SetDelete(&delete_DTCP_t);
      instance.SetDeleteArray(&deleteArray_DTCP_t);
      instance.SetDestructor(&destruct_DTCP_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DTCP_t*)
   {
      return GenerateInitInstanceLocal((::DTCP_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DTCP_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DTCP_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DTCP_t*)0x0)->GetClass();
      DTCP_t_TClassManip(theClass);
   return theClass;
   }

   static void DTCP_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *DTRK_t_Dictionary();
   static void DTRK_t_TClassManip(TClass*);
   static void *new_DTRK_t(void *p = 0);
   static void *newArray_DTRK_t(Long_t size, void *p);
   static void delete_DTRK_t(void *p);
   static void deleteArray_DTRK_t(void *p);
   static void destruct_DTRK_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::DTRK_t*)
   {
      ::DTRK_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::DTRK_t));
      static ::ROOT::TGenericClassInfo 
         instance("DTRK_t", "include/bankheader.h", 556,
                  typeid(::DTRK_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &DTRK_t_Dictionary, isa_proxy, 0,
                  sizeof(::DTRK_t) );
      instance.SetNew(&new_DTRK_t);
      instance.SetNewArray(&newArray_DTRK_t);
      instance.SetDelete(&delete_DTRK_t);
      instance.SetDeleteArray(&deleteArray_DTRK_t);
      instance.SetDestructor(&destruct_DTRK_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::DTRK_t*)
   {
      return GenerateInitInstanceLocal((::DTRK_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::DTRK_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *DTRK_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::DTRK_t*)0x0)->GetClass();
      DTRK_t_TClassManip(theClass);
   return theClass;
   }

   static void DTRK_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *EC01_t_Dictionary();
   static void EC01_t_TClassManip(TClass*);
   static void *new_EC01_t(void *p = 0);
   static void *newArray_EC01_t(Long_t size, void *p);
   static void delete_EC01_t(void *p);
   static void deleteArray_EC01_t(void *p);
   static void destruct_EC01_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EC01_t*)
   {
      ::EC01_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EC01_t));
      static ::ROOT::TGenericClassInfo 
         instance("EC01_t", "include/bankheader.h", 561,
                  typeid(::EC01_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &EC01_t_Dictionary, isa_proxy, 0,
                  sizeof(::EC01_t) );
      instance.SetNew(&new_EC01_t);
      instance.SetNewArray(&newArray_EC01_t);
      instance.SetDelete(&delete_EC01_t);
      instance.SetDeleteArray(&deleteArray_EC01_t);
      instance.SetDestructor(&destruct_EC01_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EC01_t*)
   {
      return GenerateInitInstanceLocal((::EC01_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::EC01_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *EC01_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EC01_t*)0x0)->GetClass();
      EC01_t_TClassManip(theClass);
   return theClass;
   }

   static void EC01_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *EC1_t_Dictionary();
   static void EC1_t_TClassManip(TClass*);
   static void *new_EC1_t(void *p = 0);
   static void *newArray_EC1_t(Long_t size, void *p);
   static void delete_EC1_t(void *p);
   static void deleteArray_EC1_t(void *p);
   static void destruct_EC1_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EC1_t*)
   {
      ::EC1_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EC1_t));
      static ::ROOT::TGenericClassInfo 
         instance("EC1_t", "include/bankheader.h", 566,
                  typeid(::EC1_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &EC1_t_Dictionary, isa_proxy, 0,
                  sizeof(::EC1_t) );
      instance.SetNew(&new_EC1_t);
      instance.SetNewArray(&newArray_EC1_t);
      instance.SetDelete(&delete_EC1_t);
      instance.SetDeleteArray(&deleteArray_EC1_t);
      instance.SetDestructor(&destruct_EC1_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EC1_t*)
   {
      return GenerateInitInstanceLocal((::EC1_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::EC1_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *EC1_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EC1_t*)0x0)->GetClass();
      EC1_t_TClassManip(theClass);
   return theClass;
   }

   static void EC1_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *EC1P_t_Dictionary();
   static void EC1P_t_TClassManip(TClass*);
   static void *new_EC1P_t(void *p = 0);
   static void *newArray_EC1P_t(Long_t size, void *p);
   static void delete_EC1P_t(void *p);
   static void deleteArray_EC1P_t(void *p);
   static void destruct_EC1P_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EC1P_t*)
   {
      ::EC1P_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EC1P_t));
      static ::ROOT::TGenericClassInfo 
         instance("EC1P_t", "include/bankheader.h", 573,
                  typeid(::EC1P_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &EC1P_t_Dictionary, isa_proxy, 0,
                  sizeof(::EC1P_t) );
      instance.SetNew(&new_EC1P_t);
      instance.SetNewArray(&newArray_EC1P_t);
      instance.SetDelete(&delete_EC1P_t);
      instance.SetDeleteArray(&deleteArray_EC1P_t);
      instance.SetDestructor(&destruct_EC1P_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EC1P_t*)
   {
      return GenerateInitInstanceLocal((::EC1P_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::EC1P_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *EC1P_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EC1P_t*)0x0)->GetClass();
      EC1P_t_TClassManip(theClass);
   return theClass;
   }

   static void EC1P_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *EC1R_t_Dictionary();
   static void EC1R_t_TClassManip(TClass*);
   static void *new_EC1R_t(void *p = 0);
   static void *newArray_EC1R_t(Long_t size, void *p);
   static void delete_EC1R_t(void *p);
   static void deleteArray_EC1R_t(void *p);
   static void destruct_EC1R_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EC1R_t*)
   {
      ::EC1R_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EC1R_t));
      static ::ROOT::TGenericClassInfo 
         instance("EC1R_t", "include/bankheader.h", 579,
                  typeid(::EC1R_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &EC1R_t_Dictionary, isa_proxy, 0,
                  sizeof(::EC1R_t) );
      instance.SetNew(&new_EC1R_t);
      instance.SetNewArray(&newArray_EC1R_t);
      instance.SetDelete(&delete_EC1R_t);
      instance.SetDeleteArray(&deleteArray_EC1R_t);
      instance.SetDestructor(&destruct_EC1R_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EC1R_t*)
   {
      return GenerateInitInstanceLocal((::EC1R_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::EC1R_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *EC1R_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EC1R_t*)0x0)->GetClass();
      EC1R_t_TClassManip(theClass);
   return theClass;
   }

   static void EC1R_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECCA_t_Dictionary();
   static void ECCA_t_TClassManip(TClass*);
   static void *new_ECCA_t(void *p = 0);
   static void *newArray_ECCA_t(Long_t size, void *p);
   static void delete_ECCA_t(void *p);
   static void deleteArray_ECCA_t(void *p);
   static void destruct_ECCA_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECCA_t*)
   {
      ::ECCA_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECCA_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECCA_t", "include/bankheader.h", 631,
                  typeid(::ECCA_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECCA_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECCA_t) );
      instance.SetNew(&new_ECCA_t);
      instance.SetNewArray(&newArray_ECCA_t);
      instance.SetDelete(&delete_ECCA_t);
      instance.SetDeleteArray(&deleteArray_ECCA_t);
      instance.SetDestructor(&destruct_ECCA_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECCA_t*)
   {
      return GenerateInitInstanceLocal((::ECCA_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECCA_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECCA_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECCA_t*)0x0)->GetClass();
      ECCA_t_TClassManip(theClass);
   return theClass;
   }

   static void ECCA_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECCL_t_Dictionary();
   static void ECCL_t_TClassManip(TClass*);
   static void *new_ECCL_t(void *p = 0);
   static void *newArray_ECCL_t(Long_t size, void *p);
   static void delete_ECCL_t(void *p);
   static void deleteArray_ECCL_t(void *p);
   static void destruct_ECCL_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECCL_t*)
   {
      ::ECCL_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECCL_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECCL_t", "include/bankheader.h", 641,
                  typeid(::ECCL_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECCL_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECCL_t) );
      instance.SetNew(&new_ECCL_t);
      instance.SetNewArray(&newArray_ECCL_t);
      instance.SetDelete(&delete_ECCL_t);
      instance.SetDeleteArray(&deleteArray_ECCL_t);
      instance.SetDestructor(&destruct_ECCL_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECCL_t*)
   {
      return GenerateInitInstanceLocal((::ECCL_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECCL_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECCL_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECCL_t*)0x0)->GetClass();
      ECCL_t_TClassManip(theClass);
   return theClass;
   }

   static void ECCL_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECCT_t_Dictionary();
   static void ECCT_t_TClassManip(TClass*);
   static void *new_ECCT_t(void *p = 0);
   static void *newArray_ECCT_t(Long_t size, void *p);
   static void delete_ECCT_t(void *p);
   static void deleteArray_ECCT_t(void *p);
   static void destruct_ECCT_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECCT_t*)
   {
      ::ECCT_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECCT_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECCT_t", "include/bankheader.h", 651,
                  typeid(::ECCT_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECCT_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECCT_t) );
      instance.SetNew(&new_ECCT_t);
      instance.SetNewArray(&newArray_ECCT_t);
      instance.SetDelete(&delete_ECCT_t);
      instance.SetDeleteArray(&deleteArray_ECCT_t);
      instance.SetDestructor(&destruct_ECCT_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECCT_t*)
   {
      return GenerateInitInstanceLocal((::ECCT_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECCT_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECCT_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECCT_t*)0x0)->GetClass();
      ECCT_t_TClassManip(theClass);
   return theClass;
   }

   static void ECCT_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *EC_t_Dictionary();
   static void EC_t_TClassManip(TClass*);
   static void *new_EC_t(void *p = 0);
   static void *newArray_EC_t(Long_t size, void *p);
   static void delete_EC_t(void *p);
   static void deleteArray_EC_t(void *p);
   static void destruct_EC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EC_t*)
   {
      ::EC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EC_t));
      static ::ROOT::TGenericClassInfo 
         instance("EC_t", "include/bankheader.h", 665,
                  typeid(::EC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &EC_t_Dictionary, isa_proxy, 0,
                  sizeof(::EC_t) );
      instance.SetNew(&new_EC_t);
      instance.SetNewArray(&newArray_EC_t);
      instance.SetDelete(&delete_EC_t);
      instance.SetDeleteArray(&deleteArray_EC_t);
      instance.SetDestructor(&destruct_EC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EC_t*)
   {
      return GenerateInitInstanceLocal((::EC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::EC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *EC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EC_t*)0x0)->GetClass();
      EC_t_TClassManip(theClass);
   return theClass;
   }

   static void EC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECDI_t_Dictionary();
   static void ECDI_t_TClassManip(TClass*);
   static void *new_ECDI_t(void *p = 0);
   static void *newArray_ECDI_t(Long_t size, void *p);
   static void delete_ECDI_t(void *p);
   static void deleteArray_ECDI_t(void *p);
   static void destruct_ECDI_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECDI_t*)
   {
      ::ECDI_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECDI_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECDI_t", "include/bankheader.h", 670,
                  typeid(::ECDI_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECDI_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECDI_t) );
      instance.SetNew(&new_ECDI_t);
      instance.SetNewArray(&newArray_ECDI_t);
      instance.SetDelete(&delete_ECDI_t);
      instance.SetDeleteArray(&deleteArray_ECDI_t);
      instance.SetDestructor(&destruct_ECDI_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECDI_t*)
   {
      return GenerateInitInstanceLocal((::ECDI_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECDI_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECDI_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECDI_t*)0x0)->GetClass();
      ECDI_t_TClassManip(theClass);
   return theClass;
   }

   static void ECDI_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECG_t_Dictionary();
   static void ECG_t_TClassManip(TClass*);
   static void *new_ECG_t(void *p = 0);
   static void *newArray_ECG_t(Long_t size, void *p);
   static void delete_ECG_t(void *p);
   static void deleteArray_ECG_t(void *p);
   static void destruct_ECG_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECG_t*)
   {
      ::ECG_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECG_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECG_t", "include/bankheader.h", 677,
                  typeid(::ECG_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECG_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECG_t) );
      instance.SetNew(&new_ECG_t);
      instance.SetNewArray(&newArray_ECG_t);
      instance.SetDelete(&delete_ECG_t);
      instance.SetDeleteArray(&deleteArray_ECG_t);
      instance.SetDestructor(&destruct_ECG_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECG_t*)
   {
      return GenerateInitInstanceLocal((::ECG_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECG_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECG_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECG_t*)0x0)->GetClass();
      ECG_t_TClassManip(theClass);
   return theClass;
   }

   static void ECG_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECHB_t_Dictionary();
   static void ECHB_t_TClassManip(TClass*);
   static void *new_ECHB_t(void *p = 0);
   static void *newArray_ECHB_t(Long_t size, void *p);
   static void delete_ECHB_t(void *p);
   static void deleteArray_ECHB_t(void *p);
   static void destruct_ECHB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECHB_t*)
   {
      ::ECHB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECHB_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECHB_t", "include/bankheader.h", 701,
                  typeid(::ECHB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECHB_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECHB_t) );
      instance.SetNew(&new_ECHB_t);
      instance.SetNewArray(&newArray_ECHB_t);
      instance.SetDelete(&delete_ECHB_t);
      instance.SetDeleteArray(&deleteArray_ECHB_t);
      instance.SetDestructor(&destruct_ECHB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECHB_t*)
   {
      return GenerateInitInstanceLocal((::ECHB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECHB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECHB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECHB_t*)0x0)->GetClass();
      ECHB_t_TClassManip(theClass);
   return theClass;
   }

   static void ECHB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECH_t_Dictionary();
   static void ECH_t_TClassManip(TClass*);
   static void *new_ECH_t(void *p = 0);
   static void *newArray_ECH_t(Long_t size, void *p);
   static void delete_ECH_t(void *p);
   static void deleteArray_ECH_t(void *p);
   static void destruct_ECH_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECH_t*)
   {
      ::ECH_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECH_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECH_t", "include/bankheader.h", 741,
                  typeid(::ECH_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECH_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECH_t) );
      instance.SetNew(&new_ECH_t);
      instance.SetNewArray(&newArray_ECH_t);
      instance.SetDelete(&delete_ECH_t);
      instance.SetDeleteArray(&deleteArray_ECH_t);
      instance.SetDestructor(&destruct_ECH_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECH_t*)
   {
      return GenerateInitInstanceLocal((::ECH_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECH_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECH_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECH_t*)0x0)->GetClass();
      ECH_t_TClassManip(theClass);
   return theClass;
   }

   static void ECH_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECMT_t_Dictionary();
   static void ECMT_t_TClassManip(TClass*);
   static void *new_ECMT_t(void *p = 0);
   static void *newArray_ECMT_t(Long_t size, void *p);
   static void delete_ECMT_t(void *p);
   static void deleteArray_ECMT_t(void *p);
   static void destruct_ECMT_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECMT_t*)
   {
      ::ECMT_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECMT_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECMT_t", "include/bankheader.h", 754,
                  typeid(::ECMT_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECMT_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECMT_t) );
      instance.SetNew(&new_ECMT_t);
      instance.SetNewArray(&newArray_ECMT_t);
      instance.SetDelete(&delete_ECMT_t);
      instance.SetDeleteArray(&deleteArray_ECMT_t);
      instance.SetDestructor(&destruct_ECMT_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECMT_t*)
   {
      return GenerateInitInstanceLocal((::ECMT_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECMT_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECMT_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECMT_t*)0x0)->GetClass();
      ECMT_t_TClassManip(theClass);
   return theClass;
   }

   static void ECMT_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECP1_t_Dictionary();
   static void ECP1_t_TClassManip(TClass*);
   static void *new_ECP1_t(void *p = 0);
   static void *newArray_ECP1_t(Long_t size, void *p);
   static void delete_ECP1_t(void *p);
   static void deleteArray_ECP1_t(void *p);
   static void destruct_ECP1_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECP1_t*)
   {
      ::ECP1_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECP1_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECP1_t", "include/bankheader.h", 762,
                  typeid(::ECP1_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECP1_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECP1_t) );
      instance.SetNew(&new_ECP1_t);
      instance.SetNewArray(&newArray_ECP1_t);
      instance.SetDelete(&delete_ECP1_t);
      instance.SetDeleteArray(&deleteArray_ECP1_t);
      instance.SetDestructor(&destruct_ECP1_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECP1_t*)
   {
      return GenerateInitInstanceLocal((::ECP1_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECP1_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECP1_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECP1_t*)0x0)->GetClass();
      ECP1_t_TClassManip(theClass);
   return theClass;
   }

   static void ECP1_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECPB_t_Dictionary();
   static void ECPB_t_TClassManip(TClass*);
   static void *new_ECPB_t(void *p = 0);
   static void *newArray_ECPB_t(Long_t size, void *p);
   static void delete_ECPB_t(void *p);
   static void deleteArray_ECPB_t(void *p);
   static void destruct_ECPB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECPB_t*)
   {
      ::ECPB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECPB_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECPB_t", "include/bankheader.h", 769,
                  typeid(::ECPB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECPB_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECPB_t) );
      instance.SetNew(&new_ECPB_t);
      instance.SetNewArray(&newArray_ECPB_t);
      instance.SetDelete(&delete_ECPB_t);
      instance.SetDeleteArray(&deleteArray_ECPB_t);
      instance.SetDestructor(&destruct_ECPB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECPB_t*)
   {
      return GenerateInitInstanceLocal((::ECPB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECPB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECPB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECPB_t*)0x0)->GetClass();
      ECPB_t_TClassManip(theClass);
   return theClass;
   }

   static void ECPB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECPC_t_Dictionary();
   static void ECPC_t_TClassManip(TClass*);
   static void *new_ECPC_t(void *p = 0);
   static void *newArray_ECPC_t(Long_t size, void *p);
   static void delete_ECPC_t(void *p);
   static void deleteArray_ECPC_t(void *p);
   static void destruct_ECPC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECPC_t*)
   {
      ::ECPC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECPC_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECPC_t", "include/bankheader.h", 787,
                  typeid(::ECPC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECPC_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECPC_t) );
      instance.SetNew(&new_ECPC_t);
      instance.SetNewArray(&newArray_ECPC_t);
      instance.SetDelete(&delete_ECPC_t);
      instance.SetDeleteArray(&deleteArray_ECPC_t);
      instance.SetDestructor(&destruct_ECPC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECPC_t*)
   {
      return GenerateInitInstanceLocal((::ECPC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECPC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECPC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECPC_t*)0x0)->GetClass();
      ECPC_t_TClassManip(theClass);
   return theClass;
   }

   static void ECPC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECP_t_Dictionary();
   static void ECP_t_TClassManip(TClass*);
   static void *new_ECP_t(void *p = 0);
   static void *newArray_ECP_t(Long_t size, void *p);
   static void delete_ECP_t(void *p);
   static void deleteArray_ECP_t(void *p);
   static void destruct_ECP_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECP_t*)
   {
      ::ECP_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECP_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECP_t", "include/bankheader.h", 792,
                  typeid(::ECP_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECP_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECP_t) );
      instance.SetNew(&new_ECP_t);
      instance.SetNewArray(&newArray_ECP_t);
      instance.SetDelete(&delete_ECP_t);
      instance.SetDeleteArray(&deleteArray_ECP_t);
      instance.SetDestructor(&destruct_ECP_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECP_t*)
   {
      return GenerateInitInstanceLocal((::ECP_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECP_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECP_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECP_t*)0x0)->GetClass();
      ECP_t_TClassManip(theClass);
   return theClass;
   }

   static void ECP_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECPE_t_Dictionary();
   static void ECPE_t_TClassManip(TClass*);
   static void *new_ECPE_t(void *p = 0);
   static void *newArray_ECPE_t(Long_t size, void *p);
   static void delete_ECPE_t(void *p);
   static void deleteArray_ECPE_t(void *p);
   static void destruct_ECPE_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECPE_t*)
   {
      ::ECPE_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECPE_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECPE_t", "include/bankheader.h", 801,
                  typeid(::ECPE_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECPE_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECPE_t) );
      instance.SetNew(&new_ECPE_t);
      instance.SetNewArray(&newArray_ECPE_t);
      instance.SetDelete(&delete_ECPE_t);
      instance.SetDeleteArray(&deleteArray_ECPE_t);
      instance.SetDestructor(&destruct_ECPE_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECPE_t*)
   {
      return GenerateInitInstanceLocal((::ECPE_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECPE_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECPE_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECPE_t*)0x0)->GetClass();
      ECPE_t_TClassManip(theClass);
   return theClass;
   }

   static void ECPE_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECPI_t_Dictionary();
   static void ECPI_t_TClassManip(TClass*);
   static void *new_ECPI_t(void *p = 0);
   static void *newArray_ECPI_t(Long_t size, void *p);
   static void delete_ECPI_t(void *p);
   static void deleteArray_ECPI_t(void *p);
   static void destruct_ECPI_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECPI_t*)
   {
      ::ECPI_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECPI_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECPI_t", "include/bankheader.h", 806,
                  typeid(::ECPI_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECPI_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECPI_t) );
      instance.SetNew(&new_ECPI_t);
      instance.SetNewArray(&newArray_ECPI_t);
      instance.SetDelete(&delete_ECPI_t);
      instance.SetDeleteArray(&deleteArray_ECPI_t);
      instance.SetDestructor(&destruct_ECPI_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECPI_t*)
   {
      return GenerateInitInstanceLocal((::ECPI_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECPI_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECPI_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECPI_t*)0x0)->GetClass();
      ECPI_t_TClassManip(theClass);
   return theClass;
   }

   static void ECPI_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECPO_t_Dictionary();
   static void ECPO_t_TClassManip(TClass*);
   static void *new_ECPO_t(void *p = 0);
   static void *newArray_ECPO_t(Long_t size, void *p);
   static void delete_ECPO_t(void *p);
   static void deleteArray_ECPO_t(void *p);
   static void destruct_ECPO_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECPO_t*)
   {
      ::ECPO_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECPO_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECPO_t", "include/bankheader.h", 817,
                  typeid(::ECPO_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECPO_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECPO_t) );
      instance.SetNew(&new_ECPO_t);
      instance.SetNewArray(&newArray_ECPO_t);
      instance.SetDelete(&delete_ECPO_t);
      instance.SetDeleteArray(&deleteArray_ECPO_t);
      instance.SetDestructor(&destruct_ECPO_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECPO_t*)
   {
      return GenerateInitInstanceLocal((::ECPO_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECPO_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECPO_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECPO_t*)0x0)->GetClass();
      ECPO_t_TClassManip(theClass);
   return theClass;
   }

   static void ECPO_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECRB_t_Dictionary();
   static void ECRB_t_TClassManip(TClass*);
   static void *new_ECRB_t(void *p = 0);
   static void *newArray_ECRB_t(Long_t size, void *p);
   static void delete_ECRB_t(void *p);
   static void deleteArray_ECRB_t(void *p);
   static void destruct_ECRB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECRB_t*)
   {
      ::ECRB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECRB_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECRB_t", "include/bankheader.h", 826,
                  typeid(::ECRB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECRB_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECRB_t) );
      instance.SetNew(&new_ECRB_t);
      instance.SetNewArray(&newArray_ECRB_t);
      instance.SetDelete(&delete_ECRB_t);
      instance.SetDeleteArray(&deleteArray_ECRB_t);
      instance.SetDestructor(&destruct_ECRB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECRB_t*)
   {
      return GenerateInitInstanceLocal((::ECRB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECRB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECRB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECRB_t*)0x0)->GetClass();
      ECRB_t_TClassManip(theClass);
   return theClass;
   }

   static void ECRB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ECS_t_Dictionary();
   static void ECS_t_TClassManip(TClass*);
   static void *new_ECS_t(void *p = 0);
   static void *newArray_ECS_t(Long_t size, void *p);
   static void delete_ECS_t(void *p);
   static void deleteArray_ECS_t(void *p);
   static void destruct_ECS_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ECS_t*)
   {
      ::ECS_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ECS_t));
      static ::ROOT::TGenericClassInfo 
         instance("ECS_t", "include/bankheader.h", 877,
                  typeid(::ECS_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ECS_t_Dictionary, isa_proxy, 0,
                  sizeof(::ECS_t) );
      instance.SetNew(&new_ECS_t);
      instance.SetNewArray(&newArray_ECS_t);
      instance.SetDelete(&delete_ECS_t);
      instance.SetDeleteArray(&deleteArray_ECS_t);
      instance.SetDestructor(&destruct_ECS_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ECS_t*)
   {
      return GenerateInitInstanceLocal((::ECS_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ECS_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ECS_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ECS_t*)0x0)->GetClass();
      ECS_t_TClassManip(theClass);
   return theClass;
   }

   static void ECS_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *EID0_t_Dictionary();
   static void EID0_t_TClassManip(TClass*);
   static void *new_EID0_t(void *p = 0);
   static void *newArray_EID0_t(Long_t size, void *p);
   static void delete_EID0_t(void *p);
   static void deleteArray_EID0_t(void *p);
   static void destruct_EID0_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EID0_t*)
   {
      ::EID0_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EID0_t));
      static ::ROOT::TGenericClassInfo 
         instance("EID0_t", "include/bankheader.h", 975,
                  typeid(::EID0_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &EID0_t_Dictionary, isa_proxy, 0,
                  sizeof(::EID0_t) );
      instance.SetNew(&new_EID0_t);
      instance.SetNewArray(&newArray_EID0_t);
      instance.SetDelete(&delete_EID0_t);
      instance.SetDeleteArray(&deleteArray_EID0_t);
      instance.SetDestructor(&destruct_EID0_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EID0_t*)
   {
      return GenerateInitInstanceLocal((::EID0_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::EID0_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *EID0_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EID0_t*)0x0)->GetClass();
      EID0_t_TClassManip(theClass);
   return theClass;
   }

   static void EID0_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *EPIC_t_Dictionary();
   static void EPIC_t_TClassManip(TClass*);
   static void *new_EPIC_t(void *p = 0);
   static void *newArray_EPIC_t(Long_t size, void *p);
   static void delete_EPIC_t(void *p);
   static void deleteArray_EPIC_t(void *p);
   static void destruct_EPIC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EPIC_t*)
   {
      ::EPIC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EPIC_t));
      static ::ROOT::TGenericClassInfo 
         instance("EPIC_t", "include/bankheader.h", 981,
                  typeid(::EPIC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &EPIC_t_Dictionary, isa_proxy, 0,
                  sizeof(::EPIC_t) );
      instance.SetNew(&new_EPIC_t);
      instance.SetNewArray(&newArray_EPIC_t);
      instance.SetDelete(&delete_EPIC_t);
      instance.SetDeleteArray(&deleteArray_EPIC_t);
      instance.SetDestructor(&destruct_EPIC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EPIC_t*)
   {
      return GenerateInitInstanceLocal((::EPIC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::EPIC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *EPIC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EPIC_t*)0x0)->GetClass();
      EPIC_t_TClassManip(theClass);
   return theClass;
   }

   static void EPIC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *EVNT_t_Dictionary();
   static void EVNT_t_TClassManip(TClass*);
   static void *new_EVNT_t(void *p = 0);
   static void *newArray_EVNT_t(Long_t size, void *p);
   static void delete_EVNT_t(void *p);
   static void deleteArray_EVNT_t(void *p);
   static void destruct_EVNT_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EVNT_t*)
   {
      ::EVNT_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::EVNT_t));
      static ::ROOT::TGenericClassInfo 
         instance("EVNT_t", "include/bankheader.h", 985,
                  typeid(::EVNT_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &EVNT_t_Dictionary, isa_proxy, 0,
                  sizeof(::EVNT_t) );
      instance.SetNew(&new_EVNT_t);
      instance.SetNewArray(&newArray_EVNT_t);
      instance.SetDelete(&delete_EVNT_t);
      instance.SetDeleteArray(&deleteArray_EVNT_t);
      instance.SetDestructor(&destruct_EVNT_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EVNT_t*)
   {
      return GenerateInitInstanceLocal((::EVNT_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::EVNT_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *EVNT_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::EVNT_t*)0x0)->GetClass();
      EVNT_t_TClassManip(theClass);
   return theClass;
   }

   static void EVNT_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *FBPM_t_Dictionary();
   static void FBPM_t_TClassManip(TClass*);
   static void *new_FBPM_t(void *p = 0);
   static void *newArray_FBPM_t(Long_t size, void *p);
   static void delete_FBPM_t(void *p);
   static void deleteArray_FBPM_t(void *p);
   static void destruct_FBPM_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::FBPM_t*)
   {
      ::FBPM_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::FBPM_t));
      static ::ROOT::TGenericClassInfo 
         instance("FBPM_t", "include/bankheader.h", 1005,
                  typeid(::FBPM_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &FBPM_t_Dictionary, isa_proxy, 0,
                  sizeof(::FBPM_t) );
      instance.SetNew(&new_FBPM_t);
      instance.SetNewArray(&newArray_FBPM_t);
      instance.SetDelete(&delete_FBPM_t);
      instance.SetDeleteArray(&deleteArray_FBPM_t);
      instance.SetDestructor(&destruct_FBPM_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::FBPM_t*)
   {
      return GenerateInitInstanceLocal((::FBPM_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::FBPM_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *FBPM_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::FBPM_t*)0x0)->GetClass();
      FBPM_t_TClassManip(theClass);
   return theClass;
   }

   static void FBPM_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *G1SL_t_Dictionary();
   static void G1SL_t_TClassManip(TClass*);
   static void *new_G1SL_t(void *p = 0);
   static void *newArray_G1SL_t(Long_t size, void *p);
   static void delete_G1SL_t(void *p);
   static void deleteArray_G1SL_t(void *p);
   static void destruct_G1SL_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::G1SL_t*)
   {
      ::G1SL_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::G1SL_t));
      static ::ROOT::TGenericClassInfo 
         instance("G1SL_t", "include/bankheader.h", 1010,
                  typeid(::G1SL_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &G1SL_t_Dictionary, isa_proxy, 0,
                  sizeof(::G1SL_t) );
      instance.SetNew(&new_G1SL_t);
      instance.SetNewArray(&newArray_G1SL_t);
      instance.SetDelete(&delete_G1SL_t);
      instance.SetDeleteArray(&deleteArray_G1SL_t);
      instance.SetDestructor(&destruct_G1SL_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::G1SL_t*)
   {
      return GenerateInitInstanceLocal((::G1SL_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::G1SL_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *G1SL_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::G1SL_t*)0x0)->GetClass();
      G1SL_t_TClassManip(theClass);
   return theClass;
   }

   static void G1SL_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *G2SL_t_Dictionary();
   static void G2SL_t_TClassManip(TClass*);
   static void *new_G2SL_t(void *p = 0);
   static void *newArray_G2SL_t(Long_t size, void *p);
   static void delete_G2SL_t(void *p);
   static void deleteArray_G2SL_t(void *p);
   static void destruct_G2SL_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::G2SL_t*)
   {
      ::G2SL_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::G2SL_t));
      static ::ROOT::TGenericClassInfo 
         instance("G2SL_t", "include/bankheader.h", 1076,
                  typeid(::G2SL_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &G2SL_t_Dictionary, isa_proxy, 0,
                  sizeof(::G2SL_t) );
      instance.SetNew(&new_G2SL_t);
      instance.SetNewArray(&newArray_G2SL_t);
      instance.SetDelete(&delete_G2SL_t);
      instance.SetDeleteArray(&deleteArray_G2SL_t);
      instance.SetDestructor(&destruct_G2SL_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::G2SL_t*)
   {
      return GenerateInitInstanceLocal((::G2SL_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::G2SL_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *G2SL_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::G2SL_t*)0x0)->GetClass();
      G2SL_t_TClassManip(theClass);
   return theClass;
   }

   static void G2SL_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *G3SL_t_Dictionary();
   static void G3SL_t_TClassManip(TClass*);
   static void *new_G3SL_t(void *p = 0);
   static void *newArray_G3SL_t(Long_t size, void *p);
   static void delete_G3SL_t(void *p);
   static void deleteArray_G3SL_t(void *p);
   static void destruct_G3SL_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::G3SL_t*)
   {
      ::G3SL_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::G3SL_t));
      static ::ROOT::TGenericClassInfo 
         instance("G3SL_t", "include/bankheader.h", 1142,
                  typeid(::G3SL_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &G3SL_t_Dictionary, isa_proxy, 0,
                  sizeof(::G3SL_t) );
      instance.SetNew(&new_G3SL_t);
      instance.SetNewArray(&newArray_G3SL_t);
      instance.SetDelete(&delete_G3SL_t);
      instance.SetDeleteArray(&deleteArray_G3SL_t);
      instance.SetDestructor(&destruct_G3SL_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::G3SL_t*)
   {
      return GenerateInitInstanceLocal((::G3SL_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::G3SL_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *G3SL_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::G3SL_t*)0x0)->GetClass();
      G3SL_t_TClassManip(theClass);
   return theClass;
   }

   static void G3SL_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *G4SL_t_Dictionary();
   static void G4SL_t_TClassManip(TClass*);
   static void *new_G4SL_t(void *p = 0);
   static void *newArray_G4SL_t(Long_t size, void *p);
   static void delete_G4SL_t(void *p);
   static void deleteArray_G4SL_t(void *p);
   static void destruct_G4SL_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::G4SL_t*)
   {
      ::G4SL_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::G4SL_t));
      static ::ROOT::TGenericClassInfo 
         instance("G4SL_t", "include/bankheader.h", 1208,
                  typeid(::G4SL_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &G4SL_t_Dictionary, isa_proxy, 0,
                  sizeof(::G4SL_t) );
      instance.SetNew(&new_G4SL_t);
      instance.SetNewArray(&newArray_G4SL_t);
      instance.SetDelete(&delete_G4SL_t);
      instance.SetDeleteArray(&deleteArray_G4SL_t);
      instance.SetDestructor(&destruct_G4SL_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::G4SL_t*)
   {
      return GenerateInitInstanceLocal((::G4SL_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::G4SL_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *G4SL_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::G4SL_t*)0x0)->GetClass();
      G4SL_t_TClassManip(theClass);
   return theClass;
   }

   static void G4SL_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GPAR_t_Dictionary();
   static void GPAR_t_TClassManip(TClass*);
   static void *new_GPAR_t(void *p = 0);
   static void *newArray_GPAR_t(Long_t size, void *p);
   static void delete_GPAR_t(void *p);
   static void deleteArray_GPAR_t(void *p);
   static void destruct_GPAR_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::GPAR_t*)
   {
      ::GPAR_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::GPAR_t));
      static ::ROOT::TGenericClassInfo 
         instance("GPAR_t", "include/bankheader.h", 1274,
                  typeid(::GPAR_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GPAR_t_Dictionary, isa_proxy, 0,
                  sizeof(::GPAR_t) );
      instance.SetNew(&new_GPAR_t);
      instance.SetNewArray(&newArray_GPAR_t);
      instance.SetDelete(&delete_GPAR_t);
      instance.SetDeleteArray(&deleteArray_GPAR_t);
      instance.SetDestructor(&destruct_GPAR_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::GPAR_t*)
   {
      return GenerateInitInstanceLocal((::GPAR_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::GPAR_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GPAR_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::GPAR_t*)0x0)->GetClass();
      GPAR_t_TClassManip(theClass);
   return theClass;
   }

   static void GPAR_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GPID_t_Dictionary();
   static void GPID_t_TClassManip(TClass*);
   static void *new_GPID_t(void *p = 0);
   static void *newArray_GPID_t(Long_t size, void *p);
   static void delete_GPID_t(void *p);
   static void deleteArray_GPID_t(void *p);
   static void destruct_GPID_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::GPID_t*)
   {
      ::GPID_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::GPID_t));
      static ::ROOT::TGenericClassInfo 
         instance("GPID_t", "include/bankheader.h", 1279,
                  typeid(::GPID_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GPID_t_Dictionary, isa_proxy, 0,
                  sizeof(::GPID_t) );
      instance.SetNew(&new_GPID_t);
      instance.SetNewArray(&newArray_GPID_t);
      instance.SetDelete(&delete_GPID_t);
      instance.SetDeleteArray(&deleteArray_GPID_t);
      instance.SetDestructor(&destruct_GPID_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::GPID_t*)
   {
      return GenerateInitInstanceLocal((::GPID_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::GPID_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GPID_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::GPID_t*)0x0)->GetClass();
      GPID_t_TClassManip(theClass);
   return theClass;
   }

   static void GPID_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GP_X_t_Dictionary();
   static void GP_X_t_TClassManip(TClass*);
   static void *new_GP_X_t(void *p = 0);
   static void *newArray_GP_X_t(Long_t size, void *p);
   static void delete_GP_X_t(void *p);
   static void deleteArray_GP_X_t(void *p);
   static void destruct_GP_X_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::GP_X_t*)
   {
      ::GP_X_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::GP_X_t));
      static ::ROOT::TGenericClassInfo 
         instance("GP_X_t", "include/bankheader.h", 1309,
                  typeid(::GP_X_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GP_X_t_Dictionary, isa_proxy, 0,
                  sizeof(::GP_X_t) );
      instance.SetNew(&new_GP_X_t);
      instance.SetNewArray(&newArray_GP_X_t);
      instance.SetDelete(&delete_GP_X_t);
      instance.SetDeleteArray(&deleteArray_GP_X_t);
      instance.SetDestructor(&destruct_GP_X_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::GP_X_t*)
   {
      return GenerateInitInstanceLocal((::GP_X_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::GP_X_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GP_X_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::GP_X_t*)0x0)->GetClass();
      GP_X_t_TClassManip(theClass);
   return theClass;
   }

   static void GP_X_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *GP_Y_t_Dictionary();
   static void GP_Y_t_TClassManip(TClass*);
   static void *new_GP_Y_t(void *p = 0);
   static void *newArray_GP_Y_t(Long_t size, void *p);
   static void delete_GP_Y_t(void *p);
   static void deleteArray_GP_Y_t(void *p);
   static void destruct_GP_Y_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::GP_Y_t*)
   {
      ::GP_Y_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::GP_Y_t));
      static ::ROOT::TGenericClassInfo 
         instance("GP_Y_t", "include/bankheader.h", 1312,
                  typeid(::GP_Y_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &GP_Y_t_Dictionary, isa_proxy, 0,
                  sizeof(::GP_Y_t) );
      instance.SetNew(&new_GP_Y_t);
      instance.SetNewArray(&newArray_GP_Y_t);
      instance.SetDelete(&delete_GP_Y_t);
      instance.SetDeleteArray(&deleteArray_GP_Y_t);
      instance.SetDestructor(&destruct_GP_Y_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::GP_Y_t*)
   {
      return GenerateInitInstanceLocal((::GP_Y_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::GP_Y_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *GP_Y_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::GP_Y_t*)0x0)->GetClass();
      GP_Y_t_TClassManip(theClass);
   return theClass;
   }

   static void GP_Y_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HBER_t_Dictionary();
   static void HBER_t_TClassManip(TClass*);
   static void *new_HBER_t(void *p = 0);
   static void *newArray_HBER_t(Long_t size, void *p);
   static void delete_HBER_t(void *p);
   static void deleteArray_HBER_t(void *p);
   static void destruct_HBER_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HBER_t*)
   {
      ::HBER_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HBER_t));
      static ::ROOT::TGenericClassInfo 
         instance("HBER_t", "include/bankheader.h", 1315,
                  typeid(::HBER_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HBER_t_Dictionary, isa_proxy, 0,
                  sizeof(::HBER_t) );
      instance.SetNew(&new_HBER_t);
      instance.SetNewArray(&newArray_HBER_t);
      instance.SetDelete(&delete_HBER_t);
      instance.SetDeleteArray(&deleteArray_HBER_t);
      instance.SetDestructor(&destruct_HBER_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HBER_t*)
   {
      return GenerateInitInstanceLocal((::HBER_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HBER_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HBER_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HBER_t*)0x0)->GetClass();
      HBER_t_TClassManip(theClass);
   return theClass;
   }

   static void HBER_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HBID_t_Dictionary();
   static void HBID_t_TClassManip(TClass*);
   static void *new_HBID_t(void *p = 0);
   static void *newArray_HBID_t(Long_t size, void *p);
   static void delete_HBID_t(void *p);
   static void deleteArray_HBID_t(void *p);
   static void destruct_HBID_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HBID_t*)
   {
      ::HBID_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HBID_t));
      static ::ROOT::TGenericClassInfo 
         instance("HBID_t", "include/bankheader.h", 1340,
                  typeid(::HBID_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HBID_t_Dictionary, isa_proxy, 0,
                  sizeof(::HBID_t) );
      instance.SetNew(&new_HBID_t);
      instance.SetNewArray(&newArray_HBID_t);
      instance.SetDelete(&delete_HBID_t);
      instance.SetDeleteArray(&deleteArray_HBID_t);
      instance.SetDestructor(&destruct_HBID_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HBID_t*)
   {
      return GenerateInitInstanceLocal((::HBID_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HBID_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HBID_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HBID_t*)0x0)->GetClass();
      HBID_t_TClassManip(theClass);
   return theClass;
   }

   static void HBID_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HBLA_t_Dictionary();
   static void HBLA_t_TClassManip(TClass*);
   static void *new_HBLA_t(void *p = 0);
   static void *newArray_HBLA_t(Long_t size, void *p);
   static void delete_HBLA_t(void *p);
   static void deleteArray_HBLA_t(void *p);
   static void destruct_HBLA_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HBLA_t*)
   {
      ::HBLA_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HBLA_t));
      static ::ROOT::TGenericClassInfo 
         instance("HBLA_t", "include/bankheader.h", 1376,
                  typeid(::HBLA_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HBLA_t_Dictionary, isa_proxy, 0,
                  sizeof(::HBLA_t) );
      instance.SetNew(&new_HBLA_t);
      instance.SetNewArray(&newArray_HBLA_t);
      instance.SetDelete(&delete_HBLA_t);
      instance.SetDeleteArray(&deleteArray_HBLA_t);
      instance.SetDestructor(&destruct_HBLA_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HBLA_t*)
   {
      return GenerateInitInstanceLocal((::HBLA_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HBLA_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HBLA_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HBLA_t*)0x0)->GetClass();
      HBLA_t_TClassManip(theClass);
   return theClass;
   }

   static void HBLA_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HBTB_t_Dictionary();
   static void HBTB_t_TClassManip(TClass*);
   static void *new_HBTB_t(void *p = 0);
   static void *newArray_HBTB_t(Long_t size, void *p);
   static void delete_HBTB_t(void *p);
   static void deleteArray_HBTB_t(void *p);
   static void destruct_HBTB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HBTB_t*)
   {
      ::HBTB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HBTB_t));
      static ::ROOT::TGenericClassInfo 
         instance("HBTB_t", "include/bankheader.h", 1394,
                  typeid(::HBTB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HBTB_t_Dictionary, isa_proxy, 0,
                  sizeof(::HBTB_t) );
      instance.SetNew(&new_HBTB_t);
      instance.SetNewArray(&newArray_HBTB_t);
      instance.SetDelete(&delete_HBTB_t);
      instance.SetDeleteArray(&deleteArray_HBTB_t);
      instance.SetDestructor(&destruct_HBTB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HBTB_t*)
   {
      return GenerateInitInstanceLocal((::HBTB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HBTB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HBTB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HBTB_t*)0x0)->GetClass();
      HBTB_t_TClassManip(theClass);
   return theClass;
   }

   static void HBTB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HBTR_t_Dictionary();
   static void HBTR_t_TClassManip(TClass*);
   static void *new_HBTR_t(void *p = 0);
   static void *newArray_HBTR_t(Long_t size, void *p);
   static void delete_HBTR_t(void *p);
   static void deleteArray_HBTR_t(void *p);
   static void destruct_HBTR_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HBTR_t*)
   {
      ::HBTR_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HBTR_t));
      static ::ROOT::TGenericClassInfo 
         instance("HBTR_t", "include/bankheader.h", 1406,
                  typeid(::HBTR_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HBTR_t_Dictionary, isa_proxy, 0,
                  sizeof(::HBTR_t) );
      instance.SetNew(&new_HBTR_t);
      instance.SetNewArray(&newArray_HBTR_t);
      instance.SetDelete(&delete_HBTR_t);
      instance.SetDeleteArray(&deleteArray_HBTR_t);
      instance.SetDestructor(&destruct_HBTR_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HBTR_t*)
   {
      return GenerateInitInstanceLocal((::HBTR_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HBTR_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HBTR_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HBTR_t*)0x0)->GetClass();
      HBTR_t_TClassManip(theClass);
   return theClass;
   }

   static void HBTR_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HCAL_t_Dictionary();
   static void HCAL_t_TClassManip(TClass*);
   static void *new_HCAL_t(void *p = 0);
   static void *newArray_HCAL_t(Long_t size, void *p);
   static void delete_HCAL_t(void *p);
   static void deleteArray_HCAL_t(void *p);
   static void destruct_HCAL_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HCAL_t*)
   {
      ::HCAL_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HCAL_t));
      static ::ROOT::TGenericClassInfo 
         instance("HCAL_t", "include/bankheader.h", 1417,
                  typeid(::HCAL_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HCAL_t_Dictionary, isa_proxy, 0,
                  sizeof(::HCAL_t) );
      instance.SetNew(&new_HCAL_t);
      instance.SetNewArray(&newArray_HCAL_t);
      instance.SetDelete(&delete_HCAL_t);
      instance.SetDeleteArray(&deleteArray_HCAL_t);
      instance.SetDestructor(&destruct_HCAL_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HCAL_t*)
   {
      return GenerateInitInstanceLocal((::HCAL_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HCAL_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HCAL_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HCAL_t*)0x0)->GetClass();
      HCAL_t_TClassManip(theClass);
   return theClass;
   }

   static void HCAL_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HDPL_t_Dictionary();
   static void HDPL_t_TClassManip(TClass*);
   static void *new_HDPL_t(void *p = 0);
   static void *newArray_HDPL_t(Long_t size, void *p);
   static void delete_HDPL_t(void *p);
   static void deleteArray_HDPL_t(void *p);
   static void destruct_HDPL_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HDPL_t*)
   {
      ::HDPL_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HDPL_t));
      static ::ROOT::TGenericClassInfo 
         instance("HDPL_t", "include/bankheader.h", 1424,
                  typeid(::HDPL_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HDPL_t_Dictionary, isa_proxy, 0,
                  sizeof(::HDPL_t) );
      instance.SetNew(&new_HDPL_t);
      instance.SetNewArray(&newArray_HDPL_t);
      instance.SetDelete(&delete_HDPL_t);
      instance.SetDeleteArray(&deleteArray_HDPL_t);
      instance.SetDestructor(&destruct_HDPL_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HDPL_t*)
   {
      return GenerateInitInstanceLocal((::HDPL_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HDPL_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HDPL_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HDPL_t*)0x0)->GetClass();
      HDPL_t_TClassManip(theClass);
   return theClass;
   }

   static void HDPL_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HEAD_t_Dictionary();
   static void HEAD_t_TClassManip(TClass*);
   static void *new_HEAD_t(void *p = 0);
   static void *newArray_HEAD_t(Long_t size, void *p);
   static void delete_HEAD_t(void *p);
   static void deleteArray_HEAD_t(void *p);
   static void destruct_HEAD_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HEAD_t*)
   {
      ::HEAD_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HEAD_t));
      static ::ROOT::TGenericClassInfo 
         instance("HEAD_t", "include/bankheader.h", 1434,
                  typeid(::HEAD_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HEAD_t_Dictionary, isa_proxy, 0,
                  sizeof(::HEAD_t) );
      instance.SetNew(&new_HEAD_t);
      instance.SetNewArray(&newArray_HEAD_t);
      instance.SetDelete(&delete_HEAD_t);
      instance.SetDeleteArray(&deleteArray_HEAD_t);
      instance.SetDestructor(&destruct_HEAD_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HEAD_t*)
   {
      return GenerateInitInstanceLocal((::HEAD_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HEAD_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HEAD_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HEAD_t*)0x0)->GetClass();
      HEAD_t_TClassManip(theClass);
   return theClass;
   }

   static void HEAD_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HEVT_t_Dictionary();
   static void HEVT_t_TClassManip(TClass*);
   static void *new_HEVT_t(void *p = 0);
   static void *newArray_HEVT_t(Long_t size, void *p);
   static void delete_HEVT_t(void *p);
   static void deleteArray_HEVT_t(void *p);
   static void destruct_HEVT_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HEVT_t*)
   {
      ::HEVT_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HEVT_t));
      static ::ROOT::TGenericClassInfo 
         instance("HEVT_t", "include/bankheader.h", 1444,
                  typeid(::HEVT_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HEVT_t_Dictionary, isa_proxy, 0,
                  sizeof(::HEVT_t) );
      instance.SetNew(&new_HEVT_t);
      instance.SetNewArray(&newArray_HEVT_t);
      instance.SetDelete(&delete_HEVT_t);
      instance.SetDeleteArray(&deleteArray_HEVT_t);
      instance.SetDestructor(&destruct_HEVT_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HEVT_t*)
   {
      return GenerateInitInstanceLocal((::HEVT_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HEVT_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HEVT_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HEVT_t*)0x0)->GetClass();
      HEVT_t_TClassManip(theClass);
   return theClass;
   }

   static void HEVT_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *HLS_t_Dictionary();
   static void HLS_t_TClassManip(TClass*);
   static void *new_HLS_t(void *p = 0);
   static void *newArray_HLS_t(Long_t size, void *p);
   static void delete_HLS_t(void *p);
   static void deleteArray_HLS_t(void *p);
   static void destruct_HLS_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HLS_t*)
   {
      ::HLS_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::HLS_t));
      static ::ROOT::TGenericClassInfo 
         instance("HLS_t", "include/bankheader.h", 1462,
                  typeid(::HLS_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &HLS_t_Dictionary, isa_proxy, 0,
                  sizeof(::HLS_t) );
      instance.SetNew(&new_HLS_t);
      instance.SetNewArray(&newArray_HLS_t);
      instance.SetDelete(&delete_HLS_t);
      instance.SetDeleteArray(&deleteArray_HLS_t);
      instance.SetDestructor(&destruct_HLS_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HLS_t*)
   {
      return GenerateInitInstanceLocal((::HLS_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HLS_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *HLS_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::HLS_t*)0x0)->GetClass();
      HLS_t_TClassManip(theClass);
   return theClass;
   }

   static void HLS_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *IC_t_Dictionary();
   static void IC_t_TClassManip(TClass*);
   static void *new_IC_t(void *p = 0);
   static void *newArray_IC_t(Long_t size, void *p);
   static void delete_IC_t(void *p);
   static void deleteArray_IC_t(void *p);
   static void destruct_IC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::IC_t*)
   {
      ::IC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::IC_t));
      static ::ROOT::TGenericClassInfo 
         instance("IC_t", "include/bankheader.h", 1480,
                  typeid(::IC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &IC_t_Dictionary, isa_proxy, 0,
                  sizeof(::IC_t) );
      instance.SetNew(&new_IC_t);
      instance.SetNewArray(&newArray_IC_t);
      instance.SetDelete(&delete_IC_t);
      instance.SetDeleteArray(&deleteArray_IC_t);
      instance.SetDestructor(&destruct_IC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::IC_t*)
   {
      return GenerateInitInstanceLocal((::IC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::IC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *IC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::IC_t*)0x0)->GetClass();
      IC_t_TClassManip(theClass);
   return theClass;
   }

   static void IC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ICHB_t_Dictionary();
   static void ICHB_t_TClassManip(TClass*);
   static void *new_ICHB_t(void *p = 0);
   static void *newArray_ICHB_t(Long_t size, void *p);
   static void delete_ICHB_t(void *p);
   static void deleteArray_ICHB_t(void *p);
   static void destruct_ICHB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ICHB_t*)
   {
      ::ICHB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ICHB_t));
      static ::ROOT::TGenericClassInfo 
         instance("ICHB_t", "include/bankheader.h", 1485,
                  typeid(::ICHB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ICHB_t_Dictionary, isa_proxy, 0,
                  sizeof(::ICHB_t) );
      instance.SetNew(&new_ICHB_t);
      instance.SetNewArray(&newArray_ICHB_t);
      instance.SetDelete(&delete_ICHB_t);
      instance.SetDeleteArray(&deleteArray_ICHB_t);
      instance.SetDestructor(&destruct_ICHB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ICHB_t*)
   {
      return GenerateInitInstanceLocal((::ICHB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ICHB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ICHB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ICHB_t*)0x0)->GetClass();
      ICHB_t_TClassManip(theClass);
   return theClass;
   }

   static void ICHB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *KFIT_t_Dictionary();
   static void KFIT_t_TClassManip(TClass*);
   static void *new_KFIT_t(void *p = 0);
   static void *newArray_KFIT_t(Long_t size, void *p);
   static void delete_KFIT_t(void *p);
   static void deleteArray_KFIT_t(void *p);
   static void destruct_KFIT_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::KFIT_t*)
   {
      ::KFIT_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::KFIT_t));
      static ::ROOT::TGenericClassInfo 
         instance("KFIT_t", "include/bankheader.h", 1501,
                  typeid(::KFIT_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &KFIT_t_Dictionary, isa_proxy, 0,
                  sizeof(::KFIT_t) );
      instance.SetNew(&new_KFIT_t);
      instance.SetNewArray(&newArray_KFIT_t);
      instance.SetDelete(&delete_KFIT_t);
      instance.SetDeleteArray(&deleteArray_KFIT_t);
      instance.SetDestructor(&destruct_KFIT_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::KFIT_t*)
   {
      return GenerateInitInstanceLocal((::KFIT_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::KFIT_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *KFIT_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::KFIT_t*)0x0)->GetClass();
      KFIT_t_TClassManip(theClass);
   return theClass;
   }

   static void KFIT_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *L1PG_t_Dictionary();
   static void L1PG_t_TClassManip(TClass*);
   static void *new_L1PG_t(void *p = 0);
   static void *newArray_L1PG_t(Long_t size, void *p);
   static void delete_L1PG_t(void *p);
   static void deleteArray_L1PG_t(void *p);
   static void destruct_L1PG_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::L1PG_t*)
   {
      ::L1PG_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::L1PG_t));
      static ::ROOT::TGenericClassInfo 
         instance("L1PG_t", "include/bankheader.h", 1549,
                  typeid(::L1PG_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &L1PG_t_Dictionary, isa_proxy, 0,
                  sizeof(::L1PG_t) );
      instance.SetNew(&new_L1PG_t);
      instance.SetNewArray(&newArray_L1PG_t);
      instance.SetDelete(&delete_L1PG_t);
      instance.SetDeleteArray(&deleteArray_L1PG_t);
      instance.SetDestructor(&destruct_L1PG_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::L1PG_t*)
   {
      return GenerateInitInstanceLocal((::L1PG_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::L1PG_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *L1PG_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::L1PG_t*)0x0)->GetClass();
      L1PG_t_TClassManip(theClass);
   return theClass;
   }

   static void L1PG_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *L2H_t_Dictionary();
   static void L2H_t_TClassManip(TClass*);
   static void *new_L2H_t(void *p = 0);
   static void *newArray_L2H_t(Long_t size, void *p);
   static void delete_L2H_t(void *p);
   static void deleteArray_L2H_t(void *p);
   static void destruct_L2H_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::L2H_t*)
   {
      ::L2H_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::L2H_t));
      static ::ROOT::TGenericClassInfo 
         instance("L2H_t", "include/bankheader.h", 1552,
                  typeid(::L2H_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &L2H_t_Dictionary, isa_proxy, 0,
                  sizeof(::L2H_t) );
      instance.SetNew(&new_L2H_t);
      instance.SetNewArray(&newArray_L2H_t);
      instance.SetDelete(&delete_L2H_t);
      instance.SetDeleteArray(&deleteArray_L2H_t);
      instance.SetDestructor(&destruct_L2H_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::L2H_t*)
   {
      return GenerateInitInstanceLocal((::L2H_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::L2H_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *L2H_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::L2H_t*)0x0)->GetClass();
      L2H_t_TClassManip(theClass);
   return theClass;
   }

   static void L2H_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *L2S_t_Dictionary();
   static void L2S_t_TClassManip(TClass*);
   static void *new_L2S_t(void *p = 0);
   static void *newArray_L2S_t(Long_t size, void *p);
   static void delete_L2S_t(void *p);
   static void deleteArray_L2S_t(void *p);
   static void destruct_L2S_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::L2S_t*)
   {
      ::L2S_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::L2S_t));
      static ::ROOT::TGenericClassInfo 
         instance("L2S_t", "include/bankheader.h", 1556,
                  typeid(::L2S_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &L2S_t_Dictionary, isa_proxy, 0,
                  sizeof(::L2S_t) );
      instance.SetNew(&new_L2S_t);
      instance.SetNewArray(&newArray_L2S_t);
      instance.SetDelete(&delete_L2S_t);
      instance.SetDeleteArray(&deleteArray_L2S_t);
      instance.SetDestructor(&destruct_L2S_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::L2S_t*)
   {
      return GenerateInitInstanceLocal((::L2S_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::L2S_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *L2S_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::L2S_t*)0x0)->GetClass();
      L2S_t_TClassManip(theClass);
   return theClass;
   }

   static void L2S_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *LASR_t_Dictionary();
   static void LASR_t_TClassManip(TClass*);
   static void *new_LASR_t(void *p = 0);
   static void *newArray_LASR_t(Long_t size, void *p);
   static void delete_LASR_t(void *p);
   static void deleteArray_LASR_t(void *p);
   static void destruct_LASR_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::LASR_t*)
   {
      ::LASR_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::LASR_t));
      static ::ROOT::TGenericClassInfo 
         instance("LASR_t", "include/bankheader.h", 1560,
                  typeid(::LASR_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &LASR_t_Dictionary, isa_proxy, 0,
                  sizeof(::LASR_t) );
      instance.SetNew(&new_LASR_t);
      instance.SetNewArray(&newArray_LASR_t);
      instance.SetDelete(&delete_LASR_t);
      instance.SetDeleteArray(&deleteArray_LASR_t);
      instance.SetDestructor(&destruct_LASR_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::LASR_t*)
   {
      return GenerateInitInstanceLocal((::LASR_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::LASR_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *LASR_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::LASR_t*)0x0)->GetClass();
      LASR_t_TClassManip(theClass);
   return theClass;
   }

   static void LASR_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *LCDI_t_Dictionary();
   static void LCDI_t_TClassManip(TClass*);
   static void *new_LCDI_t(void *p = 0);
   static void *newArray_LCDI_t(Long_t size, void *p);
   static void delete_LCDI_t(void *p);
   static void deleteArray_LCDI_t(void *p);
   static void destruct_LCDI_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::LCDI_t*)
   {
      ::LCDI_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::LCDI_t));
      static ::ROOT::TGenericClassInfo 
         instance("LCDI_t", "include/bankheader.h", 1566,
                  typeid(::LCDI_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &LCDI_t_Dictionary, isa_proxy, 0,
                  sizeof(::LCDI_t) );
      instance.SetNew(&new_LCDI_t);
      instance.SetNewArray(&newArray_LCDI_t);
      instance.SetDelete(&delete_LCDI_t);
      instance.SetDeleteArray(&deleteArray_LCDI_t);
      instance.SetDestructor(&destruct_LCDI_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::LCDI_t*)
   {
      return GenerateInitInstanceLocal((::LCDI_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::LCDI_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *LCDI_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::LCDI_t*)0x0)->GetClass();
      LCDI_t_TClassManip(theClass);
   return theClass;
   }

   static void LCDI_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *LCPB_t_Dictionary();
   static void LCPB_t_TClassManip(TClass*);
   static void *new_LCPB_t(void *p = 0);
   static void *newArray_LCPB_t(Long_t size, void *p);
   static void delete_LCPB_t(void *p);
   static void deleteArray_LCPB_t(void *p);
   static void destruct_LCPB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::LCPB_t*)
   {
      ::LCPB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::LCPB_t));
      static ::ROOT::TGenericClassInfo 
         instance("LCPB_t", "include/bankheader.h", 1572,
                  typeid(::LCPB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &LCPB_t_Dictionary, isa_proxy, 0,
                  sizeof(::LCPB_t) );
      instance.SetNew(&new_LCPB_t);
      instance.SetNewArray(&newArray_LCPB_t);
      instance.SetDelete(&delete_LCPB_t);
      instance.SetDeleteArray(&deleteArray_LCPB_t);
      instance.SetDestructor(&destruct_LCPB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::LCPB_t*)
   {
      return GenerateInitInstanceLocal((::LCPB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::LCPB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *LCPB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::LCPB_t*)0x0)->GetClass();
      LCPB_t_TClassManip(theClass);
   return theClass;
   }

   static void LCPB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *LOWQ_t_Dictionary();
   static void LOWQ_t_TClassManip(TClass*);
   static void *new_LOWQ_t(void *p = 0);
   static void *newArray_LOWQ_t(Long_t size, void *p);
   static void delete_LOWQ_t(void *p);
   static void deleteArray_LOWQ_t(void *p);
   static void destruct_LOWQ_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::LOWQ_t*)
   {
      ::LOWQ_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::LOWQ_t));
      static ::ROOT::TGenericClassInfo 
         instance("LOWQ_t", "include/bankheader.h", 1584,
                  typeid(::LOWQ_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &LOWQ_t_Dictionary, isa_proxy, 0,
                  sizeof(::LOWQ_t) );
      instance.SetNew(&new_LOWQ_t);
      instance.SetNewArray(&newArray_LOWQ_t);
      instance.SetDelete(&delete_LOWQ_t);
      instance.SetDeleteArray(&deleteArray_LOWQ_t);
      instance.SetDestructor(&destruct_LOWQ_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::LOWQ_t*)
   {
      return GenerateInitInstanceLocal((::LOWQ_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::LOWQ_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *LOWQ_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::LOWQ_t*)0x0)->GetClass();
      LOWQ_t_TClassManip(theClass);
   return theClass;
   }

   static void LOWQ_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *MCEV_t_Dictionary();
   static void MCEV_t_TClassManip(TClass*);
   static void *new_MCEV_t(void *p = 0);
   static void *newArray_MCEV_t(Long_t size, void *p);
   static void delete_MCEV_t(void *p);
   static void deleteArray_MCEV_t(void *p);
   static void destruct_MCEV_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MCEV_t*)
   {
      ::MCEV_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::MCEV_t));
      static ::ROOT::TGenericClassInfo 
         instance("MCEV_t", "include/bankheader.h", 1598,
                  typeid(::MCEV_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &MCEV_t_Dictionary, isa_proxy, 0,
                  sizeof(::MCEV_t) );
      instance.SetNew(&new_MCEV_t);
      instance.SetNewArray(&newArray_MCEV_t);
      instance.SetDelete(&delete_MCEV_t);
      instance.SetDeleteArray(&deleteArray_MCEV_t);
      instance.SetDestructor(&destruct_MCEV_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MCEV_t*)
   {
      return GenerateInitInstanceLocal((::MCEV_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::MCEV_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MCEV_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::MCEV_t*)0x0)->GetClass();
      MCEV_t_TClassManip(theClass);
   return theClass;
   }

   static void MCEV_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *MCHD_t_Dictionary();
   static void MCHD_t_TClassManip(TClass*);
   static void *new_MCHD_t(void *p = 0);
   static void *newArray_MCHD_t(Long_t size, void *p);
   static void delete_MCHD_t(void *p);
   static void deleteArray_MCHD_t(void *p);
   static void destruct_MCHD_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MCHD_t*)
   {
      ::MCHD_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::MCHD_t));
      static ::ROOT::TGenericClassInfo 
         instance("MCHD_t", "include/bankheader.h", 1602,
                  typeid(::MCHD_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &MCHD_t_Dictionary, isa_proxy, 0,
                  sizeof(::MCHD_t) );
      instance.SetNew(&new_MCHD_t);
      instance.SetNewArray(&newArray_MCHD_t);
      instance.SetDelete(&delete_MCHD_t);
      instance.SetDeleteArray(&deleteArray_MCHD_t);
      instance.SetDestructor(&destruct_MCHD_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MCHD_t*)
   {
      return GenerateInitInstanceLocal((::MCHD_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::MCHD_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MCHD_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::MCHD_t*)0x0)->GetClass();
      MCHD_t_TClassManip(theClass);
   return theClass;
   }

   static void MCHD_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *MCTK_t_Dictionary();
   static void MCTK_t_TClassManip(TClass*);
   static void *new_MCTK_t(void *p = 0);
   static void *newArray_MCTK_t(Long_t size, void *p);
   static void delete_MCTK_t(void *p);
   static void deleteArray_MCTK_t(void *p);
   static void destruct_MCTK_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MCTK_t*)
   {
      ::MCTK_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::MCTK_t));
      static ::ROOT::TGenericClassInfo 
         instance("MCTK_t", "include/bankheader.h", 1620,
                  typeid(::MCTK_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &MCTK_t_Dictionary, isa_proxy, 0,
                  sizeof(::MCTK_t) );
      instance.SetNew(&new_MCTK_t);
      instance.SetNewArray(&newArray_MCTK_t);
      instance.SetDelete(&delete_MCTK_t);
      instance.SetDeleteArray(&deleteArray_MCTK_t);
      instance.SetDestructor(&destruct_MCTK_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MCTK_t*)
   {
      return GenerateInitInstanceLocal((::MCTK_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::MCTK_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MCTK_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::MCTK_t*)0x0)->GetClass();
      MCTK_t_TClassManip(theClass);
   return theClass;
   }

   static void MCTK_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *MCVX_t_Dictionary();
   static void MCVX_t_TClassManip(TClass*);
   static void *new_MCVX_t(void *p = 0);
   static void *newArray_MCVX_t(Long_t size, void *p);
   static void delete_MCVX_t(void *p);
   static void deleteArray_MCVX_t(void *p);
   static void destruct_MCVX_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MCVX_t*)
   {
      ::MCVX_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::MCVX_t));
      static ::ROOT::TGenericClassInfo 
         instance("MCVX_t", "include/bankheader.h", 1633,
                  typeid(::MCVX_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &MCVX_t_Dictionary, isa_proxy, 0,
                  sizeof(::MCVX_t) );
      instance.SetNew(&new_MCVX_t);
      instance.SetNewArray(&newArray_MCVX_t);
      instance.SetDelete(&delete_MCVX_t);
      instance.SetDeleteArray(&deleteArray_MCVX_t);
      instance.SetDestructor(&destruct_MCVX_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MCVX_t*)
   {
      return GenerateInitInstanceLocal((::MCVX_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::MCVX_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MCVX_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::MCVX_t*)0x0)->GetClass();
      MCVX_t_TClassManip(theClass);
   return theClass;
   }

   static void MCVX_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *MTRK_t_Dictionary();
   static void MTRK_t_TClassManip(TClass*);
   static void *new_MTRK_t(void *p = 0);
   static void *newArray_MTRK_t(Long_t size, void *p);
   static void delete_MTRK_t(void *p);
   static void deleteArray_MTRK_t(void *p);
   static void destruct_MTRK_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MTRK_t*)
   {
      ::MTRK_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::MTRK_t));
      static ::ROOT::TGenericClassInfo 
         instance("MTRK_t", "include/bankheader.h", 1640,
                  typeid(::MTRK_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &MTRK_t_Dictionary, isa_proxy, 0,
                  sizeof(::MTRK_t) );
      instance.SetNew(&new_MTRK_t);
      instance.SetNewArray(&newArray_MTRK_t);
      instance.SetDelete(&delete_MTRK_t);
      instance.SetDeleteArray(&deleteArray_MTRK_t);
      instance.SetDestructor(&destruct_MTRK_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MTRK_t*)
   {
      return GenerateInitInstanceLocal((::MTRK_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::MTRK_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MTRK_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::MTRK_t*)0x0)->GetClass();
      MTRK_t_TClassManip(theClass);
   return theClass;
   }

   static void MTRK_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *MVRT_t_Dictionary();
   static void MVRT_t_TClassManip(TClass*);
   static void *new_MVRT_t(void *p = 0);
   static void *newArray_MVRT_t(Long_t size, void *p);
   static void delete_MVRT_t(void *p);
   static void deleteArray_MVRT_t(void *p);
   static void destruct_MVRT_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::MVRT_t*)
   {
      ::MVRT_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::MVRT_t));
      static ::ROOT::TGenericClassInfo 
         instance("MVRT_t", "include/bankheader.h", 1649,
                  typeid(::MVRT_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &MVRT_t_Dictionary, isa_proxy, 0,
                  sizeof(::MVRT_t) );
      instance.SetNew(&new_MVRT_t);
      instance.SetNewArray(&newArray_MVRT_t);
      instance.SetDelete(&delete_MVRT_t);
      instance.SetDeleteArray(&deleteArray_MVRT_t);
      instance.SetDestructor(&destruct_MVRT_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::MVRT_t*)
   {
      return GenerateInitInstanceLocal((::MVRT_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::MVRT_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *MVRT_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::MVRT_t*)0x0)->GetClass();
      MVRT_t_TClassManip(theClass);
   return theClass;
   }

   static void MVRT_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PART_t_Dictionary();
   static void PART_t_TClassManip(TClass*);
   static void *new_PART_t(void *p = 0);
   static void *newArray_PART_t(Long_t size, void *p);
   static void delete_PART_t(void *p);
   static void deleteArray_PART_t(void *p);
   static void destruct_PART_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PART_t*)
   {
      ::PART_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PART_t));
      static ::ROOT::TGenericClassInfo 
         instance("PART_t", "include/bankheader.h", 1664,
                  typeid(::PART_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PART_t_Dictionary, isa_proxy, 0,
                  sizeof(::PART_t) );
      instance.SetNew(&new_PART_t);
      instance.SetNewArray(&newArray_PART_t);
      instance.SetDelete(&delete_PART_t);
      instance.SetDeleteArray(&deleteArray_PART_t);
      instance.SetDestructor(&destruct_PART_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PART_t*)
   {
      return GenerateInitInstanceLocal((::PART_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PART_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PART_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PART_t*)0x0)->GetClass();
      PART_t_TClassManip(theClass);
   return theClass;
   }

   static void PART_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PCO_t_Dictionary();
   static void PCO_t_TClassManip(TClass*);
   static void *new_PCO_t(void *p = 0);
   static void *newArray_PCO_t(Long_t size, void *p);
   static void delete_PCO_t(void *p);
   static void deleteArray_PCO_t(void *p);
   static void destruct_PCO_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PCO_t*)
   {
      ::PCO_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PCO_t));
      static ::ROOT::TGenericClassInfo 
         instance("PCO_t", "include/bankheader.h", 1679,
                  typeid(::PCO_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PCO_t_Dictionary, isa_proxy, 0,
                  sizeof(::PCO_t) );
      instance.SetNew(&new_PCO_t);
      instance.SetNewArray(&newArray_PCO_t);
      instance.SetDelete(&delete_PCO_t);
      instance.SetDeleteArray(&deleteArray_PCO_t);
      instance.SetDestructor(&destruct_PCO_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PCO_t*)
   {
      return GenerateInitInstanceLocal((::PCO_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PCO_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PCO_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PCO_t*)0x0)->GetClass();
      PCO_t_TClassManip(theClass);
   return theClass;
   }

   static void PCO_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PHTM_t_Dictionary();
   static void PHTM_t_TClassManip(TClass*);
   static void *new_PHTM_t(void *p = 0);
   static void *newArray_PHTM_t(Long_t size, void *p);
   static void delete_PHTM_t(void *p);
   static void deleteArray_PHTM_t(void *p);
   static void destruct_PHTM_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PHTM_t*)
   {
      ::PHTM_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PHTM_t));
      static ::ROOT::TGenericClassInfo 
         instance("PHTM_t", "include/bankheader.h", 1689,
                  typeid(::PHTM_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PHTM_t_Dictionary, isa_proxy, 0,
                  sizeof(::PHTM_t) );
      instance.SetNew(&new_PHTM_t);
      instance.SetNewArray(&newArray_PHTM_t);
      instance.SetDelete(&delete_PHTM_t);
      instance.SetDeleteArray(&deleteArray_PHTM_t);
      instance.SetDestructor(&destruct_PHTM_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PHTM_t*)
   {
      return GenerateInitInstanceLocal((::PHTM_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PHTM_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PHTM_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PHTM_t*)0x0)->GetClass();
      PHTM_t_TClassManip(theClass);
   return theClass;
   }

   static void PHTM_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PID1_t_Dictionary();
   static void PID1_t_TClassManip(TClass*);
   static void *new_PID1_t(void *p = 0);
   static void *newArray_PID1_t(Long_t size, void *p);
   static void delete_PID1_t(void *p);
   static void deleteArray_PID1_t(void *p);
   static void destruct_PID1_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PID1_t*)
   {
      ::PID1_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PID1_t));
      static ::ROOT::TGenericClassInfo 
         instance("PID1_t", "include/bankheader.h", 1702,
                  typeid(::PID1_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PID1_t_Dictionary, isa_proxy, 0,
                  sizeof(::PID1_t) );
      instance.SetNew(&new_PID1_t);
      instance.SetNewArray(&newArray_PID1_t);
      instance.SetDelete(&delete_PID1_t);
      instance.SetDeleteArray(&deleteArray_PID1_t);
      instance.SetDestructor(&destruct_PID1_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PID1_t*)
   {
      return GenerateInitInstanceLocal((::PID1_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PID1_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PID1_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PID1_t*)0x0)->GetClass();
      PID1_t_TClassManip(theClass);
   return theClass;
   }

   static void PID1_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PID2_t_Dictionary();
   static void PID2_t_TClassManip(TClass*);
   static void *new_PID2_t(void *p = 0);
   static void *newArray_PID2_t(Long_t size, void *p);
   static void delete_PID2_t(void *p);
   static void deleteArray_PID2_t(void *p);
   static void destruct_PID2_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PID2_t*)
   {
      ::PID2_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PID2_t));
      static ::ROOT::TGenericClassInfo 
         instance("PID2_t", "include/bankheader.h", 1720,
                  typeid(::PID2_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PID2_t_Dictionary, isa_proxy, 0,
                  sizeof(::PID2_t) );
      instance.SetNew(&new_PID2_t);
      instance.SetNewArray(&newArray_PID2_t);
      instance.SetDelete(&delete_PID2_t);
      instance.SetDeleteArray(&deleteArray_PID2_t);
      instance.SetDestructor(&destruct_PID2_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PID2_t*)
   {
      return GenerateInitInstanceLocal((::PID2_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PID2_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PID2_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PID2_t*)0x0)->GetClass();
      PID2_t_TClassManip(theClass);
   return theClass;
   }

   static void PID2_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PID3_t_Dictionary();
   static void PID3_t_TClassManip(TClass*);
   static void *new_PID3_t(void *p = 0);
   static void *newArray_PID3_t(Long_t size, void *p);
   static void delete_PID3_t(void *p);
   static void deleteArray_PID3_t(void *p);
   static void destruct_PID3_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PID3_t*)
   {
      ::PID3_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PID3_t));
      static ::ROOT::TGenericClassInfo 
         instance("PID3_t", "include/bankheader.h", 1738,
                  typeid(::PID3_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PID3_t_Dictionary, isa_proxy, 0,
                  sizeof(::PID3_t) );
      instance.SetNew(&new_PID3_t);
      instance.SetNewArray(&newArray_PID3_t);
      instance.SetDelete(&delete_PID3_t);
      instance.SetDeleteArray(&deleteArray_PID3_t);
      instance.SetDestructor(&destruct_PID3_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PID3_t*)
   {
      return GenerateInitInstanceLocal((::PID3_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PID3_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PID3_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PID3_t*)0x0)->GetClass();
      PID3_t_TClassManip(theClass);
   return theClass;
   }

   static void PID3_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PID4_t_Dictionary();
   static void PID4_t_TClassManip(TClass*);
   static void *new_PID4_t(void *p = 0);
   static void *newArray_PID4_t(Long_t size, void *p);
   static void delete_PID4_t(void *p);
   static void deleteArray_PID4_t(void *p);
   static void destruct_PID4_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PID4_t*)
   {
      ::PID4_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PID4_t));
      static ::ROOT::TGenericClassInfo 
         instance("PID4_t", "include/bankheader.h", 1756,
                  typeid(::PID4_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PID4_t_Dictionary, isa_proxy, 0,
                  sizeof(::PID4_t) );
      instance.SetNew(&new_PID4_t);
      instance.SetNewArray(&newArray_PID4_t);
      instance.SetDelete(&delete_PID4_t);
      instance.SetDeleteArray(&deleteArray_PID4_t);
      instance.SetDestructor(&destruct_PID4_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PID4_t*)
   {
      return GenerateInitInstanceLocal((::PID4_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PID4_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PID4_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PID4_t*)0x0)->GetClass();
      PID4_t_TClassManip(theClass);
   return theClass;
   }

   static void PID4_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PID5_t_Dictionary();
   static void PID5_t_TClassManip(TClass*);
   static void *new_PID5_t(void *p = 0);
   static void *newArray_PID5_t(Long_t size, void *p);
   static void delete_PID5_t(void *p);
   static void deleteArray_PID5_t(void *p);
   static void destruct_PID5_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PID5_t*)
   {
      ::PID5_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PID5_t));
      static ::ROOT::TGenericClassInfo 
         instance("PID5_t", "include/bankheader.h", 1774,
                  typeid(::PID5_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PID5_t_Dictionary, isa_proxy, 0,
                  sizeof(::PID5_t) );
      instance.SetNew(&new_PID5_t);
      instance.SetNewArray(&newArray_PID5_t);
      instance.SetDelete(&delete_PID5_t);
      instance.SetDeleteArray(&deleteArray_PID5_t);
      instance.SetDestructor(&destruct_PID5_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PID5_t*)
   {
      return GenerateInitInstanceLocal((::PID5_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PID5_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PID5_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PID5_t*)0x0)->GetClass();
      PID5_t_TClassManip(theClass);
   return theClass;
   }

   static void PID5_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PID6_t_Dictionary();
   static void PID6_t_TClassManip(TClass*);
   static void *new_PID6_t(void *p = 0);
   static void *newArray_PID6_t(Long_t size, void *p);
   static void delete_PID6_t(void *p);
   static void deleteArray_PID6_t(void *p);
   static void destruct_PID6_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PID6_t*)
   {
      ::PID6_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PID6_t));
      static ::ROOT::TGenericClassInfo 
         instance("PID6_t", "include/bankheader.h", 1792,
                  typeid(::PID6_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PID6_t_Dictionary, isa_proxy, 0,
                  sizeof(::PID6_t) );
      instance.SetNew(&new_PID6_t);
      instance.SetNewArray(&newArray_PID6_t);
      instance.SetDelete(&delete_PID6_t);
      instance.SetDeleteArray(&deleteArray_PID6_t);
      instance.SetDestructor(&destruct_PID6_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PID6_t*)
   {
      return GenerateInitInstanceLocal((::PID6_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PID6_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PID6_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PID6_t*)0x0)->GetClass();
      PID6_t_TClassManip(theClass);
   return theClass;
   }

   static void PID6_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PIDT_t_Dictionary();
   static void PIDT_t_TClassManip(TClass*);
   static void *new_PIDT_t(void *p = 0);
   static void *newArray_PIDT_t(Long_t size, void *p);
   static void delete_PIDT_t(void *p);
   static void deleteArray_PIDT_t(void *p);
   static void destruct_PIDT_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PIDT_t*)
   {
      ::PIDT_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PIDT_t));
      static ::ROOT::TGenericClassInfo 
         instance("PIDT_t", "include/bankheader.h", 1810,
                  typeid(::PIDT_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PIDT_t_Dictionary, isa_proxy, 0,
                  sizeof(::PIDT_t) );
      instance.SetNew(&new_PIDT_t);
      instance.SetNewArray(&newArray_PIDT_t);
      instance.SetDelete(&delete_PIDT_t);
      instance.SetDeleteArray(&deleteArray_PIDT_t);
      instance.SetDestructor(&destruct_PIDT_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PIDT_t*)
   {
      return GenerateInitInstanceLocal((::PIDT_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PIDT_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PIDT_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PIDT_t*)0x0)->GetClass();
      PIDT_t_TClassManip(theClass);
   return theClass;
   }

   static void PIDT_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PRTM_t_Dictionary();
   static void PRTM_t_TClassManip(TClass*);
   static void *new_PRTM_t(void *p = 0);
   static void *newArray_PRTM_t(Long_t size, void *p);
   static void delete_PRTM_t(void *p);
   static void deleteArray_PRTM_t(void *p);
   static void destruct_PRTM_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PRTM_t*)
   {
      ::PRTM_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PRTM_t));
      static ::ROOT::TGenericClassInfo 
         instance("PRTM_t", "include/bankheader.h", 1822,
                  typeid(::PRTM_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PRTM_t_Dictionary, isa_proxy, 0,
                  sizeof(::PRTM_t) );
      instance.SetNew(&new_PRTM_t);
      instance.SetNewArray(&newArray_PRTM_t);
      instance.SetDelete(&delete_PRTM_t);
      instance.SetDeleteArray(&deleteArray_PRTM_t);
      instance.SetDestructor(&destruct_PRTM_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PRTM_t*)
   {
      return GenerateInitInstanceLocal((::PRTM_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PRTM_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PRTM_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PRTM_t*)0x0)->GetClass();
      PRTM_t_TClassManip(theClass);
   return theClass;
   }

   static void PRTM_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PSO_t_Dictionary();
   static void PSO_t_TClassManip(TClass*);
   static void *new_PSO_t(void *p = 0);
   static void *newArray_PSO_t(Long_t size, void *p);
   static void delete_PSO_t(void *p);
   static void deleteArray_PSO_t(void *p);
   static void destruct_PSO_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PSO_t*)
   {
      ::PSO_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PSO_t));
      static ::ROOT::TGenericClassInfo 
         instance("PSO_t", "include/bankheader.h", 1825,
                  typeid(::PSO_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PSO_t_Dictionary, isa_proxy, 0,
                  sizeof(::PSO_t) );
      instance.SetNew(&new_PSO_t);
      instance.SetNewArray(&newArray_PSO_t);
      instance.SetDelete(&delete_PSO_t);
      instance.SetDeleteArray(&deleteArray_PSO_t);
      instance.SetDestructor(&destruct_PSO_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PSO_t*)
   {
      return GenerateInitInstanceLocal((::PSO_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PSO_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PSO_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PSO_t*)0x0)->GetClass();
      PSO_t_TClassManip(theClass);
   return theClass;
   }

   static void PSO_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *PTDB_t_Dictionary();
   static void PTDB_t_TClassManip(TClass*);
   static void *new_PTDB_t(void *p = 0);
   static void *newArray_PTDB_t(Long_t size, void *p);
   static void delete_PTDB_t(void *p);
   static void deleteArray_PTDB_t(void *p);
   static void destruct_PTDB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::PTDB_t*)
   {
      ::PTDB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::PTDB_t));
      static ::ROOT::TGenericClassInfo 
         instance("PTDB_t", "include/bankheader.h", 1831,
                  typeid(::PTDB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &PTDB_t_Dictionary, isa_proxy, 0,
                  sizeof(::PTDB_t) );
      instance.SetNew(&new_PTDB_t);
      instance.SetNewArray(&newArray_PTDB_t);
      instance.SetDelete(&delete_PTDB_t);
      instance.SetDeleteArray(&deleteArray_PTDB_t);
      instance.SetDestructor(&destruct_PTDB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::PTDB_t*)
   {
      return GenerateInitInstanceLocal((::PTDB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::PTDB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *PTDB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::PTDB_t*)0x0)->GetClass();
      PTDB_t_TClassManip(theClass);
   return theClass;
   }

   static void PTDB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RCST_t_Dictionary();
   static void RCST_t_TClassManip(TClass*);
   static void *new_RCST_t(void *p = 0);
   static void *newArray_RCST_t(Long_t size, void *p);
   static void delete_RCST_t(void *p);
   static void deleteArray_RCST_t(void *p);
   static void destruct_RCST_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RCST_t*)
   {
      ::RCST_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RCST_t));
      static ::ROOT::TGenericClassInfo 
         instance("RCST_t", "include/bankheader.h", 1844,
                  typeid(::RCST_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RCST_t_Dictionary, isa_proxy, 0,
                  sizeof(::RCST_t) );
      instance.SetNew(&new_RCST_t);
      instance.SetNewArray(&newArray_RCST_t);
      instance.SetDelete(&delete_RCST_t);
      instance.SetDeleteArray(&deleteArray_RCST_t);
      instance.SetDestructor(&destruct_RCST_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RCST_t*)
   {
      return GenerateInitInstanceLocal((::RCST_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RCST_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RCST_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RCST_t*)0x0)->GetClass();
      RCST_t_TClassManip(theClass);
   return theClass;
   }

   static void RCST_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RF_t_Dictionary();
   static void RF_t_TClassManip(TClass*);
   static void *new_RF_t(void *p = 0);
   static void *newArray_RF_t(Long_t size, void *p);
   static void delete_RF_t(void *p);
   static void deleteArray_RF_t(void *p);
   static void destruct_RF_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RF_t*)
   {
      ::RF_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RF_t));
      static ::ROOT::TGenericClassInfo 
         instance("RF_t", "include/bankheader.h", 1861,
                  typeid(::RF_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RF_t_Dictionary, isa_proxy, 0,
                  sizeof(::RF_t) );
      instance.SetNew(&new_RF_t);
      instance.SetNewArray(&newArray_RF_t);
      instance.SetDelete(&delete_RF_t);
      instance.SetDeleteArray(&deleteArray_RF_t);
      instance.SetDestructor(&destruct_RF_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RF_t*)
   {
      return GenerateInitInstanceLocal((::RF_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RF_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RF_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RF_t*)0x0)->GetClass();
      RF_t_TClassManip(theClass);
   return theClass;
   }

   static void RF_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RGLK_t_Dictionary();
   static void RGLK_t_TClassManip(TClass*);
   static void *new_RGLK_t(void *p = 0);
   static void *newArray_RGLK_t(Long_t size, void *p);
   static void delete_RGLK_t(void *p);
   static void deleteArray_RGLK_t(void *p);
   static void destruct_RGLK_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RGLK_t*)
   {
      ::RGLK_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RGLK_t));
      static ::ROOT::TGenericClassInfo 
         instance("RGLK_t", "include/bankheader.h", 1866,
                  typeid(::RGLK_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RGLK_t_Dictionary, isa_proxy, 0,
                  sizeof(::RGLK_t) );
      instance.SetNew(&new_RGLK_t);
      instance.SetNewArray(&newArray_RGLK_t);
      instance.SetDelete(&delete_RGLK_t);
      instance.SetDeleteArray(&deleteArray_RGLK_t);
      instance.SetDestructor(&destruct_RGLK_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RGLK_t*)
   {
      return GenerateInitInstanceLocal((::RGLK_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RGLK_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RGLK_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RGLK_t*)0x0)->GetClass();
      RGLK_t_TClassManip(theClass);
   return theClass;
   }

   static void RGLK_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RNLG_t_Dictionary();
   static void RNLG_t_TClassManip(TClass*);
   static void *new_RNLG_t(void *p = 0);
   static void *newArray_RNLG_t(Long_t size, void *p);
   static void delete_RNLG_t(void *p);
   static void deleteArray_RNLG_t(void *p);
   static void destruct_RNLG_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RNLG_t*)
   {
      ::RNLG_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RNLG_t));
      static ::ROOT::TGenericClassInfo 
         instance("RNLG_t", "include/bankheader.h", 1878,
                  typeid(::RNLG_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RNLG_t_Dictionary, isa_proxy, 0,
                  sizeof(::RNLG_t) );
      instance.SetNew(&new_RNLG_t);
      instance.SetNewArray(&newArray_RNLG_t);
      instance.SetDelete(&delete_RNLG_t);
      instance.SetDeleteArray(&deleteArray_RNLG_t);
      instance.SetDestructor(&destruct_RNLG_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RNLG_t*)
   {
      return GenerateInitInstanceLocal((::RNLG_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RNLG_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RNLG_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RNLG_t*)0x0)->GetClass();
      RNLG_t_TClassManip(theClass);
   return theClass;
   }

   static void RNLG_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RNPE_t_Dictionary();
   static void RNPE_t_TClassManip(TClass*);
   static void *new_RNPE_t(void *p = 0);
   static void *newArray_RNPE_t(Long_t size, void *p);
   static void delete_RNPE_t(void *p);
   static void deleteArray_RNPE_t(void *p);
   static void destruct_RNPE_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RNPE_t*)
   {
      ::RNPE_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RNPE_t));
      static ::ROOT::TGenericClassInfo 
         instance("RNPE_t", "include/bankheader.h", 1881,
                  typeid(::RNPE_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RNPE_t_Dictionary, isa_proxy, 0,
                  sizeof(::RNPE_t) );
      instance.SetNew(&new_RNPE_t);
      instance.SetNewArray(&newArray_RNPE_t);
      instance.SetDelete(&delete_RNPE_t);
      instance.SetDeleteArray(&deleteArray_RNPE_t);
      instance.SetDestructor(&destruct_RNPE_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RNPE_t*)
   {
      return GenerateInitInstanceLocal((::RNPE_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RNPE_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RNPE_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RNPE_t*)0x0)->GetClass();
      RNPE_t_TClassManip(theClass);
   return theClass;
   }

   static void RNPE_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RTSL_t_Dictionary();
   static void RTSL_t_TClassManip(TClass*);
   static void *new_RTSL_t(void *p = 0);
   static void *newArray_RTSL_t(Long_t size, void *p);
   static void delete_RTSL_t(void *p);
   static void deleteArray_RTSL_t(void *p);
   static void destruct_RTSL_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RTSL_t*)
   {
      ::RTSL_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RTSL_t));
      static ::ROOT::TGenericClassInfo 
         instance("RTSL_t", "include/bankheader.h", 1885,
                  typeid(::RTSL_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RTSL_t_Dictionary, isa_proxy, 0,
                  sizeof(::RTSL_t) );
      instance.SetNew(&new_RTSL_t);
      instance.SetNewArray(&newArray_RTSL_t);
      instance.SetDelete(&delete_RTSL_t);
      instance.SetDeleteArray(&deleteArray_RTSL_t);
      instance.SetDestructor(&destruct_RTSL_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RTSL_t*)
   {
      return GenerateInitInstanceLocal((::RTSL_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RTSL_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RTSL_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RTSL_t*)0x0)->GetClass();
      RTSL_t_TClassManip(theClass);
   return theClass;
   }

   static void RTSL_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *RUNC_t_Dictionary();
   static void RUNC_t_TClassManip(TClass*);
   static void *new_RUNC_t(void *p = 0);
   static void *newArray_RUNC_t(Long_t size, void *p);
   static void delete_RUNC_t(void *p);
   static void deleteArray_RUNC_t(void *p);
   static void destruct_RUNC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::RUNC_t*)
   {
      ::RUNC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::RUNC_t));
      static ::ROOT::TGenericClassInfo 
         instance("RUNC_t", "include/bankheader.h", 1951,
                  typeid(::RUNC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &RUNC_t_Dictionary, isa_proxy, 0,
                  sizeof(::RUNC_t) );
      instance.SetNew(&new_RUNC_t);
      instance.SetNewArray(&newArray_RUNC_t);
      instance.SetDelete(&delete_RUNC_t);
      instance.SetDeleteArray(&deleteArray_RUNC_t);
      instance.SetDestructor(&destruct_RUNC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::RUNC_t*)
   {
      return GenerateInitInstanceLocal((::RUNC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::RUNC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *RUNC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::RUNC_t*)0x0)->GetClass();
      RUNC_t_TClassManip(theClass);
   return theClass;
   }

   static void RUNC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *S1ST_t_Dictionary();
   static void S1ST_t_TClassManip(TClass*);
   static void *new_S1ST_t(void *p = 0);
   static void *newArray_S1ST_t(Long_t size, void *p);
   static void delete_S1ST_t(void *p);
   static void deleteArray_S1ST_t(void *p);
   static void destruct_S1ST_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::S1ST_t*)
   {
      ::S1ST_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::S1ST_t));
      static ::ROOT::TGenericClassInfo 
         instance("S1ST_t", "include/bankheader.h", 1966,
                  typeid(::S1ST_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &S1ST_t_Dictionary, isa_proxy, 0,
                  sizeof(::S1ST_t) );
      instance.SetNew(&new_S1ST_t);
      instance.SetNewArray(&newArray_S1ST_t);
      instance.SetDelete(&delete_S1ST_t);
      instance.SetDeleteArray(&deleteArray_S1ST_t);
      instance.SetDestructor(&destruct_S1ST_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::S1ST_t*)
   {
      return GenerateInitInstanceLocal((::S1ST_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::S1ST_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *S1ST_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::S1ST_t*)0x0)->GetClass();
      S1ST_t_TClassManip(theClass);
   return theClass;
   }

   static void S1ST_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SC1_t_Dictionary();
   static void SC1_t_TClassManip(TClass*);
   static void *new_SC1_t(void *p = 0);
   static void *newArray_SC1_t(Long_t size, void *p);
   static void delete_SC1_t(void *p);
   static void deleteArray_SC1_t(void *p);
   static void destruct_SC1_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SC1_t*)
   {
      ::SC1_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SC1_t));
      static ::ROOT::TGenericClassInfo 
         instance("SC1_t", "include/bankheader.h", 2003,
                  typeid(::SC1_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SC1_t_Dictionary, isa_proxy, 0,
                  sizeof(::SC1_t) );
      instance.SetNew(&new_SC1_t);
      instance.SetNewArray(&newArray_SC1_t);
      instance.SetDelete(&delete_SC1_t);
      instance.SetDeleteArray(&deleteArray_SC1_t);
      instance.SetDestructor(&destruct_SC1_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SC1_t*)
   {
      return GenerateInitInstanceLocal((::SC1_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SC1_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SC1_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SC1_t*)0x0)->GetClass();
      SC1_t_TClassManip(theClass);
   return theClass;
   }

   static void SC1_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCC_t_Dictionary();
   static void SCC_t_TClassManip(TClass*);
   static void *new_SCC_t(void *p = 0);
   static void *newArray_SCC_t(Long_t size, void *p);
   static void delete_SCC_t(void *p);
   static void deleteArray_SCC_t(void *p);
   static void destruct_SCC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCC_t*)
   {
      ::SCC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCC_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCC_t", "include/bankheader.h", 2014,
                  typeid(::SCC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCC_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCC_t) );
      instance.SetNew(&new_SCC_t);
      instance.SetNewArray(&newArray_SCC_t);
      instance.SetDelete(&delete_SCC_t);
      instance.SetDeleteArray(&deleteArray_SCC_t);
      instance.SetDestructor(&destruct_SCC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCC_t*)
   {
      return GenerateInitInstanceLocal((::SCC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCC_t*)0x0)->GetClass();
      SCC_t_TClassManip(theClass);
   return theClass;
   }

   static void SCC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SC_t_Dictionary();
   static void SC_t_TClassManip(TClass*);
   static void *new_SC_t(void *p = 0);
   static void *newArray_SC_t(Long_t size, void *p);
   static void delete_SC_t(void *p);
   static void deleteArray_SC_t(void *p);
   static void destruct_SC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SC_t*)
   {
      ::SC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SC_t));
      static ::ROOT::TGenericClassInfo 
         instance("SC_t", "include/bankheader.h", 2064,
                  typeid(::SC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SC_t_Dictionary, isa_proxy, 0,
                  sizeof(::SC_t) );
      instance.SetNew(&new_SC_t);
      instance.SetNewArray(&newArray_SC_t);
      instance.SetDelete(&delete_SC_t);
      instance.SetDeleteArray(&deleteArray_SC_t);
      instance.SetDestructor(&destruct_SC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SC_t*)
   {
      return GenerateInitInstanceLocal((::SC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SC_t*)0x0)->GetClass();
      SC_t_TClassManip(theClass);
   return theClass;
   }

   static void SC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCDI_t_Dictionary();
   static void SCDI_t_TClassManip(TClass*);
   static void *new_SCDI_t(void *p = 0);
   static void *newArray_SCDI_t(Long_t size, void *p);
   static void delete_SCDI_t(void *p);
   static void deleteArray_SCDI_t(void *p);
   static void destruct_SCDI_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCDI_t*)
   {
      ::SCDI_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCDI_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCDI_t", "include/bankheader.h", 2071,
                  typeid(::SCDI_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCDI_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCDI_t) );
      instance.SetNew(&new_SCDI_t);
      instance.SetNewArray(&newArray_SCDI_t);
      instance.SetDelete(&delete_SCDI_t);
      instance.SetDeleteArray(&deleteArray_SCDI_t);
      instance.SetDestructor(&destruct_SCDI_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCDI_t*)
   {
      return GenerateInitInstanceLocal((::SCDI_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCDI_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCDI_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCDI_t*)0x0)->GetClass();
      SCDI_t_TClassManip(theClass);
   return theClass;
   }

   static void SCDI_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCGD_t_Dictionary();
   static void SCGD_t_TClassManip(TClass*);
   static void *new_SCGD_t(void *p = 0);
   static void *newArray_SCGD_t(Long_t size, void *p);
   static void delete_SCGD_t(void *p);
   static void deleteArray_SCGD_t(void *p);
   static void destruct_SCGD_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCGD_t*)
   {
      ::SCGD_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCGD_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCGD_t", "include/bankheader.h", 2078,
                  typeid(::SCGD_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCGD_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCGD_t) );
      instance.SetNew(&new_SCGD_t);
      instance.SetNewArray(&newArray_SCGD_t);
      instance.SetDelete(&delete_SCGD_t);
      instance.SetDeleteArray(&deleteArray_SCGD_t);
      instance.SetDestructor(&destruct_SCGD_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCGD_t*)
   {
      return GenerateInitInstanceLocal((::SCGD_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCGD_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCGD_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCGD_t*)0x0)->GetClass();
      SCGD_t_TClassManip(theClass);
   return theClass;
   }

   static void SCGD_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCG_t_Dictionary();
   static void SCG_t_TClassManip(TClass*);
   static void *new_SCG_t(void *p = 0);
   static void *newArray_SCG_t(Long_t size, void *p);
   static void delete_SCG_t(void *p);
   static void deleteArray_SCG_t(void *p);
   static void destruct_SCG_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCG_t*)
   {
      ::SCG_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCG_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCG_t", "include/bankheader.h", 2090,
                  typeid(::SCG_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCG_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCG_t) );
      instance.SetNew(&new_SCG_t);
      instance.SetNewArray(&newArray_SCG_t);
      instance.SetDelete(&delete_SCG_t);
      instance.SetDeleteArray(&deleteArray_SCG_t);
      instance.SetDestructor(&destruct_SCG_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCG_t*)
   {
      return GenerateInitInstanceLocal((::SCG_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCG_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCG_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCG_t*)0x0)->GetClass();
      SCG_t_TClassManip(theClass);
   return theClass;
   }

   static void SCG_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCH_t_Dictionary();
   static void SCH_t_TClassManip(TClass*);
   static void *new_SCH_t(void *p = 0);
   static void *newArray_SCH_t(Long_t size, void *p);
   static void delete_SCH_t(void *p);
   static void deleteArray_SCH_t(void *p);
   static void destruct_SCH_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCH_t*)
   {
      ::SCH_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCH_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCH_t", "include/bankheader.h", 2103,
                  typeid(::SCH_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCH_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCH_t) );
      instance.SetNew(&new_SCH_t);
      instance.SetNewArray(&newArray_SCH_t);
      instance.SetDelete(&delete_SCH_t);
      instance.SetDeleteArray(&deleteArray_SCH_t);
      instance.SetDestructor(&destruct_SCH_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCH_t*)
   {
      return GenerateInitInstanceLocal((::SCH_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCH_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCH_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCH_t*)0x0)->GetClass();
      SCH_t_TClassManip(theClass);
   return theClass;
   }

   static void SCH_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCMD_t_Dictionary();
   static void SCMD_t_TClassManip(TClass*);
   static void *new_SCMD_t(void *p = 0);
   static void *newArray_SCMD_t(Long_t size, void *p);
   static void delete_SCMD_t(void *p);
   static void deleteArray_SCMD_t(void *p);
   static void destruct_SCMD_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCMD_t*)
   {
      ::SCMD_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCMD_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCMD_t", "include/bankheader.h", 2114,
                  typeid(::SCMD_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCMD_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCMD_t) );
      instance.SetNew(&new_SCMD_t);
      instance.SetNewArray(&newArray_SCMD_t);
      instance.SetDelete(&delete_SCMD_t);
      instance.SetDeleteArray(&deleteArray_SCMD_t);
      instance.SetDestructor(&destruct_SCMD_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCMD_t*)
   {
      return GenerateInitInstanceLocal((::SCMD_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCMD_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCMD_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCMD_t*)0x0)->GetClass();
      SCMD_t_TClassManip(theClass);
   return theClass;
   }

   static void SCMD_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCMT_t_Dictionary();
   static void SCMT_t_TClassManip(TClass*);
   static void *new_SCMT_t(void *p = 0);
   static void *newArray_SCMT_t(Long_t size, void *p);
   static void delete_SCMT_t(void *p);
   static void deleteArray_SCMT_t(void *p);
   static void destruct_SCMT_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCMT_t*)
   {
      ::SCMT_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCMT_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCMT_t", "include/bankheader.h", 2129,
                  typeid(::SCMT_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCMT_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCMT_t) );
      instance.SetNew(&new_SCMT_t);
      instance.SetNewArray(&newArray_SCMT_t);
      instance.SetDelete(&delete_SCMT_t);
      instance.SetDeleteArray(&deleteArray_SCMT_t);
      instance.SetDestructor(&destruct_SCMT_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCMT_t*)
   {
      return GenerateInitInstanceLocal((::SCMT_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCMT_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCMT_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCMT_t*)0x0)->GetClass();
      SCMT_t_TClassManip(theClass);
   return theClass;
   }

   static void SCMT_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCMW_t_Dictionary();
   static void SCMW_t_TClassManip(TClass*);
   static void *new_SCMW_t(void *p = 0);
   static void *newArray_SCMW_t(Long_t size, void *p);
   static void delete_SCMW_t(void *p);
   static void deleteArray_SCMW_t(void *p);
   static void destruct_SCMW_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCMW_t*)
   {
      ::SCMW_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCMW_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCMW_t", "include/bankheader.h", 2132,
                  typeid(::SCMW_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCMW_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCMW_t) );
      instance.SetNew(&new_SCMW_t);
      instance.SetNewArray(&newArray_SCMW_t);
      instance.SetDelete(&delete_SCMW_t);
      instance.SetDeleteArray(&deleteArray_SCMW_t);
      instance.SetDestructor(&destruct_SCMW_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCMW_t*)
   {
      return GenerateInitInstanceLocal((::SCMW_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCMW_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCMW_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCMW_t*)0x0)->GetClass();
      SCMW_t_TClassManip(theClass);
   return theClass;
   }

   static void SCMW_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCPB_t_Dictionary();
   static void SCPB_t_TClassManip(TClass*);
   static void *new_SCPB_t(void *p = 0);
   static void *newArray_SCPB_t(Long_t size, void *p);
   static void delete_SCPB_t(void *p);
   static void deleteArray_SCPB_t(void *p);
   static void destruct_SCPB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCPB_t*)
   {
      ::SCPB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCPB_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCPB_t", "include/bankheader.h", 2135,
                  typeid(::SCPB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCPB_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCPB_t) );
      instance.SetNew(&new_SCPB_t);
      instance.SetNewArray(&newArray_SCPB_t);
      instance.SetDelete(&delete_SCPB_t);
      instance.SetDeleteArray(&deleteArray_SCPB_t);
      instance.SetDestructor(&destruct_SCPB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCPB_t*)
   {
      return GenerateInitInstanceLocal((::SCPB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCPB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCPB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCPB_t*)0x0)->GetClass();
      SCPB_t_TClassManip(theClass);
   return theClass;
   }

   static void SCPB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCP_t_Dictionary();
   static void SCP_t_TClassManip(TClass*);
   static void *new_SCP_t(void *p = 0);
   static void *newArray_SCP_t(Long_t size, void *p);
   static void delete_SCP_t(void *p);
   static void deleteArray_SCP_t(void *p);
   static void destruct_SCP_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCP_t*)
   {
      ::SCP_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCP_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCP_t", "include/bankheader.h", 2143,
                  typeid(::SCP_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCP_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCP_t) );
      instance.SetNew(&new_SCP_t);
      instance.SetNewArray(&newArray_SCP_t);
      instance.SetDelete(&delete_SCP_t);
      instance.SetDeleteArray(&deleteArray_SCP_t);
      instance.SetDestructor(&destruct_SCP_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCP_t*)
   {
      return GenerateInitInstanceLocal((::SCP_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCP_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCP_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCP_t*)0x0)->GetClass();
      SCP_t_TClassManip(theClass);
   return theClass;
   }

   static void SCP_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCPE_t_Dictionary();
   static void SCPE_t_TClassManip(TClass*);
   static void *new_SCPE_t(void *p = 0);
   static void *newArray_SCPE_t(Long_t size, void *p);
   static void delete_SCPE_t(void *p);
   static void deleteArray_SCPE_t(void *p);
   static void destruct_SCPE_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCPE_t*)
   {
      ::SCPE_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCPE_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCPE_t", "include/bankheader.h", 2161,
                  typeid(::SCPE_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCPE_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCPE_t) );
      instance.SetNew(&new_SCPE_t);
      instance.SetNewArray(&newArray_SCPE_t);
      instance.SetDelete(&delete_SCPE_t);
      instance.SetDeleteArray(&deleteArray_SCPE_t);
      instance.SetDestructor(&destruct_SCPE_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCPE_t*)
   {
      return GenerateInitInstanceLocal((::SCPE_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCPE_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCPE_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCPE_t*)0x0)->GetClass();
      SCPE_t_TClassManip(theClass);
   return theClass;
   }

   static void SCPE_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCPS_t_Dictionary();
   static void SCPS_t_TClassManip(TClass*);
   static void *new_SCPS_t(void *p = 0);
   static void *newArray_SCPS_t(Long_t size, void *p);
   static void delete_SCPS_t(void *p);
   static void deleteArray_SCPS_t(void *p);
   static void destruct_SCPS_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCPS_t*)
   {
      ::SCPS_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCPS_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCPS_t", "include/bankheader.h", 2168,
                  typeid(::SCPS_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCPS_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCPS_t) );
      instance.SetNew(&new_SCPS_t);
      instance.SetNewArray(&newArray_SCPS_t);
      instance.SetDelete(&delete_SCPS_t);
      instance.SetDeleteArray(&deleteArray_SCPS_t);
      instance.SetDestructor(&destruct_SCPS_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCPS_t*)
   {
      return GenerateInitInstanceLocal((::SCPS_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCPS_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCPS_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCPS_t*)0x0)->GetClass();
      SCPS_t_TClassManip(theClass);
   return theClass;
   }

   static void SCPS_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCRC_t_Dictionary();
   static void SCRC_t_TClassManip(TClass*);
   static void *new_SCRC_t(void *p = 0);
   static void *newArray_SCRC_t(Long_t size, void *p);
   static void delete_SCRC_t(void *p);
   static void deleteArray_SCRC_t(void *p);
   static void destruct_SCRC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCRC_t*)
   {
      ::SCRC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCRC_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCRC_t", "include/bankheader.h", 2186,
                  typeid(::SCRC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCRC_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCRC_t) );
      instance.SetNew(&new_SCRC_t);
      instance.SetNewArray(&newArray_SCRC_t);
      instance.SetDelete(&delete_SCRC_t);
      instance.SetDeleteArray(&deleteArray_SCRC_t);
      instance.SetDestructor(&destruct_SCRC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCRC_t*)
   {
      return GenerateInitInstanceLocal((::SCRC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCRC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCRC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCRC_t*)0x0)->GetClass();
      SCRC_t_TClassManip(theClass);
   return theClass;
   }

   static void SCRC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCR_t_Dictionary();
   static void SCR_t_TClassManip(TClass*);
   static void *new_SCR_t(void *p = 0);
   static void *newArray_SCR_t(Long_t size, void *p);
   static void delete_SCR_t(void *p);
   static void deleteArray_SCR_t(void *p);
   static void destruct_SCR_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCR_t*)
   {
      ::SCR_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCR_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCR_t", "include/bankheader.h", 2200,
                  typeid(::SCR_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCR_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCR_t) );
      instance.SetNew(&new_SCR_t);
      instance.SetNewArray(&newArray_SCR_t);
      instance.SetDelete(&delete_SCR_t);
      instance.SetDeleteArray(&deleteArray_SCR_t);
      instance.SetDestructor(&destruct_SCR_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCR_t*)
   {
      return GenerateInitInstanceLocal((::SCR_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCR_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCR_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCR_t*)0x0)->GetClass();
      SCR_t_TClassManip(theClass);
   return theClass;
   }

   static void SCR_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SCS_t_Dictionary();
   static void SCS_t_TClassManip(TClass*);
   static void *new_SCS_t(void *p = 0);
   static void *newArray_SCS_t(Long_t size, void *p);
   static void delete_SCS_t(void *p);
   static void deleteArray_SCS_t(void *p);
   static void destruct_SCS_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SCS_t*)
   {
      ::SCS_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SCS_t));
      static ::ROOT::TGenericClassInfo 
         instance("SCS_t", "include/bankheader.h", 2214,
                  typeid(::SCS_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SCS_t_Dictionary, isa_proxy, 0,
                  sizeof(::SCS_t) );
      instance.SetNew(&new_SCS_t);
      instance.SetNewArray(&newArray_SCS_t);
      instance.SetDelete(&delete_SCS_t);
      instance.SetDeleteArray(&deleteArray_SCS_t);
      instance.SetDestructor(&destruct_SCS_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SCS_t*)
   {
      return GenerateInitInstanceLocal((::SCS_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SCS_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SCS_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SCS_t*)0x0)->GetClass();
      SCS_t_TClassManip(theClass);
   return theClass;
   }

   static void SCS_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SGMP_t_Dictionary();
   static void SGMP_t_TClassManip(TClass*);
   static void *new_SGMP_t(void *p = 0);
   static void *newArray_SGMP_t(Long_t size, void *p);
   static void delete_SGMP_t(void *p);
   static void deleteArray_SGMP_t(void *p);
   static void destruct_SGMP_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SGMP_t*)
   {
      ::SGMP_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SGMP_t));
      static ::ROOT::TGenericClassInfo 
         instance("SGMP_t", "include/bankheader.h", 2408,
                  typeid(::SGMP_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SGMP_t_Dictionary, isa_proxy, 0,
                  sizeof(::SGMP_t) );
      instance.SetNew(&new_SGMP_t);
      instance.SetNewArray(&newArray_SGMP_t);
      instance.SetDelete(&delete_SGMP_t);
      instance.SetDeleteArray(&deleteArray_SGMP_t);
      instance.SetDestructor(&destruct_SGMP_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SGMP_t*)
   {
      return GenerateInitInstanceLocal((::SGMP_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SGMP_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SGMP_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SGMP_t*)0x0)->GetClass();
      SGMP_t_TClassManip(theClass);
   return theClass;
   }

   static void SGMP_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SPAR_t_Dictionary();
   static void SPAR_t_TClassManip(TClass*);
   static void *new_SPAR_t(void *p = 0);
   static void *newArray_SPAR_t(Long_t size, void *p);
   static void delete_SPAR_t(void *p);
   static void deleteArray_SPAR_t(void *p);
   static void destruct_SPAR_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SPAR_t*)
   {
      ::SPAR_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SPAR_t));
      static ::ROOT::TGenericClassInfo 
         instance("SPAR_t", "include/bankheader.h", 2417,
                  typeid(::SPAR_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SPAR_t_Dictionary, isa_proxy, 0,
                  sizeof(::SPAR_t) );
      instance.SetNew(&new_SPAR_t);
      instance.SetNewArray(&newArray_SPAR_t);
      instance.SetDelete(&delete_SPAR_t);
      instance.SetDeleteArray(&deleteArray_SPAR_t);
      instance.SetDestructor(&destruct_SPAR_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SPAR_t*)
   {
      return GenerateInitInstanceLocal((::SPAR_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SPAR_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SPAR_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SPAR_t*)0x0)->GetClass();
      SPAR_t_TClassManip(theClass);
   return theClass;
   }

   static void SPAR_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SPIN_t_Dictionary();
   static void SPIN_t_TClassManip(TClass*);
   static void *new_SPIN_t(void *p = 0);
   static void *newArray_SPIN_t(Long_t size, void *p);
   static void delete_SPIN_t(void *p);
   static void deleteArray_SPIN_t(void *p);
   static void destruct_SPIN_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SPIN_t*)
   {
      ::SPIN_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SPIN_t));
      static ::ROOT::TGenericClassInfo 
         instance("SPIN_t", "include/bankheader.h", 2423,
                  typeid(::SPIN_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SPIN_t_Dictionary, isa_proxy, 0,
                  sizeof(::SPIN_t) );
      instance.SetNew(&new_SPIN_t);
      instance.SetNewArray(&newArray_SPIN_t);
      instance.SetDelete(&delete_SPIN_t);
      instance.SetDeleteArray(&deleteArray_SPIN_t);
      instance.SetDestructor(&destruct_SPIN_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SPIN_t*)
   {
      return GenerateInitInstanceLocal((::SPIN_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SPIN_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SPIN_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SPIN_t*)0x0)->GetClass();
      SPIN_t_TClassManip(theClass);
   return theClass;
   }

   static void SPIN_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ST1_t_Dictionary();
   static void ST1_t_TClassManip(TClass*);
   static void *new_ST1_t(void *p = 0);
   static void *newArray_ST1_t(Long_t size, void *p);
   static void delete_ST1_t(void *p);
   static void deleteArray_ST1_t(void *p);
   static void destruct_ST1_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ST1_t*)
   {
      ::ST1_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ST1_t));
      static ::ROOT::TGenericClassInfo 
         instance("ST1_t", "include/bankheader.h", 2428,
                  typeid(::ST1_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ST1_t_Dictionary, isa_proxy, 0,
                  sizeof(::ST1_t) );
      instance.SetNew(&new_ST1_t);
      instance.SetNewArray(&newArray_ST1_t);
      instance.SetDelete(&delete_ST1_t);
      instance.SetDeleteArray(&deleteArray_ST1_t);
      instance.SetDestructor(&destruct_ST1_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ST1_t*)
   {
      return GenerateInitInstanceLocal((::ST1_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ST1_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ST1_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ST1_t*)0x0)->GetClass();
      ST1_t_TClassManip(theClass);
   return theClass;
   }

   static void ST1_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *ST_t_Dictionary();
   static void ST_t_TClassManip(TClass*);
   static void *new_ST_t(void *p = 0);
   static void *newArray_ST_t(Long_t size, void *p);
   static void delete_ST_t(void *p);
   static void deleteArray_ST_t(void *p);
   static void destruct_ST_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::ST_t*)
   {
      ::ST_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::ST_t));
      static ::ROOT::TGenericClassInfo 
         instance("ST_t", "include/bankheader.h", 2436,
                  typeid(::ST_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &ST_t_Dictionary, isa_proxy, 0,
                  sizeof(::ST_t) );
      instance.SetNew(&new_ST_t);
      instance.SetNewArray(&newArray_ST_t);
      instance.SetDelete(&delete_ST_t);
      instance.SetDeleteArray(&deleteArray_ST_t);
      instance.SetDestructor(&destruct_ST_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::ST_t*)
   {
      return GenerateInitInstanceLocal((::ST_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::ST_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *ST_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::ST_t*)0x0)->GetClass();
      ST_t_TClassManip(theClass);
   return theClass;
   }

   static void ST_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *STG_t_Dictionary();
   static void STG_t_TClassManip(TClass*);
   static void *new_STG_t(void *p = 0);
   static void *newArray_STG_t(Long_t size, void *p);
   static void delete_STG_t(void *p);
   static void deleteArray_STG_t(void *p);
   static void destruct_STG_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::STG_t*)
   {
      ::STG_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::STG_t));
      static ::ROOT::TGenericClassInfo 
         instance("STG_t", "include/bankheader.h", 2441,
                  typeid(::STG_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &STG_t_Dictionary, isa_proxy, 0,
                  sizeof(::STG_t) );
      instance.SetNew(&new_STG_t);
      instance.SetNewArray(&newArray_STG_t);
      instance.SetDelete(&delete_STG_t);
      instance.SetDeleteArray(&deleteArray_STG_t);
      instance.SetDestructor(&destruct_STG_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::STG_t*)
   {
      return GenerateInitInstanceLocal((::STG_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::STG_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *STG_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::STG_t*)0x0)->GetClass();
      STG_t_TClassManip(theClass);
   return theClass;
   }

   static void STG_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *STH_t_Dictionary();
   static void STH_t_TClassManip(TClass*);
   static void *new_STH_t(void *p = 0);
   static void *newArray_STH_t(Long_t size, void *p);
   static void delete_STH_t(void *p);
   static void deleteArray_STH_t(void *p);
   static void destruct_STH_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::STH_t*)
   {
      ::STH_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::STH_t));
      static ::ROOT::TGenericClassInfo 
         instance("STH_t", "include/bankheader.h", 2459,
                  typeid(::STH_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &STH_t_Dictionary, isa_proxy, 0,
                  sizeof(::STH_t) );
      instance.SetNew(&new_STH_t);
      instance.SetNewArray(&newArray_STH_t);
      instance.SetDelete(&delete_STH_t);
      instance.SetDeleteArray(&deleteArray_STH_t);
      instance.SetDestructor(&destruct_STH_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::STH_t*)
   {
      return GenerateInitInstanceLocal((::STH_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::STH_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *STH_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::STH_t*)0x0)->GetClass();
      STH_t_TClassManip(theClass);
   return theClass;
   }

   static void STH_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *STN0_t_Dictionary();
   static void STN0_t_TClassManip(TClass*);
   static void *new_STN0_t(void *p = 0);
   static void *newArray_STN0_t(Long_t size, void *p);
   static void delete_STN0_t(void *p);
   static void deleteArray_STN0_t(void *p);
   static void destruct_STN0_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::STN0_t*)
   {
      ::STN0_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::STN0_t));
      static ::ROOT::TGenericClassInfo 
         instance("STN0_t", "include/bankheader.h", 2471,
                  typeid(::STN0_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &STN0_t_Dictionary, isa_proxy, 0,
                  sizeof(::STN0_t) );
      instance.SetNew(&new_STN0_t);
      instance.SetNewArray(&newArray_STN0_t);
      instance.SetDelete(&delete_STN0_t);
      instance.SetDeleteArray(&deleteArray_STN0_t);
      instance.SetDestructor(&destruct_STN0_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::STN0_t*)
   {
      return GenerateInitInstanceLocal((::STN0_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::STN0_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *STN0_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::STN0_t*)0x0)->GetClass();
      STN0_t_TClassManip(theClass);
   return theClass;
   }

   static void STN0_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *STN1_t_Dictionary();
   static void STN1_t_TClassManip(TClass*);
   static void *new_STN1_t(void *p = 0);
   static void *newArray_STN1_t(Long_t size, void *p);
   static void delete_STN1_t(void *p);
   static void deleteArray_STN1_t(void *p);
   static void destruct_STN1_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::STN1_t*)
   {
      ::STN1_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::STN1_t));
      static ::ROOT::TGenericClassInfo 
         instance("STN1_t", "include/bankheader.h", 2475,
                  typeid(::STN1_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &STN1_t_Dictionary, isa_proxy, 0,
                  sizeof(::STN1_t) );
      instance.SetNew(&new_STN1_t);
      instance.SetNewArray(&newArray_STN1_t);
      instance.SetDelete(&delete_STN1_t);
      instance.SetDeleteArray(&deleteArray_STN1_t);
      instance.SetDestructor(&destruct_STN1_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::STN1_t*)
   {
      return GenerateInitInstanceLocal((::STN1_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::STN1_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *STN1_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::STN1_t*)0x0)->GetClass();
      STN1_t_TClassManip(theClass);
   return theClass;
   }

   static void STN1_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *STPB_t_Dictionary();
   static void STPB_t_TClassManip(TClass*);
   static void *new_STPB_t(void *p = 0);
   static void *newArray_STPB_t(Long_t size, void *p);
   static void delete_STPB_t(void *p);
   static void deleteArray_STPB_t(void *p);
   static void destruct_STPB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::STPB_t*)
   {
      ::STPB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::STPB_t));
      static ::ROOT::TGenericClassInfo 
         instance("STPB_t", "include/bankheader.h", 2479,
                  typeid(::STPB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &STPB_t_Dictionary, isa_proxy, 0,
                  sizeof(::STPB_t) );
      instance.SetNew(&new_STPB_t);
      instance.SetNewArray(&newArray_STPB_t);
      instance.SetDelete(&delete_STPB_t);
      instance.SetDeleteArray(&deleteArray_STPB_t);
      instance.SetDestructor(&destruct_STPB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::STPB_t*)
   {
      return GenerateInitInstanceLocal((::STPB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::STPB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *STPB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::STPB_t*)0x0)->GetClass();
      STPB_t_TClassManip(theClass);
   return theClass;
   }

   static void STPB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *STPE_t_Dictionary();
   static void STPE_t_TClassManip(TClass*);
   static void *new_STPE_t(void *p = 0);
   static void *newArray_STPE_t(Long_t size, void *p);
   static void delete_STPE_t(void *p);
   static void deleteArray_STPE_t(void *p);
   static void destruct_STPE_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::STPE_t*)
   {
      ::STPE_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::STPE_t));
      static ::ROOT::TGenericClassInfo 
         instance("STPE_t", "include/bankheader.h", 2486,
                  typeid(::STPE_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &STPE_t_Dictionary, isa_proxy, 0,
                  sizeof(::STPE_t) );
      instance.SetNew(&new_STPE_t);
      instance.SetNewArray(&newArray_STPE_t);
      instance.SetDelete(&delete_STPE_t);
      instance.SetDeleteArray(&deleteArray_STPE_t);
      instance.SetDestructor(&destruct_STPE_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::STPE_t*)
   {
      return GenerateInitInstanceLocal((::STPE_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::STPE_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *STPE_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::STPE_t*)0x0)->GetClass();
      STPE_t_TClassManip(theClass);
   return theClass;
   }

   static void STPE_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *STR_t_Dictionary();
   static void STR_t_TClassManip(TClass*);
   static void *new_STR_t(void *p = 0);
   static void *newArray_STR_t(Long_t size, void *p);
   static void delete_STR_t(void *p);
   static void deleteArray_STR_t(void *p);
   static void destruct_STR_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::STR_t*)
   {
      ::STR_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::STR_t));
      static ::ROOT::TGenericClassInfo 
         instance("STR_t", "include/bankheader.h", 2491,
                  typeid(::STR_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &STR_t_Dictionary, isa_proxy, 0,
                  sizeof(::STR_t) );
      instance.SetNew(&new_STR_t);
      instance.SetNewArray(&newArray_STR_t);
      instance.SetDelete(&delete_STR_t);
      instance.SetDeleteArray(&deleteArray_STR_t);
      instance.SetDestructor(&destruct_STR_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::STR_t*)
   {
      return GenerateInitInstanceLocal((::STR_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::STR_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *STR_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::STR_t*)0x0)->GetClass();
      STR_t_TClassManip(theClass);
   return theClass;
   }

   static void STR_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *STS_t_Dictionary();
   static void STS_t_TClassManip(TClass*);
   static void *new_STS_t(void *p = 0);
   static void *newArray_STS_t(Long_t size, void *p);
   static void delete_STS_t(void *p);
   static void deleteArray_STS_t(void *p);
   static void destruct_STS_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::STS_t*)
   {
      ::STS_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::STS_t));
      static ::ROOT::TGenericClassInfo 
         instance("STS_t", "include/bankheader.h", 2499,
                  typeid(::STS_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &STS_t_Dictionary, isa_proxy, 0,
                  sizeof(::STS_t) );
      instance.SetNew(&new_STS_t);
      instance.SetNewArray(&newArray_STS_t);
      instance.SetDelete(&delete_STS_t);
      instance.SetDeleteArray(&deleteArray_STS_t);
      instance.SetDestructor(&destruct_STS_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::STS_t*)
   {
      return GenerateInitInstanceLocal((::STS_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::STS_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *STS_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::STS_t*)0x0)->GetClass();
      STS_t_TClassManip(theClass);
   return theClass;
   }

   static void STS_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *SYNC_t_Dictionary();
   static void SYNC_t_TClassManip(TClass*);
   static void *new_SYNC_t(void *p = 0);
   static void *newArray_SYNC_t(Long_t size, void *p);
   static void delete_SYNC_t(void *p);
   static void deleteArray_SYNC_t(void *p);
   static void destruct_SYNC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::SYNC_t*)
   {
      ::SYNC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::SYNC_t));
      static ::ROOT::TGenericClassInfo 
         instance("SYNC_t", "include/bankheader.h", 2517,
                  typeid(::SYNC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &SYNC_t_Dictionary, isa_proxy, 0,
                  sizeof(::SYNC_t) );
      instance.SetNew(&new_SYNC_t);
      instance.SetNewArray(&newArray_SYNC_t);
      instance.SetDelete(&delete_SYNC_t);
      instance.SetDeleteArray(&deleteArray_SYNC_t);
      instance.SetDestructor(&destruct_SYNC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::SYNC_t*)
   {
      return GenerateInitInstanceLocal((::SYNC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::SYNC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *SYNC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::SYNC_t*)0x0)->GetClass();
      SYNC_t_TClassManip(theClass);
   return theClass;
   }

   static void SYNC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TACO_t_Dictionary();
   static void TACO_t_TClassManip(TClass*);
   static void *new_TACO_t(void *p = 0);
   static void *newArray_TACO_t(Long_t size, void *p);
   static void delete_TACO_t(void *p);
   static void deleteArray_TACO_t(void *p);
   static void destruct_TACO_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TACO_t*)
   {
      ::TACO_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TACO_t));
      static ::ROOT::TGenericClassInfo 
         instance("TACO_t", "include/bankheader.h", 2522,
                  typeid(::TACO_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TACO_t_Dictionary, isa_proxy, 0,
                  sizeof(::TACO_t) );
      instance.SetNew(&new_TACO_t);
      instance.SetNewArray(&newArray_TACO_t);
      instance.SetDelete(&delete_TACO_t);
      instance.SetDeleteArray(&deleteArray_TACO_t);
      instance.SetDestructor(&destruct_TACO_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TACO_t*)
   {
      return GenerateInitInstanceLocal((::TACO_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TACO_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TACO_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TACO_t*)0x0)->GetClass();
      TACO_t_TClassManip(theClass);
   return theClass;
   }

   static void TACO_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TAGE_t_Dictionary();
   static void TAGE_t_TClassManip(TClass*);
   static void *new_TAGE_t(void *p = 0);
   static void *newArray_TAGE_t(Long_t size, void *p);
   static void delete_TAGE_t(void *p);
   static void deleteArray_TAGE_t(void *p);
   static void destruct_TAGE_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TAGE_t*)
   {
      ::TAGE_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TAGE_t));
      static ::ROOT::TGenericClassInfo 
         instance("TAGE_t", "include/bankheader.h", 2534,
                  typeid(::TAGE_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TAGE_t_Dictionary, isa_proxy, 0,
                  sizeof(::TAGE_t) );
      instance.SetNew(&new_TAGE_t);
      instance.SetNewArray(&newArray_TAGE_t);
      instance.SetDelete(&delete_TAGE_t);
      instance.SetDeleteArray(&deleteArray_TAGE_t);
      instance.SetDestructor(&destruct_TAGE_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TAGE_t*)
   {
      return GenerateInitInstanceLocal((::TAGE_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TAGE_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TAGE_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TAGE_t*)0x0)->GetClass();
      TAGE_t_TClassManip(theClass);
   return theClass;
   }

   static void TAGE_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TAGI_t_Dictionary();
   static void TAGI_t_TClassManip(TClass*);
   static void *new_TAGI_t(void *p = 0);
   static void *newArray_TAGI_t(Long_t size, void *p);
   static void delete_TAGI_t(void *p);
   static void deleteArray_TAGI_t(void *p);
   static void destruct_TAGI_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TAGI_t*)
   {
      ::TAGI_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TAGI_t));
      static ::ROOT::TGenericClassInfo 
         instance("TAGI_t", "include/bankheader.h", 2538,
                  typeid(::TAGI_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TAGI_t_Dictionary, isa_proxy, 0,
                  sizeof(::TAGI_t) );
      instance.SetNew(&new_TAGI_t);
      instance.SetNewArray(&newArray_TAGI_t);
      instance.SetDelete(&delete_TAGI_t);
      instance.SetDeleteArray(&deleteArray_TAGI_t);
      instance.SetDestructor(&destruct_TAGI_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TAGI_t*)
   {
      return GenerateInitInstanceLocal((::TAGI_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TAGI_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TAGI_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TAGI_t*)0x0)->GetClass();
      TAGI_t_TClassManip(theClass);
   return theClass;
   }

   static void TAGI_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TAGM_t_Dictionary();
   static void TAGM_t_TClassManip(TClass*);
   static void *new_TAGM_t(void *p = 0);
   static void *newArray_TAGM_t(Long_t size, void *p);
   static void delete_TAGM_t(void *p);
   static void deleteArray_TAGM_t(void *p);
   static void destruct_TAGM_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TAGM_t*)
   {
      ::TAGM_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TAGM_t));
      static ::ROOT::TGenericClassInfo 
         instance("TAGM_t", "include/bankheader.h", 2548,
                  typeid(::TAGM_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TAGM_t_Dictionary, isa_proxy, 0,
                  sizeof(::TAGM_t) );
      instance.SetNew(&new_TAGM_t);
      instance.SetNewArray(&newArray_TAGM_t);
      instance.SetDelete(&delete_TAGM_t);
      instance.SetDeleteArray(&deleteArray_TAGM_t);
      instance.SetDestructor(&destruct_TAGM_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TAGM_t*)
   {
      return GenerateInitInstanceLocal((::TAGM_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TAGM_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TAGM_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TAGM_t*)0x0)->GetClass();
      TAGM_t_TClassManip(theClass);
   return theClass;
   }

   static void TAGM_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TAGR_t_Dictionary();
   static void TAGR_t_TClassManip(TClass*);
   static void *new_TAGR_t(void *p = 0);
   static void *newArray_TAGR_t(Long_t size, void *p);
   static void delete_TAGR_t(void *p);
   static void deleteArray_TAGR_t(void *p);
   static void destruct_TAGR_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TAGR_t*)
   {
      ::TAGR_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TAGR_t));
      static ::ROOT::TGenericClassInfo 
         instance("TAGR_t", "include/bankheader.h", 2556,
                  typeid(::TAGR_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TAGR_t_Dictionary, isa_proxy, 0,
                  sizeof(::TAGR_t) );
      instance.SetNew(&new_TAGR_t);
      instance.SetNewArray(&newArray_TAGR_t);
      instance.SetDelete(&delete_TAGR_t);
      instance.SetDeleteArray(&deleteArray_TAGR_t);
      instance.SetDestructor(&destruct_TAGR_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TAGR_t*)
   {
      return GenerateInitInstanceLocal((::TAGR_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TAGR_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TAGR_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TAGR_t*)0x0)->GetClass();
      TAGR_t_TClassManip(theClass);
   return theClass;
   }

   static void TAGR_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TAGT_t_Dictionary();
   static void TAGT_t_TClassManip(TClass*);
   static void *new_TAGT_t(void *p = 0);
   static void *newArray_TAGT_t(Long_t size, void *p);
   static void delete_TAGT_t(void *p);
   static void deleteArray_TAGT_t(void *p);
   static void destruct_TAGT_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TAGT_t*)
   {
      ::TAGT_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TAGT_t));
      static ::ROOT::TGenericClassInfo 
         instance("TAGT_t", "include/bankheader.h", 2564,
                  typeid(::TAGT_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TAGT_t_Dictionary, isa_proxy, 0,
                  sizeof(::TAGT_t) );
      instance.SetNew(&new_TAGT_t);
      instance.SetNewArray(&newArray_TAGT_t);
      instance.SetDelete(&delete_TAGT_t);
      instance.SetDeleteArray(&deleteArray_TAGT_t);
      instance.SetDestructor(&destruct_TAGT_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TAGT_t*)
   {
      return GenerateInitInstanceLocal((::TAGT_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TAGT_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TAGT_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TAGT_t*)0x0)->GetClass();
      TAGT_t_TClassManip(theClass);
   return theClass;
   }

   static void TAGT_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TBER_t_Dictionary();
   static void TBER_t_TClassManip(TClass*);
   static void *new_TBER_t(void *p = 0);
   static void *newArray_TBER_t(Long_t size, void *p);
   static void delete_TBER_t(void *p);
   static void deleteArray_TBER_t(void *p);
   static void destruct_TBER_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TBER_t*)
   {
      ::TBER_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TBER_t));
      static ::ROOT::TGenericClassInfo 
         instance("TBER_t", "include/bankheader.h", 2569,
                  typeid(::TBER_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TBER_t_Dictionary, isa_proxy, 0,
                  sizeof(::TBER_t) );
      instance.SetNew(&new_TBER_t);
      instance.SetNewArray(&newArray_TBER_t);
      instance.SetDelete(&delete_TBER_t);
      instance.SetDeleteArray(&deleteArray_TBER_t);
      instance.SetDestructor(&destruct_TBER_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TBER_t*)
   {
      return GenerateInitInstanceLocal((::TBER_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TBER_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TBER_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TBER_t*)0x0)->GetClass();
      TBER_t_TClassManip(theClass);
   return theClass;
   }

   static void TBER_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TBID_t_Dictionary();
   static void TBID_t_TClassManip(TClass*);
   static void *new_TBID_t(void *p = 0);
   static void *newArray_TBID_t(Long_t size, void *p);
   static void delete_TBID_t(void *p);
   static void deleteArray_TBID_t(void *p);
   static void destruct_TBID_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TBID_t*)
   {
      ::TBID_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TBID_t));
      static ::ROOT::TGenericClassInfo 
         instance("TBID_t", "include/bankheader.h", 2594,
                  typeid(::TBID_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TBID_t_Dictionary, isa_proxy, 0,
                  sizeof(::TBID_t) );
      instance.SetNew(&new_TBID_t);
      instance.SetNewArray(&newArray_TBID_t);
      instance.SetDelete(&delete_TBID_t);
      instance.SetDeleteArray(&deleteArray_TBID_t);
      instance.SetDestructor(&destruct_TBID_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TBID_t*)
   {
      return GenerateInitInstanceLocal((::TBID_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TBID_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TBID_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TBID_t*)0x0)->GetClass();
      TBID_t_TClassManip(theClass);
   return theClass;
   }

   static void TBID_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TBLA_t_Dictionary();
   static void TBLA_t_TClassManip(TClass*);
   static void *new_TBLA_t(void *p = 0);
   static void *newArray_TBLA_t(Long_t size, void *p);
   static void delete_TBLA_t(void *p);
   static void deleteArray_TBLA_t(void *p);
   static void destruct_TBLA_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TBLA_t*)
   {
      ::TBLA_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TBLA_t));
      static ::ROOT::TGenericClassInfo 
         instance("TBLA_t", "include/bankheader.h", 2630,
                  typeid(::TBLA_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TBLA_t_Dictionary, isa_proxy, 0,
                  sizeof(::TBLA_t) );
      instance.SetNew(&new_TBLA_t);
      instance.SetNewArray(&newArray_TBLA_t);
      instance.SetDelete(&delete_TBLA_t);
      instance.SetDeleteArray(&deleteArray_TBLA_t);
      instance.SetDestructor(&destruct_TBLA_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TBLA_t*)
   {
      return GenerateInitInstanceLocal((::TBLA_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TBLA_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TBLA_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TBLA_t*)0x0)->GetClass();
      TBLA_t_TClassManip(theClass);
   return theClass;
   }

   static void TBLA_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TBTR_t_Dictionary();
   static void TBTR_t_TClassManip(TClass*);
   static void *new_TBTR_t(void *p = 0);
   static void *newArray_TBTR_t(Long_t size, void *p);
   static void delete_TBTR_t(void *p);
   static void deleteArray_TBTR_t(void *p);
   static void destruct_TBTR_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TBTR_t*)
   {
      ::TBTR_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TBTR_t));
      static ::ROOT::TGenericClassInfo 
         instance("TBTR_t", "include/bankheader.h", 2649,
                  typeid(::TBTR_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TBTR_t_Dictionary, isa_proxy, 0,
                  sizeof(::TBTR_t) );
      instance.SetNew(&new_TBTR_t);
      instance.SetNewArray(&newArray_TBTR_t);
      instance.SetDelete(&delete_TBTR_t);
      instance.SetDeleteArray(&deleteArray_TBTR_t);
      instance.SetDestructor(&destruct_TBTR_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TBTR_t*)
   {
      return GenerateInitInstanceLocal((::TBTR_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TBTR_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TBTR_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TBTR_t*)0x0)->GetClass();
      TBTR_t_TClassManip(theClass);
   return theClass;
   }

   static void TBTR_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TCSB_t_Dictionary();
   static void TCSB_t_TClassManip(TClass*);
   static void *new_TCSB_t(void *p = 0);
   static void *newArray_TCSB_t(Long_t size, void *p);
   static void delete_TCSB_t(void *p);
   static void deleteArray_TCSB_t(void *p);
   static void destruct_TCSB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TCSB_t*)
   {
      ::TCSB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TCSB_t));
      static ::ROOT::TGenericClassInfo 
         instance("TCSB_t", "include/bankheader.h", 2661,
                  typeid(::TCSB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TCSB_t_Dictionary, isa_proxy, 0,
                  sizeof(::TCSB_t) );
      instance.SetNew(&new_TCSB_t);
      instance.SetNewArray(&newArray_TCSB_t);
      instance.SetDelete(&delete_TCSB_t);
      instance.SetDeleteArray(&deleteArray_TCSB_t);
      instance.SetDestructor(&destruct_TCSB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TCSB_t*)
   {
      return GenerateInitInstanceLocal((::TCSB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TCSB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TCSB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TCSB_t*)0x0)->GetClass();
      TCSB_t_TClassManip(theClass);
   return theClass;
   }

   static void TCSB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TDPL_t_Dictionary();
   static void TDPL_t_TClassManip(TClass*);
   static void *new_TDPL_t(void *p = 0);
   static void *newArray_TDPL_t(Long_t size, void *p);
   static void delete_TDPL_t(void *p);
   static void deleteArray_TDPL_t(void *p);
   static void destruct_TDPL_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TDPL_t*)
   {
      ::TDPL_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TDPL_t));
      static ::ROOT::TGenericClassInfo 
         instance("TDPL_t", "include/bankheader.h", 2669,
                  typeid(::TDPL_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TDPL_t_Dictionary, isa_proxy, 0,
                  sizeof(::TDPL_t) );
      instance.SetNew(&new_TDPL_t);
      instance.SetNewArray(&newArray_TDPL_t);
      instance.SetDelete(&delete_TDPL_t);
      instance.SetDeleteArray(&deleteArray_TDPL_t);
      instance.SetDestructor(&destruct_TDPL_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TDPL_t*)
   {
      return GenerateInitInstanceLocal((::TDPL_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TDPL_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TDPL_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TDPL_t*)0x0)->GetClass();
      TDPL_t_TClassManip(theClass);
   return theClass;
   }

   static void TDPL_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TESC_t_Dictionary();
   static void TESC_t_TClassManip(TClass*);
   static void *new_TESC_t(void *p = 0);
   static void *newArray_TESC_t(Long_t size, void *p);
   static void delete_TESC_t(void *p);
   static void deleteArray_TESC_t(void *p);
   static void destruct_TESC_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TESC_t*)
   {
      ::TESC_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TESC_t));
      static ::ROOT::TGenericClassInfo 
         instance("TESC_t", "include/bankheader.h", 2679,
                  typeid(::TESC_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TESC_t_Dictionary, isa_proxy, 0,
                  sizeof(::TESC_t) );
      instance.SetNew(&new_TESC_t);
      instance.SetNewArray(&newArray_TESC_t);
      instance.SetDelete(&delete_TESC_t);
      instance.SetDeleteArray(&deleteArray_TESC_t);
      instance.SetDestructor(&destruct_TESC_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TESC_t*)
   {
      return GenerateInitInstanceLocal((::TESC_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TESC_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TESC_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TESC_t*)0x0)->GetClass();
      TESC_t_TClassManip(theClass);
   return theClass;
   }

   static void TESC_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TGBI_t_Dictionary();
   static void TGBI_t_TClassManip(TClass*);
   static void *new_TGBI_t(void *p = 0);
   static void *newArray_TGBI_t(Long_t size, void *p);
   static void delete_TGBI_t(void *p);
   static void deleteArray_TGBI_t(void *p);
   static void destruct_TGBI_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TGBI_t*)
   {
      ::TGBI_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TGBI_t));
      static ::ROOT::TGenericClassInfo 
         instance("TGBI_t", "include/bankheader.h", 2682,
                  typeid(::TGBI_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TGBI_t_Dictionary, isa_proxy, 0,
                  sizeof(::TGBI_t) );
      instance.SetNew(&new_TGBI_t);
      instance.SetNewArray(&newArray_TGBI_t);
      instance.SetDelete(&delete_TGBI_t);
      instance.SetDeleteArray(&deleteArray_TGBI_t);
      instance.SetDestructor(&destruct_TGBI_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TGBI_t*)
   {
      return GenerateInitInstanceLocal((::TGBI_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TGBI_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TGBI_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TGBI_t*)0x0)->GetClass();
      TGBI_t_TClassManip(theClass);
   return theClass;
   }

   static void TGBI_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TGEO_t_Dictionary();
   static void TGEO_t_TClassManip(TClass*);
   static void *new_TGEO_t(void *p = 0);
   static void *newArray_TGEO_t(Long_t size, void *p);
   static void delete_TGEO_t(void *p);
   static void deleteArray_TGEO_t(void *p);
   static void destruct_TGEO_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TGEO_t*)
   {
      ::TGEO_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TGEO_t));
      static ::ROOT::TGenericClassInfo 
         instance("TGEO_t", "include/bankheader.h", 2689,
                  typeid(::TGEO_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TGEO_t_Dictionary, isa_proxy, 0,
                  sizeof(::TGEO_t) );
      instance.SetNew(&new_TGEO_t);
      instance.SetNewArray(&newArray_TGEO_t);
      instance.SetDelete(&delete_TGEO_t);
      instance.SetDeleteArray(&deleteArray_TGEO_t);
      instance.SetDestructor(&destruct_TGEO_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TGEO_t*)
   {
      return GenerateInitInstanceLocal((::TGEO_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TGEO_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TGEO_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TGEO_t*)0x0)->GetClass();
      TGEO_t_TClassManip(theClass);
   return theClass;
   }

   static void TGEO_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TGPB_t_Dictionary();
   static void TGPB_t_TClassManip(TClass*);
   static void *new_TGPB_t(void *p = 0);
   static void *newArray_TGPB_t(Long_t size, void *p);
   static void delete_TGPB_t(void *p);
   static void deleteArray_TGPB_t(void *p);
   static void destruct_TGPB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TGPB_t*)
   {
      ::TGPB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TGPB_t));
      static ::ROOT::TGenericClassInfo 
         instance("TGPB_t", "include/bankheader.h", 2697,
                  typeid(::TGPB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TGPB_t_Dictionary, isa_proxy, 0,
                  sizeof(::TGPB_t) );
      instance.SetNew(&new_TGPB_t);
      instance.SetNewArray(&newArray_TGPB_t);
      instance.SetDelete(&delete_TGPB_t);
      instance.SetDeleteArray(&deleteArray_TGPB_t);
      instance.SetDestructor(&destruct_TGPB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TGPB_t*)
   {
      return GenerateInitInstanceLocal((::TGPB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TGPB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TGPB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TGPB_t*)0x0)->GetClass();
      TGPB_t_TClassManip(theClass);
   return theClass;
   }

   static void TGPB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TGS_t_Dictionary();
   static void TGS_t_TClassManip(TClass*);
   static void *new_TGS_t(void *p = 0);
   static void *newArray_TGS_t(Long_t size, void *p);
   static void delete_TGS_t(void *p);
   static void deleteArray_TGS_t(void *p);
   static void destruct_TGS_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TGS_t*)
   {
      ::TGS_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TGS_t));
      static ::ROOT::TGenericClassInfo 
         instance("TGS_t", "include/bankheader.h", 2703,
                  typeid(::TGS_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TGS_t_Dictionary, isa_proxy, 0,
                  sizeof(::TGS_t) );
      instance.SetNew(&new_TGS_t);
      instance.SetNewArray(&newArray_TGS_t);
      instance.SetDelete(&delete_TGS_t);
      instance.SetDeleteArray(&deleteArray_TGS_t);
      instance.SetDestructor(&destruct_TGS_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TGS_t*)
   {
      return GenerateInitInstanceLocal((::TGS_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TGS_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TGS_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TGS_t*)0x0)->GetClass();
      TGS_t_TClassManip(theClass);
   return theClass;
   }

   static void TGS_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TLV1_t_Dictionary();
   static void TLV1_t_TClassManip(TClass*);
   static void *new_TLV1_t(void *p = 0);
   static void *newArray_TLV1_t(Long_t size, void *p);
   static void delete_TLV1_t(void *p);
   static void deleteArray_TLV1_t(void *p);
   static void destruct_TLV1_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TLV1_t*)
   {
      ::TLV1_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TLV1_t));
      static ::ROOT::TGenericClassInfo 
         instance("TLV1_t", "include/bankheader.h", 2897,
                  typeid(::TLV1_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TLV1_t_Dictionary, isa_proxy, 0,
                  sizeof(::TLV1_t) );
      instance.SetNew(&new_TLV1_t);
      instance.SetNewArray(&newArray_TLV1_t);
      instance.SetDelete(&delete_TLV1_t);
      instance.SetDeleteArray(&deleteArray_TLV1_t);
      instance.SetDestructor(&destruct_TLV1_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TLV1_t*)
   {
      return GenerateInitInstanceLocal((::TLV1_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TLV1_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TLV1_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TLV1_t*)0x0)->GetClass();
      TLV1_t_TClassManip(theClass);
   return theClass;
   }

   static void TLV1_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TRCF_t_Dictionary();
   static void TRCF_t_TClassManip(TClass*);
   static void *new_TRCF_t(void *p = 0);
   static void *newArray_TRCF_t(Long_t size, void *p);
   static void delete_TRCF_t(void *p);
   static void deleteArray_TRCF_t(void *p);
   static void destruct_TRCF_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRCF_t*)
   {
      ::TRCF_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TRCF_t));
      static ::ROOT::TGenericClassInfo 
         instance("TRCF_t", "include/bankheader.h", 2901,
                  typeid(::TRCF_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TRCF_t_Dictionary, isa_proxy, 0,
                  sizeof(::TRCF_t) );
      instance.SetNew(&new_TRCF_t);
      instance.SetNewArray(&newArray_TRCF_t);
      instance.SetDelete(&delete_TRCF_t);
      instance.SetDeleteArray(&deleteArray_TRCF_t);
      instance.SetDestructor(&destruct_TRCF_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRCF_t*)
   {
      return GenerateInitInstanceLocal((::TRCF_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRCF_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TRCF_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TRCF_t*)0x0)->GetClass();
      TRCF_t_TClassManip(theClass);
   return theClass;
   }

   static void TRCF_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TRGS_t_Dictionary();
   static void TRGS_t_TClassManip(TClass*);
   static void *new_TRGS_t(void *p = 0);
   static void *newArray_TRGS_t(Long_t size, void *p);
   static void delete_TRGS_t(void *p);
   static void deleteArray_TRGS_t(void *p);
   static void destruct_TRGS_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRGS_t*)
   {
      ::TRGS_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TRGS_t));
      static ::ROOT::TGenericClassInfo 
         instance("TRGS_t", "include/bankheader.h", 2904,
                  typeid(::TRGS_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TRGS_t_Dictionary, isa_proxy, 0,
                  sizeof(::TRGS_t) );
      instance.SetNew(&new_TRGS_t);
      instance.SetNewArray(&newArray_TRGS_t);
      instance.SetDelete(&delete_TRGS_t);
      instance.SetDeleteArray(&deleteArray_TRGS_t);
      instance.SetDestructor(&destruct_TRGS_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRGS_t*)
   {
      return GenerateInitInstanceLocal((::TRGS_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRGS_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TRGS_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TRGS_t*)0x0)->GetClass();
      TRGS_t_TClassManip(theClass);
   return theClass;
   }

   static void TRGS_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TRKS_t_Dictionary();
   static void TRKS_t_TClassManip(TClass*);
   static void *new_TRKS_t(void *p = 0);
   static void *newArray_TRKS_t(Long_t size, void *p);
   static void delete_TRKS_t(void *p);
   static void deleteArray_TRKS_t(void *p);
   static void destruct_TRKS_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRKS_t*)
   {
      ::TRKS_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TRKS_t));
      static ::ROOT::TGenericClassInfo 
         instance("TRKS_t", "include/bankheader.h", 3002,
                  typeid(::TRKS_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TRKS_t_Dictionary, isa_proxy, 0,
                  sizeof(::TRKS_t) );
      instance.SetNew(&new_TRKS_t);
      instance.SetNewArray(&newArray_TRKS_t);
      instance.SetDelete(&delete_TRKS_t);
      instance.SetDeleteArray(&deleteArray_TRKS_t);
      instance.SetDestructor(&destruct_TRKS_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRKS_t*)
   {
      return GenerateInitInstanceLocal((::TRKS_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRKS_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TRKS_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TRKS_t*)0x0)->GetClass();
      TRKS_t_TClassManip(theClass);
   return theClass;
   }

   static void TRKS_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TRL1_t_Dictionary();
   static void TRL1_t_TClassManip(TClass*);
   static void *new_TRL1_t(void *p = 0);
   static void *newArray_TRL1_t(Long_t size, void *p);
   static void delete_TRL1_t(void *p);
   static void deleteArray_TRL1_t(void *p);
   static void destruct_TRL1_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRL1_t*)
   {
      ::TRL1_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TRL1_t));
      static ::ROOT::TGenericClassInfo 
         instance("TRL1_t", "include/bankheader.h", 3014,
                  typeid(::TRL1_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TRL1_t_Dictionary, isa_proxy, 0,
                  sizeof(::TRL1_t) );
      instance.SetNew(&new_TRL1_t);
      instance.SetNewArray(&newArray_TRL1_t);
      instance.SetDelete(&delete_TRL1_t);
      instance.SetDeleteArray(&deleteArray_TRL1_t);
      instance.SetDestructor(&destruct_TRL1_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRL1_t*)
   {
      return GenerateInitInstanceLocal((::TRL1_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRL1_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TRL1_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TRL1_t*)0x0)->GetClass();
      TRL1_t_TClassManip(theClass);
   return theClass;
   }

   static void TRL1_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TRPB_t_Dictionary();
   static void TRPB_t_TClassManip(TClass*);
   static void *new_TRPB_t(void *p = 0);
   static void *newArray_TRPB_t(Long_t size, void *p);
   static void delete_TRPB_t(void *p);
   static void deleteArray_TRPB_t(void *p);
   static void destruct_TRPB_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TRPB_t*)
   {
      ::TRPB_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TRPB_t));
      static ::ROOT::TGenericClassInfo 
         instance("TRPB_t", "include/bankheader.h", 3026,
                  typeid(::TRPB_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TRPB_t_Dictionary, isa_proxy, 0,
                  sizeof(::TRPB_t) );
      instance.SetNew(&new_TRPB_t);
      instance.SetNewArray(&newArray_TRPB_t);
      instance.SetDelete(&delete_TRPB_t);
      instance.SetDeleteArray(&deleteArray_TRPB_t);
      instance.SetDestructor(&destruct_TRPB_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TRPB_t*)
   {
      return GenerateInitInstanceLocal((::TRPB_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TRPB_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TRPB_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TRPB_t*)0x0)->GetClass();
      TRPB_t_TClassManip(theClass);
   return theClass;
   }

   static void TRPB_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TSPR_t_Dictionary();
   static void TSPR_t_TClassManip(TClass*);
   static void *new_TSPR_t(void *p = 0);
   static void *newArray_TSPR_t(Long_t size, void *p);
   static void delete_TSPR_t(void *p);
   static void deleteArray_TSPR_t(void *p);
   static void destruct_TSPR_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TSPR_t*)
   {
      ::TSPR_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TSPR_t));
      static ::ROOT::TGenericClassInfo 
         instance("TSPR_t", "include/bankheader.h", 3036,
                  typeid(::TSPR_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TSPR_t_Dictionary, isa_proxy, 0,
                  sizeof(::TSPR_t) );
      instance.SetNew(&new_TSPR_t);
      instance.SetNewArray(&newArray_TSPR_t);
      instance.SetDelete(&delete_TSPR_t);
      instance.SetDeleteArray(&deleteArray_TSPR_t);
      instance.SetDestructor(&destruct_TSPR_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TSPR_t*)
   {
      return GenerateInitInstanceLocal((::TSPR_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TSPR_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TSPR_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TSPR_t*)0x0)->GetClass();
      TSPR_t_TClassManip(theClass);
   return theClass;
   }

   static void TSPR_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *TSRG_t_Dictionary();
   static void TSRG_t_TClassManip(TClass*);
   static void *new_TSRG_t(void *p = 0);
   static void *newArray_TSRG_t(Long_t size, void *p);
   static void delete_TSRG_t(void *p);
   static void deleteArray_TSRG_t(void *p);
   static void destruct_TSRG_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::TSRG_t*)
   {
      ::TSRG_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::TSRG_t));
      static ::ROOT::TGenericClassInfo 
         instance("TSRG_t", "include/bankheader.h", 3039,
                  typeid(::TSRG_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &TSRG_t_Dictionary, isa_proxy, 0,
                  sizeof(::TSRG_t) );
      instance.SetNew(&new_TSRG_t);
      instance.SetNewArray(&newArray_TSRG_t);
      instance.SetDelete(&delete_TSRG_t);
      instance.SetDeleteArray(&deleteArray_TSRG_t);
      instance.SetDestructor(&destruct_TSRG_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::TSRG_t*)
   {
      return GenerateInitInstanceLocal((::TSRG_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::TSRG_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *TSRG_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::TSRG_t*)0x0)->GetClass();
      TSRG_t_TClassManip(theClass);
   return theClass;
   }

   static void TSRG_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *UNUS_t_Dictionary();
   static void UNUS_t_TClassManip(TClass*);
   static void *new_UNUS_t(void *p = 0);
   static void *newArray_UNUS_t(Long_t size, void *p);
   static void delete_UNUS_t(void *p);
   static void deleteArray_UNUS_t(void *p);
   static void destruct_UNUS_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::UNUS_t*)
   {
      ::UNUS_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::UNUS_t));
      static ::ROOT::TGenericClassInfo 
         instance("UNUS_t", "include/bankheader.h", 3042,
                  typeid(::UNUS_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &UNUS_t_Dictionary, isa_proxy, 0,
                  sizeof(::UNUS_t) );
      instance.SetNew(&new_UNUS_t);
      instance.SetNewArray(&newArray_UNUS_t);
      instance.SetDelete(&delete_UNUS_t);
      instance.SetDeleteArray(&deleteArray_UNUS_t);
      instance.SetDestructor(&destruct_UNUS_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::UNUS_t*)
   {
      return GenerateInitInstanceLocal((::UNUS_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::UNUS_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *UNUS_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::UNUS_t*)0x0)->GetClass();
      UNUS_t_TClassManip(theClass);
   return theClass;
   }

   static void UNUS_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *VERT_t_Dictionary();
   static void VERT_t_TClassManip(TClass*);
   static void *new_VERT_t(void *p = 0);
   static void *newArray_VERT_t(Long_t size, void *p);
   static void delete_VERT_t(void *p);
   static void deleteArray_VERT_t(void *p);
   static void destruct_VERT_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::VERT_t*)
   {
      ::VERT_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::VERT_t));
      static ::ROOT::TGenericClassInfo 
         instance("VERT_t", "include/bankheader.h", 3052,
                  typeid(::VERT_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &VERT_t_Dictionary, isa_proxy, 0,
                  sizeof(::VERT_t) );
      instance.SetNew(&new_VERT_t);
      instance.SetNewArray(&newArray_VERT_t);
      instance.SetDelete(&delete_VERT_t);
      instance.SetDeleteArray(&deleteArray_VERT_t);
      instance.SetDestructor(&destruct_VERT_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::VERT_t*)
   {
      return GenerateInitInstanceLocal((::VERT_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::VERT_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *VERT_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::VERT_t*)0x0)->GetClass();
      VERT_t_TClassManip(theClass);
   return theClass;
   }

   static void VERT_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *addressBanks_t_Dictionary();
   static void addressBanks_t_TClassManip(TClass*);
   static void *new_addressBanks_t(void *p = 0);
   static void *newArray_addressBanks_t(Long_t size, void *p);
   static void delete_addressBanks_t(void *p);
   static void deleteArray_addressBanks_t(void *p);
   static void destruct_addressBanks_t(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::addressBanks_t*)
   {
      ::addressBanks_t *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::addressBanks_t));
      static ::ROOT::TGenericClassInfo 
         instance("addressBanks_t", "include/RootBeerTypes.h", 30,
                  typeid(::addressBanks_t), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &addressBanks_t_Dictionary, isa_proxy, 0,
                  sizeof(::addressBanks_t) );
      instance.SetNew(&new_addressBanks_t);
      instance.SetNewArray(&newArray_addressBanks_t);
      instance.SetDelete(&delete_addressBanks_t);
      instance.SetDeleteArray(&deleteArray_addressBanks_t);
      instance.SetDestructor(&destruct_addressBanks_t);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::addressBanks_t*)
   {
      return GenerateInitInstanceLocal((::addressBanks_t*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::addressBanks_t*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *addressBanks_t_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::addressBanks_t*)0x0)->GetClass();
      addressBanks_t_TClassManip(theClass);
   return theClass;
   }

   static void addressBanks_t_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_BEAM_t(void *p) {
      return  p ? new(p) ::BEAM_t : new ::BEAM_t;
   }
   static void *newArray_BEAM_t(Long_t nElements, void *p) {
      return p ? new(p) ::BEAM_t[nElements] : new ::BEAM_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_BEAM_t(void *p) {
      delete ((::BEAM_t*)p);
   }
   static void deleteArray_BEAM_t(void *p) {
      delete [] ((::BEAM_t*)p);
   }
   static void destruct_BEAM_t(void *p) {
      typedef ::BEAM_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::BEAM_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_BMPR_t(void *p) {
      return  p ? new(p) ::BMPR_t : new ::BMPR_t;
   }
   static void *newArray_BMPR_t(Long_t nElements, void *p) {
      return p ? new(p) ::BMPR_t[nElements] : new ::BMPR_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_BMPR_t(void *p) {
      delete ((::BMPR_t*)p);
   }
   static void deleteArray_BMPR_t(void *p) {
      delete [] ((::BMPR_t*)p);
   }
   static void destruct_BMPR_t(void *p) {
      typedef ::BMPR_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::BMPR_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_BREP_t(void *p) {
      return  p ? new(p) ::BREP_t : new ::BREP_t;
   }
   static void *newArray_BREP_t(Long_t nElements, void *p) {
      return p ? new(p) ::BREP_t[nElements] : new ::BREP_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_BREP_t(void *p) {
      delete ((::BREP_t*)p);
   }
   static void deleteArray_BREP_t(void *p) {
      delete [] ((::BREP_t*)p);
   }
   static void destruct_BREP_t(void *p) {
      typedef ::BREP_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::BREP_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CALB_t(void *p) {
      return  p ? new(p) ::CALB_t : new ::CALB_t;
   }
   static void *newArray_CALB_t(Long_t nElements, void *p) {
      return p ? new(p) ::CALB_t[nElements] : new ::CALB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CALB_t(void *p) {
      delete ((::CALB_t*)p);
   }
   static void deleteArray_CALB_t(void *p) {
      delete [] ((::CALB_t*)p);
   }
   static void destruct_CALB_t(void *p) {
      typedef ::CALB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CALB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CALL_t(void *p) {
      return  p ? new(p) ::CALL_t : new ::CALL_t;
   }
   static void *newArray_CALL_t(Long_t nElements, void *p) {
      return p ? new(p) ::CALL_t[nElements] : new ::CALL_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CALL_t(void *p) {
      delete ((::CALL_t*)p);
   }
   static void deleteArray_CALL_t(void *p) {
      delete [] ((::CALL_t*)p);
   }
   static void destruct_CALL_t(void *p) {
      typedef ::CALL_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CALL_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CC01_t(void *p) {
      return  p ? new(p) ::CC01_t : new ::CC01_t;
   }
   static void *newArray_CC01_t(Long_t nElements, void *p) {
      return p ? new(p) ::CC01_t[nElements] : new ::CC01_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CC01_t(void *p) {
      delete ((::CC01_t*)p);
   }
   static void deleteArray_CC01_t(void *p) {
      delete [] ((::CC01_t*)p);
   }
   static void destruct_CC01_t(void *p) {
      typedef ::CC01_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CC01_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CC1_t(void *p) {
      return  p ? new(p) ::CC1_t : new ::CC1_t;
   }
   static void *newArray_CC1_t(Long_t nElements, void *p) {
      return p ? new(p) ::CC1_t[nElements] : new ::CC1_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CC1_t(void *p) {
      delete ((::CC1_t*)p);
   }
   static void deleteArray_CC1_t(void *p) {
      delete [] ((::CC1_t*)p);
   }
   static void destruct_CC1_t(void *p) {
      typedef ::CC1_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CC1_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CC_t(void *p) {
      return  p ? new(p) ::CC_t : new ::CC_t;
   }
   static void *newArray_CC_t(Long_t nElements, void *p) {
      return p ? new(p) ::CC_t[nElements] : new ::CC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CC_t(void *p) {
      delete ((::CC_t*)p);
   }
   static void deleteArray_CC_t(void *p) {
      delete [] ((::CC_t*)p);
   }
   static void destruct_CC_t(void *p) {
      typedef ::CC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CCDI_t(void *p) {
      return  p ? new(p) ::CCDI_t : new ::CCDI_t;
   }
   static void *newArray_CCDI_t(Long_t nElements, void *p) {
      return p ? new(p) ::CCDI_t[nElements] : new ::CCDI_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CCDI_t(void *p) {
      delete ((::CCDI_t*)p);
   }
   static void deleteArray_CCDI_t(void *p) {
      delete [] ((::CCDI_t*)p);
   }
   static void destruct_CCDI_t(void *p) {
      typedef ::CCDI_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CCDI_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CCH_t(void *p) {
      return  p ? new(p) ::CCH_t : new ::CCH_t;
   }
   static void *newArray_CCH_t(Long_t nElements, void *p) {
      return p ? new(p) ::CCH_t[nElements] : new ::CCH_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CCH_t(void *p) {
      delete ((::CCH_t*)p);
   }
   static void deleteArray_CCH_t(void *p) {
      delete [] ((::CCH_t*)p);
   }
   static void destruct_CCH_t(void *p) {
      typedef ::CCH_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CCH_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CCMT_t(void *p) {
      return  p ? new(p) ::CCMT_t : new ::CCMT_t;
   }
   static void *newArray_CCMT_t(Long_t nElements, void *p) {
      return p ? new(p) ::CCMT_t[nElements] : new ::CCMT_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CCMT_t(void *p) {
      delete ((::CCMT_t*)p);
   }
   static void deleteArray_CCMT_t(void *p) {
      delete [] ((::CCMT_t*)p);
   }
   static void destruct_CCMT_t(void *p) {
      typedef ::CCMT_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CCMT_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CCPB_t(void *p) {
      return  p ? new(p) ::CCPB_t : new ::CCPB_t;
   }
   static void *newArray_CCPB_t(Long_t nElements, void *p) {
      return p ? new(p) ::CCPB_t[nElements] : new ::CCPB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CCPB_t(void *p) {
      delete ((::CCPB_t*)p);
   }
   static void deleteArray_CCPB_t(void *p) {
      delete [] ((::CCPB_t*)p);
   }
   static void destruct_CCPB_t(void *p) {
      typedef ::CCPB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CCPB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CCPE_t(void *p) {
      return  p ? new(p) ::CCPE_t : new ::CCPE_t;
   }
   static void *newArray_CCPE_t(Long_t nElements, void *p) {
      return p ? new(p) ::CCPE_t[nElements] : new ::CCPE_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CCPE_t(void *p) {
      delete ((::CCPE_t*)p);
   }
   static void deleteArray_CCPE_t(void *p) {
      delete [] ((::CCPE_t*)p);
   }
   static void destruct_CCPE_t(void *p) {
      typedef ::CCPE_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CCPE_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CCRC_t(void *p) {
      return  p ? new(p) ::CCRC_t : new ::CCRC_t;
   }
   static void *newArray_CCRC_t(Long_t nElements, void *p) {
      return p ? new(p) ::CCRC_t[nElements] : new ::CCRC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CCRC_t(void *p) {
      delete ((::CCRC_t*)p);
   }
   static void deleteArray_CCRC_t(void *p) {
      delete [] ((::CCRC_t*)p);
   }
   static void destruct_CCRC_t(void *p) {
      typedef ::CCRC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CCRC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CCS_t(void *p) {
      return  p ? new(p) ::CCS_t : new ::CCS_t;
   }
   static void *newArray_CCS_t(Long_t nElements, void *p) {
      return p ? new(p) ::CCS_t[nElements] : new ::CCS_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CCS_t(void *p) {
      delete ((::CCS_t*)p);
   }
   static void deleteArray_CCS_t(void *p) {
      delete [] ((::CCS_t*)p);
   }
   static void destruct_CCS_t(void *p) {
      typedef ::CCS_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CCS_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CHI2_t(void *p) {
      return  p ? new(p) ::CHI2_t : new ::CHI2_t;
   }
   static void *newArray_CHI2_t(Long_t nElements, void *p) {
      return p ? new(p) ::CHI2_t[nElements] : new ::CHI2_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CHI2_t(void *p) {
      delete ((::CHI2_t*)p);
   }
   static void deleteArray_CHI2_t(void *p) {
      delete [] ((::CHI2_t*)p);
   }
   static void destruct_CHI2_t(void *p) {
      typedef ::CHI2_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CHI2_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CL01_t(void *p) {
      return  p ? new(p) ::CL01_t : new ::CL01_t;
   }
   static void *newArray_CL01_t(Long_t nElements, void *p) {
      return p ? new(p) ::CL01_t[nElements] : new ::CL01_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CL01_t(void *p) {
      delete ((::CL01_t*)p);
   }
   static void deleteArray_CL01_t(void *p) {
      delete [] ((::CL01_t*)p);
   }
   static void destruct_CL01_t(void *p) {
      typedef ::CL01_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CL01_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CLST_t(void *p) {
      return  p ? new(p) ::CLST_t : new ::CLST_t;
   }
   static void *newArray_CLST_t(Long_t nElements, void *p) {
      return p ? new(p) ::CLST_t[nElements] : new ::CLST_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CLST_t(void *p) {
      delete ((::CLST_t*)p);
   }
   static void deleteArray_CLST_t(void *p) {
      delete [] ((::CLST_t*)p);
   }
   static void destruct_CLST_t(void *p) {
      typedef ::CLST_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CLST_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CPED_t(void *p) {
      return  p ? new(p) ::CPED_t : new ::CPED_t;
   }
   static void *newArray_CPED_t(Long_t nElements, void *p) {
      return p ? new(p) ::CPED_t[nElements] : new ::CPED_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CPED_t(void *p) {
      delete ((::CPED_t*)p);
   }
   static void deleteArray_CPED_t(void *p) {
      delete [] ((::CPED_t*)p);
   }
   static void destruct_CPED_t(void *p) {
      typedef ::CPED_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CPED_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_CSQL_t(void *p) {
      return  p ? new(p) ::CSQL_t : new ::CSQL_t;
   }
   static void *newArray_CSQL_t(Long_t nElements, void *p) {
      return p ? new(p) ::CSQL_t[nElements] : new ::CSQL_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_CSQL_t(void *p) {
      delete ((::CSQL_t*)p);
   }
   static void deleteArray_CSQL_t(void *p) {
      delete [] ((::CSQL_t*)p);
   }
   static void destruct_CSQL_t(void *p) {
      typedef ::CSQL_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CSQL_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DC0_t(void *p) {
      return  p ? new(p) ::DC0_t : new ::DC0_t;
   }
   static void *newArray_DC0_t(Long_t nElements, void *p) {
      return p ? new(p) ::DC0_t[nElements] : new ::DC0_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DC0_t(void *p) {
      delete ((::DC0_t*)p);
   }
   static void deleteArray_DC0_t(void *p) {
      delete [] ((::DC0_t*)p);
   }
   static void destruct_DC0_t(void *p) {
      typedef ::DC0_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DC0_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DC1_t(void *p) {
      return  p ? new(p) ::DC1_t : new ::DC1_t;
   }
   static void *newArray_DC1_t(Long_t nElements, void *p) {
      return p ? new(p) ::DC1_t[nElements] : new ::DC1_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DC1_t(void *p) {
      delete ((::DC1_t*)p);
   }
   static void deleteArray_DC1_t(void *p) {
      delete [] ((::DC1_t*)p);
   }
   static void destruct_DC1_t(void *p) {
      typedef ::DC1_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DC1_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DCDW_t(void *p) {
      return  p ? new(p) ::DCDW_t : new ::DCDW_t;
   }
   static void *newArray_DCDW_t(Long_t nElements, void *p) {
      return p ? new(p) ::DCDW_t[nElements] : new ::DCDW_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DCDW_t(void *p) {
      delete ((::DCDW_t*)p);
   }
   static void deleteArray_DCDW_t(void *p) {
      delete [] ((::DCDW_t*)p);
   }
   static void destruct_DCDW_t(void *p) {
      typedef ::DCDW_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DCDW_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DCGM_t(void *p) {
      return  p ? new(p) ::DCGM_t : new ::DCGM_t;
   }
   static void *newArray_DCGM_t(Long_t nElements, void *p) {
      return p ? new(p) ::DCGM_t[nElements] : new ::DCGM_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DCGM_t(void *p) {
      delete ((::DCGM_t*)p);
   }
   static void deleteArray_DCGM_t(void *p) {
      delete [] ((::DCGM_t*)p);
   }
   static void destruct_DCGM_t(void *p) {
      typedef ::DCGM_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DCGM_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DCGW_t(void *p) {
      return  p ? new(p) ::DCGW_t : new ::DCGW_t;
   }
   static void *newArray_DCGW_t(Long_t nElements, void *p) {
      return p ? new(p) ::DCGW_t[nElements] : new ::DCGW_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DCGW_t(void *p) {
      delete ((::DCGW_t*)p);
   }
   static void deleteArray_DCGW_t(void *p) {
      delete [] ((::DCGW_t*)p);
   }
   static void destruct_DCGW_t(void *p) {
      typedef ::DCGW_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DCGW_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DCH_t(void *p) {
      return  p ? new(p) ::DCH_t : new ::DCH_t;
   }
   static void *newArray_DCH_t(Long_t nElements, void *p) {
      return p ? new(p) ::DCH_t[nElements] : new ::DCH_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DCH_t(void *p) {
      delete ((::DCH_t*)p);
   }
   static void deleteArray_DCH_t(void *p) {
      delete [] ((::DCH_t*)p);
   }
   static void destruct_DCH_t(void *p) {
      typedef ::DCH_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DCH_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DCMN_t(void *p) {
      return  p ? new(p) ::DCMN_t : new ::DCMN_t;
   }
   static void *newArray_DCMN_t(Long_t nElements, void *p) {
      return p ? new(p) ::DCMN_t[nElements] : new ::DCMN_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DCMN_t(void *p) {
      delete ((::DCMN_t*)p);
   }
   static void deleteArray_DCMN_t(void *p) {
      delete [] ((::DCMN_t*)p);
   }
   static void destruct_DCMN_t(void *p) {
      typedef ::DCMN_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DCMN_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DCPB_t(void *p) {
      return  p ? new(p) ::DCPB_t : new ::DCPB_t;
   }
   static void *newArray_DCPB_t(Long_t nElements, void *p) {
      return p ? new(p) ::DCPB_t[nElements] : new ::DCPB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DCPB_t(void *p) {
      delete ((::DCPB_t*)p);
   }
   static void deleteArray_DCPB_t(void *p) {
      delete [] ((::DCPB_t*)p);
   }
   static void destruct_DCPB_t(void *p) {
      typedef ::DCPB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DCPB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DCV1_t(void *p) {
      return  p ? new(p) ::DCV1_t : new ::DCV1_t;
   }
   static void *newArray_DCV1_t(Long_t nElements, void *p) {
      return p ? new(p) ::DCV1_t[nElements] : new ::DCV1_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DCV1_t(void *p) {
      delete ((::DCV1_t*)p);
   }
   static void deleteArray_DCV1_t(void *p) {
      delete [] ((::DCV1_t*)p);
   }
   static void destruct_DCV1_t(void *p) {
      typedef ::DCV1_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DCV1_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DCV2_t(void *p) {
      return  p ? new(p) ::DCV2_t : new ::DCV2_t;
   }
   static void *newArray_DCV2_t(Long_t nElements, void *p) {
      return p ? new(p) ::DCV2_t[nElements] : new ::DCV2_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DCV2_t(void *p) {
      delete ((::DCV2_t*)p);
   }
   static void deleteArray_DCV2_t(void *p) {
      delete [] ((::DCV2_t*)p);
   }
   static void destruct_DCV2_t(void *p) {
      typedef ::DCV2_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DCV2_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DCV3_t(void *p) {
      return  p ? new(p) ::DCV3_t : new ::DCV3_t;
   }
   static void *newArray_DCV3_t(Long_t nElements, void *p) {
      return p ? new(p) ::DCV3_t[nElements] : new ::DCV3_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DCV3_t(void *p) {
      delete ((::DCV3_t*)p);
   }
   static void deleteArray_DCV3_t(void *p) {
      delete [] ((::DCV3_t*)p);
   }
   static void destruct_DCV3_t(void *p) {
      typedef ::DCV3_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DCV3_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DDLY_t(void *p) {
      return  p ? new(p) ::DDLY_t : new ::DDLY_t;
   }
   static void *newArray_DDLY_t(Long_t nElements, void *p) {
      return p ? new(p) ::DDLY_t[nElements] : new ::DDLY_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DDLY_t(void *p) {
      delete ((::DDLY_t*)p);
   }
   static void deleteArray_DDLY_t(void *p) {
      delete [] ((::DDLY_t*)p);
   }
   static void destruct_DDLY_t(void *p) {
      typedef ::DDLY_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DDLY_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DGEO_t(void *p) {
      return  p ? new(p) ::DGEO_t : new ::DGEO_t;
   }
   static void *newArray_DGEO_t(Long_t nElements, void *p) {
      return p ? new(p) ::DGEO_t[nElements] : new ::DGEO_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DGEO_t(void *p) {
      delete ((::DGEO_t*)p);
   }
   static void deleteArray_DGEO_t(void *p) {
      delete [] ((::DGEO_t*)p);
   }
   static void destruct_DGEO_t(void *p) {
      typedef ::DGEO_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DGEO_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DHCL_t(void *p) {
      return  p ? new(p) ::DHCL_t : new ::DHCL_t;
   }
   static void *newArray_DHCL_t(Long_t nElements, void *p) {
      return p ? new(p) ::DHCL_t[nElements] : new ::DHCL_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DHCL_t(void *p) {
      delete ((::DHCL_t*)p);
   }
   static void deleteArray_DHCL_t(void *p) {
      delete [] ((::DHCL_t*)p);
   }
   static void destruct_DHCL_t(void *p) {
      typedef ::DHCL_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DHCL_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DITM_t(void *p) {
      return  p ? new(p) ::DITM_t : new ::DITM_t;
   }
   static void *newArray_DITM_t(Long_t nElements, void *p) {
      return p ? new(p) ::DITM_t[nElements] : new ::DITM_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DITM_t(void *p) {
      delete ((::DITM_t*)p);
   }
   static void deleteArray_DITM_t(void *p) {
      delete [] ((::DITM_t*)p);
   }
   static void destruct_DITM_t(void *p) {
      typedef ::DITM_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DITM_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DOCA_t(void *p) {
      return  p ? new(p) ::DOCA_t : new ::DOCA_t;
   }
   static void *newArray_DOCA_t(Long_t nElements, void *p) {
      return p ? new(p) ::DOCA_t[nElements] : new ::DOCA_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DOCA_t(void *p) {
      delete ((::DOCA_t*)p);
   }
   static void deleteArray_DOCA_t(void *p) {
      delete [] ((::DOCA_t*)p);
   }
   static void destruct_DOCA_t(void *p) {
      typedef ::DOCA_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DOCA_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DPCP_t(void *p) {
      return  p ? new(p) ::DPCP_t : new ::DPCP_t;
   }
   static void *newArray_DPCP_t(Long_t nElements, void *p) {
      return p ? new(p) ::DPCP_t[nElements] : new ::DPCP_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DPCP_t(void *p) {
      delete ((::DPCP_t*)p);
   }
   static void deleteArray_DPCP_t(void *p) {
      delete [] ((::DPCP_t*)p);
   }
   static void destruct_DPCP_t(void *p) {
      typedef ::DPCP_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DPCP_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DPSP_t(void *p) {
      return  p ? new(p) ::DPSP_t : new ::DPSP_t;
   }
   static void *newArray_DPSP_t(Long_t nElements, void *p) {
      return p ? new(p) ::DPSP_t[nElements] : new ::DPSP_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DPSP_t(void *p) {
      delete ((::DPSP_t*)p);
   }
   static void deleteArray_DPSP_t(void *p) {
      delete [] ((::DPSP_t*)p);
   }
   static void destruct_DPSP_t(void *p) {
      typedef ::DPSP_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DPSP_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DSPC_t(void *p) {
      return  p ? new(p) ::DSPC_t : new ::DSPC_t;
   }
   static void *newArray_DSPC_t(Long_t nElements, void *p) {
      return p ? new(p) ::DSPC_t[nElements] : new ::DSPC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DSPC_t(void *p) {
      delete ((::DSPC_t*)p);
   }
   static void deleteArray_DSPC_t(void *p) {
      delete [] ((::DSPC_t*)p);
   }
   static void destruct_DSPC_t(void *p) {
      typedef ::DSPC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DSPC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DSPS_t(void *p) {
      return  p ? new(p) ::DSPS_t : new ::DSPS_t;
   }
   static void *newArray_DSPS_t(Long_t nElements, void *p) {
      return p ? new(p) ::DSPS_t[nElements] : new ::DSPS_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DSPS_t(void *p) {
      delete ((::DSPS_t*)p);
   }
   static void deleteArray_DSPS_t(void *p) {
      delete [] ((::DSPS_t*)p);
   }
   static void destruct_DSPS_t(void *p) {
      typedef ::DSPS_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DSPS_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DSTC_t(void *p) {
      return  p ? new(p) ::DSTC_t : new ::DSTC_t;
   }
   static void *newArray_DSTC_t(Long_t nElements, void *p) {
      return p ? new(p) ::DSTC_t[nElements] : new ::DSTC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DSTC_t(void *p) {
      delete ((::DSTC_t*)p);
   }
   static void deleteArray_DSTC_t(void *p) {
      delete [] ((::DSTC_t*)p);
   }
   static void destruct_DSTC_t(void *p) {
      typedef ::DSTC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DSTC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DTCP_t(void *p) {
      return  p ? new(p) ::DTCP_t : new ::DTCP_t;
   }
   static void *newArray_DTCP_t(Long_t nElements, void *p) {
      return p ? new(p) ::DTCP_t[nElements] : new ::DTCP_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DTCP_t(void *p) {
      delete ((::DTCP_t*)p);
   }
   static void deleteArray_DTCP_t(void *p) {
      delete [] ((::DTCP_t*)p);
   }
   static void destruct_DTCP_t(void *p) {
      typedef ::DTCP_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DTCP_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_DTRK_t(void *p) {
      return  p ? new(p) ::DTRK_t : new ::DTRK_t;
   }
   static void *newArray_DTRK_t(Long_t nElements, void *p) {
      return p ? new(p) ::DTRK_t[nElements] : new ::DTRK_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_DTRK_t(void *p) {
      delete ((::DTRK_t*)p);
   }
   static void deleteArray_DTRK_t(void *p) {
      delete [] ((::DTRK_t*)p);
   }
   static void destruct_DTRK_t(void *p) {
      typedef ::DTRK_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::DTRK_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_EC01_t(void *p) {
      return  p ? new(p) ::EC01_t : new ::EC01_t;
   }
   static void *newArray_EC01_t(Long_t nElements, void *p) {
      return p ? new(p) ::EC01_t[nElements] : new ::EC01_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_EC01_t(void *p) {
      delete ((::EC01_t*)p);
   }
   static void deleteArray_EC01_t(void *p) {
      delete [] ((::EC01_t*)p);
   }
   static void destruct_EC01_t(void *p) {
      typedef ::EC01_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EC01_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_EC1_t(void *p) {
      return  p ? new(p) ::EC1_t : new ::EC1_t;
   }
   static void *newArray_EC1_t(Long_t nElements, void *p) {
      return p ? new(p) ::EC1_t[nElements] : new ::EC1_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_EC1_t(void *p) {
      delete ((::EC1_t*)p);
   }
   static void deleteArray_EC1_t(void *p) {
      delete [] ((::EC1_t*)p);
   }
   static void destruct_EC1_t(void *p) {
      typedef ::EC1_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EC1_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_EC1P_t(void *p) {
      return  p ? new(p) ::EC1P_t : new ::EC1P_t;
   }
   static void *newArray_EC1P_t(Long_t nElements, void *p) {
      return p ? new(p) ::EC1P_t[nElements] : new ::EC1P_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_EC1P_t(void *p) {
      delete ((::EC1P_t*)p);
   }
   static void deleteArray_EC1P_t(void *p) {
      delete [] ((::EC1P_t*)p);
   }
   static void destruct_EC1P_t(void *p) {
      typedef ::EC1P_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EC1P_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_EC1R_t(void *p) {
      return  p ? new(p) ::EC1R_t : new ::EC1R_t;
   }
   static void *newArray_EC1R_t(Long_t nElements, void *p) {
      return p ? new(p) ::EC1R_t[nElements] : new ::EC1R_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_EC1R_t(void *p) {
      delete ((::EC1R_t*)p);
   }
   static void deleteArray_EC1R_t(void *p) {
      delete [] ((::EC1R_t*)p);
   }
   static void destruct_EC1R_t(void *p) {
      typedef ::EC1R_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EC1R_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECCA_t(void *p) {
      return  p ? new(p) ::ECCA_t : new ::ECCA_t;
   }
   static void *newArray_ECCA_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECCA_t[nElements] : new ::ECCA_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECCA_t(void *p) {
      delete ((::ECCA_t*)p);
   }
   static void deleteArray_ECCA_t(void *p) {
      delete [] ((::ECCA_t*)p);
   }
   static void destruct_ECCA_t(void *p) {
      typedef ::ECCA_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECCA_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECCL_t(void *p) {
      return  p ? new(p) ::ECCL_t : new ::ECCL_t;
   }
   static void *newArray_ECCL_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECCL_t[nElements] : new ::ECCL_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECCL_t(void *p) {
      delete ((::ECCL_t*)p);
   }
   static void deleteArray_ECCL_t(void *p) {
      delete [] ((::ECCL_t*)p);
   }
   static void destruct_ECCL_t(void *p) {
      typedef ::ECCL_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECCL_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECCT_t(void *p) {
      return  p ? new(p) ::ECCT_t : new ::ECCT_t;
   }
   static void *newArray_ECCT_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECCT_t[nElements] : new ::ECCT_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECCT_t(void *p) {
      delete ((::ECCT_t*)p);
   }
   static void deleteArray_ECCT_t(void *p) {
      delete [] ((::ECCT_t*)p);
   }
   static void destruct_ECCT_t(void *p) {
      typedef ::ECCT_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECCT_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_EC_t(void *p) {
      return  p ? new(p) ::EC_t : new ::EC_t;
   }
   static void *newArray_EC_t(Long_t nElements, void *p) {
      return p ? new(p) ::EC_t[nElements] : new ::EC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_EC_t(void *p) {
      delete ((::EC_t*)p);
   }
   static void deleteArray_EC_t(void *p) {
      delete [] ((::EC_t*)p);
   }
   static void destruct_EC_t(void *p) {
      typedef ::EC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECDI_t(void *p) {
      return  p ? new(p) ::ECDI_t : new ::ECDI_t;
   }
   static void *newArray_ECDI_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECDI_t[nElements] : new ::ECDI_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECDI_t(void *p) {
      delete ((::ECDI_t*)p);
   }
   static void deleteArray_ECDI_t(void *p) {
      delete [] ((::ECDI_t*)p);
   }
   static void destruct_ECDI_t(void *p) {
      typedef ::ECDI_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECDI_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECG_t(void *p) {
      return  p ? new(p) ::ECG_t : new ::ECG_t;
   }
   static void *newArray_ECG_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECG_t[nElements] : new ::ECG_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECG_t(void *p) {
      delete ((::ECG_t*)p);
   }
   static void deleteArray_ECG_t(void *p) {
      delete [] ((::ECG_t*)p);
   }
   static void destruct_ECG_t(void *p) {
      typedef ::ECG_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECG_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECHB_t(void *p) {
      return  p ? new(p) ::ECHB_t : new ::ECHB_t;
   }
   static void *newArray_ECHB_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECHB_t[nElements] : new ::ECHB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECHB_t(void *p) {
      delete ((::ECHB_t*)p);
   }
   static void deleteArray_ECHB_t(void *p) {
      delete [] ((::ECHB_t*)p);
   }
   static void destruct_ECHB_t(void *p) {
      typedef ::ECHB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECHB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECH_t(void *p) {
      return  p ? new(p) ::ECH_t : new ::ECH_t;
   }
   static void *newArray_ECH_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECH_t[nElements] : new ::ECH_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECH_t(void *p) {
      delete ((::ECH_t*)p);
   }
   static void deleteArray_ECH_t(void *p) {
      delete [] ((::ECH_t*)p);
   }
   static void destruct_ECH_t(void *p) {
      typedef ::ECH_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECH_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECMT_t(void *p) {
      return  p ? new(p) ::ECMT_t : new ::ECMT_t;
   }
   static void *newArray_ECMT_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECMT_t[nElements] : new ::ECMT_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECMT_t(void *p) {
      delete ((::ECMT_t*)p);
   }
   static void deleteArray_ECMT_t(void *p) {
      delete [] ((::ECMT_t*)p);
   }
   static void destruct_ECMT_t(void *p) {
      typedef ::ECMT_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECMT_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECP1_t(void *p) {
      return  p ? new(p) ::ECP1_t : new ::ECP1_t;
   }
   static void *newArray_ECP1_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECP1_t[nElements] : new ::ECP1_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECP1_t(void *p) {
      delete ((::ECP1_t*)p);
   }
   static void deleteArray_ECP1_t(void *p) {
      delete [] ((::ECP1_t*)p);
   }
   static void destruct_ECP1_t(void *p) {
      typedef ::ECP1_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECP1_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECPB_t(void *p) {
      return  p ? new(p) ::ECPB_t : new ::ECPB_t;
   }
   static void *newArray_ECPB_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECPB_t[nElements] : new ::ECPB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECPB_t(void *p) {
      delete ((::ECPB_t*)p);
   }
   static void deleteArray_ECPB_t(void *p) {
      delete [] ((::ECPB_t*)p);
   }
   static void destruct_ECPB_t(void *p) {
      typedef ::ECPB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECPB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECPC_t(void *p) {
      return  p ? new(p) ::ECPC_t : new ::ECPC_t;
   }
   static void *newArray_ECPC_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECPC_t[nElements] : new ::ECPC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECPC_t(void *p) {
      delete ((::ECPC_t*)p);
   }
   static void deleteArray_ECPC_t(void *p) {
      delete [] ((::ECPC_t*)p);
   }
   static void destruct_ECPC_t(void *p) {
      typedef ::ECPC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECPC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECP_t(void *p) {
      return  p ? new(p) ::ECP_t : new ::ECP_t;
   }
   static void *newArray_ECP_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECP_t[nElements] : new ::ECP_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECP_t(void *p) {
      delete ((::ECP_t*)p);
   }
   static void deleteArray_ECP_t(void *p) {
      delete [] ((::ECP_t*)p);
   }
   static void destruct_ECP_t(void *p) {
      typedef ::ECP_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECP_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECPE_t(void *p) {
      return  p ? new(p) ::ECPE_t : new ::ECPE_t;
   }
   static void *newArray_ECPE_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECPE_t[nElements] : new ::ECPE_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECPE_t(void *p) {
      delete ((::ECPE_t*)p);
   }
   static void deleteArray_ECPE_t(void *p) {
      delete [] ((::ECPE_t*)p);
   }
   static void destruct_ECPE_t(void *p) {
      typedef ::ECPE_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECPE_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECPI_t(void *p) {
      return  p ? new(p) ::ECPI_t : new ::ECPI_t;
   }
   static void *newArray_ECPI_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECPI_t[nElements] : new ::ECPI_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECPI_t(void *p) {
      delete ((::ECPI_t*)p);
   }
   static void deleteArray_ECPI_t(void *p) {
      delete [] ((::ECPI_t*)p);
   }
   static void destruct_ECPI_t(void *p) {
      typedef ::ECPI_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECPI_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECPO_t(void *p) {
      return  p ? new(p) ::ECPO_t : new ::ECPO_t;
   }
   static void *newArray_ECPO_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECPO_t[nElements] : new ::ECPO_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECPO_t(void *p) {
      delete ((::ECPO_t*)p);
   }
   static void deleteArray_ECPO_t(void *p) {
      delete [] ((::ECPO_t*)p);
   }
   static void destruct_ECPO_t(void *p) {
      typedef ::ECPO_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECPO_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECRB_t(void *p) {
      return  p ? new(p) ::ECRB_t : new ::ECRB_t;
   }
   static void *newArray_ECRB_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECRB_t[nElements] : new ::ECRB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECRB_t(void *p) {
      delete ((::ECRB_t*)p);
   }
   static void deleteArray_ECRB_t(void *p) {
      delete [] ((::ECRB_t*)p);
   }
   static void destruct_ECRB_t(void *p) {
      typedef ::ECRB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECRB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ECS_t(void *p) {
      return  p ? new(p) ::ECS_t : new ::ECS_t;
   }
   static void *newArray_ECS_t(Long_t nElements, void *p) {
      return p ? new(p) ::ECS_t[nElements] : new ::ECS_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ECS_t(void *p) {
      delete ((::ECS_t*)p);
   }
   static void deleteArray_ECS_t(void *p) {
      delete [] ((::ECS_t*)p);
   }
   static void destruct_ECS_t(void *p) {
      typedef ::ECS_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ECS_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_EID0_t(void *p) {
      return  p ? new(p) ::EID0_t : new ::EID0_t;
   }
   static void *newArray_EID0_t(Long_t nElements, void *p) {
      return p ? new(p) ::EID0_t[nElements] : new ::EID0_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_EID0_t(void *p) {
      delete ((::EID0_t*)p);
   }
   static void deleteArray_EID0_t(void *p) {
      delete [] ((::EID0_t*)p);
   }
   static void destruct_EID0_t(void *p) {
      typedef ::EID0_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EID0_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_EPIC_t(void *p) {
      return  p ? new(p) ::EPIC_t : new ::EPIC_t;
   }
   static void *newArray_EPIC_t(Long_t nElements, void *p) {
      return p ? new(p) ::EPIC_t[nElements] : new ::EPIC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_EPIC_t(void *p) {
      delete ((::EPIC_t*)p);
   }
   static void deleteArray_EPIC_t(void *p) {
      delete [] ((::EPIC_t*)p);
   }
   static void destruct_EPIC_t(void *p) {
      typedef ::EPIC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EPIC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_EVNT_t(void *p) {
      return  p ? new(p) ::EVNT_t : new ::EVNT_t;
   }
   static void *newArray_EVNT_t(Long_t nElements, void *p) {
      return p ? new(p) ::EVNT_t[nElements] : new ::EVNT_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_EVNT_t(void *p) {
      delete ((::EVNT_t*)p);
   }
   static void deleteArray_EVNT_t(void *p) {
      delete [] ((::EVNT_t*)p);
   }
   static void destruct_EVNT_t(void *p) {
      typedef ::EVNT_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EVNT_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_FBPM_t(void *p) {
      return  p ? new(p) ::FBPM_t : new ::FBPM_t;
   }
   static void *newArray_FBPM_t(Long_t nElements, void *p) {
      return p ? new(p) ::FBPM_t[nElements] : new ::FBPM_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_FBPM_t(void *p) {
      delete ((::FBPM_t*)p);
   }
   static void deleteArray_FBPM_t(void *p) {
      delete [] ((::FBPM_t*)p);
   }
   static void destruct_FBPM_t(void *p) {
      typedef ::FBPM_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::FBPM_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_G1SL_t(void *p) {
      return  p ? new(p) ::G1SL_t : new ::G1SL_t;
   }
   static void *newArray_G1SL_t(Long_t nElements, void *p) {
      return p ? new(p) ::G1SL_t[nElements] : new ::G1SL_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_G1SL_t(void *p) {
      delete ((::G1SL_t*)p);
   }
   static void deleteArray_G1SL_t(void *p) {
      delete [] ((::G1SL_t*)p);
   }
   static void destruct_G1SL_t(void *p) {
      typedef ::G1SL_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::G1SL_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_G2SL_t(void *p) {
      return  p ? new(p) ::G2SL_t : new ::G2SL_t;
   }
   static void *newArray_G2SL_t(Long_t nElements, void *p) {
      return p ? new(p) ::G2SL_t[nElements] : new ::G2SL_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_G2SL_t(void *p) {
      delete ((::G2SL_t*)p);
   }
   static void deleteArray_G2SL_t(void *p) {
      delete [] ((::G2SL_t*)p);
   }
   static void destruct_G2SL_t(void *p) {
      typedef ::G2SL_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::G2SL_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_G3SL_t(void *p) {
      return  p ? new(p) ::G3SL_t : new ::G3SL_t;
   }
   static void *newArray_G3SL_t(Long_t nElements, void *p) {
      return p ? new(p) ::G3SL_t[nElements] : new ::G3SL_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_G3SL_t(void *p) {
      delete ((::G3SL_t*)p);
   }
   static void deleteArray_G3SL_t(void *p) {
      delete [] ((::G3SL_t*)p);
   }
   static void destruct_G3SL_t(void *p) {
      typedef ::G3SL_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::G3SL_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_G4SL_t(void *p) {
      return  p ? new(p) ::G4SL_t : new ::G4SL_t;
   }
   static void *newArray_G4SL_t(Long_t nElements, void *p) {
      return p ? new(p) ::G4SL_t[nElements] : new ::G4SL_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_G4SL_t(void *p) {
      delete ((::G4SL_t*)p);
   }
   static void deleteArray_G4SL_t(void *p) {
      delete [] ((::G4SL_t*)p);
   }
   static void destruct_G4SL_t(void *p) {
      typedef ::G4SL_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::G4SL_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_GPAR_t(void *p) {
      return  p ? new(p) ::GPAR_t : new ::GPAR_t;
   }
   static void *newArray_GPAR_t(Long_t nElements, void *p) {
      return p ? new(p) ::GPAR_t[nElements] : new ::GPAR_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_GPAR_t(void *p) {
      delete ((::GPAR_t*)p);
   }
   static void deleteArray_GPAR_t(void *p) {
      delete [] ((::GPAR_t*)p);
   }
   static void destruct_GPAR_t(void *p) {
      typedef ::GPAR_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::GPAR_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_GPID_t(void *p) {
      return  p ? new(p) ::GPID_t : new ::GPID_t;
   }
   static void *newArray_GPID_t(Long_t nElements, void *p) {
      return p ? new(p) ::GPID_t[nElements] : new ::GPID_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_GPID_t(void *p) {
      delete ((::GPID_t*)p);
   }
   static void deleteArray_GPID_t(void *p) {
      delete [] ((::GPID_t*)p);
   }
   static void destruct_GPID_t(void *p) {
      typedef ::GPID_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::GPID_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_GP_X_t(void *p) {
      return  p ? new(p) ::GP_X_t : new ::GP_X_t;
   }
   static void *newArray_GP_X_t(Long_t nElements, void *p) {
      return p ? new(p) ::GP_X_t[nElements] : new ::GP_X_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_GP_X_t(void *p) {
      delete ((::GP_X_t*)p);
   }
   static void deleteArray_GP_X_t(void *p) {
      delete [] ((::GP_X_t*)p);
   }
   static void destruct_GP_X_t(void *p) {
      typedef ::GP_X_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::GP_X_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_GP_Y_t(void *p) {
      return  p ? new(p) ::GP_Y_t : new ::GP_Y_t;
   }
   static void *newArray_GP_Y_t(Long_t nElements, void *p) {
      return p ? new(p) ::GP_Y_t[nElements] : new ::GP_Y_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_GP_Y_t(void *p) {
      delete ((::GP_Y_t*)p);
   }
   static void deleteArray_GP_Y_t(void *p) {
      delete [] ((::GP_Y_t*)p);
   }
   static void destruct_GP_Y_t(void *p) {
      typedef ::GP_Y_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::GP_Y_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_HBER_t(void *p) {
      return  p ? new(p) ::HBER_t : new ::HBER_t;
   }
   static void *newArray_HBER_t(Long_t nElements, void *p) {
      return p ? new(p) ::HBER_t[nElements] : new ::HBER_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_HBER_t(void *p) {
      delete ((::HBER_t*)p);
   }
   static void deleteArray_HBER_t(void *p) {
      delete [] ((::HBER_t*)p);
   }
   static void destruct_HBER_t(void *p) {
      typedef ::HBER_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HBER_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_HBID_t(void *p) {
      return  p ? new(p) ::HBID_t : new ::HBID_t;
   }
   static void *newArray_HBID_t(Long_t nElements, void *p) {
      return p ? new(p) ::HBID_t[nElements] : new ::HBID_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_HBID_t(void *p) {
      delete ((::HBID_t*)p);
   }
   static void deleteArray_HBID_t(void *p) {
      delete [] ((::HBID_t*)p);
   }
   static void destruct_HBID_t(void *p) {
      typedef ::HBID_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HBID_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_HBLA_t(void *p) {
      return  p ? new(p) ::HBLA_t : new ::HBLA_t;
   }
   static void *newArray_HBLA_t(Long_t nElements, void *p) {
      return p ? new(p) ::HBLA_t[nElements] : new ::HBLA_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_HBLA_t(void *p) {
      delete ((::HBLA_t*)p);
   }
   static void deleteArray_HBLA_t(void *p) {
      delete [] ((::HBLA_t*)p);
   }
   static void destruct_HBLA_t(void *p) {
      typedef ::HBLA_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HBLA_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_HBTB_t(void *p) {
      return  p ? new(p) ::HBTB_t : new ::HBTB_t;
   }
   static void *newArray_HBTB_t(Long_t nElements, void *p) {
      return p ? new(p) ::HBTB_t[nElements] : new ::HBTB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_HBTB_t(void *p) {
      delete ((::HBTB_t*)p);
   }
   static void deleteArray_HBTB_t(void *p) {
      delete [] ((::HBTB_t*)p);
   }
   static void destruct_HBTB_t(void *p) {
      typedef ::HBTB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HBTB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_HBTR_t(void *p) {
      return  p ? new(p) ::HBTR_t : new ::HBTR_t;
   }
   static void *newArray_HBTR_t(Long_t nElements, void *p) {
      return p ? new(p) ::HBTR_t[nElements] : new ::HBTR_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_HBTR_t(void *p) {
      delete ((::HBTR_t*)p);
   }
   static void deleteArray_HBTR_t(void *p) {
      delete [] ((::HBTR_t*)p);
   }
   static void destruct_HBTR_t(void *p) {
      typedef ::HBTR_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HBTR_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_HCAL_t(void *p) {
      return  p ? new(p) ::HCAL_t : new ::HCAL_t;
   }
   static void *newArray_HCAL_t(Long_t nElements, void *p) {
      return p ? new(p) ::HCAL_t[nElements] : new ::HCAL_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_HCAL_t(void *p) {
      delete ((::HCAL_t*)p);
   }
   static void deleteArray_HCAL_t(void *p) {
      delete [] ((::HCAL_t*)p);
   }
   static void destruct_HCAL_t(void *p) {
      typedef ::HCAL_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HCAL_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_HDPL_t(void *p) {
      return  p ? new(p) ::HDPL_t : new ::HDPL_t;
   }
   static void *newArray_HDPL_t(Long_t nElements, void *p) {
      return p ? new(p) ::HDPL_t[nElements] : new ::HDPL_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_HDPL_t(void *p) {
      delete ((::HDPL_t*)p);
   }
   static void deleteArray_HDPL_t(void *p) {
      delete [] ((::HDPL_t*)p);
   }
   static void destruct_HDPL_t(void *p) {
      typedef ::HDPL_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HDPL_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_HEAD_t(void *p) {
      return  p ? new(p) ::HEAD_t : new ::HEAD_t;
   }
   static void *newArray_HEAD_t(Long_t nElements, void *p) {
      return p ? new(p) ::HEAD_t[nElements] : new ::HEAD_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_HEAD_t(void *p) {
      delete ((::HEAD_t*)p);
   }
   static void deleteArray_HEAD_t(void *p) {
      delete [] ((::HEAD_t*)p);
   }
   static void destruct_HEAD_t(void *p) {
      typedef ::HEAD_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HEAD_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_HEVT_t(void *p) {
      return  p ? new(p) ::HEVT_t : new ::HEVT_t;
   }
   static void *newArray_HEVT_t(Long_t nElements, void *p) {
      return p ? new(p) ::HEVT_t[nElements] : new ::HEVT_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_HEVT_t(void *p) {
      delete ((::HEVT_t*)p);
   }
   static void deleteArray_HEVT_t(void *p) {
      delete [] ((::HEVT_t*)p);
   }
   static void destruct_HEVT_t(void *p) {
      typedef ::HEVT_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HEVT_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_HLS_t(void *p) {
      return  p ? new(p) ::HLS_t : new ::HLS_t;
   }
   static void *newArray_HLS_t(Long_t nElements, void *p) {
      return p ? new(p) ::HLS_t[nElements] : new ::HLS_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_HLS_t(void *p) {
      delete ((::HLS_t*)p);
   }
   static void deleteArray_HLS_t(void *p) {
      delete [] ((::HLS_t*)p);
   }
   static void destruct_HLS_t(void *p) {
      typedef ::HLS_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HLS_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_IC_t(void *p) {
      return  p ? new(p) ::IC_t : new ::IC_t;
   }
   static void *newArray_IC_t(Long_t nElements, void *p) {
      return p ? new(p) ::IC_t[nElements] : new ::IC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_IC_t(void *p) {
      delete ((::IC_t*)p);
   }
   static void deleteArray_IC_t(void *p) {
      delete [] ((::IC_t*)p);
   }
   static void destruct_IC_t(void *p) {
      typedef ::IC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::IC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ICHB_t(void *p) {
      return  p ? new(p) ::ICHB_t : new ::ICHB_t;
   }
   static void *newArray_ICHB_t(Long_t nElements, void *p) {
      return p ? new(p) ::ICHB_t[nElements] : new ::ICHB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ICHB_t(void *p) {
      delete ((::ICHB_t*)p);
   }
   static void deleteArray_ICHB_t(void *p) {
      delete [] ((::ICHB_t*)p);
   }
   static void destruct_ICHB_t(void *p) {
      typedef ::ICHB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ICHB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_KFIT_t(void *p) {
      return  p ? new(p) ::KFIT_t : new ::KFIT_t;
   }
   static void *newArray_KFIT_t(Long_t nElements, void *p) {
      return p ? new(p) ::KFIT_t[nElements] : new ::KFIT_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_KFIT_t(void *p) {
      delete ((::KFIT_t*)p);
   }
   static void deleteArray_KFIT_t(void *p) {
      delete [] ((::KFIT_t*)p);
   }
   static void destruct_KFIT_t(void *p) {
      typedef ::KFIT_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::KFIT_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_L1PG_t(void *p) {
      return  p ? new(p) ::L1PG_t : new ::L1PG_t;
   }
   static void *newArray_L1PG_t(Long_t nElements, void *p) {
      return p ? new(p) ::L1PG_t[nElements] : new ::L1PG_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_L1PG_t(void *p) {
      delete ((::L1PG_t*)p);
   }
   static void deleteArray_L1PG_t(void *p) {
      delete [] ((::L1PG_t*)p);
   }
   static void destruct_L1PG_t(void *p) {
      typedef ::L1PG_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::L1PG_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_L2H_t(void *p) {
      return  p ? new(p) ::L2H_t : new ::L2H_t;
   }
   static void *newArray_L2H_t(Long_t nElements, void *p) {
      return p ? new(p) ::L2H_t[nElements] : new ::L2H_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_L2H_t(void *p) {
      delete ((::L2H_t*)p);
   }
   static void deleteArray_L2H_t(void *p) {
      delete [] ((::L2H_t*)p);
   }
   static void destruct_L2H_t(void *p) {
      typedef ::L2H_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::L2H_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_L2S_t(void *p) {
      return  p ? new(p) ::L2S_t : new ::L2S_t;
   }
   static void *newArray_L2S_t(Long_t nElements, void *p) {
      return p ? new(p) ::L2S_t[nElements] : new ::L2S_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_L2S_t(void *p) {
      delete ((::L2S_t*)p);
   }
   static void deleteArray_L2S_t(void *p) {
      delete [] ((::L2S_t*)p);
   }
   static void destruct_L2S_t(void *p) {
      typedef ::L2S_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::L2S_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_LASR_t(void *p) {
      return  p ? new(p) ::LASR_t : new ::LASR_t;
   }
   static void *newArray_LASR_t(Long_t nElements, void *p) {
      return p ? new(p) ::LASR_t[nElements] : new ::LASR_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_LASR_t(void *p) {
      delete ((::LASR_t*)p);
   }
   static void deleteArray_LASR_t(void *p) {
      delete [] ((::LASR_t*)p);
   }
   static void destruct_LASR_t(void *p) {
      typedef ::LASR_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::LASR_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_LCDI_t(void *p) {
      return  p ? new(p) ::LCDI_t : new ::LCDI_t;
   }
   static void *newArray_LCDI_t(Long_t nElements, void *p) {
      return p ? new(p) ::LCDI_t[nElements] : new ::LCDI_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_LCDI_t(void *p) {
      delete ((::LCDI_t*)p);
   }
   static void deleteArray_LCDI_t(void *p) {
      delete [] ((::LCDI_t*)p);
   }
   static void destruct_LCDI_t(void *p) {
      typedef ::LCDI_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::LCDI_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_LCPB_t(void *p) {
      return  p ? new(p) ::LCPB_t : new ::LCPB_t;
   }
   static void *newArray_LCPB_t(Long_t nElements, void *p) {
      return p ? new(p) ::LCPB_t[nElements] : new ::LCPB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_LCPB_t(void *p) {
      delete ((::LCPB_t*)p);
   }
   static void deleteArray_LCPB_t(void *p) {
      delete [] ((::LCPB_t*)p);
   }
   static void destruct_LCPB_t(void *p) {
      typedef ::LCPB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::LCPB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_LOWQ_t(void *p) {
      return  p ? new(p) ::LOWQ_t : new ::LOWQ_t;
   }
   static void *newArray_LOWQ_t(Long_t nElements, void *p) {
      return p ? new(p) ::LOWQ_t[nElements] : new ::LOWQ_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_LOWQ_t(void *p) {
      delete ((::LOWQ_t*)p);
   }
   static void deleteArray_LOWQ_t(void *p) {
      delete [] ((::LOWQ_t*)p);
   }
   static void destruct_LOWQ_t(void *p) {
      typedef ::LOWQ_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::LOWQ_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_MCEV_t(void *p) {
      return  p ? new(p) ::MCEV_t : new ::MCEV_t;
   }
   static void *newArray_MCEV_t(Long_t nElements, void *p) {
      return p ? new(p) ::MCEV_t[nElements] : new ::MCEV_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_MCEV_t(void *p) {
      delete ((::MCEV_t*)p);
   }
   static void deleteArray_MCEV_t(void *p) {
      delete [] ((::MCEV_t*)p);
   }
   static void destruct_MCEV_t(void *p) {
      typedef ::MCEV_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MCEV_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_MCHD_t(void *p) {
      return  p ? new(p) ::MCHD_t : new ::MCHD_t;
   }
   static void *newArray_MCHD_t(Long_t nElements, void *p) {
      return p ? new(p) ::MCHD_t[nElements] : new ::MCHD_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_MCHD_t(void *p) {
      delete ((::MCHD_t*)p);
   }
   static void deleteArray_MCHD_t(void *p) {
      delete [] ((::MCHD_t*)p);
   }
   static void destruct_MCHD_t(void *p) {
      typedef ::MCHD_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MCHD_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_MCTK_t(void *p) {
      return  p ? new(p) ::MCTK_t : new ::MCTK_t;
   }
   static void *newArray_MCTK_t(Long_t nElements, void *p) {
      return p ? new(p) ::MCTK_t[nElements] : new ::MCTK_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_MCTK_t(void *p) {
      delete ((::MCTK_t*)p);
   }
   static void deleteArray_MCTK_t(void *p) {
      delete [] ((::MCTK_t*)p);
   }
   static void destruct_MCTK_t(void *p) {
      typedef ::MCTK_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MCTK_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_MCVX_t(void *p) {
      return  p ? new(p) ::MCVX_t : new ::MCVX_t;
   }
   static void *newArray_MCVX_t(Long_t nElements, void *p) {
      return p ? new(p) ::MCVX_t[nElements] : new ::MCVX_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_MCVX_t(void *p) {
      delete ((::MCVX_t*)p);
   }
   static void deleteArray_MCVX_t(void *p) {
      delete [] ((::MCVX_t*)p);
   }
   static void destruct_MCVX_t(void *p) {
      typedef ::MCVX_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MCVX_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_MTRK_t(void *p) {
      return  p ? new(p) ::MTRK_t : new ::MTRK_t;
   }
   static void *newArray_MTRK_t(Long_t nElements, void *p) {
      return p ? new(p) ::MTRK_t[nElements] : new ::MTRK_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_MTRK_t(void *p) {
      delete ((::MTRK_t*)p);
   }
   static void deleteArray_MTRK_t(void *p) {
      delete [] ((::MTRK_t*)p);
   }
   static void destruct_MTRK_t(void *p) {
      typedef ::MTRK_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MTRK_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_MVRT_t(void *p) {
      return  p ? new(p) ::MVRT_t : new ::MVRT_t;
   }
   static void *newArray_MVRT_t(Long_t nElements, void *p) {
      return p ? new(p) ::MVRT_t[nElements] : new ::MVRT_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_MVRT_t(void *p) {
      delete ((::MVRT_t*)p);
   }
   static void deleteArray_MVRT_t(void *p) {
      delete [] ((::MVRT_t*)p);
   }
   static void destruct_MVRT_t(void *p) {
      typedef ::MVRT_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::MVRT_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PART_t(void *p) {
      return  p ? new(p) ::PART_t : new ::PART_t;
   }
   static void *newArray_PART_t(Long_t nElements, void *p) {
      return p ? new(p) ::PART_t[nElements] : new ::PART_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PART_t(void *p) {
      delete ((::PART_t*)p);
   }
   static void deleteArray_PART_t(void *p) {
      delete [] ((::PART_t*)p);
   }
   static void destruct_PART_t(void *p) {
      typedef ::PART_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PART_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PCO_t(void *p) {
      return  p ? new(p) ::PCO_t : new ::PCO_t;
   }
   static void *newArray_PCO_t(Long_t nElements, void *p) {
      return p ? new(p) ::PCO_t[nElements] : new ::PCO_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PCO_t(void *p) {
      delete ((::PCO_t*)p);
   }
   static void deleteArray_PCO_t(void *p) {
      delete [] ((::PCO_t*)p);
   }
   static void destruct_PCO_t(void *p) {
      typedef ::PCO_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PCO_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PHTM_t(void *p) {
      return  p ? new(p) ::PHTM_t : new ::PHTM_t;
   }
   static void *newArray_PHTM_t(Long_t nElements, void *p) {
      return p ? new(p) ::PHTM_t[nElements] : new ::PHTM_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PHTM_t(void *p) {
      delete ((::PHTM_t*)p);
   }
   static void deleteArray_PHTM_t(void *p) {
      delete [] ((::PHTM_t*)p);
   }
   static void destruct_PHTM_t(void *p) {
      typedef ::PHTM_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PHTM_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PID1_t(void *p) {
      return  p ? new(p) ::PID1_t : new ::PID1_t;
   }
   static void *newArray_PID1_t(Long_t nElements, void *p) {
      return p ? new(p) ::PID1_t[nElements] : new ::PID1_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PID1_t(void *p) {
      delete ((::PID1_t*)p);
   }
   static void deleteArray_PID1_t(void *p) {
      delete [] ((::PID1_t*)p);
   }
   static void destruct_PID1_t(void *p) {
      typedef ::PID1_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PID1_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PID2_t(void *p) {
      return  p ? new(p) ::PID2_t : new ::PID2_t;
   }
   static void *newArray_PID2_t(Long_t nElements, void *p) {
      return p ? new(p) ::PID2_t[nElements] : new ::PID2_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PID2_t(void *p) {
      delete ((::PID2_t*)p);
   }
   static void deleteArray_PID2_t(void *p) {
      delete [] ((::PID2_t*)p);
   }
   static void destruct_PID2_t(void *p) {
      typedef ::PID2_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PID2_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PID3_t(void *p) {
      return  p ? new(p) ::PID3_t : new ::PID3_t;
   }
   static void *newArray_PID3_t(Long_t nElements, void *p) {
      return p ? new(p) ::PID3_t[nElements] : new ::PID3_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PID3_t(void *p) {
      delete ((::PID3_t*)p);
   }
   static void deleteArray_PID3_t(void *p) {
      delete [] ((::PID3_t*)p);
   }
   static void destruct_PID3_t(void *p) {
      typedef ::PID3_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PID3_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PID4_t(void *p) {
      return  p ? new(p) ::PID4_t : new ::PID4_t;
   }
   static void *newArray_PID4_t(Long_t nElements, void *p) {
      return p ? new(p) ::PID4_t[nElements] : new ::PID4_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PID4_t(void *p) {
      delete ((::PID4_t*)p);
   }
   static void deleteArray_PID4_t(void *p) {
      delete [] ((::PID4_t*)p);
   }
   static void destruct_PID4_t(void *p) {
      typedef ::PID4_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PID4_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PID5_t(void *p) {
      return  p ? new(p) ::PID5_t : new ::PID5_t;
   }
   static void *newArray_PID5_t(Long_t nElements, void *p) {
      return p ? new(p) ::PID5_t[nElements] : new ::PID5_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PID5_t(void *p) {
      delete ((::PID5_t*)p);
   }
   static void deleteArray_PID5_t(void *p) {
      delete [] ((::PID5_t*)p);
   }
   static void destruct_PID5_t(void *p) {
      typedef ::PID5_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PID5_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PID6_t(void *p) {
      return  p ? new(p) ::PID6_t : new ::PID6_t;
   }
   static void *newArray_PID6_t(Long_t nElements, void *p) {
      return p ? new(p) ::PID6_t[nElements] : new ::PID6_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PID6_t(void *p) {
      delete ((::PID6_t*)p);
   }
   static void deleteArray_PID6_t(void *p) {
      delete [] ((::PID6_t*)p);
   }
   static void destruct_PID6_t(void *p) {
      typedef ::PID6_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PID6_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PIDT_t(void *p) {
      return  p ? new(p) ::PIDT_t : new ::PIDT_t;
   }
   static void *newArray_PIDT_t(Long_t nElements, void *p) {
      return p ? new(p) ::PIDT_t[nElements] : new ::PIDT_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PIDT_t(void *p) {
      delete ((::PIDT_t*)p);
   }
   static void deleteArray_PIDT_t(void *p) {
      delete [] ((::PIDT_t*)p);
   }
   static void destruct_PIDT_t(void *p) {
      typedef ::PIDT_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PIDT_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PRTM_t(void *p) {
      return  p ? new(p) ::PRTM_t : new ::PRTM_t;
   }
   static void *newArray_PRTM_t(Long_t nElements, void *p) {
      return p ? new(p) ::PRTM_t[nElements] : new ::PRTM_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PRTM_t(void *p) {
      delete ((::PRTM_t*)p);
   }
   static void deleteArray_PRTM_t(void *p) {
      delete [] ((::PRTM_t*)p);
   }
   static void destruct_PRTM_t(void *p) {
      typedef ::PRTM_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PRTM_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PSO_t(void *p) {
      return  p ? new(p) ::PSO_t : new ::PSO_t;
   }
   static void *newArray_PSO_t(Long_t nElements, void *p) {
      return p ? new(p) ::PSO_t[nElements] : new ::PSO_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PSO_t(void *p) {
      delete ((::PSO_t*)p);
   }
   static void deleteArray_PSO_t(void *p) {
      delete [] ((::PSO_t*)p);
   }
   static void destruct_PSO_t(void *p) {
      typedef ::PSO_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PSO_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_PTDB_t(void *p) {
      return  p ? new(p) ::PTDB_t : new ::PTDB_t;
   }
   static void *newArray_PTDB_t(Long_t nElements, void *p) {
      return p ? new(p) ::PTDB_t[nElements] : new ::PTDB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_PTDB_t(void *p) {
      delete ((::PTDB_t*)p);
   }
   static void deleteArray_PTDB_t(void *p) {
      delete [] ((::PTDB_t*)p);
   }
   static void destruct_PTDB_t(void *p) {
      typedef ::PTDB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::PTDB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_RCST_t(void *p) {
      return  p ? new(p) ::RCST_t : new ::RCST_t;
   }
   static void *newArray_RCST_t(Long_t nElements, void *p) {
      return p ? new(p) ::RCST_t[nElements] : new ::RCST_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_RCST_t(void *p) {
      delete ((::RCST_t*)p);
   }
   static void deleteArray_RCST_t(void *p) {
      delete [] ((::RCST_t*)p);
   }
   static void destruct_RCST_t(void *p) {
      typedef ::RCST_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RCST_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_RF_t(void *p) {
      return  p ? new(p) ::RF_t : new ::RF_t;
   }
   static void *newArray_RF_t(Long_t nElements, void *p) {
      return p ? new(p) ::RF_t[nElements] : new ::RF_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_RF_t(void *p) {
      delete ((::RF_t*)p);
   }
   static void deleteArray_RF_t(void *p) {
      delete [] ((::RF_t*)p);
   }
   static void destruct_RF_t(void *p) {
      typedef ::RF_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RF_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_RGLK_t(void *p) {
      return  p ? new(p) ::RGLK_t : new ::RGLK_t;
   }
   static void *newArray_RGLK_t(Long_t nElements, void *p) {
      return p ? new(p) ::RGLK_t[nElements] : new ::RGLK_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_RGLK_t(void *p) {
      delete ((::RGLK_t*)p);
   }
   static void deleteArray_RGLK_t(void *p) {
      delete [] ((::RGLK_t*)p);
   }
   static void destruct_RGLK_t(void *p) {
      typedef ::RGLK_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RGLK_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_RNLG_t(void *p) {
      return  p ? new(p) ::RNLG_t : new ::RNLG_t;
   }
   static void *newArray_RNLG_t(Long_t nElements, void *p) {
      return p ? new(p) ::RNLG_t[nElements] : new ::RNLG_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_RNLG_t(void *p) {
      delete ((::RNLG_t*)p);
   }
   static void deleteArray_RNLG_t(void *p) {
      delete [] ((::RNLG_t*)p);
   }
   static void destruct_RNLG_t(void *p) {
      typedef ::RNLG_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RNLG_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_RNPE_t(void *p) {
      return  p ? new(p) ::RNPE_t : new ::RNPE_t;
   }
   static void *newArray_RNPE_t(Long_t nElements, void *p) {
      return p ? new(p) ::RNPE_t[nElements] : new ::RNPE_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_RNPE_t(void *p) {
      delete ((::RNPE_t*)p);
   }
   static void deleteArray_RNPE_t(void *p) {
      delete [] ((::RNPE_t*)p);
   }
   static void destruct_RNPE_t(void *p) {
      typedef ::RNPE_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RNPE_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_RTSL_t(void *p) {
      return  p ? new(p) ::RTSL_t : new ::RTSL_t;
   }
   static void *newArray_RTSL_t(Long_t nElements, void *p) {
      return p ? new(p) ::RTSL_t[nElements] : new ::RTSL_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_RTSL_t(void *p) {
      delete ((::RTSL_t*)p);
   }
   static void deleteArray_RTSL_t(void *p) {
      delete [] ((::RTSL_t*)p);
   }
   static void destruct_RTSL_t(void *p) {
      typedef ::RTSL_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RTSL_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_RUNC_t(void *p) {
      return  p ? new(p) ::RUNC_t : new ::RUNC_t;
   }
   static void *newArray_RUNC_t(Long_t nElements, void *p) {
      return p ? new(p) ::RUNC_t[nElements] : new ::RUNC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_RUNC_t(void *p) {
      delete ((::RUNC_t*)p);
   }
   static void deleteArray_RUNC_t(void *p) {
      delete [] ((::RUNC_t*)p);
   }
   static void destruct_RUNC_t(void *p) {
      typedef ::RUNC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::RUNC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_S1ST_t(void *p) {
      return  p ? new(p) ::S1ST_t : new ::S1ST_t;
   }
   static void *newArray_S1ST_t(Long_t nElements, void *p) {
      return p ? new(p) ::S1ST_t[nElements] : new ::S1ST_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_S1ST_t(void *p) {
      delete ((::S1ST_t*)p);
   }
   static void deleteArray_S1ST_t(void *p) {
      delete [] ((::S1ST_t*)p);
   }
   static void destruct_S1ST_t(void *p) {
      typedef ::S1ST_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::S1ST_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SC1_t(void *p) {
      return  p ? new(p) ::SC1_t : new ::SC1_t;
   }
   static void *newArray_SC1_t(Long_t nElements, void *p) {
      return p ? new(p) ::SC1_t[nElements] : new ::SC1_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SC1_t(void *p) {
      delete ((::SC1_t*)p);
   }
   static void deleteArray_SC1_t(void *p) {
      delete [] ((::SC1_t*)p);
   }
   static void destruct_SC1_t(void *p) {
      typedef ::SC1_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SC1_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCC_t(void *p) {
      return  p ? new(p) ::SCC_t : new ::SCC_t;
   }
   static void *newArray_SCC_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCC_t[nElements] : new ::SCC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCC_t(void *p) {
      delete ((::SCC_t*)p);
   }
   static void deleteArray_SCC_t(void *p) {
      delete [] ((::SCC_t*)p);
   }
   static void destruct_SCC_t(void *p) {
      typedef ::SCC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SC_t(void *p) {
      return  p ? new(p) ::SC_t : new ::SC_t;
   }
   static void *newArray_SC_t(Long_t nElements, void *p) {
      return p ? new(p) ::SC_t[nElements] : new ::SC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SC_t(void *p) {
      delete ((::SC_t*)p);
   }
   static void deleteArray_SC_t(void *p) {
      delete [] ((::SC_t*)p);
   }
   static void destruct_SC_t(void *p) {
      typedef ::SC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCDI_t(void *p) {
      return  p ? new(p) ::SCDI_t : new ::SCDI_t;
   }
   static void *newArray_SCDI_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCDI_t[nElements] : new ::SCDI_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCDI_t(void *p) {
      delete ((::SCDI_t*)p);
   }
   static void deleteArray_SCDI_t(void *p) {
      delete [] ((::SCDI_t*)p);
   }
   static void destruct_SCDI_t(void *p) {
      typedef ::SCDI_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCDI_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCGD_t(void *p) {
      return  p ? new(p) ::SCGD_t : new ::SCGD_t;
   }
   static void *newArray_SCGD_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCGD_t[nElements] : new ::SCGD_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCGD_t(void *p) {
      delete ((::SCGD_t*)p);
   }
   static void deleteArray_SCGD_t(void *p) {
      delete [] ((::SCGD_t*)p);
   }
   static void destruct_SCGD_t(void *p) {
      typedef ::SCGD_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCGD_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCG_t(void *p) {
      return  p ? new(p) ::SCG_t : new ::SCG_t;
   }
   static void *newArray_SCG_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCG_t[nElements] : new ::SCG_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCG_t(void *p) {
      delete ((::SCG_t*)p);
   }
   static void deleteArray_SCG_t(void *p) {
      delete [] ((::SCG_t*)p);
   }
   static void destruct_SCG_t(void *p) {
      typedef ::SCG_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCG_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCH_t(void *p) {
      return  p ? new(p) ::SCH_t : new ::SCH_t;
   }
   static void *newArray_SCH_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCH_t[nElements] : new ::SCH_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCH_t(void *p) {
      delete ((::SCH_t*)p);
   }
   static void deleteArray_SCH_t(void *p) {
      delete [] ((::SCH_t*)p);
   }
   static void destruct_SCH_t(void *p) {
      typedef ::SCH_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCH_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCMD_t(void *p) {
      return  p ? new(p) ::SCMD_t : new ::SCMD_t;
   }
   static void *newArray_SCMD_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCMD_t[nElements] : new ::SCMD_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCMD_t(void *p) {
      delete ((::SCMD_t*)p);
   }
   static void deleteArray_SCMD_t(void *p) {
      delete [] ((::SCMD_t*)p);
   }
   static void destruct_SCMD_t(void *p) {
      typedef ::SCMD_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCMD_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCMT_t(void *p) {
      return  p ? new(p) ::SCMT_t : new ::SCMT_t;
   }
   static void *newArray_SCMT_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCMT_t[nElements] : new ::SCMT_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCMT_t(void *p) {
      delete ((::SCMT_t*)p);
   }
   static void deleteArray_SCMT_t(void *p) {
      delete [] ((::SCMT_t*)p);
   }
   static void destruct_SCMT_t(void *p) {
      typedef ::SCMT_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCMT_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCMW_t(void *p) {
      return  p ? new(p) ::SCMW_t : new ::SCMW_t;
   }
   static void *newArray_SCMW_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCMW_t[nElements] : new ::SCMW_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCMW_t(void *p) {
      delete ((::SCMW_t*)p);
   }
   static void deleteArray_SCMW_t(void *p) {
      delete [] ((::SCMW_t*)p);
   }
   static void destruct_SCMW_t(void *p) {
      typedef ::SCMW_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCMW_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCPB_t(void *p) {
      return  p ? new(p) ::SCPB_t : new ::SCPB_t;
   }
   static void *newArray_SCPB_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCPB_t[nElements] : new ::SCPB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCPB_t(void *p) {
      delete ((::SCPB_t*)p);
   }
   static void deleteArray_SCPB_t(void *p) {
      delete [] ((::SCPB_t*)p);
   }
   static void destruct_SCPB_t(void *p) {
      typedef ::SCPB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCPB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCP_t(void *p) {
      return  p ? new(p) ::SCP_t : new ::SCP_t;
   }
   static void *newArray_SCP_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCP_t[nElements] : new ::SCP_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCP_t(void *p) {
      delete ((::SCP_t*)p);
   }
   static void deleteArray_SCP_t(void *p) {
      delete [] ((::SCP_t*)p);
   }
   static void destruct_SCP_t(void *p) {
      typedef ::SCP_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCP_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCPE_t(void *p) {
      return  p ? new(p) ::SCPE_t : new ::SCPE_t;
   }
   static void *newArray_SCPE_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCPE_t[nElements] : new ::SCPE_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCPE_t(void *p) {
      delete ((::SCPE_t*)p);
   }
   static void deleteArray_SCPE_t(void *p) {
      delete [] ((::SCPE_t*)p);
   }
   static void destruct_SCPE_t(void *p) {
      typedef ::SCPE_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCPE_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCPS_t(void *p) {
      return  p ? new(p) ::SCPS_t : new ::SCPS_t;
   }
   static void *newArray_SCPS_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCPS_t[nElements] : new ::SCPS_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCPS_t(void *p) {
      delete ((::SCPS_t*)p);
   }
   static void deleteArray_SCPS_t(void *p) {
      delete [] ((::SCPS_t*)p);
   }
   static void destruct_SCPS_t(void *p) {
      typedef ::SCPS_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCPS_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCRC_t(void *p) {
      return  p ? new(p) ::SCRC_t : new ::SCRC_t;
   }
   static void *newArray_SCRC_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCRC_t[nElements] : new ::SCRC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCRC_t(void *p) {
      delete ((::SCRC_t*)p);
   }
   static void deleteArray_SCRC_t(void *p) {
      delete [] ((::SCRC_t*)p);
   }
   static void destruct_SCRC_t(void *p) {
      typedef ::SCRC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCRC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCR_t(void *p) {
      return  p ? new(p) ::SCR_t : new ::SCR_t;
   }
   static void *newArray_SCR_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCR_t[nElements] : new ::SCR_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCR_t(void *p) {
      delete ((::SCR_t*)p);
   }
   static void deleteArray_SCR_t(void *p) {
      delete [] ((::SCR_t*)p);
   }
   static void destruct_SCR_t(void *p) {
      typedef ::SCR_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCR_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SCS_t(void *p) {
      return  p ? new(p) ::SCS_t : new ::SCS_t;
   }
   static void *newArray_SCS_t(Long_t nElements, void *p) {
      return p ? new(p) ::SCS_t[nElements] : new ::SCS_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SCS_t(void *p) {
      delete ((::SCS_t*)p);
   }
   static void deleteArray_SCS_t(void *p) {
      delete [] ((::SCS_t*)p);
   }
   static void destruct_SCS_t(void *p) {
      typedef ::SCS_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SCS_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SGMP_t(void *p) {
      return  p ? new(p) ::SGMP_t : new ::SGMP_t;
   }
   static void *newArray_SGMP_t(Long_t nElements, void *p) {
      return p ? new(p) ::SGMP_t[nElements] : new ::SGMP_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SGMP_t(void *p) {
      delete ((::SGMP_t*)p);
   }
   static void deleteArray_SGMP_t(void *p) {
      delete [] ((::SGMP_t*)p);
   }
   static void destruct_SGMP_t(void *p) {
      typedef ::SGMP_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SGMP_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SPAR_t(void *p) {
      return  p ? new(p) ::SPAR_t : new ::SPAR_t;
   }
   static void *newArray_SPAR_t(Long_t nElements, void *p) {
      return p ? new(p) ::SPAR_t[nElements] : new ::SPAR_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SPAR_t(void *p) {
      delete ((::SPAR_t*)p);
   }
   static void deleteArray_SPAR_t(void *p) {
      delete [] ((::SPAR_t*)p);
   }
   static void destruct_SPAR_t(void *p) {
      typedef ::SPAR_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SPAR_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SPIN_t(void *p) {
      return  p ? new(p) ::SPIN_t : new ::SPIN_t;
   }
   static void *newArray_SPIN_t(Long_t nElements, void *p) {
      return p ? new(p) ::SPIN_t[nElements] : new ::SPIN_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SPIN_t(void *p) {
      delete ((::SPIN_t*)p);
   }
   static void deleteArray_SPIN_t(void *p) {
      delete [] ((::SPIN_t*)p);
   }
   static void destruct_SPIN_t(void *p) {
      typedef ::SPIN_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SPIN_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ST1_t(void *p) {
      return  p ? new(p) ::ST1_t : new ::ST1_t;
   }
   static void *newArray_ST1_t(Long_t nElements, void *p) {
      return p ? new(p) ::ST1_t[nElements] : new ::ST1_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ST1_t(void *p) {
      delete ((::ST1_t*)p);
   }
   static void deleteArray_ST1_t(void *p) {
      delete [] ((::ST1_t*)p);
   }
   static void destruct_ST1_t(void *p) {
      typedef ::ST1_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ST1_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_ST_t(void *p) {
      return  p ? new(p) ::ST_t : new ::ST_t;
   }
   static void *newArray_ST_t(Long_t nElements, void *p) {
      return p ? new(p) ::ST_t[nElements] : new ::ST_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_ST_t(void *p) {
      delete ((::ST_t*)p);
   }
   static void deleteArray_ST_t(void *p) {
      delete [] ((::ST_t*)p);
   }
   static void destruct_ST_t(void *p) {
      typedef ::ST_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::ST_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_STG_t(void *p) {
      return  p ? new(p) ::STG_t : new ::STG_t;
   }
   static void *newArray_STG_t(Long_t nElements, void *p) {
      return p ? new(p) ::STG_t[nElements] : new ::STG_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_STG_t(void *p) {
      delete ((::STG_t*)p);
   }
   static void deleteArray_STG_t(void *p) {
      delete [] ((::STG_t*)p);
   }
   static void destruct_STG_t(void *p) {
      typedef ::STG_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::STG_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_STH_t(void *p) {
      return  p ? new(p) ::STH_t : new ::STH_t;
   }
   static void *newArray_STH_t(Long_t nElements, void *p) {
      return p ? new(p) ::STH_t[nElements] : new ::STH_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_STH_t(void *p) {
      delete ((::STH_t*)p);
   }
   static void deleteArray_STH_t(void *p) {
      delete [] ((::STH_t*)p);
   }
   static void destruct_STH_t(void *p) {
      typedef ::STH_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::STH_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_STN0_t(void *p) {
      return  p ? new(p) ::STN0_t : new ::STN0_t;
   }
   static void *newArray_STN0_t(Long_t nElements, void *p) {
      return p ? new(p) ::STN0_t[nElements] : new ::STN0_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_STN0_t(void *p) {
      delete ((::STN0_t*)p);
   }
   static void deleteArray_STN0_t(void *p) {
      delete [] ((::STN0_t*)p);
   }
   static void destruct_STN0_t(void *p) {
      typedef ::STN0_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::STN0_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_STN1_t(void *p) {
      return  p ? new(p) ::STN1_t : new ::STN1_t;
   }
   static void *newArray_STN1_t(Long_t nElements, void *p) {
      return p ? new(p) ::STN1_t[nElements] : new ::STN1_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_STN1_t(void *p) {
      delete ((::STN1_t*)p);
   }
   static void deleteArray_STN1_t(void *p) {
      delete [] ((::STN1_t*)p);
   }
   static void destruct_STN1_t(void *p) {
      typedef ::STN1_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::STN1_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_STPB_t(void *p) {
      return  p ? new(p) ::STPB_t : new ::STPB_t;
   }
   static void *newArray_STPB_t(Long_t nElements, void *p) {
      return p ? new(p) ::STPB_t[nElements] : new ::STPB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_STPB_t(void *p) {
      delete ((::STPB_t*)p);
   }
   static void deleteArray_STPB_t(void *p) {
      delete [] ((::STPB_t*)p);
   }
   static void destruct_STPB_t(void *p) {
      typedef ::STPB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::STPB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_STPE_t(void *p) {
      return  p ? new(p) ::STPE_t : new ::STPE_t;
   }
   static void *newArray_STPE_t(Long_t nElements, void *p) {
      return p ? new(p) ::STPE_t[nElements] : new ::STPE_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_STPE_t(void *p) {
      delete ((::STPE_t*)p);
   }
   static void deleteArray_STPE_t(void *p) {
      delete [] ((::STPE_t*)p);
   }
   static void destruct_STPE_t(void *p) {
      typedef ::STPE_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::STPE_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_STR_t(void *p) {
      return  p ? new(p) ::STR_t : new ::STR_t;
   }
   static void *newArray_STR_t(Long_t nElements, void *p) {
      return p ? new(p) ::STR_t[nElements] : new ::STR_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_STR_t(void *p) {
      delete ((::STR_t*)p);
   }
   static void deleteArray_STR_t(void *p) {
      delete [] ((::STR_t*)p);
   }
   static void destruct_STR_t(void *p) {
      typedef ::STR_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::STR_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_STS_t(void *p) {
      return  p ? new(p) ::STS_t : new ::STS_t;
   }
   static void *newArray_STS_t(Long_t nElements, void *p) {
      return p ? new(p) ::STS_t[nElements] : new ::STS_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_STS_t(void *p) {
      delete ((::STS_t*)p);
   }
   static void deleteArray_STS_t(void *p) {
      delete [] ((::STS_t*)p);
   }
   static void destruct_STS_t(void *p) {
      typedef ::STS_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::STS_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_SYNC_t(void *p) {
      return  p ? new(p) ::SYNC_t : new ::SYNC_t;
   }
   static void *newArray_SYNC_t(Long_t nElements, void *p) {
      return p ? new(p) ::SYNC_t[nElements] : new ::SYNC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_SYNC_t(void *p) {
      delete ((::SYNC_t*)p);
   }
   static void deleteArray_SYNC_t(void *p) {
      delete [] ((::SYNC_t*)p);
   }
   static void destruct_SYNC_t(void *p) {
      typedef ::SYNC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::SYNC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TACO_t(void *p) {
      return  p ? new(p) ::TACO_t : new ::TACO_t;
   }
   static void *newArray_TACO_t(Long_t nElements, void *p) {
      return p ? new(p) ::TACO_t[nElements] : new ::TACO_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TACO_t(void *p) {
      delete ((::TACO_t*)p);
   }
   static void deleteArray_TACO_t(void *p) {
      delete [] ((::TACO_t*)p);
   }
   static void destruct_TACO_t(void *p) {
      typedef ::TACO_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TACO_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TAGE_t(void *p) {
      return  p ? new(p) ::TAGE_t : new ::TAGE_t;
   }
   static void *newArray_TAGE_t(Long_t nElements, void *p) {
      return p ? new(p) ::TAGE_t[nElements] : new ::TAGE_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TAGE_t(void *p) {
      delete ((::TAGE_t*)p);
   }
   static void deleteArray_TAGE_t(void *p) {
      delete [] ((::TAGE_t*)p);
   }
   static void destruct_TAGE_t(void *p) {
      typedef ::TAGE_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TAGE_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TAGI_t(void *p) {
      return  p ? new(p) ::TAGI_t : new ::TAGI_t;
   }
   static void *newArray_TAGI_t(Long_t nElements, void *p) {
      return p ? new(p) ::TAGI_t[nElements] : new ::TAGI_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TAGI_t(void *p) {
      delete ((::TAGI_t*)p);
   }
   static void deleteArray_TAGI_t(void *p) {
      delete [] ((::TAGI_t*)p);
   }
   static void destruct_TAGI_t(void *p) {
      typedef ::TAGI_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TAGI_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TAGM_t(void *p) {
      return  p ? new(p) ::TAGM_t : new ::TAGM_t;
   }
   static void *newArray_TAGM_t(Long_t nElements, void *p) {
      return p ? new(p) ::TAGM_t[nElements] : new ::TAGM_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TAGM_t(void *p) {
      delete ((::TAGM_t*)p);
   }
   static void deleteArray_TAGM_t(void *p) {
      delete [] ((::TAGM_t*)p);
   }
   static void destruct_TAGM_t(void *p) {
      typedef ::TAGM_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TAGM_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TAGR_t(void *p) {
      return  p ? new(p) ::TAGR_t : new ::TAGR_t;
   }
   static void *newArray_TAGR_t(Long_t nElements, void *p) {
      return p ? new(p) ::TAGR_t[nElements] : new ::TAGR_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TAGR_t(void *p) {
      delete ((::TAGR_t*)p);
   }
   static void deleteArray_TAGR_t(void *p) {
      delete [] ((::TAGR_t*)p);
   }
   static void destruct_TAGR_t(void *p) {
      typedef ::TAGR_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TAGR_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TAGT_t(void *p) {
      return  p ? new(p) ::TAGT_t : new ::TAGT_t;
   }
   static void *newArray_TAGT_t(Long_t nElements, void *p) {
      return p ? new(p) ::TAGT_t[nElements] : new ::TAGT_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TAGT_t(void *p) {
      delete ((::TAGT_t*)p);
   }
   static void deleteArray_TAGT_t(void *p) {
      delete [] ((::TAGT_t*)p);
   }
   static void destruct_TAGT_t(void *p) {
      typedef ::TAGT_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TAGT_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TBER_t(void *p) {
      return  p ? new(p) ::TBER_t : new ::TBER_t;
   }
   static void *newArray_TBER_t(Long_t nElements, void *p) {
      return p ? new(p) ::TBER_t[nElements] : new ::TBER_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TBER_t(void *p) {
      delete ((::TBER_t*)p);
   }
   static void deleteArray_TBER_t(void *p) {
      delete [] ((::TBER_t*)p);
   }
   static void destruct_TBER_t(void *p) {
      typedef ::TBER_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TBER_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TBID_t(void *p) {
      return  p ? new(p) ::TBID_t : new ::TBID_t;
   }
   static void *newArray_TBID_t(Long_t nElements, void *p) {
      return p ? new(p) ::TBID_t[nElements] : new ::TBID_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TBID_t(void *p) {
      delete ((::TBID_t*)p);
   }
   static void deleteArray_TBID_t(void *p) {
      delete [] ((::TBID_t*)p);
   }
   static void destruct_TBID_t(void *p) {
      typedef ::TBID_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TBID_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TBLA_t(void *p) {
      return  p ? new(p) ::TBLA_t : new ::TBLA_t;
   }
   static void *newArray_TBLA_t(Long_t nElements, void *p) {
      return p ? new(p) ::TBLA_t[nElements] : new ::TBLA_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TBLA_t(void *p) {
      delete ((::TBLA_t*)p);
   }
   static void deleteArray_TBLA_t(void *p) {
      delete [] ((::TBLA_t*)p);
   }
   static void destruct_TBLA_t(void *p) {
      typedef ::TBLA_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TBLA_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TBTR_t(void *p) {
      return  p ? new(p) ::TBTR_t : new ::TBTR_t;
   }
   static void *newArray_TBTR_t(Long_t nElements, void *p) {
      return p ? new(p) ::TBTR_t[nElements] : new ::TBTR_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TBTR_t(void *p) {
      delete ((::TBTR_t*)p);
   }
   static void deleteArray_TBTR_t(void *p) {
      delete [] ((::TBTR_t*)p);
   }
   static void destruct_TBTR_t(void *p) {
      typedef ::TBTR_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TBTR_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TCSB_t(void *p) {
      return  p ? new(p) ::TCSB_t : new ::TCSB_t;
   }
   static void *newArray_TCSB_t(Long_t nElements, void *p) {
      return p ? new(p) ::TCSB_t[nElements] : new ::TCSB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TCSB_t(void *p) {
      delete ((::TCSB_t*)p);
   }
   static void deleteArray_TCSB_t(void *p) {
      delete [] ((::TCSB_t*)p);
   }
   static void destruct_TCSB_t(void *p) {
      typedef ::TCSB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TCSB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TDPL_t(void *p) {
      return  p ? new(p) ::TDPL_t : new ::TDPL_t;
   }
   static void *newArray_TDPL_t(Long_t nElements, void *p) {
      return p ? new(p) ::TDPL_t[nElements] : new ::TDPL_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TDPL_t(void *p) {
      delete ((::TDPL_t*)p);
   }
   static void deleteArray_TDPL_t(void *p) {
      delete [] ((::TDPL_t*)p);
   }
   static void destruct_TDPL_t(void *p) {
      typedef ::TDPL_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TDPL_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TESC_t(void *p) {
      return  p ? new(p) ::TESC_t : new ::TESC_t;
   }
   static void *newArray_TESC_t(Long_t nElements, void *p) {
      return p ? new(p) ::TESC_t[nElements] : new ::TESC_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TESC_t(void *p) {
      delete ((::TESC_t*)p);
   }
   static void deleteArray_TESC_t(void *p) {
      delete [] ((::TESC_t*)p);
   }
   static void destruct_TESC_t(void *p) {
      typedef ::TESC_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TESC_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TGBI_t(void *p) {
      return  p ? new(p) ::TGBI_t : new ::TGBI_t;
   }
   static void *newArray_TGBI_t(Long_t nElements, void *p) {
      return p ? new(p) ::TGBI_t[nElements] : new ::TGBI_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TGBI_t(void *p) {
      delete ((::TGBI_t*)p);
   }
   static void deleteArray_TGBI_t(void *p) {
      delete [] ((::TGBI_t*)p);
   }
   static void destruct_TGBI_t(void *p) {
      typedef ::TGBI_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TGBI_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TGEO_t(void *p) {
      return  p ? new(p) ::TGEO_t : new ::TGEO_t;
   }
   static void *newArray_TGEO_t(Long_t nElements, void *p) {
      return p ? new(p) ::TGEO_t[nElements] : new ::TGEO_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TGEO_t(void *p) {
      delete ((::TGEO_t*)p);
   }
   static void deleteArray_TGEO_t(void *p) {
      delete [] ((::TGEO_t*)p);
   }
   static void destruct_TGEO_t(void *p) {
      typedef ::TGEO_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TGEO_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TGPB_t(void *p) {
      return  p ? new(p) ::TGPB_t : new ::TGPB_t;
   }
   static void *newArray_TGPB_t(Long_t nElements, void *p) {
      return p ? new(p) ::TGPB_t[nElements] : new ::TGPB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TGPB_t(void *p) {
      delete ((::TGPB_t*)p);
   }
   static void deleteArray_TGPB_t(void *p) {
      delete [] ((::TGPB_t*)p);
   }
   static void destruct_TGPB_t(void *p) {
      typedef ::TGPB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TGPB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TGS_t(void *p) {
      return  p ? new(p) ::TGS_t : new ::TGS_t;
   }
   static void *newArray_TGS_t(Long_t nElements, void *p) {
      return p ? new(p) ::TGS_t[nElements] : new ::TGS_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TGS_t(void *p) {
      delete ((::TGS_t*)p);
   }
   static void deleteArray_TGS_t(void *p) {
      delete [] ((::TGS_t*)p);
   }
   static void destruct_TGS_t(void *p) {
      typedef ::TGS_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TGS_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TLV1_t(void *p) {
      return  p ? new(p) ::TLV1_t : new ::TLV1_t;
   }
   static void *newArray_TLV1_t(Long_t nElements, void *p) {
      return p ? new(p) ::TLV1_t[nElements] : new ::TLV1_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TLV1_t(void *p) {
      delete ((::TLV1_t*)p);
   }
   static void deleteArray_TLV1_t(void *p) {
      delete [] ((::TLV1_t*)p);
   }
   static void destruct_TLV1_t(void *p) {
      typedef ::TLV1_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TLV1_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRCF_t(void *p) {
      return  p ? new(p) ::TRCF_t : new ::TRCF_t;
   }
   static void *newArray_TRCF_t(Long_t nElements, void *p) {
      return p ? new(p) ::TRCF_t[nElements] : new ::TRCF_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRCF_t(void *p) {
      delete ((::TRCF_t*)p);
   }
   static void deleteArray_TRCF_t(void *p) {
      delete [] ((::TRCF_t*)p);
   }
   static void destruct_TRCF_t(void *p) {
      typedef ::TRCF_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TRCF_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRGS_t(void *p) {
      return  p ? new(p) ::TRGS_t : new ::TRGS_t;
   }
   static void *newArray_TRGS_t(Long_t nElements, void *p) {
      return p ? new(p) ::TRGS_t[nElements] : new ::TRGS_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRGS_t(void *p) {
      delete ((::TRGS_t*)p);
   }
   static void deleteArray_TRGS_t(void *p) {
      delete [] ((::TRGS_t*)p);
   }
   static void destruct_TRGS_t(void *p) {
      typedef ::TRGS_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TRGS_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRKS_t(void *p) {
      return  p ? new(p) ::TRKS_t : new ::TRKS_t;
   }
   static void *newArray_TRKS_t(Long_t nElements, void *p) {
      return p ? new(p) ::TRKS_t[nElements] : new ::TRKS_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRKS_t(void *p) {
      delete ((::TRKS_t*)p);
   }
   static void deleteArray_TRKS_t(void *p) {
      delete [] ((::TRKS_t*)p);
   }
   static void destruct_TRKS_t(void *p) {
      typedef ::TRKS_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TRKS_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRL1_t(void *p) {
      return  p ? new(p) ::TRL1_t : new ::TRL1_t;
   }
   static void *newArray_TRL1_t(Long_t nElements, void *p) {
      return p ? new(p) ::TRL1_t[nElements] : new ::TRL1_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRL1_t(void *p) {
      delete ((::TRL1_t*)p);
   }
   static void deleteArray_TRL1_t(void *p) {
      delete [] ((::TRL1_t*)p);
   }
   static void destruct_TRL1_t(void *p) {
      typedef ::TRL1_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TRL1_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TRPB_t(void *p) {
      return  p ? new(p) ::TRPB_t : new ::TRPB_t;
   }
   static void *newArray_TRPB_t(Long_t nElements, void *p) {
      return p ? new(p) ::TRPB_t[nElements] : new ::TRPB_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TRPB_t(void *p) {
      delete ((::TRPB_t*)p);
   }
   static void deleteArray_TRPB_t(void *p) {
      delete [] ((::TRPB_t*)p);
   }
   static void destruct_TRPB_t(void *p) {
      typedef ::TRPB_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TRPB_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TSPR_t(void *p) {
      return  p ? new(p) ::TSPR_t : new ::TSPR_t;
   }
   static void *newArray_TSPR_t(Long_t nElements, void *p) {
      return p ? new(p) ::TSPR_t[nElements] : new ::TSPR_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TSPR_t(void *p) {
      delete ((::TSPR_t*)p);
   }
   static void deleteArray_TSPR_t(void *p) {
      delete [] ((::TSPR_t*)p);
   }
   static void destruct_TSPR_t(void *p) {
      typedef ::TSPR_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TSPR_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_TSRG_t(void *p) {
      return  p ? new(p) ::TSRG_t : new ::TSRG_t;
   }
   static void *newArray_TSRG_t(Long_t nElements, void *p) {
      return p ? new(p) ::TSRG_t[nElements] : new ::TSRG_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_TSRG_t(void *p) {
      delete ((::TSRG_t*)p);
   }
   static void deleteArray_TSRG_t(void *p) {
      delete [] ((::TSRG_t*)p);
   }
   static void destruct_TSRG_t(void *p) {
      typedef ::TSRG_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::TSRG_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_UNUS_t(void *p) {
      return  p ? new(p) ::UNUS_t : new ::UNUS_t;
   }
   static void *newArray_UNUS_t(Long_t nElements, void *p) {
      return p ? new(p) ::UNUS_t[nElements] : new ::UNUS_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_UNUS_t(void *p) {
      delete ((::UNUS_t*)p);
   }
   static void deleteArray_UNUS_t(void *p) {
      delete [] ((::UNUS_t*)p);
   }
   static void destruct_UNUS_t(void *p) {
      typedef ::UNUS_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::UNUS_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_VERT_t(void *p) {
      return  p ? new(p) ::VERT_t : new ::VERT_t;
   }
   static void *newArray_VERT_t(Long_t nElements, void *p) {
      return p ? new(p) ::VERT_t[nElements] : new ::VERT_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_VERT_t(void *p) {
      delete ((::VERT_t*)p);
   }
   static void deleteArray_VERT_t(void *p) {
      delete [] ((::VERT_t*)p);
   }
   static void destruct_VERT_t(void *p) {
      typedef ::VERT_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::VERT_t

namespace ROOT {
   // Wrappers around operator new
   static void *new_addressBanks_t(void *p) {
      return  p ? new(p) ::addressBanks_t : new ::addressBanks_t;
   }
   static void *newArray_addressBanks_t(Long_t nElements, void *p) {
      return p ? new(p) ::addressBanks_t[nElements] : new ::addressBanks_t[nElements];
   }
   // Wrapper around operator delete
   static void delete_addressBanks_t(void *p) {
      delete ((::addressBanks_t*)p);
   }
   static void deleteArray_addressBanks_t(void *p) {
      delete [] ((::addressBanks_t*)p);
   }
   static void destruct_addressBanks_t(void *p) {
      typedef ::addressBanks_t current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::addressBanks_t

namespace {
  void TriggerDictionaryInitialization_bankvarsDict_Impl() {
    static const char* headers[] = {
"include/bankvars.h",
0
    };
    static const char* includePaths[] = {
"/mnt/share/cern_CentOS7/root/v6.14.04/include",
"/home/dglazier/Dropbox/HaSpect/dev/HASPECT6/ExtraPackages/RootBeerLite/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "bankvarsDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  BEAM_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  BMPR_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  BREP_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CALB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CALL_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CC01_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CC1_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CCDI_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CCH_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CCMT_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CCPB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CCPE_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CCRC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CCS_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CHI2_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CL01_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CLST_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CPED_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  CSQL_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DC0_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DC1_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DCDW_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DCGM_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DCGW_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DCH_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DCMN_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DCPB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DCV1_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DCV2_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DCV3_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DDLY_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DGEO_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DHCL_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DITM_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DOCA_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DPCP_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DPSP_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DSPC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DSPS_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DSTC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DTCP_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  DTRK_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  EC01_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  EC1_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  EC1P_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  EC1R_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECCA_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECCL_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECCT_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  EC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECDI_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECG_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECHB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECH_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECMT_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECP1_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECPB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECPC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECP_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECPE_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECPI_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECPO_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECRB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ECS_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  EID0_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  EPIC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  EVNT_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  FBPM_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  G1SL_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  G2SL_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  G3SL_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  G4SL_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  GPAR_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  GPID_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  GP_X_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  GP_Y_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  HBER_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  HBID_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  HBLA_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  HBTB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  HBTR_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  HCAL_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  HDPL_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  HEAD_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  HEVT_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  HLS_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  IC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ICHB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  KFIT_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  L1PG_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  L2H_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  L2S_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  LASR_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  LCDI_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  LCPB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  LOWQ_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  MCEV_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  MCHD_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  MCTK_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  MCVX_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  MTRK_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  MVRT_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PART_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PCO_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PHTM_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PID1_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PID2_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PID3_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PID4_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PID5_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PID6_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PIDT_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PRTM_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PSO_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  PTDB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  RCST_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  RF_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  RGLK_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  RNLG_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  RNPE_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  RTSL_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  RUNC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  S1ST_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SC1_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCDI_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCGD_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCG_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCH_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCMD_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCMT_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCMW_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCPB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCP_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCPE_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCPS_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCRC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCR_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SCS_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SGMP_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SPAR_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SPIN_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ST1_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  ST_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  STG_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  STH_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  STN0_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  STN1_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  STPB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  STPE_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  STR_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  STS_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  SYNC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TACO_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TAGE_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TAGI_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TAGM_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TAGR_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TAGT_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TBER_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TBID_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TBLA_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TBTR_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TCSB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TDPL_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TESC_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TGBI_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TGEO_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TGPB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TGS_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TLV1_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TRCF_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TRGS_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TRKS_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TRL1_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TRPB_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TSPR_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  TSRG_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  UNUS_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  VERT_t;
struct __attribute__((annotate("$clingAutoload$include/bankvars.h")))  addressBanks_t;
typedef struct BEAM_t BEAM_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct BMPR_t BMPR_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct BREP_t BREP_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CALB_t CALB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CALL_t CALL_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CC01_t CC01_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CC1_t CC1_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CC_t CC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CCDI_t CCDI_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CCH_t CCH_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CCMT_t CCMT_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CCPB_t CCPB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CCPE_t CCPE_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CCRC_t CCRC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CCS_t CCS_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CHI2_t CHI2_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CL01_t CL01_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CLST_t CLST_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CPED_t CPED_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct CSQL_t CSQL_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DC0_t DC0_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DC1_t DC1_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DCDW_t DCDW_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DCGM_t DCGM_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DCGW_t DCGW_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DCH_t DCH_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DCMN_t DCMN_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DCPB_t DCPB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DCV1_t DCV1_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DCV2_t DCV2_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DCV3_t DCV3_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DDLY_t DDLY_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DGEO_t DGEO_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DHCL_t DHCL_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DITM_t DITM_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DOCA_t DOCA_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DPCP_t DPCP_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DPSP_t DPSP_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DSPC_t DSPC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DSPS_t DSPS_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DSTC_t DSTC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DTCP_t DTCP_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct DTRK_t DTRK_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct EC01_t EC01_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct EC1_t EC1_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct EC1P_t EC1P_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct EC1R_t EC1R_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECCA_t ECCA_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECCL_t ECCL_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECCT_t ECCT_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct EC_t EC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECDI_t ECDI_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECG_t ECG_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECHB_t ECHB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECH_t ECH_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECMT_t ECMT_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECP1_t ECP1_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECPB_t ECPB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECPC_t ECPC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECP_t ECP_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECPE_t ECPE_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECPI_t ECPI_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECPO_t ECPO_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECRB_t ECRB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ECS_t ECS_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct EID0_t EID0_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct EPIC_t EPIC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct EVNT_t EVNT_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct FBPM_t FBPM_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct G1SL_t G1SL_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct G2SL_t G2SL_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct G3SL_t G3SL_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct G4SL_t G4SL_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct GPAR_t GPAR_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct GPID_t GPID_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct GP_X_t GP_X_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct GP_Y_t GP_Y_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct HBER_t HBER_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct HBID_t HBID_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct HBLA_t HBLA_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct HBTB_t HBTB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct HBTR_t HBTR_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct HCAL_t HCAL_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct HDPL_t HDPL_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct HEAD_t HEAD_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct HEVT_t HEVT_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct HLS_t HLS_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct IC_t IC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ICHB_t ICHB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct KFIT_t KFIT_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct L1PG_t L1PG_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct L2H_t L2H_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct L2S_t L2S_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct LASR_t LASR_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct LCDI_t LCDI_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct LCPB_t LCPB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct LOWQ_t LOWQ_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct MCEV_t MCEV_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct MCHD_t MCHD_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct MCTK_t MCTK_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct MCVX_t MCVX_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct MTRK_t MTRK_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct MVRT_t MVRT_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PART_t PART_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PCO_t PCO_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PHTM_t PHTM_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PID1_t PID1_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PID2_t PID2_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PID3_t PID3_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PID4_t PID4_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PID5_t PID5_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PID6_t PID6_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PIDT_t PIDT_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PRTM_t PRTM_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PSO_t PSO_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct PTDB_t PTDB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct RCST_t RCST_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct RF_t RF_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct RGLK_t RGLK_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct RNLG_t RNLG_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct RNPE_t RNPE_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct RTSL_t RTSL_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct RUNC_t RUNC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct S1ST_t S1ST_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SC1_t SC1_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCC_t SCC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SC_t SC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCDI_t SCDI_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCGD_t SCGD_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCG_t SCG_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCH_t SCH_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCMD_t SCMD_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCMT_t SCMT_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCMW_t SCMW_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCPB_t SCPB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCP_t SCP_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCPE_t SCPE_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCPS_t SCPS_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCRC_t SCRC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCR_t SCR_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SCS_t SCS_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SGMP_t SGMP_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SPAR_t SPAR_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SPIN_t SPIN_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ST1_t ST1_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct ST_t ST_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct STG_t STG_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct STH_t STH_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct STN0_t STN0_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct STN1_t STN1_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct STPB_t STPB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct STPE_t STPE_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct STR_t STR_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct STS_t STS_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct SYNC_t SYNC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TACO_t TACO_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TAGE_t TAGE_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TAGI_t TAGI_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TAGM_t TAGM_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TAGR_t TAGR_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TAGT_t TAGT_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TBER_t TBER_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TBID_t TBID_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TBLA_t TBLA_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TBTR_t TBTR_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TCSB_t TCSB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TDPL_t TDPL_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TESC_t TESC_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TGBI_t TGBI_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TGEO_t TGEO_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TGPB_t TGPB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TGS_t TGS_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TLV1_t TLV1_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TRCF_t TRCF_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TRGS_t TRGS_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TRKS_t TRKS_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TRL1_t TRL1_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TRPB_t TRPB_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TSPR_t TSPR_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct TSRG_t TSRG_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct UNUS_t UNUS_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
typedef struct VERT_t VERT_t __attribute__((annotate("$clingAutoload$include/bankvars.h"))) ;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "bankvarsDict dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "include/bankvars.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"BEAM", payloadCode, "@",
"BEAM_NH", payloadCode, "@",
"BEAM_NS", payloadCode, "@",
"BEAM_S", payloadCode, "@",
"BEAM_t", payloadCode, "@",
"BMPR", payloadCode, "@",
"BMPR_NH", payloadCode, "@",
"BMPR_NS", payloadCode, "@",
"BMPR_S", payloadCode, "@",
"BMPR_t", payloadCode, "@",
"BREP", payloadCode, "@",
"BREP_NH", payloadCode, "@",
"BREP_NS", payloadCode, "@",
"BREP_S", payloadCode, "@",
"BREP_t", payloadCode, "@",
"CALB", payloadCode, "@",
"CALB_NH", payloadCode, "@",
"CALB_NS", payloadCode, "@",
"CALB_S", payloadCode, "@",
"CALB_t", payloadCode, "@",
"CALL", payloadCode, "@",
"CALL_NH", payloadCode, "@",
"CALL_S", payloadCode, "@",
"CALL_t", payloadCode, "@",
"CC", payloadCode, "@",
"CC01", payloadCode, "@",
"CC01_NH", payloadCode, "@",
"CC01_NS", payloadCode, "@",
"CC01_S", payloadCode, "@",
"CC01_t", payloadCode, "@",
"CC1", payloadCode, "@",
"CC1_NH", payloadCode, "@",
"CC1_NS", payloadCode, "@",
"CC1_S", payloadCode, "@",
"CC1_t", payloadCode, "@",
"CCDI", payloadCode, "@",
"CCDI_NH", payloadCode, "@",
"CCDI_NS", payloadCode, "@",
"CCDI_S", payloadCode, "@",
"CCDI_t", payloadCode, "@",
"CCH", payloadCode, "@",
"CCH_NH", payloadCode, "@",
"CCH_NS", payloadCode, "@",
"CCH_S", payloadCode, "@",
"CCH_t", payloadCode, "@",
"CCMT", payloadCode, "@",
"CCMT_NH", payloadCode, "@",
"CCMT_NS", payloadCode, "@",
"CCMT_S", payloadCode, "@",
"CCMT_t", payloadCode, "@",
"CCPB", payloadCode, "@",
"CCPB_NH", payloadCode, "@",
"CCPB_S", payloadCode, "@",
"CCPB_t", payloadCode, "@",
"CCPE", payloadCode, "@",
"CCPE_NH", payloadCode, "@",
"CCPE_NS", payloadCode, "@",
"CCPE_S", payloadCode, "@",
"CCPE_t", payloadCode, "@",
"CCRC", payloadCode, "@",
"CCRC_NH", payloadCode, "@",
"CCRC_S", payloadCode, "@",
"CCRC_t", payloadCode, "@",
"CCS", payloadCode, "@",
"CCS_NH", payloadCode, "@",
"CCS_NS", payloadCode, "@",
"CCS_S", payloadCode, "@",
"CCS_t", payloadCode, "@",
"CC_NH", payloadCode, "@",
"CC_NS", payloadCode, "@",
"CC_S", payloadCode, "@",
"CC_t", payloadCode, "@",
"CHI2", payloadCode, "@",
"CHI2_NH", payloadCode, "@",
"CHI2_NS", payloadCode, "@",
"CHI2_S", payloadCode, "@",
"CHI2_t", payloadCode, "@",
"CL01", payloadCode, "@",
"CL01_NH", payloadCode, "@",
"CL01_S", payloadCode, "@",
"CL01_t", payloadCode, "@",
"CLST", payloadCode, "@",
"CLST_NH", payloadCode, "@",
"CLST_NS", payloadCode, "@",
"CLST_S", payloadCode, "@",
"CLST_t", payloadCode, "@",
"CPED", payloadCode, "@",
"CPED_NH", payloadCode, "@",
"CPED_NS", payloadCode, "@",
"CPED_S", payloadCode, "@",
"CPED_t", payloadCode, "@",
"CSQL", payloadCode, "@",
"CSQL_NH", payloadCode, "@",
"CSQL_NS", payloadCode, "@",
"CSQL_S", payloadCode, "@",
"CSQL_t", payloadCode, "@",
"DC0", payloadCode, "@",
"DC0_NH", payloadCode, "@",
"DC0_NS", payloadCode, "@",
"DC0_S", payloadCode, "@",
"DC0_t", payloadCode, "@",
"DC1", payloadCode, "@",
"DC1_NH", payloadCode, "@",
"DC1_NS", payloadCode, "@",
"DC1_S", payloadCode, "@",
"DC1_t", payloadCode, "@",
"DCDW", payloadCode, "@",
"DCDW_NH", payloadCode, "@",
"DCDW_NS", payloadCode, "@",
"DCDW_S", payloadCode, "@",
"DCDW_t", payloadCode, "@",
"DCGM", payloadCode, "@",
"DCGM_NH", payloadCode, "@",
"DCGM_NS", payloadCode, "@",
"DCGM_S", payloadCode, "@",
"DCGM_t", payloadCode, "@",
"DCGW", payloadCode, "@",
"DCGW_NH", payloadCode, "@",
"DCGW_NS", payloadCode, "@",
"DCGW_S", payloadCode, "@",
"DCGW_t", payloadCode, "@",
"DCH", payloadCode, "@",
"DCH_NH", payloadCode, "@",
"DCH_NS", payloadCode, "@",
"DCH_S", payloadCode, "@",
"DCH_t", payloadCode, "@",
"DCMN", payloadCode, "@",
"DCMN_NH", payloadCode, "@",
"DCMN_NS", payloadCode, "@",
"DCMN_S", payloadCode, "@",
"DCMN_t", payloadCode, "@",
"DCPB", payloadCode, "@",
"DCPB_NH", payloadCode, "@",
"DCPB_S", payloadCode, "@",
"DCPB_t", payloadCode, "@",
"DCV1", payloadCode, "@",
"DCV1_NH", payloadCode, "@",
"DCV1_NS", payloadCode, "@",
"DCV1_S", payloadCode, "@",
"DCV1_t", payloadCode, "@",
"DCV2", payloadCode, "@",
"DCV2_NH", payloadCode, "@",
"DCV2_NS", payloadCode, "@",
"DCV2_S", payloadCode, "@",
"DCV2_t", payloadCode, "@",
"DCV3", payloadCode, "@",
"DCV3_NH", payloadCode, "@",
"DCV3_NS", payloadCode, "@",
"DCV3_S", payloadCode, "@",
"DCV3_t", payloadCode, "@",
"DDLY", payloadCode, "@",
"DDLY_NH", payloadCode, "@",
"DDLY_NS", payloadCode, "@",
"DDLY_S", payloadCode, "@",
"DDLY_t", payloadCode, "@",
"DGEO", payloadCode, "@",
"DGEO_NH", payloadCode, "@",
"DGEO_NS", payloadCode, "@",
"DGEO_S", payloadCode, "@",
"DGEO_t", payloadCode, "@",
"DHCL", payloadCode, "@",
"DHCL_NH", payloadCode, "@",
"DHCL_NS", payloadCode, "@",
"DHCL_S", payloadCode, "@",
"DHCL_t", payloadCode, "@",
"DITM", payloadCode, "@",
"DITM_NH", payloadCode, "@",
"DITM_NS", payloadCode, "@",
"DITM_S", payloadCode, "@",
"DITM_t", payloadCode, "@",
"DOCA", payloadCode, "@",
"DOCA_NH", payloadCode, "@",
"DOCA_NS", payloadCode, "@",
"DOCA_S", payloadCode, "@",
"DOCA_t", payloadCode, "@",
"DPCP", payloadCode, "@",
"DPCP_NH", payloadCode, "@",
"DPCP_NS", payloadCode, "@",
"DPCP_S", payloadCode, "@",
"DPCP_t", payloadCode, "@",
"DPSP", payloadCode, "@",
"DPSP_NH", payloadCode, "@",
"DPSP_NS", payloadCode, "@",
"DPSP_S", payloadCode, "@",
"DPSP_t", payloadCode, "@",
"DSPC", payloadCode, "@",
"DSPC_NH", payloadCode, "@",
"DSPC_NS", payloadCode, "@",
"DSPC_S", payloadCode, "@",
"DSPC_t", payloadCode, "@",
"DSPS", payloadCode, "@",
"DSPS_NH", payloadCode, "@",
"DSPS_NS", payloadCode, "@",
"DSPS_S", payloadCode, "@",
"DSPS_t", payloadCode, "@",
"DSTC", payloadCode, "@",
"DSTC_NH", payloadCode, "@",
"DSTC_S", payloadCode, "@",
"DSTC_t", payloadCode, "@",
"DTCP", payloadCode, "@",
"DTCP_NH", payloadCode, "@",
"DTCP_NS", payloadCode, "@",
"DTCP_S", payloadCode, "@",
"DTCP_t", payloadCode, "@",
"DTRK", payloadCode, "@",
"DTRK_NH", payloadCode, "@",
"DTRK_NS", payloadCode, "@",
"DTRK_S", payloadCode, "@",
"DTRK_t", payloadCode, "@",
"EC", payloadCode, "@",
"EC01", payloadCode, "@",
"EC01_NH", payloadCode, "@",
"EC01_NS", payloadCode, "@",
"EC01_S", payloadCode, "@",
"EC01_t", payloadCode, "@",
"EC1", payloadCode, "@",
"EC1P", payloadCode, "@",
"EC1P_NH", payloadCode, "@",
"EC1P_NS", payloadCode, "@",
"EC1P_S", payloadCode, "@",
"EC1P_t", payloadCode, "@",
"EC1R", payloadCode, "@",
"EC1R_NH", payloadCode, "@",
"EC1R_NS", payloadCode, "@",
"EC1R_S", payloadCode, "@",
"EC1R_t", payloadCode, "@",
"EC1_NH", payloadCode, "@",
"EC1_NS", payloadCode, "@",
"EC1_S", payloadCode, "@",
"EC1_t", payloadCode, "@",
"ECCA", payloadCode, "@",
"ECCA_NH", payloadCode, "@",
"ECCA_NS", payloadCode, "@",
"ECCA_S", payloadCode, "@",
"ECCA_t", payloadCode, "@",
"ECCL", payloadCode, "@",
"ECCL_NH", payloadCode, "@",
"ECCL_NS", payloadCode, "@",
"ECCL_S", payloadCode, "@",
"ECCL_t", payloadCode, "@",
"ECCT", payloadCode, "@",
"ECCT_NH", payloadCode, "@",
"ECCT_NS", payloadCode, "@",
"ECCT_S", payloadCode, "@",
"ECCT_t", payloadCode, "@",
"ECDI", payloadCode, "@",
"ECDI_NH", payloadCode, "@",
"ECDI_NS", payloadCode, "@",
"ECDI_S", payloadCode, "@",
"ECDI_t", payloadCode, "@",
"ECG", payloadCode, "@",
"ECG_NH", payloadCode, "@",
"ECG_NS", payloadCode, "@",
"ECG_S", payloadCode, "@",
"ECG_t", payloadCode, "@",
"ECH", payloadCode, "@",
"ECHB", payloadCode, "@",
"ECHB_NH", payloadCode, "@",
"ECHB_S", payloadCode, "@",
"ECHB_t", payloadCode, "@",
"ECH_NH", payloadCode, "@",
"ECH_NS", payloadCode, "@",
"ECH_S", payloadCode, "@",
"ECH_t", payloadCode, "@",
"ECMT", payloadCode, "@",
"ECMT_NH", payloadCode, "@",
"ECMT_NS", payloadCode, "@",
"ECMT_S", payloadCode, "@",
"ECMT_t", payloadCode, "@",
"ECP", payloadCode, "@",
"ECP1", payloadCode, "@",
"ECP1_NH", payloadCode, "@",
"ECP1_NS", payloadCode, "@",
"ECP1_S", payloadCode, "@",
"ECP1_t", payloadCode, "@",
"ECPB", payloadCode, "@",
"ECPB_NH", payloadCode, "@",
"ECPB_S", payloadCode, "@",
"ECPB_t", payloadCode, "@",
"ECPC", payloadCode, "@",
"ECPC_NH", payloadCode, "@",
"ECPC_NS", payloadCode, "@",
"ECPC_S", payloadCode, "@",
"ECPC_t", payloadCode, "@",
"ECPE", payloadCode, "@",
"ECPE_NH", payloadCode, "@",
"ECPE_NS", payloadCode, "@",
"ECPE_S", payloadCode, "@",
"ECPE_t", payloadCode, "@",
"ECPI", payloadCode, "@",
"ECPI_NH", payloadCode, "@",
"ECPI_S", payloadCode, "@",
"ECPI_t", payloadCode, "@",
"ECPO", payloadCode, "@",
"ECPO_NH", payloadCode, "@",
"ECPO_NS", payloadCode, "@",
"ECPO_S", payloadCode, "@",
"ECPO_t", payloadCode, "@",
"ECP_NH", payloadCode, "@",
"ECP_NS", payloadCode, "@",
"ECP_S", payloadCode, "@",
"ECP_t", payloadCode, "@",
"ECRB", payloadCode, "@",
"ECRB_NH", payloadCode, "@",
"ECRB_NS", payloadCode, "@",
"ECRB_S", payloadCode, "@",
"ECRB_t", payloadCode, "@",
"ECS", payloadCode, "@",
"ECS_NH", payloadCode, "@",
"ECS_NS", payloadCode, "@",
"ECS_S", payloadCode, "@",
"ECS_t", payloadCode, "@",
"EC_NH", payloadCode, "@",
"EC_NS", payloadCode, "@",
"EC_S", payloadCode, "@",
"EC_t", payloadCode, "@",
"EID0", payloadCode, "@",
"EID0_NH", payloadCode, "@",
"EID0_NS", payloadCode, "@",
"EID0_S", payloadCode, "@",
"EID0_t", payloadCode, "@",
"EPIC", payloadCode, "@",
"EPIC_NH", payloadCode, "@",
"EPIC_NS", payloadCode, "@",
"EPIC_S", payloadCode, "@",
"EPIC_t", payloadCode, "@",
"EVNT", payloadCode, "@",
"EVNT_NH", payloadCode, "@",
"EVNT_S", payloadCode, "@",
"EVNT_t", payloadCode, "@",
"FBPM", payloadCode, "@",
"FBPM_NH", payloadCode, "@",
"FBPM_NS", payloadCode, "@",
"FBPM_S", payloadCode, "@",
"FBPM_t", payloadCode, "@",
"G1SL", payloadCode, "@",
"G1SL_NH", payloadCode, "@",
"G1SL_NS", payloadCode, "@",
"G1SL_S", payloadCode, "@",
"G1SL_t", payloadCode, "@",
"G2SL", payloadCode, "@",
"G2SL_NH", payloadCode, "@",
"G2SL_NS", payloadCode, "@",
"G2SL_S", payloadCode, "@",
"G2SL_t", payloadCode, "@",
"G3SL", payloadCode, "@",
"G3SL_NH", payloadCode, "@",
"G3SL_NS", payloadCode, "@",
"G3SL_S", payloadCode, "@",
"G3SL_t", payloadCode, "@",
"G4SL", payloadCode, "@",
"G4SL_NH", payloadCode, "@",
"G4SL_NS", payloadCode, "@",
"G4SL_S", payloadCode, "@",
"G4SL_t", payloadCode, "@",
"GPAR", payloadCode, "@",
"GPAR_NH", payloadCode, "@",
"GPAR_NS", payloadCode, "@",
"GPAR_S", payloadCode, "@",
"GPAR_t", payloadCode, "@",
"GPID", payloadCode, "@",
"GPID_NH", payloadCode, "@",
"GPID_S", payloadCode, "@",
"GPID_t", payloadCode, "@",
"GP_X", payloadCode, "@",
"GP_X_NH", payloadCode, "@",
"GP_X_S", payloadCode, "@",
"GP_X_t", payloadCode, "@",
"GP_Y", payloadCode, "@",
"GP_Y_NH", payloadCode, "@",
"GP_Y_S", payloadCode, "@",
"GP_Y_t", payloadCode, "@",
"HBER", payloadCode, "@",
"HBER_NH", payloadCode, "@",
"HBER_S", payloadCode, "@",
"HBER_t", payloadCode, "@",
"HBID", payloadCode, "@",
"HBID_NH", payloadCode, "@",
"HBID_S", payloadCode, "@",
"HBID_t", payloadCode, "@",
"HBLA", payloadCode, "@",
"HBLA_NH", payloadCode, "@",
"HBLA_NS", payloadCode, "@",
"HBLA_S", payloadCode, "@",
"HBLA_t", payloadCode, "@",
"HBTB", payloadCode, "@",
"HBTB_NH", payloadCode, "@",
"HBTB_NS", payloadCode, "@",
"HBTB_S", payloadCode, "@",
"HBTB_t", payloadCode, "@",
"HBTR", payloadCode, "@",
"HBTR_NH", payloadCode, "@",
"HBTR_S", payloadCode, "@",
"HBTR_t", payloadCode, "@",
"HCAL", payloadCode, "@",
"HCAL_NH", payloadCode, "@",
"HCAL_NS", payloadCode, "@",
"HCAL_S", payloadCode, "@",
"HCAL_t", payloadCode, "@",
"HDPL", payloadCode, "@",
"HDPL_NH", payloadCode, "@",
"HDPL_NS", payloadCode, "@",
"HDPL_S", payloadCode, "@",
"HDPL_t", payloadCode, "@",
"HEAD", payloadCode, "@",
"HEAD_NH", payloadCode, "@",
"HEAD_S", payloadCode, "@",
"HEAD_t", payloadCode, "@",
"HEVT", payloadCode, "@",
"HEVT_NH", payloadCode, "@",
"HEVT_S", payloadCode, "@",
"HEVT_t", payloadCode, "@",
"HLS", payloadCode, "@",
"HLS_NH", payloadCode, "@",
"HLS_NS", payloadCode, "@",
"HLS_S", payloadCode, "@",
"HLS_t", payloadCode, "@",
"IC", payloadCode, "@",
"ICHB", payloadCode, "@",
"ICHB_NH", payloadCode, "@",
"ICHB_NS", payloadCode, "@",
"ICHB_S", payloadCode, "@",
"ICHB_t", payloadCode, "@",
"IC_NH", payloadCode, "@",
"IC_NS", payloadCode, "@",
"IC_S", payloadCode, "@",
"IC_t", payloadCode, "@",
"KFIT", payloadCode, "@",
"KFIT_NH", payloadCode, "@",
"KFIT_NS", payloadCode, "@",
"KFIT_S", payloadCode, "@",
"KFIT_t", payloadCode, "@",
"L1PG", payloadCode, "@",
"L1PG_NH", payloadCode, "@",
"L1PG_NS", payloadCode, "@",
"L1PG_S", payloadCode, "@",
"L1PG_t", payloadCode, "@",
"L2H", payloadCode, "@",
"L2H_NH", payloadCode, "@",
"L2H_NS", payloadCode, "@",
"L2H_S", payloadCode, "@",
"L2H_t", payloadCode, "@",
"L2S", payloadCode, "@",
"L2S_NH", payloadCode, "@",
"L2S_NS", payloadCode, "@",
"L2S_S", payloadCode, "@",
"L2S_t", payloadCode, "@",
"LASR", payloadCode, "@",
"LASR_NH", payloadCode, "@",
"LASR_NS", payloadCode, "@",
"LASR_S", payloadCode, "@",
"LASR_t", payloadCode, "@",
"LCDI", payloadCode, "@",
"LCDI_NH", payloadCode, "@",
"LCDI_NS", payloadCode, "@",
"LCDI_S", payloadCode, "@",
"LCDI_t", payloadCode, "@",
"LCPB", payloadCode, "@",
"LCPB_NH", payloadCode, "@",
"LCPB_S", payloadCode, "@",
"LCPB_t", payloadCode, "@",
"LOWQ", payloadCode, "@",
"LOWQ_NH", payloadCode, "@",
"LOWQ_NS", payloadCode, "@",
"LOWQ_S", payloadCode, "@",
"LOWQ_t", payloadCode, "@",
"MCEV", payloadCode, "@",
"MCEV_NH", payloadCode, "@",
"MCEV_NS", payloadCode, "@",
"MCEV_S", payloadCode, "@",
"MCEV_t", payloadCode, "@",
"MCHD", payloadCode, "@",
"MCHD_NH", payloadCode, "@",
"MCHD_NS", payloadCode, "@",
"MCHD_S", payloadCode, "@",
"MCHD_t", payloadCode, "@",
"MCTK", payloadCode, "@",
"MCTK_NH", payloadCode, "@",
"MCTK_NS", payloadCode, "@",
"MCTK_S", payloadCode, "@",
"MCTK_t", payloadCode, "@",
"MCVX", payloadCode, "@",
"MCVX_NH", payloadCode, "@",
"MCVX_S", payloadCode, "@",
"MCVX_t", payloadCode, "@",
"MTRK", payloadCode, "@",
"MTRK_NH", payloadCode, "@",
"MTRK_NS", payloadCode, "@",
"MTRK_S", payloadCode, "@",
"MTRK_t", payloadCode, "@",
"MVRT", payloadCode, "@",
"MVRT_NH", payloadCode, "@",
"MVRT_S", payloadCode, "@",
"MVRT_t", payloadCode, "@",
"PART", payloadCode, "@",
"PART_NH", payloadCode, "@",
"PART_S", payloadCode, "@",
"PART_t", payloadCode, "@",
"PCO", payloadCode, "@",
"PCO_NH", payloadCode, "@",
"PCO_NS", payloadCode, "@",
"PCO_S", payloadCode, "@",
"PCO_t", payloadCode, "@",
"PHTM", payloadCode, "@",
"PHTM_NH", payloadCode, "@",
"PHTM_NS", payloadCode, "@",
"PHTM_S", payloadCode, "@",
"PHTM_t", payloadCode, "@",
"PID1", payloadCode, "@",
"PID1_NH", payloadCode, "@",
"PID1_NS", payloadCode, "@",
"PID1_S", payloadCode, "@",
"PID1_t", payloadCode, "@",
"PID2", payloadCode, "@",
"PID2_NH", payloadCode, "@",
"PID2_NS", payloadCode, "@",
"PID2_S", payloadCode, "@",
"PID2_t", payloadCode, "@",
"PID3", payloadCode, "@",
"PID3_NH", payloadCode, "@",
"PID3_NS", payloadCode, "@",
"PID3_S", payloadCode, "@",
"PID3_t", payloadCode, "@",
"PID4", payloadCode, "@",
"PID4_NH", payloadCode, "@",
"PID4_NS", payloadCode, "@",
"PID4_S", payloadCode, "@",
"PID4_t", payloadCode, "@",
"PID5", payloadCode, "@",
"PID5_NH", payloadCode, "@",
"PID5_NS", payloadCode, "@",
"PID5_S", payloadCode, "@",
"PID5_t", payloadCode, "@",
"PID6", payloadCode, "@",
"PID6_NH", payloadCode, "@",
"PID6_NS", payloadCode, "@",
"PID6_S", payloadCode, "@",
"PID6_t", payloadCode, "@",
"PIDT", payloadCode, "@",
"PIDT_NH", payloadCode, "@",
"PIDT_NS", payloadCode, "@",
"PIDT_S", payloadCode, "@",
"PIDT_t", payloadCode, "@",
"PRTM", payloadCode, "@",
"PRTM_NH", payloadCode, "@",
"PRTM_NS", payloadCode, "@",
"PRTM_S", payloadCode, "@",
"PRTM_t", payloadCode, "@",
"PSO", payloadCode, "@",
"PSO_NH", payloadCode, "@",
"PSO_NS", payloadCode, "@",
"PSO_S", payloadCode, "@",
"PSO_t", payloadCode, "@",
"PTDB", payloadCode, "@",
"PTDB_NH", payloadCode, "@",
"PTDB_NS", payloadCode, "@",
"PTDB_S", payloadCode, "@",
"PTDB_t", payloadCode, "@",
"RCST", payloadCode, "@",
"RCST_NH", payloadCode, "@",
"RCST_NS", payloadCode, "@",
"RCST_S", payloadCode, "@",
"RCST_t", payloadCode, "@",
"RF", payloadCode, "@",
"RF_NH", payloadCode, "@",
"RF_S", payloadCode, "@",
"RF_t", payloadCode, "@",
"RGLK", payloadCode, "@",
"RGLK_NH", payloadCode, "@",
"RGLK_NS", payloadCode, "@",
"RGLK_S", payloadCode, "@",
"RGLK_t", payloadCode, "@",
"RNLG", payloadCode, "@",
"RNLG_NH", payloadCode, "@",
"RNLG_NS", payloadCode, "@",
"RNLG_S", payloadCode, "@",
"RNLG_t", payloadCode, "@",
"RNPE", payloadCode, "@",
"RNPE_NH", payloadCode, "@",
"RNPE_NS", payloadCode, "@",
"RNPE_S", payloadCode, "@",
"RNPE_t", payloadCode, "@",
"RTSL", payloadCode, "@",
"RTSL_NH", payloadCode, "@",
"RTSL_NS", payloadCode, "@",
"RTSL_S", payloadCode, "@",
"RTSL_t", payloadCode, "@",
"RUNC", payloadCode, "@",
"RUNC_NH", payloadCode, "@",
"RUNC_NS", payloadCode, "@",
"RUNC_S", payloadCode, "@",
"RUNC_t", payloadCode, "@",
"S1ST", payloadCode, "@",
"S1ST_NH", payloadCode, "@",
"S1ST_NS", payloadCode, "@",
"S1ST_S", payloadCode, "@",
"S1ST_t", payloadCode, "@",
"SC", payloadCode, "@",
"SC1", payloadCode, "@",
"SC1_NH", payloadCode, "@",
"SC1_NS", payloadCode, "@",
"SC1_S", payloadCode, "@",
"SC1_t", payloadCode, "@",
"SCC", payloadCode, "@",
"SCC_NH", payloadCode, "@",
"SCC_NS", payloadCode, "@",
"SCC_S", payloadCode, "@",
"SCC_t", payloadCode, "@",
"SCDI", payloadCode, "@",
"SCDI_NH", payloadCode, "@",
"SCDI_NS", payloadCode, "@",
"SCDI_S", payloadCode, "@",
"SCDI_t", payloadCode, "@",
"SCG", payloadCode, "@",
"SCGD", payloadCode, "@",
"SCGD_NH", payloadCode, "@",
"SCGD_NS", payloadCode, "@",
"SCGD_S", payloadCode, "@",
"SCGD_t", payloadCode, "@",
"SCG_NH", payloadCode, "@",
"SCG_NS", payloadCode, "@",
"SCG_S", payloadCode, "@",
"SCG_t", payloadCode, "@",
"SCH", payloadCode, "@",
"SCH_NH", payloadCode, "@",
"SCH_NS", payloadCode, "@",
"SCH_S", payloadCode, "@",
"SCH_t", payloadCode, "@",
"SCMD", payloadCode, "@",
"SCMD_NH", payloadCode, "@",
"SCMD_NS", payloadCode, "@",
"SCMD_S", payloadCode, "@",
"SCMD_t", payloadCode, "@",
"SCMT", payloadCode, "@",
"SCMT_NH", payloadCode, "@",
"SCMT_NS", payloadCode, "@",
"SCMT_S", payloadCode, "@",
"SCMT_t", payloadCode, "@",
"SCMW", payloadCode, "@",
"SCMW_NH", payloadCode, "@",
"SCMW_NS", payloadCode, "@",
"SCMW_S", payloadCode, "@",
"SCMW_t", payloadCode, "@",
"SCP", payloadCode, "@",
"SCPB", payloadCode, "@",
"SCPB_NH", payloadCode, "@",
"SCPB_S", payloadCode, "@",
"SCPB_t", payloadCode, "@",
"SCPE", payloadCode, "@",
"SCPE_NH", payloadCode, "@",
"SCPE_NS", payloadCode, "@",
"SCPE_S", payloadCode, "@",
"SCPE_t", payloadCode, "@",
"SCPS", payloadCode, "@",
"SCPS_NH", payloadCode, "@",
"SCPS_NS", payloadCode, "@",
"SCPS_S", payloadCode, "@",
"SCPS_t", payloadCode, "@",
"SCP_NH", payloadCode, "@",
"SCP_NS", payloadCode, "@",
"SCP_S", payloadCode, "@",
"SCP_t", payloadCode, "@",
"SCR", payloadCode, "@",
"SCRC", payloadCode, "@",
"SCRC_NH", payloadCode, "@",
"SCRC_NS", payloadCode, "@",
"SCRC_S", payloadCode, "@",
"SCRC_t", payloadCode, "@",
"SCR_NH", payloadCode, "@",
"SCR_NS", payloadCode, "@",
"SCR_S", payloadCode, "@",
"SCR_t", payloadCode, "@",
"SCS", payloadCode, "@",
"SCS_NH", payloadCode, "@",
"SCS_NS", payloadCode, "@",
"SCS_S", payloadCode, "@",
"SCS_t", payloadCode, "@",
"SC_NH", payloadCode, "@",
"SC_NS", payloadCode, "@",
"SC_S", payloadCode, "@",
"SC_t", payloadCode, "@",
"SGMP", payloadCode, "@",
"SGMP_NH", payloadCode, "@",
"SGMP_NS", payloadCode, "@",
"SGMP_S", payloadCode, "@",
"SGMP_t", payloadCode, "@",
"SPAR", payloadCode, "@",
"SPAR_NH", payloadCode, "@",
"SPAR_NS", payloadCode, "@",
"SPAR_S", payloadCode, "@",
"SPAR_t", payloadCode, "@",
"SPIN", payloadCode, "@",
"SPIN_NH", payloadCode, "@",
"SPIN_NS", payloadCode, "@",
"SPIN_S", payloadCode, "@",
"SPIN_t", payloadCode, "@",
"ST", payloadCode, "@",
"ST1", payloadCode, "@",
"ST1_NH", payloadCode, "@",
"ST1_NS", payloadCode, "@",
"ST1_S", payloadCode, "@",
"ST1_t", payloadCode, "@",
"STG", payloadCode, "@",
"STG_NH", payloadCode, "@",
"STG_NS", payloadCode, "@",
"STG_S", payloadCode, "@",
"STG_t", payloadCode, "@",
"STH", payloadCode, "@",
"STH_NH", payloadCode, "@",
"STH_NS", payloadCode, "@",
"STH_S", payloadCode, "@",
"STH_t", payloadCode, "@",
"STN0", payloadCode, "@",
"STN0_NH", payloadCode, "@",
"STN0_S", payloadCode, "@",
"STN0_t", payloadCode, "@",
"STN1", payloadCode, "@",
"STN1_NH", payloadCode, "@",
"STN1_S", payloadCode, "@",
"STN1_t", payloadCode, "@",
"STPB", payloadCode, "@",
"STPB_NH", payloadCode, "@",
"STPB_S", payloadCode, "@",
"STPB_t", payloadCode, "@",
"STPE", payloadCode, "@",
"STPE_NH", payloadCode, "@",
"STPE_NS", payloadCode, "@",
"STPE_S", payloadCode, "@",
"STPE_t", payloadCode, "@",
"STR", payloadCode, "@",
"STR_NH", payloadCode, "@",
"STR_S", payloadCode, "@",
"STR_t", payloadCode, "@",
"STS", payloadCode, "@",
"STS_NH", payloadCode, "@",
"STS_NS", payloadCode, "@",
"STS_S", payloadCode, "@",
"STS_t", payloadCode, "@",
"ST_NH", payloadCode, "@",
"ST_S", payloadCode, "@",
"ST_t", payloadCode, "@",
"SYNC", payloadCode, "@",
"SYNC_NH", payloadCode, "@",
"SYNC_NS", payloadCode, "@",
"SYNC_S", payloadCode, "@",
"SYNC_t", payloadCode, "@",
"TACO", payloadCode, "@",
"TACO_NH", payloadCode, "@",
"TACO_NS", payloadCode, "@",
"TACO_S", payloadCode, "@",
"TACO_t", payloadCode, "@",
"TAGE", payloadCode, "@",
"TAGE_NH", payloadCode, "@",
"TAGE_S", payloadCode, "@",
"TAGE_t", payloadCode, "@",
"TAGI", payloadCode, "@",
"TAGI_NH", payloadCode, "@",
"TAGI_NS", payloadCode, "@",
"TAGI_S", payloadCode, "@",
"TAGI_t", payloadCode, "@",
"TAGM", payloadCode, "@",
"TAGM_NH", payloadCode, "@",
"TAGM_S", payloadCode, "@",
"TAGM_t", payloadCode, "@",
"TAGR", payloadCode, "@",
"TAGR_NH", payloadCode, "@",
"TAGR_S", payloadCode, "@",
"TAGR_t", payloadCode, "@",
"TAGT", payloadCode, "@",
"TAGT_NH", payloadCode, "@",
"TAGT_S", payloadCode, "@",
"TAGT_t", payloadCode, "@",
"TBER", payloadCode, "@",
"TBER_NH", payloadCode, "@",
"TBER_S", payloadCode, "@",
"TBER_t", payloadCode, "@",
"TBID", payloadCode, "@",
"TBID_NH", payloadCode, "@",
"TBID_S", payloadCode, "@",
"TBID_t", payloadCode, "@",
"TBLA", payloadCode, "@",
"TBLA_NH", payloadCode, "@",
"TBLA_NS", payloadCode, "@",
"TBLA_S", payloadCode, "@",
"TBLA_t", payloadCode, "@",
"TBTR", payloadCode, "@",
"TBTR_NH", payloadCode, "@",
"TBTR_S", payloadCode, "@",
"TBTR_t", payloadCode, "@",
"TCSB", payloadCode, "@",
"TCSB_NH", payloadCode, "@",
"TCSB_NS", payloadCode, "@",
"TCSB_S", payloadCode, "@",
"TCSB_t", payloadCode, "@",
"TDPL", payloadCode, "@",
"TDPL_NH", payloadCode, "@",
"TDPL_NS", payloadCode, "@",
"TDPL_S", payloadCode, "@",
"TDPL_t", payloadCode, "@",
"TESC", payloadCode, "@",
"TESC_NH", payloadCode, "@",
"TESC_S", payloadCode, "@",
"TESC_t", payloadCode, "@",
"TGBI", payloadCode, "@",
"TGBI_NH", payloadCode, "@",
"TGBI_S", payloadCode, "@",
"TGBI_t", payloadCode, "@",
"TGEO", payloadCode, "@",
"TGEO_NH", payloadCode, "@",
"TGEO_NS", payloadCode, "@",
"TGEO_S", payloadCode, "@",
"TGEO_t", payloadCode, "@",
"TGPB", payloadCode, "@",
"TGPB_NH", payloadCode, "@",
"TGPB_S", payloadCode, "@",
"TGPB_t", payloadCode, "@",
"TGS", payloadCode, "@",
"TGS_NH", payloadCode, "@",
"TGS_NS", payloadCode, "@",
"TGS_S", payloadCode, "@",
"TGS_t", payloadCode, "@",
"TLV1", payloadCode, "@",
"TLV1_NH", payloadCode, "@",
"TLV1_NS", payloadCode, "@",
"TLV1_S", payloadCode, "@",
"TLV1_t", payloadCode, "@",
"TRCF", payloadCode, "@",
"TRCF_NH", payloadCode, "@",
"TRCF_NS", payloadCode, "@",
"TRCF_S", payloadCode, "@",
"TRCF_t", payloadCode, "@",
"TRGS", payloadCode, "@",
"TRGS_NH", payloadCode, "@",
"TRGS_NS", payloadCode, "@",
"TRGS_S", payloadCode, "@",
"TRGS_t", payloadCode, "@",
"TRKS", payloadCode, "@",
"TRKS_NH", payloadCode, "@",
"TRKS_NS", payloadCode, "@",
"TRKS_S", payloadCode, "@",
"TRKS_t", payloadCode, "@",
"TRL1", payloadCode, "@",
"TRL1_NH", payloadCode, "@",
"TRL1_NS", payloadCode, "@",
"TRL1_S", payloadCode, "@",
"TRL1_t", payloadCode, "@",
"TRPB", payloadCode, "@",
"TRPB_NH", payloadCode, "@",
"TRPB_NS", payloadCode, "@",
"TRPB_S", payloadCode, "@",
"TRPB_t", payloadCode, "@",
"TSPR", payloadCode, "@",
"TSPR_NH", payloadCode, "@",
"TSPR_NS", payloadCode, "@",
"TSPR_S", payloadCode, "@",
"TSPR_t", payloadCode, "@",
"TSRG", payloadCode, "@",
"TSRG_NH", payloadCode, "@",
"TSRG_NS", payloadCode, "@",
"TSRG_S", payloadCode, "@",
"TSRG_t", payloadCode, "@",
"UNUS", payloadCode, "@",
"UNUS_NH", payloadCode, "@",
"UNUS_NS", payloadCode, "@",
"UNUS_S", payloadCode, "@",
"UNUS_t", payloadCode, "@",
"VERT", payloadCode, "@",
"VERT_NH", payloadCode, "@",
"VERT_NS", payloadCode, "@",
"VERT_S", payloadCode, "@",
"VERT_t", payloadCode, "@",
"addressBanks_t", payloadCode, "@",
"bankAddress", payloadCode, "@",
"nBankTypes", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("bankvarsDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_bankvarsDict_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_bankvarsDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_bankvarsDict() {
  TriggerDictionaryInitialization_bankvarsDict_Impl();
}
