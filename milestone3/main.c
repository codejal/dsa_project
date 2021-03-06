/*
MILESTONE 3
MAIN PROGRAM

Name of the group    :  PRASTAV

Members of the group :  19ucs160         Aashita Agrawal  
						19ucs162         Pranjal Gupta    
                        19uec070         Vedang Trivedi  
                        19uec168         Aakash Taneja    
                        19uec121         Ritisha Garg 
                        19ucc088         Sai Shruti
                        19ume012         Tanishka Garg   
                        
Date the file was submitted : 19.04.2020

The purpose of the game program is to form and declare the best word (word with maximum score) using a bag of letters given as input. 

DETAILS : In this milestone(3) we are given a bag of letters and are required to find a word from dictionary with maximum possible score.

METHOD : 
SWITCH CASE : The file with name i.txt contains all the words which have length>=2 and length<=i
*/

#include "header.h"
int main()
{
	char letters[20], word[20], word_copy[20], letter_copy[20], word_temp[20];
	int letter_len, weight = 0, score = -99999, word_len, score_temp, flag = 0;
	FILE *fp;

	printf("\nLET'S START THE GAME\nENTER THE LETTERS IN THE BAG : ");
	scanf("%s", letters);
	printf("ONE MOMENT PLEASE! I AM FINDING WORD/WORDS FOR YOU .... \n\n");
	clock_t begin = clock();

	letter_len = strlen(letters);

	assert(letter_len != 0);
	assert(letter_len != 1);
	assert(letter_len != 2);

	if (letter_len > 15)
		fp = fopen("dict03/15.txt", "r");
	else
		switch (letter_len)
		{
		case 3:
			fp = fopen("dict03/3.txt", "r");
			break;
		case 4:
			fp = fopen("dict03/4.txt", "r");
			break;
		case 5:
			fp = fopen("dict03/5.txt", "r");
			break;
		case 6:
			fp = fopen("dict03/6.txt", "r");
			break;
		case 7:
			fp = fopen("dict03/7.txt", "r");
			break;
		case 8:
			fp = fopen("dict03/8.txt", "r");
			break;
		case 9:
			fp = fopen("dict03/9.txt", "r");
			break;
		case 10:
			fp = fopen("dict03/10.txt", "r");
			break;
		case 11:
			fp = fopen("dict03/11.txt", "r");
			break;
		case 12:
			fp = fopen("dict03/12.txt", "r");
			break;
		case 13:
			fp = fopen("dict03/13.txt", "r");
			break;
		case 14:
			fp = fopen("dict03/14.txt", "r");
			break;
		case 15:
			fp = fopen("dict03/15.txt", "r");
			break;
		}
	strcpy(letter_copy, letters);
	while (fscanf(fp, "%s", word) != EOF)
	{
		strcpy(word_copy, word);

		if (from_bag(letter_copy, word_copy) == 1)
		{
			flag = 1;
			word_len = strlen(word);
			weight = cal_weight(word);
			score_temp = cal_score(weight, letter_len, word_len);

			if (score_temp > score)
			{
				score = score_temp;
				strcpy(word_temp, word);
				printf("           WORD  : %s\n", word_temp);
				printf("           SCORE : %d\n", score);
				printf("\n");
			}
		}
	}
	if (flag == 0)
		printf("OOOOPS!!! NO WORD IN DICTIONARY CAN BE FORMED FROM GIVEN LETTERS \n");
	else
		printf("'%s' is the best word I found for you with a score of %d for the give bag of letters '%s'\n", word_temp, score, letters);

	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Execution Time : %f sec \n ", time_spent);
	return 0;
}
