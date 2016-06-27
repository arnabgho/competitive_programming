#include<stdio.h>
#include<stdlib.h>

#define SIZE 60

int a[SIZE][SIZE];
int row[SIZE], used_row[SIZE], row2[SIZE];
int column[SIZE], column2[SIZE];

int main( )
{
	int t, n, m, i, j, k, flag, row_sum, column_sum, tipu, row_max, r, l, counter = 1;
	scanf("%d",&t);
	while ( t-- )
	{
		flag = row_sum = column_sum = 0;
		scanf("%d %d",&n, &m);
		for ( i = 0; i < n; i++ )
		{
			scanf("%d",&row[i]);
			if ( row[i] > m )
				flag = -1;
			row_sum += row[i];
			row2[i] = row[i];
		}
		for ( i = 0; i < m; i++ )
		{
			scanf("%d",&column[i]);
			if ( column[i] > n )
				flag = -1;
			column_sum += column[i];
		}		
		if ( column_sum != row_sum )
			flag = -1;
		if ( flag == -1 )
		{
			printf("TestCase #:%d\n",counter++);
			printf("-1\n");
		}
		else
		{
			for ( i = 0; i < n; i++ )
			{
				for ( j = 1; j <= row[i]; j++ )
				{
					a[i][m-j] = 1;
				}
			}
		/*	printf("\nprinting matrix after initializing\n");
			for ( i = 0; i < n; i++ )
			{
				for ( j = 0; j < m; j++ )
				{
					printf("%d ",a[i][j]);
				}
				printf("\n");
			} */
			for ( i = 0; i < m; i++ )
			{
				for ( j = 1; j <= column[i]; j++ )
				{
					row_max = n-1;
					for ( k = n-1; k >= 0; k-- )
					{
						if ( row[k] > row[row_max] && !used_row[k] )   // to prevent shifting the same row twice
							row_max = k;
					}
					if ( i != m-row[row_max] )
					{
						a[row_max][i] = 1;
						a[row_max][m-row[row_max]] = 0;    //shifting the maximum lower(in case of tie) 1 towards left
					}
					used_row[row_max] = 1;
					row[row_max]--;
				}
			/*	printf("\nprinting matrix after column %d\n",i);
				for ( k = 0; k < n; k++ )
				{
					for ( l = 0; l < m; l++ )
					{
						printf("%d ",a[k][l]);
					}
					printf("\n");
				}  */
				for ( k = 0; k < n; k++ )
					used_row[k] = 0;
			}
		/*	printf("\nprinting matrix\n");
			for ( i = 0; i < n; i++ )
			{
				for ( j = 0; j < m; j++ )
				{
					printf("%d ",a[i][j]);
				}
				printf("\n");
			}
			printf("\n");  */
			tipu = 0;
		/*	for ( i = 0; i < m; i++ )
			{
				for ( j = 0; j < n; j++ )
				{
					tipu = 0;
					if ( a[j][i] == 1 )
					{
						for ( k = i+1; k < m; k++ )
						{
							if ( a[j][k] == 0 )
							{
								for ( l = j+1; l < n; l++ )
								{
									if ( a[l][k] == 1 && a[l][i] == 0 )
									{
										a[l][k] = 0, a[l][i] = 1;
										a[j][i] = 0, a[j][k] = 1;
										tipu = 1;
										break;
									}
								}
								if ( tipu )
								{
									tipu = 0;
									break;
								}
							}
						}  // breaking out of it due to if(tipu)
					}
				}
			}

			printf("TestCase #:%d\n",counter++);
			for ( i = 0; i < n; i++ )
			{
				for ( j = 0; j < m; j++ )
				{
					printf("%d",a[i][j]);
				}
				printf("\n");
			}   */

			for ( i = 0; i < n; i++ )
			{
				for ( j = 0; j < m; j++ )
				{
					tipu = 0;
					if ( a[i][j] == 1 )
					{
						for ( k = j+1; k < m; k++ )
						{
							if ( a[i][k] == 0 )
							{
								for ( l = i+1; l < n; l++ )
								{
									if ( a[l][k] == 1 && a[l][j] == 0 )
									{
										a[l][k] = 0, a[l][j] = 1;
										a[i][j] = 0, a[i][k] = 1;
										tipu = 1;
										break;
									}
								}
								if ( tipu )
								{
									tipu = 0;
									break;
								}
							}
						}  // breaking out of it due to if(tipu)
					}
				}
			}

		//	printf("printing the matrix after sorting:\n");
			/*for ( i = 0; i < n; i++ )
			{
				row[i] = 0;
			}
			for ( i = 0; i < n; i++ )
			{
				for ( j = 0; j < m; j++ )
				{
					row[i] += a[i][j];
				}
			}
			for ( i = 0; i < n; i++ )
			{
				if ( row[i] != row2[i] )
				{
					printf("damn\n");
				}
			}
			for ( i = 0; i < m; i++ )
			{
				for ( j = 0; j < n; j++ )
				{
					column2[i] += a[j][i];
				}
			}
			for ( i = 0; i < m; i++ )
				if ( column[i] != column2[i] )
					printf("oh! no\n");		*/

					
			printf("TestCase #:%d\n",counter++);
			for ( i = 0; i < n; i++ )
			{
				for ( j = 0; j < m; j++ )
				{
					printf("%d",a[i][j]);
				}
				printf("\n");
			}
		//	printf("\n");							
		}
		for ( i = 0; i < SIZE; i++ )
			for ( j = 0; j < SIZE; j++ )
				a[i][j] = 0;
		for ( i = 0; i < SIZE; i++ )
			row[i] = column[i] = used_row[i] = row2[i] = column2[i] = 0;
	}
	return 0;
}











