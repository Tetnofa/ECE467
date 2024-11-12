void main() {
    int x;
    int y;
    bool flag;
    
    x = 5;
    y = 10;
    flag = true;
    
    if (flag && (x < y)) {
        x = x + 1;
        flag = false;
    }
} 