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

int filling(struct tStudentCard *group);

int main(void)//������� �������
{
	//struct tStudentCard group[number];
	struct tStudentCard group[number] = {
{"Gates","Bill",1,{5,5,5}},
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
	filling(group);
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
	for (i = 0; i <= number; i++)
	{
			group[i].Course = rand()/RAND_MAX;
			group[i].Marks.Math = 5*rand()/RAND_MAX;
			group[i].Marks.Phys = 5*rand()/RAND_MAX;
			group[i].Marks.Inform = 5*rand()/RAND_MAX;
	}
}
