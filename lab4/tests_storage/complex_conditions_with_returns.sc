void complexConditionsWithReturns() {
    int x;
    int y;
    x = 3;
    y = 4;
    
    if (y < 0) {
        x = y;
    }

    if (x < y && x > 0) {
        y = x;
        return; // Returns if x is positive and less than y
    } else {
        y = y - x; // This will execute if the condition is false
        return;
    }

    if (y < 0) {
        return; // Returns if y is negative
    }
}