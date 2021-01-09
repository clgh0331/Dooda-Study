#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int count = 0;

    int *array = (int*)malloc(n * sizeof(int));
    int *erased_array = (int*)malloc(n * sizeof(int));
    int erased_index = 0;

    memset(erased_array, 0, n * sizeof(int));

    if(n > 2) {
        int j = 0;
        for(int i = 2; i <= n; i++) {
            array[j] = i;        
            j += 1;
        }


        j = 0;
        for(int i = 2; i <= n; i++) {
            int flag = 0;

            for(int m = 2; m < array[j]; m++) {
                if(array[j] % m == 0) {
                    flag++;
                }
            }

            if(flag == 0) {
                for(int m = 2; m < n; m++) {
                    if(m % array[j] == 0) {
                        for(int x = 0; x <= n; x++) {
                            if(erased_array[x] != m) {
                                erased_array[erased_index++] = m;      
                                break;
                            }
                        }
                    }
                }
            }
            
            j += 1;
        }

        printf("%d", erased_array[k - 1]);
    }

    free(array);
    free(erased_array);

    return 0;
}
