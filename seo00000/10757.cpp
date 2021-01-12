#include <iostream>
#include <string>

using namespace std;

string zerofill(string n, int size){
    string zerofill = "";
     for(int i=0; i<size; i++){
        zerofill += "0";
     } 
     return zerofill + n;
}

int main() {
    string a, b;
    cin >> a >> b;
    
    int size;
    
    if((int)a.length() > (int)b.length()){
        size = (int)a.length();
        int s = (int)a.length() - (int)b.length();
        b = zerofill(b, s);
    } else if((int)a.length() < (int)b.length()) {
        size = (int)b.length();
        int s = (int)b.length() - (int)a.length();
        a = zerofill(a, s);
    } else {
        size = (int)a.length();
    }
    
    string arr2 = "";
    int *arr = new int[size+1];
    int ch_ten = 0;
    int last = 0;
    
    for(int i = 1, j = 0; i < size+1; i++){
        
        int aa = (int)(a[a.length()-i]-48);
        int bb = (int)(b[b.length()-i]-48);
        int add_num = (aa + bb);
        
        if(add_num + j > 9){
            arr[ch_ten++] = (add_num + j - 10);
            j=1;
        }else{
            arr[ch_ten++] = (add_num + j);
            j=0;
        }
        if((i == size) && j == 1){
            last = 1;
        }
    }
    
    string result = "";
    if(last == 1) result += 1 + 48;
    
    for(int i = 1; i < size + 1; i++){
        result += arr[size-i]+48;
    }
    cout << result;
    
    delete[] arr;
    
    return 0;
}
