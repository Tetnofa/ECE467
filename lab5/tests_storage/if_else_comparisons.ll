; ModuleID = 'if_else_comparisons.bc'
source_filename = "if_else_comparisons.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  store i32 10, ptr %x, align 4
  store i32 5, ptr %y, align 4
  %0 = load i32, ptr %x, align 4
  %1 = load i32, ptr %y, align 4
  %2 = icmp sgt i32 %0, %1
  br i1 %2, label %then, label %else

then:                                             ; preds = %entry
  %3 = load i32, ptr %x, align 4
  %4 = load i32, ptr %y, align 4
  %5 = sub i32 %3, %4
  store i32 %5, ptr %x, align 4
  br label %merge

merge:                                            ; preds = %else, %then
  ret void

else:                                             ; preds = %entry
  %6 = load i32, ptr %y, align 4
  %7 = load i32, ptr %x, align 4
  %8 = sub i32 %6, %7
  store i32 %8, ptr %y, align 4
  br label %merge
}
