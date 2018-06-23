#define CATCH_CONFIG_MAIN
#include "../../../../test/c++/catch.hpp"
#include "../../src/linked_list/linked_list.cpp"

using namespace std;

using ListChar = LinkedList<char>;
using ListInt = LinkedList<int>;
using ListFloat = LinkedList<float>;

TEST_CASE("init")
{
	ListInt list1();

	std::list<int> std_list_int;
	for(int i = 0; i < 10; ++i)
	{
		std_list_int.push_back(i);
	}
	const std::list<int> list_copy = std_list_int;
	ListInt list2(list_copy);
	ListInt list3(list2);

	std::initializer_list<float> list_d1 = {1.1,2.2,3.3,4.4,5.5};
	ListFloat list4(list_d1);
}

TEST_CASE("pop")
{
	std::list<int> std_list_int;
	for(int i = 0; i < 10; ++i)
	{
		std_list_int.push_back(i);
	}
	const std::list<int> list_copy = std_list_int;
	ListInt list(list_copy);

	REQUIRE(list.popBack() == 9);
	REQUIRE(list.popBack() == 8);
	REQUIRE(list.popBack() == 7);
	REQUIRE(list.popBack() == 6);

	REQUIRE(list.popFront() == 0);
	REQUIRE(list.popFront() == 1);
	REQUIRE(list.popFront() == 2);
	REQUIRE(list.popFront() == 3);
}

TEST_CASE("operator []")
{
	std::list<int> std_list_int;
	for(int i = 0; i < 10; ++i)
	{
		std_list_int.push_back(i);
	}
	const std::list<int> list_copy = std_list_int;
	ListInt list(list_copy);

	REQUIRE(list[9] == 9);
	REQUIRE(list[8] == 8);
	REQUIRE(list[7] == 7);
	REQUIRE(list[6] == 6);

	REQUIRE(list[0] == 0);
	REQUIRE(list[1] == 1);
	REQUIRE(list[2] == 2);
	REQUIRE(list[3] == 3);
}

TEST_CASE("push")
{
	std::list<int> std_list_int;
	for(int i = 0; i < 10; ++i)
	{
		std_list_int.push_back(i);
	}
	const std::list<int> list_copy = std_list_int;
	ListInt list(list_copy);

	list.pushFront(10);
	REQUIRE(list[0] == 10);
	list.pushFront(20);
	REQUIRE(list[0] == 20);
	list.pushFront(30);
	REQUIRE(list[0] == 30);
	list.pushFront(40);
	REQUIRE(list[0] == 40);

	list.pushBack(10);
	REQUIRE(list[14] == 10);
	list.pushBack(20);
	REQUIRE(list[15] == 20);
	list.pushBack(30);
	REQUIRE(list[16] == 30);
	list.pushBack(40);
	REQUIRE(list[17] == 40);
}

TEST_CASE("clear")
{
	std::list<int> std_list_int;
	for(int i = 0; i < 10; ++i)
	{
		std_list_int.push_back(i);
	}
	const std::list<int> list_copy = std_list_int;
	ListInt list(list_copy);

	list.clear();
	REQUIRE(list.size() == 0);
	REQUIRE(list.isEmpty() == true);
}

TEST_CASE("insert")
{
	std::list<int> std_list_int;
	for(int i = 0; i < 10; ++i)
	{
		std_list_int.push_back(i);
	}
	const std::list<int> list_copy = std_list_int;
	ListInt list(list_copy);

	list.insert(1, 10);
	REQUIRE(list[1] == 10);
	list.insert(5, 30);
	REQUIRE(list[5] == 30);
	list.insert(8, 60);
	REQUIRE(list[8] == 60);
}

TEST_CASE("addAll")
{
	std::list<int> std_list_int1;
	for(int i = 0; i < 10; ++i)
	{
		std_list_int1.push_back(i);
	}
	const std::list<int> list_copy1 = std_list_int1;
	ListInt list1(list_copy1);

	std::list<int> std_list_int2;
	for(int i = 10; i < 20; ++i)
	{
		std_list_int2.push_back(i);
	}
	const std::list<int> list_copy2 = std_list_int2;
	const ListInt list3(list_copy2);

	ListInt list4 = list1.addAll(list3);
}

TEST_CASE("operator +")
{
	std::list<int> std_list_int1;
	for(int i = 0; i < 10; ++i)
	{
		std_list_int1.push_back(i);
	}
	const std::list<int> list_copy1 = std_list_int1;
	ListInt list1(list_copy1);

	std::list<int> std_list_int2;
	for(int i = 10; i < 20; ++i)
	{
		std_list_int2.push_back(i);
	}
	const std::list<int> list_copy2 = std_list_int2;
	ListInt list2(list_copy2);

	ListInt list3 = list1 + list2;
	ListInt list4(list1 + list2);
}