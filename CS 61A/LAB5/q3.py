def enumerate(s, start=0):
    """Returns a list of lists, where the i-th list contains i+start and
    the i-th element of s.
    >>> enumerate([6, 1, 'a'])
    [[0, 6], [1, 1], [2, 'a']]
    >>> enumerate('five', 5)
    [[5, 'f'], [6, 'i'], [7, 'v'], [8, 'e']]
    """

    "*** YOUR CODE HERE ***"
 
    
    enumerate = [[i+start, s[i]] for i in range(len(s))]
    # return the expression i + start and the "i" index of s from the length of s
    return enumerate