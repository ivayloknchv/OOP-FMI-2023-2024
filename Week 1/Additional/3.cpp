#include <iostream>

const int MAX_SIZE = 50;
const int MAX_BOOKS = 15;

enum class ErrorMessage
{
	FULL_CAPACITY,
	EMPTY_STOCK,
	NO_ERROR,
	NULLPTR,
	NOT_FOUND
};

enum class Genres {
	Novel,
	Historic,
	Poetry,
	Others
};

struct Book {
	char title[MAX_SIZE];
	char author[MAX_SIZE];
	Genres genre;
	unsigned availableCount;
};

struct Library {
	unsigned booksCount;
	Book books[15];
};

bool strCompare(char* lhs, char* rhs)
{
	if (!lhs || !rhs)
	{
		return false;
	}

	char* lhs_copy = lhs;
	char* rhs_copy = rhs;

	while (*lhs != '\0' || *rhs != '\0')
	{
		if (*lhs != *rhs)
		{
			return false;
		}
		lhs++;
		rhs++;
	}

	if (lhs - lhs_copy == rhs - rhs_copy)
	{
		lhs = lhs_copy;
		rhs = rhs_copy;
		return true;
	}

	lhs = lhs_copy;
	rhs = rhs_copy;
	return false;

}

Genres getGenre(const int num)
{
	switch (num)
	{
	case 1: 
		return Genres::Novel;
		break;
	case 2:
		return Genres::Historic;
		break;
	case 3:
		return Genres::Poetry;
		break;
	default: 
		return Genres::Others;
	}
}

Book createBook()
{
	
	Book b;

	std::cin.ignore();

	std::cin.getline(b.title, MAX_SIZE);

	std::cin.getline(b.author, MAX_SIZE);

	int genre = 0;

	std::cin >> genre;

	b.genre = getGenre(genre);

	std::cin >> b.availableCount;

	return b;
}

ErrorMessage AddToLibraby(Library& myLibrary, const Book& myBook)
{
	if (myLibrary.booksCount >= MAX_BOOKS)
	{
		return ErrorMessage::FULL_CAPACITY;
	}


	myLibrary.books[myLibrary.booksCount] = createBook();

	myLibrary.booksCount++;

	return ErrorMessage::NO_ERROR;
	
}

ErrorMessage TakeBook(Library& myLibrary, char* targetTitle)
{
	if (!targetTitle)
	{
		return ErrorMessage::NULLPTR;
	}

	for (unsigned i = 0; i < myLibrary.booksCount; i++)
	{
		if (strCompare(myLibrary.books[i].title, targetTitle))
		{

			if (myLibrary.books[i].availableCount > 0)
			{
				myLibrary.books[i].availableCount--;

				return ErrorMessage::NO_ERROR;
			}
			else
			{
				return ErrorMessage::EMPTY_STOCK;
			}
		}
	}
		return ErrorMessage::NOT_FOUND;
}

ErrorMessage ReturnBook(Library& myLibrary, char* targetTitle)
{
	if (!targetTitle)
	{
		return ErrorMessage::NULLPTR;
	}

	for (unsigned i = 0; i < myLibrary.booksCount; i++)
	{
		if (strCompare(myLibrary.books[i].title, targetTitle))
		{
			myLibrary.books[i].availableCount++;

			return ErrorMessage::NO_ERROR;
		}
	}
		return ErrorMessage::NOT_FOUND;
}

void printGenre(const Genres& genre)
{
	switch (genre)
	{
	case(Genres::Novel):
		std::cout << "Novel"<<' ';
		break;

	case(Genres::Historic):
		std::cout << "Historic"<<' ';
		break;

	case(Genres::Poetry):
		std::cout << "Poetry"<<' ';
		break;

	case(Genres::Others):
		std::cout << "Other"<<' ';
		break;

	default: break;
	}
}

void printBook(const Book& myBook)
{
	std::cout << myBook.title<<' ';
	std::cout << myBook.author << ' ';
	printGenre(myBook.genre);
	std::cout << myBook.availableCount << ' '<<std::endl;
}

void printLibrary(const Library& myLibrary)
{
	for (unsigned i = 0; i < myLibrary.booksCount; i++)
	{
		printBook(myLibrary.books[i]);
	}
}

int main()
{
	int n = 0;
	std::cin >> n;

	Library l;
	l.booksCount = n;

	for(int i=0;i<n;i++)
	{
		l.books[i] = createBook();
	}

	printLibrary(l);

	char str[MAX_SIZE]{};

	std::cin.ignore();
	std::cin.getline(str, MAX_SIZE);

	ErrorMessage er = TakeBook(l, str);
	return 0;
}
