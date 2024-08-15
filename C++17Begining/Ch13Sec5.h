#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch13Sec5{
public:
	static void test1() {
		cout << "----------测试13_5_1: " << endl;
		Box13_5_1_3 b;

		cout << endl;
		cout << "----------派生类实现中显示调用基类的副本构造函数(手动实现) " << endl;
		MyBox13_6_1_1 box1(1, 2, 3);
		MyBox13_6_1_1 box2 = box1;
		cout << "box2: " << box2.volume() << endl;

		cout << "----------基类和派生类的副本构造函数全由编译器提供 " << endl;
		MyBox13_6_1_2 box3(1, 2, 3);
		MyBox13_6_1_2 box4 = box3;
		cout << box4.volume() << endl;

		cout << "----------派生类实现中没有显示调用基类的副本构造函数 " << endl;
		MyBox13_6_1_3 box5(1, 2, 3);
		MyBox13_6_1_3 box6 = box5;
		cout << box6.volume() << endl;

	}

	static void test2() {
		// 无法初始化
		//MyBox13_5_2_1 box1;


	}
	static void test3() {
		cout << "----------测试13_5_3: " << endl;
		MyBox13_5_3_1 box1{ 1,2 };
		MyBox13_5_3_1 box2;
	}
	

};

