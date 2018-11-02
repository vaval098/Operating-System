#include <iostream>
using namespace std;
int main()
{	
	int p,pf,i,j,n,k;
	int avail,flag=0, hit=0;
    cout << "Enter the total pages: "<<endl;
	cin >> p;
	int rs[p];
	cout << "Enter the page numbers: "<<endl;
    for(i=0;i<p;i++)
    cin >> rs[i];
    cout << "Enter the number of frames: "<<endl;
    cin >> pf;
	int frame[pf];
	for(i=0;i<pf;i++)
        frame[i]= -1;
    
    cout<<"Page Frame initially contains: "<<endl;
    for(i=0;i<pf;i++)
    cout<<frame[i]<<"\t";
    
	j=0;
	cout <<"\n \nRef string\t  Page Frames"<<endl;
    for(int i=0;i<p;i++) 
	{    
		cout << rs[i] <<"\t\t";
        avail=0;
    	for(int k=0;k<pf;k++)
			if(frame[k]==rs[i])
            {
		    avail=1;
		    hit++;
		    }
        
		if (avail==0){
            frame[j]=rs[i];
            j=(j+1)%pf;
            flag++;
            for(int k=0;k<pf;k++)
            cout << frame[k] << "\t";
		}
        cout << endl;
	}
	cout << "\nTotal Page Hit Is= " << hit<<endl;
    cout << "Total Page Fault Is= " << flag;
    return 0;
}
