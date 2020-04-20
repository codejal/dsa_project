//MAIN PROGRAM
#include "header.h"
int main()
{
    int checkmark=0;
    char letters[30],word_copy[20];

//scanning word and letters(including *)
    printf("Put the letters in my bag : ");
    scanf("%s",letters);
    printf("Enter the word to start the game : ");
    scanf("%s",word_copy);
    letter_len=strlen(letters);
    word_len=strlen(word_copy);

//changing lowercase to uppercase in word entered if any
	for(i=0;i<word_length;i++)
	{
		if(word_copy[i]>='a' && word_copy[i]<='z')
		word_copy[i]-=32;
	}


	checkmark=from_bag(letters,word_copy);
	if(checkmark==1)
	{
		checkmark=from_dictionary(word_copy);
	
		if(checkmark==2)
		{
			weight=cal_score(word_copy);
			score=cal_score(weight,letter_len,word_len);
		}
		else
		{
			printf("OOPSSS!! WORD NOT FOUND IN DICTIONARY");
			exit(0);
	}
	else
	{
		printf("OOPSSS!! WORD NOT FORMED BY LETTERS IN BAG");
		exit(0);
	}
	printf("YAAAAYY!!! GIVEN WORD IS VALID");
	printf("SCORE OF THE GIVEN WORD IS : %d",score);
	return 0;
}



