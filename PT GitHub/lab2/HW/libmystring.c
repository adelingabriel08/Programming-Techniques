#include <stddef.h>
unsigned int Mystrlen(const char *dest)
{
	unsigned int i=0;
	while(dest[i]!='\0')
		++i;
	return i;
}
char* Mystrstr(char *dest, const char *src)
{
	char* address='\0';
	for(int i=0;i<Mystrlen(dest);i++)
		if(dest[i]==src[0])
		{
			address=dest+i;
			for(int j=1;j<Mystrlen(src);j++)
				if(dest[i+j]!=src[j])
					{
					break;
					address='\0';
					}
		}
	return address;
}
char* Mystrchr(const char *dest, const char src)
{
	for(int i=0;i<Mystrlen(dest);i++)
		if(dest[i]==src)
			return dest+i;
	return '\0';
}
void Mystrtoupper(char *dest)
{
	for(int i=0;i<Mystrlen(dest);i++)
		if(dest[i]>='a'&& dest[i]<='z')
			dest[i]=dest[i]-32;
}
void Mystrtolower(char *dest)
{
	for(int i=0;i<Mystrlen(dest);i++)
		if(dest[i]>='A'&& dest[i]<='Z')
			dest[i]=dest[i]+32;
}
int Mystrcmp(const char *a,const char *b)
{
	if(Mystrlen(a)!=Mystrlen(b))
		return a[Mystrlen(a)-1]-b[Mystrlen(b)-1];
	for(int i=0; i<Mystrlen(a); i++)
			if(a[i]!=b[i]) return a[i]-b[i];
	return 0;
}
char *Mystrcpy(char *a, const char *b)
{
	for(int i=0;i<Mystrlen(b);i++)
		a[i]=b[i];
	return a;
}
char *Mystrncpy(char *a,const char *b,unsigned int c)
{
	for(int i=0;i<c && b[i]!='\0';i++)
		a[i]=b[i];
	a[c]='\0';
	return a;
}
char* Mystrerror(int errornum)
{
    return (char*)errornum;
}
char* Mymemset(char *dest, int character, int n)
{
    int j=0;
    while(dest[j] && j<n)
    {
        dest[j] = character;
        j++;
    }
    
    return dest;
}
char* Mymemchr(char *dest, int character, int n)
{
    
    char *ptr = dest;
    while( n--)
        if( *ptr != character )
            ptr++;
        else
            return ptr;
    return 0;
}
char* Mystrcat(char *dest,  char *src)
{
    int i = 0;
    while(dest[i])
        i++;
    for(int j = 0; src[j] ;j++)
    {
        dest[i] = src[j];
        i++;
    }
    dest[i]='\0';
    return dest;

}
char *Mystrncat(char *dest,  char *src,int n)
{
    int i = 0;
    while(dest[i])
        i++;
    for(int j = 0; src[j] && j<n;j++)
    {
        dest[i]=src[j];
        i++;
    }
    dest[i]='\0';
    return dest;
}
char* Mystrrchr( char *str, int c)
{
    char *ptr;
    for( int i = 0; str[i]; i++)
        if(str[i]==c)
     		return str+i;
}
int strcoll( char *s1,  char *s2)
{
    for(int i = 0; s1[i] ;i++)
    {
        if(s1[i] == s2[i]) 
            return 0;
        if(s1[i] < s2[i])
            return -1;
        if(s1[i] > s2[i])
            return 1;
    }
    return 0;
}