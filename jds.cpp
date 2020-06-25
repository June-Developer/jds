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

int main()
{
	class_T<int, int> t(3, 5);
	t.show();
	return 0;
}
