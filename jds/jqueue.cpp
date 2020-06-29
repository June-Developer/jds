#include "jqueue.h"

namespace jds 
{

	template<typename T>
	jqueue<T>::jqueue()
	{

	}

	template<typename T>
	jqueue<T>::~jqueue()
	{

	}

	template<typename T>
	void jqueue<T>::push(T element)
	{
		this->push_front(element);
	}

	template<typename T>
	T jqueue<T>::pop()
	{
		this->pop_back();
	}

}