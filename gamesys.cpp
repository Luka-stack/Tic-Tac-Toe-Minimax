/*
 * Created By Hayami Takahiro
 * C Source file which contains all function for AI Player
 */

/*
 * helper function to clear stdin
 */
void clean_stdin(void) {

    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

/*
 * populate board with empty tiles
 */
void set_empty_board(int *board)
{
    int i;

    for (i = 0; i < 9; i++)
        board[i] = 0;
}

/*
 * take player move till it is valid,
 * execute or print error
 */
void execute_player_move(int *board) {
    int checkInput = 0, executeMove = -1;

    while (1)
    {
        printf("\nPlease enter number <0, 9> indicating where you want put your sign: ");
        checkInput = scanf("%d", &executeMove);
        clean_stdin();
        if (checkInput != 0 && (executeMove >= 0 && executeMove <= 8)) {
            if (board[executeMove] == 0) {
                board[executeMove] = 1;
                break;
            }
            else {
                printf("[%d] is occupied\n", executeMove);
            }
        }
        else {
            printf("Invalid Input. Enter Number in range <0, 8>\n");
        }
    }
}

/*
 * replace every 1 and 0 for human's and ai's signs
 */
void display_board(const int *board, char hu, char ai)
{
    int i;

    printf("\n\n\t\t");
    for (i = 0; i < 25; i++)
        printf("#");
    printf("\n\t\t#\t\t\t\t\t\t#\n");

    for (i = 0; i < 7; i+=3)
    {
        //printf("\t\t#\t\t%c | %c | %c\t\t#\n", board[i] == 1 ? hu : ai, board[i] == 1 ? hu : ai, board[i] == 1 ? hu : ai);
        printf("\t\t#\t\t%c | ", board[i] == 1 ? hu : (board[i] == 2 ? ai : '_'));
        printf("%c | ", board[i+1] == 1 ? hu : (board[i+1] == 2 ? ai : '_'));
        printf("%c\t\t#\n", board[i+2] == 1 ? hu : (board[i+2] == 2 ? ai : '_'));

        if (i < 6) {
            printf("\t\t#\t\t---------\t\t#");

            if (i == 0)
                printf("\t '%c' - Human Player", hu);
            else
                printf("\t '%c' - Computer Player", ai);
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
    for (i = 0; i < 37; i++)
        printf("#");

    printf("\n\t\t#\t\t\t\t\t\t\t\t\t#\n");
    printf("\t\t#\t\t 1 - Play Game vs Ai\t\t\t\t#");
    printf("\n\t\t#\t\t\t\t\t\t\t\t\t#\n");
    printf("\t\t#\t\t 2 - Print Author \t\t\t#");
    printf("\n\t\t#\t\t\t\t\t\t\t\t\t#\n");
    printf("\t\t#\t\t 0 - Exit \t\t\t\t\t#");
    printf("\n\t\t#\t\t\t\t\t\t\t\t\t#\n");

    printf("\t\t");
    for (i = 0; i < 37; i++)
        printf("#");
    printf("\n\n");
}

void print_author(void)
{
    printf("\n\t\t Project: Ichi - Rei Game\n");
    printf("\n\t\t Created By: Hayami Takahiro On: 25.12.2018\n");
    printf("\n\t\t Description: Tic-Tac_Toe Based on MiniMax Algorithm\n");
}

/*
 * check if someone won or if it is draw
 * human player - 1, ai player - -1, draw 0
 */
//TODO think about merging this function with evaluate
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
    if (board[3] == board[4] && board[3] == board[6])
    {
        if (board[3] == 2)
            return -1;
        else if (board[3] == 1)
            return 1;
    }

    for (i = 0; i < 9; i++) {
        if (board[i] == 0)
            return -2;
    }

    return 0;
}