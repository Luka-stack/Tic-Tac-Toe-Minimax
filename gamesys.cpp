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
void set_empty_board(char *board)
{
    int i;

    for (i = 0; i < 9; i++)
        board[i] = '_';
}

/*
 * take player move till it is valid,
 * execute or print error
 */
void execute_player_move(char *board) {
    int checkInput = 0, executeMove = -1;

    while (1)
    {
        printf("\nPlease enter number <0, 9> indicating where you want put your sign: ");
        checkInput = scanf("%d", &executeMove);
        clean_stdin();
        if (checkInput != 0 && (executeMove >= 0 && executeMove <= 8)) {
            if (board[executeMove] == '_') {
                board[executeMove] = 'O';
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

void display_board(const char *board)
{
    int i;

    printf("\n\n\t\t");
    for (i = 0; i < 25; i++)
        printf("#");
    printf("\n\t\t#\t\t\t\t\t\t#\n");

    for (i = 0; i < 7; i+=3)
    {
        printf("\t\t#\t\t%c | %c | %c\t\t#\n", board[i], board[i+1], board[i+2]);
        if (i < 6) {
            printf("\t\t#\t\t---------\t\t#");

            if (i == 0)
                printf("\t 'X' - Human Player");
            else
                printf("\t 'O' - Computer Player");
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
    printf("\t\t#\t\t 1 - Play Game \t\t\t\t#");
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
int is_game_finished(const char *board)
{
    int i;

    /* check rows */
    for (i = 0; i < 7; i+=3)
    {
        if (board[i] == board[i+1] && board[i] == board[i+2])
        {
            if (board[i] == 'X')
                return -1;
            else if (board[i] == 'O')
                return 1;
        }
    }

    /* check columns */
    for (i = 0; i < 3; i++)
    {
        if (board[i] == board[i+3] && board[i] == board[i+6])
        {
            if (board[i] == 'X')
                return -1;
            else if (board[i] == 'O')
                return 1;
        }
    }

    /* check diagonals */
    if (board[0] == board[4] && board[0] == board[8])
    {
        if (board[0] == 'X')
            return -1;
        else if (board[0] == 'O')
            return 1;
    }
    if (board[3] == board[4] && board[3] == board[6])
    {
        if (board[3] == 'X')
            return -1;
        else if (board[3] == 'O')
            return 1;
    }

    for (i = 0; i < 9; i++) {
        if (board[i] == '_')
            return -2;
    }

    return 0;
}