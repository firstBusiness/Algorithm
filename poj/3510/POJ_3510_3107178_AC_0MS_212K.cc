#include <stdio.h>
#include <string.h>

char out[10000001];
int len,n;

int main()
{
	int i,m=0,j;
	char ch,c2,c3;
	ch = getchar();
	while (1)
	{
		if (ch>='A' && ch<='Z')
		{
			if (ch != 'E')
			{
				ch = getchar();
				continue;
			}
			c2 = getchar();
			if (c2 != 'O')	ch = c2;
			else
			{
				c3 = getchar();
				if (c3 != 'F')			ch = c3;
				else return 0;
			}
		}
		else if (ch == ' ' || ch == '\t' || ch == '\n')
		{
			printf("%c",ch);
			ch = getchar();
		}
		else if (ch>='a' && ch<='z')
		{
			if (ch == 'd')
			{
				m = 1;
				while ((c2=getchar()) == 'd')m++;
				if (m == 2)
				{
					ch = c2;
					printf("p");
				}
				else
				{
					
					for (i=0; i<m; i++)
						printf("d");
					ch = c2;
				}
			}
			else if (ch == 'p')
			{
				c2 = getchar();
				if (c2 == 'i')
				{
				    c2 = getchar();
				    if (c2  == 'n')
				    {
                        c2 = getchar();
                        if (c2 == 'k')
                        {
                            printf("%s","floyd");
                            ch = getchar();
                            continue;
                        }
                        else
                        {
                            printf("%s","pin");
                            ch = c2;
                        }
                        
				    }
				    else
				    {
				        printf("%s","pi");
				        ch = c2;
				    }
				}
				else
				{
				    printf("p");
				    ch = c2;
				}
			}
			else if (ch == 'c')
			{
				c2 = getchar();
				if (c2 == 'e')
				{
					c2 = getchar();
					if (c2 == 'i')
					{
					    printf("cei");
					    ch = getchar();
					}
					else
					{
					    printf("%s","ce");
                        ch = c2;
					}
				}
				else
				{
					printf("c");
					ch = c2;
					continue;
				}
			}
			else if (ch == 'e')
			{
			    c2 =getchar();
			    if (c2 == 'i')
			    {
			        printf("ie");
			        ch = getchar();
			    }
			    else
			    {
			        printf("e");
			        ch = c2;
			    }
			}
			else
				printf("%c",ch),ch = getchar();
		}
		else
			ch = getchar();
	}	
	return 0;
}
