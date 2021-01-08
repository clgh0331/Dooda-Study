#include <iostream>
using namespace std;

bool check_decimal(int);

int main() {
    int a, k, len;
    int cnt = 0;
    int k_value = 0;
    cin >> a >> k;
    
    len = a-1;
    int *nums = new int[len];
    
    //배열 초기화
    for(int i=0, n=2;i<len;i++){
        nums[i] = n++;
    }
    
    for(int i=0;i<len;i++){
        
        //소수인지 아닌지 체크
        // 체크하는 수가 이미 하단에서 다른 소수의 배수라서 0으로 삭제되어 있을 경우를 함수 내에서 체크해줌
        if(check_decimal(nums[i])) { // 소수일 경우
            int n = nums[i];
            for(int j=i;j<len;j+=n){
                // 삭제하려는 배수가 이미 삭제되어 있을 경우.
                // 위의 소수/소수삭제여부 체크랑 별도임.(소수는 삭제가 안되어 있으나 그 배수가 삭제 되어 있을 경우)
                if(nums[j]!=0){
                    cnt++;
                    if(cnt==k) k_value = nums[j];
                }
                nums[j] = 0;
            }
        }
    }
    
    cout << k_value;
    
    delete nums;
    
    return 0;
}

bool check_decimal(int n){
    for(int i=2;i<n;i++){
        if(n%i==0) return false;
    }
    return n!=0?true:false;
}
