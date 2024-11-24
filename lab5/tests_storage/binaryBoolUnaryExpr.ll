; ModuleID = 'binaryBoolUnaryExpr.bc'
source_filename = "binaryBoolUnaryExpr.bc"
target triple = "x86_64-unknown-linux-gnu"

define i1 @boolexprChecker(i1 zeroext %a, i1 zeroext %b) {
entry:
  %a1 = alloca i1, align 1
  store i1 %a, ptr %a1, align 1
  %b2 = alloca i1, align 1
  store i1 %b, ptr %b2, align 1
  %c = alloca i1, align 1
  %num = alloca i32, align 4
  %num2 = alloca i32, align 4
  %num1 = alloca i32, align 4
  %0 = load i1, ptr %a1, align 1
  %1 = load i1, ptr %b2, align 1
  %2 = load i1, ptr %c, align 1
  %3 = or i1 %1, %2
  %4 = and i1 %0, %3
  %5 = load i1, ptr %a1, align 1
  %6 = and i1 %4, %5
  %7 = load i1, ptr %b2, align 1
  %8 = and i1 %6, %7
  %9 = load i1, ptr %c, align 1
  %10 = load i32, ptr %num1, align 4
  %11 = load i32, ptr %num2, align 4
  %12 = icmp sle i32 %10, %11
  %13 = or i1 %9, %12
  %14 = and i1 %8, %13
  %15 = load i32, ptr %num2, align 4
  %16 = load i32, ptr %num1, align 4
  %17 = icmp sge i32 %15, %16
  %18 = and i1 %14, %17
  %19 = load i32, ptr %num, align 4
  %20 = load i32, ptr %num2, align 4
  %21 = icmp eq i32 %19, %20
  %22 = and i1 %18, %21
  ret i1 %22
}

define i1 @checker() {
entry:
  %a = alloca i1, align 1
  %b = alloca i1, align 1
  %c = alloca i1, align 1
  %num = alloca i32, align 4
  %num2 = alloca i32, align 4
  %0 = load i1, ptr %a, align 1
  %1 = load i1, ptr %b, align 1
  %2 = load i1, ptr %c, align 1
  %3 = or i1 %1, %2
  %4 = and i1 %0, %3
  %5 = load i1, ptr %a, align 1
  %6 = and i1 %4, %5
  %7 = load i1, ptr %b, align 1
  %8 = and i1 %6, %7
  %9 = load i32, ptr %num, align 4
  %10 = load i32, ptr %num2, align 4
  %11 = icmp slt i32 %9, %10
  %12 = load i32, ptr %num, align 4
  %13 = load i32, ptr %num2, align 4
  %14 = icmp sgt i32 %12, %13
  %15 = or i1 %11, %14
  %16 = load i32, ptr %num, align 4
  %17 = load i32, ptr %num2, align 4
  %18 = icmp eq i32 %16, %17
  %19 = or i1 %15, %18
  %20 = load i32, ptr %num, align 4
  %21 = load i32, ptr %num2, align 4
  %22 = icmp ne i32 %20, %21
  %23 = or i1 %19, %22
  %24 = and i1 %8, %23
  ret i1 %24
}

define i32 @main() {
entry:
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %f = alloca i32, align 4
  %g = alloca i32, align 4
  %d = alloca i32, align 4
  %c = alloca i32, align 4
  %0 = load i32, ptr %a, align 4
  %1 = load i32, ptr %b, align 4
  %2 = add i32 %0, %1
  %3 = load i32, ptr %c, align 4
  %4 = add i32 %2, %3
  %5 = add i32 %4, 1
  %6 = add i32 %5, 2
  %7 = load i32, ptr %f, align 4
  %8 = sdiv i32 3, %7
  %9 = load i32, ptr %a, align 4
  %10 = sdiv i32 %8, %9
  %11 = load i32, ptr %g, align 4
  %12 = sdiv i32 %10, %11
  %13 = load i32, ptr %b, align 4
  %14 = sdiv i32 %12, %13
  %15 = load i32, ptr %c, align 4
  %16 = mul i32 %14, %15
  %17 = load i32, ptr %b, align 4
  %18 = mul i32 %16, %17
  %19 = load i32, ptr %d, align 4
  %20 = mul i32 %18, %19
  %21 = add i32 %6, %20
  ret i32 %21
}

define i1 @unaryChecker(i1 zeroext %a, i1 zeroext %c) {
entry:
  %a1 = alloca i1, align 1
  store i1 %a, ptr %a1, align 1
  %c2 = alloca i1, align 1
  store i1 %c, ptr %c2, align 1
  %b = alloca i1, align 1
  %f = alloca i32, align 4
  %d = alloca i32, align 4
  %0 = load i1, ptr %a1, align 1
  %1 = xor i1 %0, true
  %2 = load i1, ptr %b, align 1
  %3 = xor i1 %2, true
  %4 = load i1, ptr %c2, align 1
  %5 = xor i1 %4, true
  %6 = or i1 %3, %5
  %7 = and i1 %1, %6
  %8 = load i1, ptr %c2, align 1
  %9 = and i1 %7, %8
  %10 = load i32, ptr %f, align 4
  %11 = load i32, ptr %d, align 4
  %12 = icmp ne i32 %10, %11
  %13 = and i1 %9, %12
  %14 = load i32, ptr %f, align 4
  %15 = load i32, ptr %d, align 4
  %16 = icmp slt i32 %14, %15
  %17 = and i1 %13, %16
  %18 = load i32, ptr %f, align 4
  %19 = sub i32 0, %18
  %20 = load i32, ptr %d, align 4
  %21 = sub i32 0, %20
  %22 = icmp ne i32 %19, %21
  %23 = load i32, ptr %f, align 4
  %24 = sub i32 0, %23
  %25 = load i32, ptr %d, align 4
  %26 = sub i32 0, %25
  %27 = icmp eq i32 %24, %26
  %28 = or i1 %22, %27
  %29 = and i1 %17, %28
  ret i1 %29
}
