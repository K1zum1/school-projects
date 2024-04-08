def couple(s1, s2):
    """Return a list that contains lists with i-th elements of two sequences
    coupled together.
    >>> s1 = [1, 2, 3]
    >>> s2 = [4, 5, 6]
    >>> couple(s1, s2)
    [[1, 4], [2, 5], [3, 6]]
    >>> s3 = ['c', 6]
    >>> s4 = ['s', '1']
    >>> couple(s3, s4)
    [['c', 's'], [6, '1']]
    """
    # this line was given, it basically raises an error if the lengths are not the same
    assert len(s1) == len(s2)

    "*** YOUR CODE HERE ***"
    
    # set the variable couple equal to a new list that uses list comprehension
    # the expression [s1[i], s2[i]] is printed from the for loop
    # as i iterates over the length of s1, it creates the list containing the elements s1,s2 
    couple = [[s1[i], s2[i]] for i in range(len(s1))]
    return couple
            
        