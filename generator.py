import sys
import random
import os

if len(sys.argv) < 3:
    exit(print(f'usage: {sys.argv[0]} <type> <cases>'))

t = sys.argv[1]
n = sys.argv[2]
d = False
i = 0

if len(sys.argv) > 3:
    if sys.argv[3] == '-d':
        d = True

print("-------------")
while i < int(n):
    numbers = ' '.join(map(str, random.sample(range(-1000000, 1000000), int(t))))
    if d:
        print("[{}]".format(numbers))
    print("Result:")
    os.system("./push_swap {} | ./checker {}".format(numbers, numbers));
    print("Instructions:")
    os.system("./push_swap {} | wc -l".format(numbers));
    print("-------------")
    i += 1
