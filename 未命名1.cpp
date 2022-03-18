#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define f 9
#define j 11

char map[f][j+1] = 
{
	{"*#*********"},
	{"***###*###*"},
	{"###**#****#"},
	{"*#**###**#*"},
	{"***********"},
	{"#####*##*##"},
	{"**#*****#*E"},
	{"***#*###**#"},
	{"*#*********"}
};

void print_map()
{
	for(int i=0;i<f;i++)		
	puts(map[i]);
}


void show_cursur(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	printf("curX=%d,curY=%d\n",x,y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
};

int curX,curY;

int main()
{
	while(1)
	{
	
	
		print_map();
		show_cursur(curX,curY);
		char t=getch();
			system("cls");
		if(t=='w')
		{
			if((curY-1)>=0 && (map[curY-1][curX]=='*'||map[curY-1][curX]=='E')) curY--;
		}
			
		else if(t=='s')
		{
			if((curY+1)<f && (map[curY+1][curX]=='*'||map[curY+1][curX]=='E'))curY++;
		}
		
		else if(t=='a')
		{
			if((curX-1)>=0 &&(map[curY][curX-1]=='*'||map[curY][curX-1]=='E')) curX--;
		}
		
		else if(t=='d')
		{
			if((curX+1)<j&& (map[curY][curX+1]=='*'||map[curY][curX+1]=='E')) curX++;
		}
	
	if(map[curY][curX]=='E')break;
	}
	printf("恭喜你！，成功获救了\n");
	return 0;
	
}
