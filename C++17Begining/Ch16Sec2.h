#pragma once
#include <iostream>
#include "NeedClass.h"


class Ch16Sec2{
public:
	static void test1() {
	}
	static void test2() {
		MyArray16_2_2<int> arr{ 4 };

		arr[0] = 1;
		arr[2] = 3;

		for ( size_t s = 0; s < arr.getSize(); s++){

			std::cout << arr[s] << std::endl;
		}

		
		MyArray16_2_2<int> arr1{ arr };
		MyArray16_2_2<int> arr2 = arr1;
	}
};

