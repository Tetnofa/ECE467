; ModuleID = 'assign_array.bc'
source_filename = "assign_array.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @main() {
entry:
  %a = alloca [5 x i32], align 4
  %0 = getelementptr [5 x i32], ptr %a, i32 0, i32 0
  store i32 1, ptr %0, align 4
  ret i32 0
}
