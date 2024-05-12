#include <iostream>
#include "Playlist.h"
#include <stdexcept>

int main()
{
		Song s2("song2", "rock", 206);
		Song s1("song1", "pop", 193, &s2);

		Playlist p(&s1);

		Song s3("song3", "rap", 182);
		p += s3;
		
		Song s4("song4", "jazz", 432);
		p += s4;
		p -= s2;
		std::cout << p.getSongsCount();
		p();
	return 0;
}