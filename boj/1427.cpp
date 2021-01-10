#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    string nums;
    nums = to_string(n);

    sort(nums.begin(),nums.end());
    reverse(nums.begin(),nums.end());

    cout << nums <<'\n';

    return 0;

}