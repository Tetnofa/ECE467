; ModuleID = 'if_else_with_nested_loops.bc'
source_filename = "if_else_with_nested_loops.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @ifElseWithNestedLoops() {
entry:
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  store i32 0, ptr %i, align 4
  %0 = load i32, ptr %i, align 4
  %1 = icmp slt i32 %0, 5
  br i1 %1, label %then, label %else

then:                                             ; preds = %entry
  br label %while.cond

merge:                                            ; preds = %while.exit
  ret void

else:                                             ; preds = %entry
  ret void

while.cond:                                       ; preds = %merge2, %then
  %2 = load i32, ptr %j, align 4
  %3 = icmp slt i32 %2, 3
  br i1 %3, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %4 = load i32, ptr %j, align 4
  %5 = icmp eq i32 %4, 1
  br i1 %5, label %then1, label %merge2

while.exit:                                       ; preds = %while.cond
  br label %merge

then1:                                            ; preds = %while.body
  ret void

merge2:                                           ; preds = %while.body
  %6 = load i32, ptr %j, align 4
  %7 = add i32 %6, 1
  store i32 %7, ptr %j, align 4
  br label %while.cond
}
