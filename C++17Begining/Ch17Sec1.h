#pragma once
#include <iostream>
#include <type_traits>
#include "NeedClass.h"
using namespace std;
// 测试章：为实现简单，类的声明和类的实现放在一个文件中



class Ch17Sec1 {
public:
	// Sec1：左值和右值
	static void test0() {
		auto obj1 = MyClass17_1::createObject();
		cout << "接受即复制该右值：" << endl;
		printTypeInfo(obj1);
		const MyClass17_1& obj2 = MyClass17_1::createObject();
		cout << "使用const引用接受，不复制该对象：" << typeid(obj2).name() << endl;
		printTypeInfo(obj2);

		// 引用3+4的结果的别名
		int&& x = 3 + 4;
		cout << "右值引用：" << typeid(x).name() << endl;

	}
	// Sec2：移动对象
	static void test1() {

	}

	// Sec6：this指针
	static void test2() {

	}

};

