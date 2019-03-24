#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Heap{
int* array;
int count;
};

Heap* Create_Heap(int capacity)
{
    Heap* h = new Heap;
    h->count=0;
    h->array=new int[capacity];
    return h;
}
print_heap(Heap* h)
{
    for(int i=0;i<h->count;i++)
        cout<<h->array[i]<<" ";
}
get_random_data(Heap *h,int size)//Generate random array of integer
{
    srand(time(NULL));

      h->count=size;
      while(size>=0)
        h->array[--size]=100*rand()/RAND_MAX;
///Generating Worst Case Data
//    for(int i=size,j=0;i>0;i--,j++)
//        h->array[j]=i;
}

inline Left_Child(int i)
{
    return (2*i+1);
}

inline Right_Child(int i)
{
    return (2*i+2);
}

void Arrange_Heap(Heap *h,int size,int i)
{
    int l,r,max=i;
    l=Left_Child(i);
    r=Right_Child(i);

    if(l<size && h->array[l] > h->array[max])
        max=l;

    if(r<size && h->array[r] > h->array[max])
        max=r;

    if(max!=i){
        swap(h->array[i],h->array[max]);
        Arrange_Heap(h,size,max);
    }
}

void Build_Heap(Heap *h,int size)
{
    get_random_data(h,size);
    cout<<"Unsorted Data : ";print_heap(h);
    for(int i=(size/2)-1;i>=0;i--)
    Arrange_Heap(h,h->count,i);
}
main()//Heap Sorting
{
    int size=15;

    Heap *h=Create_Heap(size);

    Build_Heap(h,size);

    //Sorting Data by Repeatedly Deleting Element at Root Node
    for(int i=size-1;i>=0;i--)
    {
        swap(h->array[0],h->array[i]);
        Arrange_Heap(h,i,0);
    }

    cout<<"\nAfter Sorting : ";print_heap(h);
}
