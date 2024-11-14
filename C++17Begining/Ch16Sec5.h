#pragma once
#include <iostream>
#include "NeedClass.h"
class Ch16Sec5{
public:
	static void test0() {
		cout << "----------测试0: 非类型的类模板参数" << endl;
		Array16_5_1<int, 5> arr1{ 4 };
		arr1.println();



	}
	static void test1() {
		cout << "----------测试1: 非参数类型的实参不同，则定义出的类不同" << endl;
		Class16_5_1<int,1> c1;
		Class16_5_1<int, 2> c2;
		Class16_5_1<int, 2> c3;

		cout << &c1.a << endl;
		cout << &c2.a << endl;
		cout << &c3.a << endl;
		c1.f1();
	}

	static void test2() {
		cout << "----------测试1: 非类型参数的实参" << endl;
		int a = 3;
		const int b = 3;
		// a不是常量，无法通过编译
		//Class16_5_1<int, a> arr1;
		Class16_5_1<int, b> arr1;

	
		cout << "----------测试2: 对比非类型模板实参与构造函数实参" << endl;
		Class16_5_1<int, 0> c1;
		Class16_5_1<int, 1> c2;
		//c1 = c2;// 不是一个类型的对象
	}





};

