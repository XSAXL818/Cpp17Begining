#pragma once

#include <string>
#include <iostream>
#include <vector>
using namespace std;




class Ch12Sec1
{
public:
	static void test1(){
		cout << "\n测试12_1_1：标准库中运算符的重载\n";


		string s1{ "123" };
		string s2{ "234" };

		cout << (s1 > s2) << endl;
	}

	static void test2() {
		cout << "\n测试12_1_2：实现重载运算符\n";
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
		cout << "\n测试12_1_3：非成员运算符函数\n";
		Cube12_1_3 c1{ 3 };
		Cube12_1_3 c2{ 4 };

		cout << (c1 < c2) << endl;
		cout << (c1 < 4) << endl;

		cout << operator<(c1, c2) << endl;
	
	}

	static void test4() {
		cout << "\n测试12_1_4：提供对运算符的全部支持\n";
		cout << "不提供explicit修饰\n";
		Cube12_1_4_1 c1{ 4 };
		Cube12_1_4_1 c2{ 5 };
		cout << (c1 < c2) << endl;
		cout << (c1 < 5) << endl;// 出现错误

		cout << "提供explicit修饰\n";
		Cube12_1_4_2 c3{ 4 };
		Cube12_1_4_2 c4{ 5 };
		cout << (c3 < c4) << endl;
		//cout << (c3 < 5) << endl;// 出现错误,不存在隐式转换，也没有重载

		cout << "提供全面支持\n";
		Cube12_1_4_3 c5{ 4 };
		Cube12_1_4_3 c6{ 5 };
		cout << (c5 < c6) << endl;
		cout << (c5 < 10) << endl;
		cout << (10 < c5) << endl;
		cout << (c5 < Double{3.0}) << endl;
		
	}

	static void test5() {
		cout << "\n测试12_1_5：在类中实现所有的比较运算符\n";
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

