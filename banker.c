#include<stdio.h>
#include<stdlib.h>
#define NUMBER_OF_CUSTOMERS 5
#define NUMBER_OF_RESOURCES 3

void print(int x[][10],int n,int m){
	int i,j;
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<m;j++){
			printf("%d\t",x[i][j]);
		}
	}
}

int request_resources(int customer_num, int request[]) {
  int reqmat[1][10];
	int i;
	printf("\n Enter additional request :- \n");
	for(i=0;i<m;i++){
		printf(" Request for resource %d : ",i+1);
		scanf("%d",&reqmat[0][i]);
	}

	for(i=0;i<m;i++)
		if(reqmat[0][i] > N[pid][i]){
			printf("\n Error encountered.\n");
			exit(0);
	}

	for(i=0;i<m;i++)
		if(reqmat[0][i] > AV[0][i]){
			printf("\n Resources unavailable.\n");
			exit(0);
		}

	for(i=0;i<m;i++){
		AV[0][i]-=reqmat[0][i];
		A[pid][i]+=reqmat[0][i];
		N[pid][i]-=reqmat[0][i];
	}
}

int release_resources(int customer num, int release[]);

int main() {
  /* the available amount of each resource */
  int available[NUMBER_OF_RESOURCES];
  /*the maximum demand of each customer */
  int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
  /* the amount currently allocated to each customer */
  int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
  /* the remaining need of each customer */
  int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];
  int ret, n, m, pid, ch;
  printf("\n DEADLOCK AVOIDANCE USING BANKER'S ALGORITHM\n");
	accept(A,N,M,W,&n,&m);
	ret=banker(A,N,W,n,m);
	if(ret !=0 ){
		printf("\n Do you want make an additional request ? (1=Yes|0=No)");
		scanf("%d",&ch);
		if(ch == 1){
			printf("\n Enter process no. : ");
			scanf("%d",&pid);
			res_request(A,N,W,pid-1,m);
			ret=banker(A,N,W,n,m);
			if(ret == 0 )
				exit(0);
		}
	}
  else  exit(0);
	return 0;
}
