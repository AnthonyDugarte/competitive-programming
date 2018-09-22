int turnBitOff(int n, int b) // start counting b at 0
{
    return n & ~(1 << b);
}

int turnBitOn(int n, int b) // start counting b at 0
{
    return n | (1 << b);
}
