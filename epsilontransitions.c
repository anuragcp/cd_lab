#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
int table[10][10][10],i,j,k,n,p[10],eps[10][5],l,size[10][10],seps[10];
char states[10],first[2],final[10],state[2];
printf("Enter number of states\t");
scanf("%d",&n);

printf("\nEnter the States as a single string\t");
scanf("%s",states);
printf("\nEnter the first state\t");
scanf("%s",first);
printf("\nEnter the final states as a single string\t");
scanf("%s",final);

printf("Enter the table values");
for(i=0;i<n;i++)
{
for(j=0;j<3;j++)
	{
		printf("\nEnter number of states in [%d, %d] \t",i+1,j+1);
		scanf("%d",&size[i][j]);
		if(size[i][j]>0)
		{
			printf("Enter %d elements\n",size[i][j]);
		
			for(k=0;k<size[i][j];k++)
			{scanf("%s",state);	
				//printf("cde");
				for(l=0;l<n;l++)
					if(states[l] == state[0])
					{//printf("abc");
						table[i][j][k] = l+1;
						break;
					}
				//printf("efg:");
			}
		}
		/*
		for(k=0;k<size[i][j];k++)
		scanf("%d",&table[i][j][k]);*/
	}
	
}
printf("\n\n\nE-NFA\n\n");
printf("\tStates\t0\t1\t eps\n");
for(i=0;i<n;i++)
{
	printf("\n\t");
	if(states[i] == first[0])
		printf("*");
	for(j=0;j<strlen(final);j++)
		if(final[j] == states[i])
			printf(">");
	printf("%c",states[i]);
	for(j=0;j<3;j++)
	{
		printf("\t");
		for(k=0;k<size[i][j];k++)
		printf("%c ",states[table[i][j][k]-1]);
	}
}
for(i=0;i<n;i++)
seps[i]=0;
for(i=0;i<n;i++)
for(j=0;j<10;j++)
	eps[i][j] = 0;

for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		p[j]=0;
	p[i]=1;
	eps[i][0]=i+1;
	k=1;
	for(j=0;j<10;j++)
	{
		if(eps[i][j])
		{
			for(l=0;l<size[i][2];l++)
			if(p[table[i][2][l]-1]==0)
			{
				eps[i][k]=table[i][2][l];
				p[eps[i][k]-1]=1;
				k++;
			}
		}
	
	}
	
}
printf("\n\nEpsilon transition\n\nStates\teps");
for(i=0;i<n;i++)
{
	printf("\n%c \t",states[i]);
	for(k=0;eps[i][k]!=0 ;k++)
	printf("%c ",states[eps[i][k]-1]);

}
}

