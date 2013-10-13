#include<iostream>
//#include<stdio.h>
using namespace std;
//******************结构体定义**************//
typedef struct Worker    //学生结构体
{
	char name[10];      //学生姓名
	int no;             //学生工号
	char depno[20];     //学生班级
	int math;           //学生数学成绩
	int english;        //学生英语成绩
	int salary;         //学生体育成绩

	struct Worker * next;
}Linkworker;
typedef struct No      //pno链结构体
{
	int no;
	struct No *next;
}Linkno;

typedef struct Salary   //psalary链结构体
{
	int salary;
	int no;
	struct Salary *next;
}Linksalary;

typedef struct Math   //pmath链结构体
{
	int salary;
	int no;
	struct Math *next;
}Linkmath;

typedef struct English   //penglish链结构体
{
	int salary;
	int no;
	struct English *next;
}Linkenglish;

//**************************************初始化*************************************************//

void Initworker(Linkworker *&worker)//学生结构体的初始化
{
	worker=(Linkworker *)malloc(sizeof(Linkworker));
	worker->next=NULL;
}
void Initno(Linkno *&dpno)
{
	dpno=(Linkno *)malloc(sizeof(Linkno));  //pno结构体的初始化
	dpno->next=NULL;
}

void Initsalary(Linksalary *&salary)  //psalary结构体的初始化
{
	salary=(Linksalary *)malloc(sizeof(Linksalary));
	salary->next=NULL;
}
void Initmath(Linkmath *&math)  //pmath结构体的初始化
{
	math=(Linkmath *)malloc(sizeof(Linkmath));
	math->next=NULL;
}
void Initenglish(Linkenglish *&english)  //penglish结构体的初始化
{
	english=(Linkenglish *)malloc(sizeof(Linkenglish));
	english->next=NULL;
}


//***********************************主要的函数方法*******************************************//
void readFile(FILE *fp,Linkworker *&p)//从文件中读取数据到单链表里
{
	Linkworker *s;
	if((fp=fopen("zg.txt","r"))==NULL)
	{
		printf("没有发现文件\n");
		return;
	}
	while(true)
	{
		s=(Linkworker *)malloc(sizeof(Linkworker));
	if(fscanf(fp,"%d%s%s%d%d%d",&s->no,&s->name,&s->depno,&s->math,&s->english,&s->salary) == EOF)
			break;
		p->next=s;
		p=s;
	}
	p->next=NULL;
	fclose(fp);
}
void deleteworker(Linkworker *&worker)
{
}
void Addworker(Linkworker *&worker)//增加学生记录
{
	Linkworker *s,*p=worker;
	printf("******请输入要增加的学生记录*******\n");
	printf("学号    姓名     班级      数学     英语   体育\n");
    //while(p->next!=NULL)
		//p=p->next;
	s=(Linkworker *)malloc(sizeof(Linkworker));
	cin>>s->no  >>s->name  >>s->depno  >>s->math  >>s->english   >>s->salary;
    p->next=s;
	p=s;
	p->next=NULL;
}

int LocateElem(Linkworker *worker,int no) //查找学号在链表的位置
{
	Linkworker *p=worker->next;
	int i=1;
	while(p!=NULL && p->no!=no)
	{
		p=p->next;
		i++;
	}
	if(p==NULL)
		return 0;
	else
		return i;
}

void DeleteWorker(Linkworker *worker,int no)//删除学生链表的数据
{
	if(no==0)
	{

		Linkworker *p=worker;
		Linkworker *q;
	    q=p->next;
		if(q==NULL)
		{
			return;
		}
	    p->next=q->next;
		free(q);
		return;
	}
	Linkworker *p=worker->next;
	Linkworker *q;
	if(p==NULL)
	{
		printf("空，不能删除");
		return;
	}
	int j=0;
	while(j<no-1 && p!=NULL)
	{
		j++;
		p=p->next;
	}

	if(p!=NULL)
	{
		q=p->next;
		if(q==NULL)
		{
			return;
		}
	    p->next=q->next;
		free(q);
	}

}

void updateWorker(Linkworker *worker,int no)  //修改数据
{
	Linkworker *p=worker->next;
	while(p!=NULL && p->no!=no)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
	   printf("学号:");
		 cin>>p->no;
	   printf("姓名:");
		 cin>>p->name;
       printf("班级:");
		cin>>p->depno;
	   printf("数学:");
		cin>>p->math;
	    printf("英语:");
		cin>>p->english;
		printf("体育:");
		cin>>p->salary;

	}
}

void tongjiworker(Linkworker *worker)   //统计
{
	Linkworker *p=worker->next;
	int max_math=p->math;
	int max_english=p->english;
	int max_salary=p->salary;
	int nopass_math=0;
	int nopass_english=0;
	int nopass_salary=0;
	while(p!=NULL)
	{
		if(p->math>max_math)
			max_math=p->math;
		if(p->english>max_english)
			max_english=p->english;
		if(p->salary>max_salary)
			max_salary=p->salary;
		if(p->math<60)
			nopass_math++;
		if(p->english<60)
			nopass_english++;
		if(p->salary<60)
			nopass_salary++;
		p=p->next;
	}
	printf("数学最高分 英语最高分 体育最高分 数学不及格人数 英语不及格人数 体育不及格人数 ");
    printf("%9d%9d%9d%15d%15d%15d\n",max_math,max_english,max_salary,nopass_math,nopass_english,nopass_salary);

}

void DispWorker(Linkworker *worker)//输出学生链表的数据
{
	Linkworker *p=worker->next;
	printf("********输出单链表里的数据:*******\n");
		if(p==NULL)
	{
		printf("<<职工链表为空:\n");
		return;
	}
	printf("学 号     姓 名       班 级        数 学     英 语     体 育\n");
	while(p!=NULL)
	{
		printf("%d%13s%15s%9d%9d%9d\n",p->no,p->name,p->depno,p->math,p->english,p->salary);
		p=p->next;
	}
}
void sort_pno(Linkworker *worker,Linkno *&dpno)//按no排序
{
	Linkworker *p=worker->next;
	Linkno *pno=dpno,*s;
    while(p!=NULL)
	{
		s=(Linkno *)malloc(sizeof(Linkno));
		s->no=p->no;
		pno->next=s;
		pno=s;
		p=p->next;
	}
	pno->next=NULL;
	Linkno *pp=dpno->next,*q,*r;
	if(pp!=NULL)
	{
		r=pp->next;
		pp->next=NULL;
		pp=r;
		while(pp!=NULL)
		{
			r=pp->next;
			q=dpno;
			while(q->next!=NULL&&q->next->no<pp->no)
				q=q->next;
			pp->next=q->next;
			q->next=pp;
			pp=r;
		}
	}
}
void Disp_no(Linkworker *worker,Linkno *dpno)//按no排序输出
{
	Linkno *no=dpno->next;
	Linkworker *p;
	if(no==NULL)
	{
		printf("<<没有按no排序，请先排序再输出:\n");
	}
	else
	{
        printf("*******按no输出。沿pno链输出全部学生记录。:*******\n");
		printf("  学号    姓名     班级     数学      英语     体育\n");
		while(no!=NULL)
		{
			p=worker->next;
			while(no->no!=p->no&&p!=NULL)
				p=p->next;
			printf("  %d%9s%9s%9d%9d%9d\n",p->no,p->name,p->depno,p->math,p->english,p->salary);
			no=no->next;
		}
	}
}


void clear(FILE *fp)//清除文件数据
{
	if((fp=fopen("zg.txt","w"))=NULL)
	{
		printf("文本清空\n");
		return;
	}
	printf("<<文件已经清空\n");
}
void SaveOut(Linkworker *L , FILE *fs)//保存链表数据到文本里
{
	char tempbuf[30];

	Linkworker *p=L->next;
	while (p!=NULL)
	{
		sprintf(tempbuf,"%d %s %s %d %d  %d\r\n",p->no,p->name,p->depno,p->math,p->english,p->salary);
		fwrite(tempbuf,strlen(tempbuf),1,fs);
		p=p->next;
	}
	printf("<<退出程序\n");
}
void main()
{
	int i,t1=1,t2;
	Linkworker *w,*p;
	Linkno *dpno;
	Initno(dpno);
	Linksalary *salary;
	Initsalary(salary);
	Initworker(w);
	p=w;
	FILE *fp;
	readFile(fp,p);
    printf("1.输入。添加一个学生记录。\n"
    "2.输出。输出全部学生记录。\n"
    "3.按学号排序。通过pno指针将学生记录按学号o从小到大链接起来。\n"
    "4.按学号输出。沿pno链输出全部学生记录。\n"
	"5.统计。统计所有科目最高分与不及格人数。\n"
	"6.删除。按学号删除该生所有记录.\n"
	"7.修改。按学号修改该生的记录.\n"
    "9.全清。删除学生文件中的全部记录。\n"
    "0.保存退出\n");
	while(t1)
	{
		printf("************************************************\n");
		printf("请输入选择:");
		cin>>t2;
		switch(t2)
		{
		case 1:
			{
				Addworker(p);
				break;
			}
		case 2:
			{
				DispWorker(w);
				break;
			}
		case 3:
			{
				sort_pno(w,dpno);

				printf("<<已按学号排序\n");
				break;
			}
		case 4:
			{

				Disp_no(w,dpno);
				break;
			}
		case 5:
			{
				tongjiworker(w);
				break;
			}
		case 6:
			{
				int no2;
               printf("请输入你要删除的学号");
				   cin>>no2;
				int loca=LocateElem(w,no2);
				DeleteWorker(w,loca-1);
				break;
			}
		case 7:
			{
				int no2;
               printf("请输入你要修改的学号");
				   cin>>no2;
				updateWorker(w,no2);
				break;
			}

		case 9:
			{
				clear(fp);
				break;
			}
		case 0:
			{

					FILE *fs;
					if((fs=fopen("zg.txt","w"))==NULL)
					{
						cout<<"can't open file\n";
						break;
					}
					SaveOut(w,fs);
					fclose(fs);
					return ;
			}
		}
	}
}
