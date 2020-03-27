#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


int main(){

    int n;
    int k;
    
    int lenmax=0;

    cin >> n;
    int index[n];
    int ans[1000000] = {0};
    cin >> k;
    for (int i = 0; i < n; i++){
        int a;
        cin>>index[i];
    }
    int j=0;
    while(j >= n){
        int a = index[j];
        for(int i=0;i<k;i++){
            if(ans[j-i] >= a){
                break;
            }else{
                ans[j-i] = a;
            }
        }
        for(int i=0;i<k;i++){
            if(index[j+i]<a){
                ans[j+i] = a;
            }else{
                j = j+i;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<ans[i];
    }

}