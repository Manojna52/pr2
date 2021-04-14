#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include "fun.h"
#include<time.h>


void print(char ar[][5])
{
	int i,j;
		for(i=0;i<6;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c",ar[i][j]);
		}
		printf("\n");
	}
}
/**
 * @brief it gives the indexes at which the hangman characterrs should be drawn
 * @param wrong the number of times the user guessed it wrong
 * @return int 
 */
int i_value(int wrong)
{
	if(wrong==1)
	{
		return (2);
	}
	if(wrong==2)
	{
		return (3);
	}
	if(wrong==3)
	{
		return (4);
	}
	if(wrong==4)
	{
		return (3);
	}
	if(wrong==5)
	{
		return (3);
	}
	if(wrong==6)
	{
		return(5);
	}
	if(wrong==7)
	{
		return(5);
	}
}
/**
 * @brief similat to that of the above description
 * 
 * @param wrong 
 * @return int 
 */
int j_value(int wrong)
{
	if(wrong==1)
	{
		return (2);
	}
	if(wrong==2)
	{
		return(2);
	}
	if(wrong==3)
	{
		return (2);
	}
	if(wrong==4)
	{
		return (1);
	}
	if(wrong==5)
	{
		return(3);
	}
	if(wrong==6)
	{
		return (1);
	}
	if(wrong==7)
	{
		return(3);
	}
}
/**
 * @brief it checks if the character that is guessed is wrong or not
 * 
 * @param wtg word to guess
 * @param key the key pressed by the user to guess
 * @param length the length of the array
 * @param player the word that is displayed to the player after guess
 * @return int returns 1 if the word that is guessed is present if not it return2 0
 */
int check(char *wtg,char key,int length,char *player)
{
	int i=0,flag=0;
	for(i=0;i<length;i++)
	{
		if(*(wtg+i)==key)
		{
			*(player+i)=key;
			flag=1;
			
		}
	}
	if(flag==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/**
 * @brief it takes the users name
 * 
 * @param val it is a structure which contains the template of the users data 
 * @param num it talks about the number of plauyers
 */

void users_name(hangman_user *val,int num)
{
	int i=0;
	for(i=0;i<num;i++)
	{
		printf("%d users name:\n",i+1);
		scanf("%s",(val+i)->user_name);
	}
}


/**
 * @brief it prints the text image
 * 
 * @param fptr file pointer
 */
void print_image(FILE *fptr)
{
    char read_string[128];

    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}
/**
 * @brief it takes up the users details
 * 
 * @param val passing structure as a pointer
 */
void user_details(handcricket *val)
{
  printf(" user name:");
  scanf("%s",(val+0)->user_name);
   printf(" user place:");
  scanf("%s",(val+0)->user_place);
   printf(" user id an integer number:");
  scanf("%d",&(val+0)->user_id);
  
}
/**
 * @brief it keeps tract of the batting and the run scored
 * 
 * @param over the number of overs they are willing to play
 * @param chase the target that is given for chase
 * @param val it is used to keep in track whether the user is batting first or chasing
 * @return int 
 */
int bat(int over,int chase,int val)
{
  int run,score=0;
  printf("NOTE enter the shots between 1-6\n");
  for(int i=0;i<over*6;i++)
  {
 if(val==1)
 {
     if(score>chase)
     {
         break;
     }
 }
  printf("Enter the batting shots:");
  scanf("%d",&run);
  if(run>6)
  {
  
  printf("no ball");
score=score+1;
i=i-1;
  
}
/**
 * @brief Construct a new srand object 
 * it generates a random time
 * 
 */
  srand(time(NULL));
  int k=rand()%6;
  if(run==k)
  {
        char *filename = "Implementation/src/out.txt";
    FILE *fptr6 = NULL;

    if((fptr6 = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

    print_image(fptr6);

    fclose(fptr6);
    printf("\n");
   
    break;
  }
  else
  {
  if(run==4)
  {
     
      char *filename = "Implementation/src/four.txt";
    FILE *fptr5 = NULL;

    if((fptr5 = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

    print_image(fptr5);


    fclose(fptr5);
printf("\n");
  }
  if(run==6)
{
    
     char *filename = "Implementation/src/six.txt";
    FILE *fptr4 = NULL;

    if((fptr4 = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

    print_image(fptr4);

    fclose(fptr4);
    printf("\n");
    

}

}
 score+=run;
  }
  return score;
}
/**
 * @brief it talks about the bowling function
 * 
 * @param over the number of overs willing to play
 * @param chase if they are chasing the run they need to chase
 * @param val to check if the player is bowling first or second
 * @return int return the total score
 */
int bowl(int over,int chase,int val)
{
    
  int run,score=0;
  printf("NOTE enter the shots between 1-6\n");
  for(int i=0;i<over*6;i++)
  {
  
  printf("Enter the bowling runs:");
   if(val==1)
      {
          if(score>chase)
          {
              break;
          }
      }
  scanf("%d",&run);
   if(run>6)
  {
     
  
  printf("invlaid choice");
  exit (0);
}
/**
 * @brief Construct a new srand object
 * to generate a random number from 1 to 6
 * 
 */
  srand(time(NULL));
  int k=rand()%6;
  if(run==k)
  {
      /**
       * @brief to display a image text 
       * 
       */
      char *filename = "Implementation/src/out.txt";
    FILE *fptr1 = NULL;

    if((fptr1 = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

    print_image(fptr1);

    fclose(fptr1);
    printf("\n");
    break;
  }
  else{
  
  if(k==4)
  {
        
      char *filename = "Implementation/src/four.txt";
    FILE *fptr2 = NULL;

    if((fptr2 = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

    print_image(fptr2);

    fclose(fptr2);
    printf("\n");
  }
  if(k==6)
  {
char *filename = "Implementation/src/six.txt";
    FILE *fptr3 = NULL;

    if((fptr3 = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }

    print_image(fptr3);

    fclose(fptr3);
    printf("\n");
  }
  /**
   * @brief keeps track of the scores
   * 
   */
  score+=k;
}
  }
  return score;
}
  
