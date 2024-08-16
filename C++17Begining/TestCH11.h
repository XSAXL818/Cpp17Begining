#pragma once
#include <iostream>
#include "Ch11Sec5.h"
#include "Ch11Sec7.h"
#include "Ch11Sec8.h"
#include "Ch11Sec9.h"
#include "Ch11Sec10.h"
#include "Ch11Sec11.h"
#include "Ch11Sec12.h"
#include "Ch11Sec13.h"
#include "Ch11Sec14.h"
#include "BaseCharpter.h"


using namespace std;



// 第11章，定义自己的数据类型

class TestCH11{
public:
	static void allTest() {
		BaseCharpter::setSection(4);
		//cout << "******************** Sec4：副本构造函数 *************************" << endl;
		BaseCharpter::showSectionTitle("副本构造函数");
		Ch11Sec5::test0();

		//cout << "******************** Sec5：访问私有类成员 *************************" << endl;
		BaseCharpter::showSectionTitle("访问私有类成员");
		Ch11Sec5::test1();

		//cout << "\n\n******************** Sec6：this指针 *************************" << endl;
		BaseCharpter::showSectionTitle("this指针");
		Ch11Sec5::test2();

		//cout << "\n\n******************** Sec7：const对象和const成员函数 *************************" << endl;
		BaseCharpter::showSectionTitle("const对象和const成员函数");
		Ch11Sec7::test1();
		Ch11Sec7::test3();
		Ch11Sec7::test4();
		Ch11Sec7::test5();

		//cout << "\n\n******************** Sec8：友元 *************************" << endl;
		BaseCharpter::showSectionTitle("友元");
		Ch11Sec8::test1();
		Ch11Sec8::test2();

		//cout << "\n\n******************** Sec9：类的对象数组 *************************" << endl;
		BaseCharpter::showSectionTitle("类的对象数组");
		Ch11Sec9::test1();

		//cout << "\n\n******************** Sec10：类对象的大小 *************************" << endl;
		BaseCharpter::showSectionTitle("类对象的大小");
		Ch11Sec10::test1();

		//cout << "\n\n******************** Sec11：类的静态成员 *************************" << endl;
		BaseCharpter::showSectionTitle("类的静态成员");
		Ch11Sec11::test1();
		Ch11Sec11::test2();
		Ch11Sec11::test3();
		Ch11Sec11::test4();
		Ch11Sec11::test5();

		//cout << "\n\n******************** Sec12：析构函数 *************************" << endl;
		BaseCharpter::showSectionTitle("析构函数");
		Ch11Sec12::test1();


		//cout << "\n\n******************** Sec13：类的静态成员 *************************" << endl;
		BaseCharpter::showSectionTitle("类的静态成员");
		Ch11Sec13::test1();


		//cout << "\n\n******************** Sec14：嵌套类 *************************" << endl;
		BaseCharpter::showSectionTitle("嵌套类");
		Ch11Sec14::test1();

		



	}
};

