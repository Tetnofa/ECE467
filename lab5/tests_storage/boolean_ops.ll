; ModuleID = 'boolean_ops.bc'
source_filename = "boolean_ops.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %a = alloca i1, align 1
  %b = alloca i1, align 1
  %result = alloca i1, align 1
  store i1 true, ptr %a, align 1
  store i1 false, ptr %b, align 1
  %0 = load i1, ptr %a, align 1
  %1 = load i1, ptr %b, align 1
  %2 = and i1 %0, %1
  store i1 %2, ptr %result, align 1
  %3 = load i1, ptr %a, align 1
  %4 = load i1, ptr %b, align 1
  %5 = or i1 %3, %4
  store i1 %5, ptr %result, align 1
  %6 = load i1, ptr %a, align 1
  %7 = xor i1 %6, true
  store i1 %7, ptr %result, align 1
  ret void
}
