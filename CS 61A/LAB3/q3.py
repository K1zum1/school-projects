def make_keeper(n): 
    """Returns a function which takes one parameter cond and prints
    out all integers 1..i..n  where calling cond(i) returns True.
 
    >>> def is_even(x):
    ... #Even numbers have remainder 0 when divided by 2.
    ...     return x % 2 == 0
    >>> make_keeper(5)(is_even)
    2
    4
    """
    # nest the new function inside of make_keeper(n)
    def make_keeper2(cond):
        # initialize a value of 1 to begin counting
        num = 1
        # while n is greater than or equal to num run this code
        while num <= n:
            # check if the cond is true. aka: if the number is even
            if cond(num):
                # print that num if true otherwise ignore
                print(num)
            # increment num by 1 and continue the code until it terminates
            num += 1
    #returns true
    return make_keeper2