int z;
int main() {
    int x;
    bool y;
    y = x;
    z = x;
} 
int fcn () {
    bool f;
    bool g;
    g = f;
}
int fcn1 () {
    bool g;
    int x;
    g = x;
}
int fcn2 () {
    int z;
    x = z;
}
void fcn3 () {
    p = f;
}
bool abc;
bool fcn4() {
    abc = x;
}
int f() {
    x = y == z;
}
bool fcn5() {
    int poo;
    int pee;
    {
        pee = poo; 
        {
            int pee;
            bool poo;
            {
                poo = pee;
            }
        }
    }
}