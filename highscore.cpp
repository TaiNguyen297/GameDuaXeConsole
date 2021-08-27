#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//struct HighScore{
//	int score;
//	char name[30];
//};
//HighScore highscore[5];
void getHighScore()
{
	FILE *score;
	score = fopen("HighScore.txt","a");
	if(score == NULL)
	{
		printf("File doesn't exist !");
		exit(0);
	}
	printf("Enter your score: ");
	fflush(stdin);
	
}
void showHighScore()
{
	int i;
	FILE *score;
	score = fopen("HighScore.txt","r");
	if(score == NULL)
	{
		printf("Can't open this file. This file doesn't exist.");
		exit(1);
	}
	printf("HIGH SCORE\n");
	fscanf (score, "%d", &i);    
    while (!feof (score))
    {  
      printf ("%d\n", i);
      fscanf (score, "%d", &i);      
    }
	fclose(score);
	
}
int main()
{
	showHighScore();
}
