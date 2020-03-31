#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main(){
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int datas;
        int data;
        int x,y;
        int count = 0;
        vector<int> dataset;
        cin>>datas;
        for(int j=0;j<datas;j++){
            cin>>data;
            dataset.push_back(data);
        }
        for(int a=0;a<dataset.size();a++){
            x = dataset[a];
            for(int b = a+1;b<dataset.size();b++){
                y = dataset[b];
                
                if(x == 0 && y==0){
                    // Z1 Z2 相加 找 Z3 == 0
                    count += 2*(dataset.size()-b-1);
                    for(int c = b+1;c<dataset.size();c++){
                        if(dataset[c] == 0){
                            count ++;
                        }
                    }
                }else if(x == 0){
                    // Z1 找  y z ==0, Z2 找 y ==0 , Z3找 z ==0
                    for(int c = b+1;c<dataset.size();c++){
                        if(y == 0 || dataset[c] == 0){
                            if(y == 0 && dataset[c] == 0){
                                count += 3;
                            }else{
                                count += 1;
                            }
                        }
                    }
                }else if(y == 0){
                    // Z1 不用找 不可能, Z2 找 z ==0 , Z3找 z ==0
                    for(int c = b+1;c<dataset.size();c++){
                        if(dataset[c] == 0){
                            count += 2;
                        }
                    }
                }else{
                    for(int c = b+1;c<dataset.size();c++){
                        int z = dataset[c];
                        if(x == y*z){
                            count +=1;
                        }else if(y == x*z){
                            count +=1;
                        }else if(z == x*y){
                            count +=1;
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<i+1<<":"<<count<<endl;
    }
}