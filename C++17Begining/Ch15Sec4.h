#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch15Sec4{
public:

	static void test1() {
		cout << "\n------测试1：重新抛出异常\n";
		Oops15_4_1 oops;
		MoreOops15_4_1 mOops;


		for (int i = 0; i < 2; i++) {
			cout << "迭代次数: " << i << endl;
			try {
				try {
					if (i == 0) {
						throw oops;
					}
					else {
						throw mOops;
					}
				}
				catch (Oops15_4_1& oops) {
					if (typeid(oops) == typeid(MoreOops15_4_1)) {
						throw;
					}
					cout << "捕获异常：Oops15_4_1" << endl;
				}
			}
			catch (Oops15_4_1& moreOops) {
				cout << "捕获异常：MoreOops15_4_1" << endl;
			}

		}
		cout << "\nfor 循环结束\n";

	}

	static void test2() {
		cout << "\n------测试2：重新抛出异常,throw 对象\n";
		Oops15_4_1 oops;
		MoreOops15_4_1 mOops;


		for (int i = 0; i < 2; i++) {
			cout << "迭代次数: " << i << endl;
			try {
				try {
					if (i == 0) {
						throw oops;
					}
					else {
						throw mOops;
					}
				}
				catch (Oops15_4_1& oops) {
					if (typeid(oops) == typeid(MoreOops15_4_1)) {
						throw oops;
					}
					cout << "捕获异常：Oops15_4_1" << endl;
				}
			}
			catch (Oops15_4_1& moreOops) {
				cout << "捕获异常：MoreOops15_4_1" << endl;
			}

		}
		cout << "\nfor 循环结束\n";

	}

};

