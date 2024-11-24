; ModuleID = 'refexpr.bc'
source_filename = "refexpr.bc"
target triple = "x86_64-unknown-linux-gnu"

@x = common global i32 0
@y = common global [30 x i32] zeroinitializer

define i1 @abc() {
entry:
  %arr = alloca [30 x i32], align 4
  %boolarr = alloca [391 x i1], align 1
  %0 = getelementptr [391 x i1], ptr %boolarr, i32 0, i32 31
  %1 = load i1, ptr %0, align 1
  ret i1 %1
}

define i1 @aff(i32 %a, i32 %b, ptr %c, ptr %d, ptr %e, i32 %f) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %c3 = alloca ptr, align 8
  store ptr %c, ptr %c3, align 8
  %d4 = alloca ptr, align 8
  store ptr %d, ptr %d4, align 8
  %e5 = alloca ptr, align 8
  store ptr %e, ptr %e5, align 8
  %f6 = alloca i32, align 4
  store i32 %f, ptr %f6, align 4
  %boolARR = alloca [30913 x i1], align 1
  %0 = getelementptr [30913 x i1], ptr %boolARR, i32 0, i32 -31
  %1 = load i1, ptr %0, align 1
  %2 = getelementptr [30913 x i1], ptr %boolARR, i32 0, i32 31
  %3 = load i1, ptr %2, align 1
  ret i1 %3
}

define i32 @main() {
entry:
  %y = alloca i32, align 4
  %0 = load i32, ptr %y, align 4
  %1 = load i32, ptr %y, align 4
  ret i32 %1
}

define i1 @testing(ptr %a) {
entry:
  %a1 = alloca ptr, align 8
  store ptr %a, ptr %a1, align 8
  %x = alloca i32, align 4
  %0 = load i32, ptr %x, align 4
  %1 = load ptr, ptr %a1, align 8
  %2 = getelementptr i1, ptr %1, i32 %0
  %3 = load i1, ptr %2, align 1
  ret i1 %3
}

define i32 @void1() {
entry:
  %0 = load i32, ptr @x, align 4
  %1 = load i32, ptr @x, align 4
  ret i32 %1
}

define i32 @void2() {
entry:
  %z = alloca i32, align 4
  %0 = load i32, ptr %z, align 4
  %1 = load i32, ptr %z, align 4
  ret i32 %1
}

define i32 @x1(i32 %a, i32 %b, i32 %c) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %c3 = alloca i32, align 4
  store i32 %c, ptr %c3, align 4
  %arr = alloca [39 x i32], align 4
  %0 = getelementptr [39 x i32], ptr %arr, i32 0, i32 20
  %1 = load i32, ptr %0, align 4
  ret i32 %1
}

define i32 @x2() {
entry:
  %arr = alloca [31 x i32], align 4
  %0 = getelementptr [31 x i32], ptr %arr, i32 0, i32 31
  %1 = load i32, ptr %0, align 4
  ret i32 %1
}

define i32 @x3(ptr %c) {
entry:
  %c1 = alloca ptr, align 8
  store ptr %c, ptr %c1, align 8
  %arr = alloca [30 x i32], align 4
  %0 = load ptr, ptr %c1, align 8
  %1 = getelementptr i32, ptr %0, i32 30
  %2 = load i32, ptr %1, align 4
  ret i32 %2
}

define i32 @x4(ptr %d) {
entry:
  %d1 = alloca ptr, align 8
  store ptr %d, ptr %d1, align 8
  %c = alloca [30 x i32], align 4
  %0 = load ptr, ptr %d1, align 8
  %1 = getelementptr i32, ptr %0, i32 93
  %2 = load i32, ptr %1, align 4
  %3 = getelementptr [30 x i32], ptr %c, i32 0, i32 -3
  %4 = load i32, ptr %3, align 4
  ret i32 %4
}

define i32 @x5() {
entry:
  %0 = load i32, ptr getelementptr inbounds ([30 x i32], ptr @y, i32 0, i32 29), align 4
  ret i32 %0
}

define i1 @z(ptr %a) {
entry:
  %a1 = alloca ptr, align 8
  store ptr %a, ptr %a1, align 8
  %0 = load ptr, ptr %a1, align 8
  %1 = getelementptr i1, ptr %0, i32 29
  %2 = load i1, ptr %1, align 1
  ret i1 %2
}
