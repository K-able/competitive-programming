def main():
    n = int(input())
    a_list = list(map(int, input().split()))
    a_list = [a for a in a_list if a % 2 == 0]
    ans = 'APPROVED'
    for a in a_list:
        if a % 3 != 0 and a % 5 != 0:
            ans = 'DENIED'
            break
    print(ans)

if __name__ == "__main__":
    main()    