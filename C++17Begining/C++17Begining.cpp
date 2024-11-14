// C++17Begining.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include "Test45.h"
#include "MyTest.h"

#include "TestCH11.h"
#include "TestCh12.h"
#include "TestCh13.h"
#include "TestCh14.h"
#include "TestCh15.h"
#include "TestCh16.h"
#include "BaseCharpter.h"


using namespace std;


int main()
{
    /*cout << "-----------测试：外部定义类的函数----------------" << endl;
    MyTest::test1();
    cout << "-------------------------------------------------" << endl;

    cout << "-----------测试：使用explicit，只能显式转换----------------" << endl;
    MyTest::test2();
    cout << "-------------------------------------------------" << endl;


    cout << "-----------测试：使用explicit，只能显式转换----------------" << endl;
    MyTest::test3();
    cout << "-------------------------------------------------" << endl;*/

    BaseCharpter::setChapter(11);
    // 第11章的测试
    BaseCharpter::showChapterTitle("定义自己的数据类型");
    TestCH11::allTest();
    
    // 第12章的测试
    BaseCharpter::showChapterTitle("运算符重载");
    TestCh12::allTest();

    
    // 第13章的测试
    BaseCharpter::showChapterTitle("继承");
    TestCh13::allTest();

    // 第14章的测试
    BaseCharpter::showChapterTitle("多态性");
    TestCh14::allTest();

    // 第15章的测试
    BaseCharpter::showChapterTitle("运行时错误和异常");
    TestCh15::allTest();

    // 第16章的测试
    BaseCharpter::showChapterTitle("类模板");
    TestCh16::allTest();



    return 0;
}
