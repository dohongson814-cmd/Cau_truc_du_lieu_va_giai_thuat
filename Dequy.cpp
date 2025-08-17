#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int MaxLeft(int a[],int low,int mid)
{
	int maxSum=INT_MIN,sum=0;
	for (int i=mid;i >= low;i--){
	sum+=a[i];
	if (sum>maxSum) maxSum=sum;
	}
	return maxSum;
}

int MaxRight(int a[],int mid1,int high)
{
	int maxSum=INT_MIN,sum=0;
	for (int i=mid1;i<=high;i++){
	sum+=a[i];
	if (sum>maxSum) maxSum=sum;
	}
	return maxSum;
}


int MaxSub(int a[],int low, int high)
{
	if (low == high) return a[low]; // ch? còn 1 ph?n t?
	else{
	int mid=(low+high)/2;
	int WL=MaxLeft(a,low,mid);
	int WR=MaxRight(a,mid+1,high);
	int WM=WL+WR;
	return max(WL,max(WR,WM));
	}
}
int main() {
    int a[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(a) / sizeof(a[0]);

    int ans = MaxSub(a, 0, n - 1);
    printf("Tong day con lon nhat = %d\n", ans);

    return 0;
}
