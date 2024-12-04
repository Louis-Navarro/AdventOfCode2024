import re


def main():
    with open("data.txt") as f:
        data = f.read()

    pattern = re.compile(r"(don)'t\(\)|(do)\(\)|mul\((\d{1,3}),(\d{1,3})\)")
    matches = pattern.findall(data)

    flag = True
    total = 0
    for mul in matches:
        if (mul[0] != ""):
            flag = False
        elif (mul[1] != ""):
            flag = True
        elif (flag):
            total += int(mul[2]) * int(mul[3])
        print(mul)

    print(total)


if __name__ == "__main__":
    main()
