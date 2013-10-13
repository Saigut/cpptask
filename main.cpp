#include<iostream>
#include<stdio.h>
using namespace std;
//******************�ṹ�嶨��**************//
typedef struct Worker    //ѧ���ṹ��
{
	char name[10];      //ѧ������
	int no;             //ѧ������
	char depno[20];     //ѧ���༶
	int math;           //ѧ����ѧ�ɼ�
	int english;        //ѧ��Ӣ��ɼ�
	int salary;         //ѧ�������ɼ�

	struct Worker * next;
}Linkworker;
typedef struct No      //pno���ṹ��
{
	int no;
	struct No *next;
}Linkno;

typedef struct Salary   //psalary���ṹ��
{
	int salary;
	int no;
	struct Salary *next;
}Linksalary;

typedef struct Math   //pmath���ṹ��
{
	int salary;
	int no;
	struct Math *next;
}Linkmath;

typedef struct English   //penglish���ṹ��
{
	int salary;
	int no;
	struct English *next;
}Linkenglish;

//**************************************��ʼ��*************************************************//

void Initworker(Linkworker *&worker)//ѧ���ṹ��ĳ�ʼ��
{
	worker=(Linkworker *)malloc(sizeof(Linkworker));
	worker->next=NULL;
}
void Initno(Linkno *&dpno)
{
	dpno=(Linkno *)malloc(sizeof(Linkno));  //pno�ṹ��ĳ�ʼ��
	dpno->next=NULL;
}

void Initsalary(Linksalary *&salary)  //psalary�ṹ��ĳ�ʼ��
{
	salary=(Linksalary *)malloc(sizeof(Linksalary));
	salary->next=NULL;
}
void Initmath(Linkmath *&math)  //pmath�ṹ��ĳ�ʼ��
{
	math=(Linkmath *)malloc(sizeof(Linkmath));
	math->next=NULL;
}
void Initenglish(Linkenglish *&english)  //penglish�ṹ��ĳ�ʼ��
{
	english=(Linkenglish *)malloc(sizeof(Linkenglish));
	english->next=NULL;
}


//***********************************��Ҫ�ĺ�������*******************************************//
void readFile(FILE *fp,Linkworker *&p)//���ļ��ж�ȡ���ݵ���������
{
	Linkworker *s;
	if((fp=fopen("zg.txt","r"))==NULL)
	{
		printf("û�з����ļ�\n");
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
void Addworker(Linkworker *&worker)//����ѧ����¼
{
	Linkworker *s,*p=worker;
	printf("******������Ҫ���ӵ�ѧ����¼*******\n");
	printf("ѧ��    ����     �༶      ��ѧ     Ӣ��   ����\n");
    //while(p->next!=NULL)
		//p=p->next;
	s=(Linkworker *)malloc(sizeof(Linkworker));
	cin>>s->no  >>s->name  >>s->depno  >>s->math  >>s->english   >>s->salary;
    p->next=s;
	p=s;
	p->next=NULL;
}

int LocateElem(Linkworker *worker,int no) //����ѧ���������λ��
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

void DeleteWorker(Linkworker *worker,int no)//ɾ��ѧ�����������
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
		printf("�գ�����ɾ��");
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

void updateWorker(Linkworker *worker,int no)  //�޸�����
{
	Linkworker *p=worker->next;
	while(p!=NULL && p->no!=no)
	{
		p=p->next;
	}
	if(p!=NULL)
	{
	   printf("ѧ��:");
		 cin>>p->no;
	   printf("����:");
		 cin>>p->name;
       printf("�༶:");
		cin>>p->depno;
	   printf("��ѧ:");
		cin>>p->math;
	    printf("Ӣ��:");
		cin>>p->english;
		printf("����:");
		cin>>p->salary;

	}
}

void tongjiworker(Linkworker *worker)   //ͳ��
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
	printf("��ѧ��߷� Ӣ����߷� ������߷� ��ѧ���������� Ӣ�ﲻ�������� �������������� ");
    printf("%9d%9d%9d%15d%15d%15d\n",max_math,max_english,max_salary,nopass_math,nopass_english,nopass_salary);

}

void DispWorker(Linkworker *worker)//���ѧ�����������
{
	Linkworker *p=worker->next;
	printf("********����������������:*******\n");
		if(p==NULL)
	{
		printf("<<ְ������Ϊ��:\n");
		return;
	}
	printf("ѧ ��     �� ��       �� ��        �� ѧ     Ӣ ��     �� ��\n");
	while(p!=NULL)
	{
		printf("%d%13s%15s%9d%9d%9d\n",p->no,p->name,p->depno,p->math,p->english,p->salary);
		p=p->next;
	}
}
void sort_pno(Linkworker *worker,Linkno *&dpno)//��no����
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
void Disp_no(Linkworker *worker,Linkno *dpno)//��no�������
{
	Linkno *no=dpno->next;
	Linkworker *p;
	if(no==NULL)
	{
		printf("<<û�а�no�����������������:\n");
	}
	else
	{
        printf("*******��no�������pno�����ȫ��ѧ����¼��:*******\n");
		printf("  ѧ��    ����     �༶     ��ѧ      Ӣ��     ����\n");
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


void clear(FILE *fp)//����ļ�����
{
	if((fp=fopen("zg.txt","w"))=NULL)
	{
		printf("�ı����\n");
		return;
	}
	printf("<<�ļ��Ѿ����\n");
}
void SaveOut(Linkworker *L , FILE *fs)//�����������ݵ��ı���
{
	char tempbuf[30];

	Linkworker *p=L->next;
	while (p!=NULL)
	{
		sprintf(tempbuf,"%d %s %s %d %d  %d\r\n",p->no,p->name,p->depno,p->math,p->english,p->salary);
		fwrite(tempbuf,strlen(tempbuf),1,fs);
		p=p->next;
	}
	printf("<<�˳�����\n");
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
    printf("1.���롣���һ��ѧ����¼��\n"
    "2.��������ȫ��ѧ����¼��\n"
    "3.��ѧ������ͨ��pnoָ�뽫ѧ����¼��ѧ��o��С��������������\n"
    "4.��ѧ���������pno�����ȫ��ѧ����¼��\n"
	"5.ͳ�ơ�ͳ�����п�Ŀ��߷��벻����������\n"
	"6.ɾ������ѧ��ɾ���������м�¼.\n"
	"7.�޸ġ���ѧ���޸ĸ����ļ�¼.\n"
    "9.ȫ�塣ɾ��ѧ���ļ��е�ȫ����¼��\n"
    "0.�����˳�\n");
	while(t1)
	{
		printf("************************************************\n");
		printf("������ѡ��:");
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

				printf("<<�Ѱ�ѧ������\n");
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
               printf("��������Ҫɾ����ѧ��");
				   cin>>no2;
				int loca=LocateElem(w,no2);
				DeleteWorker(w,loca-1);
				break;
			}
		case 7:
			{
				int no2;
               printf("��������Ҫ�޸ĵ�ѧ��");
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
