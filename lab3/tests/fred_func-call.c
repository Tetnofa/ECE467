int func1(int x);
bool func2(bool b);
void func3(int x, bool b);
int func4(int arr[]);   // Takes an array of integers
bool func5(bool arr[]); // Takes an array of booleans
void func6();           // No parameters
int func7(int x, int y, int z);
bool func8(bool b1, bool b2);

int f1(int a1[], int a2) { return 0; }

int f2() {
  int foo[6];
  f1(foo, 3);
}

void f3() {
  int x;
  int y;
  int z;
  bool b1;
  bool b2;
  int arr[5];      // assume declared and initialized elsewhere
  bool boolArr[3]; // assume declared and initialized elsewhere

  func1(5);
  func1(x);

  func2(true);
  func2(b1);

  func3(10, false);
  func3(x, b2);

  func4(arr);

  func5(boolArr);

  func6();

  func7(1, 2, 3);
  func7(x, y, z);

  func8(true, false);
  func8(b1, b2);

  // Nested valid calls
  func1(func7(1, 2, func1(5)));
  func8(func2(true), func5(boolArr));
  func3(func1(3), func8(false, func2(true)));

  // Invalid
  func1(true);           // Invalid: expected int, got bool
  func2(5);              // Invalid: expected bool, got int
  func3(true, 10);       // Invalid: expected int for 1st arg, bool for 2nd
  func4(5);              // Invalid: expected array of int, got int
  func5(arr);            // Invalid: expected array of bool, got array of int
  func6(10);             // Invalid: func6 takes no arguments
  func7(1, true, 3);     // Invalid: expected int for 2nd arg, got bool
  func8(1, 0);           // Invalid: expected bools, got ints
  func1(func5(boolArr)); // Invalid: func1 expects int, func5 returns bool
  func3(func4(arr), 10); // Invalid: func3 expects bool for 2nd arg, got int
  func7(1, 2);           // Invalid: func7 requires 3 arguments, only 2 given
  func8(true);           // Invalid: func8 requires 2 arguments, only 1 given
  func1(10, 20);         // Invalid: func1 requires 1 argument, but 2 provided
  func4(true);           // Invalid: expected array of int, got bool
}
