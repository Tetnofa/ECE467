; ModuleID = 'while_loop_with_returns.bc'
source_filename = "while_loop_with_returns.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @whileLoopWithReturns() {
entry:
  %count = alloca i32, align 4
  store i32 0, ptr %count, align 4
  br label %while.cond

while.cond:                                       ; preds = %merge, %entry
  %0 = load i32, ptr %count, align 4
  %1 = icmp slt i32 %0, 5
  br i1 %1, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %2 = load i32, ptr %count, align 4
  %3 = icmp eq i32 %2, 3
  br i1 %3, label %then, label %merge

while.exit:                                       ; preds = %while.cond
  ret void

then:                                             ; preds = %while.body
  ret void

merge:                                            ; preds = %while.body
  %4 = load i32, ptr %count, align 4
  %5 = add i32 %4, 1
  store i32 %5, ptr %count, align 4
  br label %while.cond
}
