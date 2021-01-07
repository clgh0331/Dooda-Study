#include <stdio.h>

int main() {
    int a, b, v, location = 0, results = 1, oneday;

    scanf("%d %d %d", &a, &b, &v);
    
    /*
        while(location < v) {
            results++;
            location += a;
            if (location >= v) break;
            location -= b;
        }
    */

    oneday = a - b;
    if ((v - a) % oneday != 0) results++;
    results += (v - a) / oneday;
    printf("%d", results);
}