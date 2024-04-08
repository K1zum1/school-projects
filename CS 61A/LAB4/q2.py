def hailstone(n):
    """Print out the hailstone sequence starting at n, and return the number of elements in the sequence.
    >>> a = hailstone(10)
    10
    5
    16
    8
    4
    2
    1
    >>> a
    7
    """
    # print the current value of n
    print(n)
    # if n = 1 then return 1
    if n == 1:
        return 1
        # if n is evenly divisible by 2, then divide by 2 recursively. The 1
        # is needed to add to the length of the sequence (a = 7)
    elif n % 2 == 0:
        return 1 + hailstone(n//2)
    else:
        # else multiply by 3 and add 1 recursively
        return 1 + hailstone(3 * n + 1)