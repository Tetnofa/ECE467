int arr[5];
bool barr[3];

void testExpr() {
    int x;
    int y;
    bool z;
    
    // Complex arithmetic
    x = 5 + 3 * 2 - 1;
    y = (10 / 2) + 3;
    
    // Complex boolean expressions
    z = !((x > y) && (y <= 10)) || (x == y);
    
    // Array access with expressions
    arr[x + 1] = arr[y - 1] * 2;
    barr[1] = barr[0] && (x > y);

}