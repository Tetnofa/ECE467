; ModuleID = 'complex_conditions_with_returns.bc'
source_filename = "complex_conditions_with_returns.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @complexConditionsWithReturns() {
entry:
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  store i32 3, ptr %x, align 4
  store i32 4, ptr %y, align 4
  %0 = load i32, ptr %y, align 4
  %1 = icmp slt i32 %0, 0
  br i1 %1, label %then, label %merge

then:                                             ; preds = %entry
  %2 = load i32, ptr %y, align 4
  store i32 %2, ptr %x, align 4
  br label %merge

merge:                                            ; preds = %then, %entry
  %3 = load i32, ptr %x, align 4
  %4 = load i32, ptr %y, align 4
  %5 = icmp slt i32 %3, %4
  %6 = load i32, ptr %x, align 4
  %7 = icmp sgt i32 %6, 0
  %8 = and i1 %5, %7
  br i1 %8, label %then1, label %else

then1:                                            ; preds = %merge
  %9 = load i32, ptr %x, align 4
  store i32 %9, ptr %y, align 4
  ret void

merge2:                                           ; No predecessors!
  %10 = load i32, ptr %y, align 4
  %11 = icmp slt i32 %10, 0
  br i1 %11, label %then3, label %merge4

else:                                             ; preds = %merge
  %12 = load i32, ptr %y, align 4
  %13 = load i32, ptr %x, align 4
  %14 = sub i32 %12, %13
  store i32 %14, ptr %y, align 4
  ret void

then3:                                            ; preds = %merge2
  ret void

merge4:                                           ; preds = %merge2
  ret void
}
