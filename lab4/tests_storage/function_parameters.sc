int calculate(int a, int b, bool flag) {
    int result;
    result = 0;
    
    if (flag) {
        result = a + b;
    } else {
        result = a - b;
    }
    return result;
}

void main() {
    int x;
    int y;
    bool flag;
    
    x = 10;
    y = 5;
    flag = true;
    x = calculate(x, y, flag);
} 