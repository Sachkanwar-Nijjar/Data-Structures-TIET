//      Q1
#include<iostream>
using namespace std;
void create(int a[],int n)
{
	cout<<"enter the elements of your aaray"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void display(int a[],int n)
{
	cout<<"\n your array is=";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}
}
void insert(int a[],int &n,int ele,int pos)
{
	n++;
	for(int i=n-1;i>=pos;i--)
	{
		a[i]=a[i-1];
	}
	a[pos-1]=ele;
}
void delete_ele(int a[],int &n,int pos)
{
	for(int i=pos-1;i<n-1;i++)
	{
			a[i]=a[i+1];
	}
	n--;
}
void lin_search(int a[],int n,int ele)
{
	for(int i=0;i<n;i++)
	{
		if(ele==a[i])
		{
			cout<<"\n element found at "<<i+1;
		}
	}
}
int main()
{
	int k;
	int n;
			cout<<"\n enter the size of array=\n";
			cin>>n;
			int a[n];
	cout<<"select accordingly for a array";
	cout<<"\n1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT";
	again:
	cout<<"\nenter the opperation number=\n";
	cin>>k;
	
		switch(k)
		{
		case 1:
			create(a,n);
			goto again;
			break;
        case 2:
			display(a,n);
			goto again;
			break;
		case 3:
			{
			int ele,pos;
			cout<<"enter the element you want to store and at which positon\n";
			cin>>ele;
			cin>>pos;
			insert(a,n,ele,pos);
			cout<<"\nafter insertion";
			display(a,n);
			goto again;
			break;
		}
		case 4:
			{
			int ele,pos;
			cout<<"enter the positoin you want to delete=\n";
			cin>>pos;
			delete_ele(a,n,pos);
			cout<<"\nafter deletion";
			display(a,n);
			goto again;
			break;	
}
		case 5:
		{
				int ele;
			cout<<"\n enter the element you want to search=\n";
			cin>>ele;
			lin_search(a,n,ele);
			goto again;
			break;}
		default:
			cout<<"eop"<<endl;
}
	
	return 0;
		
}




// Q2
#include<iostream>
using namespace std;
void del(int a[],int &n,int pos)
{
	for(int i=pos-1;i<n-1;i++)
	{
			a[i]=a[i+1];
	}
	n--;
}
int main()
{
	int n;
	cout<<"enter the no. of ele in the array=\n";
	cin>>n;
	int a[n];
	cout<<"\nenter the ele of array\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]==a[j+1])
			{
				del(a,n,j+1);
				j--;//to check that pos again
			}
			else
			{
				continue;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<endl<<a[i];
	}
	return 0;
}



//Q3
#include<stdio.h>
int main()
{
int i;
int arr[5] = {1};
for (i = 0; i < 5; i++)
printf("%d",arr[i]);
return 0;
}




//Q4 a
#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"\nenter no. of elemnets in array=";
	cin>>n;
	int a[n];
	cout<<"\nenter elements in your array=\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	cout<<"\nyour elements are=\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}
	for(int i=0;i<n/2;i++)
	{
		swap(a[i],a[n-i-1]);
	}
	cout<<"\nyour reversed elements are=\n";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}
	
}

//  Q4 b
#include<iostream>
using namespace std;
int main()
{
	int a[2][2]={{1,2},{3,4}},b[2][2]={{1,0},{0,1}},d[2][2]={0};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int same=0;same<2;same++)
			{
				d[i][j]=d[i][j]+(a[i][same]*b[same][j]);
			}
		}
	}
	for(int i=0; i<2; i++) {
    for(int j=0; j<2; j++) {
        cout << d[i][j] << " ";
    }
    cout << endl;
}

}


// Q4 c
#include<iostream>
using namespace std;
int main()
{
int r,c;
cout<<"enter the number of rows and column of your matrix"<<endl;
cin>>r>>c;
int a[r][c],b[c][r];
cout<<"\n enter the elements of your matrix\n";
for(int i=0;i<r;i++)
{
	for(int j=0;j<c;j++)
	{
		cin>>a[i][j];
	}
}
cout<<"\nyour matrix is\n";
for(int i=0;i<r;i++)
{
	for(int j=0;j<c;j++)
	{
		cout<<a[i][j]<<" ";
	}
	cout<<endl;
}
for(int i=0;i<c;i++)
{
	for(int j=0;j<r;j++)
	{
		b[i][j]=a[j][i];
	}
}
cout<<endl;
for(int i=0;i<c;i++)
{
	for(int j=0;j<r;j++)
	{
		cout<<b[i][j]<<" ";
	}
	cout<<endl;
}
}

//Q5

#include<iostream>
using namespace std;
int main()
{
	int r,c;
cout<<"enter the number of rows and column of your matrix"<<endl;
cin>>r>>c;
int a[r][c];
cout<<"\n enter the elements of your matrix\n";
for(int i=0;i<r;i++)
{
	for(int j=0;j<c;j++)
	{
		cin>>a[i][j];
	}
}
cout<<"\nyour matrix is\n";
for(int i=0;i<r;i++)
{
	for(int j=0;j<c;j++)
	{
		cout<<a[i][j]<<" ";
	}
	cout<<endl;
}
for(int i=0;i<r;i++)
{
	int s=0;
	for(int j=0;j<c;j++)
	{
		s=s+a[i][j];
	}
	cout<<"\n sum of elemets of "<<i+1<<"row="<<s<<endl;
}
for(int i=0;i<c;i++)
{
	int s=0;
	for(int j=0;j<r;j++)
	{
		s=s+a[j][i];
	}
	cout<<"\n sum of elemets of "<<i+1<<"column="<<s<<endl;
}
return 0;
}

