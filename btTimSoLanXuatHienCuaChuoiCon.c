#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
    char *ptr;
    int length;
    bool status;
    int numbers;
}words;

int sizeOfString (char *str){
    int size = 1 ;
    while (*str != '\0'){
        if (*str == ' '){
            size++;
        }
        str++;
    }
    return size;
}

words* SplitString(char *str, int size){
    words *array = (words* )malloc(sizeof(words)*size);
    int index = 0;
    int count = 0;
    array[index].ptr = str;
    while (*str != '\0'){
        if (*str == ' '){
            if(*(str-1) == ',') count--;
            array[index].length = count;
            count = 0;
            str++;
            index++;
            array[index].ptr = str;
        }
        else {
            str++;
            count++;
        }
    }
    array[index].length = count;
    return array;
}


void findString (words *array, int size)
{
    for(int i=0; i<size; i++){
        int count = 0;
        for (int j = 0; j<size; j++)
        {
            int iptr = 0;
            while (array[i].ptr[iptr] == array[j].ptr[iptr]) 
            {
                iptr++;
                if (array[i].length == iptr && array[j].length == iptr)
                {
                    count++;
                    if(count>=2) array[j].status = false;
                    else array[j].status = true;
                    break;
                }
            }
        }
        array[i].numbers = count;
        // printf("%d\n",array[i].numbers);
    }
}



void printString (words *array, int size){
    for (int i=0; i<size; i++){
        if(array[i].status == true){
            for (int j = 0; j < array[i].length; j++)
            {
                printf("%c",array[i].ptr[j]);
            }
            printf("\t:%d\n",array[i].numbers);
        }
    }
}

int main()
{
    char string[] = "nam hoang bao, nam hoang hoang, bao bao yen, anh bao yen";
    int size = sizeOfString(string);
    words *a = SplitString(string, size);
    findString (a, size);
    printString(a, size);
    return 0;
}
