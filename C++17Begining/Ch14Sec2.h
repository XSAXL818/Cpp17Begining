#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch14Sec2{
public:
	static void test1() {
		cout << "----------测试14_2: 多态引发的成本" << endl;
		cout << sizeof(Box14_2_1) << endl;
		cout << sizeof(Box14_2_2) << endl;


	}
};

