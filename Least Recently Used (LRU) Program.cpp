#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
    int p,pf,i,count=0;
	int page[p],frame[pf],fcount[pf]; 
    cout<<"Enter the No. of Pages: ";
    cin>>p;  
	cout<<"Enter the Reference String:\n";
    for(i=0;i<p;i++)
        cin>>page[i]; 

    cout<<"Enter the No of frames: ";
    cin>>pf;         
	for(i=0;i<pf;i++)
    {
        frame[i]=-1; 
        fcount[i]=0; 
    }

	i=0;
    while(i<p)
    {
        int j=0,flag=0;
        while(j<pf)
        {
            if(page[i]==frame[j])
			{  
            flag=1;
            fcount[j]=i+1;
        	}
        j++;
    	}   
        j=0;  
        cout<<"\n-----------------------------------\n";
        cout<<"\nRef string  |  Page Frames\n";
        cout<<"\t"<<page[i]<<"   |";   
        if(flag==0)
        {
            int min=0,k=0;
            while(k<(pf-1))
            {
               if(fcount[min]>fcount[k+1]) 
                  min=k+1;
                k++;
            }
	        frame[min]=page[i]; 
	        fcount[min]=i+1;   
	        count++;
	        while(j<pf)
	        {
	            cout<<"\t|"<<frame[j]<<"|";
	            j++;
			}
        }
           i++; 
    }
    cout<<"\n-----------------------------------\n";
	cout<<"\nTotal Page Fault is: "<<count;
    return 0;
}       
