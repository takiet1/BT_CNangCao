#include <stdio.h> 
#include <stdint.h>
#include <stdlib.h>


typedef struct
{
    char *ptr;
    int length;
}words;

int sizeOfString (char *str){
    int size = 1; 
    while(*str != '\0'){
        if(*str == ' ') size++;
        str++;
    }
    return size;
}

words* luuMang(char *str, int size){
    words *array = (words*)malloc(sizeof(words)*size);
    int index = 0;
    int count = 0;
    array[index].ptr = str;
    while(*str != '\0'){
        if(*str == ' '){
            if (*(str-1) == ',') count--;
            array[index].length = count;
            count = 0; 
            str++; 
            index++;
            array[index].ptr = str;
        }
        else{
            str++;
            count++;
        }
    }
    array[index].length = count;
    return array;
}

void daoTu(words *array, int size){
for(int i =size; i>=0 ; i--){
    for(int j =0;j<array[i].length;j++){
        printf("%c",array[i].ptr[j]); 
    } 
    printf(" ");   
    //   if(size==1) printf("%.*s", array[0].length, array[0].ptr);

}
}



int main()
{
    char string[] = "nam hoang bao, nam hoang hoang, bao bao yen, anh bao yen";

    int size = sizeOfString (string);

    words *a = luuMang(string, size);

    daoTu(a, size);

    return 0;
}
