#pragma once

#include <iostream>
#include "NeedClass.h"
#include "BaseCharpter.h"

#include "Ch15Sec1.h"
#include "Ch15Sec2.h"
#include "Ch15Sec3.h"
#include "Ch15Sec4.h"
#include "Ch15Sec5.h"
#include "Ch15Sec6.h"
#include "Ch15Sec7.h"
#include "Ch15Sec8.h"
#include "Ch15Sec9.h"


class TestCh15{
public:
	static void allTest() {
		
		BaseCharpter::section = 2;
		BaseCharpter::showSectionTitle("处理错误");
		Ch15Sec2::test1();
		Ch15Sec2::test2();
		Ch15Sec2::test3();


		BaseCharpter::showSectionTitle("用类对象作为异常");
		Ch15Sec3::test1();
		Ch15Sec3::test2();

		BaseCharpter::showSectionTitle("重新抛出异常");
		Ch15Sec4::test1();
		Ch15Sec4::test2();
		
		BaseCharpter::section = 7;
		BaseCharpter::showSectionTitle("noexcept 限定符");
		Ch15Sec7::test1();
		Ch15Sec7::test2();

		
		BaseCharpter::showSectionTitle("异常和资源泄漏");
		Ch15Sec8::test1();
		Ch15Sec8::test2();


	}




};

