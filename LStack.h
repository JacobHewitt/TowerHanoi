//Jacob Hewitt - Computer Science - 3218832
#ifndef LSTACK_H
#define LSTACK_H
#include "LinkedList.h"
using namespace linkedList;

namespace stack{
template <typename Data>
class LStack{
	public:
	
		// mutator member functions
		LStack();
		LStack(LStack *source); // copy function
		~LStack();
		void push(const Data);
		Data pop();
		
		// query member functions
		Data top() const;
		bool empty() const;
		size_t length() const;
		
		
	private:
		LinkedList<Data> *list;
		
};
#include "LStack.template"
}
#endif