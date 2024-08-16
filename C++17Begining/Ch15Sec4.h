#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch15Sec4{
public:
	static void test1() {
		cout << "----------测试14_1: 使用基类指针和调用继承的函数" << endl;

		cout << "对象调用\n";
		ABox14_1_1 aBox{ 3 };
		cout << "调用aBox的volume()函数：" << aBox.volume() << endl;
		aBox.showVolume();

		cout << "指针调用\n";
		Box14_1_1* pBox = &aBox;
		cout << "调用aBox的volume()函数：" << pBox->volume() << endl;
		pBox->showVolume();

	}

};

