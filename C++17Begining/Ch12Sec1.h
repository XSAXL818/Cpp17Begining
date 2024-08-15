#pragma once

#include <string>
#include <iostream>
#include <vector>
using namespace std;




class Ch12Sec1
{
public:
	static void test1(){
		cout << "\n����12_1_1����׼���������������\n";


		string s1{ "123" };
		string s2{ "234" };

		cout << (s1 > s2) << endl;
	}

	static void test2() {
		cout << "\n����12_1_2��ʵ�����������\n";
		vector< Cube12_1_2> vec{ Cube12_1_2{1},Cube12_1_2 {3},Cube12_1_2 {9},Cube12_1_2{4} };
		
		if (vec.size() == 0) {
			return;
		}
		 
		Cube12_1_2 max{ vec[0] };
		for (const Cube12_1_2& c : vec) {
			if (max < c) {
				max = c;
			}
		}
		cout << "max = " << max.getVolume() << endl;

		max = vec[0];
		for (const Cube12_1_2& c : vec) {
			if (max.operator<(c.getVolume())) {
				max = c;
			}
		}
		cout << "max = " << max.getVolume() << endl;

	}

	static void test3() {
		cout << "\n����12_1_3���ǳ�Ա���������\n";
		Cube12_1_3 c1{ 3 };
		Cube12_1_3 c2{ 4 };

		cout << (c1 < c2) << endl;
		cout << (c1 < 4) << endl;

		cout << operator<(c1, c2) << endl;
	
	}

	static void test4() {
		cout << "\n����12_1_4���ṩ���������ȫ��֧��\n";
		cout << "���ṩexplicit����\n";
		Cube12_1_4_1 c1{ 4 };
		Cube12_1_4_1 c2{ 5 };
		cout << (c1 < c2) << endl;
		cout << (c1 < 5) << endl;// ���ִ���

		cout << "�ṩexplicit����\n";
		Cube12_1_4_2 c3{ 4 };
		Cube12_1_4_2 c4{ 5 };
		cout << (c3 < c4) << endl;
		//cout << (c3 < 5) << endl;// ���ִ���,��������ʽת����Ҳû������

		cout << "�ṩȫ��֧��\n";
		Cube12_1_4_3 c5{ 4 };
		Cube12_1_4_3 c6{ 5 };
		cout << (c5 < c6) << endl;
		cout << (c5 < 10) << endl;
		cout << (10 < c5) << endl;
		cout << (c5 < Double{3.0}) << endl;
		
	}

	static void test5() {
		cout << "\n����12_1_5��������ʵ�����еıȽ������\n";
		Cube12_1_5 c1{ 4 };
		Cube12_1_5 c2{ 5 };

		cout << (c1 < c2) << endl;
		cout << (c1 <= c2) << endl;
		cout << (c1 > c2) << endl;
		cout << (c1 >= c2) << endl;
		cout << (c1 == c2) << endl;
		cout << (c1 != c2) << endl;



	}

};

