def make_fib():
    """Returns a function that returns the next Fibonacci number
    every time it is called.
    
    >>> fib = make_fib()
    >>> fib()
    0
    >>> fib()
    1
    >>> fib()
    1
    >>> fib()
    2
    >>> fib()
    3
    >>> fib2 = make_fib()
    >>> fib() + sum([fib2() for _ in range(5)])
    12
    """
    # initialize two numbers
    nextnum, nextnextnum = 0,1
    # define a function
    def fib_next():
        # make the two variables non local so that they can be updated
        nonlocal nextnum, nextnextnum
        # store the value of nextnum into total
        total = nextnum
        # update the variables, making nextnum = nextnextnum and nextnextnum equal
        # to nextnextnum + nextnum
        nextnum, nextnextnum = nextnextnum, nextnextnum + nextnum
        # return the current number and then return the fibonnaci function
        return total
    return fib_next
        