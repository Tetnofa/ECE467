int func(int a, int b) {
    return a + b;
}

int main() {
    int x;
    int y;
    return func(func(3,4), func(x,y));
}
int arrFunc(int arr[]) {
    return arr[0] + arr[1];
}
int callerArray(int arr[]) {
    return arrFunc(arr);
}
int callerArray2(int arr[]);
int callerArray2(int arr[]) {
    return callerArray(arr);
}
int callArray2() {
    int arr[2];
    return callerArray2(arr);
}
int callIntTrivialArrayParam(int arr[]);
bool trivialArray(int arr[]);
bool trivialArray(int arr[]) {
    int arr2[30];
    return callIntTrivialArrayParam(arr2) == 0 && arr[0] == 0 && arr[201] == 0 || arr[0] == 1 && arr[201] == 1;
}
int trivial(int arr[]) {
    return arr[0];
}
int callIntTrivialArrayStack(int a) {
    int arr[3];
    return trivial(arr);
}
int callIntTrivialArrayParam(int arr[]) {
    return trivial(arr);
}
bool callTrivialArray() {
    int arr[2];
    return trivialArray(arr);
}

int addFunc(int a, int b) {
    return a + b;
}
int callerScale(int a) {
    return addFunc(a, 1);
}
int callerScalar2(int a, int b);
int callerScalar2(int a, int b) {
    return callerScale(a+b);
}
int callScalar() {
    int arr[2];
    return callerScalar2(arr[0], arr[1]);
}
void recursive(int a) {
    recursive(a+1);
    return;
}
bool main2() {
    return callScalar() == 3;
}

bool wtf() {
    return callerScale(callerScale(0)) <= 1;
}