#include "SpellCard.h"
#include <cstring>

#pragma warning (disable : 4996)

SpellCard::SpellCard() = default;

SpellCard::SpellCard(const char* newName, const char* newCaption, Type newType)
{
	setName(newName);
	setCaption(newCaption);
	setType(newType);
}

void SpellCard::setName(const char* newName)
{
	if (!newName)
	{
		return;
	}

	if (strlen(newName) > Contants::MAX_NAME)
	{
		return;
	}

	strcpy(name, newName);
}

void SpellCard::setCaption(const char* newCaption)
{
	if (!newCaption)
	{
		return;
	}

	if (strlen(newCaption) > Contants::MAX_CAPTION)
	{
		return;
	}

	strcpy(caption, newCaption);
}

void SpellCard::setType(Type newType)
{
	type = newType;
}

const char* SpellCard::getName() const
{
	return name;
}

const char* SpellCard::getCaption() const
{
	return caption;
}

Type SpellCard::getType() const
{
	return type;
}
