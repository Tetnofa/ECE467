; ModuleID = 'arraydecl.bc'
source_filename = "arraydecl.bc"
target triple = "x86_64-unknown-linux-gnu"

@global1 = common global i32 0
@global2 = common global i32 0
@global3 = common global i32 0
@global4 = common global i32 0
@gloabl5 = common global i1 false
@arr = common global [10 x i32] zeroinitializer
@arr623 = common global [12341 x i1] zeroinitializer

define i32 @main(i32 %a, i32 %b, i32 %c, i1 zeroext %x) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %c3 = alloca i32, align 4
  store i32 %c, ptr %c3, align 4
  %x4 = alloca i1, align 1
  store i1 %x, ptr %x4, align 1
  %y = alloca i1, align 1
  %z = alloca i32, align 4
  %arr = alloca [10 x i32], align 4
  %arr2 = alloca [10 x i32], align 4
  %arr3 = alloca [10 x i32], align 4
  %arr4 = alloca [10 x i32], align 4
  %arr5 = alloca [10 x i32], align 4
  %arr6 = alloca [12312 x i1], align 1
  ret i32 3
}

define i32 @poo(i32 %a, i32 %b, i32 %c, i32 %x) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %c3 = alloca i32, align 4
  store i32 %c, ptr %c3, align 4
  %x4 = alloca i32, align 4
  store i32 %x, ptr %x4, align 4
  %ad = alloca i32, align 4
  %bc = alloca i32, align 4
  %cd = alloca i32, align 4
  %xd = alloca i32, align 4
  %arr641 = alloca [12312 x i1], align 1
  %arr = alloca [10 x i32], align 4
  %arr2 = alloca [10 x i32], align 4
  %arr3 = alloca [10 x i32], align 4
  %arr4 = alloca [10 x i32], align 4
  %arr5 = alloca [10 x i32], align 4
  ret i32 123213
}
