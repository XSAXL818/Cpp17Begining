#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch15Sec7 {
public:
	static void test1() {
		cout << "----------����1: noexcept�޶���" << endl;
		cout << "noexcept�����ڲ����쳣" << endl;
		Class15_7_1_1::fun();

		cout << "noexcept������δ�ɹ������쳣" << endl;
		Class15_7_1_1::fun_except();


	}


	static void test2() {
		cout << "----------����2: �쳣����������" << endl;
		//Class15_7_2_1 a;// ��test2����ִ�������ֹ����

		try {
			Class15_7_2_2 b;
		}
		catch (int a) {
			cout << a << endl;
		}
	}


};