
///Enfa to nfa

int nfa[10][10][10],zeroclos[10][10],m,oneclos[10][10];

for(i=0;i<n;i++)
{
		for(j=0;j<n;j++)
			{
			p[j] = 0;
			}
		m = 0;
		for(j=0;eps[i][j] !=0;j++)
		{
			for(k=0;k<size[eps[i][j]-1][0];k++)
			{
				if(p[eps[i][j]-1] ==0)
				{
					zeroclos[i][m]=table[eps[i][j]-1][0][k];
					p[zeroclos[i][m]-1] = 1;
					m++;
				}
			}
		
		}
		zeroclos[i][m] = '\0';
		
		for(j=0;j<n;j++)
			{
			p[j] = 0;
			}
		m = 0;
		for(j=0;eps[i][j] !=0;j++)
		{
			for(k=0;k<size[eps[i][j]-1][1];k++)
			{
				if(p[eps[i][j]-1] ==0)
				{
					oneclos[i][m]=table[eps[i][j]-1][1][k];
					p[oneclos[i][m]-1] = 1;
					m++;
				}
			}
		
		}
		oneclos[i][m] = '\0';

}
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		p[j] = 0;
	m = 0;
	for(j=0;zeroclos[i][j] != '\0';j++)
	{
		for(k=0;eps[zeroclos[i][j]-1][k] != 0;k++)
		{
			if(p[eps[zeroclos[i][j]-1][k]-1] == 0)
			{
				nfa[i][0][m]= eps[zeroclos[i][j]-1][k];
				p[eps[zeroclos[i][j]-1][k]-1] = 1;
				m++;
		
			}
		}
	
	}
	nfa[i][0][m] = '\0';
	
	
	
	
	for(j=0;j<n;j++)
		p[j] = 0;
	m = 0;
	for(j=0;oneclos[i][j] != '\0';j++)
	{
		for(k=0;eps[oneclos[i][j]-1][k] != 0;k++)
		{
			if(p[eps[oneclos[i][j]-1][k]-1] == 0)
			{
				nfa[i][1][m]= eps[oneclos[i][j]-1][k];
				p[eps[oneclos[i][j]-1][k]-1] = 1;
				m++;
		
			}
		}
	
	}
	nfa[i][1][m] = '\0';
}
printf("\n\n\nNFA \n\nStates\t0\t1\n");
for(i=0;i<n;i++)
{
	printf("\n");
	if(states[i] == first[0])
		printf("*");
	for(j=0;j<strlen(final);j++)
		if(final[j] == states[i])
			printf(">");
	printf("%c \t",states[i]);
	for(j=0;nfa[i][0][j] != '\0';j++)
	printf("%c ",states[nfa[i][0][j]-1]);
	printf("\t");
	for(j=0;nfa[i][1][j] != '\0';j++)
	printf("%c ",states[nfa[i][1][j]-1]);
	


}
printf("\n\n");

///nfa to dfa

int dfa[10][10][10];

dfa[0][0][0] = nfa[0][0][0];
for(i=0;i<2;i++)
for(j=0;nfa[0][i][j] != '\0';j++)
{
	dfa[0][i][j] = nfa[0][i][j];
}
}
