class Link:
    empty = ()
    
    def __init__(self, first, rest=empty):
        self.first = first
        self.rest = rest
        
        
def link_to_list(link):
    """Takes a linked list and returns a Python list with the same elements.

    >>> link = Link(1, Link(2, Link(3, Link(4))))
    >>> link_to_list(link)
    [1, 2, 3, 4]
    >>> link_to_list(link.empty)
    []
    """
    "*** YOUR CODE HERE ***"
    if link is Link.empty:
        return [ ]
    else:
        return [link.first] + link_to_list(link.rest)

