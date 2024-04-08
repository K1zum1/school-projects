def key_of_min_value(d):
    """Returns the key in a dict d that corresponds to the minimum value of d.
    >>> letters = {'a': 6, 'b': 5, 'c': 4, 'd': 5}
    >>> min(letters)
    'a'
    >>> key_of_min_value(letters)
    'c'
    """
    "*** YOUR CODE HERE ***"
    # this returns the minimum between value d, and the value associated
    # with the key because the minimum value is the one with the smallest value
    # in the dict
    return min(d,key=lambda x: d[x])
        