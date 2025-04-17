#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIN_POSITION 100
int check_snake_ladder(int position) {
    if (position == 3) return 22;
    if (position == 5) return 8;
    if (position == 11) return 26;
    if (position == 20) return 29;
    if (position == 27) return 1;
    if (position == 21) return 9;
    if (position == 17) return 4;
    if (position == 19) return 7;

    return position;
}
int roll_dice() {
    return (rand() % 6) + 1;
}

void play_game() {
    int player1 = 0, player2 = 0;
    int turn = 1;
    char ch;

    srand(time(NULL));

    while (player1 < WIN_POSITION && player2 < WIN_POSITION) {
        printf("\nPlayer %d's turn. Press Enter to roll the dice...", turn);
        getchar();

        int dice = roll_dice();
        printf("Player %d rolled a %d\n", turn, dice);

        if (turn == 1) {
            player1 += dice;
            if (player1 > WIN_POSITION) player1 -= dice;
            player1 = check_snake_ladder(player1);
            printf("Player 1 is now at position %d\n", player1);
            if (player1 == WIN_POSITION) {
                printf("\n🎉 Player 1 wins!\n");
                break;
            }
            turn = 2;
        } else {
            player2 += dice;
            if (player2 > WIN_POSITION) player2 -= dice;
            player2 = check_snake_ladder(player2);
            printf("Player 2 is now at position %d\n", player2);
            if (player2 == WIN_POSITION) {
                printf("\n🎉 Player 2 wins!\n");
                break;
            }
            turn = 1;
        }
    }
}

int main() {
    printf("🎲 Welcome to Snake and Ladder Game!\n");
    play_game();
    return 0;
}
