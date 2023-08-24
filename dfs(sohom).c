#include<stdio.h>
#include<stdlib.h>
void print(int ** arr , int n);
void dfs(int **arr, int n , int source);
void dfs(int **arr, int n , int source)
{
	int *stack = (int *)calloc(n,sizeof(int *));
	int *visited = (int *)calloc(n,sizeof(int *));
	int i , current ,  top = -1 ;
	for(i = 0 ; i < n ; i++ ) 
	{
		visited[i] = -1;
	}
	visited[source] = 0;
	top++;
	int u ; 
	stack[top] = source;
	printf("\nDFS traversal for given graph is :\n");
	while(top != -1)
	{
		current = stack[top];
		top --;
		u = current;
		printf("%d",++u);
		for( i = 0 ; i < n ; i++)
		{
			if(arr[current][i] == 1 && visited[i] < 0)
			{
				top++;
				stack[top] = i;
				visited[i] = visited[current] + 1;
			}
		}
	}
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
	printf("\nEnter source vertex from which DFS traversal must be performed :\nSource=>");
	scanf("%d",&source);
	dfs(arr, n , source-1);
}
