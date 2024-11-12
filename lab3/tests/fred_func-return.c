// Valid void function with no return value
void funcVoid() {
  int x;
  if (x > 0) {
    return; // Valid: void function with early return
  }
  // No return statement required for void functions at end
}

// Valid int function with proper return types
int funcInt() {
  int x;
  return x; // Valid: returns int variable
}

int funcIntConstant() {
  return 42; // Valid: returns int constant
}

// Valid bool function with proper return types
bool funcBool() {
  bool b1;
  return b1; // Valid: returns bool variable
}

bool funcBoolExpression() {
  bool b1;
  bool b2;
  return b1 && b2; // Valid: returns bool expression
}

// Nested valid returns within control structures
int funcNestedReturns(int y) {
  if (y > 0) {
    return y; // Valid return within conditional block
  } else if (y < 0) {
    return -y; // Valid return in alternative branch
  }
  return 0; // Valid return in case all conditions fail
}


// Invalid: void function returning a value
void funcVoidInvalid() {
    int x;
    return x;           // Invalid: void function cannot return a value
}

// Invalid: int function missing return statement
int funcIntMissingReturn() {
    int x;
    if (x > 0) {
        return x;       // Only returns in one branch
    }
    // Invalid: missing return statement for other cases
}

// Invalid: bool function returning an int
bool funcBoolInvalidReturnType() {
    int x;
    return x;           // Invalid: expected bool, found int
}

// Invalid: int function returning a bool
int funcIntInvalidReturnType() {
    bool b;
    return b;           // Invalid: expected int, found bool
}

// Invalid return expressions in nested control structures
bool funcBoolNestedInvalid(int y) {
    if (y > 0) {
        return y;       // Invalid: expected bool, found int
    } else if (y < 0) {
        return !y;      // Invalid: '!' applied to int instead of bool
    }
    return true;        // Valid return, but previous ones are invalid
}

// Attempting to return an undeclared variable
int funcReturnUndeclared() {
    return undeclaredVar; // Invalid: undeclared variable in return
}

// Invalid use of return in void function
void funcVoidExtraReturn() {
    int x;
    return x + 1;       // Invalid: void function cannot return a value
}

