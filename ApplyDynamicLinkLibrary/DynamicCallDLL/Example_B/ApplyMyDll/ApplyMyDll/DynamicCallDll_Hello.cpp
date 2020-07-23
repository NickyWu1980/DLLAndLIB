#if 1
// DynamicCallDll.cpp
//#undef UNICODE
#include <windows.h>
#include <iostream>
using namespace std;


class MyDllBase {
public:
    virtual ~MyDllBase() {};
    virtual void hello() = 0;
};

// using pfGetInst = MyDllBase* (*)()
// pfGetInst 是一个指针，指向一个函数，这个函数返回 MyDllBase 的指针
typedef MyDllBase* (*pfGetInst)();

int main()
{
	HMODULE hMod = LoadLibrary(L"MyDll.dll");
	if (hMod) {
		pfGetInst pfGetInstance = (pfGetInst)GetProcAddress(hMod, "GetInstance");
		if (pfGetInstance) {
			// 通过基类指针指向了派生类的对象
			MyDllBase* pInst = pfGetInstance();
			if (NULL != pInst) {
				pInst->hello();
			}
			if (NULL == pInst) {
				std::cout << "Dinamic call MyDll failed T_T" << std::endl;
				delete pInst;
			}
		}
	}
	system("pause");
	return 0;
}

#else
#include <iostream>
#include <windows.h>
using namespace std;
/*
class CDLL
{
public:
	virtual int MyPrint() = 0;

};
*/

int main()
{
	HINSTANCE hDll;//句柄

	typedef CDLL*(*MyGetInstance)();
	MyGetInstance instance;//函数指针
	hDll = ::LoadLibrary(L"MyDll.dll");//动态加载DLL模块句柄
	if (hDll)
	{
		instance = (MyGetInstance)GetProcAddress(hDll, "getInstance");//得到所加载DLL模块中函数的地址
		
		CDLL *dll = instance();
		int ret = dll->MyPrint();
		cout << "ret=" << ret << endl;
		FreeLibrary(hDll);//释放已经加载的DLL模块
	}

	system("pause");
	return 0;
}
#endif