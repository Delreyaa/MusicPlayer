#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"winmm.lib")
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <mmsystem.h>
#define N 20
#define Debug

/***************************************************************************************/
void play(const char *name)          //播放音乐,传入参数为歌曲名
{
	char cmd[MAX_PATH] = { 0 };			//用于存放命令
	char pathname[MAX_PATH] = { 0 };	//用于存放音乐文件的完整路径

	/*加路径*/
	wsprintf(pathname, "D:\\MediaPlayerFile\\%s.wav", name);
	/*GetShortPathName获取指定路径的短路径形式，要求被转换的歌名必须能在指定目录下找到文件，否则转换失败。*/
	// 第一个参数：源文件路径，第二个参数：文件路径的短形式，第三个参数：目的数组长度。
	GetShortPathName(pathname, pathname, MAX_PATH);//滤掉文件路径的空格

#ifdef Debug
	puts(pathname);
#endif

	/*定义发往MCI的命令，cmd指定命令存储的数组，后面参数跟printf()相同*/
	wsprintf(cmd, "open %s", pathname);		//写入命令：打开文件
	/*发送命令*/
	// 第一个参数：存储命令的数组首地址，第二个参数：接受MCI返回的信息，第三个参数：接受数组的长度，第四个参数：回调窗口的句柄，一般为NULL
	mciSendString(cmd, "", 0, NULL);
	wsprintf(cmd, "play %s", pathname);		//写入命令：播放文件

#ifdef Debug
	puts(cmd);
#endif

	mciSendString(cmd, "", 0, NULL);

	return;
}

/***************************************************************************************/
void pause(const char *name)        // 暂停
{
	char cmd[MAX_PATH] = { 0 };
	char pathname[MAX_PATH] = { 0 };

	// 加路径
	wsprintf(pathname, "D:\\MediaPlayerFile\\%s.wav", name);
	// GetShortPathName用来转换短名，要求被转换的歌名必须能在指定目录下找到文件，否则转换失败。
	// 第一个参数：源文件名，第二个参数：目的文件名，第三个参数：目的数组长度。
	GetShortPathName(pathname, pathname, MAX_PATH);

	wsprintf(cmd, "pause %s", pathname);
	mciSendString(cmd, "", 0, NULL);

#ifdef Debug
	puts(cmd);
#endif
}




/***************************************************************************************/
void PlayControl(void)
{
	getchar();		//滤去缓冲区的换行符
	/*获取用户输入的歌曲名（不含后缀）*/
	printf("please enter a song's name(end with '$')\n");
	char songname[N] = { 0 };
	int i = 0;
	while ((songname[i++] = getchar()) != '$')
		continue;
	getchar();
	songname[i - 1] = '\0';

	play(songname);



	do {
		printf("1) pause\n");
		printf("2) continue\n");
		printf("3) stop\n");

		char ch = getchar();
		getchar();
#ifdef Debug
		putchar(ch);
		putchar('\n');
#endi`
		switch (ch)
		{
		case '1':
			puts("case 1: pause\n");
			pause(songname);
			break;
		case '2':
			puts("case 2: continue\n");
			play(songname);
			break;
		case '3':
			puts("case 3: stop\n");
		default:
			puts("error!");
		}
	} while (1);
	
}

