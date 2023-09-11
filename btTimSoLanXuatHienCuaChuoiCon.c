#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    char *ptr;
    uint8_t  length;
    uint8_t  quantity;
    bool status;
}words;

uint8_t  sizeStr (char *str ){
    uint8_t  size = 1;
    while (*str != '\0'){
        if(*str == ' ')   size++;

        str++;
    }
    return size;
}

words* splitString (char *str, uint8_t  size){
    words *array = (words*)malloc(sizeof(words)*size);
    uint8_t  index = 0;
    uint8_t  count = 0;
array[index].ptr = str ;
while(*str != '\0'){
    if(*str == ' '){
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

void findName(words *array, uint8_t  size)
{
    for (uint8_t  i = 0; i < size; i++)
    
    {
        uint8_t  count = 0;
        for(uint8_t  j=0; j<size ; j++){
            uint8_t  i_ptr=0;
            while (array[i].ptr[i_ptr] == array[j].ptr[i_ptr]){
                i_ptr++;
                if(array[i].length == i_ptr && array[j].length == i_ptr){
                    count++;
                    if(count>=2) array[j].status = false;
                    else array[j].status = true;
                    break;
                }
            }
                }
           array[i].quantity = count;

        }
    }

void printName(words *array, uint8_t   size){
    for (uint8_t i=0; i<size; i++){
        if (array[i].status == true){
            for (uint8_t   j=0; j< array[i].length; j++){
            printf("%c",array[i].ptr[j]);
        }
        printf("\t:%d\n",array[i].quantity);
        }
    }
}
 
uint8_t main(){
char string[] = "nam hoang bao, nam hoang hoang, bao bao yen, anh bao yen";
uint8_t size = sizeStr(string);
words *a = splitString(string,size);
findName(a,size);
printName(a,size);
return 0;
}
