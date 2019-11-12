def solve(N, X, A):
    ans = best1 = best2 = best3 = 0
    for a in A:
        best3 = max(0, a, best1 + a, best2 + a, best3 + a)
        best2 = max(0, X*a, best1 + X*a, best2 + X*a)
        best1 = max(0, a, best1 + a)
        ans = max(ans, best1, best2, best3)
    return ans

rrm = lambda: map(int, raw_input().split())
(N, X), A = rrm(), rrm()
print solve(N, X, A)