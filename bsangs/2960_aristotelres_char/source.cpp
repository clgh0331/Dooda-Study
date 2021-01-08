#include <stdio.h>

int main() {
    // k번쨰 , k번째 인지 카운트
    int N, K, arr[1001], temp[1001], i, j, k_th, k_count = 0;

    scanf("%d %d", &N, &K);

    for(i = 0; i <= N; i++) arr[i] = i;

    for(i = 2; i <= N; i++) {
        for (j = i; j <= N; j++) {
            if (arr[j] != 0 && j % i == 0) {
                k_count++;
                if (k_count == K) k_th = arr[j];
                arr[j] = 0;
            }
        }
    }

    printf("%d", k_th);
}