#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;
// �����£�Ϊʵ�ּ򵥣�������������ʵ�ַ���һ���ļ���

class Ch11Sec12{
public:
	static void test1() {
		cout << "����11_12����������" << endl;
		Box11_11_12_1 b1;

		Box11_11_12_1 b2{ 2 };

		cout << "��ǰ��������" << Box11_11_12_1::objCnt << endl;

		cout << "��������:" << endl;
		Box11_11_12_1 arr[3] = { b1, b2 };
		cout << "ÿ��ѭ������һ������" << endl;
		for (Box11_11_12_1 b : arr) {
			b.print();
		}
		

		cout << "ÿ��ѭ�����ᴴ������" << endl;
		for (const Box11_11_12_1& b : arr) {
		}

		cout << "��������ǰ���ڶ���" << Box11_11_12_1::objCnt << endl;
	}
};

