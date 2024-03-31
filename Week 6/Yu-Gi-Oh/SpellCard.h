#pragma once

namespace Contants
{
	constexpr int MAX_NAME = 25;
	constexpr int MAX_CAPTION = 100;
}

enum class Type
{
	UNKNOWN,
	TRAP,
	BUFF,
	SPELL
};

class SpellCard
{
	char name[Contants::MAX_NAME + 1]{};
	char caption[Contants::MAX_CAPTION + 1]{};
	Type type=Type::UNKNOWN;

public:

	SpellCard();
	SpellCard(const char* newName, const char* newCaption, Type newType);

	void setName(const char* newName);
	void setCaption(const char* newCaption);
	void setType(Type newType);

	const char* getName() const;
	const char* getCaption() const;
	Type getType() const;
};