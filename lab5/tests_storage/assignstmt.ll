; ModuleID = 'assignstmt.bc'
source_filename = "assignstmt.bc"
target triple = "x86_64-unknown-linux-gnu"

define i1 @array(ptr %arr) {
entry:
  %arr1 = alloca ptr, align 8
  store ptr %arr, ptr %arr1, align 8
  %0 = load ptr, ptr %arr1, align 8
  %1 = getelementptr i1, ptr %0, i32 0
  store i1 true, ptr %1, align 1
  %2 = load ptr, ptr %arr1, align 8
  %3 = getelementptr i1, ptr %2, i32 0
  %4 = load i1, ptr %3, align 1
  ret i1 %4
}

define i32 @bothArrays(ptr %arr2, ptr %arr1) {
entry:
  %arr21 = alloca ptr, align 8
  store ptr %arr2, ptr %arr21, align 8
  %arr12 = alloca ptr, align 8
  store ptr %arr1, ptr %arr12, align 8
  %0 = load ptr, ptr %arr21, align 8
  %1 = getelementptr i32, ptr %0, i32 0
  %2 = load i32, ptr %1, align 4
  %3 = load ptr, ptr %arr12, align 8
  %4 = getelementptr i32, ptr %3, i32 0
  store i32 %2, ptr %4, align 4
  %5 = load ptr, ptr %arr12, align 8
  %6 = getelementptr i32, ptr %5, i32 1892
  %7 = load i32, ptr %6, align 4
  ret i32 %7
}

define i32 @main() {
entry:
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %0 = load i32, ptr %b, align 4
  store i32 %0, ptr %a, align 4
  %1 = load i32, ptr %a, align 4
  ret i32 %1
}

define i1 @padlajwhd(i32 %a, i32 %b, i32 %c, i1 zeroext %x, i1 zeroext %y) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %c3 = alloca i32, align 4
  store i32 %c, ptr %c3, align 4
  %x4 = alloca i1, align 1
  store i1 %x, ptr %x4, align 1
  %y5 = alloca i1, align 1
  store i1 %y, ptr %y5, align 1
  %0 = load i32, ptr %a1, align 4
  store i32 %0, ptr %b2, align 4
  %1 = load i32, ptr %a1, align 4
  store i32 %1, ptr %c3, align 4
  %2 = load i32, ptr %c3, align 4
  store i32 %2, ptr %a1, align 4
  %3 = load i1, ptr %y5, align 1
  store i1 %3, ptr %x4, align 1
  %4 = load i1, ptr %x4, align 1
  store i1 %4, ptr %y5, align 1
  %5 = load i1, ptr %x4, align 1
  ret i1 %5
}

define i32 @poo() {
entry:
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %0 = load i32, ptr %x, align 4
  store i32 %0, ptr %y, align 4
  %1 = load i32, ptr %a, align 4
  store i32 %1, ptr %b, align 4
  %2 = load i32, ptr %b, align 4
  store i32 %2, ptr %y, align 4
  %3 = load i32, ptr %y, align 4
  ret i32 %3
}

define i1 @stackArray(i32 %a) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %arr = alloca [10 x i32], align 4
  %0 = getelementptr [10 x i32], ptr %arr, i32 0, i32 0
  store i32 3, ptr %0, align 4
  ret i1 true
}
