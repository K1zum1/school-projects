def is_prime(n):
    """Returns True if n is a prime number and False otherwise.

    >>> is_prime(2)
    True
    >>> is_prime(16)
    False
    >>> is_prime(521)
    True
    """
    # define our helper function
    def is_prime_helper(x):
        # if x is equal to n then there must be no possible divisor for n and it is a prime
        if x == n:
            return True
        # if you can divide n by x evenly or is n is equal to one then it is not prime
        # the reason we need n==1 is because prime numbers are defined as integers greater than one
        # and one is not a prime number
        elif n % x == 0 or n == 1:
            return False
        else:
            # else recrusively check the next value of x which would be 3
            return is_prime_helper(x+1)
        # start by checking an initial value of 2 since 1 would not matter
    return is_prime_helper(2)