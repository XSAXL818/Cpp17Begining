#pragma once
#include <iostream>

using namespace std;

class Ch12Sec5
{
public:
	static void test1() {
		cout << "����12_5: +���������" << endl;
		Cube12_5_1 c1{ 4.0 };
		Cube12_5_1 c2{ 3.0 };

		Cube12_5_1 c3 = c1 + c2;
		cout << c1.getVolume() << endl;
		cout << c2.getVolume() << endl;
		cout << c3.getVolume() << endl;
	}

	static void test2() {
		cout << "����12_5: +ʹ��+=ʵ��+�����" << endl;
		Cube12_5_2 c1{ 3 };
		Cube12_5_2 c2{ 4 };

		Cube12_5_2 c3{ 0 };
		c3 += (c1 + c2);
		cout << c1.getVolume() << endl;
		cout << c2.getVolume() << endl;
		cout << c3.getVolume() << endl;
	}
};

