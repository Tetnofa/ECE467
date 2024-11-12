// Test semantic errors (this should fail compilation)
int arr[3];  // Move array declaration to global scope

void errorTest() {
    int x;
    bool y;
    
    // Type mismatch
    x = true;  // Error
    
    // Undefined variable
    z = 5;     // Error
    
    // Invalid operation
    y = x + y; // Error
    
    // Array out of bounds
    arr[5] = 1; // Error
} 