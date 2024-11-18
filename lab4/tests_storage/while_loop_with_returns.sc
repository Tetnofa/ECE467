void whileLoopWithReturns() {
    int count;
    count = 0;

    while (count < 5) {
        if (count == 3) {
            return; // Return when count is 3
        }
        count = count + 1;
    }

    // This will not execute if count reaches 3
}