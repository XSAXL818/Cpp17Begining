#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;

class Ch13Sec2{
public:
	static void test1() {
		cout << "----------����13_1: ��ʼ�������˽�г�Ա" << endl;
		MyBox13_1_1_public box1(1, 2, 3);
		cout << box1.getVolume() << endl;
	}
};

