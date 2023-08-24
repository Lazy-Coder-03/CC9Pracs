#include<stdio.h>
#include<stdlib.h>
void print(int ** arr , int n);
void dijkstra(int ** arr , int n , int start);

void dijkstra(int ** arr , int  n , int start)
{
	int i , j ,  count , mindist; 
	int **cost = (int ** )calloc(n ,sizeof(int *));
	for(i = 0 ; i <  n ; i++)
	{
		cost[i] = (int *)calloc(n , sizeof(int *));
	}
	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			if(i == j)
				arr[i][j] = 0;
			else if(arr[i][j] == 0)
				cost[i][j] = 9999;
			else
				cost[i][j] = arr[i][j];
		}
	}
	printf("\n");
	print(cost , n );
	int *visited = (int *)calloc(n,sizeof(int));
	int *distance = (int *)calloc(n,sizeof(int));
	int *pred = (int *)calloc(n,sizeof(int));
	for(i = 0 ; i < n ; i ++)
	{
		distance[i] = cost[start][i];
		pred[i] = start;
		visited[i] = 0 ;
	}
	distance[start] = 0 ;
	visited[start] = 1;
	count = 1;
	int nextnode;
	while(count < n -1 )
	{
		mindist = 9999;
		for(i = 0 ; i < n ; i++)
		{
			if(distance[i] < mindist && !visited[i])
			{
				mindist = distance[i];
				nextnode = i ;
				
			}
		}
		visited[nextnode] = 1;
		for(i = 0 ; i < n ; i++)
		{
			if( !visited[i])
			{
				if(mindist + cost[nextnode][i] < distance[i])
				{
					distance[i] = mindist + cost[nextnode][i];
					pred[i] = nextnode;
				}
			}
		}
		count ++;
	
	}
	printf("\nThe shortest paths to all vertices from source %d is as follows :\n",start);
	for(i = 0 ; i < n ; i++)
	{
		printf("Distance from source to vertex %d = %d\n",i+1,distance[i]);
	}
	free(distance);
	free(visited);
	free(cost);
	free(pred);
	
}
void print(int ** arr , int n)
{
	int i , j;
	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			printf("   %d   ",arr[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int j , w , ch, dir, u , v, n , i ;
	printf("\nFor undirected graph, Enter 1.\nFor directed graph,Enter 2.\nChoice=>");
	scanf("%d",&dir);
	n = 0;		
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
	switch(dir)
	{
		case 1 :
			
				do{
					printf("\nEnter vertex pair (u,v) )between which there must be an edge :\n");
					scanf("%d %d",&u,&v);
					printf("\nEnter edge cost: \n");
					scanf("%d",&w);
					if(u > n || v > n || u < 1 || v < 1 || w < 1)
					{
						while(u > n || v > n || u < 1 || v < 1 || w < 1)
						{
							printf("\nNeither vertex of the vertex pair can be be > n or < 1 AND Edge Cost also cannot be < 1.");			
							printf("\Enter vertex pair (u,v) )between which there must be an edge :\n");
							scanf("%d %d",&u,&v);
							printf("\nEnter edge cost: \n");
							scanf("%d",&w);
							
						}	
					}
					arr[u-1][v-1] = w;
					arr[v-1][u-1] = w;
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
					printf("\nEnter edge cost: \n");
					scanf("%d",&w);
					
					if(u > n || v > n || u < 1 || v < 1 || w < 1)
					{
						while(u > n || v > n || u < 1 || v < 1 || w < 1)
						{
							printf("\nNeither vertex of the vertex pair can be be > n or < 1.");				
							printf("\Enter source vertex :");
							scanf("%d",&u);
							printf("\nEnter destination vertex :");
							scanf("%d",&v);
							printf("\nEnter edge cost: \n");
							scanf("%d",&w);
						
						}	
					}
					arr[u-1][v-1] = w;
					printf("\nEnter 1 to add more edges.\nEnter 0 to end.\nChoice=>");
					scanf("%d",&ch);				
						
				}while(ch != 0);
				
				
				break;
			
	
		default :
			printf("\nInvalid choice.");
	}
	print(arr,n);
	printf("\nEnter source vertex from which you want to find shortest path to all other vertices : \n");
	int source;
	scanf("%d",&source);
	dijkstra(arr, n , source-1);	
}
