; ModuleID = 'global_local_interaction.bc'
source_filename = "global_local_interaction.bc"
target triple = "x86_64-unknown-linux-gnu"

@globalX = common global i32 0
@globalFlag = common global i1 false

define void @main() {
entry:
  %localX = alloca i32, align 4
  %localFlag = alloca i1, align 1
  store i32 42, ptr @globalX, align 4
  %0 = load i32, ptr @globalX, align 4
  store i32 %0, ptr %localX, align 4
  %1 = load i32, ptr %localX, align 4
  %2 = icmp sgt i32 %1, 0
  store i1 %2, ptr @globalFlag, align 1
  %3 = load i1, ptr @globalFlag, align 1
  store i1 %3, ptr %localFlag, align 1
  ret void
}
