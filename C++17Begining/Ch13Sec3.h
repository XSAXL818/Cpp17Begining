#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch13Sec3{
public:
	static void test1() {
		cout << "----------测试12_13: 使用protected修饰基类成员" << endl;

		MyBox13_3_1_public mBox1(1, 2, 3);
		// protected修饰基类的成员，只能在派生类的成员函数访问
		//mBox1.height = 3;

	}
};

