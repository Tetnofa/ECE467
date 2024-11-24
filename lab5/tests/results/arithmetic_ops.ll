; ModuleID = 'arithmetic_ops.bc'
source_filename = "arithmetic_ops.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %result = alloca i32, align 4
  store i32 10, ptr %a, align 4
  store i32 5, ptr %b, align 4
  %0 = load i32, ptr %a, align 4
  %1 = load i32, ptr %b, align 4
  %2 = add i32 %0, %1
  store i32 %2, ptr %result, align 4
  %3 = load i32, ptr %a, align 4
  %4 = load i32, ptr %b, align 4
  %5 = sub i32 %3, %4
  store i32 %5, ptr %result, align 4
  %6 = load i32, ptr %a, align 4
  %7 = load i32, ptr %b, align 4
  %8 = mul i32 %6, %7
  store i32 %8, ptr %result, align 4
  %9 = load i32, ptr %a, align 4
  %10 = load i32, ptr %b, align 4
  %11 = sdiv i32 %9, %10
  store i32 %11, ptr %result, align 4
  ret void
}
