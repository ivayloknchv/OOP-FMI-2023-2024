#pragma once


enum class Product
{
	DEFAULT,
	FOOD,
	DRINK
};

class RestaurantItem
{
	Product _product = Product::DEFAULT;
	char* _name = nullptr;
	unsigned _count = 0;
	double _price = 0;

	void copyFrom(const RestaurantItem& other);
	void moveFrom(RestaurantItem&& other);
	void free();

public:

	RestaurantItem() = default;
	RestaurantItem(const RestaurantItem& other);
	RestaurantItem& operator=(const RestaurantItem& other);
	RestaurantItem(RestaurantItem&& other) noexcept;
	RestaurantItem& operator=(RestaurantItem&& other) noexcept;
	virtual ~RestaurantItem();

	RestaurantItem(Product product, const char* name, unsigned count, double price);

	void setProduct(Product product);
	void setCount(unsigned count);
	void setPrice(double price);
	void setName(const char* name);

	Product getProduct() const;
	unsigned getCount() const;
	double getPrice() const;
	const char* getName() const;

	virtual RestaurantItem* clone() const = 0 ;
	virtual void print() const = 0;
};

