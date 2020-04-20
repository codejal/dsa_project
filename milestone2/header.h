// HEADER FILE


/*Name of the group : PRASTAV
Members of the group :  Aakash Taneja - 19uec168 ,
						Aashita Agrawal - 19ucs160 , 
						Pranjal Gupta - 19ucs162 , 
                        Ritisha Garg - 19uec121 ,
                        Sai Shruti - 19ucc088 ,
                        Tanishka Garg - 19ume012 , 
                        Vedang Trivedi - 19uec070

Date the file was submitted : 15.02.2020

The purpose of the game program is to form a word using a bag of letters given as input. Not
every given letter in the bag is distinct; some letters may be present more than once.
The project program forms a word.
In this way a game which is like a popular game of Scrabble is formed. 

Details : There is main( ) where as input a bag of letters is provided and the word is formed
which is further checked from the dictionary that whether it is present in the dictionary or not. 
'Header.h' includes functions like 'from_bag', 'from_dictionary' , 'cal_weight' , 'cal_score'.
The function 'from_bag' collects the letters from the bag and the word. The function 'from_dictionary'
checks whether the word is present in th dictionary or is invalid. Funcion 'cal_weight' calculates the 
weight of the word from the provided points against each letter. The function 'cal_score' calculates the
score of the words .As output it is expected that the program will return the score of the word.
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
int from_bag(char letters[],char word_copy[]);
int from_dictionary(char word_copy[]);
int cal_weight(char word_copy[]);
int cal_score(int weight,int letter_len,int word_len);