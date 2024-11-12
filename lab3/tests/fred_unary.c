void f1() {
  int x;
  int y;
  bool b1;
  bool b2;
  
  -5;
  -x;
  -(-10);
  -(y + 3);

  !true;
  !b1;
  !(false || true);
  !(!b2);
  !(b1 && b2);
  !((b1 || false) && (b2 || true));

  !5;          // Invalid: '!' applied to int instead of bool
  -x &&y;      // Invalid: '-' should apply to entire integer expression
  -(true);     // Invalid: '-' applied to bool instead of int
  -(!b1);      // Invalid: '-' applied to result of boolean expression
  -true;       // Invalid: '-' applied to a bool constant
  !(x + y);    // Invalid: '!' applied to int expression
  !(-x);       // Invalid: '!' applied to result of integer expression
  -(b1 || b2); // Invalid: '-' applied to boolean expression
}
