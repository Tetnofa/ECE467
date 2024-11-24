; ModuleID = 'mixed_operations.bc'
source_filename = "mixed_operations.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %flag = alloca i1, align 1
  store i32 5, ptr %x, align 4
  store i32 10, ptr %y, align 4
  store i1 true, ptr %flag, align 1
  %0 = load i1, ptr %flag, align 1
  %1 = load i32, ptr %x, align 4
  %2 = load i32, ptr %y, align 4
  %3 = icmp slt i32 %1, %2
  %4 = and i1 %0, %3
  br i1 %4, label %then, label %merge

then:                                             ; preds = %entry
  %5 = load i32, ptr %x, align 4
  %6 = add i32 %5, 1
  store i32 %6, ptr %x, align 4
  store i1 false, ptr %flag, align 1
  br label %merge

merge:                                            ; preds = %then, %entry
  ret void
}
