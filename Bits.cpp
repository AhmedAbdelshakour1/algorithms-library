// __builtin_clz // Returns the number of leading 0-bits in x. eg 8 = 00000000000000000000000000001000 --> 28
// __builtin_ctz // Returns the number of trailing 0-bits in x. eg 8 = 1000 --> 3
// __builtin_popcount // Returns the number of 1-bits in x.  

//for long long
// __builtin_clzll
// __builtin_ctzll 
// __builtin_popcountll 
//.....................................................................................//
void printNumber(int n, int len) {
    if (!len)
        return;

    printNumber(n >> 1, len - 1);    // remove last bit
    cout << (n & 1);                        // print last bit
}
//.....................................................................................//
bool isOne(int n, int indx) { return (n & (1 << indx) ) != 0; } // check if index bit is 1 - (0-indexed)

int flipRightMostToOne(int n) { return n | (n + 1); } // flip right-most 0 to 1 , Eg 10011 to 10111

int turnOnLastConsecutiveZeroes(int n) { return n | (n - 1); } // turn on right-most consecutive zeroes to 1 if there is any .  Eg 10100 to 10111, 111 to 111

int turnOffLastConsecutiveBits(int S) { return S & (S + 1); } // turn off right-most consecutive ones to 0 if there is any , Eg 1011 to 1000

int turnOffLastBit(int n) { return n & (n - 1); } // turn off right-most 1 to 0 , Eg 111 to 110

int zerosToFirstOne(int n) { return n & (-n); } // return zeros till first one. Eg n = 1010 to 10

int modN(int S, int N) { return S & (N - 1); } //return S%N where N is a power of 2

bool isPowerOfTwo(int n) { return (n & (n - 1)) == 0; }  // checks if n is power of 2 , n > 0

int getBit(int num, int idx) { return ((num >> idx) & 1) == 1; }//get bit in idx from right 110100 idx = 2 >> 1

int setBit1(int num, int idx) { return num | (1 << idx); } //set bit 1 in idx from right
 
int setBit0(int num, int idx) { return num & ~(1 << idx); } //set bit 0 in idx from right

int flipBit(int num, int idx) {return num ^ (1 << idx); } 
//.....................................................................................//
// Let's first assume, mask was complete and we work on it reverse
void PrintAllSubsetsAllOnes(int len) {
    int mask = (1 << len) - 1;
    for (int i = mask; i >= 0; i = i - 1) {
        printNumber(i, len);
        cout << endl;
    }
}

// Print all submasks of a given mask
void getAllSubMasks(int mask) {
    for (int subMask = mask; subMask; subMask = (subMask - 1) & mask) {
        printNumber(subMask, 32);    // this code doesn't print 0
        cout << endl;
    }
    // For reverse: ~subMask&mask = subMask^mask
}
//.....................................................................................//
void STL() {
    const int N = 20;        // const
    string s = "000111";
    bitset<N> x(s);            // 00000000000000000111
    x.set();                // 11111111111111111111
    x.flip();                // 00000000000000000000

    x = 10;                    // 00000000000000001010
    x |= 3;                    // 00000000000000001011
    x = (x << 3);                // 00000000000001011000
    x = ~x;                    // 11111111111110100111

    x.set(15, 0);            // 11110111111110100111
    x.set(15);                // 11111111111110100111
    x.flip(0);                // 11111111111110100110
    x.count();                // Returns the number of 1 bits that are set. //16
    x.any();                // Returns true if any 1 bits are set.
    x.none();                // Returns true if no bits are set.
    x.test(15);
    x.to_ulong();            // Returns an unsigned long represent mask
    // The most interesting
    if (x[2] == 0) {
        x[0] = 1;    // Set bit from most right to 1
        x[N - 1] = 0;    // Set bit from most left to 0
    }
    cout << x << endl;            // display a string of N bits
}
