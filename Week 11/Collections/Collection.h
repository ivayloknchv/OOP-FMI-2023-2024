#pragma once

class Collection
{
public:

	virtual void add(int num) = 0;
	virtual void remove(int num) = 0;
	virtual int count(int num) const = 0;
	virtual bool contains(int num) const = 0;
	virtual ~Collection()= default;
};

