int main() {
  true && false;
  true || true;
  1 + 2;
  3 - 4;
  5 * 6;
  7 / -8;
  1 == 1;
  2 != 3;
  true == false;
  true != true;
  9 < 10;
  -11 <= -11;
  12 > -13;
  14 >= 15;
  (true && false) || true;
  (1 + 2) - 3;
  (4 * -5) / (6 + 7);
  (false || true) && (true || false);
  ((1 * 2) - 3) < 4;
  (1 + (2 * 3)) == 6;
  (true && (false || true)) == (true && false);
  1 + 2 * 3 - 4 / -5;
  (1 + 2 * 3) <= (4 - 5 / 6);
  true || (false && true) || (false == true);

  true + 1;               // Invalid: mixing bool and int
  false - true;           // Invalid: '-' not defined for bools
  1 && 2;                 // Invalid: '&&' requires bool operands
  true / false;           // Invalid: '/' not defined for bools
  1 < true;               // Invalid: incompatible types
  false >= -1;            // Invalid: incompatible types
  (true + false) || true; // Invalid: '+' not defined for bools
  (1 == true) && false;   // Invalid: incompatible types in '=='
  1 || 0;                 // Invalid: '||' requires bool operands
  (true && 1) == false;   // Invalid: mixing bool and int
  ((2 + true) == false);  // Invalid: '+' requires int operands
}
