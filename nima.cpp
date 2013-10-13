// StudentSys.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
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
			cout<<"��һ��������δ��ѧ�����ϣ���¼��"<<endl;
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
			cout<<"�Ѷ���"<<stu.size()<<"��ѧ����Ϣ"<<endl;
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
	cout<<"����ʧ��"<<endl;
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
	cout<<"��Ҫ���Ӷ��ٸ�ѧ��(����0ȡ��)��";
	cin>>num;
	for (int i=0;i<num;i++)
	{
		cout<<"������ѧ��ѧ�š��������༶����ѧ��Ӣ������ɼ���\n���ӣ�3112007924 �¿��� �ż�1 100 80 78\n>>";
		cin>>id>>name>>grade>>Math>>English>>PE;
		student* m_stu=CreatStudent(id,name,grade,Math,English,PE);
		stu.push_back(*m_stu);
		cout<<"��ӳɹ�,Ŀǰ����"<<stu.size()<<"��ѧ����Ϣ"<<endl;
		cout<<endl;
	}
	save();

}
void studentSys::query(){
	cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�༶"<<setw(10)<<"��ѧ"<<setw(10)<<"Ӣ��"<<setw(10)<<"����"<<endl;
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
	cout<<"1���޸����ϣ�2��ɾ�����ϣ�0��ȡ��\n>>";
	cin>>mode;
	if(mode==0)return;
	cout<<"������ѧ�ź��������ÿո������";
	cin>>oid>>oname;
	for (vector<student>::iterator it=stu.begin();it!=stu.end();it++)
	{
		if (mode==1&&(*it).getId()==oid&&(*it).getName()==oname)
		{
			cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�༶"<<setw(10)<<"��ѧ"<<setw(10)<<"Ӣ��"<<setw(10)<<"����"<<endl;
			cout<<setw(10)<<(*it).getId()<<setw(10)<<(*it).getName()<<setw(10)<<(*it).getGrade()<<setw(10)<<(*it).getMath()<<setw(10)<<(*it).getEnglish()<<setw(10)<<(*it).getPE()<<endl;
			cout<<"������ѧ�š��������༶����ѧ��Ӣ������ɼ����ÿո������\n>>";
			cin>>id>>name>>grade>>Math>>English>>PE;
			(*it).setEnglish(English);
			(*it).setId(id);
			(*it).setGrade(grade);
			(*it).setMath(Math);
			(*it).setName(name);
			(*it).setPE(PE);
			cout<<"�޸ĳɹ�"<<endl;
			cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�༶"<<setw(10)<<"��ѧ"<<setw(10)<<"Ӣ��"<<setw(10)<<"����"<<endl;
			cout<<setw(10)<<(*it).getId()<<setw(10)<<(*it).getName()<<setw(10)<<(*it).getGrade()<<setw(10)<<(*it).getMath()<<setw(10)<<(*it).getEnglish()<<setw(10)<<(*it).getPE()<<endl;
			break;
		}else if (mode==2&&(*it).getId()==oid&&(*it).getName()==oname)
		{
			cout<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�༶"<<setw(10)<<"��ѧ"<<setw(10)<<"Ӣ��"<<setw(10)<<"����"<<endl;
			cout<<setw(10)<<(*it).getId()<<setw(10)<<(*it).getName()<<setw(10)<<(*it).getGrade()<<setw(10)<<(*it).getMath()<<setw(10)<<(*it).getEnglish()<<setw(10)<<(*it).getPE()<<endl;
			cout<<"�Ƿ�Ҫɾ��(y/n) ";
			char b;
			cin>>b;
			if (b=='y'){
				stu.erase(it);
				cout<<"ɾ���ɹ�"<<endl;
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
	cout<<"��ѧƽ���֣�"<<msum/stu.size()<<endl;
	cout<<"Ӣ��ƽ���֣�"<<esum/stu.size()<<endl;
	cout<<"����ƽ���֣�"<<psum/stu.size()<<endl;
	cout<<endl;

}
void studentSys::out(){
	fstream outfile("student.txt",ios::out);
	double msum=0,esum=0,psum=0;
	outfile<<setw(10)<<"ѧ��"<<setw(10)<<"����"<<setw(10)<<"�༶"<<setw(10)<<"��ѧ"<<setw(10)<<"Ӣ��"<<setw(10)<<"����"<<endl;
	for (int i=0;i<stu.size();i++)
	{
		msum+=stu[i].getMath();
		esum+=stu[i].getEnglish();
		psum+=stu[i].getPE();
		outfile<<setw(10)<<stu[i].getId()<<setw(10)<<stu[i].getName()<<setw(10)<<stu[i].getGrade()<<setw(10)<<stu[i].getMath()<<setw(10)<<stu[i].getEnglish()<<setw(10)<<stu[i].getPE()<<endl;
	}
	outfile<<endl;
	outfile<<"��ѧƽ���֣�"<<msum/stu.size()<<endl;
	outfile<<"Ӣ��ƽ���֣�"<<esum/stu.size()<<endl;
	outfile<<"����ƽ���֣�"<<psum/stu.size()<<endl;
	cout<<"�ļ��������student.txt��"<<endl;
}
int main()
{
	cout<<"\t\t�����  ��ӭ����ѧ���ɼ�����ϵͳ  ��������"<<endl;
	studentSys admin;
	bool b=true;
	int select;
	while(b){
	cout<<"1�������¼\n2����ѯ��¼\n3�����¼�¼\n4��ͳ�Ƽ�¼\n5�������¼\n0���˳�\n>>";
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
		cout<<"�������"<<endl;
		break;
	}
}
	return 0;
}

