#pragma once


#include <iostream>
#include "NeedClass.h"

using namespace std;
// 测试章：为实现简单，类的声明和类的实现放在一个文件中


//Sec7：const对象和const成员函数
class Ch11Sec7{
public:

	//1 const成员函数
	static void test1() {
		cout << "-------测试：const成员函数\n";
		const Box7_1_1 b1{ 1,2,3 };
		//b1.setLength();// b1.不会给予任何提示
		//b1.getLength();// 该函数不会修改成员变量，但仍然无法调用

		const Box7_1_2 b2{1,2,3 };
		cout << b2.getHeight() << endl;
	}

	//3 const重载
	static void test3() {
		cout << "-------测试7_3：const重载\n";
		Box7_3_1 b1{ 1,2,3 };
		b1.a() = 3;// 
		cout << b1.a() << endl;

		const Box7_3_1 b2{ 1,2,3 };
		// b2.a() = 3;// 无法调用,这是个好事
		// cout << b2.a() << endl; // 这是个坏事


		Box7_3_2 b3{ 1,2,3 };
		cout << b3.a() << endl;

		const Box7_3_2 b4{ 1,2,3 };
		cout << b4.a() << endl;
		// b4.a() = 4;// 无法调用,这是个好事


	}

	static void test4() {
		cout << "-------测试7_4：常量的强制转换\n";

		const Box7_3_2 b1{ 1,2,3 };
		Box7_3_2& rb = const_cast<Box7_3_2&>(b1);
		rb.a() = 3;
		cout << b1.a() << endl;
		cout << rb.a() << endl;
		cout << &b1 << endl;
		cout << &rb << endl;

	}


	static void test5() {
		cout << "-------测试7_5：使用mutable关键字\n";

		const Log7_5 log;
		log.write("Hello, world!");

		log.write("测试!");



	}


};

