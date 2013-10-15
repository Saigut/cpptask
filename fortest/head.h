#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

class Student
{
public:
    Student();
    void setData();
    void setNext(Student * ptr);

    void getData();
    char * getStuID();
    char * getName();
    char * getGclass();
    int getMathScore();
    int getEnglishScore();
    int getPhyscore();
    Student * getNext();

    void getMath();
    void getEnglish();
    void getPhy();

private:
    Student * next;
    char stuID[11];
    char name[20];
    char gclass[20];

    int mathScore, englishScore, phyScore;

};

class StudentList
{
public:
//   StudentList(Student * HeadP);
//   int getSize() const;
    StudentList();
    void readFromFile();
    void saveToFile();

    void addStu();
    void updateStu();
    void searchStu();
    void deleteStu();
    void sortStu();

    void searchID();
    void searchName();
    void searchGclass();
    void searchMath();
    void searchEng();
    void searchPhy();

    void menuList();

private:
    Student * HeadPtr;
    Student * CurPtr;
    Student * NextPtr;
};

void welcome();
void about();
void quit();





#endif // HEAD_H_INCLUDED
