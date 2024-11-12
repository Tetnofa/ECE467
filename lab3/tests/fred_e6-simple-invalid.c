int main() {
  // This also tests that the line number of the error 
  // reported is the line number corresponding to 
  // the LEFT operand (for some reason);
  (true + false) || true; // Invalid: '+' not defined for bools
}
