// Test function declarations, calls and recursion
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return factorial(n - 1);
}

bool isEven(int num) {
    if (num == 0) {
        return true;
    }
    if (num == 1) {
        return false;
    }
    return isEven(num - 2);
}

void testFunctions() {
    int result;
    bool evenTest;
    
    result = factorial(5);
    writeInt(result);
    newLine();
    
    evenTest = isEven(4);
    writeBool(evenTest);
    newLine();
} 