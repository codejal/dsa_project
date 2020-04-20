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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
int from_bag(char letters[], char word_copy[]);
int cal_weight(char word_copy[]);
int cal_score(int weight, int letter_len, int word_len);
