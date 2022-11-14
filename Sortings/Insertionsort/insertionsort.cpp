#include<iostream>
#include<vector>
using namespace std;

// TC : O(n^2) , Best O(n) 
// SC : O(1)


void insort(vector<int> &arr){
    int i=1;
    int j=0;
    while(i<arr.size()){
        int temp=arr[i];
        j=i-1;
        while(j>=0){
            if(arr[j]>temp){ //shift
                arr[j+1]=arr[j];
            }
            else //do nothing
                break;
            j--;
        }
        arr[j+1]=temp; // insert value
        i++;
    }
}

int main(){
    vector<int> arr = {6,5,4,7,2,1};
    insort(arr);
    for(int i=0;i<arr.size();i++)
        cout<<arr[i];
    return 0;
}