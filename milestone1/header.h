#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
int from_bag(char letters[],char word_copy[]);
int from_dictionary(char word_copy[]);
int cal_weight(char word_copy[]);
int cal_score(int weight,int letter_len,int word_len);