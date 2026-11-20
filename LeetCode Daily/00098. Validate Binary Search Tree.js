var isInterleave = function(s1, s2, s3) {
    if (s1.length+s2.length !== s3.length) return false;
    const dp = Array(s2.length+1).fill(false);
    dp[0]=true;
    for(let i=0; i<=s1.length; i++) {
        for(let j=0; j<=s2.length; j++) {
            if(i===0 && j===0) continue;
            dp[j]=(i>0 && dp[j] && s1[i-1]===s3[i+j-1]) || (j>0 && dp[j-1] && s2[j-1]===s3[i+j-1]);
        }
    }
    return dp[s2.length];
};
