#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;

class Ch12Sec9
{
public:

	static void test1() {
		cout << "²âÊÔ12_9: ÖØÔØ[]ÔËËã·û" << endl;

		vector<int> v1 = { 1, 2, 3, 4, 5 };
		vector<int> v2 = { 10, 20, 30, 40, 50 };
		vector<int> v3 = { 100, 200, 300, 400, 500 };
		vector<vector<int>> vec{v1, v2, v3};

		Matrix12_9 m1(vec);

		cout << vec[0][1] << endl;




	}
};

