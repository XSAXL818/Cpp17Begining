#pragma once
#include <iostream>
#include "Ch11Sec5.h"
#include "Ch11Sec7.h"
#include "Ch11Sec8.h"
#include "Ch11Sec9.h"
#include "Ch11Sec10.h"
#include "Ch11Sec11.h"
#include "Ch11Sec12.h"
#include "Ch11Sec13.h"
#include "Ch11Sec14.h"



using namespace std;



// ��11�£������Լ�����������

class TestCH11{
public:
	static void allTest() {

		cout << "******************** Sec4���������캯�� *************************" << endl;
		Ch11Sec5::test0();

		cout << "******************** Sec5������˽�����Ա *************************" << endl;
		Ch11Sec5::test1();

		cout << "\n\n******************** Sec6��thisָ�� *************************" << endl;
		Ch11Sec5::test2();

		cout << "\n\n******************** Sec7��const�����const��Ա���� *************************" << endl;
		Ch11Sec7::test1();
		Ch11Sec7::test3();
		Ch11Sec7::test4();
		Ch11Sec7::test5();

		cout << "\n\n******************** Sec8����Ԫ *************************" << endl;
		Ch11Sec8::test1();
		Ch11Sec8::test2();

		cout << "\n\n******************** Sec9����Ķ������� *************************" << endl;
		Ch11Sec9::test1();

		cout << "\n\n******************** Sec10�������Ĵ�С *************************" << endl;
		Ch11Sec10::test1();

		cout << "\n\n******************** Sec11����ľ�̬��Ա *************************" << endl;
		Ch11Sec11::test1();
		Ch11Sec11::test2();
		Ch11Sec11::test3();
		Ch11Sec11::test4();
		Ch11Sec11::test5();


		cout << "\n\n******************** Sec12���������� *************************" << endl;
		Ch11Sec12::test1();


		cout << "\n\n******************** Sec11����ľ�̬��Ա *************************" << endl;
		Ch11Sec13::test1();


		cout << "\n\n******************** Sec11��Ƕ���� *************************" << endl;
		
		Ch11Sec14::test1();

		cout << "\n\n******************** Sec11����ľ�̬��Ա *************************" << endl;
		



	}
};

