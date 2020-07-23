#ifdef MY_DLL_EXPORTS
#   define MY_DLL_EXP __declspec(dllexport)
#else
#   define MY_DLL_EXP __declspec(dllimport)
#endif


#include "MyDllBase.h"

class  HelloDll :public MyDllBase {
public:
     HelloDll();
     ~HelloDll();
	 void  hello();
};

HelloDll* GetInstance();