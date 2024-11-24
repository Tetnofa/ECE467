; ModuleID = 'compound_conditions.bc'
source_filename = "compound_conditions.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %result = alloca i1, align 1
  store i32 5, ptr %a, align 4
  store i32 10, ptr %b, align 4
  %0 = load i32, ptr %a, align 4
  %1 = load i32, ptr %b, align 4
  %2 = icmp slt i32 %0, %1
  %3 = load i32, ptr %a, align 4
  %4 = icmp sgt i32 %3, 0
  %5 = and i1 %2, %4
  br i1 %5, label %then, label %merge

then:                                             ; preds = %entry
  store i1 true, ptr %result, align 1
  br label %merge

merge:                                            ; preds = %then, %entry
  br label %while.cond

while.cond:                                       ; preds = %while.body, %merge
  %6 = load i32, ptr %b, align 4
  %7 = load i32, ptr %a, align 4
  %8 = icmp sgt i32 %6, %7
  %9 = load i1, ptr %result, align 1
  %10 = xor i1 %9, true
  %11 = and i1 %8, %10
  br i1 %11, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %12 = load i32, ptr %a, align 4
  %13 = add i32 %12, 1
  store i32 %13, ptr %a, align 4
  br label %while.cond

while.exit:                                       ; preds = %while.cond
  ret void
}
