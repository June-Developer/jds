#include "jlist.h"
#include <iostream>

using namespace std;

namespace jds {

	template<typename T>
	jlist<T>::jlist()
		: num_element(0)
		, head(nullptr)
		, tail(nullptr)
	{

	}

	template<typename T>
	jlist<T>::~jlist()
	{

	}

	template<typename T>
	T jlist<T>::front()
	{
		return *(this->head);
	}

	template<typename T>
	T jlist<T>::back()
	{
		return *(this->tail);
	}

	template<typename T>
	jiterator<T>* jlist<T>::begin()
	{
		return this->head;
	}

	template<typename T>
	jiterator<T>* jlist<T>::end()
	{
		return this->tail;
	}

	template<typename T>
	bool jlist<T>::empty()
	{
		return (this->num_element == 0);
	}

	template<typename T>
	int jlist<T>::size()
	{
		return this->num_element;
	}
	template<typename T>
	void jlist<T>::clear()
	{
		if (!this->empty())
		{
			jiterator<T>* it = this->head;
			jiterator<T>* it_tmp = this->head;
			while (nullptr != it)
			{
				it_tmp = it->next();
				delete it;
				it = it_tmp;
				this->num_element--;
			}
		}
	}

	template<typename T>
	void jlist<T>::insert(int pos, T element)
	{
		if (pos == 0)
		{
			this->push_front(element);
		}
		else if (pos == this->size())
		{
			this->push_back(element);
		}
		else if (pos > this->size())
		{
			cout << "Error" << endl;
		}
		else
		{
			jiterator<T>* it = this->head;
			jiterator<T>* it_current = it;
			while (pos && it)
			{
				it_current = it;
				it++;
				pos--;
			}
			if (pos == 0)
			{
				jiterator<T>* it_new = new jiterator(element, it, it_current);
				it_current->next() = it->prev() = it_new;
			}
		}
	}

	template<typename T>
	void jlist<T>::push_back(T element)
	{
		if (this->empty())
		{
			jiterator<T>* it = new jiterator(element, NULL, NULL);
			this->head = this->tail = it;
		}
		else
		{
			jiterator<T>* it = new jiterator(element, NULL, this->tail);
			this->tail = it;
		}

		this->num_element++;
	}

	template<typename T>
	void jlist<T>::push_front(T element)
	{
		if (this->empty())
		{
			jiterator<T>* it = new jiterator(element, NULL, NULL);
			this->head = this->tail = it;
		}
		else
		{
			jiterator<T>* it = new jiterator(element, this->head, NULL);
			this->head = it;
		}

		this->num_element++;
	}

	template<typename T>
	T jlist<T>::pop_back()
	{
		T element_tmp = *(this->tail);
		if (this->num_element == 1)
		{
			delete (this->tail);
			this->tail = nullptr;
			this->head = nullptr;
		}
		else
		{
			jiterator<T>* it_tmp = this->tail;
			this->tail->prev()->next() == NULL;
			this->tail = this->tail->prev();
			delete (it_tmp);
		}
		this->num_element--;
		return element_tmp;
	}

	template<typename T>
	T jlist<T>::pop_front()
	{
		T element_tmp = *(this->head);
		if (this->num_element == 1)
		{
			delete (this->head);
			this->head = nullptr;
			this->tail = nullptr;
		}
		else
		{
			jiterator<T>* it_tmp = this->head;
			this->head->next()->prev() == NULL;
			this->head = this->tail->next();
			delete (it_tmp);
		}
		this->num_element--;
		return element_tmp;
	}
}