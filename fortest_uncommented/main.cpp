#include <iostream>
#include <fstream>
#include "head.h"           //类及函数的声明都在此头文件中

using namespace std;


int main()
{
    welcome();
    StudentList StuDB;      //建立学生数据库链表
    StuDB.readFromFile();   //从文件中读取数据库数据
    StuDB.menuList();       //展示操作菜单
    StuDB.saveToFile();     //存入数据库数据
    quit();

    return 0;
}
