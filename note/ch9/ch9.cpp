#include <iostream>
#include <string>
#include <vector>

using namespace std;


// 9.1 函数模版的一个小例子
template <typename T> // template关键字，表明接下来的是一个模板声明 <typename T>是模板参数列表,typename 表示T是一个类型，即T可以是任意类型
T my_max1(T a, T b) { // 可以用class代替typename，表明T是类类型(也可以表示基本类型)，但typename更常用
    return a > b ? a : b;
}
template <class T> T my_max2(T a, T b) {// 可以写在一行上
    return a > b ? a : b;
}

// 9.2 函数模版的使用
void test2(){
    // T为int类型
    cout << my_max1(1, 2) << endl;
    // T为double类型
    cout << my_max2(1.1, 2.2) << endl;
    // T为string类型
    cout << my_max1(string("hello"), string("world")) << endl;

    // 测试传入不同类型的参数，无法编译。因为模板函数的参数类型是由编译器推导的，编译器无法推导出T的类型
    //cout << my_max1(1, 2.2) << endl; // 2.2 
}

// 9.3 模板类型参数
template <typename T>
const T& my_max3(const T& a,const T& b) {
    cout << "函数调用中: " << endl;
    cout << "a地址: " << &a << endl;
    cout << "b地址: " << &b << endl;
    return a > b ? a : b;
}

template <typename T>
T& my_max4(T& a,T& b) {
    cout << "函数调用中: " << endl;
    cout << "a地址: " << &a << endl;
    cout << "b地址: " << &b << endl;
    return a > b ? a : b;
}

template <typename T>
T& my_max5(T& a,T& b) {
    cout << "函数调用中: " << endl;
    cout << "a地址: " << &a << endl;
    cout << "b地址: " << &b << endl;
    return ref(a) > ref(b) ? ref(a) : ref(b);
}


void test3(){
    int a{1},b{2};
    cout << "函数调用传入的实参: " << endl;
    cout << "a地址: " << &a << endl;
    cout << "b地址: " << &b << endl;
    auto max = my_max3(a,b);// 返回的值不是a,b的引用
    cout << "max地址: " << &max << endl; 
    cout << max << endl; 
    b = 4;
    cout << max << endl; 

    // 解释：return返回的语句是一个值，而不是一个引用，所以根据值创建了一个const引用并返回

    cout << "函数参数列表不是const引用" <<endl;
    auto max2 = my_max4(a,b);// 返回的值是a,b的引用
    cout << "max2地址: " << &max2 << endl;

    cout << "使用ref函数返回引用" <<endl;
    auto max3 = my_max5(a,b);
    cout << "max3地址: " << &max3 << endl;
}

// 9.4 显示指定模板实参
template <typename T>
T my_max6(T a, T b) {
    return a > b ? a : b;
}

void test4(){
    // 显示指定模板实参
    cout << my_max6<int>(1, 2) << endl;
    // 可能出现不必要的麻烦
    cout << my_max6<int>(1, 2.2) << endl; 
}

//9.5 函数模板的特例
template <typename T>
T my_max5_1(T a, T b) {
    return a > b ? a : b;
}
// 使用特例
template <typename T>
T my_max5_2(T a, T b) {
    return a > b ? a : b;
}
template <>
int* my_max5_2(int* a, int* b) {
    return *a > *b ? a : b;
}


void test5(){
    int num1{3},num2{4};
    int* a{&num1},*b{&num2};
    // 传入指针类型，即T为int*。出现bug，比较大小事比较a和b的地址，即后声明的变量大
    cout << *my_max5_1(a,b) << endl;
    // 使用特例
    cout << *my_max5_2(a,b) << endl;
}

// 9.6 函数模板和重载
int my_max6_1(int a, int b) {
    cout << "模板声明之前：int重载"<<endl;
    return a > b ? a : b;
}

template <typename T>
T my_max6_1(T a, T b) {
    cout << "模板声明："<<endl;
    return a > b ? a : b;
}

double my_max6_1(double a, double b) {
    cout << "模板声明之后：double重载"<<endl;
    return a > b ? a : b;
}


template <typename T>
T* my_max6_1(T* a, T* b) {
    cout << "模板声明之后：指针重载"<<endl;
    return *a > *b ? a : b;
}

template <typename T>
typename vector<T>::const_iterator my_max6_1(const vector<T>& vec) {
    cout << "模板声明之后：vec重载,const"<<endl;
    return vec.begin();
}
template <typename T>
typename vector<T>::iterator my_max6_1(vector<T>& vec) {
    cout << "模板声明之后：vec重载，非const"<<endl;
    return vec.begin();
}

void test6(){
    int a{3},b{4};
    cout << my_max6_1(1, 2) << endl;
    cout << my_max6_1(1.1, 2.2) << endl;
    cout << my_max6_1(string("hello"), string("world")) << endl;
    cout << *my_max6_1(&a,&b) << endl;

    vector<int> vec{1,2,4,3,5};
    cout << *my_max6_1(vec) << endl;

}

// 9.7 多个参数的函数模板
template <typename TReturn ,typename TArg1, typename TArg2>
TReturn my_max7(TArg1 a, TArg2 b) {
    return a > b ? a : b;
}

void test7(){
    cout << my_max7<int>(1, 2.2) << endl;
    cout << my_max7<double>(1, 2.2) << endl;
    cout << my_max7<string>(string("hello"), string("world")) << endl;
}

// 9.8 模板的返回类型推断
template <typename T1,typename T2>
auto my_max8_1(T1 a, T2 b) {
    return a > b ? a : b;
}
// decltype 和 拖尾返回类型,对于模板而言decltype基本被返回类型推断取代
template <typename T1,typename T2>
auto my_max8_2(T1 a, T2 b) -> decltype(a > b ? a : b) {
    return a > b ? a : b;
}
// 计算两个vector的对应相乘的结果
template <typename T1,typename T2>
auto my_max8_3(const vector<T1>& vec1, const vector<T2>& vec2) {
    const auto min_size = min(vec1.size(), vec2.size());
    decltype(vec1[0]*vec2[0]) result{};// 用decltype是告诉编译器来如何推断类型，并不会真的执行vec1[0]*vec2[0]
    for (size_t i = 0; i < min_size; ++i) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

// auto只能进行值类型推断，无法推断出引用。而decltype可以推断出引用
// auto和decltype可以混合使用，auto用于函数返回值类型推断，decltype用于函数体内部类型推断
template <typename T1,typename T2>
auto my_max8_4(T1& a, T2& b){// 返回值
    cout << "仅使用auto来推断返回值类型: 返回的是值类型，非引用"<<endl;
    cout << "a地址: " << &a << endl;
    cout << "b地址: " << &b << endl;
    return a > b ? a : b;
}

template <typename T1,typename T2>
decltype(auto) my_max8_5(T1& a, T2& b){// 返回值
    cout << "使用decltype(auto)来推断返回值类型: 返回的是引用类型"<<endl;
    cout << "a地址: " << &a << endl;
    cout << "b地址: " << &b << endl;
    return a > b ? a : b;
}

template <typename T1,typename T2>
decltype(auto) my_max8_6(T1& a, T2& b){// 返回值
    cout << "使用decltype(auto)来推断返回值类型: 返回的是引用类型"<<endl;
    cout << "a地址: " << &a << endl;
    cout << "b地址: " << &b << endl;
    return 3+4;
}



void test8(){
    cout << "-------仅依靠auto关键字推断返回类型" << endl;
    cout << my_max8_1(1, 2.2) << endl;// double
    cout << my_max8_1(string("hello"), string("world")) << endl;// string

    cout << "-------decltype 和 拖尾返回类型" << endl;
    cout << my_max8_2(1, 2.2) << endl;// double

    cout << "-------在函数体中用decltype，返回类型推断使用auto" << endl;
    vector<int> vec1{1,2,3,4,5};
    vector<double> vec2{1.1,2.2,3.3,4.4,5.5};
    cout << my_max8_3(vec1,vec2) << endl;

    cout << "-------仅auto，auto和decltype混合使用" << endl;
    int a{1},b{2};
    // cout << &my_max8_4(a,b) << endl;// 无法调用，因为返回值是值类型，为左值，无法取地址
    cout << &my_max8_5(a,b) << endl;
    
    cout << "decltype(auto)返回语句的表达式未用到模板参数类型" << endl;
    cout << typeid(my_max8_6(a,b)).name() << endl;


    vector vec{vector<int>{1,2,}};
}


// 9.9 模板参数的默认值
// 较于函数参数的默认值，模板参数的默认值更加灵活，可以指定默认值的模板参数可以放在任意位置
template <typename TReturn = double, typename T1, typename T2>
TReturn my_max9_1(T1 a, T2 b) {
    cout << "返回值类型默认为：double"<<endl;
    return a > b ? a : b;
}

template <typename T1, typename T2, typename TReturn = T1>
TReturn my_max9_2(T1 a, T2 b) {
    cout << "返回值类型默认为：第一个参数的类型"<<endl;
    return a > b ? a : b;
}

void test9(){
    cout << my_max9_1(1, 2.2) << endl;
    
    cout << my_max9_2(1, 2.2) << endl;

    cout << my_max9_2(1.1, 2.2) << endl;
}

//9.10 非类型的模板参数
// 非类型的模板参数是一个常量表达式，可以是整型、指针、引用、枚举、数组等
template <typename T,int lower, int upper>
bool in_range(T val) {
    cout << "T放在参数列表前面"<<endl;
    return val >= lower && val <= upper;
}

template <int lower, int upper, typename T>
bool in_range(T val) {
    cout << "T放在参数列表后面"<<endl;
    return val >= lower && val <= upper;
}

constexpr int get_sum(int a,int b){
    return a+b;
}
// 仅传入数组，可以由编译器推断出N的大小
template <typename T,size_t N>
T average(const T(&arr)[N]){
    cout << "数组大小: " << N << endl;
    T sum{};
    for (size_t i = 0; i < N; ++i) {
        sum += arr[i];
    }
    cout << "sum: " << sum << endl;
    return sum/N;
}



void test10(){
    int sum{10};
    // 因为<>需要按顺序指定，所以最好将T放在后面

    cout << in_range<int,1,get_sum(1,9)>(5) << endl;
    // 不指定上下限,编译失败
    // cout << in_range<>(5) << endl;
    cout << in_range<1,10>(sum) << endl;
    cout << in_range<1,get_sum(1,10)>(sum) << endl;
    const int t{10};
    cout << in_range<1,get_sum(1,t)>(sum) << endl;

    int arr[]{1,2,3,4,5};
    cout << average(arr) << endl;
    int* parr = arr;
    // cout << average(parr) << endl;// 无法编译，编译器无法从指针获得数组大小
    int arr2[]{1,2,3,4,5,7};
    cout << average(arr2) << endl;// 此时模板实例化为average<int,6>(arr2)，即大小不同的数组会实例化为不同的函数
}




int main() {

    cout << "测试：函数模板的实例" << endl;
    test2();
    cout << endl << "-----------------------------------------------" << endl;
    cout << "测试：const引用返回值，指向的是函数传参时的值吗" << endl;
    test3();
    cout << endl << "-----------------------------------------------" << endl;

    cout << "测试：显式指定模板实参" << endl;
    test4();
    cout << endl << "-----------------------------------------------" << endl;

    cout << "测试：函数模板的特例" << endl;
    test5();
    cout << endl << "-----------------------------------------------" << endl;

    cout << "测试：函数模板和重载" << endl;
    test6();
    cout << endl << "-----------------------------------------------" << endl;

    cout << "测试：多个参数的函数模板" << endl;
    test7();
    cout << endl << "-----------------------------------------------" << endl;

    cout << "测试：多个参数的函数模板" << endl;
    test8();
    cout << endl << "-----------------------------------------------" << endl;

    cout << "测试：模板参数的默认值" << endl;
    test9();
    cout << endl << "-----------------------------------------------" << endl;


    cout << "测试：非类型模板参数" << endl;
    test10();
    cout << endl << "-----------------------------------------------" << endl;
















    return 0;
}