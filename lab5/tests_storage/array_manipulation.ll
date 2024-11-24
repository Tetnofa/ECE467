; ModuleID = 'array_manipulation.bc'
source_filename = "array_manipulation.bc"
target triple = "x86_64-unknown-linux-gnu"

@data = common global [5 x i32] zeroinitializer

define void @main() {
entry:
  %i = alloca i32, align 4
  %temp = alloca i32, align 4
  store i32 0, ptr %i, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %0 = load i32, ptr %i, align 4
  %1 = icmp slt i32 %0, 5
  br i1 %1, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %2 = load i32, ptr %i, align 4
  %3 = load i32, ptr %i, align 4
  %4 = mul i32 %2, %3
  %5 = load i32, ptr %i, align 4
  %6 = getelementptr [5 x i32], ptr @data, i32 0, i32 %5
  store i32 %4, ptr %6, align 4
  %7 = load i32, ptr %i, align 4
  %8 = add i32 %7, 1
  store i32 %8, ptr %i, align 4
  br label %while.cond

while.exit:                                       ; preds = %while.cond
  %9 = load i32, ptr getelementptr inbounds ([5 x i32], ptr @data, i32 0, i32 2), align 4
  store i32 %9, ptr %temp, align 4
  %10 = load i32, ptr getelementptr inbounds ([5 x i32], ptr @data, i32 0, i32 3), align 4
  store i32 %10, ptr getelementptr inbounds ([5 x i32], ptr @data, i32 0, i32 2), align 4
  %11 = load i32, ptr %temp, align 4
  store i32 %11, ptr getelementptr inbounds ([5 x i32], ptr @data, i32 0, i32 3), align 4
  ret void
}
