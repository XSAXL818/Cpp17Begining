#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;
// 测试章：为实现简单，类的声明和类的实现放在一个文件中



class Ch11Sec5{
public:
	// Sec4：副本构造函数
	static void test0() {
		Box4_9_1 b1{ 1,2,3 };
		Box4_9_1 b2{ b1 };// 未显式定义副本构造函数，对于指针成员变量有风险

		Box4_9_2 b3{ 1,2,3 };
		Box4_9_2 b4{ b3 };

		MyOops m1{ new int{ 1 } };
		MyOops m2{ m1 };

		*m2.ptr = 3;
		m1.print();
		m2.print();

		m1.p(m1);
	}
	// Sec5：访问私有类成员
	static void test1() {
		Box5 b;
		cout << b.getSide() << endl;
		b.setSide(-1);
		cout << b.getSide() << endl;
		b.setSide(2);
		cout << b.getSide() << endl;
	}

	// Sec6：this指针
	static void test2(){
		
		This t;
		cout << "t对象的地址：" << &t << endl;
		t.setA(1)->setB(2).setC(5);
		t.print();
	}

};

