//Jacob Hewitt - Computer Science - 3218832
#include "TowerHanoi.h"
#include <iostream>
#include <string>
namespace towerGame{
// constructor
TowerHanoi::TowerHanoi(){
	// initialize the LStack pointer objects.
	stack1 = new LStack<type>();
	stack2 = new LStack<type>();
	stack3 = new LStack<type>();
}

// destructor
TowerHanoi::~TowerHanoi(){
	// delete the LStack pointer objects.
	delete stack1;
	delete stack2;
	delete stack3;
}

// call the setup function and then the play function
void TowerHanoi::start(int input){
	setup(input);
	play();
}

// create the Nodes which represent disks on the stack/s.
void TowerHanoi::setup(int input){
	if(input > 5) input = 5; // max disks = 5
	size = input;
	
	// select how many 'X's the largest disk will be 
	int startingXs = 1; // variable represents number of 'X' s to be added to the Node.
	switch(input){
		case 5: startingXs = 9;
			break;
		case 4: startingXs = 7;
			break;
		case 3: startingXs = 5;
			break;
		case 2: startingXs = 3;
			break;
		case 1: startingXs = 1;
			break;
	}
	
	// loop through the number of disks to be added.
	for(int x = 0; x < input; x++){
		std::string toAdd; // string to be added to the Node.
		for(int y = 0; y < startingXs; y++){ // create the string of 'X's to be added to the Node.
			toAdd+="X"; // add an extra 'X'
		}
		startingXs-=2;  // minus 2 from the variable 
		stack1->push(toAdd); // create disk in the Linked List Stack 
		toAdd = "";
	}
}

// print the visual representation of the Disks on the 3 different stacks.
void TowerHanoi::print(){

	// temporary Linked List Stack objects which are copies of the member variables stacks
	LStack<type> *temp1 = new LStack<type>(stack1);
	LStack<type> *temp2 = new LStack<type>(stack2);
	LStack<type> *temp3 = new LStack<type>(stack3);
	
	// number of Nodes in each of the stacks.
	int length1;
	int length2;
	int length3;
	
	// temporary variables used to print the data to the console.
	std::string data;
	std::string toPrint;
	
	std::cout << "_____________________________________" << std::endl; // visual
	
	for(int x = size; x > 0; x--){ // Loop through how many disks there are in total.
	
		// check the length of each of the temporary stacks.
		length1 = temp1->length();
		length2 = temp2->length();
		length3 = temp3->length();
		
		// check if the length of the stack 'temp1' is equal to the increment in the loop.
		if(length1 == x){
			data = temp1->pop(); // pop the temporary stack and store the value in the 'data' variable.
			
		}
		
		toPrint = printXs(data); // work out the String to print to the console based on the value of the data variable.
		std::cout<<toPrint; // print the string returned.
		data = ""; // reset variable.
		
		// same as above
		if(length2 == x){ 
			data = temp2->pop();
		}
		toPrint = printXs(data);
		std::cout<<toPrint;
		data = "";
			
		if(length3 == x){
			data = temp3->pop();
		}
		toPrint = printXs(data);
		std::cout<<toPrint;
		data = "";
		
		std::cout << std::endl;
	}
	
	// visual
	std::cout << "_____________________________________" << std::endl;
	std::cout << "     1           2           3       " << std::endl;
	
	// delete temporary Stack objects.
	delete temp1;
	delete temp2;
	delete temp3;
}

// This function returns the String which will be printed to the screen. 
// It takes the string representation of what the Node was holding to work out the string to return.
std::string TowerHanoi::printXs(std::string toPrint){
	std::string toReturn;
	int length = toPrint.length(); // find out the length of the variable 'toPrint' (string Node was holding)
	switch(length){
		case 9:
			toReturn = " XXXXXXXXX  "; 
			break;
		case 7:
			toReturn = "  XXXXXXX   ";
			break;
		case 5: 
			toReturn = "   XXXXX    ";
			break;
		case 3:
			toReturn = "    XXX     ";
			break;
		case 1:
			toReturn = "     X      ";
			break;
		case 0:
			toReturn = "            ";
			break;
		
	}
	return toReturn;
}

// This function repeatedly asks the user for a source and a target rod. The function will then check the user input and check
// If the game move can be done. It will also Print the game to the user.
void TowerHanoi::play(){
	bool quit = false;
	
	// two integers used to represent the source stack and the target stack.
	int source, target;
	
	while(quit!=true){ // loop until the game is complete or the user inputs '0 0'
		source = 0; 
		target = 0;
		print(); // print the game to the user.
		if(checkIfComplete()){ // check if the game is complete.
			std::cout << "Game Complete!" << std::endl;
			delete this; // delete this TowerHanoi object.
			quit = true;
			break;
		}
		
		// prompt the user for input.
		std::cout << "Enter source rod and target rod." << std::endl;
		std::cin.clear();
		std::cin >> source >> target; // get two integers from the user.
		
		if(source == 0 && target == 0){ // check if the user input '0 0' then quit the game.
			std::cout << "Quit Game" << std::endl;
			quit = true;
			break;
		}
		
		if(!validateInput(source, target)){ // check the user input.
			std::cout << "Invalid Input" << std::endl;
			continue; // go back to beginning of while loop.
		}
		
		// check if the users Move was possible (check top of the source stack against the top of the target stack.
		if(checkMove(source, target) == true){ 
			move(source, target); // move the top disk from the source stack onto the top of the target stack.
		}else{
			
			std::cout << std::endl << "Invalid Move" << std::endl << std::endl;
		}
	}
}

// check if the top disk on the source stack is smaller than the top disk of the target stack.
bool TowerHanoi::checkMove(int source, int target) const{
	if(source == target) return false; // check if the input selected the same stack for target and source.
	
	// strings to hold the data stored in the top of the source stack and target stack.
	std::string sourceTop;
	std::string targetTop;
	
	// integers to represent to the length of the data stored in the Nodes.
	int length1;
	int length2;
	
	// switch statements to get the corresponding stacks the user selected.
	switch(source){ 
		case 1: sourceTop = stack1->top(); // get the data stored in the top Node in the stack.
			break;
		case 2: sourceTop = stack2->top();
			break;
		case 3: sourceTop = stack3->top();
			break;
		default: return false;
	}
	
	switch(target){
		case 1: targetTop = stack1->top();
			break;
		case 2: targetTop = stack2->top();
			break;
		case 3: targetTop = stack3->top();
			break;
		default: return false;
	}
	
	//check if the source and target returned a value (is empty)
	if(sourceTop == "") return false; 
	if(targetTop == "") return true; 
	
	// get the lengths of the two strings returned.
	length1 = sourceTop.length(); 
	length2 = targetTop.length();
	
	//check if the source's string is smaller than the target's.
	if(length1 < length2){
		return true;
	}else{
		return false;
	}
	
}

// This private function is used to move the top node of the source onto the top of the target.
void TowerHanoi::move(int source, int target){

	// variable to hold the data the node was holding.
	type dataToMove;
	
	switch(source){ 
		case 1: dataToMove = stack1->pop(); 
			break;
		case 2: dataToMove = stack2->pop();
			break;
		case 3: dataToMove = stack3->pop();
	}
	
	switch(target){
		case 1: stack1->push(dataToMove);
			break;
		case 2: stack2->push(dataToMove);
			break;
		case 3: stack3->push(dataToMove);
	}
}

// this private boolean function checks if the game is complete.
bool TowerHanoi::checkIfComplete() const{
	if(stack3->length() == size){ // check the length of the 3rd stack to the size variable (number of disks)
		return true;
	}else{
		return false;
	}
}

// this function checks if the input taken from the user is valid.
bool TowerHanoi::validateInput(int source, int target) const{
	if(source == 0 || target == 0) return false; else return true;
}

}
