#include <stdio.h>

#define BIT_LEN 33220
#define INT_LEN 10003
#define ZERO_ASCII 48

// 편의상 아래 배열들을 Decimal이라고 이름 붙임.
char input_a[INT_LEN], input_b[INT_LEN], int_sum[INT_LEN], int_temp[INT_LEN], int_cpy_temp[INT_LEN];

// 2^33216 의 길이: 10000
bool bit_A[BIT_LEN], bit_B[BIT_LEN], bit_sum[BIT_LEN], bit_temp[BIT_LEN];

int ctoi(char ascii) { return ascii - ZERO_ASCII; }
char itoc(int integer) { return integer + ZERO_ASCII; }

int strlen(char *value) {
    int count = 0;
    while(value[count] != '\0') count++;

    return count;
}

void strcpy(char *source, char *destination) {
    int i;
    
    for (i = 0; source[i] != '\0'; i++) destination[i] = source[i];

    destination[i] = '\0';
}

// 해당 Deciaml이 0값일 때 true 반환.
bool isZero(char *value) {
    for(int i = 0; value[i] != '\0'; i++) if (value[i] != '0') return false;

    return true;
}

void bincpy(bool *source, bool *destination, int length) {
    for (int i = 0; )
}

void binary_revserse(bool *binary, int length) {
    for (int i = 0; i < length; i++) bit_temp[length - i - 1] = binary[i];
}

// decimal to binary를 위해 2로 나누는 것
bool decimal_divide_two(char * value) {
    bool local_Flag = false;
    int i, num;

    for (i = 0; i < INT_LEN; i++) int_temp[i] = '0';
    int_temp[INT_LEN - 1] = '\0';

    for(i = 0; value[i] != '\0'; i++) {
        num = ctoi(value[i]);
        if (local_Flag) num += 10;

        local_Flag = (num % 2 != 0);
        int_temp[i] = itoc(num/2);
    }

    int_temp[i] = '\0';
    return local_Flag;
}

// 나중에 binary reverse를 만들면 됨. change_bit 는 역순으로 binary가 정렬 됨. return값으로 바이너리의 길이 반환.
int change_bit(bool *binary, char *decimal) {
    int len;

    strcpy(decimal, int_cpy_temp);

    for (len = 0; !isZero(int_cpy_temp); len++) {
        printf("int_temp: %s\n", int_cpy_temp);
        binary[len] = decimal_divide_two(int_cpy_temp);
        strcpy(int_temp, int_cpy_temp);
        printf("int_temp_last: %s\n", int_cpy_temp);
    }
    printf("AA %d\n", len);
    return len;
}

void print_binary(bool *binary, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d ", binary[i]);
    }
    printf("\n");
}

int main() {
    scanf("%s %s", input_a, input_b);

    int input_a_len = change_bit(bit_A, input_a), input_b_len = change_bit(bit_B, input_b);

    print_binary(bit_A, input_a_len);
    print_binary(bit_B, input_b_len);

    /*
    1. binary_reverse 로 change_bit 를 revserse함.
        1-1. bincpy를 완성 해야 함.
    2. 비트연산 ㄲ
    */

    // int carry_flag_divide = decimal_divide_two(input_a);
    // // strcpy(input_a, int_sum);

    // printf("%s, %d %d %c %d %s", int_temp, carry_flag_divide, strlen(input_a), itoc(2/2), isZero(input_b), int_sum);
}