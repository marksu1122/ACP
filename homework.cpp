#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main(){
    int num;
    cin>>num;
    queue<vector<int> > left;
    queue<vector<int> > right;
    for(int i=0;i<num;i++){
        int n,t,m;
        cin>>n;
        cin>>t;
        cin>>m;
        int ans[m];
        for(int j=0;j<m;j++){
            int arrive;
            string side;
            cin>>arrive;
            cin>>side;
            vector<int> v;
            v.push_back(arrive);
            v.push_back(j);
            if(side == "left"){
                left.push(v);
            }else{
                right.push(v);
            }
        }
        int time=0;
        bool flag = true;
        while(!left.empty()||!right.empty()){
            if(flag){
                if(right.empty() && !left.empty()){
                    if(left.front()[0] >time){
                         time = left.front()[0];
                    }
                }else if(!right.empty() && left.empty()){
                    if(right.front()[0] >time){
                        time = right.front()[0]+t;
                    }else{
                        time +=t;
                    }
                    flag = false;
                    continue;
                }else if(left.front()[0] > time){
                    if(right.front()[0] <= time){
                        time += t;
                        flag = false;
                        continue;
                    }else if(right.front()[0]<left.front()[0]){
                        time = right.front()[0]+t;
                        flag = false;
                        continue;
                    }else{
                        time = left.front()[0];
                    }
                }
                for(int i=0;i<n;i++){
                    if(left.empty() || left.front()[0]>time){
                        break;
                    }
                    ans[left.front()[1]] = time+t;
                    left.pop();
                }
                time += t;
                flag = false;
            }else{
                if(left.empty() && !right.empty()){
                    if(right.front()[0] >time){
                         time = right.front()[0];
                    }
                }else if(!left.empty() && right.empty()){
                    if(left.front()[0] >time){
                        time = left.front()[0]+t;
                    }else{
                        time +=t;
                    }
                    flag = true;
                    continue;
                }else if(right.front()[0] > time){
                    if(right.front()[0]>time){
                        if(left.front()[0] <= time){
                            time += t;
                            flag = true;
                            continue;
                        }else if(left.front()[0]<right.front()[0]){
                            time = left.front()[0]+t;
                            flag = true;
                            continue;
                        }else{
                            time = right.front()[0];
                        }
                    }
                }
                
                for(int i=0;i<n;i++){
                    if(right.empty() || right.front()[0]>time){
                        break;
                    }
                    ans[right.front()[1]] = time+t;
                    right.pop();
                }
                time += t;
                flag = true;
            }
        }
        for(int i=0;i<m;i++){
            cout<<ans[i]<<endl;
        }
        if(i<num-1){
            cout<<endl;
        }
    }
}