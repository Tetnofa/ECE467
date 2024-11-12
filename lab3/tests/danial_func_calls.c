void fcn();
void test(int x, int y, int z) {
    x = y;
}
void pee(bool a, int b, int c);
void yee(bool a, int b, int c);
int main() { 
    bool x;
    int y;
    bool z;
    fcn(x, y, z);
    fcn2();
    test(x, y, z); // x and z -> 2 are not matching so prints twice
    test(1, 2, 3);
    test(true, true, false);
    pee(a, b, c);
    yee(a, b, c);
    feet();
}
void feet() {
    a = b;
}
int pee(bool a, int b, int c) {
    v = c;
}