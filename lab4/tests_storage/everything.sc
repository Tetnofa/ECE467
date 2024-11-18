#include "scio.h"

// Global declarations
int globalArr[100];
bool globalBoolArr[50];
int globalX;
bool globalFlag;
void complexOperations(int inputArr[], bool flagArr[], int size);
int arrayHelper(int arr[], bool flags[]);
bool complexBooleanLogic(bool a, bool b, int x, int y);
int recursiveArraySum(int arr[], int index);
int main();
// Helper function for nested array operations
int arrayHelper(int arr[], bool flags[]) {
    int i;
    i = 0;
    while (i < 10) {
        if (flags[i]) {
            arr[i] = arr[i] + 1;
        } else {
            arr[i] = arr[i] * 2;
        }
        i = i + 1;
    }
    return arr[0];
}

// Complex boolean expression testing
bool complexBooleanLogic(bool a, bool b, int x, int y) {
    return !a && (b || x < y) && !(x == y) || (x >= y && !b);
}

// Recursive function with array manipulation
int recursiveArraySum(int arr[], int index) {
    int sum;
    sum = recursiveArraySum(arr, index - 1);
    if (index < 0) {
        return 0;
    }
    return arr[index] + sum;
}

// Main testing function
int main() {
    // Local declarations
    int localArr[50];
    bool boolArr[20];
    int i;
    int sum;
    bool flag;
    int helper;
    
    writeInt(-42);    // Test negative number output
    newLine();
    
    // Initialize arrays with read values
    i = 0;
    while (i < 10) {
        localArr[i] = readInt();
        boolArr[i] = readBool();
        i = i + 1;
    }
    
    // Nested if-while structure
    i = 0;
    sum = 0;
    while (i < 10) {
        if (boolArr[i]) {
            while (localArr[i] > 0) {
                if (localArr[i] / 2 == 0) {
                    sum = sum + localArr[i];
                    if (sum > 100) {
                        writeBool(true);
                        newLine();
                    }
                } else {
                    if (complexBooleanLogic(boolArr[i], boolArr[i-1], localArr[i], localArr[i-1])) {
                        sum = sum * 2;
                    }
                }
                localArr[i] = localArr[i] - 1;
            }
        }
        i = i + 1;
    }
    
    // Test recursive function
    writeInt(recursiveArraySum(localArr, 9));
    newLine();
    
    // Complex array manipulation
    i = 0;
    while (i < 10) {
        helper = arrayHelper(localArr, boolArr);
        globalArr[i] = localArr[i] + helper;
        if (globalArr[i] > 50) {
            globalBoolArr[i] = !boolArr[i];
        } else {
            if (globalArr[i] < 0) {
                globalBoolArr[i] = boolArr[i] && true;
            } else {
                globalBoolArr[i] = false;
            }
        }
        i = i + 1;
    }
    
    // Final complex expression
    flag = (!globalBoolArr[0] && globalBoolArr[1]) || (globalArr[0] <= globalArr[1]);
    writeBool(flag);
    newLine();
    
    return sum;
}

// Additional test function with nested loops and conditions
void complexNestedTest(int x, bool flag) {
    int i;
    int j;
    
    i = 0;
    while (i < x) {
        j = x;
        while (j > 0) {
            if (i + j > x) {
                if (flag) {
                    writeInt(i * j);
                } else {
                    writeInt(i + j);
                }
                newLine();
            } else {
                if (!flag && i * 2 == 0) {
                    writeBool(i < j);
                }
            }
            j = j - 1;
        }
        i = i + 1;
    }
    return;
}

void complexOperations(int inputArr[], bool flagArr[], int size) {
    int tempArr[100];
    bool processingFlags[50];
    int i;
    int j;
    int temp;
    
    // Initialize processing array
    i = 0;
    while (i < size) {
        tempArr[i] = inputArr[i] * 2;
        processingFlags[i] = !flagArr[i];
        writeInt(tempArr[i]);
        newLine();
        i = i + 1;
    }
    
    // Nested processing with multiple conditions
    i = 0;
    while (i < size) {
        j = 0;
        while (j < size - i) {
            if (tempArr[j] > tempArr[j + 1]) {
                // Swap elements
                temp = tempArr[j];
                tempArr[j] = tempArr[j + 1];
                tempArr[j + 1] = temp;
                
                // Update flags
                processingFlags[j] = !processingFlags[j];
                writeBool(processingFlags[j]);
            } else {
                if (processingFlags[j]) {
                    tempArr[j] = tempArr[j] + inputArr[i];
                    writeInt(tempArr[j]);
                } else {
                    while (tempArr[j] > 0) {
                        tempArr[j] = tempArr[j] - 1;
                        if (tempArr[j] + 2 == 0) {
                            writeBool(true);
                        } else {
                            if (processingFlags[j]) {
                                writeInt(tempArr[j]);
                            }
                        }
                    }
                }
            }
            j = j + 1;
        }
        i = i + 1;
    }
    
    // Final array processing
    i = size - 1;
    while (i >= 0) {
        if (processingFlags[i]) {
            while (tempArr[i] > inputArr[i]) {
                tempArr[i] = tempArr[i] - 1;
                writeInt(tempArr[i]);
                newLine();
            }
        } else {
            if (tempArr[i] < inputArr[i]) {
                while (tempArr[i] < inputArr[i]) {
                    tempArr[i] = tempArr[i] + 1;
                    writeBool(tempArr[i] == inputArr[i]);
                    newLine();
                }
            }
        }
        i = i - 1;
    }
}