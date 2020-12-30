#include<iostream>

using namespace std;


int numbers[100000];

void merge(int start, int mid, int end){
    int i, j ,k;
    i = start;
    j = mid+1;
    k = start;

    int temp[100000];
    while(i <= mid && j <= end){
        if(numbers[i] <= numbers[j]){
            temp[k] = numbers[i];
            i++;
        }
        else{
            temp[k] = numbers[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        for(int m = j ;  m <= end; m++){
            temp[k] = numbers[m];
            k++;
        }
    }
    else{
        for(int m = i ; m <= mid ; m++){
            temp[k] = numbers[m];
            k++;
        }
    }
    for(int m = start ; m <=end ; m++){
        numbers[m] = temp[m];
    }
}

void merge_sort(int start ,int end){
    int mid = (start+end)/2;
    if(start < end){
        merge_sort(start, mid);
        merge_sort(mid+1, end);
        merge(start, mid, end);
    }
    return;
}

bool binary_search(int target, int start, int end){
    int mid = (start+end)/2;
    if(start <= end){
        if(numbers[mid]==target){
            return true;
        }
        else if(numbers[mid]< target){
            return binary_search(target, mid+1, end);
        }
        else{
            return binary_search(target, start, mid-1);
        }
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> numbers[i];
    }
    merge_sort(0,n-1);

    int m;
    cin >> m;
    bool ans[m];
    for(int i = 0 ;  i < m ; i++){
        int togo;
        cin >> togo;
        ans[i] = binary_search(togo, 0,n-1);
    }

    for(int i = 0 ; i < m ; i++){
        cout << ans[i] << '\n';
    }

    return 0;

    
}