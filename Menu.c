#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Menu.h"

int OperatePlayListMenu(void)
{
	printf("1) create a list\n");
	printf("2) edit a list\n");
	printf("3) delete a list\n");
	printf("4) show all lists\n");
	printf("5) search for a list\n");
	int choice=0;
	scanf("%d",&choice);
	return choice;
}
int PlayControlMenu(void)
{
	printf("1) choose a song\n");
	printf("2) play\n");
	printf("3) suspend\n");
	printf("4) stop\n");
	printf("5) last\n");
	printf("6) next\n");
	printf("7) adjust process\n");
	int choice=0;
	scanf("%d",&choice);
	return choice;
}
int SoundControlMenu(void)
{
	printf("1) volume up\n");
	printf("2) volume down\n");
	int choice=0;
	scanf("%d",&choice);
	return choice;
}

int ArrangePlayListMenu(void)
{
	printf("1) glance over\n");
	printf("2) operate play lists\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

int PlayMscMenu(void)
{
	printf("1) play control\n");
	printf("2) sound control\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

int MainMenu(void)
{
	printf("1) arrange play list menu\n");
	printf("2) play music\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}