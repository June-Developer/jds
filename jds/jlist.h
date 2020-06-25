#ifndef JDS_JLIST_H_
#define JDS_JLIST_H_

#include "jiterator.h"

namespace jds {

	template <typename T>
	class jlist : public jiterator<T>
	{
	public:
		jlist();
		~jlist();

		/*
			@des: Get the front value
			@in:
			@return:
				the front value
		*/
		T front();


		/*
			@des: the back value
			@in:
			@return:
				the back value
		*/
		T back();

		/*
			@des: Get the begin of list
			@in:
			@return:
				the begin of list
		*/
		jiterator<T>* begin();

		/*
			@des: Get the end of list
			@in:
			@return:
				the end of list
		*/
		jiterator<T>* end();

		/*
			@des: check if the list is empty or not
			@in:
			@return:
				true: the list is empty
				false: the list is not empty
		*/
		bool empty();

		/*
			@des: get the size of the list
			@in:
			@return:
				the size of the list
		*/
		int size();

		/*
			@des: clear all nodes of the list
			@in:
			@return:
		*/
		void clear();

		/*
			@des: insert a node to an expected position
			@in:
				pos: possition
				element: node data
			@return:
		*/
		void insert(int pos, T element);

		/*
			@des: insert a node to the tail
			@in:
				element: node data
			@return:
		*/
		void push_back(T element);

		/*
			@des: insert a node to the head
			@in:
				element: node data
			@return:
		*/
		void push_front(T element);

		/*
			@des: remove a node to the tail
			@in:
			@return:
				data of node removed out of the list
		*/
		T pop_back();

		/*
			@des: remove a node to the head
			@in:
			@return:
				data of node removed out of the list
		*/
		T pop_front();

	private:
		int num_element;
		jiterator<T>* head;
		jiterator<T>* tail;

	};
}

#endif // !JDS_JLIST_H_

