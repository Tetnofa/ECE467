int main(int a) {
    a = 1;
}

int fcn(int f) {
    int x;
    f = x;
}


int fcn1(int f) {
    int a;
    a = f;
    fcn(f);
}
void fcn2(bool x, bool z, bool k) {
    int y;
    y = x;
    x = z;
    k = z;
    f = 1;
}
int fcn4(int pee[]);
int fcn4(int pee[]) {
    fcn4(pee);
}
void fcn3(int arr[]) {
    fcn2(arr[2]);
    fcn4(arr);
}

int pee(int a, int b, int c);
int pee(int a, int b, int c) {
    int arr[2];
    arr[1] = a;
    arr[2] = b;
    arr[3] = c;
}