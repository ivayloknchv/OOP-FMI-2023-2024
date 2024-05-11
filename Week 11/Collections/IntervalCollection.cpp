#include "IntervalCollection.h"
#include <utility>

bool IntervalCollection::isInInterval(int num) const
{
    return (num >= start && num <= end);
}

IntervalCollection::IntervalCollection(int start, int end)
{
    if (start > end)
    {
        std::swap(start, end);
    }

    this->start = start;
    this->end = end;

    free();
    capacity = end - start + 1;
    data = new int[capacity]{};
   
}

void IntervalCollection::add(int num)
{
    if (!isInInterval(num))
    {
        return;
    }

    data[num - start]++;
}

void IntervalCollection::remove(int num)
{
    if (!isInInterval(num))
    {
        return;
    }

    if (data[num - start] > 0)
    {
        --data[num - start];
    }
}

int IntervalCollection::count(int num) const
{
    if (!isInInterval(num))
    {
        return -1;
    }

    return data[num - start];
}

bool IntervalCollection::contains(int num) const
{
    if (!isInInterval(num))
    {
        return false;
    }
    return (count(num) != 0);
}
