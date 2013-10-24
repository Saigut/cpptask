#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

//学生类，学生结点
class Student
{
public:
    Student();                  //构造函数

    //以下部分为各种获取学生信息的函数
    void getData();             //获得学生信息
    char * getStuID();          //获得学生学号
    char * getName();           //获得学生姓名
    char * getGclass();         //获得学生班级
    int getMathScore();         //获得数学成绩
    int getEnglishScore();     //获得英语成绩
    int getPhyscore();          //获得物理成绩
    void getMath();             //获得数学成绩并显示姓名等其它信息
    void getEnglish();          //获得英语成绩并显示姓名等其它信息
    void getPhy();              //获得物理成绩并显示姓名等其它信息

    //以下部分为各种设置学生信息的函数
    void setData();             //录入学生信息
    void setStuID();            //设置学生学号
    void setName();             //设置学生姓名
    void setGclass();           //设置学生班级
    void setMathScore();        //设置数学成绩
    void setEnglishScore();     //设置英语成绩
    void setPhyScore();         //设置物理成绩

    //以下是关于学生结点指针的函数
    Student * getNext();        //获得下一个学生节点的指针
    void setNext(Student * ptr);    //设置指向下一个学生节点的指针

private:
    //以下部分为学生结点的各种数据成员
    char stuID[11];             //学生的学号
    char name[20];              //学生的姓名
    char gclass[20];            //学生班级

    int mathScore, englishScore, phyScore;  //学生数学、英语、物理的成绩

    Student * next;             //指向下一个学生节点的指针

};

//链表类，学生信息数据库
class StudentList
{
public:

    StudentList();              //构造函数

    //文件操作函数
    void readFromFile();        //读取文件函数
    void saveToFile();          //保存文件函数

    //各种对学生操作的函数
    void addStu();              //添加学生
    void updateStu();           //更新学生信息
    void searchStu();           //查找学生
    void deleteStu();           //删除学生
    void sortStu();             //统计各科最高分和不及格人数
    void checkStu(Student * CurStu);    //检查输入的学生信息是否合理，不合理的需要重新输入
    bool checkID(std::string str);      //检查学生学号是否唯一

    //各种查找学生信息函数
    void searchID();            //按学号查找
    void searchName();          //按姓名查找
    void searchGclass();        //按班级查找
    void searchMath();          //查看数学成绩
    void searchEng();           //查看英语成绩
    void searchPhy();           //查看物理成绩

    //主菜单
    void menuList();

private:
    //链表的头指针和用于对结点操作的指针
    Student * HeadPtr;          //链表头指针
    Student * CurPtr;           //当前指针。操作学生及学生信息时用到
    Student * NextPtr;          //下一个指针。操作学生及学生信息时用到
};

//欢迎、退出、关于界面
void welcome();
void quit();
void about();






#endif // HEAD_H_INCLUDED
