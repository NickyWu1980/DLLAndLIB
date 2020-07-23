#include <iostream>
#include <windows.h>
using namespace std;

class CDLL
{
public:
	virtual int MyPrint() = 0;

};


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