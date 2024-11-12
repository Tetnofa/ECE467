int func1(int x) {
    return (x + 1);
}

int func2(int x, bool y) {
    if (y) {
        // return (func1(x) * 2);
    }
    return func1(x);
}

bool func3(int x, int y) {
    return (func1(x) > func1(y));
}

void main() {
    int result;
    result = func2(func1(5), func3(3, 2));
    result = func2(func1(5), func1(4));
    writeInt(result);
} 