; ModuleID = 'nested_scope_shadowing.bc'
source_filename = "nested_scope_shadowing.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %x = alloca i32, align 4
  store i32 1, ptr %x, align 4
  %x1 = alloca i32, align 4
  store i32 2, ptr %x1, align 4
  %x2 = alloca i32, align 4
  store i32 3, ptr %x2, align 4
  ret void
}
