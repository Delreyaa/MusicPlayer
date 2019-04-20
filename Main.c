#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>

#include "Menu.h"
#include "glanceOver.h"
#include "playControl.h"


//#define Debug

 int main(void)
{
	switch (MainMenu())
	{
		/***********ArrangePlayListMenu******************/
	case 1:
		switch (ArrangePlayListMenu())
		{
		case 1:
			GlanceOverMenu();
			break;
		case 2:
			switch (OperatePlayListMenu())
			{
			case 1://create a list
				/////////////////////////////////
				break;
			case 2://edit a list
				/////////////////////////////////
				break;
			case 3://delete a list
				/////////////////////////////////
				break;
			case 4://show all lists
				/////////////////////////////////
				break;
			case 5://search for a list
				/////////////////////////////////
				break;
			}break;
		}break;
		//end ArrangePlayListMenu

	/***************PlayMscMenu******************/
	case 2:
		switch (PlayMscMenu())
		{
		case 1:
			PlayControl();
		case 2:
			switch (SoundControlMenu())
			{
			case 1://volume up
				/////////////////////////////////
				break;
			case 2://volume down
				/////////////////////////////////
				break;
			}break;
		}break;
		//end PlayMscMenu
	}
	//end MainMen

	system("pause");
	return 0;
	}


	