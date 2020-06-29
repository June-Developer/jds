#include "jstack.h"

namespace jds 
{

	template<typename T>
	jstack<T>::jstack()
	{

	}

	template<typename T>
	jstack<T>::~jstack()
	{

	}

	template<typename T>
	T jstack<T>::top()
	{
		return this->front();
	}

	template<typename T>
	void jstack<T>::push(T element)
	{
		this->push_front(element);
	}

	template<typename T>
	T jstack<T>::pop()
	{
		this->pop_front();
	}

}