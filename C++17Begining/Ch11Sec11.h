#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;
// 测试章：为实现简单，类的声明和类的实现放在一个文件中

class Ch11Sec11
{
public:

	static void  test1() {
		cout << "----------测试11_11_1: 静态成员变量" << endl;
		Static11_11_1_1 s1;
		Static11_11_1_1 s2{ 3 };
		cout << "类名解析方式: " << Static11_11_1_1::cnt << endl;
		cout << "对象调用方式: " << s1.cnt << endl;
		cout << "函数返回方式: " << s1.objCnt() << endl;

		Static11_11_1_2 s3;
		const Static11_11_1_2 s4;
		cout << "内联初始化静态变量: " << s4.objCnt() << endl;
	}

	static void  test2() {
		cout << "\n\n----------测试11_11_3\4: 静态常量和静态成员变量" << endl;
		CylindricalBox11_11_3 crb{ 5.0f,CylindricalBox11_11_3::MAXHEIGHT,CylindricalBox11_11_3::DEFAULTMATERIAL };
		cout << "材料: " << crb.getMaterial() << " 体积: " << crb.volume() << endl;

	}

	static void  test3() {
		cout << "\n\n----------测试11_11_5: 静态成员函数" << endl;
		Box11_11_5 b1{ 1,3,4 };
		b1.print();
		Box11_11_5::toCube(b1);
		b1.print();

	}

	static void  test4() {
		//cout << "\n\n----------测试11_11_1: 静态成员变量" << endl;
	}

	static void  test5() {
		//cout << "\n\n----------测试11_11_1: 静态成员变量" << endl;
	}
};

