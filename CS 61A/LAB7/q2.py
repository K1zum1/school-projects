def group_by(seq, fn): 
    
    """ 
    >>> group_by([12, 23, 14, 45], lambda p: p // 10) 
    {1: [12, 14], 2: [23], 4: [45]}
    >>> group_by(list(range(-3, 4)), lambda x: x * x)
    {0: [0], 1: [-1, 1], 4: [-2, 2], 9: [-3, 3]}
    """
    # initialize a dictionary
    dictionary = {}

    # for element in sequence
    for e in seq:
        # set the value of dict_key of the result of e going through fn
        dict_key = fn(e)
        # if dict_key exist in dictionary then append the dict_key to the dictionary with key value of e
        if dict_key in dictionary:
            dictionary[dict_key].append(e)
        else:
            # otherwise set it equal to the list element
            dictionary[dict_key] = [e]
    # we need to sort the dictionary because the pairs are not in the order we want them to be
    sorted_dictionary = sorted(dictionary)
    # initialize another dictionary
    result_dict = {}
    # for each x in the dictionary add it to the result along with its value
    for x in sorted_dictionary:
        result_dict[x] = dictionary[x]
    # return the result_dict
    return result_dict