def solve(fs):
    left = 0
    right = len(fs) - 1

    while right >= left:
        if fs[left] == -1:
            fs[left], fs[right] = fs[right], fs[left]  # Python swap
            while fs[right] == -1:
                right -= 1
        left += 1

    total = 0
    for i in range(len(fs)):
        if fs[i] != -1:
            total += i * fs[i]
            if i * fs[i] < 0:
                print(f"Error: {i} {fs[i]}")

    return total


def main():
    data = input()
    fs = []

    for i in range(len(data)):
        d = int(data[i])
        for j in range(d):
            fs.append(i // 2 if i % 2 == 0 else -1)

    print(solve(fs))


if __name__ == "__main__":
    main()
