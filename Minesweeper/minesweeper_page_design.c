//游戏界面设计

#include "minesweeper.h"

//游戏初始界面设计

// 
//     |---|---|---|---|---|---|---|---|---|---|---|
//     | M | I | N | E | S | W | E | E | P | E | R |
//     |---|---|---|---|---|---|---|---|---|---|---|
//
//
//
//
//         |-------|                    
//   Press | Enter | on the keyboard and start the game.     
//         |-------|       
//                                                   



//初始界面
void startpage()
{
    system("cls");

    //打印游戏界面
    printf("\n");
    printf("\t\t|---|---|---|---|---|---|---|---|---|---|---|\n");
    printf("\t\t| M | I | N | E | S | W | E | E | P | E | R |\n");
    printf("\t\t|---|---|---|---|---|---|---|---|---|---|---|\n");
    printf("\t\t\n\n\n\n");
    printf("\t\t      |-------|\n");
    printf("\t\tPress | Enter | on the keyboard and start the game.\n");
    printf("\t\t      |-------|\n");                               
    printf("\t\t                                                   ");
    //进入游戏菜单
    while(1)
    {
        if(getchar()=='\n')
        {
            break;
        }
    }
    menu();
}

//玩家输入选项不合法报错界面设计
//
// |---|---|---|---|---|
// | E | R | R | O | R |
// |---|---|---|---|---|
//
// Error: The choice you have input is invalid.
//
// You should input the serial number of the alternative. Press
//     |-------|
// the | Enter | to exit.
//     |-------|
// 

//玩家输入选项不合法报错界面
void player_wrong_choice_input()
{
    system("cls");
    printf("\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\t\t| E | R | R | O | R |\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\n");
    printf("\t\tError: The choice you have input is invalid.\n");
    printf("\n");
    printf("\t\tYou should input the serial number of the alternative. Press\n");
    printf("\t\t    |-------|\n");
    printf("\t\tthe | Enter | to exit.\n");
    printf("\t\t    |-------|\n");
    printf("\t\t");
}

//游戏菜单界面设计

//   |---|---|---|---|
//   | M | E | N | U |
//   |---|---|---|---|
//
//   1. New Game
//   2. Game Level
//   3. Game record
//
//   
//
//   Input the number of the choice you want, and 
//
//         |-------|
//   press | Enter | after you have decided.
//         |-------|
//
//
//   Your choice: 
//

//游戏菜单界面
void menu()
{
    //定义游戏菜单选项
    int menu_choice;

    system("cls");

    //打印菜单界面
    printf("\n");
    printf("\t\t|---|---|---|---|\n");
    printf("\t\t| M | E | N | U |\n");
    printf("\t\t|---|---|---|---|\n");
    printf("\t\t\n");
    printf("\t\t1. New Game\n");
    printf("\t\t2. Game Level\n");
    printf("\t\t3. Game record\n");
    printf("\t\t4. Exit");
    printf("\t\t\n\n\n");
    printf("\t\tInput the number of the choice you want, and\n");
    printf("\t\t\n");
    printf("\t\t      |-------|\n");
    printf("\t\tpress | Enter | after you have decided.\n");
    printf("\t\t      |-------|\n");
    printf("\t\t\n\n");
    printf("\t\tYour choice: ");
    scanf("%d",&menu_choice);

    //进入新游戏
    switch (menu_choice)
    {
        case 1:
            game_process();
            break;
        case 2:
            level();
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            player_wrong_choice_input();
            if(getchar()=='\n')
            {
                if(getchar()=='\n')
                {
                    menu();
                }
            }
    }
}

//玩家游戏标题界面设计
//
//  |---|---|---|---|---|---|---|---|---|    
//  | Y | O | U | R |   | G | A | M | E |       -The Residual Mark: 004-
//  |---|---|---|---|---|---|---|---|---|

//玩家游戏标题界面
void game_title()
{
    //定义剩余标记数
    int r_m=residual_mark(game_lev);

    printf("\n");
    printf("\t\t|---|---|---|---|---|---|---|---|---|\n");
    printf("\t\t| Y | O | U | R |   | G | A | M | E |\t\t-The Residual Mark: ");
    if(r_m<10)
    {
        printf("00%d-\n",r_m);
    }
    else
    {
        printf("0%d-\n",r_m);
    }
    printf("\t\t|---|---|---|---|---|---|---|---|---|\n");
}

//  游戏难度选择界面设计
//
//  |---|---|---|---|---|
//  | L | E | V | E | L |
//  |---|---|---|---|---|
//
//  There are three different levels to choose.
//      1. Easy
//          9*9 board, 10 mines
//      2. Middle
//          16*16 board, 40 mines
//      3. Difficult
//          16*30 board, 99 mines
//
//  Your choice: 

//游戏难度选择界面
void level()
{
    system("cls");

    //定义游戏难度等级选项
    int level_choice;

    printf("\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\t\t| L | E | V | E | L |\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\n");
    printf("\t\tThere are three different levels to choose.\n");
    printf("\t\t\t1. Easy\n");
    printf("\t\t\t\t9*9 board, 10 mines\n");
    printf("\t\t\t2. Middle\n");
    printf("\t\t\t\t16*16 board, 40 mines\n");
    printf("\t\t\t3. Difficult\n");
    printf("\t\t\t\t16*30 board, 99 mines\n");
    printf("\n");
    printf("\t\tYour choice: ");
    scanf("%d",&level_choice);

    switch(level_choice)
    {
        case 1:
            game_lev=1;
            break;
        case 2:
            game_lev=2;
            break;
        case 3:
            game_lev=3;
            break;
        default:
            player_wrong_choice_input();

            if(getchar()=='\n')
            {
                if(getchar()=='\n')
                {
                    level();
                }
            }
    }

    menu();
}

//  玩家坐标格式输入错误报错界面设计
//
//  |---|---|---|---|---|
//  | E | R | R | O | R |
//  |---|---|---|---|---|
//
//  Error: The format of the coordinate you input is wrong.
//
//  You should input the coordinate on the board in right format,
//  which means you should input three figures on the terminal.
//  For example: 003, 012, 004
//
//        |-------|
//  Press | Enter | to exit and input a legal coordinate. 
//        |-------|
//                                                       

//玩家坐标格式输入错误报错界面
void player_coordinate_wrong_format_warning()
{
    system("cls");
    printf("\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\t\t| E | R | R | O | R |\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\n");
    printf("\t\tError: The format of the coordinate is wrong.\n");
    printf("\n");
    printf("\t\tYou should input the coordinate on the board in right format,\n");
    printf("\t\twhich means you should input three figures on the terminal.\n");
    printf("\t\tFor example: 003, 012, 004\n");
    printf("\n");
    printf("\t\t      |-------|\n");
    printf("\t\tPress | Enter | and input the coordinate again.\n");
    printf("\t\t      |-------|\n");
    printf("\t\t                                                ");
    if(getchar()=='\n')
    {
        if(getchar()=='\n')
        {
            system("clear");
        }
    }
}

//  玩家输入坐标不存在报错界面设计
//
//  |---|---|---|---|---|
//  | E | R | R | O | R |
//  |---|---|---|---|---|
//
//  Error: The coordinate you input doesn't exist.
//
//  You should input the numbers which are listed on the sides of the board.
//
//        |-------|
//  Press | Enter | to exit and input a legal coordinate. 
//        |-------|
//

//玩家输入坐标不存在报错界面
void player_coordinate_not_exist_warning()
{
    system("cls");
    printf("\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\t\t| E | R | R | O | R |\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\n");
    printf("\t\tError: The coordinate you input doesn't exist.\n");
    printf("\n");
    printf("\t\tYou should input the numbers which are listed on the sides of the board.\n");
    printf("\t\t      |-------|\n");
    printf("\t\tPress | Enter | to exit and input a legal coordinate.\n");
    printf("\t\t      |-------|\n");
    printf("\t\t                                                     ");
    if(getchar()=='\n')
    {
        if(getchar()=='\n')
        {
            system("cls");
        }
    }
}

//选中区域未被标记报错界面设计
//
//  |---|---|---|---|---|
//  | E | R | R | O | R |
//  |---|---|---|---|---|
//
//  Error: The operation is invalid.
//
//  The operation "delete mark" can only be carried out when the area is
//  marked by P . So please choose an area which has been marked or choose
//  other operation.
//
//        |-------|
//  Press | Enter | and exit.
//        |-------|
//

//选中区域未被标记报错界面
//area_not_marked_warning(游戏难度等级，选中目标行数，选中目标列数)
void area_not_marked_warning(int lev,int target_r,int target_c)
{
    system("cls");

    printf("\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\t\t| E | R | R | O | R |\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\n");
    printf("\t\tError: The operation is invalid.\n");
    printf("\n");
    printf("\t\tThe operation DELETE MARK can only be carried out when the area is\n");
    printf("\t\tmarked by P . So please choose an area which has been marked or choose\n");
    printf("\t\tother operation.\n");
    printf("\n");
    printf("\t\t      |-------|\n");
    printf("\t\tPress | Enter | and exit.\n");
    printf("\t\t      |-------|\n");
    printf("\t\t                         ");
    if(getchar()=='\n')
    {
        if(getchar()=='\n')
        {
            player_operation_choose(lev,target_r,target_c);
        }
    }
}

//  坐标被占用报错界面设计
//
//  |---|---|---|---|---|
//  | E | R | R | O | R |
//  |---|---|---|---|---|
//
//  Error: This area has been occupied.
//
//  If you want to explore an area, it should not be explored or marked. Press
//  |-------|
//  | Enter | to exit and input a valid coordinate.
//  |-------|
//  

//坐标被占用报错界面
void area_occupied_warning()
{
    system("cls");

    printf("\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\t\t| E | R | R | O | R |\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\n");
    printf("\t\tError: This area has been occupied.\n");
    printf("\n");
    printf("\t\tIf you want to explore an area, it should not be explored or marked. Press\n");
    printf("\t\t|-------|\n");
    printf("\t\t| Enter | to exit and input a new coordinate which has not been explored or marked.\n");
    printf("\t\t|-------|\n");
    printf("\t\t");
}

//  剩余标记耗尽报错界面设计
//
//  |---|---|---|---|---|
//  | E | R | R | O | R |
//  |---|---|---|---|---|
//
//  Error: There is no available mark left.
//
//  The number of the available mark is limited. For example, you can only
//  mark ten places in easy mode. You can delete some mark on the board so 
//  that you can mark a new place.
//
//        |-------|
//  Press | Enter | to exit.
//        |-------|
//  

//剩余标记耗尽报错界面
void residual_mark_run_out_warning()
{
    system("cls");

    printf("\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\t\t| E | R | R | O | R |\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\n");
    printf("\t\tError: There is no available mark left.\n");
    printf("\n");
    printf("\t\tThe number of the available mark is limited. For example, you can only\n");
    printf("\t\tmark ten places in easy mode. You can delete some mark on the board so\n");
    printf("\t\tthat you can mark a new place.\n");
    printf("\n");
    printf("\t\t      |-------|\n");
    printf("\t\tPress | Enter | to exit.\n");
    printf("\t\t      |-------|\n");
    printf("\t\t");
}

//  多次标记报错界面设计
//
//  |---|---|---|---|---|
//  | E | R | R | O | R |
//  |---|---|---|---|---|
//
//  Error: Mutiple mark is invalid.
//
//  This area has been marked. You can not mark a place again since it has been marked.
//  So, you can choose a new area which has not been marked.
//
//        |-------|
//  Press | Enter | to exit.
//        |-------|

//多次标记报错界面
void multiple_mark_warning()
{
    system("cls");

    printf("\n");

    printf("\t\t|---|---|---|---|---|\n");
    printf("\t\t| E | R | R | O | R |\n");
    printf("\t\t|---|---|---|---|---|\n");
    printf("\n");
    printf("\t\tError: Mutiple mark is invalid.\n");
    printf("\n");
    printf("\t\tThis area has been marked. You can not mark a place again since it has been marked.\n");
    printf("\t\tSo, you can choose a new area which has not been marked.\n");
    printf("\t\t      |-------|\n");
    printf("\t\tPress | Enter | to exit.\n");
    printf("\t\t      |-------|\n");
    printf("\t\t");
}