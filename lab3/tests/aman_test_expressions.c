// Test various expressions and operators
void testExpressions() {
    int a;
    int b;
    bool c;
    bool d;
    
    a = 10;
    b = 5;
    
    // Arithmetic
    writeInt(a + b);
    writeInt(a - b);
    writeInt(a * b);
    writeInt(a / b);
    
    // Comparison
    c = a > b;
    d = a <= b;
    writeBool(c);
    writeBool(d);
    
    // Boolean logic
    writeBool(c && d);
    writeBool(c || d);
    writeBool(!c);
} 