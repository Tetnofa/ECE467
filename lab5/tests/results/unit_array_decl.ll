; ModuleID = 'unit_array_decl.bc'
source_filename = "unit_array_decl.bc"
target triple = "x86_64-unknown-linux-gnu"

@arr = common global [3 x i32] zeroinitializer

define void @main() {
entry:
  ret void
}
