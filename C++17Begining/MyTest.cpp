#include "MyTest.h"
#include "Test45.h"


// ������ⲿ���庯��
void MyTest::test1(){
	Test45 t1;
	t1.print();
	Test45 t2{1};
	t2.print();
	Test45 t3{2,&t2.m_a};
	t3.print();

	int a{ 1 }, b{ 2 };
	Test45 t4{ a,b };
	t4.print();

}

//ʹ��explicit��ֻ����ʽת��
void MyTest::test2(){
	Cube c1{ 5 };
	Cube c2{ 2 };
	cout << "����Ϊ����" << endl;
	cout << c1.isLargerThan(c2) << endl;

	cout << "����Ϊint���͵�ֵ" << endl;
	cout << c1.isLargerThan(50) << endl;

	ExplicitCube ec1{ 5 };
	cout << "����Ϊint���͵�ֵ" << endl;
	//cout << ec1.isLargerThan(50) << endl;
}

// ����ί�й��캯��
void MyTest::test3(){
	Box4_9 b1{1};
	b1.print();
	Box4_9 b2{1,2,3};
	b2.print();

}

