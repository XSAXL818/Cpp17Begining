#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch14Sec4{
public:
	static void test1() {
		cout << "----------测试14_4: 纯虚函数" << endl;

		cout << "^^^^^^^^^^^^^^测试14_4_1: 抽象类" << endl;
		ABox14_4_1 box1{ 4 };
		cout << "volume: " << box1.volume() << endl;
		Box14_4_1* pBox = &box1;
		cout << "volume: " << pBox->volume() << endl;
		// 不可以调用未定义的函数
		//cout << "volume: " << box1.Box14_4_1::volume() << endl;

		cout << "^^^^^^^^^^^^^^测试14_4_1: 抽象类作接口" << endl;
		Car14_4_1 car;
		Mover14_4_1 mover{ &car };
		mover.go("斐济");


	}
};

