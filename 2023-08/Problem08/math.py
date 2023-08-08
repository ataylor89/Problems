import sys

def approximate_pi(n):
    sum = 0
    sign = 1
    for i in range(1, n, 2):
        sum += (1/i * sign)
        sign *= -1
    return 4 * sum

if len(sys.argv) < 2:
    print('Usage: %s <degree of polynomial>')
    exit(0)

n = int(sys.argv[1])
pi = approximate_pi(n)
print('Pi = %f' % pi)
