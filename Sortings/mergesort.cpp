#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end){
    mid = start + (end-start)/2;
    int length1=mid-start+1;
    int length2=end-mid;

    // make two temporary arrays
    int *temparr1 = new int[length1];
    int *temparr2 = new int[length2];

    // insert values into temporary arrays
    for(int i=0;i<length1;i++){
        temparr1[i]=arr[start+i];
    }
    for(int i=0;i<length2;i++){
        temparr2[i]=arr[mid+1+i];
    }

    int index1=0,index2=0;
    int indexofmergedarray=start;

    // compare and insert values into the merging array
    while(index1 < length1 && index2 < length2){
        if(temparr1[index1]<=temparr2[index2]){
            arr[indexofmergedarray]=temparr1[index1];
            index1++;
        }
        else {
            arr[indexofmergedarray]=temparr2[index2];
            index2++;
        }
        indexofmergedarray++;
    }
    
    // insert the remaining values
    while(index1 < length1){
        arr[indexofmergedarray]=temparr1[index1];
        indexofmergedarray++;
        index1++;
    }
    
    while(index2 < length2){
        arr[indexofmergedarray]=temparr2[index2];
        indexofmergedarray++;
        index2++;
    }

    delete []temparr1;
    delete []temparr2;

}

void mergesort(vector<int> &arr, int start, int end){
    if(start>=end)
        return;
    
    int mid= start + (end-start)/2;
    
    //sort the left part
    mergesort(arr,start,mid);

    //sort the right part
    mergesort(arr,mid+1,end);

    //merge the sorted arrays
    merge(arr,start,mid,end);
}

int main(){
    vector<int> arr={2,5,1,4,9,7,5};
    int n=arr.size();
    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}