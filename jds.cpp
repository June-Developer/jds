// jds.cpp : Defines the entry point for the application.
//

#include "jds.h"

using namespace std;

template<typename K, typename V>
class class_T
{
public:
	class_T(K m_k, V m_v): k(m_k), v(m_v)
	{

	}
	void show()
	{
		cout << "K: " << k << endl;
			cout << "V: " << v << endl;
	}


private:
	K k;
	V v;

};

class Y
{
public:
	int a;
	Y()
	{
	}
	Y(int _a)
	{
		a = _a;
	}
	void print()
	{
		cout << a << endl;
	}

};

class X
{
public:
	int b;
	Y* y;
	X(int _b)
	{
		b = _b;
		y = new Y[b];
	}
};

int main()
{
	//class_T<int, int> t(3, 5);
	//t.show();
	X x(2);
	x.y[0].a = 0;
	x.y[1].a = 1;
	x.y[0].print();
	x.y[1].print();
	return 0;
}
