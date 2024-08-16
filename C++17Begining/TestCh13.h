#pragma once


#include "Ch13Sec1.h"
#include "Ch13Sec2.h"
#include "Ch13Sec3.h"
#include "Ch13Sec4.h"
#include "Ch13Sec5.h"
#include "Ch13Sec6.h"
#include "Ch13Sec7.h"
#include "Ch13Sec8.h"
#include "Ch13Sec9.h"
#include "Ch13Sec10.h"
#include "BaseCharpter.h"

#include <iostream>
using namespace std;



class TestCh13{
public:
	static void allTest() {
		BaseCharpter::setSection(2);
		//cout << "******************** Sec2����ļ̳� *************************" << endl;
		BaseCharpter::showSectionTitle("��ļ̳�");
		Ch13Sec2::test1();

		//cout << "******************** Sec3������ĳ�Ա����Ϊprotected *************************" << endl;
		BaseCharpter::showSectionTitle("����ĳ�Ա����Ϊprotected");
		Ch13Sec3::test1();
		
		//cout << "******************** Sec4���������Ա�ķ��ʼ��� *************************" << endl;
		BaseCharpter::showSectionTitle("�������Ա�ķ��ʼ���");
		Ch13Sec4::test1();


		//cout << "******************** Sec5���������еĹ��캯�� *************************" << endl;
		BaseCharpter::showSectionTitle("�������еĹ��캯��");
		Ch13Sec5::test1();
		Ch13Sec5::test2();
		Ch13Sec5::test3();

		//cout << "******************** Sec6���̳��е��������� *************************" << endl;
		BaseCharpter::showSectionTitle("�̳��е���������");
		Ch13Sec6::test1();

		//cout << "******************** Sec7���ظ��ĳ�Ա������ *************************" << endl;
		BaseCharpter::showSectionTitle("�ظ��ĳ�Ա������");
		Ch13Sec7::test1();

		//cout << "******************** Sec8���ظ��ĳ�Ա������ *************************" << endl;
		BaseCharpter::showSectionTitle("�ظ��ĳ�Ա������");
		Ch13Sec8::test1();

		//cout << "******************** Sec9�����ؼ̳� *************************" << endl;
		BaseCharpter::showSectionTitle("���ؼ̳�");
		Ch13Sec9::test1();

		//cout << "******************** Sec10����ص�������֮��ת�� *************************" << endl;
		BaseCharpter::showSectionTitle("��ص�������֮��ת��");
		Ch13Sec10::test1();





	}
};

