def divisor(n):
    """
    find all divisor of n
    O(sqrt(n))
    """
    import math

    half = int(math.sqrt(n)) + 1
    div = []
    for i in range(1, half):
        if n%i != 0:
            continue
        div.append(i)
        if i*i != n:
            div.append(n//i)

    return div

def is_prime(n):
    """
    check is n a prime or not
    O(sqrt(n))
    """
    import math

    if n < 2:
        return False
    
    half = int(math.sqrt(n)) + 1
    for i in range(2, half):
        if n%i == 0:
            return False
        
    return True

def factor(n, set_=False):
    """
    find all prime factor, return in counter
    O(sqrt(n))
    """
    from collections import defaultdict

    d = defaultdict(int)
    i = 2
    while i*i <= n:
        while n%i == 0:
            d[i] += 1
            n//=i
        i+=1

    if n>1:
        d[n] += 1

    if set_:
        return set(d.keys())
    else:
        return d

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

def find_soe(n):
    """
    generate soe table from [0,n]
    O(nlog(log(n))) ~= O(n)

    log(log(n)) = 4.90... when n=10**9
    """
    soe = [0 for _ in range(n+1)]

    for i in range(4, n+1, 2):
        soe[i] = 2

    for i in range(3, n+1, 2):
        if soe[i]:
            continue
        for j in range(i*i, n+1, i*2):
            soe[j] = i
            j+=i*2

    return soe