// Test variable scoping and shadowing
int x;
int y;

void outer() {
    int x;
    x = 5;  // Local x
    
    {
        int y;
        y = 10;  // Local y
        writeInt(x);  // Should print local x (5)
        writeInt(y);  // Should print local y (10)
    }
    
    writeInt(y);  // Should print global y
}

void testScoping() {
    x = 1;  // Global x
    y = 2;  // Global y
    outer();
} 