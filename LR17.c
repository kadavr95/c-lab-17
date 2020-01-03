//������������ ������ 17. ������� 1. ������� ������� (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//����������� ���������
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define number 10
struct tMarks { /* ��������� ������ */
int Math; /* ������ �� ���������� */
int Phys; /* ������ �� ������ */
int Inform; /* ������ �� ����������� */
};

struct tStudentCard {
char SurName[20]; /* ������� */
char Name[20]; /* ��� */
int Course; /* ���� */
struct tMarks Marks; /* ������ */
};

int filling(struct tStudentCard *group);//��������� �������
int output(struct tStudentCard *group);
int search(struct tStudentCard *group);

int main(void)//������� �������
{
	struct tStudentCard group[number] = {
{"Gates","Bill",1,{5,5,5}},//������� ��� � �������
{"Jobs","Steve",1,{5,5,5}},
{"Brin","Sergy",1,{5,5,5}},
{"Page","Larry",1,{5,5,5}},
{"Voznyak","Steve",1,{5,5,5}},
{"Zuckerberg","Mark",1,{5,5,5}},
{"Torvalds","Linux",1,{5,5,5}},
{"Yang","Jerry",1,{5,5,5}},
{"Ellison","Lawrence",1,{5,5,5}},
{"Einstein","Albert",1,{5,5,5}},
};
	filling(group);//���������� ����������
	output(group);//����� ������
	search(group);//����� ������� � ������� �����
	fflush(stdin);//�������� �������� ������������
	getchar();
	return 0;
}

int filling(struct tStudentCard *group)
{
    int i;//����������� ����������
	int stime;
	long int ltime;
	ltime=time(NULL);//�������� ��������� ������������������
	stime=(unsigned) ltime/2;
	srand(stime);
	for (i = 0; i < number; i++)//��������� ������� ����� � ������
	{
			group[i].Course = 1+4*rand()/RAND_MAX;
			group[i].Marks.Math = 2+3*rand()/RAND_MAX;
			group[i].Marks.Phys = 2+3*rand()/RAND_MAX;
			group[i].Marks.Inform = 2+3*rand()/RAND_MAX;
	}
}

int output(struct tStudentCard *group)//�����
{
	int i;
	printf("   Surname  |    Name    |   Course   | Mathematics|   Physics  |Informatics |\n");//���������
	for (i = 0; i < number; i++)//����� ������ ���������
	{
		printf(" %-10s |",group[i].SurName);
		printf(" %-10s |",group[i].Name);
		printf(" %-10d |",group[i].Course);
		printf(" %-10d |",group[i].Marks.Math);
		printf(" %-10d |",group[i].Marks.Phys);
		printf(" %-10d |",group[i].Marks.Inform);
		printf("\n");//������� �� �������� �������
	}
}

int search(struct tStudentCard *group)//����� ����� � ������������ ������ ��������� � ���
{
	int sum,maxsum,i,j;
	maxsum=0;//��������� �������� ������������ ����� ������
	for (i = 0; i < number; i++)//����������� ������������� ��������
	{
		if (group[i].Course==1)
		{

		sum=group[i].Marks.Math+group[i].Marks.Phys+group[i].Marks.Inform;
		if (sum>maxsum)//��������� � ������������ ������
		{
			maxsum=sum;//��������� ������������ ����� ���� ��� ������ �����
		}
		}
	}
	printf("\nBest students from 1st course:\n");//����� ���������
	for (i = 0; i < number; i++)//����� ������� ����� � ������������� �������
	{
		if (group[i].Course==1)
		{

		sum=0;//��������� �����
		 sum=group[i].Marks.Math+group[i].Marks.Phys+group[i].Marks.Inform;
		if (sum==maxsum)//�������� ��������� ������������ ����� � �������
		{
			printf("%s %s\n",group[i].SurName,group[i].Name);//����� ������ ������
		}
		}
	}
}

