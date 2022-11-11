#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &arr,int start,int end){

    // make the first element pivot
    int pivot=arr[start];
    int count=0;
    
    // count the number of elements smaller than pivot
    for(int i=start+1;i<=end;i++){
        if(arr[i]<=pivot)
            count++;
    }

    //specify the pivot index
    int pivotindex=start+count;

    //swap it with the current element at pivotindex
    swap(arr[pivotindex],arr[start]);
    
    // make the sorting as left side (<a) & right side (>a)
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
    
    // sort the left side of pivot 
    quicksort(arr,start,p-1);

    // sort the right side of pivot
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