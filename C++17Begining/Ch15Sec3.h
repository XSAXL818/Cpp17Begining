#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch15Sec3{
public:
	static void test1() {
		cout << "\n------测试1：匹配catch处理程序和异常\n";

		for (int i = 0; i < 3; i++) {
			try {
				if (i == 0) {
					throw Oops15_3_1_1{};
				}
				if (i == 1) {
					throw MoreOops15_3_1_1{};
				}
				if (i == 2) {
					throw BigOops15_3_1_1{};
				}
			}
			catch (BigOops15_3_1_1& oops) {
				cout << "1" << oops.getMsg() << endl;
			}
			catch (MoreOops15_3_1_1& oops) {
				cout << "2" << oops.getMsg() << endl;
			}
			catch (Oops15_3_1_1& oops) {
				cout << "3" << oops.getMsg() << endl;
			}
		}
	}

	static void test2() {
		cout << "\n------测试2：用基类处理程序捕获派生类异常\n";

		cout << "catch按引用接收" << endl;
		for (int i = 0; i < 3; i++) {
			try {
				if (i == 0) {
					throw Oops15_3_1_1{};
				}
				if (i == 1) {
					throw MoreOops15_3_1_1{};
				}
				if (i == 2) {
					throw BigOops15_3_1_1{};
				}
			}
			catch (Oops15_3_1_1& oops) {
				cout << typeid(oops).name() << endl;
				cout << oops.getMsg() << endl;
			}
		}

		cout << "catch按值接收" << endl;
		for (int i = 0; i < 3; i++) {
			try {
				if (i == 0) {
					throw Oops15_3_1_1{};
				}
				if (i == 1) {
					throw MoreOops15_3_1_1{};
				}
				if (i == 2) {
					throw BigOops15_3_1_1{};
				}
			}
			catch (Oops15_3_1_1 oops) {
				cout << typeid(oops).name() << endl;
				cout << oops.getMsg() << endl;
			}
		}
	}



};

