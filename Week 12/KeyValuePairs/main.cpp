#include <iostream>
#include "KeyValuePairs.hpp"

int main()
{
	KeyValuePairs<int> pairs;

	pairs.set("key1", 1);
	pairs.set("key2", 2);
	pairs.set("key3", 3);
	pairs.set("key4", 4);
	pairs.set("key5", 5);
	pairs.set("key6", 6);
	pairs.set("key7", 7);
	pairs.set("key8", 8);
	pairs.set("key9", 9);
	pairs.set("key10", 10);


	int res = pairs.get("key 1");
	res = pairs.get("key9");

	pairs.remove("key7");
	std::cout << res << ' ' << pairs.count();

	return 0;
}
