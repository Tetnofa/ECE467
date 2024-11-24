; ModuleID = 'array_with_loops.bc'
source_filename = "array_with_loops.bc"
target triple = "x86_64-unknown-linux-gnu"

@numbers = common global [10 x i32] zeroinitializer

define void @main() {
entry:
  %i = alloca i32, align 4
  store i32 0, ptr %i, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %0 = load i32, ptr %i, align 4
  %1 = icmp slt i32 %0, 10
  br i1 %1, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %2 = load i32, ptr %i, align 4
  %3 = mul i32 %2, 2
  %4 = load i32, ptr %i, align 4
  %5 = getelementptr [10 x i32], ptr @numbers, i32 0, i32 %4
  store i32 %3, ptr %5, align 4
  %6 = load i32, ptr %i, align 4
  %7 = add i32 %6, 1
  store i32 %7, ptr %i, align 4
  br label %while.cond

while.exit:                                       ; preds = %while.cond
  ret void
}
