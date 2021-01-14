#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class BigDecimalCal{
    private:
        bool flag;
        string a, b;
        
        //소수점 뒷자리를 받았을 경우 자리수가 차이 난다면 맞춰주기 위해 뒷부분을 0으로 채운다.
        string fillZeroDecimal(string num, int add_len){
            int num_len = num.length();
            for(int i=num_len;i<add_len;i++){
                num += '0';
            }
            return num;
        }
        
        // 문자열 - 숫자 형태의 a, b / isDecimal = 소수점 이하일 경우 배열 길이 +1 유무 정하는 용도 / 처음부터 +1만큼 자릿수를 올려줄것인지
        char* sum_char_num(string a, string b, bool isDecimal){
            char *add_num;
            int add_num_len;
            string fillnum;
            
            //TODO split 후 배열 길이만큼 for문 내에 while 문 반복
            
            if(a.length() > b.length()) {
                add_num_len = a.length();
                fillnum = b;
            }
            else {
                add_num_len = b.length();
                fillnum = a;
            }
            
            if(!isDecimal) add_num_len += 1;
            else {
                fillnum = fillZeroDecimal(fillnum, add_num_len);
                
                // 소수점 뒷자리를 0으로 채운 후 다시 원래 변수로 돌려줌
                if(a.length() > b.length()) b = fillnum;
                else a = fillnum;
            }
            
            add_num = new char[add_num_len];
            
            int a_idx = a.length()-1;
            int b_idx = b.length()-1;
            int add_num_idx = add_num_len-1;
            
            //add_num_len 가 0보다 크거나 같을 동안 반복한다.
            while(add_num_idx >= 0){
                
                // 서로 다른 숫자이며, 자릿수가 다를 경우를 대비해 어느 특정 숫자가 자릿수가 모자를 경우 0으로 채워주기 위함
                int a_num = 0;
                int b_num = 0;
                int plus_num = 0;
                
                if(a_idx >= 0) a_num = a[a_idx]-'0';
                if (b_idx >= 0) b_num = b[b_idx]-'0';
                
                plus_num=a_num+b_num;
                
                //덧셈해서 자릿수가 올라갔을 경우 반영시켜준다. (check는 flag 변수 사용)
                if(flag){
                    //올라간 자릿수 반영
                    plus_num+=1;
                }
                
                //덧셈 수행. 10이 넘어갔을 경우 더한 숫자에서 10만큼 빼고 flag true로 바꾼다.
                if(plus_num >= 10){
                    flag = true;
                    add_num[add_num_idx] = plus_num-10+'0';
                } else {
                    flag = false;
                    add_num[add_num_idx] = plus_num+'0';
                }
                
                a_idx--;
                b_idx--;
                add_num_idx--;
            }
            
            return add_num;
        }
        
    public:
    
        BigDecimalCal(string a, string b){
            this->a = a;
            this->b = b;
            flag = false;
        }
    
        void sum(){
            string* a_split=number_split(a);
            string* b_split=number_split(b);
            
            string decimal(sum_char_num(a_split[1], b_split[1], true));
            string essence(sum_char_num(a_split[0], b_split[0], false));
            
            string result=essence+"."+decimal;
            
            for(int i=0;i<result.length();i++){
                if(result[i] == '0' && i == 0) continue;
                cout << result[i];
            }
        }
        
        string* number_split(string n){
            //strtok을 사용하기 위해 string에서 char*로 형변환
            string* split = new string[2];
            char* n_char_str=new char[n.length()];
            char* token;
            int cnt_split = 0;
            
            
            strcpy(n_char_str, n.c_str());
            
            //split
            token=strtok(n_char_str, ".");
           
            while(token != NULL){
                string temp(token);
                split[cnt_split] = temp;
                token = strtok(NULL, ".");
                cnt_split++;
            }
            
            return split;
        }
};

int main() {
    string a, b;
    char sign;
    
    cin >> a >> b >> sign;
    
    BigDecimalCal cal = BigDecimalCal(a, b);
    
    //부호 체크로 덧셈, 뺄셈 함수 각각 적용
    if(sign == '+') {
        cal.sum();
    }
    else if (sign == '-') return 0;
    else return 0;
    
    return 0;
}
