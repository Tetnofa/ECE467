; ModuleID = 'array_ops.bc'
source_filename = "array_ops.bc"
target triple = "x86_64-unknown-linux-gnu"

@arr = common global [5 x i32] zeroinitializer

define void @main() {
entry:
  %i = alloca i32, align 4
  store i32 0, ptr %i, align 4
  store i32 1, ptr @arr, align 4
  %0 = load i32, ptr @arr, align 4
  %1 = mul i32 %0, 2
  store i32 %1, ptr getelementptr inbounds ([5 x i32], ptr @arr, i32 0, i32 1), align 4
  %2 = load i32, ptr getelementptr inbounds ([5 x i32], ptr @arr, i32 0, i32 1), align 4
  %3 = load i32, ptr @arr, align 4
  %4 = add i32 %2, %3
  store i32 %4, ptr getelementptr inbounds ([5 x i32], ptr @arr, i32 0, i32 2), align 4
  ret void
}
