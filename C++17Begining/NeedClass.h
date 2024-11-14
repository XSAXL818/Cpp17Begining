#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <utility>

using namespace std;

// ʹ�ñ������ṩ��Ĭ�ϸ������캯��
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

// �Զ��帱�����캯��
class Box4_9_2 {
public:
	int m_length;
	int m_width;
	int m_height;

	Box4_9_2() = default;
	Box4_9_2(int length, int width, int height) : m_length{ length }, m_width{ width }, m_height{ height } {
		cout << "Box4_9_1(int length, int width, int height)" << endl;
	};

	// �Զ��帱�����캯��
	/*Box4_9_1(Box4_9_1 box) {// ���󣬻ᵼ�����޵ݹ����
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
			cout << "const ���û�ȡ�����Լ�" << endl;
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
		if( isOk(s) ) { // ����Ǹ��ӵ�У���߼�������ʹ�ú���
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
		cout << "this: " << this << endl; // thisָ��ָ��ǰ����
		m_c = c;
	};

	void print() {
		cout << "a: " << m_a << " b: " << m_b << " c: " << m_c << endl;
	}
	// ������ʵ��
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

	// ���캯��
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

	// �����޸ĳ�Ա�����ĺ�������Ϊconst
	int getLength() const { return m_length; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }

	// �޸ĳ�Ա�����ĺ�������Ϊconst�ᱨ��
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
	// Ϊʹ�ô�ͳ��getter��setter
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
	// Ϊʹ�ô�ͳ��getter��setter
	int& a() { 
		cout << "��const�汾\n";
		return m_a; 
	}
	int& b() { 
		cout << "��const�汾\n";
		return m_b;
	}
	int& c() { 
		cout << "��const�汾\n";
		return m_c; 
	}
	// ʹ��const���أ���Ҫ�����������޸�Ϊconst����
	const int& a() const { 
		cout << "const�汾\n";
		return m_a; 
	}
	const int& b() const { return m_b; }
	const int& c() const { return m_c; }
	
};

class Log7_5 {
private:
	// const�����Կ����޸ĸñ���
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
		cout << "Ĭ�Ϲ��캯��" << endl;
	};
	Cube9(int _side) : side(_side) {
		cout << "Cube(int _side)���캯��" << endl;
	}

	Cube9(const Cube9& c) {
		cout << "�������캯��" << endl;
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

	// ί��
	Static11_11_1_1(int u) : Static11_11_1_1() {};

	int objCnt() const {// const����Ҳ���Ե���
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

	// ί��
	Static11_11_1_2(int u) : Static11_11_1_2() {};

	int objCnt() const {// ���ض�������͸ú����ĵ��ô���
		return ++cnt;
	}
};


// Բ���κ�����
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

	// ���������Է���˽�г�Ա
	static void toCube(Box11_11_5& b) {
		b.w = b.h = b.l;
	}
	// ��̬��Ա��������thisָ�룬ʹ��const���������壬���Բ�����
	//static void nonConst() const {}
};


class Box11_11_12_1 {
private:
	int side{ 0 };

public:

	static inline int objCnt{ 0 };

	Box11_11_12_1() {
		++objCnt;
		cout << "Ĭ�Ϲ��캯��" << endl;
	}

	Box11_11_12_1(int s) : side{ s } {
		++objCnt;
		cout << "���ι��캯��" << endl;
	}

	Box11_11_12_1(const Box11_11_12_1& bb) {
		cout << "�������캯��" << endl;
		++objCnt;
		side = bb.side;
	}

	void print() {
		cout <<"side: " << side << endl;
	}

	~Box11_11_12_1() {
		objCnt--;
		cout << "��������" << endl;
	}
};



class Cube11_13 {
private:
	int side{ 0 };

public:
	Cube11_13() {
		cout << "Ĭ�Ϲ��캯��" << endl;
	}

	Cube11_13(int s) : side{ s } {
		cout << "���ι��캯��" << endl;
	}

	Cube11_13(const Cube11_13& c) {
		cout << "�������캯��" << endl;
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

// ��װ����Cube��װΪ����
class Package11_13 {
private:
	// ����ָ�룬�������ڶ��������һ������
	SharedCube cube;
	// ����ָ����һ������
	Package11_13* pNext{ nullptr };

public:
	Package11_13(SharedCube cube) : cube{ cube } {	}
	// ɾ��ͷ������������а�����ɾ��
	~Package11_13() {
		delete pNext;// ����Ҫ���pNext�Ƿ�Ϊnullptr����Ϊdelete nullptr�ǰ�ȫ��
		pNext = nullptr;// ���Բ����ã���Ϊ�ϲ������صĿ��ƣ��������ɾ��������֮��İ���
	}
	// ��ȡCube
	SharedCube getCube() const {
		return cube;
	}

	// ����Cube
	void setCube(SharedCube cube) {
		this->cube = cube;
	}

	// ��ȡ��һ������
	Package11_13* getNext() const {
		return pNext;
	}
	// ������һ������
	void setNext(Package11_13* next) {
		pNext = next;
	}
};

class Truckload11_13 {
private:
	// ����ָ���һ������
	Package11_13* pHead{ nullptr };
	// ָ�����һ����������������°���
	Package11_13* pTail{ nullptr };
	// ��¼��ǰ���ʵİ���
	Package11_13* pCurrent{ nullptr };

public:

	Truckload11_13() = default;
	// ��������
	Truckload11_13(SharedCube cube) {
		pHead = pTail = new Package11_13{ cube };
	}
	// �������
	Truckload11_13(const vector<SharedCube>& cubes){
		for (const auto& cube : cubes) {
			addCube(cube);
		}
	}
	// �������캯��
	Truckload11_13(const Truckload11_13& truckload) {
		for (Package11_13* head = truckload.pHead; head; head = head->getNext() ) {
			addCube(head->getCube());
		}
	}

	// ��������
	~Truckload11_13() {
		delete pHead;
		pHead = pTail = nullptr;
	}

	// ��ȡ��һ��Cube
	SharedCube getFirstCube() {
		pCurrent = pHead;
		return pHead != nullptr ?  pHead->getCube() : nullptr;
	}
	// ��ȡ��һ��Cube
	SharedCube getNextCube() {
		if (pCurrent == nullptr) {// ���ص�һ��Cube
			return getFirstCube();
		}
		pCurrent = pCurrent->getNext();
		return pCurrent != nullptr ? pCurrent->getCube() : nullptr;
	}
	// ���Cube
	void addCube(SharedCube cube) {
		auto newPackage = new Package11_13{ cube };
		if (pHead == nullptr) {
			pHead = newPackage;
		} else {
			pTail->setCube(cube);
		}
		pTail = newPackage;
	}
	// ɾ��Cube
	// ˼��������ֱ���жϵ�һ���Ƿ�ΪҪɾ����
	bool removeCube(const SharedCube& cube) {
		Package11_13* pre{ nullptr };
		Package11_13* cur{ pHead };
		while (cur) {
			// ��Ҫɾ����Cube
			if (cube->compare(*cur->getCube())) {
				if (cur == pHead) {// �ж��Ƿ�δ��һ��Cube
					// �õ�һ������һ����Ϊ��һ��
					pHead = cur->getNext();
				}
				else {
					// ��ǰһ������һ��ָ��ǰ����һ��
					pre->setNext(cur->getNext());
				}
				// ɾ����ǰ����
				cur->setNext(nullptr);// ��ֹɾ���󣬺���������ɾ��
				delete cur;
				return true;
			}
		}
		return false;
	}
	// ��ӡ����Cube
	void listCubes() const {
		const int perLine{ 5 };
		int cnt{ 0 };
		for (Package11_13* index = pHead; index; index = index->getNext() ) {
			cout << index->getCube()->getSide() << " ";
			if ((++cnt) % perLine == 0) {
				cout << endl;
			}
		}
		if (cnt % perLine > 0) {// ������һ��û����������
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
		cout << "С��< ��������ذ汾1\n";
		return side < c.side;
		// or
		return getVolume() < c.getVolume();
	}

	bool operator<(int v) {
		cout << "С��< ��������ذ汾2\n";
		return getVolume() < v;
	}

	void operator=(const Cube12_1_2& c) {
		cout << "��ֵ= \n";
		side = c.side;
	}

	int getVolume() const {
		return (int)pow(side, 3);
	}
};

class Cube12_1_3 {
private:
	int side;
public:
	Cube12_1_3() = default;

	// ��ֹ���� 3 ��Ϊ��������ʽת��Ϊ�ö���
	explicit Cube12_1_3(int _side) : side{_side}{}

	int getVolume() const {// ����������Ϊconst
		return (int)pow(side, 3);
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

	int getVolume() const {// ����������Ϊconst
		return (int)pow(side, 3);
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

	int getVolume() const {// ����������Ϊconst
		return (int)pow(side, 3);
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

	int getVolume() const {// ����������Ϊconst
		return (int)pow(side, 3);
	}
	// ������� < �����ֵ
	inline bool operator<(int v) {
		return getVolume() < v;
	}

	bool operator<(Double v) const;
	friend bool operator<(int v, const Cube12_1_4_3& c);


};

inline bool Cube12_1_4_3::operator<(Double v) const {
	cout << "���ⶨ��\n";
	return this->getVolume() < v.v;
}

inline bool operator<(const Cube12_1_4_3& c1, const Cube12_1_4_3& c2) {
	return c1.getVolume() < c2.getVolume();
}

//�����ֵ < ����
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
		return (int)pow(side, 3);
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

	// ��ȡ���������Ӻ��Cube
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
	// ��ȡ���������Ӻ��Cube
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

	// ת�þ���
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

// ����
inline Matrix12_7 operator!(const Matrix12_7& m) {
	return Matrix12_7{};
}

class Cube12_8 {
public:
	int side;

	Cube12_8(int s= 0) : side{s}{}

	// ǰ++����������
	Cube12_8& operator++() {
		side++;
		return *this;
	}
	// ��++��ʹ��int��Ϊ����
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
		row = (int)data.size();
		col = (int)data[0].size();
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
	
	int getVolume() { return (int)pow(side, 3); }

	Cube12_10_1(const Box12_10_1& box);

};

class Box12_10_1 {
private:
	int side;

public:
	Box12_10_1(int s = 0) : side{ s } {}

	operator int() const {
		return (int)pow(side, 3);
	}

	int getSide() const {
		return side;
	}

	operator Cube12_10_1() {
		cout << "box����ת��Ϊcube\n";
		return Cube12_10_1{ side };
	}

};




class Msg12_12_1{
private:
	string* pTxt;

public:
	Msg12_12_1() {
		cout << "Ĭ�Ϲ��캯��\n";
		pTxt = new string();
	}

	Msg12_12_1(const string& str) {
		pTxt = new string();
		*pTxt = str;
	}
	// ����bug�汾
	/*Msg12_12_1& operator=(const Msg12_12_1& msg) {
		cout << "=���������\n";
		delete pTxt;
		pTxt = new string{ *msg.pTxt };
		return *this;
	}*/

	// �޸ĺ󣬱����Լ����Ƹ�ֵ���Լ�
	Msg12_12_1& operator=(const Msg12_12_1& msg) {
		cout << "=���������\n";
		if (*pTxt == msg.getTxt()) {
			return *this;
		}
		delete pTxt;
		pTxt = new string{ *msg.pTxt };
		return *this;
	}

	Msg12_12_1(const Msg12_12_1& msg) {
		cout << "�������캯��\n";
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
		cout << "��ֵ�����\n";
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
		// ����ֱ�ӷ���
		//cout << this->height << endl;
	}
};

class MyBox13_1_1_public : public Box13_1_1 {
private:
	string name;

public:

	MyBox13_1_1_public(int h,int w, int l) : Box13_1_1(h,w,l){}

	void print() {
		// ����ֱ�ӷ���
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
		// ���Է�����
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
	//using Box13_4_1::height;// �޷����ʻ����˽�г�Ա
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

	// �ڽ��뺯����ǰ���������δ����
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
		cout << "Box�ĸ������캯��" << endl;
		height = box.height;
		width = box.width;
		length = box.length;
	}
	Box13_6_1_1() {
		cout << "BoxĬ�Ϲ��캯��" << endl;
	}
	Box13_6_1_1(int h, int w, int l) : height{ h }, width{ w }, length{ l } {
		cout << "Box���ι��캯��" << endl;
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
	// ��ָ���������Ĭ�ϵĹ��캯��
	MyBox13_6_1_1(const MyBox13_6_1_1& mBox) : Box13_6_1_1{ mBox } {
		cout << "MyBox�ĸ������캯��" << endl;
	}

	MyBox13_6_1_1(int h,int w,int l) : Box13_6_1_1{ h,w,l } {
		cout << "MyBox�Ĵ��ι��캯��" << endl;
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
		cout << "Ĭ�Ϲ��캯��" << endl;
	}

};

class MyBox13_6_1_3 : private Box13_6_1_2 {
private:
	string name;

public:

	using Box13_6_1_2::volume;

	MyBox13_6_1_3(int h, int w, int l) : Box13_6_1_2{ h,w,l } {}

	MyBox13_6_1_3(const MyBox13_6_1_3& box) {
		cout << "�ֶ�ʵ�ָ������캯��" << endl;
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
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	Box13_5_3_1(int _a) : a{ _a } {
		cout << "���ι��캯��" << endl;
	}
};

class MyBox13_5_3_1 : private Box13_5_3_1 {
private:
	int b{ 1 };

public:
	MyBox13_5_3_1() {
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	MyBox13_5_3_1(int _a, int _b) : Box13_5_3_1{ _a }, b{ _b } {
		cout << "���ι��캯��" << endl;
	}
};



class Box13_6_1 {
private:
	int side;
public:

	~Box13_6_1() {
		cout << "Box����������" << endl;
	}
};

class MyBox13_6_1 : private Box13_6_1 {
private:
	int name;
public:

	~MyBox13_6_1() {
		cout << "MyBox����������" << endl;
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
	// public���Σ����Ի����doDouble���������η�Ҳ��public
	using Box13_8_1::doDouble;

	void doit() {
		// ��Ϊ�ͻ���ͬ�������Ի����ػ����ͬ������
		// ʹ��using ���Ի�ȡ�����ͬ������
		//doit(5);
		doDouble(3.0);
	}
	// ʹ��using��ȡ�����ͬ������
	void doDouble() {
		Box13_8_1::doDouble(3.0);
		doDouble(4.5);
	}
};

class MyBox13_8_2 : public Box13_8_1 {
private:

public:
	// public���Σ����Ի����doDouble���������η�Ҳ��public
	using Box13_8_1::doDouble;

	void doit() {
		// ��Ϊ�ͻ���ͬ�������Ի����ػ����ͬ������
		// ʹ��using ���Ի�ȡ�����ͬ������
		//doit(5);
		doDouble(3.0);
	}
	// ʹ��using��ȡ�����ͬ������
	void doDouble(double x) {
		cout << "MyBox13_8_2����: " << x << endl;
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

	double volume() {
		return (int)getSide() * (int)getSide() * (int)getSide() * base;
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
	virtual double volume() {
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

	double volume() {
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
	// �������Ͳ�ͬҲ��Эͬ
	//int print() {}

	ABox14_3_2(int side) : Box14_3_2{ side } {}

	ABox14_3_2& print() {
		cout << "ABox print..." << endl;
		return *this;
	}
	// ��ͬ
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

	// ����������
	//void print() override {}
	// ������麯���ĺ���ǩ����ͬʱ,������
	void print() const override {}
};


class Box14_3_4 {
private:
	int side;
public:
	Box14_3_4(int s = 1) : side{ 1 } {}
	// ����ʹ��final����ֹ��������д
	virtual void printVersion() const  final {
		cout << "Box print..." << endl;
	}

};

class ABox14_3_4 final : public Box14_3_4  {
public:
	// ����������
	//void printVersion() const override {};
};

// ����������
//class BBox14_3_4 : public ABox14_3_4 {};


class Box14_3_5 {
private:
	int side;
public:
	Box14_3_5(int s = 1) : side{ 1 } {}
	// ����ʹ��final����ֹ��������д
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
		cout << "��������ת��\n";
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
		cout << "Box ���캯��" << endl;
		cout << "Box volume: " << volume() << endl;
	}

	virtual int volume() const {
		return pow(side, 3);
	}

	virtual ~Box14_1_11() {
		cout << "Box ��������" << endl;
		cout << "Box volume: " << volume() << endl;
	}
};

class MyBox14_1_11 : public Box14_1_11 {
public:
	MyBox14_1_11(int s) : Box14_1_11{ s } {
		cout << "MyBox ���캯��" << endl;
	}
	int volume() const override {
		return Box14_1_11::volume() * 0.8;
	}

	~MyBox14_1_11() {
		cout << "MyBox ��������" << endl;
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
	cout << "�ú������ص��಻�Ƕ�̬��" << endl;
	return ABox14_3_1_1{};
}
inline ABox14_3_2_1 getABox14_3_2_1(){
	cout << endl << "---���뷵�ض�̬��ĺ���---" << endl;
	return ABox14_3_2_1{};
}

class Box14_4_1 {
protected:
	int side;
	// ��ֹʵ�����ҿ��Ա��̳�
	Box14_4_1(int s) : side{ s } {}
public:
	// ���麯��
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




class Box15_2_2_1 {
public:
	~Box15_2_2_1() {
		cout << "Box1 ��������\n";
	}
};

class Box15_2_2_2 {
private:
	Box15_2_2_2(const Box15_2_2_2& box) {
		cout << "�������캯��\n";
	}
public:
	Box15_2_2_2() = default;
	~Box15_2_2_2() {
		cout << "Box2 ��������\n";
	}
	void show() {
		cout << "ha" << endl;
	}
};

inline void fun15_2_2_1() {
	cout << "fun1" << endl;
}

inline void fun15_2_2_2() {
	cout << "fun2" << endl;
	throw "123";
}

inline void fun15_2_2_3() {
	fun15_2_2_2();
	cout << "fun3" << endl;
}

inline void fun15_2_2_4() {
	cout << "fun4" << endl;
}


class Oops15_3_1_1 {
protected:
	string msg;

public:
	Oops15_3_1_1(const string& m="��ͨ����") : msg{m} {}

	virtual string getMsg() const {
		return msg;
	}
};

class MoreOops15_3_1_1 : public Oops15_3_1_1 {
public:
	MoreOops15_3_1_1(const string& m = "�м�����") :Oops15_3_1_1{m}{}
};

class BigOops15_3_1_1 : public MoreOops15_3_1_1 {
public:
	BigOops15_3_1_1(const string& m = "�ش�") :MoreOops15_3_1_1{ m } {}
};


class Oops15_4_1 {
protected:
	string msg;
public:
	Oops15_4_1(const string& m = "��ͨ����") : msg{ m } {}
	virtual ~Oops15_4_1() {
		cout << "Oops ��������" << endl;
	}
	virtual string getMsg() const {
		return msg;
	}
};

class MoreOops15_4_1 : public Oops15_4_1 {
public:
	MoreOops15_4_1(const string& m = "�м�����") {
		msg = m;
	}

	~MoreOops15_4_1() {
		cout << "MoreOops ��������" << endl;
	}
};


class Class15_7_1_1 {
public:
	static void  fun() noexcept {
		try {
			throw 1;
		}
		catch (int& i) {
			cout << "i: " << i << endl;
		}
	}
	static void  fun_except() throw() {
		try {
			//throw 3.1;// �����ڴ˴�����
		}
		catch (int& i) {
			cout << "i: " << i << endl;
		}
	}
};


class Class15_7_2_1 {
public:
	// �׳��쳣����ֹ����
	~Class15_7_2_1() noexcept(false) { throw 1; }
};
class Class15_7_2_2 {
public:
	// ��ʽ���������׳��쳣
	~Class15_7_2_2() noexcept(false) { throw 1; }
};



inline int* fun15_8_1() {

	int* res{ nullptr };
	try {
		// ������Դ
		int* arr = new int[100];
		arr[1] = 10;
		res = arr;
		// �����׳��쳣�ļ���
		throw 1;
		// �ͷ���Դ
		delete[] arr;
	}
	catch (int a) {
		cout << a << endl;
	}
	cout <<"������ʣ�" << res[1] << endl;
}

class RAII15_8_1 {
private:
	int* res;
public:
	RAII15_8_1(int size) {
		res = new int[size];
		res[1] = 10;
	}
	~RAII15_8_1() {
		cout << "RAII ��������\n";
		delete[] res;
	}
	int* release() {
		int* rel = res;
		res = nullptr;
		return rel;
	}

	int* get() {
		return res;
	}

};

inline void fun15_8_2() {
	int* res{ nullptr };
	try {
		// ������Դ
		RAII15_8_1 arr{ 100 };
		res = arr.get();
		// �����׳��쳣�ļ���
		throw 1;
		// �����ռ�������Զ��ͷ���Դ
	}
	catch (int a) {
		cout << a << endl;
	}
	// ԭ�ȵ�����ʧЧ����ֻ�ܷ��ʸ��ڴ棬���ܽ���д����
	cout << "������ʣ�" << res[1] << endl;
	//delete res;
}


inline unique_ptr<int[]> fun15_8_2_1() {

	auto arr = make_unique<int[]>(100);


	throw 1;

	return arr;
}

template <typename T>
class MyClass16_1_1_1 {

};

// ��������ģ���ظ�
//template <class T>
//class MyClass16_1_1_1 {
//
//};



template <typename T1,class T2, typename arg>
class MyClass16_2_1_1 {

};


template <typename T>
class MyArray16_2_2 {
private:
	T* elem{nullptr};
	size_t size{ 0 };
public:

	explicit MyArray16_2_2<T>(int side=0) {
		cout << "���캯��" << endl;
		elem = new T[side];
		size = side;
	}

	~MyArray16_2_2<T>() {
		delete[] elem;
	}
	MyArray16_2_2<T>(const MyArray16_2_2<T>& arr) {
		cout << "�������캯��" << endl;
	}
	MyArray16_2_2& operator=(const MyArray16_2_2& arr) {
		cout << "��ֵ�����" << endl;
	}
	T& operator[](size_t s) {
		cout << "����[]" << endl;
		return elem[s];
	}
	const T& operator[](size_t s) const {
		cout << "����[] const" << endl;
		return elem[s];
	}
	size_t getSize() const {
		return size;
	}
	
};


template <typename T>
class MyArray16_3_1 {
private:
	T* elem;
	size_t size;
public:

	MyArray16_3_1(size_t _size);
	MyArray16_3_1(const MyArray16_3_1& arr);
	~MyArray16_3_1();

	const T& operator[](size_t s) const;
	T& operator[](size_t s);
	size_t getSize() { return size; }
};

template <typename T>
MyArray16_3_1<T>::MyArray16_3_1(size_t _size) : elem{ new T[_size] }, size{ _size } {
	cout << "ģ�幹�캯��" << endl;
}

template <typename T>
MyArray16_3_1<T>::MyArray16_3_1(const MyArray16_3_1& arr) {
	delete[] elem;
	cout << "�������캯��" << endl;
	size = arr.size;
	elem = new T[size];
	for (int i = 0; i < size; i++) {
		elem[i] = arr.elem[i];
	}
}
template <typename T>
MyArray16_3_1<T>::~MyArray16_3_1() {
	delete[] elem;
	cout << "��������" << endl;
}

template <typename T>
const T& MyArray16_3_1<T>::operator[](size_t s) const {
	cout << "��̬�±�[]�����\n";
	if (s >= size) {
		throw std::out_of_range{ "Index is non-vaild" + std::to_string(s) };
	}
	return elem[s];
}
// ��������ظ���ʹ��const�汾��ʵ�ַ�const���˷���Ч�ʽϷ�constʵ��const��
template <typename T>
T& MyArray16_3_1<T>::operator[](size_t s) {
	cout << "��̬�±�[]�����\n";
	return const_cast<T&>( std::as_const(*this)[s] );
}


class Data16_3_3 {
public:
	Data16_3_3() {
		cout << "Ĭ�Ϲ��캯��\n";
	}
	Data16_3_3(const Data16_3_3& data) {
		cout << "�������캯��\n";
	}
};

class Test16_3_3_1 {
public:
	Data16_3_3 arr[10];
	Test16_3_3_1() = default;

	Data16_3_3& operator[](int s) {
		return arr[s];
	}
	const Data16_3_3& operator[](int s) const {
		return const_cast<Test16_3_3_1&>(*this)[s];
	}
};

class Test16_3_3_2 {
public:
	Data16_3_3 arr[10];
	Test16_3_3_2() = default;

	Data16_3_3& operator[](int s) {
		cout << "��const\n";
		return const_cast<Data16_3_3&>(std::as_const(*this)[s]);
	}
	const Data16_3_3& operator[](int s) const {
		cout << "const\n";
		return arr[s];
	}
};


template<typename T>
class Array16_3_4 {
private:
	T* elem;
	size_t size;

public:
	Array16_3_4(size_t _size) : elem{ new T[_size] }, size{ _size } {
		cout << "���캯��" << endl;
	}

	~Array16_3_4() {
		delete[] elem;
	}

	Array16_3_4(const Array16_3_4& arr);
	const T& operator[](size_t s) const;
	T& operator[](size_t s);
	void swap(Array16_3_4& other) noexcept; 
	Array16_3_4<T>& operator=(const Array16_3_4& arr);

	void println() {
		for (int i = 0; i < size; i++) {
			cout << elem[i] << " ";
		}
		cout << endl;
	}
};

template<typename T>
Array16_3_4<T>& Array16_3_4<T>::operator=(const Array16_3_4& arr) {
	cout << "=��ֵ�����" << endl;
	// ���ƺ󽻻�
	if (this != &arr) {
		// 1�����������һ������
		Array16_3_4<T> copy{ arr };
		// 2���������Ҫ���޸ĸ���
		// 3���޸ĺ��ø����滻ԭ����
		swap(copy);
	}
	return *this;
}

// ͨ��ʵ��һ��swap(other)��Ա��������ʵ��swap(one,other)�ⲿ����
template<typename T>
void Array16_3_4<T>::swap(Array16_3_4& other) noexcept {
	std::swap(elem, other.elem);
	std::swap(size, other.size);
}
// �ǳ�Ա������swap����
template<typename T>
void swap(Array16_3_4<T>& one, Array16_3_4<T>& other) noexcept  {
	one.swap(other);
}

template<typename T>
Array16_3_4<T>::Array16_3_4(const Array16_3_4& arr) {
	cout << "�������캯��" << endl;
	elem = new T[arr.size];
	size = arr.size;
	for (int i = 0; i < size; i++) {
		elem[i] = arr.elem[i];
	}
}

template<typename T>
const T& Array16_3_4<T>::operator[](size_t s) const {
	cout << "����[] const" << endl;
	if (s >= size) {
		throw std::out_of_range{ "Index is non-vaild" + std::to_string(s) };
	}
	return elem[s];
}

template<typename T>
T& Array16_3_4<T>::operator[](size_t s) {
	cout << "����[]" << endl;
	return const_cast<T&>(std::as_const(*this)[s]);
}


template<typename T,T value>
class Array16_5_1 {
private:
	T* elem;
	size_t size;
public:
	Array16_5_1(size_t _size) : elem{ new T[_size] }, size{ _size } {
		cout << "���캯��" << endl;
		for (int i = 0; i < size; ++i) {
			elem[i] = value;
		}
	}

	~Array16_5_1() {
		delete[] elem;
	}

	void println() {
		for (int i = 0; i < size; i++) {
			cout << elem[i] << " ";
		}
		cout << endl;
	}
};

template<typename T, int size>
class Class16_5_1 {
public:
	static inline int a{ 3 };
	void f1();
	
};
template<typename T, int size>
void Class16_5_1<T,size>::f1() {
	// �����޸ķ����Ͳ���
	//size = 3;
}


template<typename T, int* size>
class Class16_5_2 {
public:
};



template<typename T>
class Class16_7_1 {
public:
	void f1();
};

template class Class16_7_1<int>;


template<typename T>
class Array16_8_1 {
public:
	T a;
	T b;
public:
	T getMax();
};
template<typename T>
T Array16_8_1<T>::getMax() {
	return a > b ? a : b;
}

template<>
class Array16_8_1<char*>{
private:

public:
	char* a;
	char* b;
	string getMax() {
		string s1{ a };
		string s2{ b };
		return s1 > s2 ? s1 : s2;
	}
};

