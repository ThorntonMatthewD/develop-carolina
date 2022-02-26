#include <stdio.h>

char board[10];

void displayBoard();
void resetBoard();

void markTile(int icon);
int checkWin();
int keepPlayingCheck(int *turnCount);


int main(int argc, char *argv[]) {

    int keepPlaying = 1;
    int player;
    int turnCount = 1; //Cannot win until 5th turn; max of 9 turns.

    int icon; //X (88) or O (79)

    //Populate board with dashes before playing. Otherwise things get weird...
    resetBoard();

    while(keepPlaying == 1) {

        player = (turnCount % 2) ? 1 : 2;
        icon = (player == 1) ? 88 : 79; //using char ints

        displayBoard();

        markTile(icon);

        if (turnCount == 9) {
            if (checkWin() == 1) {
                printf("\nCongratulations Player %d! You've won!!\n", player);
                displayBoard();
                keepPlaying = keepPlayingCheck(&turnCount);
            } else {
                printf("Looks like we have a tie on our hands. In others words, you both lose! Yay!\n");
                keepPlaying = keepPlayingCheck(&turnCount);
            }
        } else if (turnCount >= 5) {
            if (checkWin() == 1) {
                printf("\nCongratulations Player %d! You've won!!\n", player);
                displayBoard();
                keepPlaying = keepPlayingCheck(&turnCount);
            } else {
                turnCount = turnCount + 1;
            }
        } else {
            turnCount = turnCount + 1;
        }
    }
}


void displayBoard() {
    int i;

    printf("-------------\n");

    for (i = 0; i < (sizeof(board) / sizeof(*board) - 1); i = i + 3) {
        printf("| %c | %c | %c |\n", board[i], board[i + 1], board[i + 2]);
        printf("-------------\n");
    }
}


void resetBoard() {
    int i;

    for(i = 0; i < 10; i = i + 1) {
        board[i] = 45;
    }
}


void markTile(int icon) {
    int markComplete = 0;
    int tilePlacement = -1;

    while (markComplete == 0) {
        printf("Enter the tile you'd like to place your marker on (0-8): ");
        if (scanf("%d", &tilePlacement) == 1) {
            if (tilePlacement >= 0 && tilePlacement <= 8) {
                //check for if tile is already taken
                if (board[tilePlacement] == 45) {
                    board[tilePlacement] = icon;
                    markComplete = 1;
                } else {
                    printf("[Input Error] There is already a marker on tile %d. Please select another.\n\n");
                }
            } else {
                printf("[Input Error] You entered an integer, but not within the valid range. Pick a number 0-8.\n\n");
            }
        } else {
            printf("[Input Error] Enter a valid integer (0-8)\n\n");
        }
    }
}


int checkWin() {
    //Diagonal win check
    if (board[4] != 45) {
        if ((board[0] == board[4]) && (board[4] == board[8])) {
            return 1;
        } else if ((board[2] == board[4]) && (board[4] == board[6])) {
            return 1;
        } else {
            //No diagonal win! Keep looking.
        }
    }

    int i;

    //Horizontal win check
    //For a horizontal win you need one of these tiles filled in.
    int h_depends[3] = {1, 4, 7};

    for (i = 0; i < (sizeof(h_depends) / sizeof(*h_depends)); i = i + 1) {
        if ((board[h_depends[i] - 1] == board[h_depends[i]]) 
                && (board[h_depends[i]] == board[h_depends[i] + 1])
                && (board[h_depends[i]] != 45)
        ) {
            return 1;
        } else {
            //Didn't find any horizontal wins. Better check for verticals!
        }
    }

    //Vertical win check
    //For a vertical win you need one of these tiles filled in.
    int v_depends[3] = {3, 4, 5};

    for (i = 0; i < (sizeof(v_depends) / sizeof(*v_depends)); i = i + 1) {
        if ((board[v_depends[i] - 3] == board[v_depends[i]]) 
                && (board[v_depends[i]] == board[v_depends[i] + 3])
                && (board[v_depends[i]] != 45)
        ) {
            return 1;
        } else {
            //Didn't find any vertical wins either.
        }
    }

    //No win! Keep playing!
    return 0;
}

int keepPlayingCheck(int *turnCount) {
    char response;

    printf("Enter Y to play again. Enter literally anything else to stop playing: ");

    if (scanf("%d", &response) == 1) {
        if (response== 121 || response== 89) {
            resetBoard();
            *turnCount = 1;
            return 1;
        }
    }

    printf("\nThanks for playing!");
    return 0;
}
