#pragma once

#include <iostream>
#include "BaseCharpter.h"
#include "Ch17Sec1.h"
#include "Ch17Sec2.h"
#include "Ch17Sec3.h"
#include "Ch17Sec4.h"
#include "Ch17Sec5.h"
#include "Ch17Sec6.h"
#include "Ch17Sec7.h"


class TestCh17
{
public:

	static void allTest() {
		BaseCharpter::section = 1;
		BaseCharpter::showSectionTitle("LvalueºÍRvalue");
		std::cout << "---------------------------" << std::endl;
		Ch17Sec1::test0();
		


	}

};