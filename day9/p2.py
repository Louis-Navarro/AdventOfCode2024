def solve(fs, lengths):
    right = len(fs) - 1

    while right > 0:
        left = 1
        length_left = 1

        while left < right:
            if fs[left] == -1:
                length_left = 1
                while left + length_left < len(fs) and fs[left + length_left] == -1:
                    length_left += 1
                if length_left >= lengths[fs[right]]:
                    break
            left += 1

        if left < right:
            first = fs[right]
            while fs[right] == first:
                fs[left], fs[right] = fs[right], fs[left]  # Python swap
                right -= 1
                left += 1
        else:
            right -= 1

        while fs[right] == -1:
            right -= 1

    total = 0
    for i in range(len(fs)):
        if fs[i] != -1:
            total += i * fs[i]

    return total


def main():
    data = input()
    fs = []
    lengths = []

    for i in range(len(data)):
        d = int(data[i])
        for j in range(d):
            fs.append(i // 2 if i % 2 == 0 else -1)
        if i % 2 == 0:
            lengths.append(d)

    print(solve(fs, lengths))


if __name__ == "__main__":
    main()
