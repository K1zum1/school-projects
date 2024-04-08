def squares(s):
    """Returns a new list containing square roots of the elements of the original list
    that are perfect squares.
    >>> seq = [8, 49, 8, 9, 2, 1, 100, 102]
    >>> squares(seq)
    [7, 3, 1, 10]
    >>> seq = [500, 30]
    >>> squares(seq)
    []
    """
    # import a math library in order to use the .isqrt function
    import math
    # declare an array named list
    list = []
    # for x in the s array
    for x in s:
        # set the value of sqrt to the square root of x
        sqrt = math.sqrt(x)
        # if rounded value of sqrt raised to the powert of 2 equals x
        # then the number must be a perfect square
        if pow(round(sqrt),2) == x:
            # add the array value into the list and continue until the loop termiantes
            list += [round(sqrt)]
    # return the list
    return list
        