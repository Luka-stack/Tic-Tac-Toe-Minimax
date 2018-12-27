/*
 * Created By Hayami Takahiro
 * C Source file which contains all function for AI Player
 */

//TODO Think about changing char board to int board (huPlayer - 1, aiPlayer - -1, empty - 0)

/*
 * return max from given parameters
 */
int max(int num1, int num2)
{
    return (num1 > num2 ? num1 : num2);
}

/*
 * return min from given parameters
 */
int min(int num1, int num2)
{
    return (num1 < num2 ? num1 : num2);
}

/*
 * checking if there is any possible move
 * return true(1) if so, or false(0) otherwise
 */
int any_left_moves(const int *board)
{
    int i;

    for (i = 0; i < 9; i++) {
        if (board[i] == 0)
            return 1;
    }

    return 0;
}

/*
* return value based on who is winning
* return 10 if player 'X' wins, -10 if player 'O' wins, and 0 if draw
*/
int evaluate(const int *board)
{
    int i;

    /* Checking rows for 'O' and 'X' player wins */
    for (i = 0; i < 7; i+=3)
    {
        if (board[i] == board[i+1] && board[i] == board[i+2])
        {
            if (board[i] == 2)
                return 10;
            else if (board[i] == 1)
                return -10;
        }
    }

    /* Checking columns for 'O' and 'X' player wins */
    for (i = 0; i < 3; i++)
    {
        if (board[i] == board[i+3] && board[i] == board[i+6])
        {
            if (board[i] == 2)
                return 10;
            else if (board[i] == 1)
                return -10;
        }
    }

    /* Checking diagonals for 'O' and 'X' player wins */
    if (board[0] == board[4] && board[4] == board[8])
    {
        if (board[0] == 2)
            return 10;
        else if (board[0] == 1)
            return -10;
    }
    if (board[2] == board[4] && board[4] == board[6])
    {
        if (board[2] == 2)
            return 10;
        else if (board[2] == 1)
            return -10;
    }

    /* if none one won */
    return 0;
}

/*
 * Implementation of minimax algorithm.
 * Consider all of the possible ways that game could take
 * and return the score
 */
int minimax(int *board, int depth, int isMaxMove)
{
    int score, i;

    score = evaluate(board);

    /* checking (results) to stop recursion */

    /* If MaxMove won the game */
    if (score == 10)
        return score - depth;

    /* If MinMove won the game */
    if (score == -10)
        return score + depth;

    /* If it is draw */
    if (any_left_moves(board) == 0)
        return 0;

    /* call recursion */

    /* If it is MaxMove */
    if (isMaxMove)
    {
        /*  unfortunately there is no -infinite
            so take any negative (much lower than -10) */
        int best = -1000;

        /* go through all tiles (possible moves) */
        for (i = 0; i < 9; i++)
        {
            /* if tile is empty */
            if (board[i] == 0)
            {
                /* make move */
                board[i] = 2;

                /* call minimax recursively to evaluate the best move (the highest value) */
                best = max(best, minimax(board, depth+1, 0));

                /* undo the move cuz there is only one board :> */
                board[i] = 0;
            }
        }
        return best;
    }
        /* If it is MinMove */
    else {
        /*  unfortunately there is no infinite
            so take any positive (much higher than 10) */
        int best = 1000;

        /* go through all tiles (possible moves) */
        for (i = 0; i < 9; i++)
        {
            /* if tile is empty */
            if (board[i] == 0)
            {
                /* make move */
                board[i] = 1;

                /* call minimax recursively to evaluate the best move (the lowest value) */
                best = min(best, minimax(board, depth+1, 1));

                /* undo move */
                board[i] = 0;
            }
        }
        return best;
    }
}

/*
 * return the best possible move
 */
int find_best_move(int *board) {
    /* take relatively small number */
    int i, moveVal, bestVal = -1000, moveTile = -1;

    /*  go through all tiles, call minimax function for empty tiles
        and return tile with the best solution (value) */
    for (i = 0; i < 9; i++) {
        /* check if move is possible */
        if (board[i] == 0) {
            /* make move */
            board[i] = 2;

            /* evaluate minimax for this move */
            moveVal = minimax(board, 0, 0);

            /* undo the move */
            board[i] = 0;

            /*  if the moveVal is higher than current best
                update the bestVal */
            if (moveVal > bestVal)
            {
                moveTile = i;
                bestVal = moveVal;
            }
        }
    }

    return moveTile;
}
