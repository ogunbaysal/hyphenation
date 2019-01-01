#include <stdio.h>
#include <stdlib.h>
int isVowel(char);

int main()
{
    char word [50] = "", wordHyp [100] = "";
    printf("Enter a word for hyphenation:\n");
    scanf("%s", word);

    int j=0;
    int i = 0;
    while(word[i] != '\0'){
        wordHyp[i+j] = word[i];
        if(isVowel(word[i]) && !isVowel(word[i+1]) && !isVowel(word[i+2]) && !isVowel(word[i+3])){
            if(word[i+3] != '\0'){
                wordHyp[i+j+1] = word[i+1];
                wordHyp[i+j+2] = word[i+2];
                wordHyp[i+j+3] = '-';
                j++;
                i = i+2;
            }
        }else if(isVowel(word[i]) && !isVowel(word[i+1]) && !isVowel(word[i+2]) && isVowel(word[i+3])){
            wordHyp[i+j+1] = word[i+1];
            wordHyp[i+j+2] = '-';
            j++;
            i++;
        }else if(isVowel(word[i]) && !isVowel(word[i+1]) && isVowel(word[i+2])){
            wordHyp[i+j+1] = '-';
            j++;
        }else if(!isVowel(word[i]) && isVowel(word[i+1]) && isVowel(word[i+2]) && !isVowel(word[i+3])){
            wordHyp[i+j+1] = word[i+1];
            wordHyp[i+j+2] = '-'; 
            i++;
            j++;           
        }
        i++;
    }
    wordHyp[i+j] = '\0';
    printf("%s\n", wordHyp);
    return 0;
}

int isVowel(char c)
{

  switch(c)
  {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return 1;
      break;
    default:
      return 0;
      break;
  }
}