#include <stdio.h>

void draw_board(char board[3][3]);
int is_valid_move(char board[3][3], int row, int col);
void make_move(char board[3][3], int row, int col, char player);
char check_winner(char board[3][3]);
int is_draw(char board[3][3]);
void get_player_input(int *row, int *col);

int main()
{
    char board[3][3] = 
    {
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    char current_player = 'x';
    char winner = ' ';
    while (winner == ' ' && !is_draw(board))
    {
        draw_board(board);
        printf("player %c enter row & col (1-3):", current_player);
        int row, col;
        get_player_input(&row, &col);
            row--;
            col--;
        if (!is_valid_move(board, row, col))
        {
            printf("invalid move, try again\n");
            continue;
        }
        make_move(board, row, col, current_player);
        winner = check_winner(board);
        current_player = (current_player == 'x') ? 'o' : 'x';
    }
    draw_board(board);
    if (winner != ' ') printf("player %c wins\n", winner);
    else printf("It's a draw\n");
    return 0;
}

void draw_board(char board[3][3])
{
    printf(" %c | %c | %c \n",board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n",board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n",board[2][0], board[2][1], board[2][2]);
}

int is_valid_move(char board[3][3], int row, int col)
{
    if ( (row < 0 || row > 3) || (col < 0 || col > 3) || (board[row][col] != ' ') )
        return (0);
    else return (1);
}

void make_move(char board[3][3], int row, int col, char player)
{
    if (is_valid_move(board, row, col))
        board[row][col] = player;
    else printf("invalid move");
}

char check_winner(char board[3][3])
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
    {
        if (board[0][0] == 'x')
            return ('x');
        if (board[0][0] == 'o')
            return ('o');
    } 
    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
    {
        if (board[1][0] == 'x')
            return ('x');
        if (board[1][0] == 'o')
            return ('o');
    }
    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
    {
        if (board[2][0] == 'x')
            return ('x');
        if (board[2][0] == 'o')
            return ('o');
    }
    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[1][1] == 'x')
            return ('x');
        if (board[1][1] == 'o')
            return ('o');
    }
    else if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
    {
        if (board[1][1] == 'x')
            return ('x');
        if (board[1][1] == 'o')
            return ('o');
    }
    return (' ');
}

int is_draw(char board[3][3])
{
    int i = 0;
    int j = 0;
    if (check_winner(board) == ' ')
    {
        while (board[i][j] != ' ')
        {
            j++;
            if ( j == 2 )
            {
                if (i == 2)
                    return (1);
                i++;
                j = 0;
            }
        }
    }
    return (0);
}

void get_player_input(int *row, int *col)
{
    scanf("%d", row);
    scanf("%d", col);
}