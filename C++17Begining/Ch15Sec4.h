#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch15Sec4{
public:

	static void test1() {
		cout << "\n------����1�������׳��쳣\n";
		Oops15_4_1 oops;
		MoreOops15_4_1 mOops;


		for (int i = 0; i < 2; i++) {
			cout << "��������: " << i << endl;
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
					cout << "�����쳣��Oops15_4_1" << endl;
				}
			}
			catch (Oops15_4_1& moreOops) {
				cout << "�����쳣��MoreOops15_4_1" << endl;
			}

		}
		cout << "\nfor ѭ������\n";

	}

	static void test2() {
		cout << "\n------����2�������׳��쳣,throw ����\n";
		Oops15_4_1 oops;
		MoreOops15_4_1 mOops;


		for (int i = 0; i < 2; i++) {
			cout << "��������: " << i << endl;
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
					cout << "�����쳣��Oops15_4_1" << endl;
				}
			}
			catch (Oops15_4_1& moreOops) {
				cout << "�����쳣��MoreOops15_4_1" << endl;
			}

		}
		cout << "\nfor ѭ������\n";

	}

};

