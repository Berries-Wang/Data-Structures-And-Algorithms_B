#include <stdio.h>
#include <string.h>

char* reverseString(char* s);

int main(int argc , char **argv)
{

	char s[]  = "Hello World";
	printf("%s -----" , s);
	char *res = reverseString(s);
	printf("%s\n" , res);

	return 0;
}


char* reverseString(char* s)
{
	int length = strlen(s);
	int left = 0;
	int right = length - 1;


	while(left < right)
	{
		char temp = s[left];
		s[left] = s[right];
		s[right] = temp;

		left ++;
		right --;
	}

	return s;


}
