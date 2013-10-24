#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "head.h"

using namespace std;

/*****以下是对学生类的成员函数的定义*****/
Student::Student()          //构造函数，将指针初始化为空指针
{
    next = NULL;
}

//以下部分为各种获取学生信息的函数的定义
void Student::getData()     //获得学生信息
{
    cout<<stuID<<"\t"<<name<<"\t"<<gclass<<"\t"<<mathScore<<"\t"<<englishScore<<"\t"<<phyScore<<endl;
}

char * Student::getStuID()  //获得学生学号
{
    return stuID;
}

char * Student::getName()   //获得学生姓名
{
    return name;
}

char * Student::getGclass() //获得学生班级
{
    return gclass;
}

int Student::getMathScore() //获得数学分数
{
    return mathScore;
}

int Student::getEnglishScore()  //获得英语分数
{
    return englishScore;
}

int Student::getPhyscore()  //获得物理分数
{
    return phyScore;
}

void Student::getMath()     //获得数学成绩并显示姓名等其它信息
{
    cout<<mathScore<<"\t"<<name<<"\t"<<gclass<<"\t"<<stuID<<endl;
}

void Student::getEnglish()  //获得英语成绩并显示姓名等其它信息
{
    cout<<englishScore<<"\t"<<name<<"\t"<<gclass<<"\t"<<stuID<<endl;
}

void  Student::getPhy()     //获得物理成绩并显示姓名等其它信息
{
    cout<<phyScore<<"\t"<<name<<"\t"<<gclass<<"\t"<<stuID<<endl;
}

//以下部分为各种设置学生信息的函数的定义
void Student::setData()     //录入学生信息
{
    string str;
    cout<<"录入学生信息:"<<endl;
    cout<<"请按顺序输入学号、姓名、班级(如: (12)信计1)、数学成绩、英语成绩、体育成绩，各项用空格隔开"<<endl<<">>";
    cin>>stuID>>name>>gclass>>mathScore>>englishScore>>phyScore>>setiosflags(ios_base::unitbuf);    //输入数据并清除缓冲区
}

void Student::setStuID()    //设置学生学号
{
    cin>>stuID>>setiosflags(ios_base::unitbuf);
}

void Student::setName()     //设置学生姓名
{
    cin>>name>>setiosflags(ios_base::unitbuf);
}

void Student::setGclass()   //设置学生班级
{
    cin>>gclass>>setiosflags(ios_base::unitbuf);
}

void Student::setMathScore()    //设置数学成绩
{
    cin>>mathScore>>setiosflags(ios_base::unitbuf);
}

void Student::setEnglishScore() //设置英语成绩
{
    cin>>englishScore>>setiosflags(ios_base::unitbuf);
}

void Student::setPhyScore() //设置物理成绩
{
    cin>>phyScore>>setiosflags(ios_base::unitbuf);
}

//以下是关于学生结点指针的函数
Student * Student::getNext()    //获得下一个学生节点的指针
{
    return next;
}
void Student::setNext(Student * ptr)    //设置指向下一个学生节点的指针
{
    next = ptr;
}



/*****以下是对学生链表类的成员函数的定义*****/
StudentList::StudentList()      //构造函数，将指针初始化为空指针
{
    HeadPtr = NULL;
    CurPtr = NULL;
    NextPtr = NULL;
}

//文件操作函数的定义
void StudentList::readFromFile()    //读取文件
{
    ifstream readDB("StuDB.dat", ios_base::in | ios_base::binary);  //以二进制方式打开待读取的文件
    if(readDB)
    {
        cout<<"打开数据文件成功!"<<endl;
        readDB.seekg(0, ios::end);
        if(readDB.tellg() != 0)             //判断文件是否为空
        {
            readDB.clear();
            readDB.seekg(0);        //将文件指针设回文件开头
            cout<<"正在读取"<<endl;
            HeadPtr = new Student;
            readDB.read(reinterpret_cast<char *>(HeadPtr), sizeof(Student));
            cout<<"1 ";
            CurPtr = HeadPtr;
            for (int i = 2; CurPtr->getNext() != NULL; i++)     //从文件中读取学生信息，直到学生节点指向下一个学生的指针为空
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

void StudentList::saveToFile()  //保存文件
{
    ofstream saveDB ("StuDB.dat", ios_base::out | ios_base::binary);    //以二进制方式打开待保存的文件
    cout<<endl<<"正在保存数据"<<endl;
    if (HeadPtr != NULL)
    {
        CurPtr = HeadPtr;
        for(int i =1; CurPtr!= NULL; CurPtr = CurPtr->getNext())        //保存数据直到最后一个节点
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

//各种对学生操作的函数的定义
void StudentList::addStu()      //添加学生
{
    Student * newStuPtr = new Student;      //为新增的学生动态分配内存
    newStuPtr->setData();
    checkStu(newStuPtr);
    if (HeadPtr == NULL)
    {
        HeadPtr = newStuPtr;
        cout<<"添加成功"<<endl;
    }
    else
    {
        CurPtr = HeadPtr;
        for ( ; (CurPtr->getNext() != NULL); CurPtr = CurPtr->getNext()) ;  //将新增学生加到链表最后
        CurPtr->setNext(newStuPtr);
        cout<<"添加成功"<<endl;
    }
}

void StudentList::updateStu()   //更新学生信息
{
    string uID, ID;
    cout<<"请输入要更新信息的学号: ";
    cin>>uID>>setiosflags(ios_base::unitbuf);
    if (HeadPtr == NULL)
        cout<<"还没有录入任何学生信息!"<<endl;
    else
    {
        for (CurPtr = HeadPtr; (CurPtr->getNext() != NULL) && (ID.assign(CurPtr->getStuID()) != uID); CurPtr = CurPtr->getNext()) ; //查找并定位欲更新信息的学生

        if(ID == uID)
        {
            CurPtr->setData();
            checkStu(CurPtr);
            cout<<"更新信息成功"<<endl;
        }
        else
            cout<<"没有这个学号的信息!"<<endl;
    }
}

void StudentList::searchStu()   //查找学生信息
{
    char choice, i=1;

    cout<< endl<<"请选择按照哪种方式查找:"<<endl;
    cout<<"(i)学号，(n)姓名，(c)班级，(m)数学成绩，(e)英语成绩，(p)体育成绩，(k)返回主菜单"<<endl<<">>";
    while (i != 0)      //按不同方式炸找信息
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

void StudentList::deleteStu()   //删除学生
{
    string dID, ID;
    cout<<"请输入要删除学生的学号: ";
    cin>>dID>>setiosflags(ios_base::unitbuf);
    if (HeadPtr == NULL)
        cout<<"还没有录入任何学生信息!"<<endl;
    else
    {
        for (CurPtr = NULL, NextPtr = HeadPtr; (NextPtr->getNext() != NULL) && (ID.assign(NextPtr->getStuID()) !=dID); )    //查找并定位欲删除的学生
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
            delete NextPtr;         //释放已删除学生节点的内存
            cout<<"删除成功"<<endl;
        }
        else
            cout<<"没有这个学号的信息!"<<endl;
    }
}

void StudentList::sortStu()     //统计学生信息
{
    int mathMax = 0, engMax = 0, phyMax = 0;
    int mathFailedCount = 0, engFailedCount = 0, phyFailedCount = 0;
    if (HeadPtr == NULL)
        cout<<"还没有录入任何学生信息!"<<endl;
    else
    {
        for (CurPtr= HeadPtr; CurPtr != NULL; CurPtr = CurPtr->getNext())       //查找各科成绩最大值、统计各科不及格人数
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

void StudentList::checkStu(Student * CurStu)    //检查输入的学生信息是否合理，不合理的需要重新输入
{
    string str;
    str.assign(CurStu->getStuID());
    while((str.length() != 10) || (checkID(str) == false))
    {
        while (str.length() != 10)
        {
            cout<<"学号长度有误，请重新输入学号>>";
            CurStu->setStuID();
            str.assign(CurStu->getStuID());
        }
        if (checkID(str) == false)
        {
            cout<<"此学号已存在，请重新输入学号>>";
            CurStu->setStuID();
            str.assign(CurStu->getStuID());
        }
    }

    str.assign(CurStu->getName());
    while((str.length() < 1) || (str.length() > 20))
    {
        cout<<"姓名过长或未输入，请重新输入姓名>>";
        CurStu->setName();
        str.assign(CurStu->getName());
    }
    str.assign(CurStu->getGclass());
    while((str.length() < 1) || (str.length() > 20))
    {
        cout<<"班级输入过长或未输入，请重新输入班级>>";
        CurStu->setGclass();
        str.assign(CurStu->getGclass());
    }
    while((CurStu->getMathScore() < 0) || (CurStu->getMathScore() > 100))
    {
        cout<<"数学成绩范围有误，请重新输入数学成绩>>";
        CurStu->setMathScore();
    }
    while((CurStu->getEnglishScore() < 0) || (CurStu->getEnglishScore() > 100))
    {
        cout<<"英语成绩范围有误，请重新输入英语成绩>>";
        CurStu->setEnglishScore();
    }
    while((CurStu->getPhyscore() < 0) || (CurStu->getPhyscore() > 100))
    {
        cout<<"体育成绩范围有误，请重新输入体育成绩>>";
        CurStu->setPhyScore();
    }
}

bool StudentList::checkID(string str)   //检查学生学号是否唯一
{
    string ID;
    if (HeadPtr != NULL)
    {
        CurPtr = HeadPtr;
        ID.assign(CurPtr->getStuID());
        for (; (CurPtr->getNext() != NULL) && (ID.assign(CurPtr->getStuID()) != str); CurPtr = CurPtr->getNext()) ;     //查找学生以确定要录入的学号是否唯一
        if (ID != str)
            return true;
        else
            return false;
    }
    else
    {
         return true;
    }
}

void StudentList::searchID()    //按学号查询
{
    string sID, ID;
    cout<<"请输入要查找的学号: ";
    cin>>sID>>setiosflags(ios_base::unitbuf);
    if (HeadPtr == NULL)
        cout<<"还没有录入任何学生信息!"<<endl;
    else
    {
        cout<<"学号\t\t"<<"姓名\t"<<"班级\t\t"<<"数学\t"<<"英语\t"<<"体育"<<endl;
        for (CurPtr = HeadPtr; (CurPtr->getNext() != NULL) && (ID.assign(CurPtr->getStuID()) != sID); CurPtr = CurPtr->getNext()) ;     //查找学号

        if(CurPtr != NULL)
            CurPtr->getData();
        else
            cout<<"没有这个学号的信息!"<<endl;
    }
}

//各种查找学生信息函数的定义
void StudentList::searchName()  //按姓名查询
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
        for (CurPtr = HeadPtr; (CurPtr->getNext() != NULL); CurPtr = CurPtr->getNext())     //将所有该名字的学生信息都输出出来
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

void StudentList::searchGclass()    //按班级查询
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
        for (CurPtr = HeadPtr; (CurPtr != NULL); CurPtr = CurPtr->getNext())        //将所有在该班级的学生信息都输出出来
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

void StudentList::searchMath()      //查看数学成绩
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

void StudentList::searchEng()       //查看英语成绩
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

void StudentList::searchPhy()       //查看物理成绩
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

//操作菜单函数的定义
void StudentList::menuList()        //主菜单
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

//欢迎、退出、关于界面函数的定义
void welcome()
{
    cout<<"=======\t=======\t=======\t=======\t=======\t=======\t=======\t=======\t======="<<endl;
    cout<<"\t\t       "<<"欢迎进入学生成绩管理系统"<<endl;
    cout<<"=======\t=======\t=======\t=======\t=======\t=======\t=======\t=======\t======="<<endl;
}
void quit()
{
    cout<<"=======\t=======\t=======\t=======\t=======\t=======\t=======\t=======\t======="<<endl;
    cout<<"\t\t       "<<"学生成绩管理系统已关闭"<<endl;
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
