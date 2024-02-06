//玩家操作

#include "minesweeper.h"

//探雷
//mine_detection(游戏难度等级，选中目标行数，选中目标列数)
void mine_detection(int lev,int target_r,int target_c)
{
    //定义搜索对象
    int search_r;
    int search_c;

    //定义雷盘和数字盘指针转存器
    int *mineboard_pointer_storer_1;
    int *mineboard_pointer_storer_2;
    char *figureboard_pointer_storer;

    //指针转存
    switch(lev)
    {
        case 1:
            mineboard_pointer_storer_1=&mineboard_lev_easy[target_r-1][target_c-1];
            figureboard_pointer_storer=&figureboard_lev_easy[target_r-1][target_c-1];
            break;
        case 2:
            mineboard_pointer_storer_1=&mineboard_lev_middle[target_r-1][target_c-1];
            figureboard_pointer_storer=&figureboard_lev_middle[target_r-1][target_c-1];
            break;
        case 3:
            mineboard_pointer_storer_1=&mineboard_lev_difficult[target_r-1][target_c-1];
            figureboard_pointer_storer=&figureboard_lev_difficult[target_r-1][target_c-1];
            break;    
    }
    
    //判断是否有雷
    if(*mineboard_pointer_storer_1==-1)
    {
        mine_display(lev);
    }
    else
    {
        //判断是否为安全区
        if(*mineboard_pointer_storer_1>0)
        {
            transformation_i_to_c(*mineboard_pointer_storer_1,figureboard_pointer_storer);
        }
        else
        {
            //判断为绝对安全区
            //编辑选中对象
            switch(lev)
            {
                case 1:
                    figureboard_lev_easy[target_r-1][target_c-1]='0';
                    break;
                case 2:
                    figureboard_lev_middle[target_r-1][target_c-1]='0';
                    break;
                case 3:
                    figureboard_lev_difficult[target_r-1][target_c-1]='0';
                    break;
            }
            
            //无雷区搜索
            no_mine_area_search(lev,target_r,target_c);
        }
    }
}

//玩家输入
//player_input(游戏等级)
void player_input(int lev)
{
    //定义输入行数和列数
    char input_r[50];
    char input_c[50];

    //定义行数列数
    int target_r;
    int target_c;

    //定义确认选项
    int verification_choice;


    while(1)
    {
        system("cls");

        //游戏标题显示
        game_title();
        printf("\n");

        //数字盘打印
        figureboard_print(lev);
        printf("\n");

        //坐标输入
        printf("\t\t-Coordinate Input-\n");
        printf("\t\t                                                      |-------|\n");
        printf("\t\tInput the numbers on the side of the board, and press | Enter | after you finish.\n");
        printf("\t\t                                                      |-------|\n");
        printf("\n");
        printf("\t\tInput the row(R):");
        scanf("%49s",input_r);
        printf("\t\tInput the column(C):");
        scanf("%49s",input_c);

        //判断坐标格式输入合法性
        if(strlen(input_r)==3&&strlen(input_c)==3)
        {
            //数字转换
            target_r=atoi(input_r);
            target_c=atoi(input_c);

            //判断行数合法性
            if(target_r>0&&target_r<=board_row[lev-1])
            {
                //判断列数合法性
                if(target_c>0&&target_c<=board_column[lev-1])
                {
                    //待定区域选中
                    system("cls");
                    game_title();
                    printf("\n");

                    //标记
                    switch(lev)
                    {
                        case 1:
                            figureboard_lev_easy_left[target_r-1][target_c-1]='>';
                            figureboard_lev_easy_right[target_r-1][target_c-1]='<';
                            break;
                        case 2:
                            figureboard_lev_middle_left[target_r-1][target_c-1]='>';
                            figureboard_lev_middle_right[target_r-1][target_c-1]='<';                            
                            break;
                        case 3:
                            figureboard_lev_difficult_left[target_r-1][target_c-1]='>';
                            figureboard_lev_difficult_right[target_r-1][target_c-1]='<';
                            break;
                    }
                    figureboard_print(lev);
                    printf("\n");

                    //输入坐标确认
                    printf("\t\t-Verification-\n");
                    printf("\n");
                    printf("\t\tPlease ensure the coordinate you have input. The area you choose is marked by > < .\n");
                    printf("\t\t                                  |-------|\n");
                    printf("\t\tThen make your decision and press | Enter | after you finish the input.\n");
                    printf("\t\t                                  |-------|\n");
                    printf("\n");
                    printf("\t\t1. Verified\n");
                    printf("\t\t2. Input the coordinate again\n");
                    printf("\n");
                    printf("\t\tYour choice: ");
                    scanf("%d",&verification_choice);
                    if(verification_choice==1)
                    {
                        system("cls");

                        //玩家操作选择
                        player_operation_choose(lev,target_r,target_c);
                        
                    }
                    else if(verification_choice==2)
                    {
                        //清除选中待定标记
                        switch(lev)
                        {
                            case 1:
                                figureboard_lev_easy_left[target_r-1][target_c-1]=' ';
                                figureboard_lev_easy_right[target_r-1][target_c-1]=' ';
                                break;
                            case 2:
                                figureboard_lev_middle_left[target_r-1][target_c-1]=' ';
                                figureboard_lev_middle_right[target_r-1][target_c-1]=' ';
                                break;
                            case 3:
                                figureboard_lev_difficult_left[target_r-1][target_c-1]=' ';
                                figureboard_lev_difficult_right[target_r-1][target_c-1]=' ';
                                break;
                        }     
                        
                        //执行玩家输入
                        system("cls");
                        player_input(lev);
                    }
                    break;
                }
                else
                {
                    //坐标不存在报错
                    player_coordinate_not_exist_warning();
                }
            }
            else
            {
                //坐标不存在报错
                player_coordinate_not_exist_warning();
            }
        }
        else
        {
            //坐标格式报错
            player_coordinate_wrong_format_warning();
        }
    }
}

//区域标记
//area_mark(游戏难度等级，选中目标行数，选中目标列数)
void area_mark(int lev,int target_r,int target_c)
{
    //清除选中区域待定标记
    switch(lev)
    {
        case 1:
            figureboard_lev_easy_left[target_r-1][target_c-1]=' ';
            figureboard_lev_easy_right[target_r-1][target_c-1]=' ';
            break;
        case 2:
            figureboard_lev_middle_left[target_r-1][target_c-1]=' ';
            figureboard_lev_middle_right[target_r-1][target_c-1]=' ';
            break;
        case 3:
            figureboard_lev_difficult_left[target_r-1][target_c-1]=' ';
            figureboard_lev_difficult_right[target_r-1][target_c-1]=' ';
            break;
    }

    //标记
    switch(lev)
    {
        case 1:
            figureboard_lev_easy[target_r-1][target_c-1]='P';
            break;
        case 2:
            figureboard_lev_middle[target_r-1][target_c-1]='P';
            break;
        case 3:
            figureboard_lev_difficult[target_r-1][target_c-1]='P';
            break;
    }
}


//玩家操作选择
//player_operation_choose(游戏难度等级，选中目标行数，选中目标列数)
void player_operation_choose(int lev,int target_r,int target_c)
{
    //定义玩家操作选项
    int operation;

    //定义数字盘转存器
    char figureboard_storer;

    //定义标记数量
    int mark_num;

    system("cls");

    //游戏标题
    game_title();
    printf("\n");

    //数字盘打印
    figureboard_print(1);
    printf("\n");

    //玩家操作选择
    printf("\t\t-Operation-\n");
    printf("\n");
    printf("\t\tPlease choose your operation. Input the number of your choice,\n");
    printf("\t\t               |-------|\n");
    printf("\t\tand then press | Enter |.\n");
    printf("\t\t               |-------|\n");
    printf("\n"); 
    printf("\t\t\t1. Explore\n");
    printf("\t\t\t2. Mark\n");
    printf("\t\t\t3. delete mark\n");
    printf("\n");
    printf("\t\tYour choice: ");
    scanf("%d",&operation);

    if(operation==1)
    {
        system("cls");

        //数字盘转存
        switch(lev)
        {
            case 1:
                figureboard_storer=figureboard_lev_easy[target_r-1][target_c-1];
                break;
            case 2:
                figureboard_storer=figureboard_lev_middle[target_r-1][target_c-1];
                break;
            case 3:
                figureboard_storer=figureboard_lev_difficult[target_r-1][target_c-1];
                break;
        }

        //判断区域是否被占用
        if(figureboard_storer==' ')
        {
            //未被占用，则执行探索操作
            //未知区域探索
            unknown_area_explore(lev,target_r,target_c);

            //游戏结果判断
            judge(lev);
        }
        else
        {
            //如已被占用，则进入报错界面并删除待定标记
            switch(lev)
            {
                case 1:
                    figureboard_lev_easy_left[target_r-1][target_c-1]=' ';
                    figureboard_lev_easy_right[target_r-1][target_c-1]=' ';
                    break;
                case 2:
                    figureboard_lev_middle_left[target_r-1][target_c-1]=' ';
                    figureboard_lev_middle_right[target_r-1][target_c-1]=' ';
                    break;
                case 3:
                    figureboard_lev_difficult_left[target_r-1][target_c-1]=' ';
                    figureboard_lev_difficult_right[target_r-1][target_c-1]=' ';
                    break;
            }

            area_occupied_warning();

            if(getchar()=='\n')
            {
                if(getchar()=='\n')
                {
                    player_input(lev);
                }
            }
        }
    }
    else if(operation==2)
    {
        //统计当前剩余标记数
        mark_num=residual_mark(lev);

        if(mark_num==0)
        {
            //若可用标记数已耗尽则转跳至报错界面
            residual_mark_run_out_warning();
            if(getchar()=='\n')
            {
                if(getchar()=='\n')
                {
                    player_input(lev);
                }
            }
        }
        else
        {
            //数字盘转存
            switch(lev)
            {
                case 1:
                    figureboard_storer=figureboard_lev_easy[target_r-1][target_c-1];
                    break;
                case 2:
                    figureboard_storer=figureboard_lev_middle[target_r-1][target_c-1];
                    break;
                case 3:
                    figureboard_storer=figureboard_lev_difficult[target_r-1][target_c-1];
                    break;
            }

            //判断选中标记是否已被标记
            if(figureboard_storer=='P')
            {
                //若已被标记，则转跳至报错界面
                multiple_mark_warning();

                //清除待定标记
                switch(lev)
                {
                    case 1:
                        figureboard_lev_easy_left[target_r-1][target_c-1]=' ';
                        figureboard_lev_easy_right[target_r-1][target_c-1]=' ';
                        break;
                    case 2:
                        figureboard_lev_middle_left[target_r-1][target_c-1]=' ';
                        figureboard_lev_middle_right[target_r-1][target_c-1]=' ';
                        break;
                    case 3:
                        figureboard_lev_difficult_left[target_r-1][target_c-1]=' ';
                        figureboard_lev_difficult_right[target_r-1][target_c-1]=' ';
                        break;
                }

                //返回玩家输入界面
                if(getchar()=='\n')
                {
                    if(getchar()=='\n')
                    {
                        player_input(lev);
                    }
                }
            }
            else
            {
                //区域标记
                area_mark(lev,target_r,target_c);

                //完成本轮操作后，再进入下一轮操作
                player_input(lev);
            }
        }
    }
    else if (operation==3)
    {
        //标记删除
        mark_delete(lev,target_r,target_c);

        //完成本轮操作后，再进入下一轮操作
        player_input(lev);
    }
}

//未知区域探索
//unknown_area_explore(游戏难度等级，目标行数，目标列数)
void unknown_area_explore(int lev,int target_r,int target_c)
{    
    //定义雷盘存储器
    int mineboard_storer;

    //雷盘转存
    switch(lev)
    {
        case 1:
            mineboard_storer=mineboard_lev_easy[target_r-1][target_c-1];
            break;
        case 2:
            mineboard_storer=mineboard_lev_middle[target_r-1][target_c-1];
            break;
        case 3:
            mineboard_storer=mineboard_lev_difficult[target_r-1][target_c-1];
            break;
    }

    //探雷
    mine_detection(lev,target_r,target_c);

    //若选中区域有雷，则恢复待定标记
    if(mineboard_storer==-1)
    {
        switch(lev)
        {
            case 1:
                figureboard_lev_easy_left[target_r-1][target_c-1]='>';
                figureboard_lev_easy_right[target_r-1][target_c-1]='<';
                break;
            case 2:
                figureboard_lev_middle_left[target_r-1][target_c-1]='>';
                figureboard_lev_middle_right[target_r-1][target_c-1]='<';
                break;
            case 3:
                figureboard_lev_difficult_left[target_r-1][target_c-1]='>';
                figureboard_lev_difficult_right[target_r-1][target_c-1]='<';
                break;
        }
    }
    else
    {
        //否则清除待定标记
        switch(lev)
        {
            case 1:
                figureboard_lev_easy_left[target_r-1][target_c-1]=' ';
                figureboard_lev_easy_right[target_r-1][target_c-1]=' ';
                break;
            case 2:
                figureboard_lev_middle_left[target_r-1][target_c-1]=' ';
                figureboard_lev_middle_right[target_r-1][target_c-1]=' ';
                break;
            case 3:
                figureboard_lev_difficult_left[target_r-1][target_c-1]=' ';
                figureboard_lev_difficult_right[target_r-1][target_c-1]=' ';
                break;
        }
    }
}

//选中区域待定标记删除
void mark_delete(int lev,int target_r,int target_c)
{
    //定义转存器
    char figureboard_storer;
    

    //数字盘转存
    switch(lev)
    {
        case 1:
            figureboard_storer=figureboard_lev_easy[target_r-1][target_c-1];
            break;
        case 2:
            figureboard_storer=figureboard_lev_middle[target_r-1][target_c-1];
            break;
        case 3:
            figureboard_storer=figureboard_lev_difficult[target_r-1][target_c-1];
            break;
    }

    //先判断选中区域是否已被标记
    if(figureboard_storer!='P')
    {
        area_not_marked_warning(lev,target_r,target_c);
    }
    else
    {
        //删除选中区域待定标记
        switch(lev)
        {
            case 1:
                figureboard_lev_easy_left[target_r-1][target_c-1]=' ';
                figureboard_lev_easy_right[target_r-1][target_c-1]=' ';
                break;
            case 2:
                figureboard_lev_middle_left[target_r-1][target_c-1]=' ';
                figureboard_lev_middle_right[target_r-1][target_c-1]=' ';
                break;
            case 3:
                figureboard_lev_difficult_left[target_r-1][target_c-1]=' ';
                figureboard_lev_difficult_right[target_r-1][target_c-1]=' ';
                break;
        }
        
        //删除标记
        switch(lev)
        {
            case 1:
                figureboard_lev_easy[target_r-1][target_c-1]=' ';
                break;
            case 2:
                figureboard_lev_middle[target_r-1][target_c-1]=' ';
                break;
            case 3:
                figureboard_lev_difficult[target_r-1][target_c-1]=' ';
                break;
        }

    }
}

//游戏雷区已标记数量统计
//residual_mark(游戏难度等级)
int residual_mark(int lev)
{
    //定义计数器并初始化
    int sum=0;

    for(int r=1;r<=board_row[lev-1];r++)
    {
        for(int c=1;c<=board_column[lev-1];c++)
        {
            switch(lev)
            {
                case 1:
                    if(figureboard_lev_easy[r-1][c-1]=='P')
                    {
                        sum++;
                    }
                    break;
                case 2:
                    if(figureboard_lev_middle[r-1][c-1]=='P')
                    {
                        sum++;
                    }
                    break;
                case 3:
                    if(figureboard_lev_difficult[r-1][c-1]=='P')
                    {
                        sum++;
                    }
                    break;
            }
        }
    }
    return mine[lev-1]-sum;
}

