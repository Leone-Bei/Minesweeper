//主函数

#include "minesweeper.h"

//棋盘一共有两个，分别是雷盘和数字盘。雷盘用来存放地雷，数字盘则用来作为游戏的棋盘界面。雷盘与数字盘一一对应

//初级模式：棋盘大小9*9，10个雷
//中级模式：棋盘大小16*16，40个雷
//高级模式：棋盘大小16*30，99个雷
//创建雷盘

//初级雷盘9*9
int mineboard_lev_easy[9][9];
//中级雷盘16*16
int mineboard_lev_middle[16][16];
//高级雷盘16*30
int mineboard_lev_difficult[16][30];

//创建数字盘

//初级数字盘
char figureboard_lev_easy[9][9];
//中级数字盘
char figureboard_lev_middle[16][16];
//高级数字盘
char figureboard_lev_difficult[16][30];

//定义游戏难度等级
int game_lev=1;

//定义输入坐标
int row_input;
int column_input;

int main()
{
    srand((unsigned int)time(NULL));
    startpage();
    return 0;
}