#include <iostream>
#include <set>
#include <vector>
using namespace std;

// return pivot's index
int partition(vector<int>& arr, int left, int right){
    int pivot = arr[right];
    int i = left;
    int j = right - 1;
    while(i < j){
        if(arr[i] > pivot){
            swap(arr[i], arr[j]);
            j--;
        }
        else if(arr[j] <= pivot){
            swap(arr[i], arr[j]);
            i++;
        }else{
            i++;
            j--;
        }
    }
    if(arr[j] > pivot){
        swap(arr[j], arr[right]);
        return j;
    }else{
        swap(arr[j+1], arr[right]);
        return j+1;
    }
    
}

void quickSort(vector<int>& arr, int left, int right){
    if(left < right){
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
    }
    return;
}


int main(){
    vector<int> arr = {7,2,6,5,4,0,3};
    // int index = partition(arr, 0, arr.size()-1);
    // cout<<index<<endl;
    
    quickSort(arr, 0, arr.size()-1);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}