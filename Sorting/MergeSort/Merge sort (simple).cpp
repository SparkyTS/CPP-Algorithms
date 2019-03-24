#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int* get_random_data(int size)//Generate random array of integer
{
    int* data = new int[size];

    srand(time(NULL));
        for(int i=0;i<size;i++)
        data[i]=100*rand()/RAND_MAX;
   return data;
}
print_array(int* array , int size )
{
    for(int i=0;i<size;i++)
        cout<<array[i]<<" ";
}

merge(int* array,int left , int mid , int right)
{
int i,j,k;
int n1=mid-left+1;
int n2=right-mid;
int l_array[n1] , r_array[n2];

for(i=0 ; i<n1 ; i++)
    l_array[i] = array[left + i];
for(j=0 ; j<n2 ; j++)
    r_array[j] = array[mid  + j + 1];

i=0;j=0;k=left;

    while( n1 && n2)
    {
        if(l_array[i] < r_array[j]){
            array[k] = l_array[i];
            i++,k++,n1--;
        }
        else{
            array[k] = r_array[j];
            k++,j++,n2--;
        }
    }

    while(n1){
      array[k] = l_array[i];
       k++,i++,n1--;
    }


    while(n2){
        array[k] = r_array[j];
        k++,j++,n2--;
    }
}

merge_sort(int* array,int left,int right)
{
    if(left<right)
    {
     int mid = (left+right)/*(right - left)*/ / 2;
     merge_sort(array , left  , mid);
     merge_sort(array , mid+1 , right);

     merge(array,left,mid,right);
    }
}

main()
{
int* data,size=10;
data=get_random_data(size);
cout<<"Unsorted Data : ";

print_array(data,size);

merge_sort(data,0,size-1);

cout<<"\n  Sorted Data : ";
print_array(data,size);
}
