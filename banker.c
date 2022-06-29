#include <stdio.h>
int main()
{

	int n, m, i, j, k;
	printf("Enter the no. of processes\n");
	scanf("%d",&n);
	printf("Enter the no. of resource types\n");
	scanf("%d",&m);
	int alloc[n][m];
	int max[n][m];
	for(i=0;i<n;i++)
	{
	    printf("Process P%d: Enter allocation of resource types\n",i);
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
	    printf("Process P%d: Enter max of resource types\n",i);
		for(j=0;j<m;j++)
		{
			
			scanf("%d",&max[i][j]);
		}
	}
	/*int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
						{ 2, 0, 0 }, // P1
						{ 3, 0, 2 }, // P2
						{ 2, 1, 1 }, // P3
						{ 0, 0, 2 } }; // P4

	int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix
					{ 3, 2, 2 }, // P1
					{ 9, 0, 2 }, // P2
					{ 2, 2, 2 }, // P3
					{ 4, 3, 3 } }; // P4*/
	int avail[m];
	printf("Enter available resources for each resource type\n");
	for(i=0;i<m;i++)
	scanf("%d",&avail[i]);

	//int avail[3] = { 3, 3, 2 }; // Available Resources

	int finish[n], safeseq[n], ind = 0;
	for (k = 0; k < n; k++) {
		finish[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (finish[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					safeseq[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					finish[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
	if(finish[i]==0)
	{
		flag=0;
		printf("The following system is not safe");
		break;
	}
	}
	
	if(flag==1)
	{
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", safeseq[i]);
	printf(" P%d", safeseq[n - 1]);
	}
	
	return (0);

}
