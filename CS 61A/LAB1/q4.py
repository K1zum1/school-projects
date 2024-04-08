#Question 4 JAY CHONG


def sumN(n):
    """Sum all the first n natural numbers.
    >>> sumN(3) # 1 + 2 + 3 = 6
    6
    >>> sumN(5) # 1 + 2 + 3 + 4 + 5 = 15
    15
    """
    #int() is necessary to convert a float to an int
    return(int(n/2 * (n+1)))
