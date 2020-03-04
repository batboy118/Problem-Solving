# BOJ
# no. 11052
# 카드 구매하기
# https://www.acmicpc.net/problem/11052
# by JH (batboy118)

N = int(input())
l = [0]
l += list(map(int, input().split()))

dp = []

for i in range(N + 1) :
	dp.append(0)

i = 1
for i in range(N + 1) :
	j = 1
	for j in range(i + 1) :
		dp[i] = max(dp[i], dp[i - j] + l[j])

print(dp[N])
