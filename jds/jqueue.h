#ifndef JDS_QUEUE_H_
#define JDS_QUEUE_H_

#include "jlist.h"

namespace jds 
{

	template<typename T>
	class jqueue : public jlist<T>
	{
	public:
		jqueue();
		~jqueue();

		void push(T element);
		T pop();
	};

}

#endif // !JDS_QUEUE_H_
