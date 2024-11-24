; ModuleID = 'complex_boolean_expr.bc'
source_filename = "complex_boolean_expr.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %a = alloca i1, align 1
  %b = alloca i1, align 1
  %c = alloca i1, align 1
  %result = alloca i1, align 1
  store i1 true, ptr %a, align 1
  store i1 false, ptr %b, align 1
  store i1 true, ptr %c, align 1
  %0 = load i1, ptr %a, align 1
  %1 = load i1, ptr %b, align 1
  %2 = and i1 %0, %1
  %3 = load i1, ptr %c, align 1
  %4 = load i1, ptr %b, align 1
  %5 = xor i1 %4, true
  %6 = and i1 %3, %5
  %7 = or i1 %2, %6
  store i1 %7, ptr %result, align 1
  %8 = load i1, ptr %a, align 1
  %9 = load i1, ptr %b, align 1
  %10 = or i1 %8, %9
  %11 = xor i1 %10, true
  %12 = load i1, ptr %c, align 1
  %13 = and i1 %11, %12
  store i1 %13, ptr %result, align 1
  ret void
}
