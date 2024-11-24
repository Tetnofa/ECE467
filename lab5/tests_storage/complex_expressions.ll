; ModuleID = 'complex_expressions.bc'
source_filename = "complex_expressions.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %flag = alloca i1, align 1
  store i32 5, ptr %x, align 4
  store i32 10, ptr %y, align 4
  store i1 true, ptr %flag, align 1
  %0 = load i32, ptr %x, align 4
  %1 = load i32, ptr %y, align 4
  %2 = mul i32 %1, 2
  %3 = load i32, ptr %x, align 4
  %4 = add i32 %3, 1
  %5 = sdiv i32 %2, %4
  %6 = add i32 %0, %5
  store i32 %6, ptr %x, align 4
  %7 = load i32, ptr %x, align 4
  %8 = load i32, ptr %y, align 4
  %9 = icmp sgt i32 %7, %8
  %10 = load i1, ptr %flag, align 1
  %11 = xor i1 %10, true
  %12 = load i32, ptr %y, align 4
  %13 = icmp slt i32 %12, 20
  %14 = or i1 %11, %13
  %15 = and i1 %9, %14
  store i1 %15, ptr %flag, align 1
  ret void
}
