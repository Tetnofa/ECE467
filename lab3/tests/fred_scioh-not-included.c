// Declare variables to test I/O functions without including scio.h
int x;
int y;
bool b1;
bool b2;

void f1() {
  // Test read functions (should produce errors due to missing `scio.h`)
  x = readInt();   // Error: readInt not declared
  y = readInt();   // Error: readInt not declared
  b1 = readBool(); // Error: readBool not declared
  b2 = readBool(); // Error: readBool not declared

  // Test write functions (should produce errors due to missing `scio.h`)
  writeInt(x);   // Error: writeInt not declared
  writeInt(y);   // Error: writeInt not declared
  writeBool(b1); // Error: writeBool not declared
  writeBool(b2); // Error: writeBool not declared

  // Test newLine function (should produce error due to missing `scio.h`)
  newLine(); // Error: newLine not declared

  // Nested I/O operations (should produce errors)
  writeInt(readInt());   // Error: both writeInt and readInt not declared
  writeBool(readBool()); // Error: both writeBool and readBool not declared
}
