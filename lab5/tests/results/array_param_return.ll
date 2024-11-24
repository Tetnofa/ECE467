; ModuleID = 'array_param_return.bc'
source_filename = "array_param_return.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @x3(ptr %c) {
entry:
  %c1 = alloca ptr, align 8
  store ptr %c, ptr %c1, align 8
  %0 = load ptr, ptr %c1, align 8
  %1 = getelementptr i32, ptr %0, i32 30
  %2 = load i32, ptr %1, align 4
  ret i32 %2
}
