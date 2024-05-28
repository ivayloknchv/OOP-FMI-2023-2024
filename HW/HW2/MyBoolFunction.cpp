#include "MyBoolFunction.h"

bool MyBoolFunction::contains(int32_t num) const
{
    for (int32_t i = 0; i < size; i++)
    {
        if (arguments[i] == num)
        {
            return true;
        }
    }
    return false;
}

void MyBoolFunction::setArguments(const int32_t* arguments, int32_t size)
{
    if (!arguments)
    {
        return;
    }

    for (int32_t i = 0; i < size; i++)
    {
        this->arguments[i] = arguments[i];
    }
}

MyBoolFunction::MyBoolFunction(const int32_t* arguments, int32_t size)
{
    this->size = size;
    setArguments(arguments, size);
}

MyFunction* MyBoolFunction::clone() const
{
    return new MyBoolFunction(*this);
}

Pair<bool, int32_t> MyBoolFunction::operator()(int32_t num) const
{
    int numToReturn = 0;

    if (contains(num))
    {
        numToReturn = 1;
    }
    return Pair<bool, int32_t>(true,numToReturn);
}
