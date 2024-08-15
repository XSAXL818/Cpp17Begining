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

#include <iostream>
using namespace std;



class TestCh13{
public:
	static void allTest() {
		cout << "******************** Sec2：初始化基类的成员 *************************" << endl;
		Ch13Sec2::test1();

		cout << "******************** Sec3：使用protected修饰基类成员 *************************" << endl;
		Ch13Sec3::test1();
		
		cout << "******************** Sec4：改变继承成员的访问修饰符 *************************" << endl;
		Ch13Sec4::test1();


		cout << "******************** Sec5：派生类中的构造函数 *************************" << endl;
		Ch13Sec5::test1();
		Ch13Sec5::test2();
		Ch13Sec5::test3();

		cout << "******************** Sec6：继承中的析构函数 *************************" << endl;
		Ch13Sec6::test1();

		cout << "******************** Sec7：为类实现运算符 *************************" << endl;
		Ch13Sec7::test1();

		cout << "******************** Sec8：为类实现运算符 *************************" << endl;
		Ch13Sec8::test1();

		cout << "******************** Sec9：为类实现运算符 *************************" << endl;
		Ch13Sec9::test1();

		cout << "******************** Sec10：为类实现运算符 *************************" << endl;
		Ch13Sec10::test1();





	}
};

