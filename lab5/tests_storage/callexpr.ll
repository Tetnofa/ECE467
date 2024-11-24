; ModuleID = 'callexpr.bc'
source_filename = "callexpr.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @addFunc(i32 %a, i32 %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %0 = load i32, ptr %a1, align 4
  %1 = load i32, ptr %b2, align 4
  %2 = add i32 %0, %1
  ret i32 %2
}

define i32 @arrFunc(ptr %arr) {
entry:
  %arr1 = alloca ptr, align 8
  store ptr %arr, ptr %arr1, align 8
  %0 = load ptr, ptr %arr1, align 8
  %1 = getelementptr i32, ptr %0, i32 0
  %2 = load i32, ptr %1, align 4
  %3 = load ptr, ptr %arr1, align 8
  %4 = getelementptr i32, ptr %3, i32 1
  %5 = load i32, ptr %4, align 4
  %6 = add i32 %2, %5
  ret i32 %6
}

define i32 @callArray2() {
entry:
  %arr = alloca [2 x i32], align 4
  %0 = getelementptr [2 x i32], ptr %arr, i32 0, i32 0
  %1 = call i32 @callerArray2(ptr %0)
  ret i32 %1
}

define i32 @callIntTrivialArrayParam(ptr %arr) {
entry:
  %arr1 = alloca ptr, align 8
  store ptr %arr, ptr %arr1, align 8
  %0 = load ptr, ptr %arr1, align 8
  %1 = call i32 @trivial(ptr %0)
  ret i32 %1
}

define i32 @callIntTrivialArrayStack(i32 %a) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %arr = alloca [3 x i32], align 4
  %0 = getelementptr [3 x i32], ptr %arr, i32 0, i32 0
  %1 = call i32 @trivial(ptr %0)
  ret i32 %1
}

define i32 @callScalar() {
entry:
  %arr = alloca [2 x i32], align 4
  %0 = getelementptr [2 x i32], ptr %arr, i32 0, i32 0
  %1 = load i32, ptr %0, align 4
  %2 = getelementptr [2 x i32], ptr %arr, i32 0, i32 1
  %3 = load i32, ptr %2, align 4
  %4 = call i32 @callerScalar2(i32 %1, i32 %3)
  ret i32 %4
}

define i1 @callTrivialArray() {
entry:
  %arr = alloca [2 x i32], align 4
  %0 = getelementptr [2 x i32], ptr %arr, i32 0, i32 0
  %1 = call i1 @trivialArray(ptr %0)
  ret i1 %1
}

define i32 @callerArray(ptr %arr) {
entry:
  %arr1 = alloca ptr, align 8
  store ptr %arr, ptr %arr1, align 8
  %0 = load ptr, ptr %arr1, align 8
  %1 = call i32 @arrFunc(ptr %0)
  ret i32 %1
}

define i32 @callerArray2(ptr %arr) {
entry:
  %arr1 = alloca ptr, align 8
  store ptr %arr, ptr %arr1, align 8
  %0 = load ptr, ptr %arr1, align 8
  %1 = call i32 @callerArray(ptr %0)
  ret i32 %1
}

define i32 @callerScalar2(i32 %a, i32 %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %0 = load i32, ptr %a1, align 4
  %1 = load i32, ptr %b2, align 4
  %2 = add i32 %0, %1
  %3 = call i32 @callerScale(i32 %2)
  ret i32 %3
}

define i32 @callerScale(i32 %a) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %0 = load i32, ptr %a1, align 4
  %1 = call i32 @addFunc(i32 %0, i32 1)
  ret i32 %1
}

define i32 @func(i32 %a, i32 %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %0 = load i32, ptr %a1, align 4
  %1 = load i32, ptr %b2, align 4
  %2 = add i32 %0, %1
  ret i32 %2
}

define i32 @main() {
entry:
  %x = alloca i32, align 4
  %y = alloca i32, align 4
  %0 = call i32 @func(i32 3, i32 4)
  %1 = load i32, ptr %x, align 4
  %2 = load i32, ptr %y, align 4
  %3 = call i32 @func(i32 %1, i32 %2)
  %4 = call i32 @func(i32 %0, i32 %3)
  ret i32 %4
}

define i1 @main2() {
entry:
  %0 = call i32 @callScalar()
  %1 = icmp eq i32 %0, 3
  ret i1 %1
}

define void @recursive(i32 %a) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %0 = load i32, ptr %a1, align 4
  %1 = add i32 %0, 1
  call void @recursive(i32 %1)
  ret void
}

define i32 @trivial(ptr %arr) {
entry:
  %arr1 = alloca ptr, align 8
  store ptr %arr, ptr %arr1, align 8
  %0 = load ptr, ptr %arr1, align 8
  %1 = getelementptr i32, ptr %0, i32 0
  %2 = load i32, ptr %1, align 4
  ret i32 %2
}

define i1 @trivialArray(ptr %arr) {
entry:
  %arr1 = alloca ptr, align 8
  store ptr %arr, ptr %arr1, align 8
  %arr2 = alloca [30 x i32], align 4
  %0 = getelementptr [30 x i32], ptr %arr2, i32 0, i32 0
  %1 = call i32 @callIntTrivialArrayParam(ptr %0)
  %2 = icmp eq i32 %1, 0
  %3 = load ptr, ptr %arr1, align 8
  %4 = getelementptr i32, ptr %3, i32 0
  %5 = load i32, ptr %4, align 4
  %6 = icmp eq i32 %5, 0
  %7 = and i1 %2, %6
  %8 = load ptr, ptr %arr1, align 8
  %9 = getelementptr i32, ptr %8, i32 201
  %10 = load i32, ptr %9, align 4
  %11 = icmp eq i32 %10, 0
  %12 = load ptr, ptr %arr1, align 8
  %13 = getelementptr i32, ptr %12, i32 0
  %14 = load i32, ptr %13, align 4
  %15 = icmp eq i32 %14, 1
  %16 = or i1 %11, %15
  %17 = and i1 %7, %16
  %18 = load ptr, ptr %arr1, align 8
  %19 = getelementptr i32, ptr %18, i32 201
  %20 = load i32, ptr %19, align 4
  %21 = icmp eq i32 %20, 1
  %22 = and i1 %17, %21
  ret i1 %22
}

define i1 @wtf() {
entry:
  %0 = call i32 @callerScale(i32 0)
  %1 = call i32 @callerScale(i32 %0)
  %2 = icmp sle i32 %1, 1
  ret i1 %2
}
