// Test array declarations and operations
int[5] arr;
int[3] nums;

void initArrays() {
    int i;
    i = 0;
    while (i < 5) {
        arr[i] = i * 2;
        i = i + 1;
    }
}

int sumArray(int[5] input) {
    int sum;
    int i;
    sum = 0;
    i = 0;
    while (i < 5) {
        sum = sum + input[i];
        i = i + 1;
    }
    return sum;
} 