#pragma once

#include <iostream>
#include "NeedClass.h"

class Ch16Sec4{
public:
	static void test1() {

		vector vec{ 1,3,4 };
		for( auto i : vec){
			cout << i << endl;
		}

	}
};

