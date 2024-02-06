//布雷

#include "minesweeper.h"

//定义地雷数，带游戏等级
//1:初级 2:中级 3:高级
int mine[3]={m_1,m_2,m_3};

//地雷随机设置
//mineset(游戏难度等级)
void mineset(int lev)
{
    int r;//定义行
    int c;//定义列

    //定义雷盘指针转存器
    int *mineboard_pointer_storer;

    for(int i=1;i<=mine[lev-1];i++)
    {
        srand((unsigned int)time(NULL));
        while(1)
        {
            r=rand()%board_row[lev-1]+1;
            c=rand()%board_column[lev-1]+1;

            //指针存储
            switch(lev)
            {
                case 1:
                    mineboard_pointer_storer=&mineboard_lev_easy[r-1][c-1];
                    break;
                case 2:
                    mineboard_pointer_storer=&mineboard_lev_middle[r-1][c-1];
                    break;
                case 3:
                    mineboard_pointer_storer=&mineboard_lev_difficult[r-1][c-1];
                    break;    
            }

            //布雷
            if(*mineboard_pointer_storer!=-1)
            {
                *mineboard_pointer_storer=-1;
                break;
            }
        }
        
    }
}

