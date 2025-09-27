#include <stdio.h>
#include <iostream>
#include <easyx.h>
#include <graphics.h>
using namespace std;

#define WIN_WIDTH 485
#define WIN_HEIGHT 917
#define ROWS 8
#define COLS 8
IMAGE imgBg;   // 表示图片

struct block
{
	int type;
	int x, y;
	int row, col;
};

struct block map[ROWS][COLS];


void static init()
{
	initgraph(WIN_WIDTH, WIN_HEIGHT);
	loadimage(&imgBg,"Photo/xxl.png");
}

void static UpdateWindow()
{
	putimage(0, 0, &imgBg);
}

int main(void)
{
	init();

	UpdateWindow();  // 更新窗口
	system("pause");
	return 0;

}