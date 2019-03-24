#include<iostream>
#include<algorithm>
#include<functional>
main()
{
    std::vector <int> Vector {5,3,4,1,2,7,10,6,8,9};
//    std::sort(Vector.begin(),Vector.end()); //default Ascending Sorting
//      std::sort(Vector.begin(),Vector.end(),std::less <int>()); //Include functional less says Ascending Order
//        std::sort(Vector.begin(),Vector.end(),std::greater <int> ()); //Include functional greater says Descending Order
//            std::sort(Vector.begin(),Vector.end(),[] (int a , int b) {return a<b;}); //first element will be less than second so ultimately Ascending Sorting
//                std::sort(Vector.begin(),Vector.end(),[] (int a , int b) {return a>b;}); // first element will be greater than second so ultimately Descending
                    std::sort(Vector.begin(),Vector.end(),[](int a,int b) // Just to illustrate the Concept of Predicates (a and b)
                              {


//                                  if(a==1)//if a == 1 then don't sort move a to the back of the list
//                                    return false;
//                                  if(b==1)//move a to the front of list
//                                    return true;
                                  return a<b;
                              });
    for(int x : Vector)
        std::cout << x << "\n" ;
}
