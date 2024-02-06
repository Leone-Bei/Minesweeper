#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

//宏定义
#define r_1 9 //定义初级模式的行数
#define c_1 9 //定义初级模式的列数
#define m_1 10 //定义初级模式地雷数
#define r_2 16
#define c_2 16
#define m_2 40
#define r_3 16
#define c_3 30
#define m_3 99
#define Pi 3.1415926535

//变量声明
extern int mineboard_lev_easy[9][9];
extern int mineboard_lev_middle[16][16];
extern int mineboard_lev_difficult[16][30];
extern char figureboard_lev_easy[9][9];
extern char figureboard_lev_middle[16][16];
extern char figureboard_lev_difficult[16][30];
extern int game_lev;
extern int board_row[3];
extern int board_column[3];
extern int mine[3];
extern int row_input;
extern int column_input;
extern char figureboard_lev_easy_right[9][9];
extern char figureboard_lev_middle_right[16][16];
extern char figureboard_lev_difficult_right[16][30];
extern char figureboard_lev_easy_left[9][9];
extern char figureboard_lev_middle_left[16][16];
extern char figureboard_lev_difficult_left[16][30];

//函数声明
void figureboard_initialization(int k);
void mineboard_initialization(int lev);
void figureboard_print(int k);
void mineset(int lev);
void mineboard_print(int lev);
void rotation_search(int n,int r0,int c0,int *r,int *c);
void transformation_i_to_c(int i,char *c);
void mine_display(int lev);
void mineboard_edit(int lev);
void mine_detection(int lev,int target_r,int target_c);
void no_mine_area_search(int lev,int target_r,int target_c);
void figureboard_edit(int lev);
void player_input(int lev);
void game_process();
void startpage();
void menu();
void player_coordinate_wrong_format_warning();
void player_coordinate_not_exist_warning();
void game_title();
void player_operation_choose(int lev,int target_r,int target_c);
void unknown_area_explore(int lev,int target_r,int target_c);
void judge(int lev);
void mark_delete(int lev,int target_r,int target_c);
void area_not_marked_warning(int lev,int target_r,int target_c);
void level();
void player_wrong_choice_input();
int residual_mark(int lev);
void area_occupied_warning();
void residual_mark_run_out_warning();
void multiple_mark_warning();