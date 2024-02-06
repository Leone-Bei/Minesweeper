//游戏主进程

#include "minesweeper.h"

//游戏主进程
void game_process()
{
    figureboard_initialization(game_lev);
    mineboard_initialization(game_lev);
    mineset(game_lev);
    mineboard_edit(game_lev);
    player_input(game_lev);
}