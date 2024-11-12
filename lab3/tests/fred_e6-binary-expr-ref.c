int main() {
  bool b1;
  bool b2;
  bool b3;
  bool b4;
  bool b5;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;

  b1 &&b2;
  b1 || b2;
  i1 + i2;
  i1 - i2;
  i1 *i2;
  i1 / i2;
  i1 == i2;
  i1 != i2;
  b1 == b2;
  b1 != b2;
  i1 < i2;
  i1 <= i2;
  i1 > i2;
  i1 >= i2;
  (b1 && b2) || b3;
  (i1 + i2) - i3;
  (i1 * i2) / (i3 + i4);
  (b1 || b2) && (b3 || b4);
  ((i1 * i2) - i3) < i4;
  (i1 + (i2 * i3)) == i4;
  (b1 && (b2 || b3)) == (b4 && b5);
  i1 + i2 *i3 - i4 / i5;
  (i1 + i2 * i3) <= (i4 - i5 / i6);
  b1 || (b2 && b3) || (b4 == b5);

  b1 + i1;           
  // Invalid: mixing bool and int
  b1 - b2;           
  // Invalid: '-' not defined for bools
  i1 && i2;           
  // Invalid: '&&' requires bool operands
  b1 / b2;           
  // Invalid: '/' not defined for bools
  i1 < b1;           
  // Invalid: incompatible types
  b1 >= i1;          
  // Invalid: incompatible types
  (b1 + b2) || b3;   
  // Invalid: '+' not defined for bools
  (i1 == b1) && b2;  
  // Invalid: incompatible types in '=='
  i1 || i2;          
  // Invalid: '||' requires bool operands
  (b1 && i1) == b2;  
  // Invalid: mixing bool and int
  ((i1 + b1) == b2); 
}
