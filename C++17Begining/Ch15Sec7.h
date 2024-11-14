#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch15Sec7 {
public:
	static void test1() {
		cout << "----------测试1: noexcept限定符" << endl;
		cout << "noexcept函数内捕获异常" << endl;
		Class15_7_1_1::fun();

		cout << "noexcept函数内未成功捕获异常" << endl;
		Class15_7_1_1::fun_except();


	}


	static void test2() {
		cout << "----------测试2: 异常和析构函数" << endl;
		//Class15_7_2_1 a;// 会test2代码执行完后终止程序

		try {
			Class15_7_2_2 b;
		}
		catch (int a) {
			cout << a << endl;
		}
	}


};