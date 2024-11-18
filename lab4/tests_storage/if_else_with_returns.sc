void ifElseWithReturns() {
    int x;
    x = 8;

    if (x > 10) {
        return; // Will not execute
    } else {
        x = 5; // This will execute
        return;
    }

    if (x < 10) {
        return; // Will execute, returns early
    }
}