function ladderLength(beginWord: string, endWord: string, wordList: string[]): number {
    const remaining = new Set(wordList);
    if (!remaining.has(endWord)) return 0;
    let front = new Set([beginWord]);
    let back = new Set([endWord]);
    remaining.delete(beginWord);
    remaining.delete(endWord);
    let length = 1;
    while (front.size && back.size) {
        if (front.size > back.size) [front, back] = [back, front];
        const next = new Set<string>();
        for (const word of front) {
            for (let i = 0; i < word.length; i++) {
                for (let code = 97; code <= 122; code++) {
                    const candidate = word.slice(0, i) + String.fromCharCode(code) + word.slice(i + 1);
                    if (back.has(candidate)) return length + 1;
                    if (remaining.delete(candidate)) next.add(candidate);
                }
            }
        }
        front = next;
        length++;
    }
    return 0;
}
