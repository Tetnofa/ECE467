void main() {
    int x;
    int y;
    bool flag;
    
    x = 5;
    y = 10;
    flag = true;
    
    x = x + ((y * 2) / (x + 1));
    flag = (x > y) && (!flag || (y < 20));
} 