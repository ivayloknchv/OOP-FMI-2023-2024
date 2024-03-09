#include <iostream>
#include <fstream>
#include <cstring>

namespace Constants
{
	constexpr size_t MAX_NAME_SIZE = 100;
	constexpr size_t MAX_SUPPLIER_SIZE = 100;
	constexpr size_t MAX_PRODUCTS = 30;
}

enum class Category
{
	UNKNOWN,
	ELECTRONICS,
	CLOTHING,
	BOOKS, 
	FOOD,
	BEAUTY
	
};

struct Product
{
	char name[Constants::MAX_NAME_SIZE+1];
	char supplier[Constants::MAX_SUPPLIER_SIZE+1];
	double price;
	int quantity;
	Category category;
};

struct AllProducts
{
	Product products[Constants::MAX_PRODUCTS]{};
	int count = 0;
};

int getSize(std::ifstream& ifs)
{
	int currentPos = (int)ifs.tellg();

	ifs.seekg(0, std::ios::end);

	int size = (int)ifs.tellg();

	ifs.seekg(0, currentPos);

	return size;
}

void readProductsFromFile(std::ifstream& ifs, AllProducts& myProducts)
{
	myProducts.count = getSize(ifs) / sizeof(Product);

	ifs.read((char*)myProducts.products, (long long)myProducts.count * sizeof(Product));
}

void readProductsFromFile(const char* fileName, AllProducts& myProducts)
{
	if (!fileName)
	{
		return;
	}

	std::ifstream ifs(fileName, std::ios::in | std::ios::binary);

	if (!ifs.is_open())
	{
		return;
	}

	readProductsFromFile(ifs, myProducts);


	ifs.close();
}

Category getCategory(const char* str)
{
	if (!strcmp(str, "Electronics"))
	{
		return Category::ELECTRONICS;
	}

	else if (!strcmp(str, "Clothing"))
	{
		return Category::CLOTHING;
	}

	else if (!strcmp(str, "Books"))
	{
		return Category::BOOKS;
	}

	else if (!strcmp(str, "Food"))
	{
		return Category::FOOD;
	}

	else if (!strcmp(str, "Beauty"))
	{
		return Category::BEAUTY;
	}

	return Category::UNKNOWN;
}

bool checkIfProductExists(const char* str, const AllProducts& myProducts)
{
	for (int i = 0; i < myProducts.count; i++)
	{
		if (!strcmp(str, myProducts.products[i].name))
		{
			return false;
		}
	}

	return true;
}

bool initProduct(AllProducts& myProducts)
{
	Product& product = myProducts.products[myProducts.count];

	char category[Constants::MAX_NAME_SIZE+1];

	std::cin.getline(product.name, Constants::MAX_SUPPLIER_SIZE + 1);

	if (!checkIfProductExists(product.name, myProducts))
	{
		std::cout << "Product already exists!"<<std::endl;
		product.name[0] = '\0';
		return false;
	}

	std::cin.getline(product.supplier, Constants::MAX_NAME_SIZE + 1);

	std::cin >> product.price;

	std::cin >> product.quantity;

	std::cin >> category;

	product.category = getCategory(category);

	return true;
}

void saveProductsToFile(std::ofstream& ofs, const AllProducts& myProducts)
{
	int buffer = myProducts.count * sizeof(Product);

	ofs.write((const char*)myProducts.products, buffer);
}

void saveProductsToFile(const char* fileName, const AllProducts& myProducts)
{
	if (!fileName)
	{
		return;
	}

	std::ofstream ofs(fileName, std::ios::out | std::ios::binary);

	if (!ofs.is_open())
	{
		return;
	}

	saveProductsToFile(ofs, myProducts);

	ofs.close();
}

void saveProductsToFile(const char* fileName, int n)
{
	AllProducts myProducts;

	readProductsFromFile(fileName, myProducts);

	for (int i = 0; i < n; i++)
	{
		if (initProduct(myProducts))
		{
			myProducts.count++;
		}
	}

	saveProductsToFile(fileName, myProducts);
}

void changeQuantity (AllProducts& myProducts, const char* product, int newQuantity)
{
	if (!product)
	{
		return;
	}

	for (int i = 0; i < myProducts.count; i++)
	{
		if (!strcmp(myProducts.products[i].name, product))
		{
			myProducts.products[i].quantity = newQuantity;
		}
	}
}

void changeQuantity(const char* fileName, const char* product, int newQuantity)
{
	if (!fileName)
	{
		return;
	}

	AllProducts myProducts;

	readProductsFromFile(fileName, myProducts);

	changeQuantity(myProducts, product, newQuantity);

	saveProductsToFile(fileName, myProducts);
}

void printCategory(const Category& category)
{
	switch (category)
	{
	case Category::UNKNOWN: 
		std::cout << "Unknown" << std::endl; 
		break;

	case Category::ELECTRONICS: 
		std::cout << "Electronics" << std::endl; 
		break;

	case Category::CLOTHING: 
		std::cout << "Clothing" << std::endl; 
		break;

	case Category::BOOKS: 
		std::cout << "Books" << std::endl; 
		break;

	case Category::FOOD: 
		std::cout << "Food" << std::endl; 
		break;

	case Category::BEAUTY: 
		std::cout << "Beauty" << std::endl; 
		break;
	}
}

void printProduct(const Product& myProduct)
{
	std::cout << myProduct.name << ' ' << myProduct.supplier << ' ' << myProduct.price << ' ' << myProduct.quantity << ' ';
	printCategory(myProduct.category);
}

void printAllProducts(const AllProducts& myProducts)
{
	for (int i = 0; i < myProducts.count; i++)
	{
		printProduct(myProducts.products[i]);
	}
}

void printAllProducts(const char* fileName)
{
	if (!fileName)
	{
		return;
	}

	AllProducts myProducts;

	readProductsFromFile(fileName, myProducts);

	printAllProducts(myProducts);
}

void searchProduct(const AllProducts& myProducts, const char* productName)
{
	if (!productName)
	{
		return;
	}

	for (int i = 0; i < myProducts.count; i++)
	{
		if (!strcmp(myProducts.products[i].name, productName))
		{
			printProduct(myProducts.products[i]);

			return;
		}
	}
}

void printProduct(const char* fileName, const char* productName)
{
	if (!fileName || !productName)
	{
		return;
	}

	AllProducts myProducts;

	readProductsFromFile(fileName, myProducts);

	searchProduct(myProducts, productName);
}

void filterProducts(const AllProducts& myProducts, AllProducts& myCategoryProducts, const Category category)
{
	for (int i = 0; i < myProducts.count; i++)
	{
		if (myProducts.products[i].category == category)
		{
			myCategoryProducts.products[myCategoryProducts.count++] = myProducts.products[i];
		}
	}
}

void placeCategoryInFile(const char* sourceFile, const char* destinationFile, const Category category)
{
	if (!sourceFile || !destinationFile)
	{
		return;
	}

	AllProducts myProducts;

	AllProducts myCategoryProducts;

	readProductsFromFile(sourceFile, myProducts);

	filterProducts(myProducts, myCategoryProducts, category);

	saveProductsToFile(destinationFile, myCategoryProducts);
}

int main()
{
	return 0;
}
