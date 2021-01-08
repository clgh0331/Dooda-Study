#include <iostream>

using namespace std;

int main()
{
    int a, b, v;

    cin >> a >> b >> v;

    //(a-b) * n + b >= v
    //n >= (v-b) / (a-b)
    //나머지가 있으면 n에 1을 더해주면 됨.

    int day = (v - b) / (a - b);
    bool etc = (v - b) % (a - b) != 0 ? true : false;

    if (etc) day++;

    cout << day << endl;

    return 0;
}
