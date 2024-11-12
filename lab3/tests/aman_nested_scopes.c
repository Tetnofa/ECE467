void main() {
    int x;
    bool y;
    {
        int x;  // Shadowing outer x
        x = 5;
        {
            bool x;  // Shadowing both outer x's
            x = true;
            {
                int y;  // Shadowing outer y
                y = 10;
                writeInt(y);
            }
            writeBool(x);
        }
        writeInt(x);
    }
    x = 1;  // Outer most x
    writeInt(x);
} 