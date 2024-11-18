void multipleReturnsInWhileLoop(int j[]) {
    int i;
    i = 0;
    j[4] = 10;

    while (i < 5) {
        while (j[4] > 0){
            if (i == 2) {
                return; // Return when i is 2
            }
            j[4] = j[4] - 1;
        }
        i = i + 1;
    }

}