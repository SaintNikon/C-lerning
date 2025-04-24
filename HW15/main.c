#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 10
#define MINES 5

char board[SIZE][SIZE];
char visible[SIZE][SIZE];
bool game_over = false;

void initialize()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            board[i][j] = '0';
            visible[i][j] = '-';
        }
    }
    //ÐÀÑÑÒÀÍÎÂÊÀ ÌÈÍ
    srand(time(NULL));
    int mines_placed = 0;
    while (mines_placed < MINES)
    {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] != '*')
        {
            board[x][y] = '*';
            mines_placed++;
            //ðàññòàíîâêà ÷èñåë âîêðóã ìèí
            for(int i = -1; i <= 1; i++)
            {
                for(int j = -1; j <= 1; j++)
                {
                    int nx = x + i;
                    int ny = y + j;
                    if(nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && board[nx][ny] != '*')
                    {
                        board[nx][ny]++;
                    }
                }
            }
        }
    }
}

void print_board()
{
    printf("  ");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c ", visible[i][j]);
        }
        printf("\n");
    }
}

void reveal(int x, int y)
{
    if(x < 0 || x >= SIZE || y < 0 || y >= SIZE || visible[x][y] != '-')
    {
        return;
    }
    visible[x][y] = board[x][y];
    if(board[x][y] == '*')
    {
        game_over = true;
        printf("YOU DEAD!!!\n");

        for(int i = 0; i < SIZE; i++)
        {
            for(int j = 0; j < SIZE; j++)
            {
                if (board[i][j] == '*')
                {
                    visible[i][j] = '*';
                }
            }
        }
        print_board();
        return;
    }
    if(board[x][y] == '0')
    {
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                reveal(x + i, y + j);
            }
        }
    }
}

bool check_win()
{
    for (int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(board[i][j] != '*' && visible[i][j] == '-')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    initialize();
    printf("Welcome to Minesweeper!\n");
    printf("The field has sides of %d cells\n", SIZE);
    while(!game_over)
    {
        print_board();
        int x, y;
        printf("Enter the coordinates: x y\n");
        scanf("%d %d", &x, &y);

        if(x < 0 || x >= SIZE || y < 0 || y >= SIZE)
        {
            printf("coordinate error");
            continue;
        }
        reveal(x,y);
        if(check_win())
        {
            printf("YOU WIN!!!\n");
            print_board();
            break;
        }
    }
    return 0;
}
