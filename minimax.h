//
// Created by takacchi on 09/01/19.
//

#ifndef TICTACTOE_MINIMAX_H
#define TICTACTOE_MINIMAX_H

/*
 * Created By Hayami Takahiro
 * C header file which contains all function for AI Player
 */

/*
 * return max from given parameters
 */
int max(int num1, int num2);

/*
 * return min from given parameters
 */
int min(int num1, int num2);

/*
 * checking if there is any possible move
 * return true(1) if so, or false(0) otherwise
 */
int any_left_moves(const int *board);

/*
* return value based on who is winning
* return 10 if player 'X' wins, -10 if player 'O' wins, and 0 if draw
*/
int evaluate(const int *board);

/*
 * Implementation of minimax algorithm.
 * Consider all of the possible ways that game could take
 * and return the score
 */
int minimax(int *board, int depth, int isMaxMove);

/*
 * return the best possible move
 */
int find_best_move(int *board);

#endif TICTACTOE_MINIMAX_H
