#include<iostream>
#include<vector>
using namespace std;

void selectionsort(vector<int> &arr, int n){
    
    int minindex=0;

    for(int i=0;i<n-1;i++){
        //specifying min index to the ith element first
        minindex=i;
        for(int j=i+1;j<n-1;j++){

            // check the smallest element in the whole array 
            if(arr[minindex]>arr[j])
                minindex=j;
        }
        //swap the starting one with the min element found
        swap(arr[minindex],arr[i]);
    }
}

int main(){
    vector<int> arr={7,6,5,3,2,1,9};
    int n=arr.size();
    selectionsort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}