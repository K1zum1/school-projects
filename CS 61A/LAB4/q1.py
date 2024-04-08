def skip_add(n):
    """ Takes a number x and returns x + x-2 + x-4 + x-6 + ... + 0
    >>> skip_add(5)  # 5 + 3 + 1 + 0
    9
    >>> skip_add(10) # 10 + 8 + 6 + 4 + 2 + 0
    30
    >>> # Do not use while/for loops!
    """
    
    # check if n is less than 0
    if n < 0:
        # if it is then return 0
        return 0
    # otherwise recursively add n + n-2 + n-2-2 + ...
    return n + skip_add(n-2)

        