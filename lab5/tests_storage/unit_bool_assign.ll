; ModuleID = 'unit_bool_assign.bc'
source_filename = "unit_bool_assign.bc"
target triple = "x86_64-unknown-linux-gnu"

define void @main() {
entry:
  %flag = alloca i1, align 1
  store i1 true, ptr %flag, align 1
  ret void
}
