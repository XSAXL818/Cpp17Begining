#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch15Sec2{
public:
	static void test1() {
		cout << "---------���ԣ��׳��쳣---------" << endl;
		for (int i = 0; i < 6; i++) {
			try {
				if (i % 2 == 0) {
					throw "ż��";
				}
				cout << "δ�׳�ż���쳣" << endl;
				if (i % 3 == 2) {
					throw 1;
				}
			}
			catch (const char* msg) {
				cout << "�����쳣��" << msg << endl;
				return;
			}
			catch (int i) {
				cout << "�����쳣��" << i << endl;
			}

			cout << "ѭ������һ��" << endl;
		}
		cout << "---------���Խ���---------" << endl;
	}

	static void test2() {
		cout << "\n---------���ԣ��쳣�������---------" << endl;
		for (int i = 0; i < 6; i++) {
			cout << "����: " << i << endl;
			try {
				Box15_2_2_1 box;
				if (i % 2 == 1) {
					// �����׳�ʹ��˽�и������캯������Ķ���
					/*Box15_2_2_2 box1{};
					throw box1;*/
					throw Box15_2_2_2{};
				}
			}
			catch (const char* msg) {
				cout << "�����쳣��" << msg << endl;
				return;
			}
			catch (Box15_2_2_2& box) {
				box.show();
			}
			cout << "try-catch����" << endl;
		}
	}

	static void test3() {
		cout << "\n---------���ԣ������׳��쳣�Ĵ���---------" << endl;

		try {
			fun15_2_2_1();
			fun15_2_2_3();
		}
		catch (const char* msg) {
			cout << "�����쳣��" << msg << endl;
		}



	}


};

