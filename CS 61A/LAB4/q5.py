def gcd(a, b):
    """Returns the greatest common divisor of a and b.
    Should be implemented using recursion.

    >>> gcd(34, 19)
    1
    >>> gcd(39, 91)
    13
    >>> gcd(20, 30)
    10
    >>> gcd(40, 40)
    40
    """
    # if b is equal to 0, then return a because the GCD can only be a. this is the only edge
    # case we have to check
    if b == 0:
        return a
    # recursive function provided by Lab 04 document, essentially finds the GCD of b and the 
    # remainder of "a" divided by b
    return gcd(b, a % b)