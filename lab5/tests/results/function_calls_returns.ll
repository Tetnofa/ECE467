; ModuleID = 'function_calls_returns.bc'
source_filename = "function_calls_returns.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @add(i32 %a, i32 %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %0 = load i32, ptr %a1, align 4
  %1 = load i32, ptr %b2, align 4
  %2 = add i32 %0, %1
  ret i32 %2
}

define i1 @isGreater(i32 %x, i32 %y) {
entry:
  %x1 = alloca i32, align 4
  store i32 %x, ptr %x1, align 4
  %y2 = alloca i32, align 4
  store i32 %y, ptr %y2, align 4
  %0 = load i32, ptr %x1, align 4
  %1 = load i32, ptr %y2, align 4
  %2 = icmp sgt i32 %0, %1
  ret i1 %2
}

define void @main() {
entry:
  %result = alloca i32, align 4
  %check = alloca i1, align 1
  %0 = call i32 @add(i32 5, i32 3)
  store i32 %0, ptr %result, align 4
  %1 = load i32, ptr %result, align 4
  %2 = call i1 @isGreater(i32 %1, i32 7)
  store i1 %2, ptr %check, align 1
  ret void
}
