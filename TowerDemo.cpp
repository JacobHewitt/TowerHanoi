//Jacob Hewitt - Computer Science - 3218832
#include "TowerHanoi.h"
#include <iostream>


int main(){
	int number;
	
	//initialize game
	towerGame::TowerHanoi *game = new towerGame::TowerHanoi();
	std::cout << "Enter number of disks (max = 5)" << std::endl;
	
	//get number of disks
	std::cin >> number;
	
	
	//start game
	game->start(number);
	
	
	
	
	return 0;
}