void main() {
    int x;
    int y;
    bool flag;
    
    x = 10;
    y = 5;
    flag = true;
    
    if (x > y) {
        if (flag) {
            x = x - 1;
            if (x == y) {
                flag = false;
                return;
            }
        }
    }
} 