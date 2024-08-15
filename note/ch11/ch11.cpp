#include <iostream>
#include <string>
#include <vector>
#include "Test45.h"


using namespace std;

class Animal{// 爬行动物类
private:
	int number_feet;
	string name;
    vector<string> like_food;
    
public:
    virtual void eat(){

    }
    virtual void walk(){
        cout << "动物走\n";
    }
};

class People : public Animal{// 不用再反复声明成员变量，如number_feet
public:
    void eat(){
        
    }
    
    void walk(){
        cout << "双脚走\n";
    }
    
};
class Dog : public Animal{
public:
    void eat(){
        
    }
    
    void walk(){
        cout << "四脚走\n";
    }
};



void animal_move(Animal* obj){
    obj->walk();
}


void test1(){
    People p;
    Dog d;
    animal_move(&p);
    animal_move(&d);
}


// 11.4.1 默认构造函数和定义类的构造函数
class A{
public:
    int a;
    int* pa;  
};
class B{
public:
    int a;
    int* pa;  
    B(){
        a = 0;
        pa = nullptr;
    }
    B(int _a){
        a = _a;
    }
    B(int* _pa) : pa(_pa){}
};
void test2(){
    A a;
    
    cout << a.a << endl;
    cout << "指针默认值：" << a.pa << endl;

    B b;
    cout << b.a << endl;
    cout << "指针默认值：" << b.pa << endl;

    B b1{3};
    cout << b1.a << endl;

    B b2{&b1.a};
    cout << *b2.pa << endl;

}

// 使用default关键字
class Default{
public:
    int m_a{0};
    int* m_p{nullptr};

    Default() = default;
    Default(int a, int* p): m_a(a), m_p(p){}

};

void test3(){
    Default d1;
    cout << d1.m_a << " " << d1.m_p << endl;

    Default d2{1,nullptr};
    cout << d2.m_a << " " << d2.m_p << endl;
}

// 在类外部定义函数
void test4(){
    Test45 t1;
    cout << t1.a << " " << t1.p << endl;

    Test45 t2{3,nullptr};
    cout << t2.a << " " << t2.p << endl;

    // Test45 t3{3};
    // cout << t3.a << " " << t3.p << endl;

}


int main(){

    test1();

    cout << "测试：默认构造函数" << endl;
    test2();
    cout << "------------------------" << endl;

    cout << "测试: default关键字" << endl;
    test3();
    cout << "------------------------" << endl;

    cout << "测试: 在类外部定义函数" << endl;
    test4();
    cout << "------------------------" << endl;


    return 0;
}