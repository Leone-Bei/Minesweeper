//涉及棋盘的相关函数

#include "minesweeper.h"

//棋盘设计
//     1   2   3   4   5   6   7   8   9   (C)
//   |---|---|---|---|---|---|---|---|---|
// 1 |   |   |   |   |   |   |   |   |   |
//   |---|---|---|---|---|---|---|---|---|
// 2 |   |   |   |   |   |> <|   |   |   |
//   |---|---|---|---|---|---|---|---|---|
//   |   |   |   |   |   |   |   |   |   |
//   |---|---|---|---|---|---|---|---|---|
//(R)
//

//棋盘行数
//1:初级 2:中级 3:高级
int board_row[3]={r_1,r_2,r_3};

//棋盘列数
//1:初级 2:中级 3:高级
int board_column[3]={c_1,c_2,c_3};

//定义数字盘单元格右侧
char figureboard_lev_easy_right[9][9];
char figureboard_lev_middle_right[16][16];
char figureboard_lev_difficult_right[16][30];

//定义数字盘单元格左侧
char figureboard_lev_easy_left[9][9];
char figureboard_lev_middle_left[16][16];
char figureboard_lev_difficult_left[16][30];


//数字盘初始化
//figureboard_initialization(游戏难度等级：1，2，3)
void figureboard_initialization(int lev)
{
    //定义循环变量
    int a1,b1;

    for(a1=1;a1<=board_row[lev-1];a1++)
    {
        for(b1=1;b1<=board_column[lev-1];b1++)
        {
            switch(lev)
            {
                case 1:
                    figureboard_lev_easy[a1-1][b1-1]=' ';
                    figureboard_lev_easy_left[a1-1][b1-1]=' ';
                    figureboard_lev_easy_right[a1-1][b1-1]=' ';
                    break;
                case 2:
                    figureboard_lev_middle[a1-1][b1-1]=' ';
                    figureboard_lev_middle_left[a1-1][b1-1]=' ';
                    figureboard_lev_middle_right[a1-1][b1-1]=' ';
                    break;
                case 3:
                    figureboard_lev_difficult[a1-1][b1-1]=' ';
                    figureboard_lev_difficult_left[a1-1][b1-1]=' ';
                    figureboard_lev_difficult_right[a1-1][b1-1]=' ';
                    break;
            }
        }
    }
}

//雷盘初始化
//mineboard_initialization(游戏难度等级)
void mineboard_initialization(int lev)
{
    //定义循环变量
    int a1,b1;

    for(a1=1;a1<=board_row[lev-1];a1++)
    {
        for(b1=1;b1<=board_column[lev-1];b1++)
        {
            switch(lev)
            {
                case 1:
                    mineboard_lev_easy[a1-1][b1-1]=0;
                    break;
                case 2:
                    mineboard_lev_middle[a1-1][b1-1]=0;
                    break;
                case 3:
                    mineboard_lev_difficult[a1-1][b1-1]=0;
                    break;
            }
        }
    }
}

//数字盘打印
//figureboard_print(游戏难度等级：1，2，3)
void figureboard_print(int lev)
{
    //定义循环变量
    int a1,b1;

    printf("\t\t   ");
    for(a1=1;a1<=board_column[lev-1]+1;a1++)
    {
        printf(" ");
        if(a1<board_column[lev-1]+1)
        {
            if(a1<10)
            {
                printf("00%d",a1);
            }
            else
            {
                printf("0%d",a1);
            }
        }
    }
    printf(" (C)\n");
    for(a1=1;a1<=board_row[lev-1]+1;a1++)
    {
        printf("\t\t   ");
        for(b1=1;b1<=board_column[lev-1]+1;b1++)
        {
            printf("|");
            if(b1<board_column[lev-1]+1)
            {
                printf("---");
            }
        }
        printf("\n");
        if(a1==board_row[lev-1]+1)
        {
            printf("\t\t(R)\n");
            break;
        }
        if(a1<10)
        {
            printf("\t\t00%d",a1);
        }
        else
        {
            printf("\t\t0%d",a1);
        }
        for(b1=1;b1<=board_column[lev-1]+1;b1++)
        {
            printf("|");
            if(b1<board_column[lev-1]+1)
            {
                switch(lev)
                {
                    case 1:
                        printf("%c%c%c",figureboard_lev_easy_left[a1-1][b1-1],figureboard_lev_easy[a1-1][b1-1],figureboard_lev_easy_right[a1-1][b1-1]);
                        break;
                    case 2:
                        printf("%c%c%c",figureboard_lev_middle_left[a1-1][b1-1],figureboard_lev_middle[a1-1][b1-1],figureboard_lev_middle_right[a1-1][b1-1]);
                        break;
                    case 3:
                        printf("%c%c%c",figureboard_lev_difficult_left[a1-1][b1-1],figureboard_lev_difficult[a1-1][b1-1],figureboard_lev_difficult_right[a1-1][b1-1]);
                        break;
                }
            }
        }
            printf("\n");
    }
}

//地雷显示
//mine_display(游戏难度等级)
void mine_display(int lev)
{
    //定义搜索对象行数和列数
    int r,c;

    //地雷搜索
    for(r=1;r<=board_row[lev-1];r++)
    {
        for(c=1;c<=board_column[lev-1];c++)
        {
            //指针存储           
            switch(lev)
            {
                case 1:
                    if(mineboard_lev_easy[r-1][c-1]==-1)
                    {
                        if(figureboard_lev_easy[r-1][c-1]=='P')
                        {
                            figureboard_lev_easy_left[r-1][c-1]='(';
                            figureboard_lev_easy_right[r-1][c-1]=')';
                        }
                        figureboard_lev_easy[r-1][c-1]='*';
                    }
                    break;
                case 2:
                    if(mineboard_lev_middle[r-1][c-1]==-1)
                    {
                        if(figureboard_lev_middle[r-1][c-1]=='P')
                        {
                            figureboard_lev_middle_left[r-1][c-1]='(';
                            figureboard_lev_middle_right[r-1][c-1]=')';
                        }
                        figureboard_lev_middle[r-1][c-1]='*';
                    }
                    break;
                case 3:
                    if(mineboard_lev_difficult[r-1][c-1]==-1)
                    {
                        if(figureboard_lev_difficult[r-1][c-1]=='P')
                        {
                            figureboard_lev_difficult_left[r-1][c-1]='(';
                            figureboard_lev_difficult_right[r-1][c-1]=')';
                        }
                        figureboard_lev_difficult[r-1][c-1]='*';
                    }                    
                    break;    
            }
        }
    }   
}

//雷盘编辑
//mineboard_edit(游戏难度等级)
void mineboard_edit(int lev)
{
    //定义选中对象
    int target_r;
    int target_c;

    //定义搜索对象
    int search_r;
    int search_c;

    //定义计数器
    int sum;

    //定义雷盘指针转存器
    int *mineboard_pointer_storer_1;
    int *mineboard_pointer_storer_2;

    for(target_r=1;target_r<=board_row[lev-1];target_r++)
    {
        for(target_c=1;target_c<=board_column[lev-1];target_c++)
        {
            //指针转存
            switch(lev)
            {
                case 1:
                    mineboard_pointer_storer_1=&mineboard_lev_easy[target_r-1][target_c-1];
                    break;
                case 2:
                    mineboard_pointer_storer_1=&mineboard_lev_middle[target_r-1][target_c-1];
                    break;
                case 3:
                    mineboard_pointer_storer_1=&mineboard_lev_difficult[target_r-1][target_c-1];
                    break;    
            }

            //判断是否为雷区
            if(*mineboard_pointer_storer_1!=-1)
            {
                //计数器归零
                sum=0;

                for(int k=0;k<=7;k++)
                {
                    //旋转搜索
                    rotation_search(k,target_r,target_c,&search_r,&search_c);

                    //判断当前选中对象坐标合法性
                    if(search_r>0&&search_r<board_row[lev-1]+1)
                    {
                        if(search_c>0&&search_c<board_column[lev-1]+1)
                        {
                            //指针存储
                            switch(lev)
                            {
                                case 1:
                                    mineboard_pointer_storer_2=&mineboard_lev_easy[search_r-1][search_c-1];
                                    break;
                                case 2:
                                    mineboard_pointer_storer_2=&mineboard_lev_middle[search_r-1][search_c-1];
                                    break;
                                case 3:
                                    mineboard_pointer_storer_2=&mineboard_lev_difficult[search_r-1][search_c-1];
                                    break;    
                            }

                            //统计地雷数
                            if(*mineboard_pointer_storer_2==-1)
                            {
                                sum++;
                            }
                        }
                    } 
                }

                //编辑雷盘
                *mineboard_pointer_storer_1=sum;
            }
        }
    }
}

// //数字盘编辑
// void figureboard_edit(int lev)
// {
//     //定义行数和列数
//     int r;
//     int c;

//     //定义指针转存器
//     int *mineboard_pointer_storer;
//     char *figureboard_pointer_storer;

//     for(r=1;r<=board_row[lev-1];r++)
//     {
//         for(c=1;c<=board_column[lev-1];c++)
//         {
//             switch(lev)
//             {
//                 case 1:
//                     mineboard_pointer_storer=&mineboard_lev_easy[r-1][c-1];
//                     figureboard_pointer_storer=&figureboard_lev_easy[r-1][c-1];
//                     break;
//                 case 2:
//                     mineboard_pointer_storer=&mineboard_lev_middle[r-1][c-1];
//                     figureboard_pointer_storer=&figureboard_lev_middle[r-1][c-1];
//                     break;
//                 case 3:
//                     mineboard_pointer_storer=&mineboard_lev_difficult[r-1][c-1];
//                     figureboard_pointer_storer=&figureboard_lev_difficult[r-1][c-1];
//                     break;    
//             }

//             if(*mineboard_pointer_storer==-1)
//             {
//                 *figureboard_pointer_storer='*';
//             }
//             else
//             {
//                 transformation_i_to_c(*mineboard_pointer_storer,figureboard_pointer_storer);
//             }
//         }
//     }
    
// }

// //数字盘调整
// //figureboard_adjustment(游戏难度等级)
// void figureboard_adjustment(int lev)
// {
//     int r;//定义行数
//     int c;//定义列数

//      //定义编辑对象
//     int r_0,c_0;

//     //定义计数器
//     int sum;
//     char c_sum;

//     //定义雷盘和数字盘指针转存器
//     int *mineboard_pointer_storer_1;
//     char *figureboard_pointer_storer;
//     int *mineboard_pointer_storer_2;

//     //地雷搜索
//     for(r=1;r<=board_row[lev-1];r++)
//     {
//         for(c=1;c<=board_column[lev-1];c++)
//         {
//             //指针存储           
//             switch(lev)
//             {
//                 case 1:
//                     mineboard_pointer_storer_1=&mineboard_lev_easy[r-1][c-1];
//                     figureboard_pointer_storer=&figureboard_lev_easy[r-1][c-1];
//                     break;
//                 case 2:
//                     mineboard_pointer_storer_1=&mineboard_lev_middle[r-1][c-1];
//                     figureboard_pointer_storer=&figureboard_lev_middle[r-1][c-1];
//                     break;
//                 case 3:
//                     mineboard_pointer_storer_1=&mineboard_lev_difficult[r-1][c-1];
//                     figureboard_pointer_storer=&figureboard_lev_difficult[r-1][c-1];
//                     break;    
//             }

//             //数字盘编辑
//             if(*mineboard_pointer_storer_1==-1)
//             {
//                 *figureboard_pointer_storer='*';
//             }
//         }
//     }

//     //周边格子编辑
//     for(r=1;r<=board_row[lev-1];r++)
//     {
//         for(c=1;c<=board_column[lev-1];c++)
//         {
//             //指针存储
//             switch(lev)
//             {
//                 case 1:
//                     mineboard_pointer_storer_1=&mineboard_lev_easy[r-1][c-1];
//                     figureboard_pointer_storer=&figureboard_lev_easy[r-1][c-1];
//                     break;
//                 case 2:
//                     mineboard_pointer_storer_1=&mineboard_lev_middle[r-1][c-1];
//                     figureboard_pointer_storer=&figureboard_lev_middle[r-1][c-1];
//                     break;
//                 case 3:
//                     mineboard_pointer_storer_1=&mineboard_lev_difficult[r-1][c-1];
//                     figureboard_pointer_storer=&figureboard_lev_difficult[r-1][c-1];
//                     break;    
//             }

//             //排除地雷
//             if(*mineboard_pointer_storer_1!=-1)
//             {
//                 //计数器归零
//                 sum=0;
//                 for(int j=0;j<=7;j++)
//                 {
//                     //旋转搜索
//                     rotation_search(j,r,c,&r_0,&c_0);

//                     //指针存储
//                     switch(lev)
//                     {
//                         case 1:
//                             mineboard_pointer_storer_2=&mineboard_lev_easy[r_0-1][c_0-1];
//                             break;
//                         case 2:
//                             mineboard_pointer_storer_2=&mineboard_lev_middle[r_0-1][c_0-1];
//                             break;
//                         case 3:
//                             mineboard_pointer_storer_2=&mineboard_lev_difficult[r_0-1][c_0-1];
//                             break;    
//                     }

//                     //判断当前选中对象坐标合法性
//                     if(r_0>0&&r_0<board_row[lev-1]+1)
//                     {
//                         if(c_0>0&&c_0<board_column[lev-1]+1)
//                         {
//                             if(*mineboard_pointer_storer_2==-1)
//                             {
//                                 sum++;
//                             }
//                         }
//                     } 
//                 }

//                 //编辑数字盘
//                 transformation_i_to_c(sum,&c_sum);
//                 *figureboard_pointer_storer=c_sum;
//             }
//         }
//     }
// }

