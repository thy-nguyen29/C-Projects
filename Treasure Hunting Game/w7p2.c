/*
*****************************************************************************
                          Workshop - #7 (P1)
Full Name  : Thy Nguyen
Student ID#: 105310221
Email      : nnguyen90@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_PATH_LEN 70
#define MULTIPLE 5
#define LIMIT 10
#define MIN_NUMBER 1


struct PlayerInfo
{
    char symbol;
    int lives;      
    int treasure;
    int nextMoves;
};
struct GameInfo
{
    int pathLength;
    int moves;
    int bombs[MAX_PATH_LEN];
    int treasure[MAX_PATH_LEN];
    char currentPosition[MAX_PATH_LEN];
};
int main()
{
    struct PlayerInfo player;
    struct GameInfo game;
    int i;
    char noHit = '-';
    
 

    printf("================================\n"
    "         Treasure Hunt!\n"
    "================================\n\n");

  // PLAYER CONFIGURATION PART

    printf("PLAYER Configuration\n"
    "--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.symbol);
    do
    {
        printf("Set the number of lives: ");                                                                            // Set lives number
        scanf(" %d", &player.lives);
        if (player.lives < MIN_NUMBER || player.lives > LIMIT)
        {
            printf("     Must be between 1 and %d!\n", LIMIT);
        }
    }while(player.lives < MIN_NUMBER || player.lives > LIMIT);
    printf("Player configuration set-up is complete\n\n");
    player.treasure = 0;

  // GAME CONFIGURATION PART

    printf("GAME Configuration\n"
    "------------------");
    do
    {
        printf("\nSet the path length (a multiple of %d between %d-%d): ", MULTIPLE, LIMIT, MAX_PATH_LEN);              // Set path length
        scanf(" %d", &game.pathLength);
        if ((game.pathLength % MULTIPLE != 0 ) || (game.pathLength < LIMIT || game.pathLength > MAX_PATH_LEN))
        {
            printf("     Must be a multiple of %d and between %d-%d!!!", MULTIPLE, LIMIT, MAX_PATH_LEN);
        }
    }while((game.pathLength % MULTIPLE != 0) || (game.pathLength < LIMIT || game.pathLength > MAX_PATH_LEN));
    do 
    {
        printf("Set the limit for number of moves allowed: ");                                                          // Set move limit
        scanf(" %d", &game.moves);
        if (game.moves < player.lives || (game.moves > game.pathLength * 0.75))
        {
            printf("     Value must be between %d and %2d\n", player.lives, (int)(game.pathLength * 0.75));
        }
    }while (game.moves < player.lives || (game.moves > game.pathLength * 0.75));

   // BOMB PLACEMENT PART

    printf("\nBOMB Placement\n"
    "--------------\n");
    printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n"
    "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    for (i = 0; i < game.pathLength; i += MULTIPLE)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        scanf(" %d %d %d %d %d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);
    }
    printf("BOMB placement set\n\n"

    // TREASURE PLACEMENT PART

    "TREASURE Placement\n"
    "------------------\n");
    printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n"
    "(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
    for (i = 0; i < game.pathLength; i += MULTIPLE)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
        scanf(" %d %d %d %d %d", &game.treasure[i], &game.treasure[i + 1], &game.treasure[i + 2], &game.treasure[i + 3], &game.treasure[i + 4]);
    }
    printf("TREASURE placement set\n\n"
    "GAME configuration set-up is complete...\n\n");

    // CONFIGURATION SETTING PART

    printf("------------------------------------\n"
    "TREASURE HUNT Configuration Settings\n"
    "------------------------------------\n"
    "Player:\n");
    printf("   Symbol     : %c\n", player.symbol);
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\nGame:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++) 
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < game.pathLength; i++) 
    {
        printf("%d", game.treasure[i]);
    }
    printf("\n\n====================================\n"
    "~ Get ready to play TREASURE HUNT! ~\n"
    "====================================");
    printf("\n");
    player.nextMoves == 0;
    do
    {
        printf("  ");
        for (i = 0; i < (player.nextMoves + 1); i++)                                                                                // LINE 1
        {
            if (player.nextMoves > 0 && i == (player.nextMoves - 1))
            {
                printf("%c", player.symbol);
            }
            else if (i != player.nextMoves)
            {
                printf(" ");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
        printf("  ");
        if (player.nextMoves > 0 && game.bombs[player.nextMoves - 1] == 1 && game.treasure[player.nextMoves - 1] == 0)              // LINE 2
        {
               game.currentPosition[player.nextMoves - 1] = '!';
        }
        else if (player.nextMoves > 0 && game.treasure[player.nextMoves - 1] == 1 && game.bombs[player.nextMoves - 1] == 0)
        {
            game.currentPosition[player.nextMoves - 1] = '$';
        }
        else if (player.nextMoves > 0 && game.bombs[player.nextMoves - 1] == 1 && game.treasure[player.nextMoves - 1] == 1)
        {
            game.currentPosition[player.nextMoves - 1] = '&';
        }
        else if (player.nextMoves > 0 && game.bombs[player.nextMoves - 1] == 0 && game.treasure[player.nextMoves - 1] == 0)
        {
            game.currentPosition[player.nextMoves - 1] = '.';
        }
        if (player.nextMoves < 1)
        {
            for (i = 0; i < (game.pathLength); i++)
            {
                printf("%c", noHit);
                game.currentPosition[i] = noHit;
            }
        }
        else
        {
            for (i = 0; i < (game.pathLength); i++)
            {
                printf("%c", game.currentPosition[i]);
            }
        }
        
       
        printf("\n");
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)                                                                                       // LINE 3
        {
            if (i > 0 && i % 10 == 0)
            {
                printf("%d", i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)                                                                                        // LINE 4
        {
            printf("%d", i % 10);
        }
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasure, game.moves);
        printf("+---------------------------------------------------+\n");
        if (player.lives > 0 && game.moves > 0)
        {
            do
            {
                printf("Next Move [%2d-%2d]: ", MIN_NUMBER, game.pathLength);
                scanf(" %d", &player.nextMoves);
                if (player.nextMoves < MIN_NUMBER || player.nextMoves > game.pathLength)
                {
                    printf("  Out of Range!!!\n");
                }
            } while (player.nextMoves < MIN_NUMBER || player.nextMoves > game.pathLength);
            if (game.currentPosition[player.nextMoves - 1] == noHit)
            {
                if (game.bombs[player.nextMoves - 1] == 0 && game.treasure[player.nextMoves - 1] == 0)
                {
                    printf("\n===============> [.] ...Nothing found here... [.]\n\n");
                    game.moves -= 1;
                }
                else if (game.bombs[player.nextMoves - 1] == 1 && game.treasure[player.nextMoves - 1] == 0)
                {
                    printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
                    game.moves -= 1;
                    player.lives -= 1;
                }
                else if (game.bombs[player.nextMoves - 1] == 0 && game.treasure[player.nextMoves - 1] == 1)
                {
                    printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
                    game.moves -= 1;
                    player.treasure += 1;
                }
                else if (game.bombs[player.nextMoves - 1] == 1 && game.treasure[player.nextMoves - 1] == 1)
                {
                    printf("\n===============> [&] !!! BOOOOOM !!! [&]"
                        "\n===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                    game.moves -= 1;
                    player.lives -= 1;
                    player.treasure += 1;
                }
            }
            else
            {
                printf("\n===============> Dope! You've been here before!\n");
            }
        }
    } while (player.lives != 0 && game.moves != 0);
    printf("\n");
    printf("No more LIVES remaining!\n\n");
  //-----------------------------------------------------------------------------------  
    for (i = 0; i < (player.nextMoves + 1); i++)                              
    {
        if (player.nextMoves > 0 && i == (player.nextMoves - 1))
        {
            printf("%c", player.symbol);
        }
        else if (i != player.nextMoves)
        {
            printf(" ");
        }
        else
        {
            printf(" ");
        }
    }
    printf("\n");

    if (player.nextMoves > 0 && game.bombs[player.nextMoves - 1] == 1 && game.treasure[player.nextMoves - 1] == 0)
    {
        game.currentPosition[player.nextMoves - 1] = '!';
    }
    else if (player.nextMoves > 0 && game.treasure[player.nextMoves - 1] == 1 && game.bombs[player.nextMoves - 1] == 0)
    {
        game.currentPosition[player.nextMoves - 1] = '$';
    }
    else if (player.nextMoves > 0 && game.bombs[player.nextMoves - 1] == 1 && game.treasure[player.nextMoves - 1] == 1)
    {
        game.currentPosition[player.nextMoves - 1] = '&';
    }
    else if (player.nextMoves > 0 && game.bombs[player.nextMoves - 1] == 0 && game.treasure[player.nextMoves - 1] == 0)
    {
        game.currentPosition[player.nextMoves - 1] = '.';
    }
    if (player.nextMoves < 1)
    {
        for (i = 0; i < (game.pathLength); i++)
        {
            printf("%c", noHit);
            game.currentPosition[i] = noHit;
        }
    }
    else
    {
        for (i = 0; i < (game.pathLength); i++)
        {
            printf("%c", game.currentPosition[i]);
        }
    }

    printf("\n");
    for (i = 1; i <= game.pathLength; i++)                              
    {
        if (i > 0 && i % 10 == 0)
        {
            printf("%d", i / 10);
        }
        else
        {
            printf("|");
        }
    }
    printf("\n");
    for (i = 1; i <= game.pathLength; i++)                              
    {
        printf("%d", i % 10);
    }
    printf("\n");
    printf("\n");
    printf("+---------------------------------------------------+\n");
    printf(" Lives: %2d | Treasures: %2d | Moves Remaining: %2d\n", player.lives, player.treasure, game.moves);
    printf("+---------------------------------------------------+\n\n");
    printf("##################\n");
    printf("# Game over! #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!!\n");

    return 0;
}
