def memory(n): 
    """
    >>> f = memory(10)
    >>> f(lambda x: x * 2)
    20
    >>> f(lambda x: x - 7)
    13
    >>> f(lambda x: x > 5)
    True
    """
    # define a new function that takes in a value f
    def new(f):
        # make the n value non local so the n can be updated
        nonlocal n
        # let n = the tested value of n going through the lambda function which
        # will return a true or false value
        n = f(n)
        # return n
        return n
    # return the value of new again so that we can use it later to update the value of n
    return new