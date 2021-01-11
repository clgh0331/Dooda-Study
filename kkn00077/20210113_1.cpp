#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    bool plag = false;
    int *add_num;
    int add_num_len;
    
    cin >> a >> b;
    
    if(a.length() > b.length()) add_num_len = a.length()+1;
    else add_num_len = b.length()+1;
    
    add_num = new int[add_num_len];
    
    int a_idx = a.length()-1;
    int b_idx = b.length()-1;
    int add_num_idx = add_num_len-1;
    
    while(true){
        
        // 서로 다른 숫자이며, 자릿수가 다를 경우를 대비해 어느 특정 숫자가 자릿수가 모자를 경우 0으로 채워주기 위함
        int a_num = 0;
        int b_num = 0;
        int plus_num = 0;
        
        // 더는 연산할 자릿수가 없을 경우 반복문에서 빠져나옴
        if(add_num_idx < 0) break;
        
        if(a_idx >= 0) a_num = ((int)a[a_idx])-48;
        if (b_idx >= 0) b_num = ((int)b[b_idx])-48;
        
        plus_num=a_num+b_num;
        
        //덧셈해서 자릿수가 올라갔을 경우 반영시켜준다. (check는 plag 변수 사용)
        if(plag){
            //올라간 자릿수 반영
            plus_num+=1;
        }
        
        //덧셈 수행. 10이 넘어갔을 경우 더한 숫자에서 10만큼 빼고 plag를 true로 바꾼다.
        if(plus_num >= 10){
            plag = true;
            add_num[add_num_idx] = plus_num-10;
        } else {
            plag = false;
            add_num[add_num_idx] = plus_num;
        }
        
        a_idx--;
        b_idx--;
        add_num_idx--;
    }
    
    
    for(int i=0;i<add_num_len;i++){
        // 최대 자릿수(마지막 자리가 10을 넘어갔을 경우)를 고려해 +1한 배열에
        // 10이 안넘어 갔을 경우 0을 저장함. 이것에 대한 예외처리.
        if(i==0 && add_num[i]==0) continue;
        cout << add_num[i];
    }
    
    return 0;
}
