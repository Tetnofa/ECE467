int globalX;
bool globalFlag;

void main() {
    int localX;
    bool localFlag;
    
    globalX = 42;
    localX = globalX;
    globalFlag = localX > 0;
    localFlag = globalFlag;
} 