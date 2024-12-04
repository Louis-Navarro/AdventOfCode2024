import re


def main():
    with open("data.txt") as f:
        data = f.read()

    pattern = re.compile(r"mul\((\d{1,3}),(\d{1,3})\)")
    # Find list of group 1 and 2
    matches = pattern.findall(data)
    total = 0
    for mul in matches:
        total += int(mul[0]) * int(mul[1])
    print(total)


if __name__ == "__main__":
    main()
