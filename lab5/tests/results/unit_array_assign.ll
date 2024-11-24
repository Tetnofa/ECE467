; ModuleID = 'unit_array_assign.bc'
source_filename = "unit_array_assign.bc"
target triple = "x86_64-unknown-linux-gnu"

@arr = common global [3 x i32] zeroinitializer

define void @main() {
entry:
  store i32 1, ptr @arr, align 4
  ret void
}
