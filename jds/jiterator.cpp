#include "jiterator.h"
#include <iostream>

using namespace std;

namespace jds {
	template<typename T>
	jiterator<T>::jiterator()
	{
		this->it_next = NULL;
		this->it_prev = NULL;
	}

	template<typename T>
	jiterator<T>::jiterator(T m_element, jiterator* m_next, jiterator* m_prev)
		: element(m_element)
		, next(m_next)
		, prev(m_prev)
	{

	}

	template<typename T>
	jiterator<T>::~jiterator()
	{

	}

	template<typename T>
	jiterator<T>* jiterator<T>::advance(int step)
	{
		jiterator<T>* it_bk = this;
		jiterator<T>* it = this;
		while (0 != step)
		{
			it = it->it_next;
			step--;
			if ((nullptr == it) && (step != 0))
			{
				cout << "Error" << endl;
				return it_bk;
			}
		}
		return it;
	}

	template<typename T>
	jiterator<T>* jiterator<T>::backward(int step)
	{
		jiterator<T>* it_bk = this;
		jiterator<T>* it = this;
		while (0 != step)
		{
			it = it->it_prev;
			step--;
			if ((nullptr == it) && (step != 0))
			{
				cout << "Error" << endl;
				return it_bk;
			}
		}
		return it;
	}

	template<typename T>
	int jiterator<T>::distance(jiterator<T>* it1, jiterator<T>* it2)
	{
		if ((nullptr == it1) || (nullptr == it1))
		{
			return -1;
		}

		if (it1 != it2)
		{
			int distance = 0;
			while (it1 != NULL)
			{
				it1 = it1->next;
				distance++;
				if (it1 == it2)
				{
					return distance;
				}
			}

			distance = 0;
			while (it1 != NULL)
			{
				it1 = it1->prev;
				distance++;
				if (it1 == it2)
				{
					return distance;
				}
			}
		}

		return 0;
	}

	template<typename T>
	jiterator<T>* jiterator<T>::next()
	{
		return this->it_next;
	}

	template<typename T>
	jiterator<T>* jiterator<T>::prev()
	{
		return this->it_prev;
	}

	template<typename T>
	jiterator<T>* jiterator<T>::operator++() const
	{
		this->it_next;
	}

	template<typename T>
	jiterator<T>* jiterator<T>::operator--() const
	{
		this->it_prev;
	}

	template<typename T>
	T jiterator<T>::operator*() const
	{
		this->element;
	}
}