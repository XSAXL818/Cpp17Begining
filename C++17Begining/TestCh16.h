#pragma once

#include <iostream>
#include "NeedClass.h"
#include "BaseCharpter.h"
#include "Ch16Sec1.h"
#include "Ch16Sec2.h"
#include "Ch16Sec3.h"
#include "Ch16Sec4.h"
#include "Ch16Sec5.h"
#include "Ch16Sec6.h"
#include "Ch16Sec7.h"
#include "Ch16Sec8.h"
#include "Ch16Sec9.h"
#include "Ch16Sec10.h"


class TestCh16
{
public:

	static void allTest() {
		BaseCharpter::section = 2;
		BaseCharpter::showSectionTitle("定义类模板");
		Ch16Sec2::test2();
		
		BaseCharpter::showSectionTitle("定义类模的成员函数");
		Ch16Sec3::test1();

		BaseCharpter::showSectionTitle("创建类模板的实例");
		Ch16Sec4::test1();

		BaseCharpter::showSectionTitle("非类型的类模板参数");
		Ch16Sec5::test0();
		Ch16Sec5::test1();
		Ch16Sec5::test2();

		BaseCharpter::section = 7;
		BaseCharpter::showSectionTitle("模板的显式实例化");
		Ch16Sec7::test1();


		BaseCharpter::showSectionTitle("类模板特化");
		Ch16Sec8::test1();




	}
	
};

