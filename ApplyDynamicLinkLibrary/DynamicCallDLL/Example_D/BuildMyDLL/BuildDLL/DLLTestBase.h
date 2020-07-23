class CDLLTestBase
{
  public:
	 virtual ~CDLLTestBase(){};//虚析构函数，且为内联函数
     virtual int Add(int a, int b) = 0;
};