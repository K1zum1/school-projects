def count_k(n, k):
    """ >>> count_k(3, 3) # 3, 2 + 1, 1 + 2, 1 + 1 + 1 
    4
    >>> count_k(4, 4)
    8
    >>> count_k(10, 3) 
    274
    >>> count_k(300, 1) 
    1 
    """
    # one of the base cases if there is 0 steps then there is only 1 way to sum to 0
    if n == 0:
        return 1
    # this is another case, in which if n is a negative number there should be 0 steps
    elif n < 0:
        return 0
    else: 
        # initialize a variable to keep track of how many steps are possible
        steps = 0
        # initialize a base value of 1
        i = 1
        # while i is less than or equal to k, try all possible values from 1 to k
        while i <= k:
            # recursively count all the possibles ways that steps can be taken and add it to steps
            steps += count_k(n-i,k)
            # add one to i and keep the while loop going until terminated
            i += 1
        # return the amount of steps
        return steps