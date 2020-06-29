#ifndef JDS_ITERATOR_H_
#define JDS_ITERATOR_H_

namespace jds
{
	template<typename T>
	class jiterator
	{
	public:
		jiterator();
		jiterator(T m_element, jiterator* m_next, jiterator* m_prev);
		~jiterator();

		/*
			@des: Advance iterator
			@in:
				step: the number of step to advance
			@return:
				an iterator after advancement
		*/
		jiterator<T>* advance(int step);

		/*
			@des: Back iterator
			@in:
				step: the number of step to get back
			@return:
				an iterator after backward
		*/
		jiterator<T>* backward(int step);

		/*
			@des: Return distance between iterators
			@in:
				it1: one of iterators needing to get distance
				it2: the other of iterator
			@return:
				distance between two iterators
		*/
		int distance(jiterator* it1, jiterator* it2);

		/*
			@des: Iterator to beginning
			@in: None
			@return:
				The begining of an iterator
		*/
		virtual jiterator<T>* begin() = 0;

		/*
			@des: Iterator to end
			@in: None
			@return:
				The end of an iterator
		*/
		virtual jiterator<T>* end() = 0;

		/*
			@des: Get a next iterator
			@in: None
			@return:
				The next iterator
		*/
		jiterator<T>* next();

		/*
			@des: Get a previous iterator
			@in: None
			@return:
				The previous iterator
		*/
		jiterator<T>* prev();

		/*
			Operator
		*/
		jiterator<T>* operator++() const;
		jiterator<T>* operator--() const;
		T operator*() const;

	private:
		T element;
		jiterator<T>* it_next;
		jiterator<T>* it_prev;
	};
}

#endif // !JDS_ITERATOR_H_
