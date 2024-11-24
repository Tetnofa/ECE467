; ModuleID = 'function_parameters.bc'
source_filename = "function_parameters.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @calculate(i32 %a, i32 %b, i1 zeroext %flag) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %flag3 = alloca i1, align 1
  store i1 %flag, ptr %flag3, align 1
  %result = alloca i32, align 4
  store i32 0, ptr %result, align 4
  %0 = load i1, ptr %flag3, align 1
  br i1 %0, label %then, label %else

then:                                             ; preds = %entry
  %1 = load i32, ptr %a1, align 4
  %2 = load i32, ptr %b2, align 4
  %3 = add i32 %1, %2
  store i32 %3, ptr %result, align 4
  br label %merge

merge:                                            ; preds = %else, %then
  %4 = load i32, ptr %result, align 4
  ret i32 %4

else:                                             ; preds = %entry
  %5 = load i32, ptr %a1, align 4
  %6 = load i32, ptr %b2, align 4
  %7 = sub i32 %5, %6
  store i32 %7, ptr %result, align 4
  br label %merge
}

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
  %2 = load i1, ptr %flag, align 1
  %3 = call i32 @calculate(i32 %0, i32 %1, i1 %2)
  store i32 %3, ptr %x, align 4
  ret void
}
