#include <iostream>
#include "Playlist.h"

int main()
{
	Playlist p;
	p.addSong("FTCU", 0, 2, 57, "h", "ftcu.dat");
	p.printPlaylist();
	return 0;
}