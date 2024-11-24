; ModuleID = 'while_loop_conditions.bc'
source_filename = "while_loop_conditions.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %count = alloca i32, align 4
  %flag = alloca i1, align 1
  store i32 0, ptr %count, align 4
  store i1 true, ptr %flag, align 1
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %0 = load i32, ptr %count, align 4
  %1 = icmp slt i32 %0, 5
  br i1 %1, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %2 = load i32, ptr %count, align 4
  %3 = add i32 %2, 1
  store i32 %3, ptr %count, align 4
  br label %while.cond

while.exit:                                       ; preds = %while.cond
  br label %while.cond1

while.cond1:                                      ; preds = %while.body2, %while.exit
  %4 = load i1, ptr %flag, align 1
  br i1 %4, label %while.body2, label %while.exit3

while.body2:                                      ; preds = %while.cond1
  store i1 false, ptr %flag, align 1
  br label %while.cond1

while.exit3:                                      ; preds = %while.cond1
  ret void
}
