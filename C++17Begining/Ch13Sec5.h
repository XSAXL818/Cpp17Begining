#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch13Sec5{
public:
	static void test1() {
		cout << "----------����13_5_1: " << endl;
		Box13_5_1_3 b;

		cout << endl;
		cout << "----------������ʵ������ʾ���û���ĸ������캯��(�ֶ�ʵ��) " << endl;
		MyBox13_6_1_1 box1(1, 2, 3);
		MyBox13_6_1_1 box2 = box1;
		cout << "box2: " << box2.volume() << endl;

		cout << "----------�����������ĸ������캯��ȫ�ɱ������ṩ " << endl;
		MyBox13_6_1_2 box3(1, 2, 3);
		MyBox13_6_1_2 box4 = box3;
		cout << box4.volume() << endl;

		cout << "----------������ʵ����û����ʾ���û���ĸ������캯�� " << endl;
		MyBox13_6_1_3 box5(1, 2, 3);
		MyBox13_6_1_3 box6 = box5;
		cout << box6.volume() << endl;

	}

	static void test2() {
		// �޷���ʼ��
		//MyBox13_5_2_1 box1;


	}
	static void test3() {
		cout << "----------����13_5_3: " << endl;
		MyBox13_5_3_1 box1{ 1,2 };
		MyBox13_5_3_1 box2;
	}
	

};

