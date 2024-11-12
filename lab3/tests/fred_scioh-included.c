#include "scio.h"

// Declare variables to test I/O functions
int x;
int y;
bool b1;
bool b2;
int arr[5];      // Array of integers
bool boolArr[3]; // Array of booleans

void f1() {
  // Valid uses of read functions
  x = readInt();   // Should read an integer from input
  y = readInt();   // Should read another integer from input
  b1 = readBool(); // Should read a boolean from input (0 or 1)
  b2 = readBool(); // Should read another boolean from input (0 or 1)

  // Valid uses of write functions
  writeInt(x);   // Should write the integer x followed by a space
  writeInt(y);   // Should write the integer y followed by a space
  writeBool(b1); // Should write 'false' or 'true' followed by a space
  writeBool(b2); // Should write 'false' or 'true' followed by a space

  // Valid use of newLine function
  newLine(); // Should write a newline to output

  // Nested valid I/O operations
  writeInt(readInt());   // Reads an integer and immediately writes it
  writeBool(readBool()); // Reads a boolean and immediately writes it

  // --- Invalid uses ---

  // Attempting to pass the wrong type to read and write functions
  x = readBool(); // Invalid: readBool should return bool, not int
  b1 = readInt(); // Invalid: readInt should return int, not bool

  writeInt(b1); // Invalid: writeInt expects int, not bool
  writeBool(x); // Invalid: writeBool expects bool, not int

  // Attempting to pass arrays directly to write functions
  writeInt(arr);      // Invalid: writeInt expects int, not an int array
  writeBool(boolArr); // Invalid: writeBool expects bool, not a bool array

  // Nested invalid operations
  writeInt(readBool()); // Invalid: readBool returns bool, writeInt expects int
  writeBool(readInt()); // Invalid: readInt returns int, writeBool expects bool

  // Attempting to pass constants of incorrect types
  writeInt(true); // Invalid: writeInt expects int, not bool
  writeBool(10);  // Invalid: writeBool expects bool, not int

  // Attempting to use newLine with arguments
  newLine(1); // Invalid: newLine takes no arguments
}
