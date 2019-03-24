#include<iostream>
#include<cstdlib>//for using rand() and srand() and RAND_MAX
#include<ctime>//for using time()
#include<algorithm>//for using min_element and max_element
using namespace std;

//prints the array
void print_array(int *data,int size){
    for(int i=0;i<size;i++)
    {
        cout<<data[i]<<" ";
    }
}

//generate random array of integer
int* get_random_data(int size)
{
    int* array = new int[size];
    srand(time(NULL));
    while(size>=0)
    {
        array[--size]=(100*rand())/RAND_MAX;
    }
    return array;
}

void Bubble_sort(int* data,int size)//in one iteration place the larger element at last in second iteration place the second element at the second last...........
{
    for(int i=1;i<size;i++)
        for(int j=0;j<size-i;j++)
            if(data[j]>data[j+1])
                swap(data[j],data[j+1]);
}

void Modified_Bubble_sort(int* data,int size)//If Do not swap then flag becomes 1 and saves other iteration of bubble short.
{
    for(int i=1,sorted;  i<size;  i++)
    {
        sorted=1;

        for(int j=0;j<size-i;j++)
            if(data[j]>data[j+1])
                swap(data[j],data[j+1]),sorted=0;

        if(sorted==1) break;
    }
}

int find_min(int* data,int size,int min)//returns index of array where minimum data is stored from index i
{
    for(int j=min+1;j<size;j++)
            if(data[min]>data[j])
                min=j;
    return min;
}

void Selection_sort(int* data,int size)//Find minimum and swap with first elements find min from second element and swap with the second element......
{
    int min;
    for(int i=0;i<size-1;i++)
    {
       min = find_min(data,size,i);
       if(data[min] < data[i])
        std::swap(data[min] , data[i]);
//Other way around for doing the same thing by using std::min_element()
//       int *min=std::min_element(data+i,data+size);
//        if(*(min)<data[i])
//            swap(data[i],*(min));
    }
}

void Insertion_sort(int* data,int size)//Arrange data one by one where data supposed to be two side sorted array
{
    int temp,j;
    for(int i=1;i<size;i++)
    {
        temp=data[i];

        for(j=i-1; j>=0 && temp<data[j] ;j--)
            data[j+1]=data[j];

        data[j+1]=temp;
    }
}

void Quick_sort(int* data,int left , int right)//Divide array by placing  all ascending at the right and descending at left recursively.
{
    int l = left;
    int r = right - 1;
    int size = right - left;

    if(size>1){
        int pivot = data[rand() % size + l];
        while(l<r)
        {
            while(data[r]>pivot && r>l ){
                r--;
            }
            while(data[l]<pivot && l<=r ){
                l++;
            }
            if(l<r){
                swap(data[l],data[r]);
                l++;
            }
        }
        Quick_sort(data,left,l);
        Quick_sort(data,r,right);
    }
}

//Just for fun it's actually a selction sort just trying to write in online.
void My_Sort(int* array,int size){
    for(int i = size-1 ; i >= 0 ; i--)
          std::swap(*std::max_element(array,array+i+1),*(array+i));//using *(array+i+1) in max element parameter because range is : [first,last).
//    for(int i = 0 ; i < size ; i++)
//        std::swap(*std::min_element(array+i,array+size),array[i]);
}

int main()
{
    int size=10;
    int *data = get_random_data(size);cout<<"Unsorted Data : ";print_array(data,size);
    //      Bubble_sort(data,size);
    //      Modified_Bubble_sort(data,size);
    //      Selection_sort(data,size);
    //      Insertion_sort(data,size);
    //      My_Sort(data,size);
          Quick_sort(data,0,size);
    cout<<"\n\nSorted Data : ";print_array(data,size);
    delete[] data;
    return 0;
}
