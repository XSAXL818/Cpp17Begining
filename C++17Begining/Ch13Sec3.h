#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch13Sec3{
public:
	static void test1() {
		cout << "----------����12_13: ʹ��protected���λ����Ա" << endl;

		MyBox13_3_1_public mBox1(1, 2, 3);
		// protected���λ���ĳ�Ա��ֻ����������ĳ�Ա��������
		//mBox1.height = 3;

	}
};

