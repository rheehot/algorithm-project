#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//시간 복잡도: O(n^6)
//공간 복잡도: O(n^2)
//사용한 알고리즘: 순열, 2중 for문
//사용한 자료구조: 2차원 배열

int d[21][21];


int main(){
    
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> d[i][j];
        }
    }
    
    vector<int> v;
    for(int i=0; i<n/2; i++){
        v.push_back(0);
    }
    for(int i=0; i<n/2; i++){
        v.push_back(1);
    }
    
    
    int result = 4500;
    
    vector<int> right;
    vector<int> left;
    do{
        right.clear();
        left.clear();
        
        for(int i=0; i<n; i++){
            if(v[i] == 1){
                right.push_back(i+1);
            }else{
                left.push_back(i+1);
            }
        }
        
        int right_sum = 0;
        for(int i=0; i<right.size(); i++){
            for(int j=i+1; j<right.size(); j++){
                right_sum = right_sum + d[right[i]][right[j]] + d[right[j]][right[i]];
            }
        }
        
        int left_sum = 0;
        for(int i=0; i<left.size(); i++){
            for(int j=i+1; j<left.size(); j++){
                left_sum = left_sum + d[left[i]][left[j]] + d[left[j]][left[i]];
            }
        }
        
        result = min(abs(right_sum - left_sum), result);
        
    }while(next_permutation(v.begin(), v.end()));
    
    cout << result << endl;
    
}

