//IMPLEMENTATIONS OF FUNCTIONS
#include"header.h"

int from_bag(char letters[],char word_copy[])
{
 int w=0,j=0,i=0,star_count=0,letters_length,only_letters,word_length;
    int hash_count=0,checkmark=0;
    char word[30];
    char temp;


//cal. lenghts of lettes entered and word entered
    letters_length=strlen(letters);
    word_length=strlen(word_copy);
    if(word_length>letters_length)
       return checkmark=0;
    
    else
    {
//counting no of * if any
		for(i=0;i<letters_length;i++)
		{
			if(letters[i]=='*')
			star_count++;
		}
		only_letters=letters_length-star_count;

//sorting letters including * with letters reversed
//stars at end since ascii of *=42
		for(i=0;i<letters_length;i++)
			for(j=i+1;j<letters_length;j++)
			    if(letters[i]<letters[j])
			    {
			        temp=letters[j];
			        letters[j]=letters[i];
			        letters[i]=temp;
			    }

//final sorted letters
		for(i=0;i<only_letters;i++)
			for(j=i+1;j<only_letters;j++)
			    if(letters[i]>letters[j])
			    {
			        temp=letters[j];
			        letters[j]=letters[i];
			        letters[i]=temp;
			    }


//converting entered letters to uppercase from lowercase if any
		for(i=0;i<only_letters;i++)
		{
		    if(letters[i]>='a' && letters[i]<='z')
			letters[i]-=32;
		}
	
	strcpy(word,word_copy);


//comparing string
	//no stars included
		for(i=0;i<letters_length;i++)
			for(j=0;j<word_length;j++)
			    if(letters[i]!='*' && letters[i]==word[j])
			        word[j]='#';
	//with star	
		for(i=0;i<letters_length;i++)
			for(w=0;w<word_length;w++)
	            if(letters[i]=='*'&&(word[w]=='A'||word[w]=='E'||word[w]=='I'||word[w]=='O'||word[w]=='U'))
			            {
			                word[w]='#';
			                break;
			            }

//checking first condition if word is from letters
	//counting hashtags
			    for(i=0;i<word_length;i++)
			    {
			        if(word[i]=='#')
			            hash_count++;
			    }
			    if(hash_count==word_length)
			        checkmark=1;
			    else
			    {
			        printf("Entered word is invalid as it is not formed by given letters");
				checkmark=0;
			    }
    }
	return checkmark;
}

int from_dictionary(char word_copy[])
{
	char ch[30];
	int checkmark=1;
	FILE *fp;	
	switch(word_copy[0])
	{
		case 'A': fp=fopen("a.txt","r"); break;
		case 'B': fp=fopen("b.txt","r"); break;
		case 'C': fp=fopen("c.txt","r"); break;
		case 'D': fp=fopen("d.txt","r"); break;
		case 'E': fp=fopen("e.txt","r"); break;
		case 'F': fp=fopen("f.txt","r"); break;
		case 'G': fp=fopen("g.txt","r"); break;
		case 'H': fp=fopen("h.txt","r"); break;
		case 'I': fp=fopen("i.txt","r"); break;
		case 'J': fp=fopen("j.txt","r"); break;
		case 'K': fp=fopen("k.txt","r"); break;
		case 'L': fp=fopen("l.txt","r"); break;
		case 'M': fp=fopen("m.txt","r"); break;
		case 'N': fp=fopen("n.txt","r"); break;
		case 'O': fp=fopen("o.txt","r"); break;
		case 'P': fp=fopen("p.txt","r"); break;
		case 'Q': fp=fopen("q.txt","r"); break;
		case 'R': fp=fopen("r.txt","r"); break;
		case 'S': fp=fopen("s.txt","r"); break;
		case 'T': fp=fopen("t.txt","r"); break;
		case 'U': fp=fopen("u.txt","r"); break;
		case 'V': fp=fopen("v.txt","r"); break;
		case 'W': fp=fopen("w.txt","r"); break;
		case 'X': fp=fopen("x.txt","r"); break;
		case 'Y': fp=fopen("y.txt","r"); break;
		case 'Z': fp=fopen("z.txt","r"); break;
	}
						    
	while(fscanf(fp,"%s",ch)!=EOF)
		if(strcmp(word_copy,ch)==0)
		{
			checkmark=2;
		        break;
		}

	else
		checkmark=1;
						    
fclose(fp);
retun checkmark;
}


int cal_weight(char word_copy[])
{
	int i=0,weight;
	while(word_copy[i]!='\0')
	{
		if(word_copy[i]=='E'||'A'||'I'||'O'||'N'||'R'||'T'||'L'||'S'||'U')
		weight=weight+1;
		else if(word_copy[i]=='D'||'G')
		weight=weight+2;
		else if(word_copy[i]=='B'||'C'||'M'||'P')
		weight=weight+3;
		else if(word_copy[i]=='F'||'H'||'V'||'W'||'Y')
		weight=weight+4;
		else if(word_copy[i]=='K')
		weight=weight+5;
		else if(word_copy[i]=='J'||'X')
		weight=weight+8;
		else if(word_copy[i]=='Q'||'Z')
		weight=weight+10;
		i++;
	}	
	return weight;
}

int cal_score(int weight,int letter_len,int word_len)
{
	int good,bad,mult,score;
	good=(letter_len - 1) * word_len;
	bad=3*(letter_len + 1 - word_len);
	if(bad<1)
	bad=1;
	mult=good-bad;
//score
	score=weight * mult;
	return score;
}
