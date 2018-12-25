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
    char board[9] = {
            'O', 'X', '_',
            '_', 'O', '_',
            '_', '_', '_'
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
    char board[9] = {
            'X', 'O', 'X',
            'O', 'O', 'X',
            '_', '_', '_'
    };
    display_board(board);
}

/*
 * for now human player is O
 * ai player is X
 */
int main()
{
    int i = 1, isGameOn = -2, ans = -1;
    char board[B];
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
                    display_board(board);
                    execute_player_move(board);
                    printf("\n\t\t --> %d board move <--", i++);
                    display_board(board);
                    sleep(1);
                    board[find_best_move(board)] = 'X';
                    isGameOn = is_game_finished(board);
                }

                if (isGameOn == 1)
                    printf("\n\t\t ==> Human Player Won - Congratulation");
                else if (isGameOn == -1)
                    printf("\n\t\t ==> AI Player Won - Computer seems to be smarter");
                else
                    printf("\n\t\t ==> It is a draw - That's normal don't worry :)");
                display_board(board);
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