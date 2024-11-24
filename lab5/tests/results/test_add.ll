; ModuleID = 'test_add.bc'
source_filename = "test_add.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %result = alloca i32, align 4
  store i32 5, ptr %x, align 4
  store i32 3, ptr %y, align 4
  %0 = load i32, ptr %x, align 4
  %1 = load i32, ptr %y, align 4
  %2 = add i32 %0, %1
  store i32 %2, ptr %result, align 4
  ret void
}
