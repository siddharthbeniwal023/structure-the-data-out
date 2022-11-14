#include<iostream>
#include<vector>
using namespace std;

void bubblesort(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++){ // for round from 1 to n-1
        for(int j=0;j<n-i;j++){ // for checking till the sorted array 
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}

int main(){
    vector<int> arr = {7,6,5,3,2,1,8,9};
    bubblesort(arr);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i];
    return 0;
}