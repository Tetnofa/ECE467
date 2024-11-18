int main() {
    int a;
    a = 1;
    while (a < 10) {
        a = a + 1;
    }
    return a;
}

int main2(int b) {
    while (b < 10) {
        b = b + 1;
        return 3;
    }
    return b;
}
int nested(int a, int b[]) {
    while (a < 10) {
        while (a < 10) {
            while (b[3] < a) {
                while (b[a] < 30) {
                    return 2;
                }
                while (b[a] < 123) {
                    while (a >= 0) {
                        return 3;
                    }
                }
            }
        }
    }
    return 2;
}
int nestedNoReturn(int a, int b[]) {
    int c[31];
    while (b[a] < 10) {
        a = a + 1;
        while (a < b[a]) {
            while (a >= b[1]) {
                while (c[30] != 3) {
                    c[30] = 3;
                }
            }
        }
    }
    return a;
}