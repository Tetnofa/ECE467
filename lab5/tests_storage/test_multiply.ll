; ModuleID = 'test_multiply.bc'
source_filename = "test_multiply.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %result = alloca i32, align 4
  store i32 4, ptr %x, align 4
  store i32 2, ptr %y, align 4
  %0 = load i32, ptr %x, align 4
  %1 = load i32, ptr %y, align 4
  %2 = mul i32 %0, %1
  store i32 %2, ptr %result, align 4
  ret void
}
