#pragma once


#include "Ch14Sec1.h"
#include "Ch14Sec2.h"
#include "Ch14Sec3.h"
#include "Ch14Sec4.h"


#include <iostream>
using namespace std;



class TestCh14{
public:
	static void allTest() {

		cout << "******************** Sec1：理解多态性 *************************" << endl;
		Ch14Sec1::test1();

		cout << "******************** Sec2：多态性引发的成本 *************************" << endl;
		Ch14Sec2::test1();

		cout << "******************** Sec3：确定动态类型 *************************" << endl;
		Ch14Sec3::test1();
		
		cout << "******************** Sec4：纯虚函数 *************************" << endl;
		Ch14Sec4::test1();

	}
};

