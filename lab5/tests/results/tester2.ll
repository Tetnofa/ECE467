; ModuleID = 'tests/2.c'
source_filename = "tests/2.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @quicksort(i32 noundef %start, i32 noundef %end, ptr noundef %arr) #0 {
entry:
  %start.addr = alloca i32, align 4
  %end.addr = alloca i32, align 4
  %arr.addr = alloca ptr, align 8
  %pivot = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %temp = alloca i32, align 4
  store i32 %start, ptr %start.addr, align 4
  store i32 %end, ptr %end.addr, align 4
  store ptr %arr, ptr %arr.addr, align 8
  %0 = load i32, ptr %start.addr, align 4
  %1 = load i32, ptr %end.addr, align 4
  %cmp = icmp slt i32 %0, %1
  br i1 %cmp, label %if.then, label %if.end37

if.then:                                          ; preds = %entry
  %2 = load i32, ptr %start.addr, align 4
  store i32 %2, ptr %pivot, align 4
  %3 = load i32, ptr %start.addr, align 4
  store i32 %3, ptr %i, align 4
  %4 = load i32, ptr %end.addr, align 4
  store i32 %4, ptr %j, align 4
  br label %while.cond

while.cond:                                       ; preds = %if.end, %if.then
  %5 = load i32, ptr %i, align 4
  %6 = load i32, ptr %j, align 4
  %cmp1 = icmp slt i32 %5, %6
  br i1 %cmp1, label %while.body, label %while.end26

while.body:                                       ; preds = %while.cond
  br label %while.cond2

while.cond2:                                      ; preds = %while.body7, %while.body
  %7 = load ptr, ptr %arr.addr, align 8
  %8 = load i32, ptr %i, align 4
  %idxprom = sext i32 %8 to i64
  %arrayidx = getelementptr inbounds i32, ptr %7, i64 %idxprom
  %9 = load i32, ptr %arrayidx, align 4
  %10 = load ptr, ptr %arr.addr, align 8
  %11 = load i32, ptr %pivot, align 4
  %idxprom3 = sext i32 %11 to i64
  %arrayidx4 = getelementptr inbounds i32, ptr %10, i64 %idxprom3
  %12 = load i32, ptr %arrayidx4, align 4
  %cmp5 = icmp sle i32 %9, %12
  br i1 %cmp5, label %land.rhs, label %land.end

land.rhs:                                         ; preds = %while.cond2
  %13 = load i32, ptr %i, align 4
  %14 = load i32, ptr %end.addr, align 4
  %cmp6 = icmp slt i32 %13, %14
  br label %land.end

land.end:                                         ; preds = %land.rhs, %while.cond2
  %15 = phi i1 [ false, %while.cond2 ], [ %cmp6, %land.rhs ]
  br i1 %15, label %while.body7, label %while.end

while.body7:                                      ; preds = %land.end
  %16 = load i32, ptr %i, align 4
  %add = add nsw i32 %16, 1
  store i32 %add, ptr %i, align 4
  br label %while.cond2, !llvm.loop !6

while.end:                                        ; preds = %land.end
  br label %while.cond8

while.cond8:                                      ; preds = %while.body14, %while.end
  %17 = load ptr, ptr %arr.addr, align 8
  %18 = load i32, ptr %j, align 4
  %idxprom9 = sext i32 %18 to i64
  %arrayidx10 = getelementptr inbounds i32, ptr %17, i64 %idxprom9
  %19 = load i32, ptr %arrayidx10, align 4
  %20 = load ptr, ptr %arr.addr, align 8
  %21 = load i32, ptr %pivot, align 4
  %idxprom11 = sext i32 %21 to i64
  %arrayidx12 = getelementptr inbounds i32, ptr %20, i64 %idxprom11
  %22 = load i32, ptr %arrayidx12, align 4
  %cmp13 = icmp sgt i32 %19, %22
  br i1 %cmp13, label %while.body14, label %while.end15

while.body14:                                     ; preds = %while.cond8
  %23 = load i32, ptr %j, align 4
  %sub = sub nsw i32 %23, 1
  store i32 %sub, ptr %j, align 4
  br label %while.cond8, !llvm.loop !8

while.end15:                                      ; preds = %while.cond8
  %24 = load i32, ptr %i, align 4
  %25 = load i32, ptr %j, align 4
  %cmp16 = icmp slt i32 %24, %25
  br i1 %cmp16, label %if.then17, label %if.end

if.then17:                                        ; preds = %while.end15
  %26 = load ptr, ptr %arr.addr, align 8
  %27 = load i32, ptr %i, align 4
  %idxprom18 = sext i32 %27 to i64
  %arrayidx19 = getelementptr inbounds i32, ptr %26, i64 %idxprom18
  %28 = load i32, ptr %arrayidx19, align 4
  store i32 %28, ptr %temp, align 4
  %29 = load ptr, ptr %arr.addr, align 8
  %30 = load i32, ptr %j, align 4
  %idxprom20 = sext i32 %30 to i64
  %arrayidx21 = getelementptr inbounds i32, ptr %29, i64 %idxprom20
  %31 = load i32, ptr %arrayidx21, align 4
  %32 = load ptr, ptr %arr.addr, align 8
  %33 = load i32, ptr %i, align 4
  %idxprom22 = sext i32 %33 to i64
  %arrayidx23 = getelementptr inbounds i32, ptr %32, i64 %idxprom22
  store i32 %31, ptr %arrayidx23, align 4
  %34 = load i32, ptr %temp, align 4
  %35 = load ptr, ptr %arr.addr, align 8
  %36 = load i32, ptr %j, align 4
  %idxprom24 = sext i32 %36 to i64
  %arrayidx25 = getelementptr inbounds i32, ptr %35, i64 %idxprom24
  store i32 %34, ptr %arrayidx25, align 4
  br label %if.end

if.end:                                           ; preds = %if.then17, %while.end15
  br label %while.cond, !llvm.loop !9

while.end26:                                      ; preds = %while.cond
  %37 = load ptr, ptr %arr.addr, align 8
  %38 = load i32, ptr %pivot, align 4
  %idxprom27 = sext i32 %38 to i64
  %arrayidx28 = getelementptr inbounds i32, ptr %37, i64 %idxprom27
  %39 = load i32, ptr %arrayidx28, align 4
  store i32 %39, ptr %temp, align 4
  %40 = load ptr, ptr %arr.addr, align 8
  %41 = load i32, ptr %j, align 4
  %idxprom29 = sext i32 %41 to i64
  %arrayidx30 = getelementptr inbounds i32, ptr %40, i64 %idxprom29
  %42 = load i32, ptr %arrayidx30, align 4
  %43 = load ptr, ptr %arr.addr, align 8
  %44 = load i32, ptr %pivot, align 4
  %idxprom31 = sext i32 %44 to i64
  %arrayidx32 = getelementptr inbounds i32, ptr %43, i64 %idxprom31
  store i32 %42, ptr %arrayidx32, align 4
  %45 = load i32, ptr %temp, align 4
  %46 = load ptr, ptr %arr.addr, align 8
  %47 = load i32, ptr %j, align 4
  %idxprom33 = sext i32 %47 to i64
  %arrayidx34 = getelementptr inbounds i32, ptr %46, i64 %idxprom33
  store i32 %45, ptr %arrayidx34, align 4
  %48 = load i32, ptr %j, align 4
  %sub35 = sub nsw i32 %48, 1
  %49 = load ptr, ptr %arr.addr, align 8
  call void @quicksort(i32 noundef 0, i32 noundef %sub35, ptr noundef %49)
  %50 = load i32, ptr %j, align 4
  %add36 = add nsw i32 %50, 1
  %51 = load i32, ptr %end.addr, align 4
  %52 = load ptr, ptr %arr.addr, align 8
  call void @quicksort(i32 noundef %add36, i32 noundef %51, ptr noundef %52)
  br label %if.end37

if.end37:                                         ; preds = %while.end26, %entry
  ret void
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 18.0.0 (https://github.com/llvm/llvm-project.git bf87638a9d2771a75f59aa40296368cdec3e7353)"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}