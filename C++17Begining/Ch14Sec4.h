#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch14Sec4{
public:
	static void test1() {
		cout << "----------����14_4: ���麯��" << endl;

		cout << "^^^^^^^^^^^^^^����14_4_1: ������" << endl;
		ABox14_4_1 box1{ 4 };
		cout << "volume: " << box1.volume() << endl;
		Box14_4_1* pBox = &box1;
		cout << "volume: " << pBox->volume() << endl;
		// �����Ե���δ����ĺ���
		//cout << "volume: " << box1.Box14_4_1::volume() << endl;

		cout << "^^^^^^^^^^^^^^����14_4_1: ���������ӿ�" << endl;
		Car14_4_1 car;
		Mover14_4_1 mover{ &car };
		mover.go("쳼�");


	}
};

