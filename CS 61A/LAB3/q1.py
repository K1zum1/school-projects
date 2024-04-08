def lambda_curry2(func):
    """
    Returns a Curried version of a two-argument function FUNC.
    >>> from operator import add
    >>> curried_add = lambda_curry2(add)
    >>> add_three = curried_add(3)
    >>> add_three(5)
    8
    """

    # takes in a value x, which will return a function that accepts value y, which
    # then gives you the resulting func(x,y)
    return lambda x: lambda y: func(x,y)