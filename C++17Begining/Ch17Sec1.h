#pragma once
#include <iostream>
#include <type_traits>
#include "NeedClass.h"
using namespace std;
// �����£�Ϊʵ�ּ򵥣�������������ʵ�ַ���һ���ļ���



class Ch17Sec1 {
public:
	// Sec1����ֵ����ֵ
	static void test0() {
		auto obj1 = MyClass17_1::createObject();
		cout << "���ܼ����Ƹ���ֵ��" << endl;
		printTypeInfo(obj1);
		const MyClass17_1& obj2 = MyClass17_1::createObject();
		cout << "ʹ��const���ý��ܣ������Ƹö���" << typeid(obj2).name() << endl;
		printTypeInfo(obj2);

		// ����3+4�Ľ���ı���
		int&& x = 3 + 4;
		cout << "��ֵ���ã�" << typeid(x).name() << endl;

	}
	// Sec2���ƶ�����
	static void test1() {

	}

	// Sec6��thisָ��
	static void test2() {

	}

};

