#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;
// �����£�Ϊʵ�ּ򵥣�������������ʵ�ַ���һ���ļ���

//int MyVector::m_a{ 0 };

class Ch11Sec10
{
public:
	static void test1() {
		cout << "����11_11�������Ĵ�С" << endl;
		vector<int> v1{ 4 };
		vector<int> v2{ 100,0 };
		MyVector vec1{ v1 };
		MyVector vec2{ v2 };

		cout << sizeof(v1) << endl;
		cout << sizeof(vec1) << endl;
		cout << sizeof(v2) << endl;
		cout << sizeof(vec2) << endl;

		cout << vec2.m_a << endl;

		//int MyVector::m_b{ 1 };// ������

	}

};

