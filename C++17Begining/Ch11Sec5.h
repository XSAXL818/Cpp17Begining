#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;
// �����£�Ϊʵ�ּ򵥣�������������ʵ�ַ���һ���ļ���



class Ch11Sec5{
public:
	// Sec4���������캯��
	static void test0() {
		Box4_9_1 b1{ 1,2,3 };
		Box4_9_1 b2{ b1 };// δ��ʽ���帱�����캯��������ָ���Ա�����з���

		Box4_9_2 b3{ 1,2,3 };
		Box4_9_2 b4{ b3 };

		MyOops m1{ new int{ 1 } };
		MyOops m2{ m1 };

		*m2.ptr = 3;
		m1.print();
		m2.print();

		m1.p(m1);
	}
	// Sec5������˽�����Ա
	static void test1() {
		Box5 b;
		cout << b.getSide() << endl;
		b.setSide(-1);
		cout << b.getSide() << endl;
		b.setSide(2);
		cout << b.getSide() << endl;
	}

	// Sec6��thisָ��
	static void test2(){
		
		This t;
		cout << "t����ĵ�ַ��" << &t << endl;
		t.setA(1)->setB(2).setC(5);
		t.print();
	}

};

