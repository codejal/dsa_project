//MILESTONE 2
//IMPLEMENTATIONS OF FUNCTIONS

/*Name of the group : PRASTAV
Members of the group :  19ucs160         Aashita Agrawal  
			19ucs162         Pranjal Gupta    
                        19uec070         Vedang Trivedi  
                        19uec168         Aakash Taneja    
                        19uec121         Ritisha Garg 
                        19ucc088         Sai Shruti
                        19ume012         Tanishka Garg   
                        

Date the file was submitted : 06.03.2020

The purpose of the game program is to form a word using a bag of letters given as input. Not
every given letter in the bag is distinct; some letters may be present more than once.
The project program forms a word.


In this way a game which is like a popular game of Scrabble is formed. 

DETAILS: In this milestone(2) we are given a bag of letters and are required to find a word from dictionary with maximum possible score.

METHOD: FUNCTION from_bag() : This function checks whether a given word can be formed from given bag of letters 
							  we take input of this function as letters and a word from dictionary , then we replace all common letters from word with hashtags('#')
							  and if alll the the letters of word are replaced by hashtags then the word can be formed from given letters. If this conditin is true
							  we return checkmark 1 else 0.
							  
							  since we have weight =0 for all the symbols(*) used as letters to form word count the number of such symbols by replacing all possible 
							  candidates withs slash('/') and calculate weight after subtracting this slash count from it.
*/

#include "header.h"
int slash = 0;
int from_bag(char letters[], char word_copy[])
{
	int w = 0, j = 0, i = 0, star_count = 0, letters_length = 0, only_letters = 0, word_length = 0;
	int hash_count = 0, checkmark = 0;
	char word[30];
	char temp;
	slash = 0;

	//cal. lenghts of lettes entered and word entered
	letters_length = strlen(letters);
	word_length = strlen(word_copy);
	if (word_length > letters_length)
		return checkmark = 0;

	else
	{
		//counting no of * if any
		for (i = 0; i < letters_length; i++)
		{
			if (letters[i] == '*')
				star_count++;
		}
		only_letters = letters_length - star_count;

		//sorting letters including * with letters reversed
		//stars at end since ascii of *=42
		for (i = 0; i < letters_length; i++)
			for (j = i + 1; j < letters_length; j++)
				if (letters[i] < letters[j])
				{
					temp = letters[j];
					letters[j] = letters[i];
					letters[i] = temp;
				}

		//final sorted letters
		for (i = 0; i < only_letters; i++)
			for (j = i + 1; j < only_letters; j++)
				if (letters[i] > letters[j])
				{
					temp = letters[j];
					letters[j] = letters[i];
					letters[i] = temp;
				}

		//converting entered letters to uppercase from lowercase if any
		for (i = 0; i < only_letters; i++)
		{
			if (letters[i] >= 'a' && letters[i] <= 'z')
				letters[i] -= 32;
		}

		strcpy(word, word_copy);
		int flag = 1;
		char letters_copy[30];
		strcpy(letters_copy, letters);

		//comparing string
		//no stars included
		for (i = 0; i < letters_length; i++)
			for (j = 0; j < word_length; j++)
				if (letters[i] != '*' && letters[i] == word[j])
				{
					word[j] = '#';
					break;
				}

		//with star
		for (i = 0; i < letters_length; i++)
		{
			for (w = 0; w < word_length; w++)
				if (letters[i] == '*' && (word[w] == 'A' || word[w] == 'E' || word[w] == 'I' || word[w] == 'O' || word[w] == 'U'))
				{
					word[w] = '#';
					slash = slash + 1;
					break;
				}
		}
		//slash count
		for (i = 0; i < letters_length; i++)
		{
			if (letters_copy[i] == '/')
				slash = slash + 1;
		}
		//checking first condition if word is from letters
		//counting hashtags

		for (i = 0; i < word_length; i++)
		{
			if (word[i] == '#')
				hash_count = hash_count + 1;
		}

		if (hash_count == word_length)
			checkmark = 1;
		else
		{
			checkmark = 0;
		}
	}
	return checkmark;
}

//CALCULATING WEIGHT OF THE LETTER
int cal_weight(char word_copy[])
{
	int i = 0, weight = 0;
	while (word_copy[i] != '\0')
	{
		if (word_copy[i] == 'E' || word_copy[i] == 'A' || word_copy[i] == 'I' || word_copy[i] == 'O' || word_copy[i] == 'N' || word_copy[i] == 'R' || word_copy[i] == 'T' || word_copy[i] == 'L' || word_copy[i] == 'S' || word_copy[i] == 'U')
			weight = weight + 1;
		if (word_copy[i] == 'D' || word_copy[i] == 'G')
			weight = weight + 2;
		if (word_copy[i] == 'B' || word_copy[i] == 'C' || word_copy[i] == 'M' || word_copy[i] == 'P')
			weight = weight + 3;
		if (word_copy[i] == 'F' || word_copy[i] == 'H' || word_copy[i] == 'V' || word_copy[i] == 'W' || word_copy[i] == 'Y')
			weight = weight + 4;
		if (word_copy[i] == 'K')
			weight = weight + 5;
		if (word_copy[i] == 'J' || word_copy[i] == 'X')
			weight = weight + 8;
		if (word_copy[i] == 'Q' || word_copy[i] == 'Z')
			weight = weight + 10;
		i++;
	}
	//SUBTRACTING THE NO OF STARS THAT CANCELED THE LETTERS BECAUSE THEIR SCORE IS BEING INCLUDED FOR EACH = 1
	return (weight - slash);
}

//CALCULATING FINAL SCORE
int cal_score(int weight, int letter_len, int word_len)
{
	int good = 0, bad = 0, mult = 0, score = 0;
	good = (letter_len - 1) * word_len;
	bad = 3 * (letter_len + 1 - word_len);
	if (bad < 1)
		bad = 1;
	mult = good - bad;
	//score
	score = (weight)*mult;
	return score;
}
