def bubble_sort(iteration,key = lambda el:el,reverse=False):
    '''
     Complexity:
     Best case: O(n) (everything is sorted in ascending order and it only has to verify it)
     Worst case:O(n^2) (everything is sorted in descending order and has to switch every item)
    :param iteration: list
    :param key: function
    :param reverse: bool
    :return:
    '''
    n=len(iteration)
    if reverse==True:
        for i in range(n-1):
            swapped = False
            for j in range(0, n-1):
                if key(iteration[j]) < key(iteration[j + 1]):
                    iteration[j], iteration[j+ 1] = iteration[j + 1], iteration[j]
                    swapped = True
            if (swapped == False):
                break
    else:
        for i in range(n-1):
            swapped=False
            for j in range(0, n-1):
                if key(iteration[j]) > key(iteration[j + 1]):
                    iteration[j], iteration[j + 1] = iteration[j + 1], iteration[j]
                    swapped = True
            if(swapped==False):
                break
    return iteration



