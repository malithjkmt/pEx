/* Did all the coding looking at the graph (http://en.wikipedia.org/wiki/File:Quicksort-diagram.svg) illustrated in Wikipedia.
Unfortunately I got a bugger Bug on the 56th line. Need help there.  :) */


#include <iostream>
using namespace std;

int quickSort(int *arr, int k,int s);   // prototyping the functions

int _array[] = {3,7,8,5,2,1,9,5,4};        // array to be sorted
int n = (sizeof(_array)/sizeof(_array[0]));   // get the size of the array

int main()
{

    quickSort(_array,0, n);     // calling the sorting function

    for (int i = 0; i< n; i++){     // printing the sorted function
        cout << _array[i] << "\t";
    }
    return 0;
}


int quickSort(int *arr,int L, int R)
{
    if(L==R){               // Terminating condition
        return 0;
    }
    int *pivot = (arr + R - 1); // selecting the pivot (I chose it as the last value of the array)
    int pValue = *pivot;        // copying the value of the pivot
    int left = L;               // left mark
    int right = R-2;            //right mark
    int temp = 0;               // temporary var to be used while swapping
    while(left<right){

        while(*(arr+left)<pValue){  // move left mark until it meets a value greater than the pivot value
            left++;
        }
        while(*(arr+right)>pValue){     // move right mark until it meets a value smaller than the pivot value
            right--;
        }
        if(left<right){         // check whether two marks have passed each other
            temp = *(arr+right);    // if not, interchange values as :-  left >> pivot, pivot >> right, right >> left (using temp)
            *(arr+right) = *pivot;

            *pivot = *(arr+left);
            *(arr+left) = temp;
            pivot = (arr+right);
            right--;
        }
        else{
             *(arr+left+1) = *(arr+left);   // place last values in right places
             *(arr+left) =  pValue;
             // at this point, all values below pivot are in the left and others are in the right side of the pivot
             quickSort(arr,0, left);    // calling again quickSort function to sort the left side from the pivot

             /*quickSort(arr+left+1,0, n-1-left); // calling again quickSort function to sort the right side from the pivot
             But I got a bug here, It's hard to see :(
            */
        }
        }
}






