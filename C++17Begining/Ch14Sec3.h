#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch14Sec3{
public:
	static void test1() {
		cout << "----------����14_3: ȷ����̬����" << endl;
		ABox14_3_1_1 box1;
		ABox14_3_2_1 box2;

		Box14_3_1_1* pBox1{ &box1 };
		Box14_3_2_1* pBox2{ &box2 };

		cout << "ָ��ABox14_3_1_1����Ļ���ָ��  ��" << typeid(pBox1).name() << endl;
		cout << "ָ��ABox14_3_2_1����������ָ�룺" << typeid(pBox2).name() << endl;

		cout << "������ָ��ABox14_3_1_1����Ļ���ָ��  ��" << typeid(*pBox1).name() << endl;
		cout << "������ָ��ABox14_3_2_1����������ָ�룺" << typeid(*pBox2).name() << endl;

		Box14_3_2_1& rBox1{ box2 };
		cout << "��̬����ΪBox�����õĶ���������ABox14_3_2_1: " << typeid(rBox1).name() << endl;

		cout << "���طǶ�̬���͵ĺ�����" << typeid(getABox14_3_1_1()).name() << endl;
		cout << "���ض�̬���͵ĺ���  ��" << typeid(getABox14_3_2_1()).name() << endl;

	}
};

