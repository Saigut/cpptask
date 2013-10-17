#include <iostream>
#include <fstream>
#include "head.h"

using namespace std;


int main()
{
    welcome();
    StudentList StuDB;
    StuDB.readFromFile();
    StuDB.menuList();
    StuDB.saveToFile();
    quit();

    return 0;
}
