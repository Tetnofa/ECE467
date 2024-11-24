; ModuleID = 'nested_loops.bc'
source_filename = "nested_loops.bc"
target triple = "x86_64-unknown-linux-gnu"

@arr = common global [5 x i32] zeroinitializer

define void @main() {
entry:
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  store i32 0, ptr %i, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.exit3, %entry
  %0 = load i32, ptr %i, align 4
  %1 = icmp slt i32 %0, 5
  br i1 %1, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  store i32 0, ptr %j, align 4
  br label %while.cond1

while.exit:                                       ; preds = %while.cond
  ret void

while.cond1:                                      ; preds = %while.body2, %while.body
  %2 = load i32, ptr %j, align 4
  %3 = load i32, ptr %i, align 4
  %4 = icmp slt i32 %2, %3
  br i1 %4, label %while.body2, label %while.exit3

while.body2:                                      ; preds = %while.cond1
  %5 = load i32, ptr %i, align 4
  %6 = load i32, ptr %j, align 4
  %7 = add i32 %5, %6
  %8 = load i32, ptr %j, align 4
  %9 = getelementptr [5 x i32], ptr @arr, i32 0, i32 %8
  store i32 %7, ptr %9, align 4
  %10 = load i32, ptr %j, align 4
  %11 = add i32 %10, 1
  store i32 %11, ptr %j, align 4
  br label %while.cond1

while.exit3:                                      ; preds = %while.cond1
  %12 = load i32, ptr %i, align 4
  %13 = add i32 %12, 1
  store i32 %13, ptr %i, align 4
  br label %while.cond
}
