string letters = "0123456789ABCDEF";

int toInt(char c) { return letters.find(c); }

int FromAnyBasetoDecimal(string in, int base) {
    int res = 0;
    for (size_t i = 0; i < in.size(); ++i)
        res *= base, res += toInt(in[i]);
    return res;
}

string FromDecimaltoAnyBase(int number, int base) {
    if (number == 0)
        return "0";

    string res = "";
    for (; number; number /= base)
        res = letters[number % base] + res;
    return res;
}
