#include<bits/stdc++.h>
using namespace std;
int main()
{	
	int n,i;
	float avgwt=0.0,avgtat=0.0;
	cout<<"Enter number of Process:\n";
	cin>>n;
	int p[n],at[n],c=0,ct[n],tat[n],wt[n],a[n];
	cout<<"\nEnter Burst Time for Each Process\n";  
	for(i=0;i<n;i++)                
	{
		cin>>p[i];
		at[i]=0;   
		a[i]=p[i];
	}
	sort(p,p+n);  
	
	for(i=0;i<n;i++)
	{
		c=c+p[i];
		ct[i]=c;
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-p[i];    
		avgwt=avgwt+wt[i];    
		avgtat=avgtat+tat[i];	
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(p[i]==a[j])    
			{
				tat[j]=ct[i];
				wt[j]=wt[i];
			}
		}
	}
	for(i=0;i<n;i++)
		wt[i]=tat[i]-a[i];	
	
	cout<<"\nWaiting Time"<<endl;
	for(i=0;i<n;i++)
		cout<<"wt["<<i<<"]="<<wt[i]<<endl;
		
	cout<<"\nTurn-Around Time"<<endl;
	for(i=0;i<n;i++)
    	cout<<"tat["<<i<<"]="<<tat[i]<<endl;	
	
	cout<<"\nAverage Waiting Time="<<avgwt/n<<endl;
	cout<<"avg Turn-Around Time="<<avgtat/n<<endl;
}
