#pragma once
#include "MyString.h"
#include "Order.h"

class Restaurant
{
private:

	static int constexpr MAX_NAME_SIZE = 25;

	char name[MAX_NAME_SIZE]{};
	int productsCapacity = 0;
	int productsSize = 0;
	MyString* productsList = nullptr;

	void copyFrom(const Restaurant& other);
	void moveFrom(Restaurant&& other);
	void free();

	void resize(int newCapacity);

	bool containsProduct(const MyString& product) const;
	bool checkAllProducts(const Order& order) const;
public:

	Restaurant() = default;
	Restaurant(const Restaurant& other);
	Restaurant& operator=(const Restaurant& other);
	Restaurant(Restaurant&& other) noexcept;
	Restaurant& operator=(Restaurant&& other) noexcept;
	~Restaurant() noexcept;

	Restaurant(const char* name, int productsCapacity);
	
	const char* getName() const;

	void addProduct(const MyString& newProd);
	void addProduct(MyString&& newProd);
	int deliverOrder(const Order& order) const;
};

