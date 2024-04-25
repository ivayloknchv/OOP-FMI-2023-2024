#pragma once
#include "MyString.h"

class Order
{
private:

	MyString restaurantName;
	int productsCount = 0;
	int currentCount = 0;

	MyString* productsList = nullptr;
	void copyFrom(const Order& other);
	void moveFrom(Order&& other);
	void free();

public:

	Order() = default;
	Order(const Order& other);
	Order& operator=(const Order& other);
	Order(Order&& other) noexcept;
	Order& operator=(Order&& other) noexcept;
	~Order() noexcept;


	const MyString& getRestaurantName() const;
	int getCount() const;
	const MyString* getProductsList() const;

	Order(MyString& restaurantName, int productsCount);
	void addProduct(const MyString& newProd);
	int getDeliveryTime() const;
};

