#pragma once


#include <iostream>
#include "NeedClass.h"

using namespace std;

class Ch12Sec8
{
public:
	static void test1() {
		cout << "����12_8: ���ص����͵ݼ������" << endl;
		Cube12_8 c1{ 1 };
		cout << c1.side << endl;
		cout << (c1++).side << endl;
		cout << c1.side << endl;
		++c1;
		cout << c1.side << endl;

	}




};

