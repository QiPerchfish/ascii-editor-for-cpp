#include <conio.h>
#include <windows.h>
#include <iostream>
#include <cstdio>
#include <cstring>

#define KEY_ENTER 13
#define KEY_UP 65
#define KEY_DOWN 66
#define MAX_ITEMS 20

using namespace std;

int main()
{
	const char* items[MAX_ITEMS]
	{
		"/BIN",
		"/HOME",
		"/ROOT",
		"/ETC",
		"/USR",
		"/OPT",
	};
	int selected = 0;
	int itemCount = 6;
	char input;
	bool running = true;
	
	while(running)
	{
		system("cls");
		cout<<"+-------------------------------------+"<<endl;
		cout<<"|             FILE MANAGER            |"<<endl;
		cout<<"+________________________(v 1.0 Beta)_+"<<endl;
		for(int i=0;i<itemCount;i++)//ÏÔÊ¾²Ëµ¥À¸ 
		{
			cout<<"|";
			if(i == selected)
			{
				cout<<" > ";
			}
			else
			{
				cout<<"   ";
			}
			cout<<items[i];
			int spaces = 15 - strlen(items[i]);
			for(int j=0;j < spaces;j++)
			{
				cout<<"  ";
			}
			
			cout<<"|"<<endl;
		}
		cout<<"|=====================================|"<<endl;
		cout<<"| Enter:chose w/s move q:quit         |"<<endl;
		
		input = _getch();
		
		if(input == -32 || input == 224)
		{
			input = _getch();
			switch(input)
			{
				case KEY_UP:
					selected--;
					
					break;
				case KEY_DOWN:
					selected++;
					
					break;
			}
			if(selected < 0)
			{
				selected = itemCount - 1;
			}
			if(selected >= itemCount)
			{
				selected = 0;
			}
		}
		else
		{
			switch(input)
			{
				case 'W':
				case 'w':
					selected--;
					if(selected < 0)
					{
						selected = itemCount - 1;
					}
					break;
				case 'S':
			    case 's':
					selected++;
					if(selected >= itemCount)
					{
						selected = 0;
					}
					break;
				case KEY_ENTER:
					cout<<"\n You chose:"<<items[selected]<<endl;
					cout<<"Press any key to countine";
					_getch();
					break;
				case 'q':
				case 'Q':
					cout<<"\n Shutdowning..."<<endl;
					running = false;
					break;
				default:
					break;
			}
		}
	}
	cout<<"\n Excution finished"<<endl;
	system("pause");
	return 0;
}

