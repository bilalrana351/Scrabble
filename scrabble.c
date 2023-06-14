#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

// Prototype for input of the players
void input(string player[2]);
// Prototype of function to convert lowercase to uppercase
void uppercase(string player[2]);
// Prototype for getting the numbers
int score(string player[2],int k[2]);
// Prototype for function to compare the numbers and print the result
void compare(int k[2]);

// Main Function
int main(void)
{
    string player[2];
    // Prompts for player 1 and player 2
    input(player);
    // Function to convert lowercase to uppercase
    uppercase(player);
    // Function for Giving values to numbers
    int k[2];
    score(player,k);
    // Funtion to compare the numbers and print the result
    compare(k);
}












// Code to prompt the players 1 and 2
    void input(string player[2])
    {
    player[0] = get_string("What is the word for player 1? ");
    player[1] = get_string("What is the word for player 2? ");
    }
 // Code to convert lowercase to uppercase
    void uppercase(string player[2])
    {
    for(int i=0; i<2; i++)
    {
       for(int j =0; player[i][j] != '\0'; j++)
       {
        if (islower(player[i][j]))
        {
           player[i][j] = toupper(player[i][j]);
        }
       }
    }
    }
// Code to calculate the two scores
int score(string player[2], int k[2])
  {
    k[0]=0;
    k[1]=0;
    for(int i=0; i<2; i++)
       {
         for(int j =0; player[i][j] != '\0'; j++)
         {
            char letter = player[i][j];
            if(strchr("AEILNORSTU", letter) !=NULL)
            {
               k[i] += 1;
            }
            if(strchr("DG", letter)!=NULL)
            {
               k[i] += 2;
            }
            if(strchr("BCMP", letter)!=NULL)
            {
               k[i] += 3;
            }
            if(strchr("FHVWY", letter)!=NULL)
            {
               k[i] += 4;
            }
            if(strchr("K", letter)!=NULL)
            {
               k[i] += 5;
            }
            if(strchr("JX", letter)!=NULL)
            {
               k[i] += 8;
            }
            if(strchr("Z", letter)!=NULL)
            {
               k[i] += 10;
            }
         }
       }
       return k[2];
  }
  // Code of function to compare the numbers and print the result
  void compare(int k[2])
  {
    if(k[0]>k[1])
    {
      printf("Player 1 wins!\n");
    }
    if(k[1]>k[0])
    {
      printf("Player 2 wins!\n");
    }
    else if(k[1]==k[0])
    {
      printf("Tie!\n");
    }
  }