#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main(){
    long long house, loop;

    cin >> house;
    cin >> loop;
    vector<long long> room;
    long long start = 1;
    for (int i = 0; i < house;i++){
        long long num;
        cin >> num;
        room.push_back(start);
        start += num;
    }
    for (int i = 0; i < loop;i++){
        long long letter;
        cin >> letter;
        int l = 0;
        int r = room.size() - 1;
        while (l != r) {
            int m = (l+r)/2+1;
            if (room[m] <= letter){
                l = m;
            }else{
                r = m-1;
            } 
        }

        cout << l+1 <<" "<<letter- room[l]+1<<  endl;
    }
}