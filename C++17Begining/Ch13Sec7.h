#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch13Sec7{
public:
	static void test1() {
		cout << "----------测试13_7: 重复的成员变量" << endl;

		MyBox13_7_1 box{ 1 };
		cout << box.total() << endl;

	}
};

