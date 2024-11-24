; ModuleID = 'everything.bc'
source_filename = "everything.bc"
target triple = "x86_64-unknown-linux-gnu"

@globalArr = common global [100 x i32] zeroinitializer
@globalBoolArr = common global [50 x i1] zeroinitializer
@globalX = common global i32 0
@globalFlag = common global i1 false

define i32 @arrayHelper(ptr %arr, ptr %flags) {
entry:
  %arr1 = alloca ptr, align 8
  store ptr %arr, ptr %arr1, align 8
  %flags2 = alloca ptr, align 8
  store ptr %flags, ptr %flags2, align 8
  %i = alloca i32, align 4
  store i32 0, ptr %i, align 4
  br label %while.cond

while.cond:                                       ; preds = %merge, %entry
  %0 = load i32, ptr %i, align 4
  %1 = icmp slt i32 %0, 10
  br i1 %1, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %2 = load i32, ptr %i, align 4
  %3 = load ptr, ptr %flags2, align 8
  %4 = getelementptr i1, ptr %3, i32 %2
  %5 = load i1, ptr %4, align 1
  br i1 %5, label %then, label %else

while.exit:                                       ; preds = %while.cond
  %6 = load ptr, ptr %arr1, align 8
  %7 = getelementptr i32, ptr %6, i32 0
  %8 = load i32, ptr %7, align 4
  ret i32 %8

then:                                             ; preds = %while.body
  %9 = load i32, ptr %i, align 4
  %10 = load ptr, ptr %arr1, align 8
  %11 = getelementptr i32, ptr %10, i32 %9
  %12 = load i32, ptr %11, align 4
  %13 = add i32 %12, 1
  %14 = load i32, ptr %i, align 4
  %15 = load ptr, ptr %arr1, align 8
  %16 = getelementptr i32, ptr %15, i32 %14
  store i32 %13, ptr %16, align 4
  br label %merge

merge:                                            ; preds = %else, %then
  %17 = load i32, ptr %i, align 4
  %18 = add i32 %17, 1
  store i32 %18, ptr %i, align 4
  br label %while.cond

else:                                             ; preds = %while.body
  %19 = load i32, ptr %i, align 4
  %20 = load ptr, ptr %arr1, align 8
  %21 = getelementptr i32, ptr %20, i32 %19
  %22 = load i32, ptr %21, align 4
  %23 = mul i32 %22, 2
  %24 = load i32, ptr %i, align 4
  %25 = load ptr, ptr %arr1, align 8
  %26 = getelementptr i32, ptr %25, i32 %24
  store i32 %23, ptr %26, align 4
  br label %merge
}

define i1 @complexBooleanLogic(i1 zeroext %a, i1 zeroext %b, i32 %x, i32 %y) {
entry:
  %a1 = alloca i1, align 1
  store i1 %a, ptr %a1, align 1
  %b2 = alloca i1, align 1
  store i1 %b, ptr %b2, align 1
  %x3 = alloca i32, align 4
  store i32 %x, ptr %x3, align 4
  %y4 = alloca i32, align 4
  store i32 %y, ptr %y4, align 4
  %0 = load i1, ptr %a1, align 1
  %1 = xor i1 %0, true
  %2 = load i1, ptr %b2, align 1
  %3 = load i32, ptr %x3, align 4
  %4 = load i32, ptr %y4, align 4
  %5 = icmp slt i32 %3, %4
  %6 = or i1 %2, %5
  %7 = and i1 %1, %6
  %8 = load i32, ptr %x3, align 4
  %9 = load i32, ptr %y4, align 4
  %10 = icmp eq i32 %8, %9
  %11 = xor i1 %10, true
  %12 = load i32, ptr %x3, align 4
  %13 = load i32, ptr %y4, align 4
  %14 = icmp sge i32 %12, %13
  %15 = load i1, ptr %b2, align 1
  %16 = xor i1 %15, true
  %17 = and i1 %14, %16
  %18 = or i1 %11, %17
  %19 = and i1 %7, %18
  ret i1 %19
}

define void @complexNestedTest(i32 %x, i1 zeroext %flag) {
entry:
  %x1 = alloca i32, align 4
  store i32 %x, ptr %x1, align 4
  %flag2 = alloca i1, align 1
  store i1 %flag, ptr %flag2, align 1
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  store i32 0, ptr %i, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.exit5, %entry
  %0 = load i32, ptr %i, align 4
  %1 = load i32, ptr %x1, align 4
  %2 = icmp slt i32 %0, %1
  br i1 %2, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %3 = load i32, ptr %x1, align 4
  store i32 %3, ptr %j, align 4
  br label %while.cond3

while.exit:                                       ; preds = %while.cond
  ret void

while.cond3:                                      ; preds = %merge, %while.body
  %4 = load i32, ptr %j, align 4
  %5 = icmp sgt i32 %4, 0
  br i1 %5, label %while.body4, label %while.exit5

while.body4:                                      ; preds = %while.cond3
  %6 = load i32, ptr %i, align 4
  %7 = load i32, ptr %j, align 4
  %8 = add i32 %6, %7
  %9 = load i32, ptr %x1, align 4
  %10 = icmp sgt i32 %8, %9
  br i1 %10, label %then, label %else

while.exit5:                                      ; preds = %while.cond3
  %11 = load i32, ptr %i, align 4
  %12 = add i32 %11, 1
  store i32 %12, ptr %i, align 4
  br label %while.cond

then:                                             ; preds = %while.body4
  %13 = load i1, ptr %flag2, align 1
  br i1 %13, label %then6, label %else8

merge:                                            ; preds = %merge10, %merge7
  %14 = load i32, ptr %j, align 4
  %15 = sub i32 %14, 1
  store i32 %15, ptr %j, align 4
  br label %while.cond3

else:                                             ; preds = %while.body4
  %16 = load i1, ptr %flag2, align 1
  %17 = xor i1 %16, true
  %18 = load i32, ptr %i, align 4
  %19 = mul i32 %18, 2
  %20 = icmp eq i32 %19, 0
  %21 = and i1 %17, %20
  br i1 %21, label %then9, label %merge10

then6:                                            ; preds = %then
  %22 = load i32, ptr %i, align 4
  %23 = load i32, ptr %j, align 4
  %24 = mul i32 %22, %23
  call void @writeInt(i32 %24)
  br label %merge7

merge7:                                           ; preds = %else8, %then6
  call void @newLine()
  br label %merge

else8:                                            ; preds = %then
  %25 = load i32, ptr %i, align 4
  %26 = load i32, ptr %j, align 4
  %27 = add i32 %25, %26
  call void @writeInt(i32 %27)
  br label %merge7

then9:                                            ; preds = %else
  %28 = load i32, ptr %i, align 4
  %29 = load i32, ptr %j, align 4
  %30 = icmp slt i32 %28, %29
  call void @writeBool(i1 %30)
  br label %merge10

merge10:                                          ; preds = %then9, %else
  br label %merge
}

define void @complexOperations(ptr %inputArr, ptr %flagArr, i32 %size) {
entry:
  %inputArr1 = alloca ptr, align 8
  store ptr %inputArr, ptr %inputArr1, align 8
  %flagArr2 = alloca ptr, align 8
  store ptr %flagArr, ptr %flagArr2, align 8
  %size3 = alloca i32, align 4
  store i32 %size, ptr %size3, align 4
  %tempArr = alloca [100 x i32], align 4
  %processingFlags = alloca [50 x i1], align 1
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %temp = alloca i32, align 4
  store i32 0, ptr %i, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %0 = load i32, ptr %i, align 4
  %1 = load i32, ptr %size3, align 4
  %2 = icmp slt i32 %0, %1
  br i1 %2, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %3 = load i32, ptr %i, align 4
  %4 = load ptr, ptr %inputArr1, align 8
  %5 = getelementptr i32, ptr %4, i32 %3
  %6 = load i32, ptr %5, align 4
  %7 = mul i32 %6, 2
  %8 = load i32, ptr %i, align 4
  %9 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %8
  store i32 %7, ptr %9, align 4
  %10 = load i32, ptr %i, align 4
  %11 = load ptr, ptr %flagArr2, align 8
  %12 = getelementptr i1, ptr %11, i32 %10
  %13 = load i1, ptr %12, align 1
  %14 = xor i1 %13, true
  %15 = load i32, ptr %i, align 4
  %16 = getelementptr [50 x i1], ptr %processingFlags, i32 0, i32 %15
  store i1 %14, ptr %16, align 1
  %17 = load i32, ptr %i, align 4
  %18 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %17
  %19 = load i32, ptr %18, align 4
  call void @writeInt(i32 %19)
  call void @newLine()
  %20 = load i32, ptr %i, align 4
  %21 = add i32 %20, 1
  store i32 %21, ptr %i, align 4
  br label %while.cond

while.exit:                                       ; preds = %while.cond
  store i32 0, ptr %i, align 4
  br label %while.cond4

while.cond4:                                      ; preds = %while.exit9, %while.exit
  %22 = load i32, ptr %i, align 4
  %23 = load i32, ptr %size3, align 4
  %24 = icmp slt i32 %22, %23
  br i1 %24, label %while.body5, label %while.exit6

while.body5:                                      ; preds = %while.cond4
  store i32 0, ptr %j, align 4
  br label %while.cond7

while.exit6:                                      ; preds = %while.cond4
  %25 = load i32, ptr %size3, align 4
  %26 = sub i32 %25, 1
  store i32 %26, ptr %i, align 4
  br label %while.cond21

while.cond7:                                      ; preds = %merge, %while.body5
  %27 = load i32, ptr %j, align 4
  %28 = load i32, ptr %size3, align 4
  %29 = load i32, ptr %i, align 4
  %30 = sub i32 %28, %29
  %31 = icmp slt i32 %27, %30
  br i1 %31, label %while.body8, label %while.exit9

while.body8:                                      ; preds = %while.cond7
  %32 = load i32, ptr %j, align 4
  %33 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %32
  %34 = load i32, ptr %33, align 4
  %35 = load i32, ptr %j, align 4
  %36 = add i32 %35, 1
  %37 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %36
  %38 = load i32, ptr %37, align 4
  %39 = icmp sgt i32 %34, %38
  br i1 %39, label %then, label %else

while.exit9:                                      ; preds = %while.cond7
  %40 = load i32, ptr %i, align 4
  %41 = add i32 %40, 1
  store i32 %41, ptr %i, align 4
  br label %while.cond4

then:                                             ; preds = %while.body8
  %42 = load i32, ptr %j, align 4
  %43 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %42
  %44 = load i32, ptr %43, align 4
  store i32 %44, ptr %temp, align 4
  %45 = load i32, ptr %j, align 4
  %46 = add i32 %45, 1
  %47 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %46
  %48 = load i32, ptr %47, align 4
  %49 = load i32, ptr %j, align 4
  %50 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %49
  store i32 %48, ptr %50, align 4
  %51 = load i32, ptr %temp, align 4
  %52 = load i32, ptr %j, align 4
  %53 = add i32 %52, 1
  %54 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %53
  store i32 %51, ptr %54, align 4
  %55 = load i32, ptr %j, align 4
  %56 = getelementptr [50 x i1], ptr %processingFlags, i32 0, i32 %55
  %57 = load i1, ptr %56, align 1
  %58 = xor i1 %57, true
  %59 = load i32, ptr %j, align 4
  %60 = getelementptr [50 x i1], ptr %processingFlags, i32 0, i32 %59
  store i1 %58, ptr %60, align 1
  %61 = load i32, ptr %j, align 4
  %62 = getelementptr [50 x i1], ptr %processingFlags, i32 0, i32 %61
  %63 = load i1, ptr %62, align 1
  call void @writeBool(i1 %63)
  br label %merge

merge:                                            ; preds = %merge11, %then
  %64 = load i32, ptr %j, align 4
  %65 = add i32 %64, 1
  store i32 %65, ptr %j, align 4
  br label %while.cond7

else:                                             ; preds = %while.body8
  %66 = load i32, ptr %j, align 4
  %67 = getelementptr [50 x i1], ptr %processingFlags, i32 0, i32 %66
  %68 = load i1, ptr %67, align 1
  br i1 %68, label %then10, label %else12

then10:                                           ; preds = %else
  %69 = load i32, ptr %j, align 4
  %70 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %69
  %71 = load i32, ptr %70, align 4
  %72 = load i32, ptr %i, align 4
  %73 = load ptr, ptr %inputArr1, align 8
  %74 = getelementptr i32, ptr %73, i32 %72
  %75 = load i32, ptr %74, align 4
  %76 = add i32 %71, %75
  %77 = load i32, ptr %j, align 4
  %78 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %77
  store i32 %76, ptr %78, align 4
  %79 = load i32, ptr %j, align 4
  %80 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %79
  %81 = load i32, ptr %80, align 4
  call void @writeInt(i32 %81)
  br label %merge11

merge11:                                          ; preds = %while.exit15, %then10
  br label %merge

else12:                                           ; preds = %else
  br label %while.cond13

while.cond13:                                     ; preds = %merge17, %else12
  %82 = load i32, ptr %j, align 4
  %83 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %82
  %84 = load i32, ptr %83, align 4
  %85 = icmp sgt i32 %84, 0
  br i1 %85, label %while.body14, label %while.exit15

while.body14:                                     ; preds = %while.cond13
  %86 = load i32, ptr %j, align 4
  %87 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %86
  %88 = load i32, ptr %87, align 4
  %89 = sub i32 %88, 1
  %90 = load i32, ptr %j, align 4
  %91 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %90
  store i32 %89, ptr %91, align 4
  %92 = load i32, ptr %j, align 4
  %93 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %92
  %94 = load i32, ptr %93, align 4
  %95 = add i32 %94, 2
  %96 = icmp eq i32 %95, 0
  br i1 %96, label %then16, label %else18

while.exit15:                                     ; preds = %while.cond13
  br label %merge11

then16:                                           ; preds = %while.body14
  call void @writeBool(i1 true)
  br label %merge17

merge17:                                          ; preds = %merge20, %then16
  br label %while.cond13

else18:                                           ; preds = %while.body14
  %97 = load i32, ptr %j, align 4
  %98 = getelementptr [50 x i1], ptr %processingFlags, i32 0, i32 %97
  %99 = load i1, ptr %98, align 1
  br i1 %99, label %then19, label %merge20

then19:                                           ; preds = %else18
  %100 = load i32, ptr %j, align 4
  %101 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %100
  %102 = load i32, ptr %101, align 4
  call void @writeInt(i32 %102)
  br label %merge20

merge20:                                          ; preds = %then19, %else18
  br label %merge17

while.cond21:                                     ; preds = %merge25, %while.exit6
  %103 = load i32, ptr %i, align 4
  %104 = icmp sge i32 %103, 0
  br i1 %104, label %while.body22, label %while.exit23

while.body22:                                     ; preds = %while.cond21
  %105 = load i32, ptr %i, align 4
  %106 = getelementptr [50 x i1], ptr %processingFlags, i32 0, i32 %105
  %107 = load i1, ptr %106, align 1
  br i1 %107, label %then24, label %else26

while.exit23:                                     ; preds = %while.cond21
  ret void

then24:                                           ; preds = %while.body22
  br label %while.cond27

merge25:                                          ; preds = %merge31, %while.exit29
  %108 = load i32, ptr %i, align 4
  %109 = sub i32 %108, 1
  store i32 %109, ptr %i, align 4
  br label %while.cond21

else26:                                           ; preds = %while.body22
  %110 = load i32, ptr %i, align 4
  %111 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %110
  %112 = load i32, ptr %111, align 4
  %113 = load i32, ptr %i, align 4
  %114 = load ptr, ptr %inputArr1, align 8
  %115 = getelementptr i32, ptr %114, i32 %113
  %116 = load i32, ptr %115, align 4
  %117 = icmp slt i32 %112, %116
  br i1 %117, label %then30, label %merge31

while.cond27:                                     ; preds = %while.body28, %then24
  %118 = load i32, ptr %i, align 4
  %119 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %118
  %120 = load i32, ptr %119, align 4
  %121 = load i32, ptr %i, align 4
  %122 = load ptr, ptr %inputArr1, align 8
  %123 = getelementptr i32, ptr %122, i32 %121
  %124 = load i32, ptr %123, align 4
  %125 = icmp sgt i32 %120, %124
  br i1 %125, label %while.body28, label %while.exit29

while.body28:                                     ; preds = %while.cond27
  %126 = load i32, ptr %i, align 4
  %127 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %126
  %128 = load i32, ptr %127, align 4
  %129 = sub i32 %128, 1
  %130 = load i32, ptr %i, align 4
  %131 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %130
  store i32 %129, ptr %131, align 4
  %132 = load i32, ptr %i, align 4
  %133 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %132
  %134 = load i32, ptr %133, align 4
  call void @writeInt(i32 %134)
  call void @newLine()
  br label %while.cond27

while.exit29:                                     ; preds = %while.cond27
  br label %merge25

then30:                                           ; preds = %else26
  br label %while.cond32

merge31:                                          ; preds = %while.exit34, %else26
  br label %merge25

while.cond32:                                     ; preds = %while.body33, %then30
  %135 = load i32, ptr %i, align 4
  %136 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %135
  %137 = load i32, ptr %136, align 4
  %138 = load i32, ptr %i, align 4
  %139 = load ptr, ptr %inputArr1, align 8
  %140 = getelementptr i32, ptr %139, i32 %138
  %141 = load i32, ptr %140, align 4
  %142 = icmp slt i32 %137, %141
  br i1 %142, label %while.body33, label %while.exit34

while.body33:                                     ; preds = %while.cond32
  %143 = load i32, ptr %i, align 4
  %144 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %143
  %145 = load i32, ptr %144, align 4
  %146 = add i32 %145, 1
  %147 = load i32, ptr %i, align 4
  %148 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %147
  store i32 %146, ptr %148, align 4
  %149 = load i32, ptr %i, align 4
  %150 = getelementptr [100 x i32], ptr %tempArr, i32 0, i32 %149
  %151 = load i32, ptr %150, align 4
  %152 = load i32, ptr %i, align 4
  %153 = load ptr, ptr %inputArr1, align 8
  %154 = getelementptr i32, ptr %153, i32 %152
  %155 = load i32, ptr %154, align 4
  %156 = icmp eq i32 %151, %155
  call void @writeBool(i1 %156)
  call void @newLine()
  br label %while.cond32

while.exit34:                                     ; preds = %while.cond32
  br label %merge31
}

define i32 @main() {
entry:
  %localArr = alloca [50 x i32], align 4
  %boolArr = alloca [20 x i1], align 1
  %i = alloca i32, align 4
  %sum = alloca i32, align 4
  %flag = alloca i1, align 1
  %helper = alloca i32, align 4
  call void @writeInt(i32 -42)
  call void @newLine()
  store i32 0, ptr %i, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %0 = load i32, ptr %i, align 4
  %1 = icmp slt i32 %0, 10
  br i1 %1, label %while.body, label %while.exit

while.body:                                       ; preds = %while.cond
  %2 = call i32 @readInt()
  %3 = load i32, ptr %i, align 4
  %4 = getelementptr [50 x i32], ptr %localArr, i32 0, i32 %3
  store i32 %2, ptr %4, align 4
  %5 = call i1 @readBool()
  %6 = load i32, ptr %i, align 4
  %7 = getelementptr [20 x i1], ptr %boolArr, i32 0, i32 %6
  store i1 %5, ptr %7, align 1
  %8 = load i32, ptr %i, align 4
  %9 = add i32 %8, 1
  store i32 %9, ptr %i, align 4
  br label %while.cond

while.exit:                                       ; preds = %while.cond
  store i32 0, ptr %i, align 4
  store i32 0, ptr %sum, align 4
  br label %while.cond1

while.cond1:                                      ; preds = %merge, %while.exit
  %10 = load i32, ptr %i, align 4
  %11 = icmp slt i32 %10, 10
  br i1 %11, label %while.body2, label %while.exit3

while.body2:                                      ; preds = %while.cond1
  %12 = load i32, ptr %i, align 4
  %13 = getelementptr [20 x i1], ptr %boolArr, i32 0, i32 %12
  %14 = load i1, ptr %13, align 1
  br i1 %14, label %then, label %merge

while.exit3:                                      ; preds = %while.cond1
  %15 = getelementptr [50 x i32], ptr %localArr, i32 0, i32 0
  %16 = call i32 @recursiveArraySum(ptr %15, i32 9)
  call void @writeInt(i32 %16)
  call void @newLine()
  store i32 0, ptr %i, align 4
  br label %while.cond13

then:                                             ; preds = %while.body2
  br label %while.cond4

merge:                                            ; preds = %while.exit6, %while.body2
  %17 = load i32, ptr %i, align 4
  %18 = add i32 %17, 1
  store i32 %18, ptr %i, align 4
  br label %while.cond1

while.cond4:                                      ; preds = %merge8, %then
  %19 = load i32, ptr %i, align 4
  %20 = getelementptr [50 x i32], ptr %localArr, i32 0, i32 %19
  %21 = load i32, ptr %20, align 4
  %22 = icmp sgt i32 %21, 0
  br i1 %22, label %while.body5, label %while.exit6

while.body5:                                      ; preds = %while.cond4
  %23 = load i32, ptr %i, align 4
  %24 = getelementptr [50 x i32], ptr %localArr, i32 0, i32 %23
  %25 = load i32, ptr %24, align 4
  %26 = sdiv i32 %25, 2
  %27 = icmp eq i32 %26, 0
  br i1 %27, label %then7, label %else

while.exit6:                                      ; preds = %while.cond4
  br label %merge

then7:                                            ; preds = %while.body5
  %28 = load i32, ptr %sum, align 4
  %29 = load i32, ptr %i, align 4
  %30 = getelementptr [50 x i32], ptr %localArr, i32 0, i32 %29
  %31 = load i32, ptr %30, align 4
  %32 = add i32 %28, %31
  store i32 %32, ptr %sum, align 4
  %33 = load i32, ptr %sum, align 4
  %34 = icmp sgt i32 %33, 100
  br i1 %34, label %then9, label %merge10

merge8:                                           ; preds = %merge12, %merge10
  %35 = load i32, ptr %i, align 4
  %36 = getelementptr [50 x i32], ptr %localArr, i32 0, i32 %35
  %37 = load i32, ptr %36, align 4
  %38 = sub i32 %37, 1
  %39 = load i32, ptr %i, align 4
  %40 = getelementptr [50 x i32], ptr %localArr, i32 0, i32 %39
  store i32 %38, ptr %40, align 4
  br label %while.cond4

else:                                             ; preds = %while.body5
  %41 = load i32, ptr %i, align 4
  %42 = getelementptr [20 x i1], ptr %boolArr, i32 0, i32 %41
  %43 = load i1, ptr %42, align 1
  %44 = load i32, ptr %i, align 4
  %45 = sub i32 %44, 1
  %46 = getelementptr [20 x i1], ptr %boolArr, i32 0, i32 %45
  %47 = load i1, ptr %46, align 1
  %48 = load i32, ptr %i, align 4
  %49 = getelementptr [50 x i32], ptr %localArr, i32 0, i32 %48
  %50 = load i32, ptr %49, align 4
  %51 = load i32, ptr %i, align 4
  %52 = sub i32 %51, 1
  %53 = getelementptr [50 x i32], ptr %localArr, i32 0, i32 %52
  %54 = load i32, ptr %53, align 4
  %55 = call i1 @complexBooleanLogic(i1 %43, i1 %47, i32 %50, i32 %54)
  br i1 %55, label %then11, label %merge12

then9:                                            ; preds = %then7
  call void @writeBool(i1 true)
  call void @newLine()
  br label %merge10

merge10:                                          ; preds = %then9, %then7
  br label %merge8

then11:                                           ; preds = %else
  %56 = load i32, ptr %sum, align 4
  %57 = mul i32 %56, 2
  store i32 %57, ptr %sum, align 4
  br label %merge12

merge12:                                          ; preds = %then11, %else
  br label %merge8

while.cond13:                                     ; preds = %merge17, %while.exit3
  %58 = load i32, ptr %i, align 4
  %59 = icmp slt i32 %58, 10
  br i1 %59, label %while.body14, label %while.exit15

while.body14:                                     ; preds = %while.cond13
  %60 = getelementptr [50 x i32], ptr %localArr, i32 0, i32 0
  %61 = getelementptr [20 x i1], ptr %boolArr, i32 0, i32 0
  %62 = call i32 @arrayHelper(ptr %60, ptr %61)
  store i32 %62, ptr %helper, align 4
  %63 = load i32, ptr %i, align 4
  %64 = getelementptr [50 x i32], ptr %localArr, i32 0, i32 %63
  %65 = load i32, ptr %64, align 4
  %66 = load i32, ptr %helper, align 4
  %67 = add i32 %65, %66
  %68 = load i32, ptr %i, align 4
  %69 = getelementptr [100 x i32], ptr @globalArr, i32 0, i32 %68
  store i32 %67, ptr %69, align 4
  %70 = load i32, ptr %i, align 4
  %71 = getelementptr [100 x i32], ptr @globalArr, i32 0, i32 %70
  %72 = load i32, ptr %71, align 4
  %73 = icmp sgt i32 %72, 50
  br i1 %73, label %then16, label %else18

while.exit15:                                     ; preds = %while.cond13
  %74 = load i1, ptr @globalBoolArr, align 1
  %75 = xor i1 %74, true
  %76 = load i1, ptr getelementptr inbounds ([50 x i1], ptr @globalBoolArr, i32 0, i32 1), align 1
  %77 = and i1 %75, %76
  %78 = load i32, ptr @globalArr, align 4
  %79 = load i32, ptr getelementptr inbounds ([100 x i32], ptr @globalArr, i32 0, i32 1), align 4
  %80 = icmp sle i32 %78, %79
  %81 = or i1 %77, %80
  store i1 %81, ptr %flag, align 1
  %82 = load i1, ptr %flag, align 1
  call void @writeBool(i1 %82)
  call void @newLine()
  %83 = load i32, ptr %sum, align 4
  ret i32 %83

then16:                                           ; preds = %while.body14
  %84 = load i32, ptr %i, align 4
  %85 = getelementptr [20 x i1], ptr %boolArr, i32 0, i32 %84
  %86 = load i1, ptr %85, align 1
  %87 = xor i1 %86, true
  %88 = load i32, ptr %i, align 4
  %89 = getelementptr [50 x i1], ptr @globalBoolArr, i32 0, i32 %88
  store i1 %87, ptr %89, align 1
  br label %merge17

merge17:                                          ; preds = %merge20, %then16
  %90 = load i32, ptr %i, align 4
  %91 = add i32 %90, 1
  store i32 %91, ptr %i, align 4
  br label %while.cond13

else18:                                           ; preds = %while.body14
  %92 = load i32, ptr %i, align 4
  %93 = getelementptr [100 x i32], ptr @globalArr, i32 0, i32 %92
  %94 = load i32, ptr %93, align 4
  %95 = icmp slt i32 %94, 0
  br i1 %95, label %then19, label %else21

then19:                                           ; preds = %else18
  %96 = load i32, ptr %i, align 4
  %97 = getelementptr [20 x i1], ptr %boolArr, i32 0, i32 %96
  %98 = load i1, ptr %97, align 1
  %99 = and i1 %98, true
  %100 = load i32, ptr %i, align 4
  %101 = getelementptr [50 x i1], ptr @globalBoolArr, i32 0, i32 %100
  store i1 %99, ptr %101, align 1
  br label %merge20

merge20:                                          ; preds = %else21, %then19
  br label %merge17

else21:                                           ; preds = %else18
  %102 = load i32, ptr %i, align 4
  %103 = getelementptr [50 x i1], ptr @globalBoolArr, i32 0, i32 %102
  store i1 false, ptr %103, align 1
  br label %merge20
}

declare void @newLine()

declare i1 @readBool()

declare i32 @readInt()

define i32 @recursiveArraySum(ptr %arr, i32 %index) {
entry:
  %arr1 = alloca ptr, align 8
  store ptr %arr, ptr %arr1, align 8
  %index2 = alloca i32, align 4
  store i32 %index, ptr %index2, align 4
  %sum = alloca i32, align 4
  %0 = load ptr, ptr %arr1, align 8
  %1 = load i32, ptr %index2, align 4
  %2 = sub i32 %1, 1
  %3 = call i32 @recursiveArraySum(ptr %0, i32 %2)
  store i32 %3, ptr %sum, align 4
  %4 = load i32, ptr %index2, align 4
  %5 = icmp slt i32 %4, 0
  br i1 %5, label %then, label %merge

then:                                             ; preds = %entry
  ret i32 0

merge:                                            ; preds = %entry
  %6 = load i32, ptr %index2, align 4
  %7 = load ptr, ptr %arr1, align 8
  %8 = getelementptr i32, ptr %7, i32 %6
  %9 = load i32, ptr %8, align 4
  %10 = load i32, ptr %sum, align 4
  %11 = add i32 %9, %10
  ret i32 %11
}

declare void @writeBool(i1 zeroext)

declare void @writeInt(i32)
