#pragma once
#include <iostream>

using std::cout;
using std::endl;

class Test45 {
public:
    int m_a{ 0 };
    int* p{ nullptr };
    int m_b{ 0 };
    int m_c{ 0 };

    //Test45() = default;
    Test45() { cout << "ʹ��Ĭ�Ϲ��캯��\n"; };
    Test45(int _a, int* _p);
    //Test45(int b = 1, int c = 1);// ����������κκ����������ؼ�ΪĬ�Ϲ��캯������˵�ǰ�޷�����ͨ��
   /* Test45(int a, int b = 1, int c = 1) {
        m_a = a;
        m_b = b;
        m_c = c;
    }*/

    Test45(int a) {
        m_a = a;
    }

    Test45(int a, int b) : m_a{ a }, m_b{ b } {}

    void print() {
        cout << "a: " << m_a << " b: " << m_b << " c: " << m_c << " p: " << p << endl;
    }

    int getA();
};


// ������
class Cube {
public:
    int m_side;

    Cube() = default;
    Cube(int side) : m_side{ side } {};

    int getV() {
        return (int)pow(m_side, 3);
    }

    /*bool isLargerThan(Cube& c) { // �������ã�
        return getV() > c.getV();
    }*/

    bool isLargerThan(Cube c) {// ������캯��ֻ��һ����������Ὣ�ò����������й�����󡣼���ʽת��
        return getV() > c.getV();
    }
    
    /*bool isLargerThan(const Cube& c) {// const����ֻ�ܵ���const��Ա����

         return getV() > c.getV();
    }*/
};

class ExplicitCube {
public:
    int m_side;

    ExplicitCube() = default;
    explicit ExplicitCube(int side) : m_side{ side } {};

    int getV() {
        return (int)pow(m_side, 3);
    }

    bool isLargerThan(ExplicitCube c) {
        return getV() > c.getV();
    };
};

class Box4_9 {
public:
    int m_length;
    int m_width;
    int m_height;

    int unuse;

    Box4_9() = default;
    Box4_9(int length, int width, int height) : m_length{ length }, m_width{ width }, m_height{ height } {
        cout << "Box4_9(int length, int width, int height)" << endl;
    };

    Box4_9(int cube_size) : Box4_9(cube_size,cube_size,cube_size) {
    	cout << "Box4_9(int cube_size)" << endl;
    };// ���ڳ�ʼ��������

    /*Box4_9(int len, int wid) : Box4_9(len),unuse{wid} {// ֻ�ܵ���һ��ί�й��캯��
        cout << "Box4_9(int cube_size)" << endl;
    };*/

    void print() {
        cout << "length: " << m_length << " width: " << m_width << " height: " << m_height << endl;
    }
};