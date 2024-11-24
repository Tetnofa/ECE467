; ModuleID = 'callexpr_copy.bc'
source_filename = "callexpr_copy.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @func(ptr %a) {
entry:
  %a1 = alloca ptr, align 8
  store ptr %a, ptr %a1, align 8
  %0 = load ptr, ptr %a1, align 8
  %1 = getelementptr i32, ptr %0, i32 0
  %2 = load i32, ptr %1, align 4
  ret i32 %2
}

define i32 @main() {
entry:
  %x = alloca [1 x i32], align 4
  %0 = getelementptr [1 x i32], ptr %x, i32 0, i32 0
  store i32 1, ptr %0, align 4
  %1 = getelementptr [1 x i32], ptr %x, i32 0, i32 0
  %2 = call i32 @func(ptr %1)
  %3 = getelementptr [1 x i32], ptr %x, i32 0, i32 0
  store i32 %2, ptr %3, align 4
  %4 = getelementptr [1 x i32], ptr %x, i32 0, i32 0
  %5 = load i32, ptr %4, align 4
  ret i32 %5
}
