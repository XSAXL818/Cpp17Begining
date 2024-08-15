#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch13Sec8{
public:
	static void test1() {
		cout << "----------测试13_8: 重复的成员函数" << endl;

		MyBox13_8_1 box;
		box.doDouble();
		box.doDouble(3);


		cout << "-----------派生类重载基类的成员函数----------------" << endl;

		MyBox13_8_2 box2;
		box2.doDouble(3);
	}

};

