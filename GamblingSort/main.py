import secrets
import random


def gambling_sort(arr):
    n = len(arr)

    def sort_check(arr):
        if n < 2:
            return True
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:
                return False
        print(arr)
        return True
    while not sort_check(arr):
        for j in range(n):
            first_num = secrets.choice(arr)
            second_num = secrets.choice(arr)
            if arr.index(first_num) == arr.index(second_num):
                continue
            i, j = arr.index(first_num), arr.index(second_num)
            arr[i], arr[j] = arr[j], arr[i]
            print(arr)
    return arr


if __name__ == "__main__":
    size = int(input("Size of the array: "))
    min_value = int(input("Minimum value of the array: "))
    max_value = int(input("Maximum value of the array: "))
    arr = []
    for k in range(size):
        arr.append(random.randint(min_value, max_value))
    gambling_sort(arr)
