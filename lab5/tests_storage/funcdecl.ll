; ModuleID = 'funcdecl.bc'
source_filename = "funcdecl.bc"
target triple = "x86_64-unknown-linux-gnu"

define i32 @a(i32 %a, i32 %b, i1 zeroext %c) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %c3 = alloca i1, align 1
  store i1 %c, ptr %c3, align 1
  ret i32 2029
}

define i32 @func1() {
entry:
  ret i32 2
}

define i32 @func2() {
entry:
  ret i32 3
}

define i32 @func3() {
entry:
  ret i32 4
}

define i32 @func4() {
entry:
  ret i32 5
}

define void @func5() {
entry:
  ret void
}

define void @func6() {
entry:
  ret void
}

define i1 @func7() {
entry:
  ret i1 true
}

define i1 @func8(i32 %a) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  ret i1 false
}

define i32 @func9(i32 %a, i32 %b, ptr %c) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %c3 = alloca ptr, align 8
  store ptr %c, ptr %c3, align 8
  ret i32 2
}

define i32 @main(i32 %a, i32 %b) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  ret i32 1
}

define void @noretunr() {
entry:
  ret void
}

define void @noreturn() {
entry:
  ret void
}

define void @poopee(i32 %a, i32 %b, i1 zeroext %c) {
entry:
  %a1 = alloca i32, align 4
  store i32 %a, ptr %a1, align 4
  %b2 = alloca i32, align 4
  store i32 %b, ptr %b2, align 4
  %c3 = alloca i1, align 1
  store i1 %c, ptr %c3, align 1
  %af = alloca i32, align 4
  ret void
}
