int arr[5];

void main() {
    int i;
    int j;
    
    i = 0;
    while (i < 5) {
        j = 0;
        while (j < i) {
            arr[j] = i + j;
            j = j + 1;
        }
        i = i + 1;
    }
} 