; ModuleID = 'if_else_with_returns.bc'
source_filename = "if_else_with_returns.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @ifElseWithReturns() {
entry:
  %x = alloca i32, align 4
  store i32 8, ptr %x, align 4
  %0 = load i32, ptr %x, align 4
  %1 = icmp sgt i32 %0, 10
  br i1 %1, label %then, label %else

then:                                             ; preds = %entry
  ret void

merge:                                            ; No predecessors!
  %2 = load i32, ptr %x, align 4
  %3 = icmp slt i32 %2, 10
  br i1 %3, label %then1, label %merge2

else:                                             ; preds = %entry
  store i32 5, ptr %x, align 4
  ret void

then1:                                            ; preds = %merge
  ret void

merge2:                                           ; preds = %merge
  ret void
}
