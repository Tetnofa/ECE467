void ifElseWithNestedLoops() {
    int i;
    int j;
    i = 0;

    if (i < 5) {
        while (j < 3) {
            if (j == 1) {
                return; // Return when j is 1
            }
            j = j + 1;
        }
    } else {
        return; // This will not execute
    }
}