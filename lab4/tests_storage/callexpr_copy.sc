int func(int a[]) {
    return a[0];
}

int main() {
    int x[1];
    x[0] = 1;
    x[0] = func(x);
    return x[0];
}
