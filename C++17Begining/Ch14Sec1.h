#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch14Sec1{
public:
	static void test1() {
		cout << "----------����14_1: ʹ�û���ָ��͵��ü̳еĺ���" << endl;

		cout << "�������\n";
		ABox14_1_1 aBox{ 3 };
		cout << "����aBox��volume()������" << aBox.volume() << endl;
		aBox.showVolume();

		cout << "ָ�����\n";
		Box14_1_1* pBox = &aBox;
		cout << "����aBox��volume()������" << pBox->volume() << endl;
		pBox->showVolume();

	}


	static void test2() {
		cout << "----------����14_3: �麯��" << endl;

		ABox14_3_1 box{ 3 };

		cout << "������ã�\n";
		cout << box.volume() << endl;
		box.showVolume();

		cout << "ָ����ã�\n";
		Box14_3_1* pBox{ &box };
		cout << pBox->volume() << endl;
		pBox->showVolume();

		cout << "�ͻ�����麯���ĺ�������ͬ���������б�ͬ\n";
		box.print(3);
		pBox->print();

		pBox->outsideFun();

		cout << "^^^^^^^^^^^^^^^^^ʹ���麯��ʱ��Ҫ��\n";
		cout << "��������麯���ķ������ͺͻ��������ͬ����Эͬ\n";
		Box14_3_2 box1{ 3 };
		box1.print();
		Box14_3_2* pBox1{ &box1 };
		pBox1->myFun();// ���������û�������麯��������õ���ABox

		cout << "^^^^^^^^^^^^^^^^^����ָ����麯������Ȩ��\n";
		ABox14_3_5 box2{ 3 };
		Box14_3_5* pBox2{ &box2 };
		pBox2->printVersion();

		cout << "����1.4���麯���е�Ĭ��ʵ��\n";
		ABox14_1_4_1 box3;
		Box14_1_4_1* pBox3{ &box3 };
		cout << box3.getThree() << endl;
		cout << pBox3->getThree() << endl;


		cout << "����1.5��ͨ�����õ����麯��\n";
		ABox14_1_5_1 box4{ 3 };
		showVolume14_1_5(box4);

		cout << "����1.6����̬����\n";
		vector<Box14_1_5_1> boxs;
		boxs.push_back(Box14_1_5_1{ 4 });
		boxs.push_back(ABox14_1_5_1{ 5 });
		for (const Box14_1_5_1& box : boxs) {
			box.showVolume();
		}

		vector<unique_ptr<Box14_1_5_1> > pBoxs;
		pBoxs.push_back(make_unique<Box14_1_5_1>(Box14_1_5_1{ 4 }));
		pBoxs.push_back(make_unique<ABox14_1_5_1>(ABox14_1_5_1{ 5 }));

		for (const auto& elem : pBoxs) {
			elem->showVolume();
		}

		cout << "\n����1.6����̬����\n";
		vector< unique_ptr<Box14_1_7_1> > vBoxs;
		vBoxs.push_back(make_unique<Box14_1_7_1>(Box14_1_7_1{}));
		vBoxs.push_back(make_unique<ABox14_1_7_1>(ABox14_1_7_1{}));
		cout << "�ͷż���:\n";
		vBoxs.clear();
		cout << "�ָ���--------------------------------\n";

		vector<unique_ptr< Box14_1_7_2> > vBoxs2;
		vBoxs2.push_back(make_unique< Box14_1_7_2>(Box14_1_7_2{}));
		vBoxs2.push_back(make_unique< ABox14_1_7_2>(ABox14_1_7_2{}));
		cout << "�ͷż���:\n";
		vBoxs2.clear();
		
		cout << "\n����1.7: ָ��������֮���ת��\n";
		// ��Ȼ���ϻ���ָ��ָ�����������
		ABox14_1_8_1 aBox1{ 3 };
		Box14_1_8_1* pBox4{ &aBox1 };
		Box14_1_8_1& rBox{ aBox1 };

		cout << pBox4->getVolume() << endl;
		cout << rBox.getVolume() << endl;

		BBox14_1_8_1 bBox1{ 4 };
		Box14_1_8_1* pBox5{ &bBox1 };
		ABox14_1_8_1* pBox6{ (ABox14_1_8_1*)pBox5 };
		ABox14_1_8_1* pBox7{ static_cast<ABox14_1_8_1*>(pBox5) };
		cout << pBox6->getVolume() << endl;
		cout << pBox7->getVolume() << endl;

		cout << "����static_cast\n";
		BB bb1{ 4 };
		StaticCast s1{ bb1 };
		StaticCast s2{ static_cast<StaticCast>(bb1)};
		cout << s1.getA() << endl;

		cout << "��̬ǿ��ת��\n";
		Box14_1_8_1 box5{ 3 };
		Box14_1_8_1* pBox8{ &box5 };
		ABox14_1_8_1* pBox9{ static_cast<ABox14_1_8_1*>(pBox8) };
		cout << pBox9->getVolume() << endl;
		cout << pBox9->b << endl;
		pBox9->print();

		ABox14_1_8_1* pBox10{ dynamic_cast<ABox14_1_8_1*>(pBox8) };
		if (pBox10 == nullptr) {
			cout << "ת��ʧ��\n";
		}


		cout << "\n����1.9: ��̬ǿ��ת��\n";
		cout << "^^^^^^^^^^ת��ָ��\n";
		cout << "����ת��\n";
		ABBox14_1_9_1 abBox{ 4 };
		ABox14_1_9_1* pABox{ &abBox };
		Box14_1_9_1* pBox11{ pABox };

		ABox14_1_9_1* pABox1{ dynamic_cast<ABox14_1_9_1*>(pBox11) };
		pABox1->showVolume();

		cout << "���ת��\n";

		BBox14_1_9_1* pBBox{ dynamic_cast<BBox14_1_9_1*>(pBox11) };
		if (pBBox == nullptr) {
			cout << "ת��ʧ��\n";
		}
		else {
			pBBox->show();
		}

		cout << "^^^^^^^^^^ת������\n";
		Box14_1_9_1 box6{ 3 };
		// ����ʱ�����쳣
		//showVolume14_1_9_1(box6);
		// ʹ��ָ�봦��
		showVolume14_1_9_2(box6);

		cout << "\n����1.10: �����麯���Ļ���汾\n";
		
		MyBox14_1_10 box7{ 4 };
		cout << box7.volume() << endl;
		cout << box7.Box14_1_10::volume() << endl;

		cout << "\n����1.11: �ڹ��캯�������������е����麯��\n";
		MyBox14_1_11 box8{ 4 };
		cout << box8.volume() << endl;

	}
};

