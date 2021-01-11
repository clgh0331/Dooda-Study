#include <iostream>

using namespace std;

//소수 체크 (소수면 true, 소수가 아니면 false)
bool decimal_check(int n){ 
    // for(int i=2; i <= n; i++){
        // int tmp = 0;
        for(int j=2; j < n; j++){
            if(n % j == 0){
                return false;
            }
        }
        // if(tmp > 0) cout << "ㅜㅐ: "<<i<<endl;//return false;
        // cout << "소수: " << i<<endl;
    // }
    return true;
}

// 배열 안에 해당 숫자가 있는지 확인하는 함수(있으면 true, 없으면 false)
bool hasNum(int a[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (a[i] == num) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    // cout << n << " " << k << "\n" << endl;

    int *tmp = new int[n-1];
    int l = 0;
    for(int i=2; i<=n; i++){
        if(decimal_check(i)){//소수이면
            for(int j=1; i*j<=n; j++){
                if(!hasNum(tmp, n, i*j)){
                    tmp[l++] = i*j;
                }
            }
        } 
    }
    
    // for(int i=0; i<=sizeof(tmp); i++){
    //     cout << i << ": " << tmp[i] << endl;
    // }
    cout << tmp[k-1];
    // cout << "res: " <<tmp[k-1];
   
    
    return 0;
}
