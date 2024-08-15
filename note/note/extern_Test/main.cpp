#include <iostream>
#include "extern.cpp"

extern const int extern_int;
const int other_int = 20;

using namespace std;

int main(){

    cout << &other_int << endl;
    cout << &extern_int << endl;


    return 0;
}