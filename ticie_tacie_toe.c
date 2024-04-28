#include <stdio.h>

void intro()
{
    int example[] = { 0 , 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    printf("Welcome to the game of tic tac toe \n");
    print("hwhwhwh");
    printf("Following are the numbers corresponding place on the board \n");
    printf("%d | %d | %d \n", example[7], example[8], example[9]);
    printf("--|---|-- \n");
    printf("%d | %d | %d \n", example[4], example[5], example[6]);
    printf("--|---|-- \n");
    printf("%d | %d | %d \n", example[1], example[2], example[3]);
    printf("You may enter the number to place 'X' or 'O' in your turn \n");
}

void display(char moves[10])
{
    printf("%c | %c | %c\n", moves[7], moves[8], moves[9]);
    printf("--|---|-- \n");
    printf("%c | %c | %c\n", moves[4], moves[5], moves[6]);
    printf("--|---|-- \n");
    printf("%c | %c | %c\n", moves[1], moves[2], moves[3]);
}


int win_condition(char moves[], char player1, char player2, int played[], int allowed_moves[], int next_play, int z)
{
    int n = 1;
    while (n < 8)
    {
        if (moves[n] == moves[n + 1] == moves[n + 3] == player1)
        {
            printf("Player 1 won (horizontal) \n");
            printf("Sometimes you are never meant to win player 2!! \n");
            return 0;
        }
        else if (moves[n] == moves[n + 1] == moves[n + 3] == player2)
        {
            printf("Player 2 won (horizontal) \n");
            printf("Sometimes you are never meant to win player 1!! \n");
            return 0;
        }
        n = n + 3;
    }

    n = 1;
    while (n < 4)
    {
        if (moves[n] == moves[n + 3] == moves[n + 6] == player1)
        {
            printf("Player 1 won (vertical) \n");
            printf("Sometimes you are never meant to win player 2!! \n");
            return 0;
        }
        else if (moves[n] == moves[n + 3] == moves[n + 6] == player2)
        {
            printf("Player 2 won (vertical) \n");
            printf("Sometimes you are never meant to win player 1!! \n");
            return 0;
        }
        n = n + 1;


    }

    n = 1;

    if (moves[n] == moves[n + 4] == moves[n + 8] == player1)
    {
        printf("Player 1 won (diagonal)\n");
        printf("Better luck next time Player 2!\n");
        return 0;
    }

    else if (moves[n] == moves[n + 4] == moves[n + 8] == player2)
    {
        printf("Player 2 won (diagonal)\n");
        printf("Better luck next time Player 1!\n");
        return 0;
    }

    else if (moves[n + 2] == moves[n + 4] == moves[n + 6] == player1)
    {
        printf("Player 1 won (diagonal)\n");
        printf("Player 2 you can do better!\n");
        return 0;
    }

    else if (moves[n + 2] == moves[n + 4] == moves[n + 6] == player2)
    {
        printf("Player 2 won (diagonal)\n");
        printf("Player 1 you can do better!\n");
        return 0;
    }

    else if (z == 9)
    {
        printf("It's a tie!!\n");
        return 0;
    }

}

void select_player1(char moves[10], int played[], int z) {
    char player1, player2;
    printf("Player 1 ('X' or 'O'):");
    scanf(" %c", &player1);
    while (player1 != 'X' && player1 != 'O') {
        printf("Oops! Seems like you entered an invalid option\n");
        printf("Player 1 ('X' or 'O'):");
        scanf(" %c", &player1);
    }
    if (player1 == 'X') {
        player2 = 'O';
    } else {
        player2 = 'X';
    }
    printf("Player 1 is %c\n", player1);
    printf("Player 2 is %c\n", player2);
    display(moves[10]);
}

void play1(int played[], char player1, char player2, char moves[10], int z) {
    int move_played;
    printf("Player 1's Turn (1-9):");
    scanf("%d", &move_played);
    while (move_played < 1 || move_played > 9 || moves[move_played] != ' ') {
        printf("Oops! Seems like you entered an invalid move \nEnter a valid digit!\n");
        printf("Player 1's Turn (1-9):");
        scanf("%d", &move_played);
    }
    moves[move_played] = player1;
    display(moves[10]);
}

void play2(int played[], char player1, char player2, char moves[10], int z) {
    int move_played;
    printf("Player 2's Turn (1-9):");
    scanf("%d", &move_played);
    while (move_played < 1 || move_played > 9 || moves[move_played] != ' ') {
        printf("Oops! Seems like you entered an invalid move \nEnter a valid digit!\n");
        printf("Player 2's Turn (1-9):");
        scanf("%d", &move_played);
    }
    moves[move_played] = player2;
    display(moves[10]);
}



char play_again() {
    char again = "m";
    printf("Play again? (Y or N):");
    scanf("%c", &again);
    while (again != "Y" && again != "y" && again != "N" && again != "n") {
        printf("Oops! Seems like you entered an invalid option\n");
        printf("Play again? (Y or N):");
        scanf("%c", &again);
    }
    if (again == "N" || again == "n") {
        printf("Thanks for playing :)\n");
    }
    return again;
}

int main() {
    char again = 'Y';
    while (again == 'Y') {
        memset(moves, ' ', sizeof(moves));
        char moves[10] = { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
        intro();
        select_player1();
        int z = 0;
        while (1) {

            play1();
            z += 1;
            win_condition(z);
            play2();
            z += 1;
            win_condition(z);
        }
        again = play_again();
    }
    return 0;
}
