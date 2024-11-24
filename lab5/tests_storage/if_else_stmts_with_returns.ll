; ModuleID = 'if_else_stmts_with_returns.bc'
source_filename = "if_else_stmts_with_returns.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @adkiwjha(i32 %a, i32 %b, i32 %c) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %c3 = alloca i32, align 4
  store i32 %c, ptr %c3, align 4
  %f = alloca i32, align 4
  store i32 3, ptr %a1, align 4
  %0 = load i32, ptr %a1, align 4
  %1 = icmp sgt i32 %0, 0
  br i1 %1, label %then, label %else

then:                                             ; preds = %entry
  ret void

merge:                                            ; preds = %else
  %2 = load i32, ptr %f, align 4
  %3 = icmp sgt i32 %2, 0
  br i1 %3, label %then4, label %else6

else:                                             ; preds = %entry
  store i32 2, ptr %a1, align 4
  %4 = load i32, ptr %a1, align 4
  store i32 %4, ptr %f, align 4
  br label %merge

then4:                                            ; preds = %merge
  ret void

merge5:                                           ; preds = %else6
  %5 = load i32, ptr %f, align 4
  %6 = icmp sgt i32 %5, 0
  br i1 %6, label %then7, label %else9

else6:                                            ; preds = %merge
  store i32 2, ptr %b2, align 4
  %7 = load i32, ptr %b2, align 4
  store i32 %7, ptr %f, align 4
  br label %merge5

then7:                                            ; preds = %merge5
  ret void

merge8:                                           ; preds = %else9
  %8 = load i32, ptr %f, align 4
  %9 = icmp sgt i32 %8, 0
  br i1 %9, label %then10, label %else12

else9:                                            ; preds = %merge5
  store i32 2, ptr %b2, align 4
  %10 = load i32, ptr %b2, align 4
  store i32 %10, ptr %f, align 4
  br label %merge8

then10:                                           ; preds = %merge8
  ret void

merge11:                                          ; preds = %else12
  %11 = load i32, ptr %f, align 4
  %12 = icmp sgt i32 %11, 0
  br i1 %12, label %then13, label %else15

else12:                                           ; preds = %merge8
  store i32 2, ptr %b2, align 4
  %13 = load i32, ptr %b2, align 4
  store i32 %13, ptr %f, align 4
  br label %merge11

then13:                                           ; preds = %merge11
  ret void

merge14:                                          ; preds = %else15
  ret void

else15:                                           ; preds = %merge11
  store i32 2, ptr %b2, align 4
  %14 = load i32, ptr %b2, align 4
  store i32 %14, ptr %f, align 4
  br label %merge14
}
