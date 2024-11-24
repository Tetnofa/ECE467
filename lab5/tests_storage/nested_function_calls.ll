; ModuleID = 'nested_function_calls.bc'
source_filename = "nested_function_calls.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @add(i32 %x, i32 %y) {
entry:
  %x1 = alloca i32, align 4
  store i32 %x, ptr %x1, align 4
  %y2 = alloca i32, align 4
  store i32 %y, ptr %y2, align 4
  %0 = load i32, ptr %x1, align 4
  %1 = load i32, ptr %y2, align 4
  %2 = add i32 %0, %1
  ret i32 %2
}

define void @main() {
entry:
  %result = alloca i32, align 4
  %0 = call i32 @multiply(i32 2, i32 3)
  %1 = call i32 @multiply(i32 4, i32 5)
  %2 = call i32 @add(i32 %0, i32 %1)
  store i32 %2, ptr %result, align 4
  ret void
}

define i32 @multiply(i32 %x, i32 %y) {
entry:
  %x1 = alloca i32, align 4
  store i32 %x, ptr %x1, align 4
  %y2 = alloca i32, align 4
  store i32 %y, ptr %y2, align 4
  %0 = load i32, ptr %x1, align 4
  %1 = load i32, ptr %y2, align 4
  %2 = mul i32 %0, %1
  ret i32 %2
}
