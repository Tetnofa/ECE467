; ModuleID = 'scalardecl.bc'
source_filename = "scalardecl.bc"
target triple = "x86_64-unknown-linux-gnu"

@global1 = common global i32 0
@global2 = common global i32 0
@global3 = common global i32 0
@global4 = common global i32 0
@gloabl5 = common global i1 false
@a = common global i32 0

define i1 @aain(i32 %a, i32 %b, i32 %c, i32 %x) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %c3 = alloca i32, align 4
  store i32 %c, ptr %c3, align 4
  %x4 = alloca i32, align 4
  store i32 %x, ptr %x4, align 4
  %ad = alloca i32, align 4
  %bc = alloca i32, align 4
  %cd = alloca i32, align 4
  %xd = alloca i32, align 4
  ret i1 true
}

define i32 @main(i32 %a, i32 %b, i32 %c, i1 zeroext %x) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %c3 = alloca i32, align 4
  store i32 %c, ptr %c3, align 4
  %x4 = alloca i1, align 1
  store i1 %x, ptr %x4, align 1
  %y = alloca i1, align 1
  %z = alloca i32, align 4
  ret i32 3
}
