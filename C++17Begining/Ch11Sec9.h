#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;
// �����£�Ϊʵ�ּ򵥣�������������ʵ�ַ���һ���ļ���

class Ch11Sec9
{
public:
	static void test1() {
		Cube9 c{ 2 };
		cout << endl;
		Cube9 cubes[3] = { c, Cube9{3} };

	}
};

