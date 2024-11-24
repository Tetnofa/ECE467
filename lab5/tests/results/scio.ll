; ModuleID = 'scio.bc'
source_filename = "scio.bc"
target triple = "x86_64-unknown-linux-gnu"

declare void @newLine()

declare i1 @readBool()

declare i32 @readInt()

declare void @writeBool(i1 zeroext)

declare void @writeInt(i32)
