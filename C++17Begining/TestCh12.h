#pragma once

#include "Ch12Sec1.h"
#include "Ch12Sec2.h"
#include "Ch12Sec3.h"
#include "Ch12Sec4.h"
#include "Ch12Sec5.h"
#include "Ch12Sec6.h"
#include "Ch12Sec7.h"
#include "Ch12Sec8.h"
#include "Ch12Sec9.h"
#include "Ch12Sec10.h"
#include "Ch12Sec11.h"
#include "Ch12Sec12.h"

#include <iostream>
using namespace std;




class TestCh12
{
public:
	static void allTest() {

		cout << "******************** Sec1��Ϊ��ʵ������� *************************" << endl;
		Ch12Sec1::test1();
		Ch12Sec1::test2();
		Ch12Sec1::test3();
		Ch12Sec1::test4();
		Ch12Sec1::test5();


		cout << "******************** Sec4��Ϊ���������<<����� *************************" << endl;
		Ch12Sec4::test1();


		cout << "******************** Sec5�������������� *************************" << endl;
		Ch12Sec5::test1();
		Ch12Sec5::test2();


		cout << "******************** Sec6����Ա�ͷǳ�Ա���� *************************" << endl;
		Ch12Sec6::test1();


		cout << "******************** Sec7��һԪ��������� *************************" << endl;
		Ch12Sec7::test1();


		cout << "******************** Sec8�����ص����͵ݼ������ *************************" << endl;
		Ch12Sec8::test1();


		cout << "******************** Sec9�����������±������[] *************************" << endl;
		Ch12Sec9::test1();

		cout << "******************** Sec10�����������±������[] *************************" << endl;
		Ch12Sec10::test1();

		cout << "******************** Sec11����������ת�� *************************" << endl;
		Ch12Sec11::test1();

		cout << "******************** Sec12�����ظ�ֵ����� *************************" << endl;
		Ch12Sec12::test1();
		Ch12Sec12::test2();
		Ch12Sec12::test3();

	



	}

};

