#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int* get_random_data(int size)//Generate random array of integer
{
    int* data = new int[size];
    /*
    ///For sorting char type of data
    Replace int*      with   char*
            new int   with   new char  && comment line 23 to 25
    data[0]='t';
    data[1]='a';
    data[2]='n';
    data[3]='a';
    data[4]='y';
    data[5]='_';
    data[6]='s';
    data[7]='h';
    data[8]='a';
    data[9]='h';
*/
    srand(time(NULL));
        for(int i=0;i<size;i++)
        data[i]=100*rand()/RAND_MAX;
   return data;
}
void print_array(int* array , int size )
{
    for(int i=0;i<size;i++)
        cout<<array[i]<<" ";
}
void merge(int* array1,int n1,int index1,int* array2,int n2,int index2,int* sorted,int index){
    while(n1 && n2)
    {
        if(array1[index1]<array2[index2]){
            sorted[index]=array1[index1];
            index++,index1++,n1--;
        }
        else{
            sorted[index]=array2[index2];
            index++,index2++,n2--;
        }
    }
    while(n1){
        sorted[index]=array1[index1];
        index++,index1++;n1--;
    }
    while(n2){
        sorted[index]=array2[index2];
        index++,index2++,n2--;
    }
}
void mergepass(int* const array,int size,int C,int* const sorted)
{                        //C=current_no_elements
    int P = size/(2*C);  //no of pair
    int m_size = 2*C*P;  //size of array after merging two arrays
    int R = size-m_size; //Remaining Array to merge
    int LB;              //Lower Bound - Index of first element in array
    for(int j=0;j<P;j++){
        LB=2*j*C;
        merge(array,C,LB,array,C,LB+C,sorted,LB);
    }
    if(R<=C)           //IF only one sub array left
    {
        for(int j=0;j<R;j++)
            sorted[m_size+j]=array[m_size+j];//Copying data as it is
    }
    else
    {
        merge(array,C,m_size,array,R-C,m_size+C,sorted,m_size);
    }
}
void merge_sort(int* array,int size)
{
    int C=1;int* sorted=new int[size];
    while(C<size)
    {
     mergepass(array,size,C,sorted);
     mergepass(sorted,size,2*C,array);
     C=4*C;
    }
}
int main()
{
    int* data,size=10;
    data=get_random_data(size);
    cout<<"Unsorted Data : ";
    print_array(data,size);
    merge_sort(data,size);
    cout<<"\n  Sorted Data : ";
    print_array(data,size);
    return 0;
}
