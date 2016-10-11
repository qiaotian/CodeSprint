import sys
import os
import numpy as np

def remove_n_duplicates(n, int_array):
    a = 1

int_array = [3,1,3,2,1]

temp = np.array(int_array)
temp.sort()

print(temp)


def partiton(li, a, b):
    x = li[b]
    i = a
    for j in range(a,b):
        if li[j] < x:
            li[i], li[j] = li[j], li[i]
            i += 1
    li[i], li[b] = li[b], li[i]
    return i

def quickSort(li, a, b):
    if a >= b:
        return
    i = partiton(li, a, b)
    quickSort(li, a, i - 1)
    quickSort(li, i + 1, b)

li = [5, 4, 6, 3, 2, 1]
quickSort(li, 0, len(li) - 1)
print li
