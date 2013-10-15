#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "head.h"

using namespace std;

//以下是对Student类的成员函数的定义
Student::Student()
{
    next = NULL;
}
void Student::setData()
{
    string str;
    cout<<"录入学生信息:"<<endl;
    cout<<"请按顺序输入学号、姓名、班级(如: (12)信计1)、数学成绩、英语成绩、体育成绩，各项用空格隔开"<<endl<<">>";
    cin>>stuID>>name>>gclass>>mathScore>>englishScore>>phyScore>>setiosflags(ios_base::unitbuf);

    str.assign(stuID);
    while (str.length() != 10)
    {
        cout<<"学号长度有误，请重新输入学号>>";
        cin>>stuID;
        str.assign(stuID);
    }
    str.assign(name);
    while((str.length() < 1) || (str.length() > 20))
    {
        cout<<"姓名过长或未输入，请重新输入姓名>>";
        cin>>name;
        str.assign(name);
    }
    str.assign(gclass);
    while((str.length() < 1) || (str.length() > 20))
    {
        cout<<"班级输入过长或未输入，请重新输入班级>>";
        cin>>gclass;
        str.assign(gclass);
    }
    while((mathScore < 0) || (mathScore > 100))
    {
        cout<<"数学成绩范围有误，请重新输入数学成绩>>";
        cin>>mathScore;
    }
    while((englishScore < 0) || (englishScore > 100))
    {
        cout<<"英语成绩范围有误，请重新输入英语成绩>>";
        cin>>englishScore;
    }
    while((phyScore < 0) || (phyScore > 100))
    {
        cout<<"体育成绩范围有误，请重新输入体育成绩>>";
        cin>>phyScore;
    }
}
void Student::setNext(Student * ptr)
{
    next = ptr;
}
void Student::getData()
{
    cout<<stuID<<"\t"<<name<<"\t"<<gclass<<"\t"<<mathScore<<"\t"<<englishScore<<"\t"<<phyScore<<endl;
}
char * Student::getStuID()
{
    return stuID;
}
char * Student::getName()
{
    return name;
}
char * Student::getGclass()
{
    return gclass;
}
int Student::getMathScore()
{
    return mathScore;
}
int Student::getEnglishScore()
{
    return englishScore;
}
int Student::getPhyscore()
{
    return phyScore;
}
Student * Student::getNext()
{
    return next;
}
void Student::getMath()
{
    cout<<mathScore<<"\t"<<name<<"\t"<<gclass<<"\t"<<stuID<<endl;
}
void Student::getEnglish()
{
    cout<<englishScore<<"\t"<<name<<"\t"<<gclass<<"\t"<<stuID<<endl;
}
void  Student::getPhy()
{
    cout<<phyScore<<"\t"<<name<<"\t"<<gclass<<"\t"<<stuID<<endl;
}


//以下是对StudentList类的成员函数的定义
StudentList::StudentList()
{
    HeadPtr = NULL;
    CurPtr = NULL;
    NextPtr = NULL;
}
void StudentList::readFromFile()
{
    ifstream readDB("StuDB.dat", ios_base::in | ios_base::binary);
    if(readDB)
    {
        cout<<"打开数据文件成功!"<<endl;
        readDB.seekg(0, ios::end);
        if(readDB.tellg() != 0)
        {
            readDB.clear();
            readDB.seekg(0);
            cout<<"正在读取"<<endl;
            HeadPtr = new Student;
            readDB.read(reinterpret_cast<char *>(HeadPtr), sizeof(Student));
            cout<<"1 ";
            CurPtr = HeadPtr;
            for (int i = 2; CurPtr->getNext() != NULL; i++)
            {
                CurPtr->setNext(new Student);
                CurPtr = CurPtr->getNext();
                readDB.read(reinterpret_cast<char *>(CurPtr), sizeof(Student));
                cout<<i<<" ";
            }
            cout<<endl<<"读取完成"<<endl;
        }
        else
            cout<<"数据文件为空"<<endl;
        readDB.close();
    }
    else
        cout<<"打开文件失败或没有数据文件"<<endl;
}
void StudentList::saveToFile()
{
    ofstream saveDB ("StuDB.dat", ios_base::out | ios_base::binary);
    cout<<endl<<"正在保存数据"<<endl;
    if (HeadPtr != NULL)
    {
        CurPtr = HeadPtr;
        for(int i =1; CurPtr!= NULL; CurPtr = CurPtr->getNext())
        {
            cout<<i<<" ";
            saveDB.write(reinterpret_cast<char *>(CurPtr), sizeof(Student));
            i++;
        }
    }
    else
        saveDB.write(NULL, 0);
    cout<<endl<<"保存完成"<<endl;
    saveDB.close();
}
void StudentList::addStu()
{
    Student * newStuPtr = new Student;
    newStuPtr->setData();
    if (HeadPtr == NULL)
        HeadPtr = newStuPtr;
    else
    {
        CurPtr = HeadPtr;
        for ( ; (CurPtr->getNext() != NULL); CurPtr = CurPtr->getNext()) ;
        CurPtr->setNext(newStuPtr);
        cout<<"添加成功"<<endl;
    }
}
void StudentList::updateStu()
{
    string uID, ID;
    cout<<"请输入要更新信息的学号: ";
    cin>>uID>>setiosflags(ios_base::unitbuf);
    if (HeadPtr == NULL)
        cout<<"还没有录入任何学生信息!"<<endl;
    else
    {
        for (CurPtr = HeadPtr; (CurPtr->getNext() != NULL) && (ID.assign(CurPtr->getStuID()) != uID); CurPtr = CurPtr->getNext()) ;

        if(ID == uID)
        {
            CurPtr->setData();
            cout<<"更新信息成功"<<endl;
        }
        else
            cout<<"没有这个学号的信息!"<<endl;
    }
}
void StudentList::searchStu()
{
    char choice, i=1;

    cout<< endl<<"请选择按照哪种方式查找:"<<endl;
    cout<<"(i)学号，(n)姓名，(c)班级，(m)数学成绩，(e)英语成绩，(p)体育成绩，(k)返回主菜单"<<endl<<">>";
    while (i != 0)
    {
        cin>>choice>>setiosflags(ios_base::unitbuf);

        switch (choice)
        {
        case 'i':
            searchID();
            i = 0;
            break;
        case 'n':
            searchName();
            i = 0;
            break;
        case 'c':
            searchGclass();
            i = 0;
            break;
        case 'm':
            searchMath();
            i = 0;
            break;
        case 'e':
            searchEng();
            i = 0;
            break;
        case 'p':
            searchPhy();
            i = 0;
            break;
        case 'k':
            i = 0;
            break;
        default:
            cout<<"请选择正确的选项>>";
            break;
        }
    }
}

void StudentList::deleteStu()
{
    string dID, ID;
    cout<<"请输入要删除学生的学号: ";
    cin>>dID>>setiosflags(ios_base::unitbuf);
    if (HeadPtr == NULL)
        cout<<"还没有录入任何学生信息!"<<endl;
    else
    {
        for (CurPtr = NULL, NextPtr = HeadPtr; (NextPtr->getNext() != NULL) && (ID.assign(NextPtr->getStuID()) !=dID); )
        {
            CurPtr = NextPtr;
            NextPtr = NextPtr->getNext();
        }
        if (NextPtr->getStuID() == dID)
        {
            if(CurPtr == NULL)
            {
                HeadPtr = NextPtr->getNext();
            }
            else
                CurPtr->setNext(NextPtr->getNext());
            delete NextPtr;
            cout<<"删除成功"<<endl;
        }
        else
            cout<<"没有这个学号的信息!"<<endl;
    }
}

void StudentList::sortStu()
{
    int mathMax = 0, engMax = 0, phyMax = 0;
    int mathFailedCount = 0, engFailedCount = 0, phyFailedCount = 0;
    if (HeadPtr == NULL)
        cout<<"还没有录入任何学生信息!"<<endl;
    else
    {
        for (CurPtr= HeadPtr; CurPtr != NULL; CurPtr = CurPtr->getNext())
        {
            mathMax = (mathMax > CurPtr->getMathScore())?mathMax:CurPtr->getMathScore();
            engMax = (engMax > CurPtr->getEnglishScore())?engMax:CurPtr->getEnglishScore();
            phyMax = (phyMax > CurPtr->getPhyscore())?phyMax:CurPtr->getPhyscore();
            if (CurPtr->getMathScore() < 60)
                mathFailedCount++;
            if (CurPtr->getEnglishScore() < 60)
                engFailedCount++;
            if (CurPtr->getPhyscore() < 60)
                phyFailedCount++;
        }
        cout<<"科目"<<"\t"<<"最高分"<<"\t"<<"未及格人数"<<endl;
        cout<<"数学: "<<"\t"<<mathMax<<"\t"<<mathFailedCount<<endl;
        cout<<"英语: "<<"\t"<<engMax<<"\t"<<engFailedCount<<endl;
        cout<<"体育: "<<"\t"<<phyMax<<"\t"<<phyFailedCount<<endl;
    }

}

void StudentList::searchID()
{
    string sID, ID;
    cout<<"请输入要查找的学号: ";
    cin>>sID>>setiosflags(ios_base::unitbuf);
    if (HeadPtr == NULL)
        cout<<"还没有录入任何学生信息!"<<endl;
    else
    {
        cout<<"学号\t\t"<<"姓名\t"<<"班级\t\t"<<"数学\t"<<"英语\t"<<"体育"<<endl;
        for (CurPtr = HeadPtr; (CurPtr->getNext() != NULL) && (ID.assign(CurPtr->getStuID()) != sID); CurPtr = CurPtr->getNext()) ;

        if(CurPtr != NULL)
            CurPtr->getData();
        else
            cout<<"没有这个学号的信息!"<<endl;
    }
}

void StudentList::searchName()
{
    int i=0;
    string sName, Name;
    cout<<"请输入要查找学生的名字: ";
    cin>>sName>>setiosflags(ios_base::unitbuf);
    if (HeadPtr == NULL)
        cout<<"还没有录入任何学生信息!"<<endl;
    else
    {
        cout<<"学号\t\t"<<"姓名\t"<<"班级\t\t"<<"数学\t"<<"英语\t"<<"体育"<<endl;
        for (CurPtr = HeadPtr; (CurPtr->getNext() != NULL); CurPtr = CurPtr->getNext())
        {
            if(Name.assign(CurPtr->getName()) == sName)
            {
                CurPtr->getData();
                i++;
            }
        }
        if (i == 0)
            cout<<"没有这个姓名的信息!"<<endl;
    }
}

void StudentList::searchGclass()
{
    int i=0;
    string sGclass, Gclass;
    cout<<"请输入要查找的班级(如: (12)信计1): ";
    cin>>sGclass>>setiosflags(ios_base::unitbuf);
    if (HeadPtr == NULL)
        cout<<"还没有录入任何学生信息!"<<endl<<endl;
    else
    {
        cout<<"学号\t\t"<<"姓名\t"<<"班级\t\t"<<"数学\t"<<"英语\t"<<"体育"<<endl;
        for (CurPtr = HeadPtr; (CurPtr != NULL); CurPtr = CurPtr->getNext())
        {
            if(Gclass.assign(CurPtr->getGclass()) == sGclass)
            {
                CurPtr->getData();
                i++;
            }
        }
        if (i == 0)
            cout<<"没有这个班级的信息!"<<endl;
    }
}

void StudentList::searchMath()
{
    if (HeadPtr == NULL)
        cout<<"还没有录入任何成绩信息!"<<endl;
    else
    {
        cout<<"数学"<<"\t"<<"姓名"<<"\t"<<"班级"<<"\t\t"<<"学号"<<endl;
        CurPtr = HeadPtr;
        do
        {
            CurPtr->getMath();
            CurPtr = CurPtr->getNext();
        }
        while (CurPtr != NULL);
    }
}
void StudentList::searchEng()
{
    if (HeadPtr == NULL)
        cout<<"还没有录入任何成绩信息!"<<endl;
    else
    {
        cout<<"英语"<<"\t"<<"姓名"<<"\t"<<"班级"<<"\t\t"<<"学号"<<endl;
        CurPtr = HeadPtr;
        do
        {
            CurPtr->getEnglish();
            CurPtr = CurPtr->getNext();
        }
        while (CurPtr != NULL);
    }
}
void StudentList::searchPhy()
{
    if (HeadPtr == NULL)
        cout<<"还没有录入任何成绩信息!"<<endl;
    else
    {
        cout<<"体育"<<"\t"<<"姓名"<<"\t"<<"班级"<<"\t\t"<<"学号"<<endl;
        CurPtr = HeadPtr;
        do
        {
            CurPtr->getPhy();
            CurPtr = CurPtr->getNext();
        }
        while (CurPtr != NULL);
    }
}
void StudentList::menuList()
{
    char choice, i = 1, j;
    while(i != 0)
    {
        j = 1;
        cout<<endl<<"请选择一项操作: "<<endl;
        cout<<"(a)添加学生，(u)更新学生信息，(s)查找信息，(d)删除学生，(c)统计记录，(q)退出，(b)关于"<<endl<<">>";
        while (j != 0)
        {
            cin>>choice>>setiosflags(ios_base::unitbuf);

            switch (choice)
            {
            case 'a':
                addStu();
                j = 0;
                break;
            case 'u':
                updateStu();
                j = 0;
                break;
            case 's':
                searchStu();
                j = 0;
                break;
            case 'd':
                deleteStu();
                j = 0;
                break;
            case 'c':
                sortStu();
                j = 0;
                break;
            case 'q':
                j = 0;
                i = 0;
                break;
            case 'b':
                about();
                j = 0;
                break;
            default:
                cout<<"请选择正确的选项>>";
                break;
            }
        }
    }
}

void welcome()
{
    cout<<"=======\t=======\t=======\t=======\t=======\t=======\t=======\t=======\t======="<<endl;
    cout<<"\t\t       "<<"欢迎进入学生成绩管理系统"<<endl;
    cout<<"=======\t=======\t=======\t=======\t=======\t=======\t=======\t=======\t======="<<endl;
}
void about()
{
    cout<<"=======\t=======\t=======\t=======\t=======\t=======\t======="<<endl;
    cout<<"关于"<<endl<<endl;
    cout<<"如有问题或建议请联系邮箱: gosaigut@gmail.com"<<endl;
    cout<<"你也可以来为本软件提交代码"<<endl<<"项目地址: https://github.com/Saigut/cpptask"<<endl;
    cout<<"=======\t=======\t=======\t=======\t=======\t=======\t======="<<endl;
}
void quit()
{
    cout<<"=======\t=======\t=======\t=======\t=======\t=======\t=======\t=======\t======="<<endl;
    cout<<"\t\t       "<<"学生成绩管理系统已关闭"<<endl;
    cout<<"=======\t=======\t=======\t=======\t=======\t=======\t=======\t=======\t======="<<endl;
}
