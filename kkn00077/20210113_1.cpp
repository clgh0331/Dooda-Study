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
        
        int a_num = ((int)a[a_idx])-48;
        int b_num = ((int)b[b_idx])-48;
        int plus_num = a_num+b_num;
        
        //덧셈해서 자릿수가 올라갔을 경우 반영시켜준다. (check는 plag 변수 사용)
        if(plag){
            //올라간 자릿수 반영
            plus_num+=1;
        }
        
        //TODO
        // 더는 자릿수가 남아있지 않을 경우 남은 자릿수 그대로 집어 넣어야함
        if(a_idx < 0 || b_idx < 0){
            break;   
        }
        
        cout << a_num <<" " <<b_num << " " << a_num+b_num << endl;
        //덧셈 수행. 10이 넘어갔을 경우 더한 숫자에서 10만큼 빼고 plag를 true로 바꾼다.
        if(plus_num >= 10){
            plag = true;
            add_num[add_num_idx] = plus_num-10;
        } else {
            plag = false;
            add_num[add_num_idx] = plus_num;
        }
        
        //cout << add_num[add_num_idx] << endl;
        
        a_idx--;
        b_idx--;
        add_num_idx--;
    }
    
    for(int i=0;i<add_num_len;i++){
        cout << add_num[i] << " ";
    }
    
    return 0;
}
