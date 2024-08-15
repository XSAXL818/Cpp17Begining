#pragma once

#include "Ch12Sec1.h"
#include "Ch12Sec2.h"
#include "Ch12Sec3.h"
#include "Ch12Sec4.h"
#include "Ch12Sec5.h"
#include "Ch12Sec6.h"
#include "Ch12Sec7.h"
#include "Ch12Sec8.h"
#include "Ch12Sec9.h"
#include "Ch12Sec10.h"
#include "Ch12Sec11.h"
#include "Ch12Sec12.h"

#include <iostream>
using namespace std;




class TestCh12
{
public:
	static void allTest() {

		cout << "******************** Sec1：为类实现运算符 *************************" << endl;
		Ch12Sec1::test1();
		Ch12Sec1::test2();
		Ch12Sec1::test3();
		Ch12Sec1::test4();
		Ch12Sec1::test5();


		cout << "******************** Sec4：为输出流重载<<运算符 *************************" << endl;
		Ch12Sec4::test1();


		cout << "******************** Sec5：重载算符运算符 *************************" << endl;
		Ch12Sec5::test1();
		Ch12Sec5::test2();


		cout << "******************** Sec6：成员和非成员函数 *************************" << endl;
		Ch12Sec6::test1();


		cout << "******************** Sec7：一元运算符重载 *************************" << endl;
		Ch12Sec7::test1();


		cout << "******************** Sec8：重载递增和递减运算符 *************************" << endl;
		Ch12Sec8::test1();


		cout << "******************** Sec9：重载数组下标运算符[] *************************" << endl;
		Ch12Sec9::test1();

		cout << "******************** Sec10：重载数组下标运算符[] *************************" << endl;
		Ch12Sec10::test1();

		cout << "******************** Sec11：重载类型转换 *************************" << endl;
		Ch12Sec11::test1();

		cout << "******************** Sec12：重载赋值运算符 *************************" << endl;
		Ch12Sec12::test1();
		Ch12Sec12::test2();
		Ch12Sec12::test3();

	



	}

};

