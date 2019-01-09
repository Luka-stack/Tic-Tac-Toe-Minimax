//
// Created by takacchi on 09/01/19.
//

#ifndef TICTACTOE_GAMESYS_H
#define TICTACTOE_GAMESYS_H

/*
 * Created By Hayami Takahiro
 * C header file which contains game engine with GUI
 */

/*
 * helper function to clear stdin
 */
void clean_stdin(void);
/*
 * populate board with empty tiles
 */
void set_empty_board(int *board);

/*
 * take player move till it is valid,
 * execute or print error
 * player = 1 -> human, player = 2 -> human 2
 * moveTurn 1 - human move 2 - ai move
 */
void execute_player_move(int *board, int player, int moveTurn);

/*
 * replace 1 for human player -> p1
 * 2 for human 2 player or ai player -> p2
 * setting says if its human vs ai or human vs human
 */
void display_board(const int *board, char p1, char p2, int setting);

void print_menu(void);

void print_author(void);

/*
 * check if someone won or if it is draw
 * human player - 1, ai/human2 player - -1, draw 0
 */
int is_game_finished(const int *board);

/*
 * change sign for every player
 */
void change_signs(char *ai, char *hu, char *hu2);

/*
 * play tic tac toe game depends on settings
 * p1 -> human player p2 -> ai or human2
 * setting 1 - hu vs ai 2 - hu vs hu
 */
void play_game(int setting, char p1, char p2);

#endif TICTACTOE_GAMESYS_H
