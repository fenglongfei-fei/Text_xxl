#include <stdio.h>
#include <iostream>
#include <easyx.h>
#include <graphics.h>
#include <time.h>
using namespace std;

#define WIN_WIDTH 474
#define WIN_HEIGHT 899
#define ROWS 8
#define COLS 8
#define BLOCK_TYPE_COUNT 7

IMAGE imgBg;   // 表示图片
IMAGE imgBlock[BLOCK_TYPE_COUNT];

struct block
{
	int type;
	int x;
	int y;
	int row, col;
};

struct block map[ROWS+2][COLS+2];

const int off_x = 20;
const int off_y = 250;
const int block_size = 55;

void  init()
{
	initgraph(WIN_WIDTH, WIN_HEIGHT);
	loadimage(&imgBg,"Photo/xxl.png");

	char name[64];
	for (int i = 0; i < BLOCK_TYPE_COUNT; i++)
	{
		sprintf_s(name, sizeof(name), "Photo/%d.png", i + 1);
		loadimage(&imgBlock[i], name, block_size, block_size, true);
	}

	// 配置随机数
	srand(time(NULL));

	for (int i = 1; i <= ROWS; i++)
	{
		for (int j = 1; j < COLS; j++)
		{
			map[i][j].type = 1+rand() % 4;
			map[i][j].row = i;
			map[i][j].col = j;
			map[i][j].x = off_x + (j - 1) * (block_size + 5);
			map[i][j].y = off_y + (i - 1) * (block_size + 5);
		}
	}
}

void  UpdateWindow()
{
	putimage(0, 0, &imgBg);
	for (int i = 1; i <=ROWS; i++)
	{
		for (int j = 1; j <=COLS; j++)
		{
			if (map[i][j].type)
			{
				IMAGE* img = &imgBlock[map[i][j].type - 1];
				putimage(map[i][j].x, map[i][j].y, img);
			}
		}
	}
}

int main(void)
{
	init();

	UpdateWindow();  // 更新窗口
	system("pause");
	return 0;

}