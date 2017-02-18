#include <stdio.h>
int funmax(int,int,int[],int[]);
int max (int,int);
int main() {
	//code
	int n,w,i,j,t;
	int value[100],weight[100],result[100];
	scanf("%d",&t);

	for(i=0;i<t;i++)
	{
	    scanf("%d%d",&n,&w);
	    for(j=0;j<n;j++)
	    scanf("%d",&value[i]);
	    for(j=0;j<n;j++)
	    scanf("%d",&weight[i]);
	    result[t]=funmax(n,w,value,weight);


	}
	for(i=0;i<t;i++)
	printf("%d\n",result[i]);
	return 0;
}

int funmax(int n,int cap, int val[],int weig[])
{
    int i,j;
    int table[101][101];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=cap;j++)
        {
            if(i==0||j==0)
            table[i][j]=0;
            else{

            if(weig[i-1]<=j)
            table[i][j]=max(val[i-1]+table[i-1][j-weig[i-1]] , table[i-1][j]);

            else
            table[i][j]=table[i-1][j];
            }
        }
    }
    return table[n][cap];

}

int max(int i,int j)
{
    return (i>j)?i:j;
}
