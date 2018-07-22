# include <iostream>
#include<stdio.h>
# include <limits.h>
using namespace std;
// A function to get maximum betwwen  number
int maximum(int a, int b)
{
     if(a>b){
        return a;
     }
    else{
        return b;

     }
}

/* Function to get minimum number of trials needed in worst
  case */
int min_trail(int eggs, int floors)
{
    /* Suppose there are  no floors, then no trials needed. OR if there is
 one floor, one trial needed.*/
    if (floors == 1 || floors == 0)
        return floors;

    // We need nth trials for one egg and nth floors
    if (eggs == 1)
        return floors;

    int min = INT_MAX, x, result;

    // Consider all droppings from 1st floor to kth floor and
    // return the minimum of these values plus 1.
    for (x = 1; x <= floors; x++)
    {
        result = maximum(min_trail(eggs-1, x-1), min_trail(eggs, floors-x));
        if (result < min)
            min = result;
    }

    return min + 1;
}

/*Main program */
int main()
{
    int eggs , floors;
    cout<<"Enter the number of eggs: ";
    cin>>eggs;
    cout<<"\nEnter the number of floors: ";
    cin>>floors;
    cout<<"\n The minimum number of trials in worst case with " <<eggs<<" eggs "<< floors <<" floors is :"<<min_trail(eggs, floors);
    return 0;
}
