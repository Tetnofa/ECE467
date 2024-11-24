; ModuleID = 'test_int_assign.bc'
source_filename = "test_int_assign.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %x = alloca i32, align 4
  store i32 42, ptr %x, align 4
  ret void
}
