; ModuleID = 'passed_array_with_loops_and_ifs.bc'
source_filename = "passed_array_with_loops_and_ifs.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @multipleReturnsInWhileLoop(ptr %j) {
entry:
  %j1 = alloca ptr, align 8
  store ptr %j, ptr %j1, align 8
  %i = alloca i32, align 4
  store i32 0, ptr %i, align 4
  %0 = load ptr, ptr %j1, align 8
  %1 = getelementptr i32, ptr %0, i32 4
  store i32 10, ptr %1, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.exit4, %entry
  %2 = load i32, ptr %i, align 4
  %3 = icmp slt i32 %2, 5
  br i1 %3, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  br label %while.cond2

while.exit:                                       ; preds = %while.cond
  ret void

while.cond2:                                      ; preds = %merge, %while.body
  %4 = load ptr, ptr %j1, align 8
  %5 = getelementptr i32, ptr %4, i32 4
  %6 = load i32, ptr %5, align 4
  %7 = icmp sgt i32 %6, 0
  br i1 %7, label %while.body3, label %while.exit4

while.body3:                                      ; preds = %while.cond2
  %8 = load i32, ptr %i, align 4
  %9 = icmp eq i32 %8, 2
  br i1 %9, label %then, label %merge

while.exit4:                                      ; preds = %while.cond2
  %10 = load i32, ptr %i, align 4
  %11 = add i32 %10, 1
  store i32 %11, ptr %i, align 4
  br label %while.cond

then:                                             ; preds = %while.body3
  ret void

merge:                                            ; preds = %while.body3
  %12 = load ptr, ptr %j1, align 8
  %13 = getelementptr i32, ptr %12, i32 4
  %14 = load i32, ptr %13, align 4
  %15 = sub i32 %14, 1
  %16 = load ptr, ptr %j1, align 8
  %17 = getelementptr i32, ptr %16, i32 4
  store i32 %15, ptr %17, align 4
  br label %while.cond2
}
