#pragma once


#include <iostream>
#include "NeedClass.h"

using namespace std;
// �����£�Ϊʵ�ּ򵥣�������������ʵ�ַ���һ���ļ���


//Sec7��const�����const��Ա����
class Ch11Sec7{
public:

	//1 const��Ա����
	static void test1() {
		cout << "-------���ԣ�const��Ա����\n";
		const Box7_1_1 b1{ 1,2,3 };
		//b1.setLength();// b1.��������κ���ʾ
		//b1.getLength();// �ú��������޸ĳ�Ա����������Ȼ�޷�����

		const Box7_1_2 b2{1,2,3 };
		cout << b2.getHeight() << endl;
	}

	//3 const����
	static void test3() {
		cout << "-------����7_3��const����\n";
		Box7_3_1 b1{ 1,2,3 };
		b1.a() = 3;// 
		cout << b1.a() << endl;

		const Box7_3_1 b2{ 1,2,3 };
		// b2.a() = 3;// �޷�����,���Ǹ�����
		// cout << b2.a() << endl; // ���Ǹ�����


		Box7_3_2 b3{ 1,2,3 };
		cout << b3.a() << endl;

		const Box7_3_2 b4{ 1,2,3 };
		cout << b4.a() << endl;
		// b4.a() = 4;// �޷�����,���Ǹ�����


	}

	static void test4() {
		cout << "-------����7_4��������ǿ��ת��\n";

		const Box7_3_2 b1{ 1,2,3 };
		Box7_3_2& rb = const_cast<Box7_3_2&>(b1);
		rb.a() = 3;
		cout << b1.a() << endl;
		cout << rb.a() << endl;
		cout << &b1 << endl;
		cout << &rb << endl;

	}


	static void test5() {
		cout << "-------����7_5��ʹ��mutable�ؼ���\n";

		const Log7_5 log;
		log.write("Hello, world!");

		log.write("����!");



	}


};

