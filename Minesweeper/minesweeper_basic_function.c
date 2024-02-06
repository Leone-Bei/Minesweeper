//涉及到的一些必要运算

#include "minesweeper.h"

//45度旋转搜索函数
//(角度，原点行数，原点列数，终点行数，终点列数)
void rotation_search(int n,int r0,int c0,int *r,int *c)
{
    int delta_r=(int)round(pow(2,0.5)*cos(Pi*(0.25*n)));
    int delta_c=(int)round(pow(2,0.5)*sin(Pi*(0.25*n)));
    *r=r0+delta_r;
    *c=c0+delta_c;
}

//数字与字符转换
void transformation_i_to_c(int i,char *c)
{
    switch(i)
    {
        case 0:
            *c='0';
            break;
        case 1:
            *c='1';
            break;
        case 2:
            *c='2';
            break;
        case 3:
            *c='3';
            break;
        case 4:
            *c='4';
            break;
        case 5:
            *c='5';
            break;
        case 6:
            *c='6';
            break;
        case 7:
            *c='7';
            break;
        case 8:
            *c='8';
            break;
        case 9:
            *c='9';
            break;
    }
}

//绝对安全区深度搜索
//(游戏难度等级，目标行数，目标列数)
void no_mine_area_search(int lev,int target_r,int target_c)
{
    //定义循环变量
    int i;

    //定义搜索对象
    int search_r;
    int search_c;

    //定义雷盘指针存储器
    int *mineboard_pointer_storer;

    //定义数字盘指针存储器
    char *figureboard_pointer_storer;

    for(i=0;i<=7;i++)
    {
        //旋转搜索
        rotation_search(i,target_r,target_c,&search_r,&search_c);

        //判断选中目标行数合法性
        if(search_r>0&&search_r<board_row[lev-1]+1)
        {
            //判断选中目标列数合法性
            if(search_c>0&&search_c<board_column[lev-1]+1)
            {
                //指针存储
                switch(lev)
                {
                    case 1:
                        mineboard_pointer_storer=&mineboard_lev_easy[search_r-1][search_c-1];
                        figureboard_pointer_storer=&figureboard_lev_easy[search_r-1][search_c-1];
                        break;
                    case 2:
                        mineboard_pointer_storer=&mineboard_lev_middle[search_r-1][search_c-1];
                        figureboard_pointer_storer=&figureboard_lev_middle[search_r-1][search_c-1];
                        break;
                    case 3:
                        mineboard_pointer_storer=&mineboard_lev_difficult[search_r-1][search_c-1];
                        figureboard_pointer_storer=&figureboard_lev_difficult[search_r-1][search_c-1];
                        break;    
                }

                //判断是否为雷区
                if(*mineboard_pointer_storer!=-1)
                {
                    //判断是否为绝对安全区
                    if(*mineboard_pointer_storer==0)
                    {
                        //判断以选中的绝对安全区是否已被标记
                        if(*figureboard_pointer_storer!='0')
                        {
                            //printf("(%d,%d)\n",search_r,search_c);
                            //标记当前选中区域
                            *figureboard_pointer_storer='0';
                            no_mine_area_search(lev,search_r,search_c);
                        }
                    }
                    else
                    {
                        //编辑数字盘
                        transformation_i_to_c(*mineboard_pointer_storer,figureboard_pointer_storer);
                    }
                }
            }
        }
    }
}

