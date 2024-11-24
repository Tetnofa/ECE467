; ModuleID = 'assigned_to_array.bc'
source_filename = "assigned_to_array.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @main() {
entry:
  %a = alloca [1 x i32], align 4
  %b = alloca i32, align 4
  %0 = getelementptr [1 x i32], ptr %a, i32 0, i32 0
  %1 = load i32, ptr %0, align 4
  store i32 %1, ptr %b, align 4
  ret i32 0
}
