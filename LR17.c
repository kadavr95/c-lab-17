//Лабораторная работа 17. Вариант 1. Яскович Дмитрий (T02-01c). Dimini Inc. (c)2013
#include <stdio.h>//подключение библиотек
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define number 10
struct tMarks { /* структура оценки */
int Math; /* оценка по Математике */
int Phys; /* оценка по Физике */
int Inform; /* оценка по Информатике */
};

struct tStudentCard {
char SurName[20]; /* фамилия */
char Name[20]; /* имя */
int Course; /* курс */
struct tMarks Marks; /* оценки */
};

int filling(struct tStudentCard *group);

int main(void)//главная функция
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
	fflush(stdin);//ожидание действий пользователя
	getchar();
	return 0;
}

int filling(struct tStudentCard *group)
{
    int i;//определение переменных
	int stime;
	long int ltime;
	ltime=time(NULL);//создание случайной последовательности
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
