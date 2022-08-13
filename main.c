#include <unistd.h>
#include <stdio.h>

#define SIZE 9

int cpt = 0;

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void print_debug(int board[][SIZE], int mask_board[][SIZE], int line, int index)
{
    printf("Line: %d\n", line);
    printf("Index: %d\n", index);
    printf("Valeur: %d\n", board[line][index]);
    printf("Fixer: %d\n", mask_board[line][index]);
    printf("\n");

    print_board(board);
    printf("\n");
}

void print_tiret(int i)
{
    int j;

    j = 0;
    while (j < SIZE + 4)
    {
    //----sens des aiguilles d'une montre----

        if (j % (SIZE / 3 + 1) == 0)
        {
            if (i == 0 && j == 0)  //PREMIERE ligne, PREMIERE colonne
                ft_putchar('-');
            else if (i == 0 && j == SIZE + 4)  //PREMIERE ligne, DERNIERE colonne
                ft_putchar('-');
            else if (i == SIZE && j == SIZE + 4)  //DERNIERE ligne, DERNIERE colonne
                ft_putchar('-');
            else if (i == SIZE && j == 0)  //DERNIERE ligne, PREMIERE colonne
                ft_putchar('-');
            else if (i % 3 == 0 && j % (SIZE / 3 + 1) == 0)
            {
                if (i != 0 && i != SIZE)
                    if (j == 0 || j == SIZE + 4 - 1)
                        ft_putchar('|');
                    else
                        ft_putchar('+');
                else
                    ft_putchar('-');
            }
            else
                ft_putchar('-');
        }
        else
            ft_putchar('-');
        j++;
    }
    ft_putchar('\n');
}

void    print_board(int board[SIZE][SIZE])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i <= SIZE)
    {
        if (i % 3 == 0)
            print_tiret(i);
        while (j <= SIZE)
        {
            if (j % 3 == 0 && i < SIZE)
                ft_putchar('|');
            if (i < SIZE && j < SIZE)
                ft_putchar(board[i][j] + 48);
            j++;
        }
        ft_putchar('\n');
        j = 0;
        i++;
    }
}

void    create_mask_board(int board[][SIZE], int mask_board[][SIZE])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < SIZE)
    {
        while (j < SIZE)
        {
            if (board[i][j] > 0)
                mask_board[i][j] = 1;
            else
                mask_board[i][j] = 0;
            j++;
        }
        j = 0;
        i++;
    }
}

int is_fix(int mask_board[][SIZE], int line, int index)
{
    if (mask_board[line][index] == 1)
        return 1;
    return 0;
}

int is_constraint(int board[][SIZE], int line, int index)
{
    int i;
    int j;
    int taille_square;
    int o_line;
    int o_index;
    //check line
    i = 0;
    while (i < SIZE)
    {
        if (board[line][i] == board[line][index] && i != index)
            return 1;
        i++;
    }
    //check column
    i = 0;
    while (i < SIZE)
    {
        if (board[i][index] == board[line][index] && i != line)
            return 1;
        i++;
    }
    //check square
    i = 0;
    j = 0;
    taille_square = SIZE / 3;
    o_line = line / taille_square;
    o_index = index / taille_square;
    while (i < taille_square)
    {
        while (j < taille_square)
        {
            if (board[taille_square * o_line + i][taille_square * o_index + j] == board[line][index] \
                    && (taille_square * o_line + i != line) \
                    && (taille_square * o_index + j != index))
                return 1;
            j++;
        }
        j = 0;
        i++;
    }
    return 0;
}

void change_line(int *line, int *index)
{
    if (*index == SIZE)
    {
        *line += 1;
        *index = 0;
    }
}

int solveur(int board[][SIZE], int mask_board[][SIZE], int line, int index)
{
    if (line == SIZE && index == SIZE)
        return 1;

    change_line(&line, &index);
    while (is_fix(mask_board, line, index))
    {
        index++;
        change_line(&line, &index);
    }

    if (board[line][index] == 0)
        board[line][index] = 1;

    int value;

    while (line < SIZE)
    {
        value = 1;
        while (value <= SIZE)
        {
            if (!is_constraint(board, line, index))
            {
                //print_debug(board, mask_board, line, index);
                //if (line == 0 && index == 7 && board[line][index] == 9)
                    //ft_putchar('o');
                if (solveur(board, mask_board, line, index + 1))
                    return 1;
                else
                    board[line][index] += 1;
            }
            else
                board[line][index] += 1;
            value++;
            cpt++;
        }
        board[line][index] = 0;
        return 0;
    }
}

int main(void)
{
    int board[SIZE][SIZE] = {
        {0, 8, 9, 0, 0, 0, 0, 4, 0},
        {0, 0, 0, 7, 0, 8, 0, 6, 9},
        {0, 0, 0, 0, 0, 4, 3, 0, 1},
        {0, 1, 0, 9, 4, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {4, 0, 0, 0, 6, 7, 0, 1, 0},
        {8, 0, 1, 4, 0, 0, 0, 0, 0},
        {6, 4, 0, 3, 0, 2, 0, 0, 0},
        {0, 9, 0, 0, 0, 0, 1, 3, 0}
    };
    int mask_board[SIZE][SIZE];

    create_mask_board(board, mask_board);
    solveur(board, mask_board, 0, 0);
    print_board(board);
    printf("Nombre de valeurs changé dans ce sudoku: %d", cpt);
    return 0;
}
