#include<iostream>

using namespace std;

long long cards[500000];

void merge(int start, int mid, int end){
    int i, j,k;
    i = start;
    j = mid+1;
    k = start;
    
    long long temp[500000];
    
    while(i <= mid && j <= end){
        if(cards[i]<=cards[j]){
            temp[k] = cards[i];
            i++;
        }
        else{
            temp[k] = cards[j];
            j++;
        }
        k++;
    }
    
    if(i>mid){
        for(int m = j ; m <= end; m++){
            temp[k] = cards[m];
            k++;
        }
    }
    else{
        for(int m = i ; m <= mid ; m++){
            temp[k] = cards[m];
            k++;
        }
    }
    
    for(int m = start ; m <= end ; m++){
        cards[m] = temp[m];
    }
    
    return;
}


void merge_sort(int start, int end){
    if(start < end){
        int mid = (start+end)/2;
        merge_sort(start, mid);
        merge_sort(mid+1, end);
        merge(start, mid, end);
    }
    
    return;
}

bool binary_search(long long target, int start, int end){
    if(start <= end){
        int mid = (start + end)/2;
        if(cards[mid]==target){
            return true;
        }
        else if(cards[mid] < target){
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
    for(int i = 0 ; i < n ;i++){
        cin >> cards[i];
    }
    merge_sort(0,n-1);
    
    int m;
    cin >> m;
    
    bool ans[m];
    for(int i = 0 ; i < m ; i++){
        long long target;
        cin >> target;
        ans[i] = binary_search(target, 0, n-1);
    }
    
    for(int i = 0 ; i < m ; i++){
        cout << ans[i] << ' ';
    }
    
    cout << '\n';
    return 0;

}

