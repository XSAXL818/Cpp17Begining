#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch15Sec4{
public:
	static void test1() {
		cout << "----------����14_1: ʹ�û���ָ��͵��ü̳еĺ���" << endl;

		cout << "�������\n";
		ABox14_1_1 aBox{ 3 };
		cout << "����aBox��volume()������" << aBox.volume() << endl;
		aBox.showVolume();

		cout << "ָ�����\n";
		Box14_1_1* pBox = &aBox;
		cout << "����aBox��volume()������" << pBox->volume() << endl;
		pBox->showVolume();

	}

};

