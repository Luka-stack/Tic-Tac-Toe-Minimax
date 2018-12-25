/*
 * Created by Hayami Takahiro
 */

#include <stdio.h>
#include <unistd.h>
#include "minimax.cpp"
#include "gamesys.cpp"
#define B 9

/*
 * minimax test
 */
void minimax_test()
{
    int value = 0;
    int board[9] = {
            1, 2, 1,
            1, 0, 0,
            0, 0, 2
    };

    value = find_best_move(board);

    printf("The Optimal move is: \n");
    printf("Tile: %d\n", value);
}

/*
 * display board test
 */
void display_board_test()
{
    char ai = 'A', hu = 'H';
    int board[9] = {
            1, 2, 1,
            2, 1, 2,
            1, 0, 2
    };
    display_board(board, hu, ai);
}

/*
 * human player is 1 (one)
 * ai player is 2 (two)
 * empty tile 0 (zero)
 */
int main()
{
    int i = 1, isGameOn = -2, ans = -1;
    char ai = 'A', hu = 'H', hu2 = 'O';
    int board[B];
    set_empty_board(board);

    printf("\n\t  () --=> Welcome to Ichi - Rei Game <=-- ()\n");

    while (ans != 0) {
        print_menu();
        printf("\t\tEnter Option Number: ");
        scanf("%d", &ans);

        switch (ans) {
            case 1:
                //TODO print so nice statement at the beginning
                while (isGameOn == -2) {
                    printf("\n\n\t\t ---> %d Board Move <---", i++);
                    display_board(board, hu, ai);
                    execute_player_move(board);
                    printf("\n\t\t --> %d board move <--", i++);
                    display_board(board, hu, ai);
                    sleep(1);
                    board[find_best_move(board)] = 2;
                    isGameOn = is_game_finished(board);
                }

                if (isGameOn == 1)
                    printf("\n\t\t ==> Human Player Won - Congratulation");
                else if (isGameOn == -1)
                    printf("\n\t\t ==> AI Player Won - Computer seems to be smarter");
                else
                    printf("\n\t\t ==> It is a draw - That's normal don't worry :)");
                display_board(board, hu, ai);
                break;

            case 2:
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