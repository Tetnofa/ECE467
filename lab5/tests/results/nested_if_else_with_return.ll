; ModuleID = 'nested_if_else_with_return.bc'
source_filename = "nested_if_else_with_return.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @nestedIfElseWithReturns() {
entry:
  %a = alloca i32, align 4
  store i32 7, ptr %a, align 4
  %0 = load i32, ptr %a, align 4
  %1 = icmp sgt i32 %0, 10
  br i1 %1, label %then, label %else

then:                                             ; preds = %entry
  ret void

merge:                                            ; preds = %merge2
  ret void

else:                                             ; preds = %entry
  %2 = load i32, ptr %a, align 4
  %3 = icmp sgt i32 %2, 5
  br i1 %3, label %then1, label %else3

then1:                                            ; preds = %else
  ret void

merge2:                                           ; preds = %else3
  br label %merge

else3:                                            ; preds = %else
  store i32 0, ptr %a, align 4
  br label %merge2
}
