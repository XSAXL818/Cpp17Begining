#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;

class Ch12Sec12
{
public:
	static void test1() {
		cout << "----------����12_12: ʵ�ָ��Ƹ�ֵ�����" << endl;
		Msg12_12_1 msg1{ "haha" };
		//Msg12_12_1 msg2 = msg1;// ���õ��Ǹ������캯��
		Msg12_12_1 msg2;
		msg2 = msg1;

		msg1.setTxt("����");
		cout << msg1.getTxt() << endl;
		cout << msg2.getTxt() << endl;

		//msg2 = msg2;// ����bug
		msg2 = msg2;

	}
	static void test2() {
		cout << "----------����12_12: ���Ƹ�ֵ������͸������캯��" << endl;
		Msg12_12_1 msg1{ "haha" };
		Msg12_12_1 msg2 = msg1;// ���õ��Ǹ������캯��
		msg2 = msg1;// ���Ƹ�ֵ�����
	


	}

	static void test3() {
		cout << "----------����12_12: ��ֵ��ͬ����" << endl;

		Msg12_12_2 m1{ "12" };
		cout << m1.getMsg() << endl;
		m1 = "345";
		cout << m1.getMsg() << endl;

	}
};

