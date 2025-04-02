function mostPoints(questions: number[][]): number {
    const n = questions.length;
    const dp = new Array(n).fill(0);

    for (let i = n - 1; i >= 0; i--) {
        const [points, brainpower] = questions[i];
        const nextQuestion = i + brainpower + 1;
        dp[i] = Math.max(dp[i + 1] || 0, (dp[nextQuestion] || 0) + points);
    }

    return dp[0];
}
