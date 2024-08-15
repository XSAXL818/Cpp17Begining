// C++17Begining.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include "Test45.h"
#include "MyTest.h"

#include "TestCH11.h"
#include "TestCh12.h"
#include "TestCh13.h"
#include "TestCh14.h"

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

    // 第11章的测试
    TestCH11::allTest();
    
    // 第12章的测试
    TestCh12::allTest();

    
    // 第13章的测试
    TestCh13::allTest();

    // 第14章的测试
    TestCh14::allTest();


    return 0;
}