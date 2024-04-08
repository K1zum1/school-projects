def keep_ints(cond, n):

    """Print out all integers 1..i..n where cond(i) is true

    >>> def is_even(x):
    ... #Even numbers have remainder 0 when divided by 2.
    ...     return x % 2 == 0
    >>> keep_ints(is_even, 5)
    2
    4
    """
    # initialize a value of 1 to begin counting
    num = 1
    # while n is greater than or equal to num run this code
    while num <= n:
        # check if the cond is true. aka: if the number is even
        if cond(num):
            # print that num if true otherwise ignore
            print(num)
        # increment num by 1 and continue the code until it terminates
        num += 1

        