
#Constructor
def tree(label, branches=[]):
    for branch in branches:
        assert is_tree(branch)
    return [label] + list(branches)

#Selectors
def label(tree):
    return tree[0]

def branches(tree):
    return tree[1:]

def is_tree(tree):
    if type(tree) != list or len(tree) < 1:
        return False
    return True

def is_leaf(tree):
    return not branches(tree)
def print_tree(t, indent=0):
    print('  ' * indent + str(label(t)))
    for b in branches(t):
        print_tree(b, indent + 1)
#Test Trees
t1 = tree(3, [tree(1), tree(2, [tree(1), tree(1)])])
t2 = tree('A', [tree('B'), tree('C', [tree('D'), tree('E')])])
t3 = tree(8,
          [tree(4,
                [tree(2), tree(3)]),
           tree(3,
                [tree(1), tree(1,
                               [tree(1), tree(1)])])])

def double_tree(t): 
    """Return a tree with the square of every element in t 
    >>> numbers = tree(1, [tree(2, [tree(3), tree(4)]), tree(5, [tree(6, [tree(7)]), tree(8)])]) 
    >>> print_tree(double_tree(numbers)) 
    2
      4
        6
        8
      10
        12
          14
        16
    """
    # if it is a leaf return the tree of the value doubled
    if is_leaf(t):
        return tree(label(t) * 2)
    # initialize a new array
    two_branches = []
    for x in branches(t):
        # we need to keep track of the values as x iterates through brances(t)
        # add it to the list two_branches
        two_branches += [double_tree(x)]
    # return the label doubled, and the list of branches 
    return tree(label(t) * 2, two_branches)
