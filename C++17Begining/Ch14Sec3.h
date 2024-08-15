#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch14Sec3{
public:
	static void test1() {
		cout << "----------测试14_3: 确定动态类型" << endl;
		ABox14_3_1_1 box1;
		ABox14_3_2_1 box2;

		Box14_3_1_1* pBox1{ &box1 };
		Box14_3_2_1* pBox2{ &box2 };

		cout << "指向ABox14_3_1_1对象的基类指针  ：" << typeid(pBox1).name() << endl;
		cout << "指向ABox14_3_2_1对象的虚基类指针：" << typeid(pBox2).name() << endl;

		cout << "解引用指向ABox14_3_1_1对象的基类指针  ：" << typeid(*pBox1).name() << endl;
		cout << "解引用指向ABox14_3_2_1对象的虚基类指针：" << typeid(*pBox2).name() << endl;

		Box14_3_2_1& rBox1{ box2 };
		cout << "静态类型为Box但引用的对象类型是ABox14_3_2_1: " << typeid(rBox1).name() << endl;

		cout << "返回非多态类型的函数：" << typeid(getABox14_3_1_1()).name() << endl;
		cout << "返回多态类型的函数  ：" << typeid(getABox14_3_2_1()).name() << endl;

	}
};

