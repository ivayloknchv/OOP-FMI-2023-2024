#include <iostream>
#include <fstream>
 
const unsigned MAX_SIZE = 100;
 
struct Color
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};
 
struct ColorCollection
{
    Color arr[MAX_SIZE]{};
    unsigned size = 0;
};
 
 
Color parseColor(uint32_t currentColorCode)
{
    Color c;
 
    c.red = (currentColorCode & 0xff0000) >>16;
    c.green = (currentColorCode & 0x00ff00) >> 8;
    c.blue = currentColorCode & 0x0000ff;
 
    return c;
}
 
void readColorsFromFile(std::ifstream& ifs, ColorCollection& collection)
{
    uint32_t currentColorCode;
 
    
    while (true)
    {
        
        ifs >> currentColorCode;
 
        if (ifs.eof())
        {
            
            break;
        }
 
        ifs.ignore();
        collection.arr[collection.size] = parseColor(currentColorCode);
 
        collection.size++;
    }
 
    collection.arr[collection.size] = parseColor(currentColorCode);
 
    collection.size++;
}
 
void readColorsFromFile(const char* fileName, ColorCollection& collection)
{
    if (!fileName)
    {
        return;
    }
    
    std::ifstream ifs(fileName,std::ios::in);
 
    if(!ifs.is_open())
    {
        return;
    }
 
    readColorsFromFile(ifs, collection);
    
    ifs.close();
}
 
uint32_t getPowerOfTwo(unsigned pow)
{
    return 1 << pow;
}
 
uint32_t getColorCode(const Color& c)
{
    return c.red * getPowerOfTwo(16) + c.green * getPowerOfTwo(8) + c.blue;
}
 
void printOnFile(std::ofstream& ofs, ColorCollection& collection, bool(*pred)(uint32_t))
{
    for (unsigned i = 0; i < collection.size; i++)
    {
        if (pred(collection.arr[i].red))
        {
            ofs << getColorCode(collection.arr[i]);
 
            if (i != collection.size - 1)
            {
                ofs << '|';
            }
        }
    }
}
 
void printOnFile(const char* fileName, ColorCollection& collection, bool(*pred)(uint32_t))
{
    if (!fileName)
    {
        return;
    }
 
    std::ofstream ofs(fileName, std::ios::out);
 
    if (!ofs.is_open())
    {
        return;
    }
 
    printOnFile(ofs, collection, pred);
 
    ofs.close();
}
 
void printRedColors(const char* fileName, const ColorCollection& collection)
{
}
 
int main()
{
    ColorCollection collection;
 
    readColorsFromFile("colors.txt", collection);
 
    printOnFile("colors.txt", collection, [](uint32_t x) -> bool {return true; });
 
    printOnFile("red.txt", collection, [](uint32_t x) -> bool {return x>250; });
 
    return 0;
}
