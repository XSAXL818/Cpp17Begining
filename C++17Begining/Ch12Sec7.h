#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;

class Ch12Sec7
{
public:
	static void test1() {
		cout << "����12_7: һԪ���������" << endl;

		Matrix12_7 m1{ 1,3 };

		cout << m1.getRow() << " " << m1.getCol() << endl;

		Matrix12_7 m2 = ~m1;
		cout << m2.getRow() << " " << m2.getCol() << endl;

		m2 = !m1;
		cout << m2.getRow() << " " << m2.getCol() << endl;

	}
};

