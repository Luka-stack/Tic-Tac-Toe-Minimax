/*
 * Created by Hayami Takahiro
 */

#include <stdio.h>
#include "minimax.h"
#include "gamesys.h"
#define B 9

/*
 * human player is 1 (one)
 * ai player is 2 (two)
 * empty tile 0 (zero)
 */
int main()
{
    int ans = -1;
    char ai = 'A', hu = 'H', hu2 = 'O';
    int board[B];
    set_empty_board(board);

    printf("\n\t  () --=> Welcome to Ichi - Rei Game <=-- ()\n");

    while (ans != 0) {
        print_menu();
        printf("\t\tEnter Option Number: ");
        scanf("%d", &ans);
        clean_stdin();

        switch (ans) {
            case 1:
                play_game(1, hu, ai);
                break;

            case 2:
                play_game(2, hu, hu2);
                break;

            case 3:
                change_signs(&ai, &hu, &hu2);
                break;

            case 4:
                print_author();
                break;

            case 0:
                printf("\n\t\tThanks for Playing My Game. Have a nice day\n");
                break;

            default:
                printf("\n You have to chose option 1 or 2\n");
        };
    }

    return 0;
}