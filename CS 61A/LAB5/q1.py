def if_this_not_that(i_list, this):
    """Define a function which takes a list of integers `i_list` and an integer `this`.
    For each element in `i_list`, print the element if it is larger than `this`;
    otherwise, print the word "that".
    >>> original_list = [1, 2, 3, 4, 5]
    >>> if_this_not_that(original_list, 3)
    that
    that
    that
    4
    5
    """
    
# for value inside the i_list do this
    for value in i_list:
        # if the value in the array happens to be bigger than this
        if value > this:
            # print that value
            print(value)
        else:
            # otherwise print "that"
            print("that")