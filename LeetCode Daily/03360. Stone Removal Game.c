bool canAliceWin(int n) {
    int stones = 10;
    bool aliceWins = false;
    while (n >= stones) {
        n -= stones;
        --stones;
        aliceWins = !aliceWins;
    }
    return aliceWins;
}
