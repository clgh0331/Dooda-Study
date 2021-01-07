#include <iostream>

using namespace std;

int main()
{
    int a, b, v;
    
    cin >> a >> b >> v;
    
    /*int cnt = 0;
    
    while(v > 1){
        cnt++;
        v -= a;
        if(v < 1){
            break;
        }
        v+= b;
    }
    cout << cnt;*/
    
    int day = v/(a-b);
    int etc = v%(a-b)-b;
    
    cout << (day+etc) <<endl;
    
    return 0;
}
