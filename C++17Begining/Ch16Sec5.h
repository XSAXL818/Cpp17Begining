#pragma once
#include <iostream>
#include "NeedClass.h"
class Ch16Sec5{
public:
	static void test0() {
		cout << "----------����0: �����͵���ģ�����" << endl;
		Array16_5_1<int, 5> arr1{ 4 };
		arr1.println();



	}
	static void test1() {
		cout << "----------����1: �ǲ������͵�ʵ�β�ͬ����������಻ͬ" << endl;
		Class16_5_1<int,1> c1;
		Class16_5_1<int, 2> c2;
		Class16_5_1<int, 2> c3;

		cout << &c1.a << endl;
		cout << &c2.a << endl;
		cout << &c3.a << endl;
		c1.f1();
	}

	static void test2() {
		cout << "----------����1: �����Ͳ�����ʵ��" << endl;
		int a = 3;
		const int b = 3;
		// a���ǳ������޷�ͨ������
		//Class16_5_1<int, a> arr1;
		Class16_5_1<int, b> arr1;

	
		cout << "----------����2: �Աȷ�����ģ��ʵ���빹�캯��ʵ��" << endl;
		Class16_5_1<int, 0> c1;
		Class16_5_1<int, 1> c2;
		//c1 = c2;// ����һ�����͵Ķ���
	}





};

