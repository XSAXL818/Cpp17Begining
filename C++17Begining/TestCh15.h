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
		BaseCharpter::section = 1;
		BaseCharpter::showSectionTitle("¥¶¿Ì¥ÌŒÛ");
		Ch15Sec1::test1();




	}
};

