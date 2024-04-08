def make_adder_inc(n):
    """
    >>> adder1 = make_adder_inc(5)
    >>> adder2 = make_adder_inc(6)
    >>> adder1(2) 
    7
    >>> adder1(2) # 5 + 2 + 1
    8
    >>> adder1(10) # 5 + 10 + 2
    17
    >>> [adder1(x) for x in [1, 2, 3]]
    [9, 11, 13]
    >>> adder2(5)
    11
    """
    """ YOUR CODE HERE """

    #initialize a counter
    counter = 0
    # make another function that accepts a value x
    def cont_adding(x):
        # make the variable nonlocal so that we can alter it
        nonlocal counter
        # total equals n + x + value of counter
        total = n + x + counter
        # increment the counter and then return the result
        counter += 1
        return total
    # we return the function again because we need to use it later.
    return cont_adding
    