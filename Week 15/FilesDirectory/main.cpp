#include <iostream>
#include "Folder.h"
#include "TextFile.h"

int main() {
   
    TextFile* file1 = new TextFile("File1.txt", 12.5);
    TextFile* file2 = new TextFile("File2.txt", 8.3);
    TextFile* file3 = new TextFile("File3.txt", 15.0);

    TextFile* file4 = new TextFile("File4.txt", 5.4);
    TextFile* file5 = new TextFile("File5.txt", 7.7);

    Folder* subFolder = new Folder("SubFolder");
    subFolder->addFile(file4);
    subFolder->addFile(file5);

    Folder* mainFolder = new Folder("MainFolder");
    mainFolder->addFile(file1);
    mainFolder->addFile(file2);
    mainFolder->addFile(file3);
    mainFolder->addFile(subFolder);

    mainFolder->print();

    std::cout << "Total size of all files in the main folder: " << mainFolder->getSize() << " units" << std::endl;

    delete mainFolder; 

    return 0;
}
