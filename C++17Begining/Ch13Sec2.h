#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;

class Ch13Sec2{
public:
	static void test1() {
		cout << "----------测试13_1: 初始化基类的私有成员" << endl;
		MyBox13_1_1_public box1(1, 2, 3);
		cout << box1.getVolume() << endl;
	}
};

