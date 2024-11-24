; ModuleID = 'while_loop_condition_check.bc'
source_filename = "while_loop_condition_check.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @whileLoopConditionCheck() {
entry:
  %i = alloca i32, align 4
  store i32 0, ptr %i, align 4
  br label %while.cond

while.cond:                                       ; preds = %merge, %entry
  %0 = load i32, ptr %i, align 4
  %1 = icmp slt i32 %0, 10
  br i1 %1, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %2 = load i32, ptr %i, align 4
  %3 = icmp eq i32 %2, 5
  br i1 %3, label %then, label %merge

while.exit:                                       ; preds = %while.cond
  ret void

then:                                             ; preds = %while.body
  ret void

merge:                                            ; preds = %while.body
  %4 = load i32, ptr %i, align 4
  %5 = add i32 %4, 1
  store i32 %5, ptr %i, align 4
  br label %while.cond
}
