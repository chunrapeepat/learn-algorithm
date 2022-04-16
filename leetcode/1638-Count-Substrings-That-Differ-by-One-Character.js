/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var countSubstrings = function(s, t) {
    let dp = {};
    let count = 0;
    const len = Math.min(s.length, t.length);
    for (let l = 1; l <= len; ++l) {
        for (let i = 0; i < s.length - l + 1; ++i) {
            for (let j = 0; j < t.length - l + 1; ++j) {
                dp[`${i},${j},${l}`] = (l-1 === 0 ? 0 : dp[`${i},${j},${l-1}`]) + (s[i+l-1] !== t[j+l-1] ? 1 : 0);
                if (dp[`${i},${j},${l}`] === 1) ++count;
            }   
        }
    }
    return count;
};
