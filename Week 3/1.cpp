#include <iostream>
#include <fstream>

struct Color
{
    char name[8];
    int code;
};

Color* initCollection(const unsigned n)
{
    Color* collection = new Color[n];

    for (unsigned i = 0; i < n; i++)
    {
        std::cin >> collection[i].name;
        std::cin >> collection[i].code;
    }

    return collection;
}

void writeOnFile(std::ofstream& ofs, const Color* collection, const unsigned size)
{
    ofs.write((const char*)collection, size * sizeof(Color));
}

bool writeOnFile(const Color* collection, const char* fileName, const unsigned size)
{
    if (!fileName || !collection)
    {
        return false;
    }

    std::ofstream ofs(fileName, std::ios::out | std::ios::app | std::ios::binary);

    if (!ofs.is_open())
    {
        return false;
    }

    writeOnFile(ofs, collection, size);

    ofs.close();

    return true;
}

int main()
{
    unsigned n;

    std::cin >> n;

    Color* collection = initCollection(n);

    writeOnFile(collection, "color.dat", n);

    delete[] collection;

    return 0;
}