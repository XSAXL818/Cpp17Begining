#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;
// 测试章：为实现简单，类的声明和类的实现放在一个文件中

class Ch11Sec12{
public:
	static void test1() {
		cout << "测试11_12：析构函数" << endl;
		Box11_11_12_1 b1;

		Box11_11_12_1 b2{ 2 };

		cout << "当前对象数：" << Box11_11_12_1::objCnt << endl;

		cout << "创建数组:" << endl;
		Box11_11_12_1 arr[3] = { b1, b2 };
		cout << "每次循环创建一个对象" << endl;
		for (Box11_11_12_1 b : arr) {
			b.print();
		}
		

		cout << "每次循环不会创建对象" << endl;
		for (const Box11_11_12_1& b : arr) {
		}

		cout << "函数结束前存在对象：" << Box11_11_12_1::objCnt << endl;
	}
};

