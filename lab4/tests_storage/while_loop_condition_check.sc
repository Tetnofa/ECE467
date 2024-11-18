void whileLoopConditionCheck() {
    int i;
    i = 0;

    while (i < 10) {
        if (i == 5) {
            return; // Return when i is 5
        }
        i = i + 1;
    }

    // This will not execute if i reaches 5
}