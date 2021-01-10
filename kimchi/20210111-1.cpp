#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    bool *arr = new bool[n+1];
    int cycle = 0;

    for (int i = 0; i < n + 1; i++) {
        arr[i] = true;
    }
    
    for (int i = 2; i < n + 1; i++) {
        for (int j = 1; i * j <= n + 1; j++) {
            if (arr[i * j] == true) {
                arr[i * j] = false;
                cycle++;
                if (cycle == k) {
                    cout << i * j;
                    return 0;
                }
            }
        }
    }
}
