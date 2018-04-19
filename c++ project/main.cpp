#include <iostream>

using namespace std;

int d[102][102];
int end_y = 0;

bool go(int x, int y){
    
    while(x <= 100){
        
        //그냥 아래로 이동
        if(d[x][y] > 1 && d[x][y+1] ==2){
            y = y + d[x][y] - 1;
            x = x + 1;
            
            //왼쪽으로 이동
        }else if(d[x][y] > 1 && d[x][y-1] == d[x][y]-1){
            if(x == 1 && y==3){
            }
            y = y - d[x][y] + 1;
            x = x + 1;
            
            //오른쪽 이동
        }else{
            
            x = x + 1;
            y = y;
        }
        
    }
    
    bool is_possible = false;
    if(y == end_y) is_possible = true;
    
    return is_possible;
}

int main(int argc, char** argv)
{
    int test_case;
    
    for(test_case = 1; test_case <= 10; ++test_case)
    {
        int T;
        
        cin>>T;
        
        for(int i=0; i<100; i++){
            for(int j=0; j<100; j++){
                cin >> d[i][j];
                
                if(d[i][j] == 2){
                    end_y = j;
                }
            }
        }
        
        for(int i=0; i<100; i++){
            
            int length = 1;
            for(int j=0; j<100; j++){
                
                
                //가로선이 있을때
                if(d[i][j] > 0 && d[i][j+1] > 0){
                    d[i][j+1] = d[i][j]+1;
                    length = d[i][j+1];
                    
                }else if(d[i][j] >0 && d[i][j+1] == 0){
                    d[i][j-length+1] = length;
                    length = 1;
                }
                
            }
        }
        
        
        int result = 0;
        //세로선 기준 사다리 타기
        for(int j=0; j<100; j++){
            if(d[0][j] == 1){
                if(go(0, j) == true){
                    result = j;
                    break;
                }
            }
        }
        cout << "#" << test_case << " " <<result << endl;
    }
    return 0;
}

