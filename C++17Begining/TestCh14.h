#pragma once


#include "Ch14Sec1.h"
#include "Ch14Sec2.h"
#include "Ch14Sec3.h"
#include "Ch14Sec4.h"
#include "BaseCharpter.h"


#include <iostream>
using namespace std;



class TestCh14{
public:
	static void allTest() {
		BaseCharpter::section = 1;
		//cout << "******************** Sec1������̬�� *************************" << endl;
		BaseCharpter::showSectionTitle("����̬��");
		Ch14Sec1::test1();

		//cout << "******************** Sec2����̬�������ĳɱ� *************************" << endl;
		BaseCharpter::showSectionTitle("��̬�������ĳɱ�");
		Ch14Sec2::test1();

		//cout << "******************** Sec3��ȷ����̬���� *************************" << endl;
		BaseCharpter::showSectionTitle("ȷ����̬����");
		Ch14Sec3::test1();
		
		//cout << "******************** Sec4�����麯�� *************************" << endl;
		BaseCharpter::showSectionTitle("���麯��");
		Ch14Sec4::test1();

	}
};

