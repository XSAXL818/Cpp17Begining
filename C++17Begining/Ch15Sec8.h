#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch15Sec8{
public:
	static void test1() {
		cout << "----------����1: ��Դ��ȡ����ʼ��" << endl;
		fun15_8_1();

		fun15_8_2();
		

	}

	static void test2() {
		cout << "----------����2: ���ڶ�̬�ڴ�ı�׼RAII��" << endl;

		try {
			// Ҫ�ǳ����쳣,arr���ᱻ��ֵ
			auto arr = fun15_8_2_1();
		}
		catch (int i) {
			cout << i << endl;
		}

		MoreOops15_3_1_1* p = new BigOops15_3_1_1{};
		cout << typeid(*p).name() << endl;

		

	}

};

