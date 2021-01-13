

#include <iostream>
#include <string>
using namespace std;

int sum(char a, char b);

int main()
{
    string a, b;
    cin >> a >> b;

    int maxSize;
    a.length() >= b.length() ? maxSize = a.length() + 1 : maxSize = b.length() + 1;

    char *result = new char[maxSize];

    int carry = 0;
    for (int i = 1; i <= maxSize; i++) {
        char temptA = '0';
        char temptB = '0';
        if (a.length() >= i) {
            temptA = a[a.length() - i];
        }
        if (b.length() >= i) {
            temptB = b[b.length() - i];
        }
        int temptResult = sum(temptA, temptB);
        temptResult += carry;
        carry = temptResult / 10;
        result[maxSize - i] = char(temptResult % 10 + '0');
    }

    for (int i = 0; i < maxSize; i++) {
        if (i == 0 && result[i] == '0') {}
        else if(result[i] >= '0' && result[i] <= '9') {
            cout << result[i];
        }
        
    }
    
}

int sum(char a, char b) {
    int numA = a - '0';
    int numB = b - '0';
    return numA + numB;
}
