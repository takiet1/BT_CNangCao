#include <stdio.h>
#include <string.h> 
#include <stdbool.h>

void Find(char *s1, char *s2)
{
bool Check = 0;
	for (int i = 0; i < strlen(s1); i++)
	{
		
		if (s1[i] == s2[0])
		{
			Check = 1;
			for (int j = 1; j < strlen(s2); j++)
			{
				if (s1[++i] != s2[j]) 
				{
					Check = 0;
					break;
				}
			}
		}
	}
	
	if(Check)
		{
		printf("Co\n");
		}
	else{
		printf("Ko Co\n");
	}
}


int main() 
{ 
    char s1[] = "Chuc mung sinh nhat ban. chuc ban co mot sinh nhat vui ve. va hanh phuc";
	char s2[] = "Chuc mung sinh nhat";
	Find(s1,s2);
    return 0;
}

   
