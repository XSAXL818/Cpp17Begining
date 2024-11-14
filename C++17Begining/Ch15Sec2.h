#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch15Sec2{
public:
	static void test1() {
		cout << "---------测试：抛出异常---------" << endl;
		for (int i = 0; i < 6; i++) {
			try {
				if (i % 2 == 0) {
					throw "偶数";
				}
				cout << "未抛出偶数异常" << endl;
				if (i % 3 == 2) {
					throw 1;
				}
			}
			catch (const char* msg) {
				cout << "捕获异常：" << msg << endl;
				return;
			}
			catch (int i) {
				cout << "捕获异常：" << i << endl;
			}

			cout << "循环迭代一次" << endl;
		}
		cout << "---------测试结束---------" << endl;
	}

	static void test2() {
		cout << "\n---------测试：异常处理过程---------" << endl;
		for (int i = 0; i < 6; i++) {
			cout << "迭代: " << i << endl;
			try {
				Box15_2_2_1 box;
				if (i % 2 == 1) {
					// 不能抛出使用私有副本构造函数的类的对象
					/*Box15_2_2_2 box1{};
					throw box1;*/
					throw Box15_2_2_2{};
				}
			}
			catch (const char* msg) {
				cout << "捕获异常：" << msg << endl;
				return;
			}
			catch (Box15_2_2_2& box) {
				box.show();
			}
			cout << "try-catch结束" << endl;
		}
	}

	static void test3() {
		cout << "\n---------测试：导致抛出异常的代码---------" << endl;

		try {
			fun15_2_2_1();
			fun15_2_2_3();
		}
		catch (const char* msg) {
			cout << "捕获异常：" << msg << endl;
		}



	}


};

