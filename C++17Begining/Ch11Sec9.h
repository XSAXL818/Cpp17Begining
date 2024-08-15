#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;
// 测试章：为实现简单，类的声明和类的实现放在一个文件中

class Ch11Sec9
{
public:
	static void test1() {
		Cube9 c{ 2 };
		cout << endl;
		Cube9 cubes[3] = { c, Cube9{3} };

	}
};

