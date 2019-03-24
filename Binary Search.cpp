#include<iostream>
#include<algorithm>
#include<vector>


//using the while loop
void Binary_search(const std::vector <int> &array,int find,int size)
{
    int low=0,high=size-1,mid;
    while(low<=high)
    {
        mid = ( low + high ) / 2 ;
        if(array.at(mid) == find){
            std::cout << array[mid] << " Found At index " <<mid <<"\n";
            return;
        }
        else if(array[mid]>find)
            high = mid - 1;
        else
            low = mid + 1;
    }
    std::cout << "Not Found.";
}

//using the recursive method : returns true(1) if the element is found
bool binary_recursive_serach(const std::vector<int> &array, int left, int right, int find){

    if(right-left < 0)
        return false; //indicates not found

    int mid = (left + right) / 2;

    if(array[mid] == find)
        return true;
    else if(array[mid] > find)
        return binary_recursive_serach(array,left,mid-1,find);
    else
        return binary_recursive_serach(array,mid+1,right,find);
}

main()
{
    std::vector <int> array = {1,8,5,4,3,10,7,2,9,6};

    //sorting the data before applying the binary search.
    std::sort(array.begin(),array.end());

    //printing the sorted array
    for(int x : array)
        std::cout << x  << ", " ;
    std::cout << std::endl;

    //calling the binary search function
    int find;
    std::cout << "Enter a Number To find in array using binary search : ";
    std::cin >> find;
    Binary_search(array,find,array.size());

//    std::cout << binary_recursive_serach(array,0,array.size(),10);

}
