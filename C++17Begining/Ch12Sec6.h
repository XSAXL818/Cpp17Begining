#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;

class Ch12Sec6
{
public:
	static void test1() {
		cout << "测试12_16: 运算符函数和隐式转换" << endl;

		Integer12_6 i1{ 1 };
		Integer12_6 i2{ 3 };
		
		cout << (3 + i1).getValue() << endl;
		cout << (i1 + 3).getValue() << endl;

	}
};

