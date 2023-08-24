#include<stdio.h>
#include<stdlib.h>
void floyd(int ** arr , int n  );
void floyd(int ** arr, int n)
{
	int i , j , k ;
	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++ )
		{
			for(k=0; k< n ; k++)
			{
				if((arr[j][i] + arr[i][k] )< arr[j][k])
				{		
					arr[j][k] = arr[j][i] + arr[i][k];
				}
			}
		}
	}
	printf("\nThe matrix for the all pairs shortest path is as follows :\n");
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("   %d   ",arr[i][j]);
		}
		printf("\n");
	}

	
}
void main()
{
	int i , di , n = 0 ,  j , u,v ,  cost , ch, source , destination;
	while(n==0)
	{
		printf("Enter no. of vertices:");
		scanf("%d",&n);
		
	}
	int **arr = (int **)calloc(n,sizeof(int *));
	for(i=0; i  < n ; i++)
	{
		arr[i] = (int *)calloc(n,sizeof(int));
	}
	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			
			arr[i][j] = 9999;
			if(i==j)
				arr[i][j] = 0;
		}
	}
	//for(i=0;i<n;i++)
	printf("Enter 1 for Undirected and 2 for Directed Graph : ");
	scanf("%d",&di);
	switch(di)
    {
        case 1 :
                do
                {
                    printf("\nenter the node pair within which there must be an edge :\n");
					scanf("%d %d",&u,&v);
					printf("Enter the cost of the edge: ");
					scanf("%d",&cost);
                    if(u>n || v>n || u<1 || v<1 || cost <= 0)
                    {
                        while(u>n || v>n || u<1 || v<1 || cost <= 0)
                        {
                            printf("\nNeither Node pair cannot exceed n(no. of vertices :) nor Edge cost can be less than 1");
                            printf("\nenter the node pair within which there must be an edge :\n");
                            scanf("%d %d",&u,&v);
                            printf("Enter the cost of the edge: ");
							scanf("%d",&cost);
                                        
                        }
                        
                    }
                    arr[u-1][v-1] = cost;
                    arr[v-1][u-1] = cost;
                    printf("\nDo you want to enter more edges ? 1 => Yes, 0 => No \n");
                    scanf("%d",&ch);
                    
                }
                while(ch!= 0);
                break;
        
        case 2 :
                do
                {
                    printf("\nenter the node pair within which there must be an edge :\n");
                    printf("\nEnter the source vertex :");
                    scanf("%d",&u);
                    printf("\nEnter the destination vertex : ");
                    scanf("%d",&v);
                    if(u>n || v>n || u<1 || v<1 )
                    {
                        while(u>n || v>n || u<1 || v<1 )
                        {
                            printf("\nNode pair cannot exceed n(no. of vertices :)");
                            printf("\nenter the node pair within which there must be an edge :\n");
                            scanf("%d %d",&u,&v);
                                                
                        }
                        
                    }
                    arr[u-1][v-1] = cost;
                    printf("\nDo you want to enter more edges ? 1 => Yes, 0 => No \n ");
                    scanf("%d",&ch);
                    
                }
                while(ch!= 0);
                break;
         default : printf("choice should be either 1 or 2");

    }
    printf("\nThe input cost matrix is : \n");
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("    %d    ",arr[i][j]);
		}
		printf("\n");
	}
	
floyd(arr,n);
}

