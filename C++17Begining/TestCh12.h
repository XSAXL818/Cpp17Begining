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
		BaseCharpter::setSection(1);
		//cout << "******************** Sec1��Ϊ��ʵ������� *************************" << endl;
		BaseCharpter::showSectionTitle("Ϊ��ʵ�������");
		Ch12Sec1::test1();
		Ch12Sec1::test2();
		Ch12Sec1::test3();
		Ch12Sec1::test4();
		Ch12Sec1::test5();

		BaseCharpter::setSection(4);
		//cout << "******************** Sec4��Ϊ���������<<����� *************************" << endl;
		BaseCharpter::showSectionTitle("Ϊ���������<<�����");
		Ch12Sec4::test1();


		//cout << "******************** Sec5�������������� *************************" << endl;
		BaseCharpter::showSectionTitle("������������");
		Ch12Sec5::test1();
		Ch12Sec5::test2();


		//cout << "******************** Sec6����Ա�ͷǳ�Ա���� *************************" << endl;
		BaseCharpter::showSectionTitle("��Ա�ͷǳ�Ա����");
		Ch12Sec6::test1();


		//cout << "******************** Sec7��һԪ��������� *************************" << endl;
		BaseCharpter::showSectionTitle("һԪ���������");
		Ch12Sec7::test1();


		//cout << "******************** Sec8�����ص����͵ݼ������ *************************" << endl;
		BaseCharpter::showSectionTitle("���ص����͵ݼ������");
		Ch12Sec8::test1();


		//cout << "******************** Sec9�����������±������[] *************************" << endl;
		BaseCharpter::showSectionTitle("���������±������[]");
		Ch12Sec9::test1();

		//cout << "******************** Sec10�����������±������[] *************************" << endl;
		BaseCharpter::showSectionTitle("��������");
		Ch12Sec10::test1();

		//cout << "******************** Sec11����������ת�� *************************" << endl;
		BaseCharpter::showSectionTitle("��������ת��");
		Ch12Sec11::test1();

		//cout << "******************** Sec12�����ظ�ֵ����� *************************" << endl;
		BaseCharpter::showSectionTitle("���ظ�ֵ�����");
		Ch12Sec12::test1();
		Ch12Sec12::test2();
		Ch12Sec12::test3();

	



	}

};

