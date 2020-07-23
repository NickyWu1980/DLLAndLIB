// MyDll.h
#ifdef MY_DLL_EXPORTS
#   define MY_DLL_EXP __declspec(dllexport)
#else
#   define MY_DLL_EXP __declspec(dllimport)
#endif

#include "DLLTestBase.h"

class CDLLTest :public CDLLTestBase
{
  public:
     CDLLTest();
    ~CDLLTest();
    int Add(int a, int b);
};

CDLLTest* GetInstance();