//Jacob Hewitt - Computer Science - 3218832
#ifndef TOWERHANOI_H
#define TOWERHANOI_H
#include "LStack.h"
#include <string>
using namespace stack;

namespace towerGame{
class TowerHanoi{
	public:
	
		// mutator member functions.
		TowerHanoi();
		~TowerHanoi();
		void start(int);
		void setup(int);
		void print();
		void play();
		
	private: 
		void move(int, int);
		
		// Query member functions
		std::string printXs(std::string);
		bool checkMove(int, int) const;
		bool checkIfComplete() const;
		bool validateInput(int, int) const;
		
		// variables
		size_t size; //number of disks in the game.
		typedef std::string type; // data type which will be stored in the Nodes.
		
		// 3 LinkedList Stacks
		LStack<type> *stack1; 
		LStack<type> *stack2;
		LStack<type> *stack3;
};
}

#endif