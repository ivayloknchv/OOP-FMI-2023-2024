#include <iostream>
#include <fstream>
#include <cstring>

struct Color
{
    char name[8];
    int code;
};

size_t colorsInFile(std::ifstream& ifs)
{
    size_t currentPostion = ifs.tellg();

    ifs.seekg(0, std::ios::end);

    size_t size = ifs.tellg();

    ifs.seekg(0, currentPostion);

    return (size / sizeof(Color));
}

size_t colorsInFile(const char* filePath)
{
    if (!filePath)
    {
        return -1;
    }

    std::ifstream ifs(filePath, std::ios::in | std::ios::binary);

    if (!ifs.is_open())
    {
        return -1;
    }

    size_t size = colorsInFile(ifs);

    return size;
}

Color findColorByName(std::ifstream& ifs, const char* name)
{
    size_t size = colorsInFile(ifs);

    Color* arr = new Color[size];

    ifs.read((char*)arr, size * sizeof(Color));

    for (size_t i = 0; i < size; i++)
    {
        if (!strcmp(arr[i].name, name))
        {
            return arr[i];
        }
    }

    delete[] arr;

    return { "ERROR", -1 };
}

Color findColorByName(const char* name, const char* filePath)
{
    if (!filePath || !name)
    {
        return { "ERROR", -1 };
    }

    std::ifstream ifs(filePath, std::ios::in | std::ios::binary);

    if (!ifs.is_open())
    {
        return { "ERROR", -1 };
    }

    return findColorByName(ifs, name);

}

int main()
{
    Color color = findColorByName("red", "color.dat");

    std::cout << color.name << ' ' << color.code;
    return 0;
}