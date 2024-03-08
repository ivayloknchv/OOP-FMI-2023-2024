#include <iostream>

enum class Genres
{
	Default,
	Comedy, 
	Action, 
	Horror, 
	Romantic
};

struct Movie 
{
	double rating = 0;
	const char* name=nullptr;
	unsigned duration = 0;
	Genres genre=Genres::Default;
	
};

Movie initMovie(char* name, const unsigned& duration, const Genres& genre, const double rating)
{
	return { rating, name, duration, genre };
}

void printGenre(const Genres& genre)
{
	switch (genre)
	{
	case Genres::Action:
		std::cout << "Action"<<'\t';
		break;

	case Genres::Comedy:
		std::cout << "Comedy"<<'\t';
		break;

	case Genres::Horror:
		std::cout << "Horror"<<'\t';
		break;

	case Genres::Romantic:
		std::cout << "Romantic" << '\t';
		break;
	}
}

void printMovie(const Movie& movie)
{
	std::cout << movie.name << '\t';
	printGenre(movie.genre);
	std::cout << movie.duration << " minutes" << '\t';
	std::cout << "Rating: " << movie.rating << std::endl;
}

void printCollection(const Movie* arr, const unsigned size)
{
	if (!arr)
	{
		return;
	}

	for (unsigned i = 0; i < size; i++)
	{
		printMovie(arr[i]);
	}
}


Movie getHighestRating(const Movie* arr, const unsigned size, bool(*comp)(const Movie& , const Movie& ))
{
	if (!arr)
	{
		return { 0.00,"no-name", 0, Genres::Default };
	}

	int max_idx = 0;

	for (unsigned i = 1; i < size; i++)
	{
		if (comp(arr[i],arr[max_idx]))
		{
			max_idx = i;
		}
	}

	return arr[max_idx];
}

int main()
{
	Movie arr[3];
	arr[0] = {6.5, "Movie1", 129, Genres::Horror };
	arr[1] = { 7.5, "Movie2", 179, Genres::Comedy };
	arr[2] = { 4.2, "Movie3", 152, Genres::Action };


	printMovie(getHighestRating(arr, 3, [](const Movie& lhs, const Movie& rhs) { return lhs.rating > rhs.rating; }));
	printMovie(getHighestRating(arr, 3, [](const Movie& lhs, const Movie& rhs) { return lhs.duration> rhs.duration; }));
	return 0;
}
