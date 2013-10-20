#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

//学生类，学生结点
class Student
{
public:
    Student();

    //以下部分为各种获取学生信息的函数
    void getData();
    char * getStuID();
    char * getName();
    char * getGclass();
    int getMathScore();
    int getEnglishScore();
    int getPhyscore();
    void getMath();
    void getEnglish();
    void getPhy();

    //以下部分为各种设置学生信息的函数
    void setData();
    void setStuID();
    void setName();
    void setGclass();
    void setMathScore();
    void setEnglishScore();
    void setPhyScore();

    //以下是关于学生结点指针的函数
    Student * getNext();
    void setNext(Student * ptr);

private:
    //以下部分为学生结点的各种数据成员
    char stuID[11];
    char name[20];
    char gclass[20];

    int mathScore, englishScore, phyScore;

    Student * next;

};

//链表类，学生信息数据库
class StudentList
{
public:

    StudentList();

    //文件操作函数
    void readFromFile();
    void saveToFile();

    //各种对学生操作的函数
    void addStu();
    void updateStu();
    void searchStu();
    void deleteStu();
    void sortStu();         //统计各科最高分和不及格人数
    void checkStu(Student * CurStu);
    bool checkID(std::string str);

    //各种查找学生信息函数
    void searchID();
    void searchName();
    void searchGclass();
    void searchMath();
    void searchEng();
    void searchPhy();

    //操作菜单
    void menuList();

private:
    //链表的头指针和用于对结点操作的指针
    Student * HeadPtr;
    Student * CurPtr;
    Student * NextPtr;
};

//欢迎、退出、关于界面
void welcome();
void quit();
void about();






#endif // HEAD_H_INCLUDED
