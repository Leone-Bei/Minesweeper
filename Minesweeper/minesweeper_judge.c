//游戏结果判定

#include "minesweeper.h"

//游戏结果判定
//game_judge(游戏难度等级)
void judge(int lev)
{
    //定义游戏结果
    int game_result=0;

    //定义雷盘转存器
    int mineboard_storer;

    //定义数字盘转存器
    char figureboard_storer;

    //定义计数器
    int sum=0;

    for(int r=1;r<=board_row[lev-1];r++)
    {
        for(int c=1;c<=board_column[lev-1];c++)
        {
            switch(lev)
            {
                case 1:
                    mineboard_storer=mineboard_lev_easy[r-1][c-1];
                    figureboard_storer=figureboard_lev_easy[r-1][c-1];
                    break;
                case 2:
                    mineboard_storer=mineboard_lev_middle[r-1][c-1];
                    figureboard_storer=figureboard_lev_middle[r-1][c-1];
                    break;
                case 3:
                    mineboard_storer=mineboard_lev_difficult[r-1][c-1];
                    figureboard_storer=figureboard_lev_difficult[r-1][c-1];
                    break;
            }

            //如果发现开到地雷了，判定游戏结果为输
            if(figureboard_storer=='*')
            {
                game_result=2;

                //同时结束循环
                break;
            }
            else
            {
                //检测为安全区
                if(mineboard_storer>=0)
                {
                    //检测到未探索或已标记
                    if(figureboard_storer==' '||figureboard_storer=='P')
                    {
                        sum++;
                    }
                }
            }

            if(game_result==2)
            {
                break;
            }
        } 
    }

    //若所有的安全区都已探索，判定游戏结果为赢
    if(sum==0)
    {
        game_result=1;
    }

    if(game_result==1)
    {
        system("clear");

        //地雷显示
        mine_display(lev);

        //游戏标题
        game_title();
        printf("\n");

        //数字盘打印
        figureboard_print(1);
        printf("\n");

        printf("\t\t-Game Result-\n");
        printf("\n");
        printf("\t\tVictory\n");
        printf("\n");
        printf("\t\tCongratulation! You have detected all the mines. Good job!\n");
        printf("\t\t      |-------|\n");
        printf("\t\tPress | Enter | to go to the menu page.\n");
        printf("\t\t      |-------|\n");                   
        printf("\t\t                                        ");
        if(getchar()=='\n')
        {
            if(getchar()=='\n')
            {
                menu();
            }
        }
    }
    else if(game_result==2)
    {
        system("clear");

        //游戏标题
        game_title();
        printf("\n");

        //数字盘打印
        figureboard_print(lev);
        printf("\n");

        printf("\t\t-Game Result-\n");
        printf("\n");
        printf("\t\tDefeat\n");
        printf("\n");
        printf("\t\tWhat a pity! You still have chances. Keep trying!\n");
        printf("\t\t      |-------|\n");
        printf("\t\tPress | Enter | to go to the menu page.\n");
        printf("\t\t      |-------|\n");                   
        printf("\t\t                                        ");
        if(getchar()=='\n')
        {
            if(getchar()=='\n')
            {
                menu();
            }
        }
    }
    else if(game_result==0)
    {
        //判定游戏未结束,则继续游戏
        player_input(lev);
    }
}