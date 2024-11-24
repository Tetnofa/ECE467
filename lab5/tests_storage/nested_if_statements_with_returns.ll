; ModuleID = 'nested_if_statements_with_returns.bc'
source_filename = "nested_if_statements_with_returns.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %flag = alloca i1, align 1
  store i32 10, ptr %x, align 4
  store i32 5, ptr %y, align 4
  store i1 true, ptr %flag, align 1
  %0 = load i32, ptr %x, align 4
  %1 = load i32, ptr %y, align 4
  %2 = icmp sgt i32 %0, %1
  br i1 %2, label %then, label %merge

then:                                             ; preds = %entry
  %3 = load i1, ptr %flag, align 1
  br i1 %3, label %then1, label %merge2

merge:                                            ; preds = %merge2, %entry
  ret void

then1:                                            ; preds = %then
  %4 = load i32, ptr %x, align 4
  %5 = sub i32 %4, 1
  store i32 %5, ptr %x, align 4
  %6 = load i32, ptr %x, align 4
  %7 = load i32, ptr %y, align 4
  %8 = icmp eq i32 %6, %7
  br i1 %8, label %then3, label %merge4

merge2:                                           ; preds = %merge4, %then
  br label %merge

then3:                                            ; preds = %then1
  store i1 false, ptr %flag, align 1
  ret void

merge4:                                           ; preds = %then1
  br label %merge2
}
