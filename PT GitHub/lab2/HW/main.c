#include "libmystring.h"
#include <stdio.h>
#include <errno.h>

int main()
{
	printf("Strlen: %d\n",Mystrlen("abcduioewiqo"));
	printf("Strstr: %s\n",Mystrstr("abcduioewiqo","du"));
	printf("Strchr: %s\n",Mystrchr("abcduioewiqo",'o'));
	char test[]="abc12A",test2[]="ABC12a";
	Mystrtoupper(test);
	Mystrtolower(test2);
	printf("Strtoupper: %s\n",test);
	printf("Strtoupper: %s\n",test);
	char s1[]="hello";
	char s2[]="worldd";
	printf("Strcmp: %d\n",Mystrcmp(s1,s2));
	Mystrcpy(s1,s2);
	printf("Strcpy: %s\n",s1);
	Mystrncpy(s1,s2,3);
	printf("Strncpy: %s\n",s1);
	printf("Strerror: %s\n", Mystrerror(errno));
	printf("Memset: %s\n", Mymemset(test,'-',3));
	printf("Memchr: %s\n", Mymemchr(test2,'1',6));
	printf("Strrchr: %s\n", Mystrrchr(test, 'a',2));
	printf("Strncat: %s\n",Mystrncat("abc","def",2));
	printf("Strcat: %s\n",Mystrcat("abc","def"));
	pritnf("Strcoll: %s\n", strcoll(test,test2));
	return 0;
}