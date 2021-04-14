#ifndef __FUN_H__
#define __FUN_H__
typedef struct 
{
	char user_name[100];
	char user_w[100];
	int user_p;
}hangman_user;

void print(char ar[][5]);
int i_value(int wrong);
int j_value(int wrong);
int check(char *wtg,char key,int length,char *player);
void users_name(hangman_user *val,int num);
void print_image(FILE *fptr);

typedef struct
{
  char user_name[100];
   char user_place[100];
int user_id;
}handcricket;
void print_image(FILE *fptr);
void user_details(handcricket *val);
int bat(int over,int chase,int val);
int bowl(int over,int chase,int val);
#endif