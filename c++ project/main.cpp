#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    if(next_permutation(v.begin(), v.end())){
        for(int i=0; i<n; i++){
            cout << v[i] <<" ";
        }
    }else{
        cout << -1;
    }
    
    cout << endl;
}
