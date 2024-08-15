#include "MyTest.h"
#include "Test45.h"


// 在类的外部定义函数
void MyTest::test1(){
	Test45 t1;
	t1.print();
	Test45 t2{1};
	t2.print();
	Test45 t3{2,&t2.m_a};
	t3.print();

	int a{ 1 }, b{ 2 };
	Test45 t4{ a,b };
	t4.print();

}

//使用explicit，只能显式转换
void MyTest::test2(){
	Cube c1{ 5 };
	Cube c2{ 2 };
	cout << "传参为对象" << endl;
	cout << c1.isLargerThan(c2) << endl;

	cout << "传参为int类型的值" << endl;
	cout << c1.isLargerThan(50) << endl;

	ExplicitCube ec1{ 5 };
	cout << "传参为int类型的值" << endl;
	//cout << ec1.isLargerThan(50) << endl;
}

// 测试委托构造函数
void MyTest::test3(){
	Box4_9 b1{1};
	b1.print();
	Box4_9 b2{1,2,3};
	b2.print();

}

