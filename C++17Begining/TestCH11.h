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
#include "BaseCharpter.h"


using namespace std;



// ��11�£������Լ�����������

class TestCH11{
public:
	static void allTest() {
		BaseCharpter::setSection(4);
		//cout << "******************** Sec4���������캯�� *************************" << endl;
		BaseCharpter::showSectionTitle("�������캯��");
		Ch11Sec5::test0();

		//cout << "******************** Sec5������˽�����Ա *************************" << endl;
		BaseCharpter::showSectionTitle("����˽�����Ա");
		Ch11Sec5::test1();

		//cout << "\n\n******************** Sec6��thisָ�� *************************" << endl;
		BaseCharpter::showSectionTitle("thisָ��");
		Ch11Sec5::test2();

		//cout << "\n\n******************** Sec7��const�����const��Ա���� *************************" << endl;
		BaseCharpter::showSectionTitle("const�����const��Ա����");
		Ch11Sec7::test1();
		Ch11Sec7::test3();
		Ch11Sec7::test4();
		Ch11Sec7::test5();

		//cout << "\n\n******************** Sec8����Ԫ *************************" << endl;
		BaseCharpter::showSectionTitle("��Ԫ");
		Ch11Sec8::test1();
		Ch11Sec8::test2();

		//cout << "\n\n******************** Sec9����Ķ������� *************************" << endl;
		BaseCharpter::showSectionTitle("��Ķ�������");
		Ch11Sec9::test1();

		//cout << "\n\n******************** Sec10�������Ĵ�С *************************" << endl;
		BaseCharpter::showSectionTitle("�����Ĵ�С");
		Ch11Sec10::test1();

		//cout << "\n\n******************** Sec11����ľ�̬��Ա *************************" << endl;
		BaseCharpter::showSectionTitle("��ľ�̬��Ա");
		Ch11Sec11::test1();
		Ch11Sec11::test2();
		Ch11Sec11::test3();
		Ch11Sec11::test4();
		Ch11Sec11::test5();

		//cout << "\n\n******************** Sec12���������� *************************" << endl;
		BaseCharpter::showSectionTitle("��������");
		Ch11Sec12::test1();


		//cout << "\n\n******************** Sec13����ľ�̬��Ա *************************" << endl;
		BaseCharpter::showSectionTitle("��ľ�̬��Ա");
		Ch11Sec13::test1();


		//cout << "\n\n******************** Sec14��Ƕ���� *************************" << endl;
		BaseCharpter::showSectionTitle("Ƕ����");
		Ch11Sec14::test1();

		



	}
};

