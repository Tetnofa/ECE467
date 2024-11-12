int multiply(int x, int y) {
    return x * y;
}

int add(int x, int y) {
    return x + y;
}

void main() {
    int result;
    result = add(multiply(2, 3), multiply(4, 5));
} 