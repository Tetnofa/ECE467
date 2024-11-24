; ModuleID = 'var_decl_basic.bc'
source_filename = "var_decl_basic.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %x = alloca i32, align 4
  %b = alloca i1, align 1
  %y = alloca i32, align 4
  store i32 42, ptr %x, align 4
  store i32 100, ptr %y, align 4
  store i1 true, ptr %b, align 1
  ret void
}
