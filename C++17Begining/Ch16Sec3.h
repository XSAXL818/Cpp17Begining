#pragma once

#include <iostream>
#include "NeedClass.h"

class Ch16Sec3{
public:
	static void test1() {
		cout << "----------测试1: 构造函数模板" << endl;

		size_t size{ 4 };
		MyArray16_3_1<int> arr{ size };
		MyArray16_3_1<int> arr1{ arr };


		cout << "----------测试3: 重载数组下标[]运算符" << endl;
		cout << "\n非const下标[]运算符\n";
		arr[0] = 123213;
		for (int i = 0; i < size; i++) {
			cout << ++arr[i] << endl;
			cout << arr1[i] << endl;
		}
		cout << "\nconst下标[]运算符\n";
		const MyArray16_3_1<int> arr2 = arr1;
		for (int i = 0; i < size; i++) {
			cout << arr2[i] << endl;
		}

		cout << "----------测试4: 非const实现const" << endl;
		const Test16_3_3_1 t1;
		cout << "const " << endl;
		auto e = t1[3];

		cout << "----------测试5: const实现非const" << endl;
		Test16_3_3_2 t2;
		cout << "非const " << endl;
		auto e2 = t2[3];

		cout << "const " << endl;
		const Test16_3_3_2 t3;
		auto e3 = t3[3];

		
		cout << "----------测试6: 赋值运算符模板" << endl;
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


		cout << "\n测试6： end ---------------------\n";



	}

};

