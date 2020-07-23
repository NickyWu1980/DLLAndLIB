#include <windows.h>
#include <iostream>
using namespace std;
#if 1
class CDLLTestBase {
public:
	 virtual ~CDLLTestBase(){};			//虚析构函数，且为内联函数
     virtual int Add(int a, int b) = 0; //
};

// using pfGetInst = MyDllBase* (*)()
// pfGetInst 是一个指针，指向一个函数，这个函数返回 MyDllBase 的指针
typedef CDLLTestBase* (*pfGetInst)();

int main()
{
	HMODULE hMod = LoadLibrary(L"DLLTest.dll");
	if (hMod) {
		  pfGetInst pfGetInstance = (pfGetInst)GetProcAddress(hMod, "GetInstance");
		  if (pfGetInstance) {
		  
				//通过基类指针指向派生类对象
				CDLLTestBase* pInst = pfGetInstance();
				if (NULL != pInst ){
					pInst->Add(1,2);
					std::cout << "Dinamic call MyDll Ok! ^-^" << std::endl;
				}

				if (NULL == pInst)  {
					std::cout << "Dinamic call MyDll failed T_T" << std::endl;
					//释放对象
					delete pInst;
				}
		  }
	}
	system("pause");
	return 0;
}

#else

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

#endif
