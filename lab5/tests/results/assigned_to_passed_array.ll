; ModuleID = 'assigned_to_passed_array.bc'
source_filename = "assigned_to_passed_array.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @main(ptr %a) {
entry:
  %a1 = alloca ptr, align 8
  store ptr %a, ptr %a1, align 8
  %b = alloca i32, align 4
  store i32 1, ptr %b, align 4
  %0 = load ptr, ptr %a1, align 8
  %1 = getelementptr i32, ptr %0, i32 0
  %2 = load i32, ptr %1, align 4
  store i32 %2, ptr %b, align 4
  ret i32 0
}
