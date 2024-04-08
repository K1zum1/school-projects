def flatten(lst):
    """Returns a flattened version of lst.
    >>> flatten([1, 2, 3])     # normal list
    [1, 2, 3]
    >>> x = [1, [2, 3], 4]      # deep list
    >>> flatten(x)
    [1, 2, 3, 4]
    >>> x = [[1, [1, 1]], 1, [1, 1]] # deep list
    >>> flatten(x)
    [1, 1, 1, 1, 1, 1]
    """
    # declare an array called flat
    flat = []
    # for element item in lst
    for item in lst:
        # we can use a built in python function called type
        # which will return the type of the object
        # if it is equal to a list
        if type(item) == list:
            # then we can recursively add it
            flat += flatten(item)
        else:
            # if it is not a list then add it to the list
            flat = flat + [item]
    # return the list
    return flat
    