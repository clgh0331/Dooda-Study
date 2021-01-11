#include <stdio.h>
#define BIT_LEN 33220
#define INT_LEN 10003
#define ZERO_ASCII 48

char input_a[INT_LEN], input_b[INT_LEN], int_sum[INT_LEN], int_temp[INT_LEN];

// 2^33216 의 길이: 10000
bool bit_A[BIT_LEN], bit_B[BIT_LEN], bit_sum[BIT_LEN];

int ctoi(char ascii) { return ascii - ZERO_ASCII; }
char itoc(int integer) { return integer + ZERO_ASCII; }

int strlen(char *value) {
    int count = 0;
    while(value[count] != '\0') count++;
    return count;
}

void *divide_two(char * value, int *carry_flag, int length) {
    bool local_Flag = false;

    for(int i = 0; value[i] != '\0'; i++) {
        i = ctoi(value[i]);
        if (local_Flag) i += 10;

        //
    }
}

bool *change_bit(bool *bit_list, char *input, int max_len) {
    
}

int main() {
    scanf("%s %s", input_a, input_b);

    printf("%d, %s %d", input_a[0], input_b, strlen(input_a));
}