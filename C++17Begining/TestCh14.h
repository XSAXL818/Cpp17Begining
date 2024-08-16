#pragma once


#include "Ch14Sec1.h"
#include "Ch14Sec2.h"
#include "Ch14Sec3.h"
#include "Ch14Sec4.h"
#include "BaseCharpter.h"


#include <iostream>
using namespace std;



class TestCh14{
public:
	static void allTest() {
		BaseCharpter::section = 1;
		//cout << "******************** Sec1：理解多态性 *************************" << endl;
		BaseCharpter::showSectionTitle("理解多态性");
		Ch14Sec1::test1();

		//cout << "******************** Sec2：多态性引发的成本 *************************" << endl;
		BaseCharpter::showSectionTitle("多态性引发的成本");
		Ch14Sec2::test1();

		//cout << "******************** Sec3：确定动态类型 *************************" << endl;
		BaseCharpter::showSectionTitle("确定动态类型");
		Ch14Sec3::test1();
		
		//cout << "******************** Sec4：纯虚函数 *************************" << endl;
		BaseCharpter::showSectionTitle("纯虚函数");
		Ch14Sec4::test1();

	}
};

