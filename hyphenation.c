#include <stdio.h>
#include <stdlib.h>

// GROUP INFORMATION
// 1. Student : 
//     OGÜN BAYSAL 170101035
// 2. Student :
//     MELİH ARIKAN 170101069


//bu fonksyion eger harf sesli ise 1 degil ise 0 dondurur
int isVowel(char);

int main()
{
    //word kullanicinin girecegi kelime
    //wordHype hecelenmis hali olacak
    //buraya ihtiyaciniz olan diger degiskenleri tanimlayabilirsiniz.
    char word [50] = "", wordHyp [100] = "";
    //asagidaki iki satiri degistirmeyiniz.
    printf("Enter a word for hyphenation:\n");
    scanf("%s", word);


    //yazacaginiz kod buraya gelsin. Ancak printf ve scanf gibi
    //ekranda gorunecek ciktilari degistirecek hic bir fonksyion kullanmayiniz.
    //char dizisi (string) ile calistigimiz icin word degiskenini bir fonksyiona
    //gonderip onun ustunde heceleme yapabilirsiniz ancak su an icin pointerlari
    //ogrenmedigimiz icin bu    oldukca zor olacaktir.
    //ancak metin icindeki bir harf sesli mi degil mi bunu ogrenmek icin gereken
    //fonksyionu size tanimladik.
    //sadeece Ingiliz alfabesindeki karakterler kullanilacak. Turkce' ye ait
    //ö, ı, ü, ç, ş ... gibi harflere dikkat etmenize gerek yoktur.
    //Size strcat ve strncat fonksyionlar cok yardimci olacaktir.
    //lutfen kullanimlarina bakiniz.
    //Kullanici okul gibi bir kelime girdiyse
    //hecelerine - karakteriyle ayrilmalidir.
    //o-kul gibi. Bu heceleme islemini yaparken son karakterde - isareti kalmamalidir
    //yani o-kul- olmamalidir.


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
    
    
    
      
   
	//kodunuz asagidaki satirlardan once bitmeli
    //asagidaki iki satiri degistirmeyiniz
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