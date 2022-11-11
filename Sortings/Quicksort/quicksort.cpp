#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr,int start,int end){
    int pivot=arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<=pivot)
            count++;
    }
    int pivotindex=start+count;
    swap(arr[pivotindex],arr[start]);
    
    int i=start,j=end;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<pivotindex && j>pivotindex)
            swap(arr[i++],arr[j--]);
    }
    return pivotindex;
}

void quicksort(vector<int> &arr,int start,int end){
    
    //base case
    if(start>=end)
        return;

    int p = partition(arr,start,end);

    quicksort(arr,start,p-1);

    quicksort(arr,p+1,end);

}

int main(){

    vector<int> arr={7,5,3,2,1,5,6,10,6};
    int n=arr.size();
    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}