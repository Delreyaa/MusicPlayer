/************************************
glanceOver.c by 雷雨田
Including three modules:
searchForSong
readAttribute
loadAttribute
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>
#define N 20										//数组最大长度
#define ADDR "D:\\MediaPlayerFile\\SongsList.txt"	//文档名
//#define Debug


//定义存储文件信息的结构体
typedef struct songinfo
{
	char songNum;
	char songName[N];
	char artist[N];
	char album[N];
	char timeLength[N];
}info;



void GlanceOverMenu()
{
	FILE *fp = fopen(ADDR, "r");
	if (fp == 0)
	{
		printf("source file erro!\n");
		exit(1);
	}

	/*读取文件信息到自定义结构体类型的数组*/
	info slist[N];
	int j = 0, songnum = 0;
	fscanf(fp, "%c%s%s%s%s", &slist[j].songNum, slist[j].songName,
		slist[j].artist, slist[j].album, slist[j].timeLength);
	fgetc(fp);
	while (feof(fp) == 0)		//继续读取直到文件结尾
	{
		j++;
		fscanf(fp, "%c%s%s%s%s", &slist[j].songNum, slist[j].songName,
			slist[j].artist, slist[j].album, slist[j].timeLength);
#ifdef Debug
		printf("j:%-5d\n", j);
		printf("songNum:%-5c\n%-25s%-15s%-15s%-10s\n", slist[j].songNum, slist[j].songName,
			slist[j].artist, slist[j].album, slist[j].timeLength);
#endif
		fgetc(fp);
	}
	fclose(fp);
	songnum = j + 1;
#ifdef Debug
	printf("j:%-5d\n", j);
	printf("songNum:%-5d\n", songnum);
#endif
	/*菜单--1-显示所有歌曲信息-2-查找某首歌曲*/
	//获取用户输入
	printf("\n******************GlanceOverMenu****************\n");
	printf("1) show all songs & information\n");
	printf("2) search\n");

	int choice = 0;
	scanf("%d", &choice);
	getchar();
	int i = 0;
	char inputName[N];
	switch (choice)
	{
	/*显示所有歌曲信息*/
	case 1:
		printf("%-5s%-25s%-15s%-15s%-10s\n", "编号", "歌曲名", "歌手", "专辑名", "时长");
		for (i = 0; i < songnum; i++)
		{
			printf("%-5c%-25s%-15s%-15s%-10s\n", slist[i].songNum, slist[i].songName,
				slist[i].artist, slist[i].album, slist[i].timeLength);
#ifdef Debug
			printf("songNum:%-5c,i:%d\n", slist[i].songNum, i);
#endif
		}
		break;
	/*查找某首歌曲*/
	case 2:
		/*获取要查找的歌曲名*/
		i = 0;
		printf("Which song do you want to look for?(end with '$')\n");
		while ((inputName[i++] = getchar()) != '$')
			continue;
		inputName[i - 1] = '\0';
		/*将输入与歌曲名信息比较,相同则输出歌曲所有信息*/
		i = 0;
		while (i < songnum)
		{
			if (0 == strcmp(inputName, slist[i].songName))
			{
				printf("%-5s%-15s%-15s%-15s%-10s\n", "编号", "歌曲名", "歌手", "专辑名", "时长");
				printf("%-5c%-15s%-15s%-15s%-10s\n", slist[i].songNum, slist[i].songName,
					slist[i].artist, slist[i].album, slist[i].timeLength);
				break;
			}
			i++;
		}
		if (i == songnum)
		{
			printf("no such song\n");
		}
		break;
	default:
		printf("erro input!");
	}

	system("pause");
	return;
}
