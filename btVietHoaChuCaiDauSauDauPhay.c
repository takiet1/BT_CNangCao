#include <stdio.h>
#include <string.h> 

char upper(char c){
    if('a' <= c && c <= 'z'){
        c = c - ('a' - 'A');
    }
    return c;
}

int main() 
{
    char s[]="Chuc mung sinh nhat ban. chuc ban co mot sinh nhat vui ve. va hanh phuc";
    int len = strlen(s);
    int i, count = 0;
    for (i = 0; i < len; i++ )
    {
        if(s[i] == '.') 
        {
            count = i+2;
            s[count] = upper(s[count]); 
        }      
    }

    printf("Van ban moi la: %s", s );
    return 0;
}