#include <iostream>
#include <fstream>
#include "class.cpp"

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
