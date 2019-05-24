/******************************************************************************
 * 								Main
 * Testing Bag data structure
 ******************************************************************************/
#include <iostream>

using std::cout;
using std::endl;

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