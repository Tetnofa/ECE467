void main() {
    int a;
    int b;
    bool result;
    
    a = 5;
    b = 10;
    
    if ((a < b) && (a > 0)) {
        result = true;
    }
    
    while ((b > a) && !result) {
        a = a + 1;
    }
} 