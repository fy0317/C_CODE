#include<stdio.h>
void main()
{
	long x,y;
	double z;
	short q;
	int a,b,c,d;
	printf("%d,%d,%d\n\n\n",sizeof(z),sizeof(c),sizeof(q));
	x=5,y=6,a=7,b=8;
	c=x+a;
	d=y+b;
	z=x+a;
	printf("c=x+a=%d,d=y+b=%d\n",c,d);
	printf("%d,%d\n",sizeof(z),sizeof(c));
}