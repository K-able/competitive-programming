S = input()
T = input()

ans = 0
for i in range(len(S)-len(T)+1):
    tmp = 0
    for j in range(len(T)):
        if S[i+j] != T[j]: continue
        else: tmp += 1
    ans = max(ans ,tmp)
print(len(T) - ans)
