#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char moves[10] = { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char played[10];
char allowed_moves[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char player1, player2;

void intro() {
    printf("Welcome to the game of tic tac toe\n");
    printf("Following are the numbers corresponding place on the board\n");
    printf("7 | 8 | 9\n");
    printf("--|---|-- \n");
    printf("4 | 5 | 6\n");
    printf("--|---|-- \n");
    printf("1 | 2 | 3\n");
    printf("You may enter the number to place 'X' or 'O' in your turn\n");
}

void display() {
    printf("%c | %c | %c\n", moves[7], moves[8], moves[9]);
    printf("--|---|-- \n");
    printf("%c | %c | %c\n", moves[4], moves[5], moves[6]);
    printf("--|---|-- \n");
    printf("%c | %c | %c\n", moves[1], moves[2], moves[3]);
}

void select_player1() {
    printf("Player 1 ('X' or 'O'):");
    scanf(" %c", &player1);
    while (player1 != 'X' && player1 != 'O') {
        printf("Oops! Seems like you entered an invalid option\n");
        printf("Player 1 ('X' or 'O'):");
        scanf(" %c", &player1);
    }
    if (player1 == 'X') {
        player2 = 'O';
    }
    else {
        player2 = 'X';
    }
    printf("Player 1 is %c\n", player1);
    printf("Player 2 is %c\n", player2);
    display();
}

void play1() {
    int move_played;
    printf("Player 1's Turn (1-9):");
    scanf("%d", &move_played);
    while (move_played < 1 || move_played > 9 || moves[move_played] != ' ') {
        printf("Oops! Seems like you entered an invalid move \nEnter a valid digit!\n");
        printf("Player 1's Turn (1-9):");
        scanf("%d", &move_played);
    }
    moves[move_played] = player1;
    display();
}

void play2() {
    int move_played;
    printf("Player 2's Turn (1-9):");
    scanf("%d", &move_played);
    while (move_played < 1 || move_played > 9 || moves[move_played] != ' ') {
        printf("Oops! Seems like you entered an invalid move \nEnter a valid digit!\n");
        printf("Player 2's Turn (1-9):");
        scanf("%d", &move_played);
    }
    moves[move_played] = player2;
    display();
}

int win_condition() {
    int n = 1;
    while (n < 8) {
        if (moves[n] == moves[n + 1] && moves[n + 1] == moves[n + 2] && moves[n + 2] == player1) {
            printf("Player 1 won (horizontal)\n");
            printf("Sometimes you are never meant to win player 2!!\n");
            return 0;
        }
        else if (moves[n] == moves[n + 1] && moves[n + 1] == moves[n + 2] && moves[n + 2] == player2) {
            printf("Player 2 won (horizontal)\n");
            printf("👀👀\n");
            return 0;
        }
        n = n + 3;
    }

    n = 1;
    while (n < 4) {
        if (moves[n] == moves[n + 3] && moves[n + 3] == moves[n + 6] && moves[n + 6] == player1) {
            printf("Player 1 won (vertical)\n");
            printf("Sometimes you are never meant to win player 2!!\n");
            return 0;
        }
        else if (moves[n] == moves[n + 3] && moves[n + 3] == moves[n + 6] && moves[n + 6] == player2) {
            printf("Player 2 won (vertical)\n");
            return 0;
        }
        n = n + 1;
    }

    n = 1;
    if (moves[n] == moves[n + 4] && moves[n + 4] == moves[n + 8] && moves[n + 8] == player1) {
        printf("Player 1 won (diagonal)\n");
        printf("👀👀\n");
        return 0;
    }
    else if (moves[n] == moves[n + 4] && moves[n + 4] == moves[n + 8] && moves[n + 8] == player2) {
        printf("Player 2 won (diagonal)\n");
        return 0;
    }
    else if (moves[n + 2] == moves[n + 4] && moves[n + 4] == moves[n + 6] && moves[n + 6] == player1) {
        printf("Player 1 won (diagonal)\n");
        printf("Sometimes you are never meant to win player 2!!\n");
        return 0;
    }
    else if (moves[n + 2] == moves[n + 4] && moves[n + 4] == moves[n + 6] && moves[n + 6] == player2) {
        printf("Player 2 won (diagonal)\n");
        return 0;
    }
    else {
        int i;
        for (i = 1; i < 10; i++) {
            if (moves[i] == ' ') {
                return 1;
            }
        }
        printf("It's a tie!!\n");
        printf("👀👀\n");
        return 0;
    }
}

char play_again() {
    char again[2];
    printf("Play again? (Y or N):");
    scanf("%s", again);
    while (strcmp(again, "Y") != 0 && strcmp(again, "N") != 0) {
        printf("Oops! Seems like you entered an invalid option\n");
        printf("Play again? (Y or N):");
        scanf("%s", again);
    }
    if (strcmp(again, "N") == 0) {
        printf("Thanks for playing :)\n");
    }
    return again[0];
}

int main() {
    char again = 'Y';
    while (again == 'Y') {
        memset(moves, ' ', sizeof(moves));
        moves[0] = '#';
        intro();
        select_player1();
        int something = 1;
        while (something == 1) {
            play1();
            something = win_condition();
            if (something == 1)
            {
                play2();
                something = win_condition();
            }
        }
        again = play_again();
    }
    return 0;
    }
