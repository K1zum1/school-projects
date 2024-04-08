def add_this_many(x, el, lst): 
    """ Adds el to the end of lst the number of times x occurs in lst. 
    >>> lst = [1, 2, 4, 2, 1]
    >>> add_this_many(2, 5, lst)
    >>> lst
    [1, 2, 4, 2, 1, 5, 5]
    >>> add_this_many(2, 2, lst)
    >>> lst 
    [1, 2, 4, 2, 1, 5, 5, 2, 2]
    """
    # we need to have a counter because using range(x) from the start would not work
    # this is to account for the possibility of a number error
    counter = 0 
    # for number in range of the lst
    for number in lst:
        # if that number == x then increment the counter by 1
        if number == x:
            counter += 1
    # append el to lst up to range of counter
    for i in range(counter):
        lst.append(el)
        