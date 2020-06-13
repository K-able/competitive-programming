N, K = map(int, input().split())
R, S, P = map(int, input().split())
T = input()

conv_winhand = {'r':'p', 's':'r', 'p':'s'}
conv_score = {'r':R, 's':S, 'p':P}
poi = []

ans = 0
for i in range(N):
    if i < K:
        poi.append(conv_winhand[T[i]])
        ans += conv_score[conv_winhand[T[i]]]
    else:
        if conv_winhand[T[i]] == poi[i-K]:
            tmp = T[i]
            if i + K < N and tmp == conv_winhand[T[i+K]]: tmp = conv_winhand[poi[i-K]]
            poi.append(tmp)
        else:
            poi.append(conv_winhand[T[i]])
            ans += conv_score[conv_winhand[T[i]]]
print(ans)