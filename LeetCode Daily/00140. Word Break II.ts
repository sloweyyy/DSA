function wordBreak(s: string, wordDict: string[]): string[] {
    const dictionary = new Set(wordDict);
    const memo = new Map<number, string[]>();
    memo.set(s.length, [""]);
    function visit(start: number): string[] {
        if (memo.has(start)) return memo.get(start)!;
        const result: string[] = [];
        for (let end = start + 1; end <= Math.min(s.length, start + 10); end++) {
            const word = s.slice(start, end);
            if (!dictionary.has(word)) continue;
            for (const rest of visit(end)) result.push(rest === "" ? word : word + " " + rest);
        }
        memo.set(start, result);
        return result;
    }
    return visit(0);
}
