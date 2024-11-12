void main() {
    bool a;
    bool b;
    bool c;
    bool result;
    
    a = true;
    b = false;
    c = true;
    
    result = (a && b) || (c && !b);
    result = !(a || b) && c;
} 