int data[5];

void main() {
    int i;
    int temp;
    
    i = 0;
    while (i < 5) {
        data[i] = i * i;
        i = i + 1;
    }
    
    temp = data[2];
    data[2] = data[3];
    data[3] = temp;
} 