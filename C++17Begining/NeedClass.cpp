#include "NeedClass.h"
#include <iostream>



int Static11_11_1_1::cnt{ 0 };

double CylindricalBox11_11_3::volume() const
{
	return PI * radius * radius * height;
}


Cube12_10_1::Cube12_10_1(const Box12_10_1& box) : side{ box.getSide() } {
	cout << "Cube���캯��\n";
}


void Box14_3_1::outsideFun() {
	cout << "��Դ�ļ��ж����麯��" << endl;
}