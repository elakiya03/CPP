from typing import List

x = []
y = [1, "a", "aa", False, 6.9]
x.append(1)
x.append(9)
x.append(7)

x.sort()
print(x)


# find max
def max_value(x: List[int]) -> int:
    max_val = x[0]
    for i in x:
        if i > max_val:
            max_val = i
    return max_val


print("Maximum:", max_value(x))
