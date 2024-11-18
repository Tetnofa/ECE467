void nestedIfElseWithReturns() {
    int a;
    a = 7;

    if (a > 10) {
        return; // Will not execute
    } else {
        if (a > 5) {
            return; // Will execute, returns early
        } else {
            a = 0; // This will not execute
        }
    }
}