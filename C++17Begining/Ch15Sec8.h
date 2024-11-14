#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch15Sec8{
public:
	static void test1() {
		cout << "----------测试1: 资源获取即初始化" << endl;
		fun15_8_1();

		fun15_8_2();
		

	}

	static void test2() {
		cout << "----------测试2: 用于动态内存的标准RAII类" << endl;

		try {
			// 要是出现异常,arr不会被赋值
			auto arr = fun15_8_2_1();
		}
		catch (int i) {
			cout << i << endl;
		}

		MoreOops15_3_1_1* p = new BigOops15_3_1_1{};
		cout << typeid(*p).name() << endl;

		

	}

};

