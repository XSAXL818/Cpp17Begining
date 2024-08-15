#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 使用编译器提供的默认副本构造函数
class Box4_9_1 {
public:
	int m_length;
	int m_width;
	int m_height;

	Box4_9_1() = default;
	Box4_9_1(int length, int width, int height) : m_length{ length }, m_width{ width }, m_height{ height } {
		cout << "Box4_9_1(int length, int width, int height)" << endl;
	};

};

// 自定义副本构造函数
class Box4_9_2 {
public:
	int m_length;
	int m_width;
	int m_height;

	Box4_9_2() = default;
	Box4_9_2(int length, int width, int height) : m_length{ length }, m_width{ width }, m_height{ height } {
		cout << "Box4_9_1(int length, int width, int height)" << endl;
	};

	// 自定义副本构造函数
	/*Box4_9_1(Box4_9_1 box) {// 错误，会导致无限递归调用
		m_length = box.m_length;
		m_width = box.m_width;
		m_height = box.m_height;
		cout << "Box4_9(const Box4_9& box)" << endl;
	}*/
	Box4_9_2(const Box4_9_2& box) {
		m_length = box.m_length;
		m_width = box.m_width;
		m_height = box.m_height;
		cout << "Box4_9_1(const Box4_9& box)" << endl;
	}
};

class MyOops{
public:
	int* ptr;
	MyOops() : ptr { NULL } {}

	MyOops(int* i) : ptr{ i } {}
	

	void print() {
		cout << "*ptr=" << *ptr << endl;
	}

	void p( const MyOops& m ) {
		if (&m == this) {
			cout << "const 引用获取到了自己" << endl;
		}
	}
};

class NeedClass{};

class Box5 {
private:
	int side{ 0 };

public:
	Box5() = default;
	Box5(int s) : side{ s } {};

	int getSide(){return side;}
	bool setSide(int s) {
		if( isOk(s) ) { // 如果是复杂的校验逻辑，建议使用函数
			side = s;
			return true;
		}
		return false;
	}

	void print() {
		cout << "side: " << side << endl;
	}


private:
	bool isOk(int side) {
		if( side > 0 ) {
			return true;
		}
		return false;
	}

};

class This {
private:
	int m_a{ 0 };
	int m_b{ 0 };
	int m_c{ 0 };

public:
	This() = default;

	This* setA(int a) {
		m_a = a;
		return this;
	};

	This& setB(int b) {
		m_b = b;
		return *this;
	};

	void setC(int c) {
		cout << "this: " << this << endl; // this指针指向当前对象
		m_c = c;
	};

	void print() {
		cout << "a: " << m_a << " b: " << m_b << " c: " << m_c << endl;
	}
	// 编译器实现
	/*void print() {
		cout << "a: " << this->m_a << " b: " << this->m_b << " c: " << this->m_c << endl;
	}*/
};


class Box7_1_1 {
private:
	int m_length;
	int m_width;
	int m_height;

public:
	//getter and setter
	int getLength() { return m_length; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }

	void setLength(int length) { m_length = length; }
	void setWidth(int width) { m_width = width; }
	void setHeight(int height) { m_height = height; }

	// 构造函数
	Box7_1_1(int length = 1, int width = 1, int height = 1) : m_length{ length }, m_width{ width }, m_height{ height } {
		cout << "Box7_1_1(int length = 1, int width = 1, int height = 1)" << endl;
	}
	Box7_1_1() = default;
	
};

class Box7_1_2 {
private :
	int m_length;
	int m_width;
	int m_height;

public:
	Box7_1_2() = default;
	Box7_1_2(int length, int width, int height) : m_length{ length }, m_width{ width }, m_height{ height } {
		cout << "Box7_1_2(int length, int width, int height)" << endl;
	}

	// 将不修改成员变量的函数设置为const
	int getLength() const { return m_length; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }

	// 修改成员变量的函数设置为const会报错
	void setLength(int length) { m_length = length; }
	void setWidth(int width) { m_width = width; }
	void setHeight(int height) { m_height = height; }

};

class Box7_3_1 {
private:
	int m_a{ 0 }, m_b{ 0 }, m_c{ 0 };

public:
	Box7_3_1() = default;
	Box7_3_1(int a, int b, int c) : m_a{ a }, m_b{ b }, m_c{ c } {
		cout << "Box7_3_1(int a, int b, int c)" << endl;
	}
	// 为使用传统的getter和setter
	int& a(){ return m_a; }
	int& b(){ return m_b; }
	int& c(){ return m_c; }

};


class Box7_3_2 {
private:
	int m_a{ 0 }, m_b{ 0 }, m_c{ 0 };

public:
	Box7_3_2() = default;
	Box7_3_2(int a, int b, int c) : m_a{ a }, m_b{ b }, m_c{ c } {}
	// 为使用传统的getter和setter
	int& a() { 
		cout << "非const版本\n";
		return m_a; 
	}
	int& b() { 
		cout << "非const版本\n";
		return m_b;
	}
	int& c() { 
		cout << "非const版本\n";
		return m_c; 
	}
	// 使用const重载，需要将返回类型修改为const修饰
	const int& a() const { 
		cout << "const版本\n";
		return m_a; 
	}
	const int& b() const { return m_b; }
	const int& c() const { return m_c; }
	
};

class Log7_5 {
private:
	// const对象仍可以修改该变量
	mutable int cnt{ 0 };

public:
	Log7_5() = default;

	void write(string msg) const {
		cout << ++cnt << ": " << msg << endl;	
	}
};


class Test {
public:

};

class Box8_1_1;
class BoxFridend {
public:
	static void toCubeFridend(Box8_1_1& box);
};



class Box8_1_1 {
private:
	int l{ 0 }, w{ 0 }, h{ 0 };

public:

	Box8_1_1() = default;
	Box8_1_1(int length, int width, int height) : l{ length }, w{ width }, h{ height } {
		cout << "Box8_1_1(int length, int width, int height)" << endl;
	}
	void print() {
		cout << "l: " << l << " w: " << w << " h: " << h << endl;
	}
	friend void toCube(Box8_1_1& box);
	friend void BoxFridend::toCubeFridend(Box8_1_1& box);
};


class Fri;

class Box8_2 {
private:
	int l{ 0 }, w{ 0 }, h{ 0 };
public:
	Box8_2(int length, int width, int height) : l{ length }, w{ width }, h{ height } {
		cout << "Box8_2(int length, int width, int height)" << endl;
	}

	void print() {
		cout << "l: " << l << " w: " << w << " h: " << h << endl;
	}
	
	friend class Fri;
};


class Cube9 {
private:
	int side{ 0 };
	
public:
	Cube9() {
		cout << "默认构造函数" << endl;
	};
	Cube9(int _side) : side(_side) {
		cout << "Cube(int _side)构造函数" << endl;
	}

	Cube9(const Cube9& c) {
		cout << "副本构造函数" << endl;
	}

	void print() {
		cout << "side: " << side << endl;
	}
};


class MyVector {
private:
	vector<int> vec;

public:
	/*static const int m_a{0};*/
	static inline int m_a{ 0 };
	static int m_b;
	MyVector() = default;

	MyVector(const vector<int>& v) : vec{ v } {
		//m_a++;
		cout << "MyVector(vector<int> v)" << endl;
	}
};


class Static11_11_1_1 {
public:
	static int cnt;

	int unuse;

	Static11_11_1_1() {
		cnt++;
	};

	// 委托
	Static11_11_1_1(int u) : Static11_11_1_1() {};

	int objCnt() const {// const对象也可以调用
		return cnt;
	}
};

class Static11_11_1_2 {
public:
	static inline int cnt;

	int unuse{ 0 };

	Static11_11_1_2() {
		cnt++;
	};

	// 委托
	Static11_11_1_2(int u) : Static11_11_1_2() {};

	int objCnt() const {// 返回对象个数和该函数的调用次数
		return ++cnt;
	}
};


// 圆柱形盒子类
class CylindricalBox11_11_3 {
public:
	static inline const double MAXRADIUS{ 10.0 };
	static inline const double MAXHEIGHT{ 25.0 };
	static inline const string DEFAULTMATERIAL{ "Cardboard" };
	
	CylindricalBox11_11_3() = default;
	CylindricalBox11_11_3(double r, double h, string m) : radius{ r }, height{ h }, material{ m } {
		cout << "CylindricalBox11_11_3(double r, double h, string m)" << endl;
	}
	double volume() const;

	string getMaterial() { return material; };

private:
	static inline const double PI{ 3.1415926 };

	double radius;
	double height;
	string material;
};

class Box11_11_5 {
private:
	int l{ 0 }, w{ 0 }, h{ 0 };

public:
	Box11_11_5()= default;
	Box11_11_5(int length, int width, int height) : l{ length }, w{ width }, h{ height } {
		cout << "Box11_11_5(int length, int width, int height)" << endl;
	}

	void print() {
		cout << "l: " << l << " w: " << w << " h: " << h << endl;
	}

	// 传入对象可以访问私有成员
	static void toCube(Box11_11_5& b) {
		b.w = b.h = b.l;
	}
	// 静态成员函数中无this指针，使用const修饰无意义，所以不允许
	//static void nonConst() const {}
};


class Box11_11_12_1 {
private:
	int side{ 0 };

public:

	static inline int objCnt{ 0 };

	Box11_11_12_1() {
		++objCnt;
		cout << "默认构造函数" << endl;
	}

	Box11_11_12_1(int s) : side{ s } {
		++objCnt;
		cout << "带参构造函数" << endl;
	}

	Box11_11_12_1(const Box11_11_12_1& bb) {
		cout << "副本构造函数" << endl;
		++objCnt;
		side = bb.side;
	}

	void print() {
		cout <<"side: " << side << endl;
	}

	~Box11_11_12_1() {
		objCnt--;
		cout << "析构函数" << endl;
	}
};



class Cube11_13 {
private:
	int side{ 0 };

public:
	Cube11_13() {
		cout << "默认构造函数" << endl;
	}

	Cube11_13(int s) : side{ s } {
		cout << "带参构造函数" << endl;
	}

	Cube11_13(const Cube11_13& c) {
		cout << "副本构造函数" << endl;
	}

	void print() {
		cout << "side: " << side << endl;
	}

	int getSide() const { return side; }

	int volume() const {
		return side * side * side;
	}

	bool isBiggerThan(const Cube11_13& c) const {
		return volume() > c.volume();
	}

	int compare(const Cube11_13& c) const {
		if (volume() > c.volume()) {
			return 1;
		} else if (volume() < c.volume()) {
			return -1;
		} else {
			return 0;
		}
	}

};

using SharedCube = shared_ptr<Cube11_13>;

// 包装，将Cube包装为链表
class Package11_13 {
private:
	// 共享指针，可以用于多个对象共享一个对象
	SharedCube cube;
	// 用于指向下一个包裹
	Package11_13* pNext{ nullptr };

public:
	Package11_13(SharedCube cube) : cube{ cube } {	}
	// 删除头包裹后，其后所有包括被删除
	~Package11_13() {
		delete pNext;// 不需要检查pNext是否为nullptr，因为delete nullptr是安全的
		pNext = nullptr;// 可以不设置，因为上层进行相关的控制，不会访问删除包裹及之后的包裹
	}
	// 获取Cube
	SharedCube getCube() const {
		return cube;
	}

	// 设置Cube
	void setCube(SharedCube cube) {
		this->cube = cube;
	}

	// 获取下一个包裹
	Package11_13* getNext() const {
		return pNext;
	}
	// 设置下一个包裹
	void setNext(Package11_13* next) {
		pNext = next;
	}
};

class Truckload11_13 {
private:
	// 用于指向第一个包裹
	Package11_13* pHead{ nullptr };
	// 指向最后一个包裹，便于添加新包裹
	Package11_13* pTail{ nullptr };
	// 记录当前访问的包裹
	Package11_13* pCurrent{ nullptr };

public:

	Truckload11_13() = default;
	// 单个包裹
	Truckload11_13(SharedCube cube) {
		pHead = pTail = new Package11_13{ cube };
	}
	// 多个包裹
	Truckload11_13(const vector<SharedCube>& cubes){
		for (const auto& cube : cubes) {
			addCube(cube);
		}
	}
	// 副本构造函数
	Truckload11_13(const Truckload11_13& truckload) {
		for (Package11_13* head = truckload.pHead; head; head = head->getNext() ) {
			addCube(head->getCube());
		}
	}

	// 析构函数
	~Truckload11_13() {
		delete pHead;
		pHead = pTail = nullptr;
	}

	// 获取第一个Cube
	SharedCube getFirstCube() {
		pCurrent = pHead;
		return pHead != nullptr ?  pHead->getCube() : nullptr;
	}
	// 获取下一个Cube
	SharedCube getNextCube() {
		if (pCurrent == nullptr) {// 返回第一个Cube
			return getFirstCube();
		}
		pCurrent = pCurrent->getNext();
		return pCurrent != nullptr ? pCurrent->getCube() : nullptr;
	}
	// 添加Cube
	void addCube(SharedCube cube) {
		auto newPackage = new Package11_13{ cube };
		if (pHead == nullptr) {
			pHead = newPackage;
		} else {
			pTail->setCube(cube);
		}
		pTail = newPackage;
	}
	// 删除Cube
	// 思考：可以直接判断第一个是否为要删除的
	bool removeCube(const SharedCube& cube) {
		Package11_13* pre{ nullptr };
		Package11_13* cur{ pHead };
		while (cur) {
			// 找要删除的Cube
			if (cube->compare(*cur->getCube())) {
				if (cur == pHead) {// 判断是否未第一个Cube
					// 让第一个的下一个作为第一个
					pHead = cur->getNext();
				}
				else {
					// 让前一个的下一个指向当前的下一个
					pre->setNext(cur->getNext());
				}
				// 删除当前包裹
				cur->setNext(nullptr);// 防止删除后，后续包裹被删除
				delete cur;
				return true;
			}
		}
		return false;
	}
	// 打印所有Cube
	void listCubes() const {
		const int perLine{ 5 };
		int cnt{ 0 };
		for (Package11_13* index = pHead; index; index = index->getNext() ) {
			cout << index->getCube()->getSide() << " ";
			if ((++cnt) % perLine == 0) {
				cout << endl;
			}
		}
		if (cnt % perLine > 0) {// 如果最后一行没有满，换行
			cout << endl;
		}
	}


};


class B14 {
public:
	class iterator {
	private:
		int a;
	public:
		int b;

		void print() {
			privateClass p;
			cout << p.a << " " << p.b << endl;
		}
	};

private:
	class privateClass {
	public:
		int a{ 1 };
		int b{ 1 };
	};
};


class Cube12_1_2 {
private:
	int side;

public:
	
	Cube12_1_2() = default;
	Cube12_1_2(int _side) : side{_side}{}


	bool operator<(const Cube12_1_2& c) {
		cout << "小于< 运算符重载版本1\n";
		return side < c.side;
		// or
		return getVolume() < c.getVolume();
	}

	bool operator<(int v) {
		cout << "小于< 运算符重载版本2\n";
		return getVolume() < v;
	}

	void operator=(const Cube12_1_2& c) {
		cout << "赋值= \n";
		side = c.side;
	}

	int getVolume() const {
		return pow(side, 3);
	}
};

class Cube12_1_3 {
private:
	int side;
public:
	Cube12_1_3() = default;

	// 防止出现 3 作为参数被隐式转换为该对象。
	explicit Cube12_1_3(int _side) : side{_side}{}

	int getVolume() const {// 别忘了声明为const
		return pow(side, 3);
	}

	friend bool operator<(const Cube12_1_3& c1, int side);
};

inline bool operator<(const Cube12_1_3& c1, const Cube12_1_3& c2) {
	return c1.getVolume() < c2.getVolume();
}

inline bool operator<(const Cube12_1_3& c1, int side) {
	return c1.side < side;
}


class Cube12_1_4_1 {
private:
	int side;
public:
	Cube12_1_4_1() = default;

	Cube12_1_4_1(int _side) : side{ _side } {}

	int getVolume() const {// 别忘了声明为const
		return pow(side, 3);
	}
};

inline bool operator<(const Cube12_1_4_1& c1, const Cube12_1_4_1& c2) {
	return c1.getVolume() < c2.getVolume();
}


class Cube12_1_4_2 {
private:
	int side;
public:
	Cube12_1_4_2() = default;

	explicit Cube12_1_4_2(int _side) : side{ _side } {}

	int getVolume() const {// 别忘了声明为const
		return pow(side, 3);
	}
};

inline bool operator<(const Cube12_1_4_2& c1, const Cube12_1_4_2& c2) {
	return c1.getVolume() < c2.getVolume();
}


class Double {
public:
	double v;
	Double() = default;
	Double(double _v) : v{ _v } {}
};;

class Cube12_1_4_3 {
private:
	int side;
public:
	Cube12_1_4_3() = default;

	explicit Cube12_1_4_3(int _side) : side{ _side } {}

	int getVolume() const {// 别忘了声明为const
		return pow(side, 3);
	}
	// 处理对象 < 体积数值
	inline bool operator<(int v) {
		return getVolume() < v;
	}

	bool operator<(Double v) const;
	friend bool operator<(int v, const Cube12_1_4_3& c);


};

inline bool Cube12_1_4_3::operator<(Double v) const {
	cout << "类外定义\n";
	return this->getVolume() < v.v;
}

inline bool operator<(const Cube12_1_4_3& c1, const Cube12_1_4_3& c2) {
	return c1.getVolume() < c2.getVolume();
}

//体积数值 < 对象
inline bool operator<(int v, const Cube12_1_4_3& c) {
	return v < c.getVolume();
}

#include <utility>
using namespace std::rel_ops;
class Cube12_1_5 {
private:
	int side;

public:
	Cube12_1_5() = default;
	explicit Cube12_1_5(int _side) : side{ _side }{}

	bool operator<(const Cube12_1_5& c) const {
		return side < c.side;
	}

	bool operator==(const Cube12_1_5& c) const {
		return side == c.side;
	}

	int getVolume() const {
		return pow(side, 3);
	}
};


class Box12_4_1 {
private:
	int h{ 0 };
	int w{ 0 };
	int l{ 0 };

public:
	Box12_4_1(int height,int width, int length) : l{length},w{width},h{height} {}

	inline ostream& operator<<(ostream& stream) {
		stream << "{l:" << l << ",h:" << h << ",w:" << w << "}";
		return stream;
	}

	int getLength() const {
		return l;
	}
	int getWidth() const {
		return w;
	}
	int getHeigth() const {
		return h;
	}


};


inline std::ostream& operator<<(std::ostream& stream, const Box12_4_1& b) {
	stream << "{l:" << b.getLength() << ",h:" << b.getHeigth() << ",w:" << b.getWidth() << "}";
	return stream;
};


class Cube12_5_1 {
private:
	double side;

public:
	Cube12_5_1() = default;

	explicit Cube12_5_1(double _side) : side{ _side } {}

	// 获取两个体积相加后的Cube
	inline Cube12_5_1 operator+(const Cube12_5_1& c) const {
		
		//cout << "new Cube: " << pow(getVolume() + c.getVolume(), 1.0 / 3) << endl;
		return Cube12_5_1{ pow(getVolume() + c.getVolume(), 1.0 / 3) };
	}
	double getVolume() const {
		return pow(side, 3);
	}

};

class Cube12_5_2 {
private:
	double side;

public:
	Cube12_5_2() = default;

	explicit Cube12_5_2(double _side) : side{ _side } {}
	inline Cube12_5_2& operator+=(const Cube12_5_2& c) {
		side = pow(getVolume() + c.getVolume(), 1.0 / 3);
		return *this;
	}
	// 获取两个体积相加后的Cube
	inline Cube12_5_2 operator+(const Cube12_5_2& c) const {
		return Cube12_5_2{ *this } += c;
	}
	double getVolume() const {
		return pow(side, 3);
	}
};


class Integer12_6 {
private:
	int value;

public:
	Integer12_6(int i=0) : value{i}{}

	int getValue() const {
		return value;
	}

	void setValue(int i) {
		value = i;
	}
};

inline Integer12_6 operator+(const Integer12_6& v1,const Integer12_6& v2) {
	return v1.getValue() + v2.getValue();
}

class Matrix12_7 {
private:
	int row;
	int col;

public:
	Matrix12_7(int r=0, int c=0) : row{ r }, col{ c } {}

	// 转置矩阵
	Matrix12_7 operator~() {
		return Matrix12_7{ col,row };
	}
	int getRow() {
		return row;
	}
	int getCol() {
		return col;
	}
	void setRow(int r) {
		row = r;
	}
	void setCol(int c) {
		col = c;
	}
};

// 归零
inline Matrix12_7 operator!(const Matrix12_7& m) {
	return Matrix12_7{};
}

class Cube12_8 {
public:
	int side;

	Cube12_8(int s= 0) : side{s}{}

	// 前++，返回引用
	Cube12_8& operator++() {
		side++;
		return *this;
	}
	// 后++，使用int作为区别
	Cube12_8 operator++(int) {
		return Cube12_8{ side+1 };
	}

};

class Matrix12_9 {
private:
	int row;
	int col;
	vector<vector<int>> data;

public:
	Matrix12_9(int r=0,int c=0):row{ r }, col{ c } {
		data.resize(row);
		for (auto& d : data) {
			d.resize(col);
		}
	}
	Matrix12_9(const vector<vector<int>>& d) : data{ d } {
		row = data.size();
		col = data[0].size();
	}
	vector<int>& operator[](int row) {
		return data[row];
	}
};


class Volume {
private:

public:
	double operator()(double x, double y, double z) {
		return x * y * z;
	}
};



class Sum {
private:

public:
	double operator()(const vector<int>& vec) {
		int sum{ 0 };
		for (const auto& a : vec) {
			sum += a;
		}
		return sum;
	}

	double operator()(const vector<vector<int> >& vec) {
		int sum{ 0 };
		for (const auto& a : vec) {
			sum += (*this)(a);
		}
		return sum;
	}
};

class Box12_10_1;

class Cube12_10_1 {
private:
	int side;

public:
	Cube12_10_1(int s = 0) : side{ s } {}
	
	int getVolume() { return pow(side, 3); }

	Cube12_10_1(const Box12_10_1& box);

};

class Box12_10_1 {
private:
	int side;

public:
	Box12_10_1(int s = 0) : side{ s } {}

	operator int() const {
		return pow(side, 3);
	}

	int getSide() const {
		return side;
	}

	operator Cube12_10_1() {
		cout << "box类型转换为cube\n";
		return Cube12_10_1{ side };
	}

};




class Msg12_12_1{
private:
	string* pTxt;

public:
	Msg12_12_1() {
		cout << "默认构造函数\n";
		pTxt = new string();
	}

	Msg12_12_1(const string& str) {
		pTxt = new string();
		*pTxt = str;
	}
	// 存在bug版本
	/*Msg12_12_1& operator=(const Msg12_12_1& msg) {
		cout << "=运算符重载\n";
		delete pTxt;
		pTxt = new string{ *msg.pTxt };
		return *this;
	}*/

	// 修改后，避免自己复制赋值给自己
	Msg12_12_1& operator=(const Msg12_12_1& msg) {
		cout << "=运算符重载\n";
		if (*pTxt == msg.getTxt()) {
			return *this;
		}
		delete pTxt;
		pTxt = new string{ *msg.pTxt };
		return *this;
	}

	Msg12_12_1(const Msg12_12_1& msg) {
		cout << "副本构造函数\n";
		pTxt = new string{ *msg.pTxt };
	}

	~Msg12_12_1() {
		delete pTxt;
	}

	void setTxt(const string& txt) {
		*pTxt = txt;
	}

	string getTxt() const {
		return *pTxt;
	}

};


class Msg12_12_2 {
private:
	string msg;
public:
	string getMsg() const {
		return msg;
	};

	Msg12_12_2(string str="") : msg{str}{}

	Msg12_12_2& operator=(const string& m) {
		cout << "赋值运算符\n";
		msg = m;
		return *this;
	}

};



class Box13_1_1 {
private:
	int height{ 1 };
	int width{ 1 };
	int length{ 1 };

public:

	Box13_1_1(int h, int w, int l) : height{ h }, width{ w }, length{ l } {}

	inline int getVolume() const {
		return height * width * length;
	}
};


class MyBox13_1_1_private : private Box13_1_1 {
public:
	void print() {
		// 不能直接访问
		//cout << this->height << endl;
	}
};

class MyBox13_1_1_public : public Box13_1_1 {
private:
	string name;

public:

	MyBox13_1_1_public(int h,int w, int l) : Box13_1_1(h,w,l){}

	void print() {
		// 不能直接访问
		//cout << this->height << endl;

	}
};

class Box13_3_1 {
protected:
	int height{ 1 };
	int width{ 1 };
	int length{ 1 };

public:

	Box13_3_1(int h, int w, int l) : height{ h }, width{ w }, length{ l } {}

	inline int getVolume() const {
		return height * width * length;
	}
};


class MyBox13_3_1_public : public Box13_3_1 {
private:
	string name;

public:

	MyBox13_3_1_public(int h, int w, int l) : Box13_3_1(h, w, l) {}

	void print() {
		// 可以访问了
		cout << this->height << endl;
	}
};


class Box13_4_1 {
private:
	int height{ 1 };
protected:
	int width{ 1 };
public:
	int length{ 1 };

	inline int volume() const {
		return height * width * length;
	}

};

class MyBox13_4_1 : private Box13_4_1 {


public:
	void print() {
	}
	using Box13_4_1::volume;
	//using Box13_4_1::height;// 无法访问基类的私有成员
};


class Box13_5_1_1 {
public:
	Box13_5_1_1() {
		cout << "1" << endl;
	}
};

class Box13_5_1_2  : Box13_5_1_1 {
protected:
	int a;
public:
	Box13_5_1_2() {
		cout << "2" << endl;
	}

	Box13_5_1_2(int i) {
		cout << "2-2" << endl;
	}
};

class Box13_5_1_3 : Box13_5_1_2 {
public:
	Box13_5_1_3() : Box13_5_1_2(4){
		cout << "3" << endl;
	}

	// 在进入函数体前，基类对象还未创建
	/*Box13_5_1_3(int _a) : a(a) {
		cout << "3" << endl;
	}*/
	Box13_5_1_3(int _a) {
		cout << "3" << endl;
		a = _a;
	}
};



class Box13_6_1_1 {
private:
	int height{ 1 };
	int width{ 1 };
	int length{ 1 };

public:
	Box13_6_1_1(const Box13_6_1_1& box) {
		cout << "Box的副本构造函数" << endl;
		height = box.height;
		width = box.width;
		length = box.length;
	}
	Box13_6_1_1() {
		cout << "Box默认构造函数" << endl;
	}
	Box13_6_1_1(int h, int w, int l) : height{ h }, width{ w }, length{ l } {
		cout << "Box带参构造函数" << endl;
	}

	int volume() {
		return height * width * length;
	}
};


class MyBox13_6_1_1 : private Box13_6_1_1 {
private:
	string name;

public:

	using Box13_6_1_1::volume;

	/*MyBox13_6_1_1(const MyBox13_6_1_1& mBox) {

	}*/
	// 不指定将会调用默认的构造函数
	MyBox13_6_1_1(const MyBox13_6_1_1& mBox) : Box13_6_1_1{ mBox } {
		cout << "MyBox的副本构造函数" << endl;
	}

	MyBox13_6_1_1(int h,int w,int l) : Box13_6_1_1{ h,w,l } {
		cout << "MyBox的带参构造函数" << endl;
	}

};


class Box13_6_1_2 {
private:
	int height{ 1 };
	int width{ 1 };
	int length{ 1 };

public:
	Box13_6_1_2(const Box13_6_1_2& box) {
		height = box.height;
		width = box.width;
		length = box.length;
	}
	Box13_6_1_2() {
	}
	Box13_6_1_2(int h, int w, int l) : height{ h }, width{ w }, length{ l } {
	}

	int volume() {
		return height * width * length;
	}
};

class MyBox13_6_1_2 : private Box13_6_1_2 {
private:
	string name;

public:
	using Box13_6_1_2::volume;

	MyBox13_6_1_2(int h,int w,int l) : Box13_6_1_2{ h,w,l } {}

	MyBox13_6_1_2() {
		cout << "默认构造函数" << endl;
	}

};

class MyBox13_6_1_3 : private Box13_6_1_2 {
private:
	string name;

public:

	using Box13_6_1_2::volume;

	MyBox13_6_1_3(int h, int w, int l) : Box13_6_1_2{ h,w,l } {}

	MyBox13_6_1_3(const MyBox13_6_1_3& box) {
		cout << "手动实现副本构造函数" << endl;
	}

};


class Box13_5_2_1 {
private:
	Box13_5_2_1() = default;
};

class MyBox13_5_2_1 : public Box13_5_2_1 {
public:
	MyBox13_5_2_1() = default;
};




class Box13_5_3_1 {
private:
	int a;

public:
	Box13_5_3_1() {
		cout << "默认构造函数" << endl;
	}
	Box13_5_3_1(int _a) : a{ _a } {
		cout << "带参构造函数" << endl;
	}
};

class MyBox13_5_3_1 : private Box13_5_3_1 {
private:
	int b{ 1 };

public:
	MyBox13_5_3_1() {
		cout << "默认构造函数" << endl;
	}
	MyBox13_5_3_1(int _a, int _b) : Box13_5_3_1{ _a }, b{ _b } {
		cout << "带参构造函数" << endl;
	}
};



class Box13_6_1 {
private:
	int side;
public:

	~Box13_6_1() {
		cout << "Box的析构函数" << endl;
	}
};

class MyBox13_6_1 : private Box13_6_1 {
private:
	int name;
public:

	~MyBox13_6_1() {
		cout << "MyBox的析构函数" << endl;
	}
};


class Box13_7_1 {
protected:
	int side{ 2 };
};

class MyBox13_7_1 : Box13_7_1 {
private:
	int side;

public:
	MyBox13_7_1(int s) : side{ s } {

	}

	int total() {
		return side + Box13_7_1::side;
	}
};


class Box13_8_1 {
private:

public:
	void doit(int x) {
		cout << "int: " << x << endl;
	}
	void doDouble(double x) {
		cout << "double: " << x << endl;
	}
};


class MyBox13_8_1 : public Box13_8_1 {
private:
	
public:
	// public修饰，所以基类的doDouble函数的修饰符也是public
	using Box13_8_1::doDouble;

	void doit() {
		// 因为和基类同名，所以会隐藏基类的同名函数
		// 使用using 可以获取基类的同名函数
		//doit(5);
		doDouble(3.0);
	}
	// 使用using获取基类的同名函数
	void doDouble() {
		Box13_8_1::doDouble(3.0);
		doDouble(4.5);
	}
};

class MyBox13_8_2 : public Box13_8_1 {
private:

public:
	// public修饰，所以基类的doDouble函数的修饰符也是public
	using Box13_8_1::doDouble;

	void doit() {
		// 因为和基类同名，所以会隐藏基类的同名函数
		// 使用using 可以获取基类的同名函数
		//doit(5);
		doDouble(3.0);
	}
	// 使用using获取基类的同名函数
	void doDouble(double x) {
		cout << "MyBox13_8_2重载: " << x << endl;
		Box13_8_1::doDouble(x);

	}
};



class Box14_1_1 {
private:
	int side{ 1 };
public:
	Box14_1_1() = default;
	Box14_1_1(int s) : side{ s } {}

	int getSide() const {
		return side;
	}
	int volume() const {
		return side * side * side;
	}

	void showVolume() const {
		cout << "Volume: " << volume() << endl;
	}
};


class ABox14_1_1 : public Box14_1_1 {
private:
	string name{ "A" };
	double base;
public:

	ABox14_1_1() = default;
	ABox14_1_1(int s, double b=0.8) : Box14_1_1{ s }, base{ b } {}

	int volume() {
		return getSide() * getSide() * getSide() * base;
	}
	void showVolume() {
		cout << "ABox Volume: " << volume() << endl;
	}
};


class Box14_3_1 {
private:
	int side;
public:
	Box14_3_1(int s) : side{s}{}
	virtual int volume() {
		return pow(side, 3);
	}

	void showVolume() {
		cout << "Box Volume: " << volume() << endl;
	}
	int getSide() {
		return side;
	}

	virtual void print() {
		cout << "Box...." << endl;
	}

	virtual void outsideFun();

};

class ABox14_3_1 : public Box14_3_1 {
private:
	double base;

public:
	ABox14_3_1(int s, double b = 0.8) : base{ b }, Box14_3_1{s} {}

	int volume() {
		return pow(getSide(), 3) * base;
	}

	void print(int x) {
		cout << "ABox...." << x << endl;
	}

};


class Box14_3_2 {
private:
	int side;

public:
	Box14_3_2(int s = 1) : side{ s } {}

	virtual Box14_3_2& print() {
		cout << "Box print..." << endl;
		return *this;
	}

	virtual void myFun() {
		cout << "Box : myFun" << endl;
	}
	
};

class ABox14_3_2 : public Box14_3_2 {
public:
	// 返回类型不同也不协同
	//int print() {}

	ABox14_3_2(int side) : Box14_3_2{ side } {}

	ABox14_3_2& print() {
		cout << "ABox print..." << endl;
		return *this;
	}
	// 相同
	/*Box14_3_2& print() {
		cout << "ABox print..." << endl;
		return *this;
	}*/

	void myFun() const {
		cout << "ABox : myFun" << endl;
	}
};

class Box14_3_3 {
private:
	int side;
public:
	Box14_3_3(int s = 1) : side{1}{}

	virtual void print() const {
		cout << "Box print..." << endl;
	}
};

class ABox14_3_3 : public Box14_3_3 {
public:

	// 编译器报错
	//void print() override {}
	// 与基类虚函数的函数签名相同时,不报错
	void print() const override {}
};


class Box14_3_4 {
private:
	int side;
public:
	Box14_3_4(int s = 1) : side{ 1 } {}
	// 基类使用final，防止派生类重写
	virtual void printVersion() const  final {
		cout << "Box print..." << endl;
	}

};

class ABox14_3_4 final : public Box14_3_4  {
public:
	// 编译器报错
	//void printVersion() const override {};
};

// 编译器报错
//class BBox14_3_4 : public ABox14_3_4 {};


class Box14_3_5 {
private:
	int side;
public:
	Box14_3_5(int s = 1) : side{ 1 } {}
	// 基类使用final，防止派生类重写
	virtual void printVersion() const  {
		cout << "Box print..." << endl;
	}
};

class ABox14_3_5 : public Box14_3_5 {
private:
	virtual void printVersion() const override {
		cout << "ABox print..." << endl;
	}

public:
	ABox14_3_5(int s = 1) : Box14_3_5{s}{}
};


class Box14_1_4_1 {
public:
	virtual int getThree(int v = 1) {
		return pow(v, 3);
	}
};

class ABox14_1_4_1 : public Box14_1_4_1 {
public:
	int getThree(int v = 10) override {
		return pow(v, 3);
	}
};

class Box14_1_5_1 {
private:
	int side;
public:
	Box14_1_5_1(int s = 1) :side{ s } {}

	virtual int getVolume() const {
		return pow(side, 3);
	}
	virtual void showVolume() const {
		cout << "Box Volume: " << getVolume() << endl;
	}
};

class ABox14_1_5_1 : public Box14_1_5_1 {
public:
	ABox14_1_5_1(int s = 1) :Box14_1_5_1{ s } {}

	virtual int getVolume() const override { return 0.9* Box14_1_5_1::getVolume(); }
	void showVolume() const override {
		cout << "ABox Volume: " << getVolume() << endl;
	}
};

inline void showVolume14_1_5(Box14_1_5_1& box) {
	cout << "Volume: " << box.getVolume() << endl;
}



class Box14_1_7_1 {
private:
public:
	~Box14_1_7_1() {
		cout << "Box ~" << endl;
	}
};

class ABox14_1_7_1 : public Box14_1_7_1 {

public:
	~ABox14_1_7_1() {
		cout << "ABox ~" << endl;
	}
};

class Box14_1_7_2 {
private:
public:
	virtual ~Box14_1_7_2() {
		cout << "virtual Box ~" << endl;
	}
};

class ABox14_1_7_2 : public Box14_1_7_2 {

public:
	~ABox14_1_7_2() {
		cout << "virtual ABox ~" << endl;
	}
};


class Box14_1_8_1 {
private:
	int side;
public:
	Box14_1_8_1(int s = 1) : side{ s } {}

	virtual int getVolume() const {
		return pow(side, 3);
	};
};

class ABox14_1_8_1 : public Box14_1_8_1 {

public:
	int b, c, d;
	ABox14_1_8_1(int s = 1) : Box14_1_8_1{ s } {}

	virtual int getVolume() const {
		return Box14_1_8_1::getVolume()*0.8;
	};

	void print() {
		cout << "ABox" << endl;
	}

};

class BBox14_1_8_1 : public ABox14_1_8_1 {
public:
	BBox14_1_8_1(int s = 1) : ABox14_1_8_1{ s } {}

	virtual int getVolume() const {
		return Box14_1_8_1::getVolume()*0.5;
	};
};


class StaticCast {
private:
	int a;

public:
	StaticCast(int _a) : a{ _a } {};

	void setA(int _a) {
		a = _a;
	}

	int getA() const {
		return a;
	}
	
};

class BB {
private:
	int c;
public:
	BB(int _c) : c{ _c } {};


	int getC() const {
		return c;
	}
	void setC(int _c) {
		c = _c;
	}
	operator StaticCast() {
		cout << "重载类型转换\n";
		return StaticCast{ c };
	}

};


class Box14_1_9_1 {
private:
	int side;
public:
	Box14_1_9_1(int s = 1) : side{ s } {}

	virtual int getVolume() const {
		return pow(side, 3);
	}

	virtual void showVolume() const {
		cout << "Box Volume: " << getVolume() << endl;
	}
};

class ABox14_1_9_1 : public Box14_1_9_1 {
private:
	static inline int base = 0.8;
public:

	ABox14_1_9_1(int side = 1) :Box14_1_9_1{ side } {}

	virtual int getVolume() const override {
		return Box14_1_9_1::getVolume()*base;
	}

	virtual void showVolume() const override {
		cout << "ABox Volume: " << getVolume() << endl;
	}
};

class BBox14_1_9_1  {
private:
	static inline double base = 0.5;
public:
	BBox14_1_9_1(int side=1){}

	void show() {
		cout << "BBox"<<endl;
	}
};


class ABBox14_1_9_1 : virtual public BBox14_1_9_1,virtual public ABox14_1_9_1 {
private:
	static inline double base{0.4};
public:

	ABBox14_1_9_1(int side = 1) :ABox14_1_9_1{ side } {}

	virtual int getVolume() const override {
		return Box14_1_9_1::getVolume() * base;
	}

	virtual void showVolume() const override {
		cout << "ABBox Volume: " << getVolume() << endl;
	}
};


inline void showVolume14_1_9_1(Box14_1_9_1& box) {
	ABox14_1_9_1& aBox = dynamic_cast<ABox14_1_9_1&>(box);
	cout << "ABox Volume: " << aBox.getVolume() << endl;
}

inline void showVolume14_1_9_2(Box14_1_9_1& box) {
	ABox14_1_9_1* aBox = dynamic_cast<ABox14_1_9_1*>(&box);
	if (aBox == nullptr) {
		return;
	}
	cout << "ABox Volume: " << box.getVolume() << endl;
}

class Box14_1_10 {
private:
	int side;
public:
	Box14_1_10(int s) : side{ s } {}

	virtual int volume() const {
		return pow(side, 3);
	}
};

class MyBox14_1_10 : public Box14_1_10 {
private:
	double base = 0.8;
public:
	MyBox14_1_10(int s) : Box14_1_10{s}{}
	
	int volume() const override {
		return Box14_1_10::volume() * base;
	}
};


class Box14_1_11 {
private:
	int side;
public:
	Box14_1_11(int s) : side{ s } {
		cout << "Box 构造函数" << endl;
		cout << "Box volume: " << volume() << endl;
	}

	virtual int volume() const {
		return pow(side, 3);
	}

	virtual ~Box14_1_11() {
		cout << "Box 析构函数" << endl;
		cout << "Box volume: " << volume() << endl;
	}
};

class MyBox14_1_11 : public Box14_1_11 {
public:
	MyBox14_1_11(int s) : Box14_1_11{ s } {
		cout << "MyBox 构造函数" << endl;
	}
	int volume() const override {
		return Box14_1_11::volume() * 0.8;
	}

	~MyBox14_1_11() {
		cout << "MyBox 析构函数" << endl;
	}
};


class Box14_2_1 {
private:
	int side;
public:
	void print() {}
};


class Box14_2_2 {
private:
	virtual void print3() {}
	int side;
public:
	virtual void print() {}
	virtual void f1(){}
	virtual void print1() {}

};



class Box14_3_1_1 {

};

class ABox14_3_1_1 : public Box14_3_1_1 {

};

class Box14_3_2_1 {
	virtual void f1() {}
};

class ABox14_3_2_1 : public Box14_3_2_1 {

};

inline ABox14_3_1_1 getABox14_3_1_1() {
	cout << "该函数返回的类不是多态类" << endl;
	return ABox14_3_1_1{};
}
inline ABox14_3_2_1 getABox14_3_2_1(){
	cout << endl << "---进入返回多态类的函数---" << endl;
	return ABox14_3_2_1{};
}

class Box14_4_1 {
protected:
	int side;
	// 禁止实例化且可以被继承
	Box14_4_1(int s) : side{ s } {}
public:
	// 纯虚函数
	virtual int volume() const = 0;
	virtual ~Box14_4_1(){}
};

class ABox14_4_1 : public Box14_4_1 {
public:
	ABox14_4_1(int s) : Box14_4_1{ s } {}
	int volume() const override {
		return pow(side, 3);
	}

};


class Interface14_4_1 {
public:
	virtual void move(string dest) const = 0;

	virtual ~Interface14_4_1() = default;
};

class Mover14_4_1 {
private:
	Interface14_4_1* mover;

public:
	Mover14_4_1(Interface14_4_1* m) : mover{ m } {}

	void go(string site) {
		mover->move(site);
	}
	~Mover14_4_1() = default;
};

class Car14_4_1 : public Interface14_4_1 {
public:
	void move(string dest) const override {
		cout << "Car move to " << dest << endl;
	}
};





















