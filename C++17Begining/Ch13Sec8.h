#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch13Sec8{
public:
	static void test1() {
		cout << "----------����13_8: �ظ��ĳ�Ա����" << endl;

		MyBox13_8_1 box;
		box.doDouble();
		box.doDouble(3);


		cout << "-----------���������ػ���ĳ�Ա����----------------" << endl;

		MyBox13_8_2 box2;
		box2.doDouble(3);
	}

};

