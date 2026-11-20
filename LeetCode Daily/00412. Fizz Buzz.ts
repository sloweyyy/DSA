function fizzBuzz(n: number): string[] {
    const result: string[] = [];
    for (let value = 1; value <= n; value++) {
        let text = "";
        if (value % 3 === 0) text += "Fizz";
        if (value % 5 === 0) text += "Buzz";
        result.push(text || String(value));
    }
    return result;
}
