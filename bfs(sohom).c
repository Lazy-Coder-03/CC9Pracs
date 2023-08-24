#include<stdio.h>
#include<stdlib.h>
void print(int ** arr , int n);
void bfs(int ** arr , int n, int s);
void bfs(int ** arr , int n,int s)
{
	int *d = (int *)calloc(n,sizeof(int));
	int *parent = (int *)calloc(n,sizeof(int));
	int *q = (int *)calloc(n,sizeof(int));
	int  u , count , i , current, front = -1, rear = -  1 ;
	count = 0 ;
	for(i = 0 ; i < n ; i++)
	{
		d[i] = -1 ;
		parent[i] = -1;
	}
	d[s] = 0 ;
	rear ++;
	front++;
	q[rear] = s ;
	printf("\nThe bfs traversal is as follows :");
	
	while( rear >= front)
	{
		current = q[front];
		u = current;
		u++;
		front++;
		count++;
		printf("%d-",u);
		for( i = 0 ; i < n ; i++)
		{
			if(arr[current][i] == 1 && d[i] < 0) //path exists between node i and current but node i is not visited
			{
				rear++;
				q[rear] = i;
				d[i] = d[current] + 1;
				parent[i] = current;
			}
		}
	}
	free(q);
	free(d);
	free(parent);
}
void print(int ** arr , int n)
{
	int i , j;
	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	int j , ch, dir, u , v, n , i ;
	
	while(n <= 0)
	{
		printf("Enter no. of vertices of graph =>");
		scanf("%d",&n);
	}
	int **arr = (int **)calloc(n,sizeof(int *));
	for(i = 0 ; i < n ; i++)
	{
		arr[i] = (int *)calloc(n,sizeof(int ));
	}
	printf("\nFor undirected graph, Enter 1.\nFor directed graph,Enter 2.\nChoice=>");
	scanf("%d",&dir);
	switch(dir)
	{
		case 1 :
			
				do{
					printf("\nEnter vertex pair (u,v) )between which there must be an edge :\n");
					scanf("%d %d",&u,&v);
					if(u > n || v > n || u < 1 || v < 1)
					{
						while(u > n || v > n || u < 1 || v < 1)
						{
							printf("\nNeither vertex of the vertex pair can be be > n or < 1.");			
							printf("\Enter vertex pair (u,v) )between which there must be an edge :\n");
							scanf("%d %d",&u,&v);
						}	
					}
					arr[u-1][v-1] = 1;
					arr[v-1][u-1] = 1;
					printf("\nEnter 1 to add more edges.\nEnter 0 to end.");
					scanf("%d",&ch);				
						
				}while(ch != 0);
				
				break;				
		case 2 :
		
				do{
					printf("\nEnter source vertex :");
					scanf("%d",&u);
					printf("\nEnter destination vertex :");
					scanf("%d",&v);
					if(u > n || v > n || u < 1 || v < 1)
					{
						while(u > n || v > n || u < 1 || v < 1)
						{
							printf("\nNeither vertex of the vertex pair can be be > n or < 1.");				
							printf("\Enter source vertex :");
							scanf("%d",&u);
							printf("\nEnter destination vertex :");
							scanf("%d",&v);	
						}	
					}
					arr[u-1][v-1] = 1;
					arr[v-1][u-1] = -1;
					printf("\nEnter 1 to add more edges.\nEnter 0 to end.\nChoice=>");
					scanf("%d",&ch);				
						
				}while(ch != 0);
				
				
				break;
			
	
		default :
			printf("\nInvalid choice.");
	}
	print(arr,n);
	int source;
	printf("\nEnter source vertex from which BFS traversal should be implemented : ");
	scanf("%d",&source);
	bfs(arr , n , source-1);
	free(arr);
}
