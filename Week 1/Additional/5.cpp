#include <iostream>

namespace constraits 
{
	constexpr unsigned MAX_TRANSITIONS = 4;
	constexpr unsigned MAX_STATES = 50;
}

struct transition
{
	unsigned targetNum;
	char path;
};

struct state 
{
	transition transitions[constraits::MAX_TRANSITIONS]{};
	unsigned transitionsCount = 0;
};

struct stateInfo 
{
	state data[constraits::MAX_STATES]{};
};


bool hasTransition(const stateInfo& arg, size_t from, char c)
{
	const state& myState = arg.data[from];

	for (size_t i = 0; i < myState.transitionsCount; i++)
	{
		if(myState.transitions[i].path==c)
		{
			return true;
		}
	}
	return false;
}

bool addTransition(stateInfo& arg, size_t from, char c, size_t to)
{
	state& myState = arg.data[from];
	if (myState.transitionsCount == constraits::MAX_TRANSITIONS)
	{
		return false;
	}
	
	for (size_t i = 0; i < myState.transitionsCount; i++)
	{
		if (myState.transitions[i].path == c)
		{
			myState.transitions[i].targetNum = to;
			return true;
		}
	}

	myState.transitions[myState.transitionsCount] = { to,c };
	myState.transitionsCount++;

	return false;
}

int getTransition(const stateInfo& arg, size_t from, char c)
{
	const state& myState = arg.data[from];

	for (size_t i = 0; i < myState.transitionsCount; i++)
	{
		if (myState.transitions[i].path == c)
		{
			return myState.transitions[i].targetNum;
		}
	}
	return -1;
}

bool canRead(const stateInfo& arg, char* word, size_t from)
{
	if (!word)
	{
		return false;
	}

	char* ptrCopy = word;
	size_t currentIdx = from;

	while (*ptrCopy != '\0')
	{
		currentIdx = getTransition(arg, currentIdx, *ptrCopy);
		if (currentIdx!=-1)
		{
			ptrCopy++;
		}

		else
		{
			return false;
		}
	}

	ptrCopy = nullptr;
	return true;
}
void deleteFromArray(state& myState, size_t startIdx)
{
	for (size_t i = startIdx; i < myState.transitionsCount-1; i++)
	{
		myState.transitions[i] = myState.transitions[i + 1];
	}

	myState.transitionsCount--;
}

bool removeTransition(stateInfo& arg, size_t from, char c)
{
	state& myState = arg.data[from];

	for (size_t i = 0; i < myState.transitionsCount; i++)
	{
		if (myState.transitions[i].path == 'c')
		{
			deleteFromArray(myState, i);
			return true;
		}
	}

	return false;
}
int main()
{
	return 0;
}
