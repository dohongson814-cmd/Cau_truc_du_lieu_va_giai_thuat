#include <stdio.h>

int max(int a,int b)
{
	return (a>=b)?a:b;
}

int Quyhoachdong(int a[])
{
	int n=sizeof(a);
	int ei=a[0];
	int si=a[0];
	for (int i=1;i<=n-1;i++)
	{
		ei=max(a[i],a[i]+ei);
		si=max(si,ei);
	}
	return si;
}
int main()
{
	int a[6]={-2,11,-4,13,-5,2};
	printf("%d",Quyhoachdong(a));
	return 0;
}
