/******************************************************************************
Anagram Game Using C

Aim : Created anagram game using c.
Programmer : Jaimik Chauhan
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int print_Random(int lower, int upper,  int count) 
{ 
    int i; 
    for (i = 0; i < count; i++) { 
        int num = (rand() % (upper - lower + 1)) + lower; 
        return num;
    }
} 
void sort(char str[]){
	int i, j, temp;
	int len = strlen(str);
	
	for(i = 0; i < len; i++){
		for(j = 0; j < len; j++){
			if(str[i] < str[j]){
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
}
void check_anagram(char user_entered[], char stored_string[],char original_string[]){
	char try1[3];
	//printf("user %s, stored %s",user_entered,stored_string);
	if(strcmp(user_entered,stored_string) == 0){
		printf("	***** Anagram Is Correct *****\n");
	}
	else if(strcmp(user_entered,original_string) == 0){
		printf("	_____ Both Words are same _____\n");
	}
	else{
		printf("	----- Anagram Is Wrong -----\n");
	}
	printf("		Try Again Same Anagram? (y/n)	");
	scanf("%s",&try1);
	//printf("\n");
	if(strcmp(try1,"y") == 0 || strcmp(try1,"Y") == 0){
		same_anagram(stored_string,original_string);
	}
	else if(strcmp(try1,"n") == 0 || strcmp(try1,"N") == 0){
		return;
	}
	else{
		//printf("%s \n",try1);
	}
}
void same_anagram(char stored_string[],char original_string[]){
	char w[25], sorted[25];

	printf("	Enter anagram of %s	 ",original_string);
	scanf("%s",&w);
	check_anagram(w,stored_string,original_string);	
}
void main(){
	int no, i, j, choice, user_no;
	char* words[10][25];
	char w[25], stored_string[30];

	int print_Random(int lower, int upper, int count);
	void sort(char str[]);
	void check_anagram(char user_entered[],char stored_string[],char original_string[]);
	void same_anagram(char stored_string[],char original_string[]);
	
	printf("Enter No. of words you want to Enter (Enter Minimum 5 number to enjoy game)  ");
	scanf("%d",&no);
	
	for(i = 0; i < no ; i++){
		printf("Words %d  ",i+1);
		scanf("%s",&words[i]);
	}
	printf("\n");
	
	while(1){
		//menu
		printf("\n***** Menu **********\n");
		printf("1.Start Game\n");
		printf("2.View Entered Words\n");
		printf("3.Exit\n");
		printf("***********************\n");
		printf("\nEnter Menu Choice	");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				user_no = print_Random(1,no-1,1); 
				//stored_string = words[user_no];
				printf("	Enter anagram of %s	",words[user_no]);
				scanf("%s",&w);
				if(strcmp(words[user_no],w) == 0){
					printf("		_____ Both Words are same _____\n");
				}	
				else{
					char stored_string[35], copy_stored_string[35];
					strcpy(copy_stored_string,words[user_no]);
					strcpy(stored_string,words[user_no]);
					sort(w);
					sort(stored_string);
					check_anagram(w,stored_string,copy_stored_string);
				}
				break;
			case 2:
				for(i = 0; i < no; i++){
					printf("%d : %s\n",i+1,words[i]);
				}
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("		Enter Correct Choice\n");
		}
	}
}

