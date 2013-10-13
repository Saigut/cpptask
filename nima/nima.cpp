
// StudentSys.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

class student
{
public:

	student* getStudent(){
		return this;
	}
	void setId(int id) {
		this->id = id;
	}

	void setName(string name) {
		this->name = name;
	}

	void setGrade(string grade) {
		this->grade = grade;
	}

	void setMath(int Math) {
		this->Math = Math;
	}

	void setEnglish(int English) {
		this->English = English;
	}

	void setPE(int PE) {
		this->PE = PE;
	}

	int getId() {
		return id;
	}

	string getName() {
		return name;
	}

	string getGrade() {
		return grade;
	}

	int getMath() {
		return Math;
	}

	int getEnglish() {
		return English;
	}

	int getPE() {
		return PE;
	}


private:
	int id;
	string name;
	string grade;
	int Math;
	int English;
	int PE;
};
class studentSys
{
public:
	studentSys(){
		int a;
		FILE *stream;
		if ((stream = fopen("student.dat", "rb")) == NULL)
		{
			cout<<"第一次运行尚未有学生资料，请录入"<<endl;
			add();
		}
else
{
			while(1)
			{
				student* temp=new student;
				a=fread(temp,sizeof(student),1,stream);
				if(a==0)break;
				stu.push_back(*temp);

			}
			fclose(stream);
			cout<<"已读入"<<stu.size()<<"条学生信息"<<endl;
		}

	}
	student* CreatStudent(int id,string name,string grade,int Math,int English,int PE);
	void save();
	void add();
	void query();
	void update();
	void mean();
	void out();
private:
	vector<student> stu;
};
void studentSys::save(){
	FILE *stream;
if ((stream = fopen("student.dat", "wb")) == NULL)
{
	cout<<"保存失败"<<endl;
	return;
}
	fwrite(&stu[0],sizeof(student),stu.size(),stream);
	fclose(stream);
}
void studentSys::add(){
	int num;
	int id;
	string name;
	string grade;
	int Math;
	int English;
	int PE;
	cout<<"你要增加多少个学生(输入0取消)：";
	cin>>num;
	for (int i=0;i<num;i++)
	{
		cout<<"请输入学生学号、姓名、班级、数学、英语、体育成绩：\n例子：3112007924 陈俊畅 信计1 100 80 78\n>>";
		cin>>id>>name>>grade>>Math>>English>>PE;
		student* m_stu=CreatStudent(id,name,grade,Math,English,PE);
		stu.push_back(*m_stu);
		cout<<"添加成功,目前已有"<<stu.size()<<"名学生信息"<<endl;
		cout<<endl;
	}
	save();

}
void studentSys::query(){
	cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"班级"<<setw(10)<<"数学"<<setw(10)<<"英语"<<setw(10)<<"体育"<<endl;
	for (int i=0;i<stu.size();i++)
	{
		cout<<setw(10)<<stu[i].getId()<<setw(10)<<stu[i].getName()<<setw(10)<<stu[i].getGrade()<<setw(10)<<stu[i].getMath()<<setw(10)<<stu[i].getEnglish()<<setw(10)<<stu[i].getPE()<<endl;
		if (i!=0&&i%10==0)system("pause");
	}
	system("pause");
	cout<<endl;
}
student* studentSys::CreatStudent(int id,string name,string grade,int Math,int English,int PE){
	student*p= new student;
	p->setEnglish(English);
	p->setId(id);
	p->setGrade(grade);
	p->setMath(Math);
	p->setName(name);
	p->setPE(PE);
	return p;
}
void studentSys::update(){
	int oid;
	int mode;
	string oname;
	int id;
	string name;
	string grade;
	int Math;
	int English;
	int PE;
	cout<<"1、修改资料，2、删除资料，0、取消\n>>";
	cin>>mode;
	if(mode==0)return;
	cout<<"请输入学号和姓名，用空格隔开：";
	cin>>oid>>oname;
	for (vector<student>::iterator it=stu.begin();it!=stu.end();it++)
	{
		if (mode==1&&(*it).getId()==oid&&(*it).getName()==oname)
		{
			cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"班级"<<setw(10)<<"数学"<<setw(10)<<"英语"<<setw(10)<<"体育"<<endl;
			cout<<setw(10)<<(*it).getId()<<setw(10)<<(*it).getName()<<setw(10)<<(*it).getGrade()<<setw(10)<<(*it).getMath()<<setw(10)<<(*it).getEnglish()<<setw(10)<<(*it).getPE()<<endl;
			cout<<"请输入学号、姓名、班级、数学、英语、体育成绩，用空格隔开：\n>>";
			cin>>id>>name>>grade>>Math>>English>>PE;
			(*it).setEnglish(English);
			(*it).setId(id);
			(*it).setGrade(grade);
			(*it).setMath(Math);
			(*it).setName(name);
			(*it).setPE(PE);
			cout<<"修改成功"<<endl;
			cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"班级"<<setw(10)<<"数学"<<setw(10)<<"英语"<<setw(10)<<"体育"<<endl;
			cout<<setw(10)<<(*it).getId()<<setw(10)<<(*it).getName()<<setw(10)<<(*it).getGrade()<<setw(10)<<(*it).getMath()<<setw(10)<<(*it).getEnglish()<<setw(10)<<(*it).getPE()<<endl;
			break;
		}else if (mode==2&&(*it).getId()==oid&&(*it).getName()==oname)
		{
			cout<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"班级"<<setw(10)<<"数学"<<setw(10)<<"英语"<<setw(10)<<"体育"<<endl;
			cout<<setw(10)<<(*it).getId()<<setw(10)<<(*it).getName()<<setw(10)<<(*it).getGrade()<<setw(10)<<(*it).getMath()<<setw(10)<<(*it).getEnglish()<<setw(10)<<(*it).getPE()<<endl;
			cout<<"是否要删除(y/n) ";
			char b;
			cin>>b;
			if (b=='y'){
				stu.erase(it);
				cout<<"删除成功"<<endl;
				cout<<endl;
			}
			break;
		}
	}
	save();
}
void studentSys::mean(){
	double msum=0,esum=0,psum=0;
	for (int i=0;i<stu.size();i++)
	{
		msum+=stu[i].getMath();
		esum+=stu[i].getEnglish();
		psum+=stu[i].getPE();
	}
	cout<<"数学平均分："<<msum/stu.size()<<endl;
	cout<<"英语平均分："<<esum/stu.size()<<endl;
	cout<<"体育平均分："<<psum/stu.size()<<endl;
	cout<<endl;

}
void studentSys::out(){
	fstream outfile("student.txt",ios::out);
	double msum=0,esum=0,psum=0;
	outfile<<setw(10)<<"学号"<<setw(10)<<"姓名"<<setw(10)<<"班级"<<setw(10)<<"数学"<<setw(10)<<"英语"<<setw(10)<<"体育"<<endl;
	for (int i=0;i<stu.size();i++)
	{
		msum+=stu[i].getMath();
		esum+=stu[i].getEnglish();
		psum+=stu[i].getPE();
		outfile<<setw(10)<<stu[i].getId()<<setw(10)<<stu[i].getName()<<setw(10)<<stu[i].getGrade()<<setw(10)<<stu[i].getMath()<<setw(10)<<stu[i].getEnglish()<<setw(10)<<stu[i].getPE()<<endl;
	}
	outfile<<endl;
	outfile<<"数学平均分："<<msum/stu.size()<<endl;
	outfile<<"英语平均分："<<esum/stu.size()<<endl;
	outfile<<"体育平均分："<<psum/stu.size()<<endl;
	cout<<"文件已输出到student.txt中"<<endl;
}
int main()
{
	cout<<"\t\t◎★★★★【  欢迎进入学生成绩管理系统  】★★★★◎"<<endl;
	studentSys admin;
	bool b=true;
	int select;
	while(b){
	cout<<"1、输入记录\n2、查询记录\n3、更新记录\n4、统计记录\n5、输出记录\n0、退出\n>>";
	cin>>select;
	switch (select)
	{
	case 0:
		b=false;
		break;
	case 1:
		admin.add();
		break;
	case 2:
		admin.query();
		break;
	case 3:
		admin.update();
		break;
	case 4:
		admin.mean();
		break;
	case 5:
		admin.out();
		break;
	default:
		cout<<"输入错误"<<endl;
		break;
	}
}
	return 0;
}

