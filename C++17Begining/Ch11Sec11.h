#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;
// �����£�Ϊʵ�ּ򵥣�������������ʵ�ַ���һ���ļ���

class Ch11Sec11
{
public:

	static void  test1() {
		cout << "----------����11_11_1: ��̬��Ա����" << endl;
		Static11_11_1_1 s1;
		Static11_11_1_1 s2{ 3 };
		cout << "����������ʽ: " << Static11_11_1_1::cnt << endl;
		cout << "������÷�ʽ: " << s1.cnt << endl;
		cout << "�������ط�ʽ: " << s1.objCnt() << endl;

		Static11_11_1_2 s3;
		const Static11_11_1_2 s4;
		cout << "������ʼ����̬����: " << s4.objCnt() << endl;
	}

	static void  test2() {
		cout << "\n\n----------����11_11_3\4: ��̬�����;�̬��Ա����" << endl;
		CylindricalBox11_11_3 crb{ 5.0f,CylindricalBox11_11_3::MAXHEIGHT,CylindricalBox11_11_3::DEFAULTMATERIAL };
		cout << "����: " << crb.getMaterial() << " ���: " << crb.volume() << endl;

	}

	static void  test3() {
		cout << "\n\n----------����11_11_5: ��̬��Ա����" << endl;
		Box11_11_5 b1{ 1,3,4 };
		b1.print();
		Box11_11_5::toCube(b1);
		b1.print();

	}

	static void  test4() {
		//cout << "\n\n----------����11_11_1: ��̬��Ա����" << endl;
	}

	static void  test5() {
		//cout << "\n\n----------����11_11_1: ��̬��Ա����" << endl;
	}
};

