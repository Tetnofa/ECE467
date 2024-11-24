; ModuleID = 'ifstmt.bc'
source_filename = "ifstmt.bc"
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
  %d = alloca i32, align 4
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
  %14 = load i32, ptr %f, align 4
  %15 = icmp sgt i32 %14, 3
  br i1 %15, label %then16, label %else18

else15:                                           ; preds = %merge11
  store i32 2, ptr %b2, align 4
  %16 = load i32, ptr %b2, align 4
  store i32 %16, ptr %f, align 4
  br label %merge14

then16:                                           ; preds = %merge14
  %17 = load i32, ptr %d, align 4
  store i32 %17, ptr %f, align 4
  br label %merge17

merge17:                                          ; preds = %then16
  ret void

else18:                                           ; preds = %merge14
  ret void
}

define void @amd() {
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
  br i1 %2, label %then, label %else

then:                                             ; preds = %entry
  %3 = load i1, ptr %flag, align 1
  br i1 %3, label %then1, label %merge2

merge:                                            ; preds = %merge6, %merge2
  ret void

else:                                             ; preds = %entry
  %4 = load i1, ptr %flag, align 1
  br i1 %4, label %then5, label %else7

then1:                                            ; preds = %then
  %5 = load i32, ptr %x, align 4
  %6 = sub i32 %5, 1
  store i32 %6, ptr %x, align 4
  %7 = load i32, ptr %x, align 4
  %8 = load i32, ptr %y, align 4
  %9 = icmp eq i32 %7, %8
  br i1 %9, label %then3, label %merge4

merge2:                                           ; preds = %merge4, %then
  br label %merge

then3:                                            ; preds = %then1
  store i1 false, ptr %flag, align 1
  br label %merge4

merge4:                                           ; preds = %then3, %then1
  br label %merge2

then5:                                            ; preds = %else
  ret void

merge6:                                           ; preds = %merge9
  br label %merge

else7:                                            ; preds = %else
  %10 = load i1, ptr %flag, align 1
  br i1 %10, label %then8, label %else10

then8:                                            ; preds = %else7
  ret void

merge9:                                           ; preds = %merge12
  br label %merge6

else10:                                           ; preds = %else7
  %11 = load i1, ptr %flag, align 1
  br i1 %11, label %then11, label %merge12

then11:                                           ; preds = %else10
  ret void

merge12:                                          ; preds = %else10
  br label %merge9
}

define i32 @main() {
entry:
  %a = alloca i32, align 4
  %f = alloca i32, align 4
  %z = alloca i32, align 4
  store i32 4, ptr %z, align 4
  %0 = load i32, ptr %a, align 4
  %1 = icmp eq i32 %0, 0
  br i1 %1, label %then, label %else

then:                                             ; preds = %entry
  store i32 3, ptr %a, align 4
  br label %merge

merge:                                            ; preds = %merge2, %then
  ret i32 3

else:                                             ; preds = %entry
  store i32 2, ptr %f, align 4
  %2 = load i32, ptr %f, align 4
  %3 = icmp eq i32 %2, 2
  br i1 %3, label %then1, label %else3

then1:                                            ; preds = %else
  ret i32 2

merge2:                                           ; preds = %merge8
  br label %merge

else3:                                            ; preds = %else
  %4 = load i32, ptr %f, align 4
  %5 = icmp ne i32 %4, 3
  br i1 %5, label %then4, label %else6

then4:                                            ; preds = %else3
  ret i32 3

merge5:                                           ; preds = %else6
  %6 = load i32, ptr %z, align 4
  %7 = icmp sge i32 %6, 3
  br i1 %7, label %then7, label %merge8

else6:                                            ; preds = %else3
  store i32 5, ptr %f, align 4
  br label %merge5

then7:                                            ; preds = %merge5
  %8 = load i32, ptr %z, align 4
  %9 = icmp eq i32 %8, 4
  br i1 %9, label %then9, label %merge10

merge8:                                           ; preds = %merge10, %merge5
  br label %merge2

then9:                                            ; preds = %then7
  %10 = load i32, ptr %f, align 4
  %11 = load i32, ptr %a, align 4
  %12 = icmp slt i32 %10, %11
  br i1 %12, label %then11, label %else13

merge10:                                          ; preds = %merge12, %then7
  br label %merge8

then11:                                           ; preds = %then9
  ret i32 4

merge12:                                          ; preds = %else13
  br label %merge10

else13:                                           ; preds = %then9
  %13 = load i32, ptr %f, align 4
  store i32 %13, ptr %a, align 4
  br label %merge12
}

define void @main2() {
entry:
  %a = alloca i32, align 4
  store i32 3, ptr %a, align 4
  %0 = load i32, ptr %a, align 4
  %1 = icmp sgt i32 %0, 0
  br i1 %1, label %then, label %else

then:                                             ; preds = %entry
  ret void

merge:                                            ; preds = %else
  ret void

else:                                             ; preds = %entry
  store i32 2, ptr %a, align 4
  br label %merge
}
