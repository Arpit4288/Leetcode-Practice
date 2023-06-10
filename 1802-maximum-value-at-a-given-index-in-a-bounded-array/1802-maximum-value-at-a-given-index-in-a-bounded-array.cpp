class Solution {
public:
	bool check(int mid,int n1,int n2,int maxSum)  // checking if value at index=mid, does there exist a valid sequence such that sum of sequence is <= maxSum.
	{
		long long sum=0;
		if(mid<=n1)
		{
			sum+= 1ll*mid*(mid+1)/2 +(n1+1-mid);
		}
		else
		{
			sum+=1ll* mid*(mid+1)/2;
			sum-= 1ll*(mid-n1-1)*(mid-n1)/2;
		}
		if(sum>maxSum)
			return false;
		if(mid<=n2)
		{
			sum+=1ll* mid*(mid-1)/2 +(n2+1-mid);
		}
		else
		{
			sum+= 1ll*mid*(mid-1)/2;
			sum-= 1ll*(mid-n2-1)*(mid-n2)/2;
		}
		return sum<=maxSum;
	}
	int maxValue(int n, int index, int maxSum) {
		int i=1,j=maxSum,ans=1;
		while(i<=j)
		{
			int mid=(i+j)/2;
			if(check(mid,index,n-1-index,maxSum)) // Binary search on all possible values.
			{
				i=mid+1;
				ans=mid;
			}
			else
				j=mid-1;

		}
		return ans;
	}
};