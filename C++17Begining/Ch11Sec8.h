#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;
// �����£�Ϊʵ�ּ򵥣�������������ʵ�ַ���һ���ļ���


// ȫ�ֺ���
void toCube(Box8_1_1& box) {
	box.w = box.l = box.h = 3;
}
// �ú�������ʧ�ܣ���ΪBox�ĳ�Ա������private��
//void toCube1(Box8_1_1& box) {
//	box.w = box.l;
//	box.h = box.l;
//}

void BoxFridend::toCubeFridend(Box8_1_1& box) {
	box.h = box.w = box.l = 10;
}

class Fri {
public:
	static void toCube(Box8_2& box) {
		box.l = box.w = box.h = 10;
	};
};


class Ch11Sec8{
public:
	static void test1() {
		cout << "---------����8_1�������Ԫ����\n";
		Box8_1_1 b{ 1,3,4 };
		b.print();
		toCube(b);
		b.print();

		BoxFridend::toCubeFridend(b);
		b.print();
	}


	static void test2() {
		cout << "---------����8_2����Ԫ��\n";
		Box8_2 b{ 1,3,4 };
		b.print();

		Fri::toCube(b);
		b.print();

	}
};

