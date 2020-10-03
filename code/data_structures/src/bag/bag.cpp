//Needed for random and vector
#include <vector>
#include <string>
#include <cstdlib>

using std::string;
using std::vector;


//Bag Class Declaration
class Bag
{
private: 
	vector<string> items;
	int bagSize;

public:
	Bag();
	void add(string);
	bool isEmpty();
	int sizeOfBag();
	string remove();
};

/******************************************************************************
 * 								Bag::Bag()
 * This is the constructor for Bag. It initializes the size variable.
 ******************************************************************************/
Bag::Bag()
{
	bagSize = 0;
}

/******************************************************************************
 * 								Bag::add
 * This function adds an item to the bag.
 ******************************************************************************/
void Bag::add(string item)
{
	//Store item in last element of vector
	items.push_back(item);
	//Increase the size
	bagSize++;
}

/******************************************************************************
 * 								Bag::isEmpty
 * This function returns true if the bag is empty and returns false if the 
 * bag is not empty
 ******************************************************************************/
bool Bag::isEmpty(){
	//True
	if(bagSize == 0){
		return true;
	}
	//False
	else{
		return false;
	}
}

/******************************************************************************
 * 								Bag::size
 * This function returns the current number of items in the bag
 ******************************************************************************/
int Bag::sizeOfBag(){
	return bagSize;
}

/******************************************************************************
 * 								Bag::remove
 * This function removes a random item from the bag and returns which item was
 * removed from the bag
 ******************************************************************************/
string Bag::remove(){
	//Get random item
	int randIndx = rand() % bagSize;
	string removed = items.at(randIndx);
	//Remove from bag
	items.erase(items.begin() + randIndx);
	bagSize--;
	//Return removed item
	return removed;
}

