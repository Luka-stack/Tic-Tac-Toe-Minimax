/*
 * Created By Hayami Takahiro
 * C Source file which contains game engine with GUI
 */

#include <stdio.h>
#include <unistd.h>
#include "gamesys.h"
#include "minimax.h"
#define B 9

void clean_stdin(void)
{
    int c;

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void set_empty_board(int *board)
{
    int i;

    for (i = 0; i < 9; i++)
        board[i] = 0;
}

int execute_player_move(int *board, int player, int moveTurn) {
    int checkInput = 0, executeMove = -1;

    if (moveTurn == 2)
    {
        sleep(1);
        board[find_best_move(board)] = 2;
    }
    else {
        while (1) {
            printf("\nPlease enter number 10 to exit or <0, 8> indicating where you want put your sign: ");
            checkInput = scanf("%d", &executeMove);
            clean_stdin();
            if (checkInput != 0 && (executeMove >= 0 && executeMove <= 8)) {
                if (board[executeMove] == 0) {
                    board[executeMove] = player;
                    break;
                } else {
                    printf("[%d] is occupied\n", executeMove);
                }
            } else if (executeMove == 10) {
                return 10;
            } else {
                printf("Invalid Input. Enter Number in range <0, 8>\n");
            }
        }
    }

    return 0;
}

void display_board(const int *board, char p1, char p2, int setting)
{
    int i, z = 0;

    printf("\n\n\t\t");
    for (i = 0; i < 25; i++)
        printf("#");
    printf("\n\t\t#\t\t\t\t\t\t#\n");

    for (i = 0; i < 7; i+=3)
    {
        /*printf("\t\t#\t\t%c | %c | %c\t\t#\n", board[i] == 1 ? hu : ai, board[i] == 1 ? hu : ai, board[i] == 1 ? hu : ai);*/
        printf("\t\t#\t\t%c | ", board[i] == 1 ? p1 : (board[i] == 2 ? p2 : z+'0')); z++;
        printf("%c | ", board[i+1] == 1 ? p1 : (board[i+1] == 2 ? p2 : z+'0')); z++;
        printf("%c\t\t#\n", board[i+2] == 1 ? p1 : (board[i+2] == 2 ? p2 : z+'0')); z++;

        if (i < 6) {
            printf("\t\t#\t\t---------\t\t#");

            if (i == 0)
                printf("\t '%c' - Human Player", p1);
            else
                printf("\t '%c' - %s Player", p2, setting == 1 ? "Computer" : "Human2");
            printf("\n");
        }
    }

    printf("\t\t#\t\t\t\t\t\t#\n");
    printf("\t\t");
    for (i = 0; i < 25; i++)
        printf("#");
    printf("\n\n");
}

void print_menu(void)
{
    int i;

    printf("\n\t\t");
    for (i = 0; i < 33; i++)
        printf("#");

    printf("\n\t\t#\t\t\t\t\t\t\t\t#\n");
    printf("\t\t#\t 1 - Play Game vs Ai \t\t#");
    printf("\n\t\t#\t\t\t\t\t\t\t\t#\n");
    printf("\t\t#\t 2 - Play Game vs Human \t#");
    printf("\n\t\t#\t\t\t\t\t\t\t\t#\n");
    printf("\t\t#\t 3 - Change Signs \t\t\t#");
    printf("\n\t\t#\t\t\t\t\t\t\t\t#\n");
    printf("\t\t#\t 4 - Print Author \t\t\t#");
    printf("\n\t\t#\t\t\t\t\t\t\t\t#\n");
    printf("\t\t#\t 0 - Exit \t\t\t\t\t#");
    printf("\n\t\t#\t\t\t\t\t\t\t\t#\n");

    printf("\t\t");
    for (i = 0; i < 33; i++)
        printf("#");
    printf("\n\n");
}

void print_author(void)
{
    printf("\n\t\t Project: Ichi - Rei Game\n");
    printf("\n\t\t Created By: Hayami Takahiro On: 25.12.2018\n");
    printf("\n\t\t Description: Tic-Tac-Toe Based on MiniMax Algorithm\n");
}

/* TODO think about merging this function with evaluate */
int is_game_finished(const int *board)
{
    int i;

    /* check rows */
    for (i = 0; i < 7; i+=3)
    {
        if (board[i] == board[i+1] && board[i] == board[i+2])
        {
            if (board[i] == 2)
                return -1;
            else if (board[i] == 1)
                return 1;
        }
    }

    /* check columns */
    for (i = 0; i < 3; i++)
    {
        if (board[i] == board[i+3] && board[i] == board[i+6])
        {
            if (board[i] == 2)
                return -1;
            else if (board[i] == 1)
                return 1;
        }
    }

    /* check diagonals */
    if (board[0] == board[4] && board[0] == board[8])
    {
        if (board[0] == 2)
            return -1;
        else if (board[0] == 1)
            return 1;
    }
    if (board[2] == board[4] && board[2] == board[6])
    {
        if (board[2] == 2)
            return -1;
        else if (board[2] == 1)
            return 1;
    }

    for (i = 0; i < 9; i++) {
        if (board[i] == 0)
            return -2;
    }

    return 0;
}

void change_signs(char *ai, char *hu, char *hu2) {
    int ans, outLoop = 1;

    printf("\n\t\t--=> Signs Settings <=--\n");
    while (outLoop) {
        printf("\t\tCurrent Signs: \n");
        printf("\t\t\tComputer: [%c], \tHuman: [%c], Human 2: [%c]\n", *ai, *hu, *hu2);
        printf("\n\t\tWhich one would you like to change?\n");
        printf("\t\t1. Computer \t2. Human\n\t\t3. Human 2 \t0. Back To Main menu\n\t\t>> ");
        scanf("%d", &ans);
        clean_stdin();

        switch (ans) {
            case 1:
                printf("\t\tEnter new sign for Computer: ");
                scanf("%c", ai);
                clean_stdin();
                break;

            case 2:
                printf("\t\tEnter new sign for Human: ");
                scanf("%c", hu);
                clean_stdin();
                break;

            case 3:
                printf("\t\tEnter new sign for Human 2: ");
                scanf("%c", hu2);
                clean_stdin();
                break;

            case 0:
                outLoop = 0;
                break;

            default:
                printf("\n\t\tWrong Input. Please enter number in range <0, 3>\n");
        }
    }
}

void play_game(int setting, char p1, char p2)
{
    int i = 1, isGameOn = -2, board[B];
    int whichTurn = 1,  whichPlayer = 1;
    set_empty_board(board);

    while (isGameOn == -2)
    {
        printf("\n\n\t\t ---> %d Board Move <---", i++);
        display_board(board, p1, p2, setting);
        isGameOn = execute_player_move(board, whichPlayer, whichTurn);
        if (isGameOn == 10)
            break;
        if (setting == 2)
            whichPlayer = (whichPlayer == 1 ? 2 : 1);
        else
            whichTurn = (whichTurn == 1 ? 2 : 1);
        isGameOn = is_game_finished(board);
    }

    if (isGameOn == 10) {
        printf("\n\t\t\t\t +\t+\t+ GAME HAS BEEN STOPPED +\t+\t+ \n\n");
    } else {
        if (isGameOn == 1)
            printf("\n\t\t ==> Human Player Won - Congratulation");
        else if (isGameOn == -1)
            printf("\n\t\t ==> %s Player Won - %s seems to be smarter", setting == 2 ? "Human 2" : "Computer",
                   setting == 2 ? "Human 2" : "Computer");
        else
            printf("\n\t\t ==> It is a draw - That's normal don't worry :)");
        display_board(board, p1, p2, setting);
        printf("\n\t\t\t\t +\t+\t+ GAME FINISHED +\t+\t+ \n\n");
    }

    if (isGameOn == 1)
        printf("\n\t\t ==> Human Player Won - Congratulation");
    else if (isGameOn == -1)
        printf("\n\t\t ==> %s Player Won - %s seems to be smarter", setting == 2 ? "Human 2" : "Computer",
               setting == 2 ? "Human 2" : "Computer");
    else
        printf("\n\t\t ==> It is a draw - That's normal don't worry :)");
    display_board(board, p1, p2, setting);
    printf("\n\t\t\t\t +\t+\t+ GAME FINISHED +\t+\t+ \n\n");
}
