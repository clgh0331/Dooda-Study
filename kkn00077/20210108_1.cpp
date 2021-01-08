#include <iostream>
using namespace std;

int get_climb_day(int, int, int);

int main()
{
    int a, b, v;
    
    cin >> a >> b >> v;
    cout << get_climb_day(a, b, v)<<endl;
    
    return 0;
}

int get_climb_day(int a, int b, int v){
    int total_h = v-b; // 마지막 날에는 b만큼 떨어지지 않는다
    int one_day_h = a-b; // 하루에 최종적으로 올라가는 높이
    int days = total_h/one_day_h;
    return (total_h % one_day_h != 0)?(++days):(days);
}
