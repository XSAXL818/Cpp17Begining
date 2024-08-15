#pragma once

#include <iostream>
#include "NeedClass.h"

using namespace std;

class Ch12Sec12
{
public:
	static void test1() {
		cout << "----------测试12_12: 实现复制赋值运算符" << endl;
		Msg12_12_1 msg1{ "haha" };
		//Msg12_12_1 msg2 = msg1;// 调用的是副本构造函数
		Msg12_12_1 msg2;
		msg2 = msg1;

		msg1.setTxt("换了");
		cout << msg1.getTxt() << endl;
		cout << msg2.getTxt() << endl;

		//msg2 = msg2;// 存在bug
		msg2 = msg2;

	}
	static void test2() {
		cout << "----------测试12_12: 复制赋值运算符和副本构造函数" << endl;
		Msg12_12_1 msg1{ "haha" };
		Msg12_12_1 msg2 = msg1;// 调用的是副本构造函数
		msg2 = msg1;// 复制赋值运算符
	


	}

	static void test3() {
		cout << "----------测试12_12: 赋值不同类型" << endl;

		Msg12_12_2 m1{ "12" };
		cout << m1.getMsg() << endl;
		m1 = "345";
		cout << m1.getMsg() << endl;

	}
};

