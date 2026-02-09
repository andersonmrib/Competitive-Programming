import sys 

sys.set_int_max_str_digits(0)

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    print(a * b)