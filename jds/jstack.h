#pragma once
#ifndef JDS_JSTACK_H_
#define JDS_JSTACK_H_

#include "jlist.h"

namespace jds {

	template<typename T>
	class jstack : public jlist<T>
	{
	public:
		jstack();
		~jstack();

		T top();
		void push(T element);
		T pop();
	};
}

#endif // !JDS_JSTACK_H_
