#include <iostream>

using namespace std;

void sum(int a, int b){
    cout << a + b << endl;
}
void sum(double a, double b){
    cout << a + b << endl;
}

double larger(int a, int b){
    cout << "int" << endl;
    return a > b ? a : b;
}

long larger(long& a, long& b){
    cout << "long" << endl;
    return a > b ? a : b;
}

// 测试将int类型变量使用static_cast转换为long类型作为实参，调用的long larger(long& a, long& b)函数？还是
void test1(){
    int a{1},b{4};
    double c{3.1};
    larger(a,b);
    larger(static_cast<long>(a),static_cast<long>(b));
}

double larger1(int a, int b){
    cout << "int" << endl;
    return a > b ? a : b;
}

long larger1(const long& a, const long& b){
    cout << "long" << endl;
    return a > b ? a : b;
}
// 当使用const修饰，可以接受临时变量
void test2(){
    int a{1},b{4};
    larger1(a,b);
    larger1(static_cast<long>(a),static_cast<long>(b));
}

// 8.9.3

// 对非引用和指针类型的const参数，使用const的意义是在定义时使用const修饰
//声明中不带有const
long larger893(long a, long b);

// 定义中使用const修饰
long larger893(const long a, const long b){
	// a = 1l;// 该操作不能出现
	return a > b ? a : b;
}

// 1、重载和const指针参数
long* longer3_1_1(long* a, long* b);
const long* longer3_1_2(const long* a, const long* b);

long* longer3_1_1(long* a, long* b){
    cout << "非const" << endl;
    return *a > *b ? a : b;
}
// 返回值如何不是const，无法和声明匹配。返回值必须是const修饰，因为a，b是const修饰的
const long* longer3_1_2(const long* a, const long* b){
    cout << "const" << endl;
    return *a > *b ? a : b;
}

void f3_1(long* a){
    cout << "如果只有一个指针参数，可以传入const指针" << endl;
}
void f3_11(const long* a){
    cout << "如果只有一个const指针参数，可以传入非const指针" << endl;
}


void test3(){
    long num = 3l;
    long *a{&num}, *b{&num};
    longer3_1_1(a,b);

    const long *c{&num}, *d{&num};
    longer3_1_2(c,d);

    // f3_1(c);// const传入后，在f3_1的声明和定义中可以修改地址的值，该行为不能出现
    f3_11(a);
}

// 重载和const引用参数
long& larger3_2_1(long& a, long& b){
    cout << "重载：非const引用" << endl;
    return a > b ? a : b;
}
long larger3_2_1(const long& a, const long& b){
    cout<< "重载：const引用" << endl;
    return a > b ? a : b;
}

// 上述是重载const引用和非const引用，下面只有const引用，接受非const和const变量
long larger3_2_2(const long& a, const long& b){
    cout<< "未重载：只有const引用参数" << endl;
    return a > b ? a : b;
}

// 不能使用申明无const，而定义有const
long larger3_2_3(long& a,long& b);

void test4(){
    long num = 3l;
    long a{num}, b{num};
    larger3_2_1(a,b);

    const long c{num}, d{num};
    larger3_2_1(c,d);

    // 全部接受
    larger3_2_2(a,b);
    larger3_2_2(c,d);

    // larger3_2_3(a,b);

}

long larger3_2_3(const long& a, const long& b){
    cout << "非const引用的函数申明，const引用的函数定义" << endl;
    return a > b ? a : b;
}



int main() {

    cout << "测试：非const引用不会接受临时变量，导致调用不明确" << endl;
    test1();
    cout << endl << "------------------------------------" << endl;

    cout << "测试：将引用使用const修饰，解决上述问题" << endl;
    test2();
    cout << endl << "------------------------------------" << endl;

    cout << "测试：对指针使用const和不使用const的调用" << endl;
    test3();
    cout << endl << "------------------------------------" << endl;

    cout << "测试：重载const引用和非const引用"<<endl;
    test4();
    cout << endl << "------------------------------------" << endl;

   
    return 0;
}