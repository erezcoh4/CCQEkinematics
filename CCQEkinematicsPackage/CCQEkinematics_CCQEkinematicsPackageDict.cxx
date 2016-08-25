// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME CCQEkinematics_CCQEkinematicsPackageDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
#include "BasicKinematics.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *BasicKinematics_Dictionary();
   static void BasicKinematics_TClassManip(TClass*);
   static void *new_BasicKinematics(void *p = 0);
   static void *newArray_BasicKinematics(Long_t size, void *p);
   static void delete_BasicKinematics(void *p);
   static void deleteArray_BasicKinematics(void *p);
   static void destruct_BasicKinematics(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::BasicKinematics*)
   {
      ::BasicKinematics *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::BasicKinematics));
      static ::ROOT::TGenericClassInfo 
         instance("BasicKinematics", "BasicKinematics.h", 25,
                  typeid(::BasicKinematics), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &BasicKinematics_Dictionary, isa_proxy, 4,
                  sizeof(::BasicKinematics) );
      instance.SetNew(&new_BasicKinematics);
      instance.SetNewArray(&newArray_BasicKinematics);
      instance.SetDelete(&delete_BasicKinematics);
      instance.SetDeleteArray(&deleteArray_BasicKinematics);
      instance.SetDestructor(&destruct_BasicKinematics);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::BasicKinematics*)
   {
      return GenerateInitInstanceLocal((::BasicKinematics*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::BasicKinematics*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *BasicKinematics_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::BasicKinematics*)0x0)->GetClass();
      BasicKinematics_TClassManip(theClass);
   return theClass;
   }

   static void BasicKinematics_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_BasicKinematics(void *p) {
      return  p ? new(p) ::BasicKinematics : new ::BasicKinematics;
   }
   static void *newArray_BasicKinematics(Long_t nElements, void *p) {
      return p ? new(p) ::BasicKinematics[nElements] : new ::BasicKinematics[nElements];
   }
   // Wrapper around operator delete
   static void delete_BasicKinematics(void *p) {
      delete ((::BasicKinematics*)p);
   }
   static void deleteArray_BasicKinematics(void *p) {
      delete [] ((::BasicKinematics*)p);
   }
   static void destruct_BasicKinematics(void *p) {
      typedef ::BasicKinematics current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::BasicKinematics

namespace {
  void TriggerDictionaryInitialization_libCCQEkinematics_CCQEkinematicsPackage_Impl() {
    static const char* headers[] = {
"BasicKinematics.h",
0
    };
    static const char* includePaths[] = {
"/usr/local/Cellar/root6/6.06.02/include/root",
"/Users/erezcohen/larlite/UserDev/CCQEkinematics/CCQEkinematicsPackage/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libCCQEkinematics_CCQEkinematicsPackage dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$BasicKinematics.h")))  BasicKinematics;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libCCQEkinematics_CCQEkinematicsPackage dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "BasicKinematics.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"BasicKinematics", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libCCQEkinematics_CCQEkinematicsPackage",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libCCQEkinematics_CCQEkinematicsPackage_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libCCQEkinematics_CCQEkinematicsPackage_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libCCQEkinematics_CCQEkinematicsPackage() {
  TriggerDictionaryInitialization_libCCQEkinematics_CCQEkinematicsPackage_Impl();
}
