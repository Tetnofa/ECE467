; ModuleID = 'unit_var_decl.bc'
source_filename = "unit_var_decl.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %x = alloca i32, align 4
  ret void
}
