#include<iostream>
using namespace std;

int alloc[50][50],maxi[50][50],need[50][50],avail[50];

int check_safety(int j,int nr)
{
	for(int i=0;i<nr;i++)
	{
		if(need[j][i]>avail[i])
		return 0;
	}
	return 1;
}

int check(bool a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==false)
		return 0;
	}
	return 1;
}
int main()
{
	int np=100;
	int nr=100;
	
	cout<<"Enter the no of processes : "<<endl;
	cin>>np;
	cout<<"Enter the no of resources : "<<endl;
	cin>>nr;	
	
	cout<<"Enter the allocation data : \n";
	for(int i=0;i<np;i++)
	for(int j=0;j<nr;j++)
	cin>>alloc[i][j];
	cout<<"Enter the requirement data : \n";
	for(int i=0;i<np;i++)
	for(int j=0;j<nr;j++)
	cin>>maxi[i][j];
	
	for(int i=0;i<np;i++)
	for(int j=0;j<nr;j++)
	need[i][j]=maxi[i][j]-alloc[i][j];
	
	cout<<"Enter the availability matrix : \n";
	for(int i=0;i<nr;i++)
	cin>>avail[i];
	
	int ex_it=nr;
	int flg;
	bool completed[np];
	while(10)
	{
		for(int i=0;i<np;i++)
		{
			if(!completed[i] && check_safety(i,nr))
			{
				
				for(int j=0;j<nr;j++)
				avail[j]+=alloc[i][j];
			}
			completed[i]=true;
		}
		flg=check(completed,np);
		ex_it--;
		if(flg==1 || ex_it==0)
		break;
	}
	
	cout<<"The final availability matrix \n";
	for(int i=0;i<nr;i++)
	cout<<avail[i]<<"  ";
	
//	cout<<"\n --------- Result ------------- \n";
	if(flg==1)
	cout<<"\nThere is no deadlock";
	else
	cout<<"\nSorry there is a possibility of deadlock";
	
	return 0;
}
