// Toss Up Game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>


typedef char * string;


int main(int argc, const char* argv[]){
    

    // Initialize Variables
	int rolls;
	int dice_num;
	int r; 
	int y;
	int i;
        char again;
	
	int win = 0;
	int lose = 0;
	int green = 0;
	int red = 0;
	char *die;
        
    // Random Number

	srand(time(NULL));
        
        
    // Create Dice Array    

	string dice[6];
	
    // Set Colors On Dice Based On Actual Game
        
	dice[0] = "red";
	dice[1] = "yellow";
	dice[2] = "yellow";
	dice[3] = "green";
	dice[4] = "green";
	dice[5] = "green";
        
        
    // Introduce Game
        
        std::cout << "Welcome to \"Toss Up\" the Dice Game!\n";
        std::cout << "The rules are simple : \n";
        std::cout << "Choose the amount of times you want to roll and how many dice you want to use.\n";
        std::cout << "If you roll any Greens that is a win.\n";
        std::cout << "If you roll a Yellow, but there is also a Green that is a win.\n";
        std::cout << "If you roll any Reds and no Greens, that is considered a loss. :(\n";
        std::cout << "Lets Get Started!\n";
        
        
    // Game Loop
        
        do {

            if(argc < 2 ){
                    printf("\nHow many times do you want to roll?\n");
                    scanf("%d", &rolls);

                    printf("How many dice do you want to roll?\n");
                    scanf("%d", &dice_num);
            }
            else{
                    rolls = atoi(argv[1]);
                    dice_num = atoi(argv[2]);
            }
            for (i=rolls;i > 0;i--){
                    for (y=dice_num;y > 0;y--){
                            r=rand()%6;
                            die = dice[r];
                            printf("%s,",die);
                            if(die == "green"){
                                    green++;
                            }
                            else if(die == "red"){
                                    red++;
                            }
                    }
                    //printf("green: %d\nred: %d\n",green,red);
                    printf("\n");
                    if( green == 0 && red > 0 ){
                            lose++;
                    }
                    else{
                            win++;
                    }
                    red=0;
                    green=0;
            }	
            
        // Output Game Results

            printf("Wins: %d\nLoses: %d\n",win,lose);
            
        // Prompt play again
            
            std::cout <<"\nWould you like to play again?\n" << "(Y/N): ";
            std::cin >> again;
        }
        while(again == 'y' || again == 'Y');

	return 0;
}