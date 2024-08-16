#pragma once


#include "Ch13Sec1.h"
#include "Ch13Sec2.h"
#include "Ch13Sec3.h"
#include "Ch13Sec4.h"
#include "Ch13Sec5.h"
#include "Ch13Sec6.h"
#include "Ch13Sec7.h"
#include "Ch13Sec8.h"
#include "Ch13Sec9.h"
#include "Ch13Sec10.h"
#include "BaseCharpter.h"

#include <iostream>
using namespace std;



class TestCh13{
public:
	static void allTest() {
		BaseCharpter::setSection(2);
		//cout << "******************** Sec2：类的继承 *************************" << endl;
		BaseCharpter::showSectionTitle("类的继承");
		Ch13Sec2::test1();

		//cout << "******************** Sec3：把类的成员声明为protected *************************" << endl;
		BaseCharpter::showSectionTitle("把类的成员声明为protected");
		Ch13Sec3::test1();
		
		//cout << "******************** Sec4：派生类成员的访问级别 *************************" << endl;
		BaseCharpter::showSectionTitle("派生类成员的访问级别");
		Ch13Sec4::test1();


		//cout << "******************** Sec5：派生类中的构造函数 *************************" << endl;
		BaseCharpter::showSectionTitle("派生类中的构造函数");
		Ch13Sec5::test1();
		Ch13Sec5::test2();
		Ch13Sec5::test3();

		//cout << "******************** Sec6：继承中的析构函数 *************************" << endl;
		BaseCharpter::showSectionTitle("继承中的析构函数");
		Ch13Sec6::test1();

		//cout << "******************** Sec7：重复的成员变量名 *************************" << endl;
		BaseCharpter::showSectionTitle("重复的成员变量名");
		Ch13Sec7::test1();

		//cout << "******************** Sec8：重复的成员函数名 *************************" << endl;
		BaseCharpter::showSectionTitle("重复的成员函数名");
		Ch13Sec8::test1();

		//cout << "******************** Sec9：多重继承 *************************" << endl;
		BaseCharpter::showSectionTitle("多重继承");
		Ch13Sec9::test1();

		//cout << "******************** Sec10：相关的类类型之间转换 *************************" << endl;
		BaseCharpter::showSectionTitle("相关的类类型之间转换");
		Ch13Sec10::test1();





	}
};

