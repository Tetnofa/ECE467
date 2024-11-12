bool f1(int a);

// Not an input we need to expect (at most 1 prototype and function name).
// void f1(bool b);

// void f1(int a) {
//   bool b;
//   b = a;
// }

void f1(bool a) {
  int b;
  b = a;
}
