#include<iostream>
#include<vector>
#include<string>


using namespace std;

int numbers[1000];

void merge(int start, int mid,int end){
    int i,j,k;

    i = start;
    j = mid+1;
    k = start;
    int temp_arr[1000];

    while(i <= mid  && j <= end){
        if(numbers[i] <= numbers[j]){
            temp_arr[k] = numbers[i];
            i++;
        }
        else{
            temp_arr[k] = numbers[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        for(int m = j ; m <= end ; m++){
            temp_arr[k] = numbers[m];
            k++;
        }
    }
    else{
        for(int m = i ; m <= mid ; m++){
            temp_arr[k] = numbers[m];
            k++;
        }
    }
    for(int m = start; m <= end ; m++){
        numbers[m] = temp_arr[m];
    }

}

void merge_sort(int start, int end){
    
    int mid = (start+end)/2;
    if(start < end){
        merge_sort(start,mid);
        merge_sort(mid+1,end);
        merge(start, mid, end);
    }

    return;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }
    
    merge_sort(0,n-1);
    for(int i = 0 ; i < n ; i++){
        cout << numbers[i] << '\n';
    }

    return 0;

}