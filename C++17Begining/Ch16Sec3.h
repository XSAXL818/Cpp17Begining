#pragma once

#include <iostream>
#include "NeedClass.h"

class Ch16Sec3{
public:
	static void test1() {
		cout << "----------����1: ���캯��ģ��" << endl;

		size_t size{ 4 };
		MyArray16_3_1<int> arr{ size };
		MyArray16_3_1<int> arr1{ arr };


		cout << "----------����3: ���������±�[]�����" << endl;
		cout << "\n��const�±�[]�����\n";
		arr[0] = 123213;
		for (int i = 0; i < size; i++) {
			cout << ++arr[i] << endl;
			cout << arr1[i] << endl;
		}
		cout << "\nconst�±�[]�����\n";
		const MyArray16_3_1<int> arr2 = arr1;
		for (int i = 0; i < size; i++) {
			cout << arr2[i] << endl;
		}

		cout << "----------����4: ��constʵ��const" << endl;
		const Test16_3_3_1 t1;
		cout << "const " << endl;
		auto e = t1[3];

		cout << "----------����5: constʵ�ַ�const" << endl;
		Test16_3_3_2 t2;
		cout << "��const " << endl;
		auto e2 = t2[3];

		cout << "const " << endl;
		const Test16_3_3_2 t3;
		auto e3 = t3[3];

		
		cout << "----------����6: ��ֵ�����ģ��" << endl;
		Array16_3_4<int> arr3{ 4 };
		arr3[0] = 10;
		arr3[1] = 100;
		arr3[2] = 999;
		arr[3] = 4;
		Array16_3_4<int> arr4{ 2 };
		arr4 = arr3;
		arr3.println();
		arr4.println();
		arr3[0] = 122231;
		swap(arr3, arr4);
		arr3.println();
		arr4.println();


		cout << "\n����6�� end ---------------------\n";



	}

};

