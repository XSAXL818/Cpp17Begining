#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;
// 测试章：为实现简单，类的声明和类的实现放在一个文件中


// 全局函数
void toCube(Box8_1_1& box) {
	box.w = box.l = box.h = 3;
}
// 该函数编译失败，因为Box的成员变量是private的
//void toCube1(Box8_1_1& box) {
//	box.w = box.l;
//	box.h = box.l;
//}

void BoxFridend::toCubeFridend(Box8_1_1& box) {
	box.h = box.w = box.l = 10;
}

class Fri {
public:
	static void toCube(Box8_2& box) {
		box.l = box.w = box.h = 10;
	};
};


class Ch11Sec8{
public:
	static void test1() {
		cout << "---------测试8_1：类的友元函数\n";
		Box8_1_1 b{ 1,3,4 };
		b.print();
		toCube(b);
		b.print();

		BoxFridend::toCubeFridend(b);
		b.print();
	}


	static void test2() {
		cout << "---------测试8_2：友元类\n";
		Box8_2 b{ 1,3,4 };
		b.print();

		Fri::toCube(b);
		b.print();

	}
};

