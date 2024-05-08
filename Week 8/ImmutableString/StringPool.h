#pragma once

class StringPool
{
	struct StringNode
	{
		char* data = nullptr;
		int refCount = 0;

		void allocateData(const char* newData);
	};

	StringNode* nodes = nullptr;
	int size = 0;
	int capacity = 0;

	void resize(int newCapacity);

	int findString(const char* str, bool& isFound) const;

	void insertInternal(const char* str, int idx);
	void removeInternal(int idx);

public:

	StringPool();
	StringPool(const StringPool& other) = delete;
	StringPool& operator=(const StringPool& other) = delete;
	~StringPool();

	const char* getString(const char* str);
	void removeString(const char* str);
};

