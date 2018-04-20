#include <iostream>
#include <string>

using namespace std;

int n, m;
int d[300][300];
bool check[300][300];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int cur_sheep = 0;
int cur_wolf = 0;

int total_sheep = 0;
int total_wolf = 0;

void dfs(int x, int y){
    
    check[x][y] = true;
    if(d[x][y] == 2) cur_sheep++;
    else if(d[x][y] == 3) cur_wolf++;

    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            if(check[nx][ny] == false && d[nx][ny] != 1){
                dfs(nx, ny);
            }
        }
        
    }
    
}

int main(){
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        string word;
        cin >> word;
        for(int j=0; j<m; j++){
            
            //0 필드, 1 펜스, 2 양, 3 늑대
            if(word[j] == '.') d[i][j] = 0;
            else if(word[j] == '#') d[i][j] = 1;
            else if(word[j] == 'o') d[i][j] = 2;
            else d[i][j] = 3;
            
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(check[i][j] == false){
                cur_sheep = 0;
                cur_wolf = 0;
                dfs(i, j);
                
                if(cur_sheep > cur_wolf){
                    total_sheep += cur_sheep;
                }else{
                    total_wolf += cur_wolf;
                }
                
            }
        }
    }
    
    cout << total_sheep << " " << total_wolf << endl;
}
