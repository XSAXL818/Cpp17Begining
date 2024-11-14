#pragma once
#include <iostream>
#include "NeedClass.h"
class Ch16Sec8{
public:
	static void test1() {
		cout << "----------测试1:定义类模板特化" << endl;


		Array16_8_1<int> c;
		c.a = 3;
		c.b = 4;
		cout << c.getMax() << endl;

		Array16_8_1<char*> c1;
		char str[] = "123";
		c1.a = str;
		c1.b = str;
		cout << c1.getMax() << endl;

	}
};

