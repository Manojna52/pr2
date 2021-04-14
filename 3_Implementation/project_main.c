/**
 * @file hangman_game.c
 * @author Manojna (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "fun.h"
#include<time.h>
/**
 * @brief structure that keeps the users data and word given by him
 * and also keeps track of the points
 * 
 */


int main()
{
	printf("enter into mini arcade");
	int choice;
	printf("enter one to play hangman and two to play handcricket");
	scanf("%d",&choice);
	if(choice==1)
	{
	int num_p,i=1;
	int num_p_c;
	 char *filename = "Implementation/src/image.txt";
    FILE *fptr = NULL;


	printf("WELCOME TO HANGMAN\n");
	if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

    print_image(fptr);

    fclose(fptr);

	printf("enter the number of players\n");
	scanf("%d",&num_p);
	num_p_c=num_p;
	hangman_user *players;
	/**
	 * @brief takes the input of number of players who are playing
	 * 
	 */
	players=(hangman_user *)calloc(num_p,sizeof(hangman_user));
	printf("enter players name\n");
	users_name(players,num_p);
	/**
	 * @brief initialising the users point as zero
	 * 
	 */
	for(i=0;i<num_p;i++)
	{
		players[i].user_p=0;
	}
	
	printf("enter the number of rounds\n");
	int num_rounds;
	int round=0;
	
	scanf("%d",&num_rounds);
	/**
	 * @brief this loop will continue for the number of ounds that was given
	 * 
	 */
	while(num_rounds--)
	{
		int k=0;
		
		printf("round=%d\n",round+1);
		/**
		 * @brief this loop will continue for the number of players
		 * 
		 */
		while(num_p--)
		{
			/**
			 * @brief to initialize array after each player has completed his turn
			 * 
			 */
			char arr[6][5]={' ',' ','_','_','_',
						' ',' ','|',' ','|',
						' ',' ',' ',' ','|',
						' ',' ',' ',' ','|',
						' ',' ',' ',' ','|',
						' ',' ',' ',' ','|'};
		printf("%s turn\n",players[k].user_name);
		
		char word_t_guess[100];
		int tries=6,j=0,tries_p=6;
		int lenght_of_word,wrong_g=0;
			printf("\nenter the word to guess and make sure the one whose turn is not seeing this\n");
			scanf("%s",word_t_guess);
			system("cls");
			lenght_of_word=strlen(word_t_guess);
			char *player_word;
			player_word=(char *)calloc(lenght_of_word,sizeof(char));
		
			for(i=0;i<lenght_of_word;i++)
			{
				player_word[i]='-';
			}
		/**
		 * @brief this loop will take care of the number of tries that id pending
		 * 
		 */
			while(j<tries)
			{
				char a[2],check1=0;
				printf("\n%d tries pending\n",tries_p);
				printf("enter the character you are guessing  should nt be a number\n");
				scanf("%s",a);
			
				check1=check(word_t_guess,a[0],lenght_of_word,player_word);
				/**
				 * @brief Construct a new if object
				 * if the guessed character is present in the word 
				 * 
				 */
				if(check1==1)
				{
					printf("good work\n");
						printf("%s\n",player_word);
						print(arr);
						if(strcmp(player_word,word_t_guess)==0)
						{
							printf("%s guessed it right\n",players[k].user_name);
							players[k].user_p+=10;
							break;
						}
						
				}
				/**
				 * @brief if the guessed character is not present in the word
				 * 
				 */
				else
				{
					int pos1,pos2;
					wrong_g++;
					/**
					 * @brief Construct a new if object
					 * the if is used to draw the hagman each time the user failes to guess the word
					 * 
					 */
					if(wrong_g==1)
					{
						pos1=i_value(wrong_g);
						pos2=j_value(wrong_g);
						arr[pos1][pos2]='O';

					}
					else if(wrong_g==2)
					{
						pos1=i_value(wrong_g);
						pos2=j_value(wrong_g);
						arr[pos1][pos2]='|';
						wrong_g++;
						pos1=i_value(wrong_g);
						pos2=j_value(wrong_g);
						arr[pos1][pos2]='|';
					}
					else if(wrong_g==4)
					{
						pos1=i_value(wrong_g);
						pos2=j_value(wrong_g);
						arr[pos1][pos2]='/';
					}
					else if(wrong_g==5)
					{
						pos1=i_value(wrong_g);
						pos2=j_value(wrong_g);
						arr[pos1][pos2]='\\';
					}
					else if(wrong_g==6)
					{
						pos1=i_value(wrong_g);
						pos2=j_value(wrong_g);
						arr[pos1][pos2]='/';
					}
					else if(wrong_g==7)
					{
						pos1=i_value(wrong_g);
						pos2=j_value(wrong_g);
						arr[pos1][pos2]='\\';
					}
					printf("not quite\n");
					printf("%s\n",player_word);
					print(arr);
					tries_p=tries_p-1;
					j=j+1;
				}
				}
			k=k+1;
			if(j>=tries)
			{
				printf(" BETTER LUCK NEXT TIME\n");
				printf("the correct word is %s\n",word_t_guess);
			}
}
		round++;
		printf("the scores after %d round is\n",round);
		int m=0;
		for(m=0;m<num_p_c;m++)
		{
			printf("%s score =%d\n",players[m].user_name,players[m].user_p);
		}
		
	}
	 char *filename1 = "Implementation/src/win.txt";
    FILE *fptr1 = NULL;


	
	if((fptr1 = fopen(filename1,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename1);
        return 1;
    }

    print_image(fptr1);

    fclose(fptr1);
	}
	else if (choice==2)
	{
		 int bat_score=0,bowl_score=0;
  printf("\nWELCOME TO HANDCRICKET GAME\n");
  /**
   * @brief to display the image text
   * 
   */
  char *filename = "Implementation/src/handcricket.txt";
    FILE *fptr7 = NULL;

    if((fptr7 = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

    print_image(fptr7);

    fclose(fptr7);

  handcricket *player;
  player=(handcricket *) malloc(1*sizeof(handcricket));
  printf("\nEnter the player details:\n");
  user_details(player);
  int over;
  printf("Enter the number of overs\n:");
  scanf("%d",&over);
  printf("choose between batting and bowling\n");
  printf("To bat select 1 , to bowl select 2\n");
  printf("enter your choice(1 or 2):");
  int x;
  scanf("%d",&x);

  if(x==1)
  
  {printf("%s choose to bat, Hit our shots\n",player->user_name) ;
  bat_score=bat(over,0,0);
    printf("%s score is %d\n",player->user_name,bat_score);
    printf("%s Its time to bowl\n",player->user_name) ;
    bowl_score=bowl(over,bat_score,1);
    printf("computer score is %d",bowl_score);
    
  }
  else if(x==2)
  
  {printf("%s choose to bowl\n",player->user_name) ;
   bowl_score=bowl(over,0,0);
    printf("computer score is %d\n",bowl_score);
    printf("%s time to bat, Hit our shots\n",player->user_name) ;
    bat_score=bat(over,bowl_score,1);
    printf("%s score is %d\n",player->user_name,bat_score);
    
  }
  if(bat_score>bowl_score)
  {
    printf("%s congrats you won the match\n",player->user_name);
  }
  else
  printf("computer won the match \n %s better luck next time\n",player->user_name);
  
	}
	else
	{
		printf("enter a valid number");
	}
	
}
