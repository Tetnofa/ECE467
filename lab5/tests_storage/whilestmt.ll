; ModuleID = 'whilestmt.bc'
source_filename = "whilestmt.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @main() {
entry:
  %a = alloca i32, align 4
  store i32 1, ptr %a, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %0 = load i32, ptr %a, align 4
  %1 = icmp slt i32 %0, 10
  br i1 %1, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %2 = load i32, ptr %a, align 4
  %3 = add i32 %2, 1
  store i32 %3, ptr %a, align 4
  br label %while.cond

while.exit:                                       ; preds = %while.cond
  %4 = load i32, ptr %a, align 4
  ret i32 %4
}

define i32 @main2(i32 %b) {
entry:
  %b1 = alloca i32, align 4
  store i32 %b, ptr %b1, align 4
  br label %while.cond

while.cond:                                       ; preds = %entry
  %0 = load i32, ptr %b1, align 4
  %1 = icmp slt i32 %0, 10
  br i1 %1, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %2 = load i32, ptr %b1, align 4
  %3 = add i32 %2, 1
  store i32 %3, ptr %b1, align 4
  ret i32 3

while.exit:                                       ; preds = %while.cond
  %4 = load i32, ptr %b1, align 4
  ret i32 %4
}

define i32 @nested(i32 %a, ptr %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca ptr, align 8
  store ptr %b, ptr %b2, align 8
  br label %while.cond

while.cond:                                       ; preds = %while.exit5, %entry
  %0 = load i32, ptr %a1, align 4
  %1 = icmp slt i32 %0, 10
  br i1 %1, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  br label %while.cond3

while.exit:                                       ; preds = %while.cond
  ret i32 2

while.cond3:                                      ; preds = %while.exit8, %while.body
  %2 = load i32, ptr %a1, align 4
  %3 = icmp slt i32 %2, 10
  br i1 %3, label %while.body4, label %while.exit5

while.body4:                                      ; preds = %while.cond3
  br label %while.cond6

while.exit5:                                      ; preds = %while.cond3
  br label %while.cond

while.cond6:                                      ; preds = %while.exit14, %while.body4
  %4 = load ptr, ptr %b2, align 8
  %5 = getelementptr i32, ptr %4, i32 3
  %6 = load i32, ptr %5, align 4
  %7 = load i32, ptr %a1, align 4
  %8 = icmp slt i32 %6, %7
  br i1 %8, label %while.body7, label %while.exit8

while.body7:                                      ; preds = %while.cond6
  br label %while.cond9

while.exit8:                                      ; preds = %while.cond6
  br label %while.cond3

while.cond9:                                      ; preds = %while.body7
  %9 = load i32, ptr %a1, align 4
  %10 = load ptr, ptr %b2, align 8
  %11 = getelementptr i32, ptr %10, i32 %9
  %12 = load i32, ptr %11, align 4
  %13 = icmp slt i32 %12, 30
  br i1 %13, label %while.body10, label %while.exit11

while.body10:                                     ; preds = %while.cond9
  ret i32 2

while.exit11:                                     ; preds = %while.cond9
  br label %while.cond12

while.cond12:                                     ; preds = %while.exit17, %while.exit11
  %14 = load i32, ptr %a1, align 4
  %15 = load ptr, ptr %b2, align 8
  %16 = getelementptr i32, ptr %15, i32 %14
  %17 = load i32, ptr %16, align 4
  %18 = icmp slt i32 %17, 123
  br i1 %18, label %while.body13, label %while.exit14

while.body13:                                     ; preds = %while.cond12
  br label %while.cond15

while.exit14:                                     ; preds = %while.cond12
  br label %while.cond6

while.cond15:                                     ; preds = %while.body13
  %19 = load i32, ptr %a1, align 4
  %20 = icmp sge i32 %19, 0
  br i1 %20, label %while.body16, label %while.exit17

while.body16:                                     ; preds = %while.cond15
  ret i32 3

while.exit17:                                     ; preds = %while.cond15
  br label %while.cond12
}

define i32 @nestedNoReturn(i32 %a, ptr %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca ptr, align 8
  store ptr %b, ptr %b2, align 8
  %c = alloca [31 x i32], align 4
  br label %while.cond

while.cond:                                       ; preds = %while.exit5, %entry
  %0 = load i32, ptr %a1, align 4
  %1 = load ptr, ptr %b2, align 8
  %2 = getelementptr i32, ptr %1, i32 %0
  %3 = load i32, ptr %2, align 4
  %4 = icmp slt i32 %3, 10
  br i1 %4, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %5 = load i32, ptr %a1, align 4
  %6 = add i32 %5, 1
  store i32 %6, ptr %a1, align 4
  br label %while.cond3

while.exit:                                       ; preds = %while.cond
  %7 = load i32, ptr %a1, align 4
  ret i32 %7

while.cond3:                                      ; preds = %while.exit8, %while.body
  %8 = load i32, ptr %a1, align 4
  %9 = load i32, ptr %a1, align 4
  %10 = load ptr, ptr %b2, align 8
  %11 = getelementptr i32, ptr %10, i32 %9
  %12 = load i32, ptr %11, align 4
  %13 = icmp slt i32 %8, %12
  br i1 %13, label %while.body4, label %while.exit5

while.body4:                                      ; preds = %while.cond3
  br label %while.cond6

while.exit5:                                      ; preds = %while.cond3
  br label %while.cond

while.cond6:                                      ; preds = %while.exit11, %while.body4
  %14 = load i32, ptr %a1, align 4
  %15 = load ptr, ptr %b2, align 8
  %16 = getelementptr i32, ptr %15, i32 1
  %17 = load i32, ptr %16, align 4
  %18 = icmp sge i32 %14, %17
  br i1 %18, label %while.body7, label %while.exit8

while.body7:                                      ; preds = %while.cond6
  br label %while.cond9

while.exit8:                                      ; preds = %while.cond6
  br label %while.cond3

while.cond9:                                      ; preds = %while.body10, %while.body7
  %19 = getelementptr [31 x i32], ptr %c, i32 0, i32 30
  %20 = load i32, ptr %19, align 4
  %21 = icmp ne i32 %20, 3
  br i1 %21, label %while.body10, label %while.exit11

while.body10:                                     ; preds = %while.cond9
  %22 = getelementptr [31 x i32], ptr %c, i32 0, i32 30
  store i32 3, ptr %22, align 4
  br label %while.cond9

while.exit11:                                     ; preds = %while.cond9
  br label %while.cond6
}
