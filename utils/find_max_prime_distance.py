import math

# N = 10**6 # 114
N = 10**9 # 282

def primes(n, full_table=True, set_=True):
    """
    find all prime from [0,n]
    O(nlog(log(sqrt(n)))) ~= O(n)

    log(log(sqrt(n))) = 3.90... when n=10**9
    """
    import math

    half = int(math.sqrt(n)) + 1
    primes = [1 for _ in range(n+1)]

    primes[0] = 0
    primes[1] = 0

    for i in range(4, n+1, 2):
        primes[i] = 0

    for i in range(3, half, 2):
        if not primes[i]:
            continue
        for j in range(i*i, n+1, i*2):
            primes[j] = 0

    if full_table:
        return primes
    else:
        primes = [i for i, is_prime in enumerate(primes) if is_prime]
        if set_:
            primes = set(primes)
        return primes
    
p = primes(N, full_table=False, set_=False)

max_dist = -1
for i in range(1, len(p)):
    dist = p[i] - p[i-1]
    max_dist = max(dist, max_dist)

print(max_dist)