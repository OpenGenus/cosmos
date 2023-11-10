//Needed for random and vector
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
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

Bag::Bag()
{
	bagSize = 0;
}

void Bag::add(string item)
{
	//Store item in last element of vector
	items.push_back(item);
	//Increase the size
	bagSize++;
}

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

int Bag::sizeOfBag(){
	return bagSize;
}

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

int main()
{
	//Create bag
	Bag bag;

	//Get current size 
	cout << "Bag size: " << bag.sizeOfBag() << endl;
	//Bag empty?
	cout << "Is bag empty? " << bag.isEmpty() << endl;

	//Add some items
	cout << "Adding red..." << endl;
	bag.add("red");
	cout << "Bag size: " << bag.sizeOfBag() << endl;
	cout << "Adding blue..." << endl;
	bag.add("blue");
	cout << "Bag size: " << bag.sizeOfBag() << endl;
	cout << "Adding yellow..." << endl;
	bag.add("yellow");
	cout << "Bag size: " << bag.sizeOfBag() << endl;

	//Remove an item
	cout << "Removed " << bag.remove() << " from bag." << endl;
	//Get current size 
	cout << "Bag size: " << bag.sizeOfBag() << endl;
	//Bag empty?
	cout << "Is bag empty? " << bag.isEmpty() << endl;

	//Remove an item
	cout << "Removed " << bag.remove() << " from bag." << endl;
	//Get current size 
	cout << "Bag size: " << bag.sizeOfBag() << endl;
	//Bag empty?
	cout << "Is bag empty? " << bag.isEmpty() << endl;

	//Remove last item
	cout << "Removed " << bag.remove() << " from bag." << endl;
	//Get current size 
	cout << "Bag size: " << bag.sizeOfBag() << endl;
	//Bag empty?
	cout << "Is bag empty? " << bag.isEmpty() << endl;

}
