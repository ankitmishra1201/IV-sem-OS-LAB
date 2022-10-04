#include<stdio.h>
#include<string.h>

void firstFit(int blockSize[], int m,
			int processSize[], int n)
{
	
	int allocation[n];

	
	memset(allocation, -1, sizeof(allocation));

	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				allocation[i] = j;
				blockSize[j] -= processSize[i];

				break;
			}
		}
	}

	printf( "\nProcess No.\tProcess Size\tBlock no.\n");
	for (int i = 0; i < n; i++)
	{

        printf("  %d\t\t%d\t\t",i+1,processSize[i]);
		if (allocation[i] != -1)
			printf("%d",allocation[i]+1);
		else
			printf("Not Allocated");
		printf("\n");
	}
}

void bestFit(int blockSize[], int m, int processSize[], int n)
{
    // Stores block id of the block allocated to a
    // process
    int allocation[n];

    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));

    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i=0; i<n; i++)
    {
        // Find the best fit block for current process
        int bestIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }

        // If we could find a block for current process
        if (bestIdx != -1)
        {
            // allocate block j to p[i] process
            allocation[i] = bestIdx;

            // Reduce available memory in this block.
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf( "\nProcess No.\tProcess Size\tBlock no.\n");
    for (int i = 0; i < n; i++)
    {
         printf("  %d\t\t%d\t\t",i+1,processSize[i]);
        if (allocation[i] != -1)
            printf("%d",allocation[i]+1);
        else
            printf("Not Allocated");
		printf("\n");
    }
}


// Driver code
int main()
{
	int m,n,c;
    printf("Enter the number of Blocks to be added in main Memory ");
    scanf("%d", &m);
    printf("\n");
    printf("Enter the number of processes ");
    scanf("%d", &n);
    printf("\n");
    int blockSize[m], processSize[n];
    printf("Enter the size of each block in main memory");
    for(int i=0;i<m;i++){
        scanf("%d", &blockSize[i]);
    }
    printf("\n");
     printf("Enter the size of each process");
    for(int i=0;i<n;i++){
        scanf("%d", &processSize[i]);
    }

    printf("Which fit do you wanna go for\n");
    printf("(1) First fit\n");
    printf("(2) First fit\n");
    scanf("%d",&c);

    switch (c)
    {
        case 1:
        firstFit(blockSize, m, processSize, n);
        break;

        case 2:
        bestFit(blockSize, m, processSize, n);
    
    }


	

	return 0 ;
}

