#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;



class Ch12Sec11
{
public:

	static void f1(Cube12_10_1 c) {
		cout << c.getVolume() << endl;
	}
	static void test1() {
		cout << "����12_11_1: ��������ת��" << endl;

		Box12_10_1 box(10);
		int volume = box;
		cout << "Volume of Box : " << volume << endl;
		Cube12_10_1 c1 = box;
		cout << "Volume of Cube : " << c1.getVolume() << endl;

		cout << "����12_11_2: ת����ģ����" << endl;

		Box12_10_1 b1{ 20 };
		f1( b1 );
		f1({ b1 });

	}

};

