#pragma once
#include "NeedClass.h"
#include <iostream>

using namespace std;





class Ch12Sec4
{
public:
	static void test1() {
		Box12_4_1 b{ 1,2,3 };
		b.operator<<(cout) << endl;
		b << cout << endl;

		cout << b << endl;

	}

};

