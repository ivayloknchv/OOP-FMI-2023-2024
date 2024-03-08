#include <iostream>
#include <fstream>
#include <cstream>
 
namespace Constants
{
    const unsigned MAX_NAME = 16;
    const unsigned MAX_SIZE = 100;
}
 
enum class HairColor 
{
    Brown,
    Black,
    Blonde,
    Red,
    White
};
 
struct Student
{
    char firstName[Constants::MAX_NAME + 1];
    char lastName[Constants::MAX_NAME + 1];
    unsigned fn;
    double avg;
    HairColor hair;
};
 
struct Group
{
    Student students[Constants::MAX_SIZE]{};
    unsigned studentsCount = 0;
};
 
unsigned strLen(const char* str)
{
    unsigned len = 0;
 
    while (str[len] != '\0')
    {
        len++;
    }
 
    return len;
}
 
bool strComp(const char* lhs, const char* rhs)
{
    if (!lhs || !rhs)
    {
        return false;
    }
 
    unsigned len1 = strLen(lhs);
    unsigned len2 = strLen(rhs);
 
    if (len1 != len2)
    {
        return false;
    }
 
    while (*lhs != '\0' && *rhs != '\0')
    {
        if (*lhs != *rhs)
        {
            return false;
        }
 
        lhs++;
 
        rhs++;
    }
 
    return true;
}
 
HairColor parseHairEnum(const char* hair)
{
    if (strComp(hair, "Brown"))
    {
        return HairColor::Brown;
    }
    else if (strComp(hair, "Black"))
    {
        return HairColor::Black;
    }
    else if (strComp(hair, "Blonde"))
    {
        return HairColor::Blonde;
    }
    else if (strComp(hair, "Red"))
    {
        return HairColor::Red;
    }
    else if (strComp(hair, "White"))
    {
        return HairColor::White;
    }
 
    return HairColor::Black;
}
 
void parseStudent(const char* data, Student& student)
{
    if (!data)
    {
        return;
    }
 
    std::stringstream ss(data);
    char hairBuffer[Constants::MAX_SIZE];
 
    ss.getline(student.firstName, Constants::MAX_NAME + 1, ',');
 
    ss.getline(student.lastName, Constants::MAX_NAME + 1, ',');
 
    ss >> student.fn;
    ss.ignore();
 
    ss >> student.avg;
    ss.ignore();
 
    ss.getline(hairBuffer, Constants::MAX_SIZE);
 
    student.hair = parseHairEnum(hairBuffer);
}
 
void readFromFile(std::ifstream& ifs, Group& group)
{
    char buff[Constants::MAX_SIZE];
 
    while (!ifs.eof())
    {
        ifs.getline(buff, Constants::MAX_SIZE);
 
        parseStudent(buff, group.students[group.studentsCount++]);
    }
}
 
Group readFromFile(const char* fileName)
{
    if (!fileName)
    {
        return {"NO","NO",0,2,HairColor::Black};
    }
 
    std::ifstream ifs(fileName);
 
    if (!ifs.is_open())
    {
        return { "NO","NO",0,2,HairColor::Black };;
    }
 
    Group group;
 
    readFromFile(ifs, group);
 
    ifs.close();
 
    return group;
}
 
void printHairColor(std::ofstream& ofs, const HairColor& hair)
{
    switch (hair)
    {
    case HairColor::Black: ofs << "Black" ; break;
    case HairColor::Brown : ofs << "Brown" ; break;
    case HairColor::Blonde: ofs << "Blonde" ; break;
    case HairColor::Red: ofs << "Red" ; break;
    case HairColor::White: ofs << "White"; break;
    }
}
 
void printStudent(std::ofstream& ofs, const Student& student)
{
    ofs << student.firstName << ',' << student.lastName << ',' << student.fn << ','<<student.avg<<',';
    printHairColor(ofs, student.hair);
}
 
void writeToFile(std::ofstream& ofs, const Group& group)
{
    for (unsigned i = 0; i < group.studentsCount; i++)
    {
        printStudent(ofs, group.students[i]);
 
        if (i < group.studentsCount - 1)
        {
            ofs << '\n';
        }
    }
}
 
void writeToFile(const char* fileName, const Group& group)
{
    if (!fileName)
    {
        return;
    }
 
    std::ofstream ofs(fileName);
 
    if (!ofs.is_open())
    {
        return;
    }
 
    writeToFile(ofs, group);
 
    ofs.close();
}
 
int main()
{
    Group group;
    group.students[0] = { "John", "Doe", 12345, 3.8, HairColor::Brown};
    group.students[1] = { "Jane", "Smith", 23456, 4.2, HairColor::Black };
    group.students[2] = { "Alice", "Johnson", 34567, 3.5, HairColor::Blonde };
    group.studentsCount = 3;
 
    writeToFile("students.csv", group);
 
    Group group1 = readFromFile("students.csv");
 
 
    return 0;
}
