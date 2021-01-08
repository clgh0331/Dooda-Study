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
    
    /*
    1. 2~n 수열(배열) 생성
    2. 수열 내부 반복
    3. 소수 체크 (이미 삭제되어 0이면 다음 수로 넘어가기 - 다른 소수의 배수였기 때문에 삭제되었을 경우)
    4. 수열을 돌면서 소수일 경우 해당 소수의 배수을 찾기 위해서 이중으로 해당 소수값만큼 건너 뛰면서 수열 내부 반복
    5. 배수를 삭제하기 전에 이미 삭제된 배수인지 체크
    6. 
        6-1.삭제 되어 있지 않는 경우
            1-1. 카운트를 올린다
            1-2. 카운트가 k랑 동일할 경우 해당 배수를 별도로 저장
            1-3. 수열 내에 있는 해당 배수를 삭제
        6-2.삭제 되어 있는 경우
            2-1. 카운트를 늘리지 않는다
    7. 모든 반복이 끝난 후 별도로 저장한 배수를 출력한다.
    */
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
