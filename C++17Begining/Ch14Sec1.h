#pragma once
#include <iostream>
#include "NeedClass.h"

using namespace std;


class Ch14Sec1{
public:
	static void test1() {
		cout << "----------测试14_1: 使用基类指针和调用继承的函数" << endl;

		cout << "对象调用\n";
		ABox14_1_1 aBox{ 3 };
		cout << "调用aBox的volume()函数：" << aBox.volume() << endl;
		aBox.showVolume();

		cout << "指针调用\n";
		Box14_1_1* pBox = &aBox;
		cout << "调用aBox的volume()函数：" << pBox->volume() << endl;
		pBox->showVolume();

	}


	static void test2() {
		cout << "----------测试14_3: 虚函数" << endl;

		ABox14_3_1 box{ 3 };

		cout << "对象调用：\n";
		cout << box.volume() << endl;
		box.showVolume();

		cout << "指针调用：\n";
		Box14_3_1* pBox{ &box };
		cout << pBox->volume() << endl;
		pBox->showVolume();

		cout << "和基类的虚函数的函数名相同，但参数列表不同\n";
		box.print(3);
		pBox->print();

		pBox->outsideFun();

		cout << "^^^^^^^^^^^^^^^^^使用虚函数时的要求\n";
		cout << "派生类的虚函数的返回类型和基类必须相同或者协同\n";
		Box14_3_2 box1{ 3 };
		box1.print();
		Box14_3_2* pBox1{ &box1 };
		pBox1->myFun();// 如果派生类没有隐藏虚函数，则调用的是ABox

		cout << "^^^^^^^^^^^^^^^^^基类指针的虚函数访问权限\n";
		ABox14_3_5 box2{ 3 };
		Box14_3_5* pBox2{ &box2 };
		pBox2->printVersion();

		cout << "测试1.4：虚函数中的默认实参\n";
		ABox14_1_4_1 box3;
		Box14_1_4_1* pBox3{ &box3 };
		cout << box3.getThree() << endl;
		cout << pBox3->getThree() << endl;


		cout << "测试1.5：通过引用调用虚函数\n";
		ABox14_1_5_1 box4{ 3 };
		showVolume14_1_5(box4);

		cout << "测试1.6：多态集合\n";
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

		cout << "\n测试1.6：多态集合\n";
		vector< unique_ptr<Box14_1_7_1> > vBoxs;
		vBoxs.push_back(make_unique<Box14_1_7_1>(Box14_1_7_1{}));
		vBoxs.push_back(make_unique<ABox14_1_7_1>(ABox14_1_7_1{}));
		cout << "释放集合:\n";
		vBoxs.clear();
		cout << "分隔符--------------------------------\n";

		vector<unique_ptr< Box14_1_7_2> > vBoxs2;
		vBoxs2.push_back(make_unique< Box14_1_7_2>(Box14_1_7_2{}));
		vBoxs2.push_back(make_unique< ABox14_1_7_2>(ABox14_1_7_2{}));
		cout << "释放集合:\n";
		vBoxs2.clear();
		
		cout << "\n测试1.7: 指针和类对象之间的转换\n";
		// 任然符合基类指针指向派生类对象
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

		cout << "测试static_cast\n";
		BB bb1{ 4 };
		StaticCast s1{ bb1 };
		StaticCast s2{ static_cast<StaticCast>(bb1)};
		cout << s1.getA() << endl;

		cout << "静态强制转换\n";
		Box14_1_8_1 box5{ 3 };
		Box14_1_8_1* pBox8{ &box5 };
		ABox14_1_8_1* pBox9{ static_cast<ABox14_1_8_1*>(pBox8) };
		cout << pBox9->getVolume() << endl;
		cout << pBox9->b << endl;
		pBox9->print();

		ABox14_1_8_1* pBox10{ dynamic_cast<ABox14_1_8_1*>(pBox8) };
		if (pBox10 == nullptr) {
			cout << "转换失败\n";
		}


		cout << "\n测试1.9: 动态强制转换\n";
		cout << "^^^^^^^^^^转换指针\n";
		cout << "向下转换\n";
		ABBox14_1_9_1 abBox{ 4 };
		ABox14_1_9_1* pABox{ &abBox };
		Box14_1_9_1* pBox11{ pABox };

		ABox14_1_9_1* pABox1{ dynamic_cast<ABox14_1_9_1*>(pBox11) };
		pABox1->showVolume();

		cout << "跨层转换\n";

		BBox14_1_9_1* pBBox{ dynamic_cast<BBox14_1_9_1*>(pBox11) };
		if (pBBox == nullptr) {
			cout << "转换失败\n";
		}
		else {
			pBBox->show();
		}

		cout << "^^^^^^^^^^转换引用\n";
		Box14_1_9_1 box6{ 3 };
		// 运行时报出异常
		//showVolume14_1_9_1(box6);
		// 使用指针处理
		showVolume14_1_9_2(box6);

		cout << "\n测试1.10: 调用虚函数的基类版本\n";
		
		MyBox14_1_10 box7{ 4 };
		cout << box7.volume() << endl;
		cout << box7.Box14_1_10::volume() << endl;

		cout << "\n测试1.11: 在构造函数和析构函数中调用虚函数\n";
		MyBox14_1_11 box8{ 4 };
		cout << box8.volume() << endl;

	}
};

