#include "Engine.h"

Engine::Engine(const char* newName, const char* newDescription, unsigned newHorsePowers):CarPart(newName, newDescription)
{
	setHorsePowers(newHorsePowers);
}

void Engine::setHorsePowers(unsigned newHorsePowers)
{
	horsePowers = newHorsePowers;
}

unsigned Engine::getHorsePowers() const
{
	return horsePowers;
}

std::ostream& operator<<(std::ostream& os, const Engine& obj)
{
	os << (CarPart)obj << " - "<<obj.horsePowers <<" hp" << std::endl;

	return os;
}
