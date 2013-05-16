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

int filling(struct tStudentCard *group);//прототипы функций
int output(struct tStudentCard *group);
int search(struct tStudentCard *group);

int main(void)//главная функция
{
	struct tStudentCard group[number] = {
{"Gates","Bill",1,{5,5,5}},//задание имён и фамилий
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
	filling(group);//заполнение остального
	output(group);//вывод списка
	search(group);//поиск лучшего с первого курса
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
	for (i = 0; i < number; i++)//случайное задание курса и оценок
	{
			group[i].Course = 1+4*rand()/RAND_MAX;
			group[i].Marks.Math = 2+3*rand()/RAND_MAX;
			group[i].Marks.Phys = 2+3*rand()/RAND_MAX;
			group[i].Marks.Inform = 2+3*rand()/RAND_MAX;
	}
}

int output(struct tStudentCard *group)//вывод
{
	int i;
	printf("   Surname  |    Name    |   Course   | Mathematics|   Physics  |Informatics |\n");//заголовок
	for (i = 0; i < number; i++)//вывод списка студентов
	{
		printf(" %-10s |",group[i].SurName);
		printf(" %-10s |",group[i].Name);
		printf(" %-10d |",group[i].Course);
		printf(" %-10d |",group[i].Marks.Math);
		printf(" %-10d |",group[i].Marks.Phys);
		printf(" %-10d |",group[i].Marks.Inform);
		printf("\n");//переход на следущую строчку
	}
}

int search(struct tStudentCard *group)//поиск строк с максимальной суммой элементов в них
{
	int sum,maxsum,i,j;
	maxsum=0;//начальное значение максимальной суммы оценок
	for (i = 0; i < number; i++)//определение максимального значения
	{
		if (group[i].Course==1)
		{

		sum=group[i].Marks.Math+group[i].Marks.Phys+group[i].Marks.Inform;
		if (sum>maxsum)//сравнение с максимальной суммой
		{
			maxsum=sum;//изменение максимальной суммы если она меньше новой
		}
		}
	}
	printf("\nBest students from 1st course:\n");//вывод заголовка
	for (i = 0; i < number; i++)//вывод номеров строк с максимальными суммами
	{
		if (group[i].Course==1)
		{

		sum=0;//обнуление суммы
		 sum=group[i].Marks.Math+group[i].Marks.Phys+group[i].Marks.Inform;
		if (sum==maxsum)//проверка равенства максимальной суммы и текущей
		{
			printf("%s %s\n",group[i].SurName,group[i].Name);//вывод номера строки
		}
		}
	}
}

