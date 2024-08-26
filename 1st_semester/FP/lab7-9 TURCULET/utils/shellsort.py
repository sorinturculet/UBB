def shellsort(iteration,key=lambda el:el,reverse=False):
    n=len(iteration)
    gap = n // 2
    while gap > 0:
        j = gap
        while j < n:
            i = j - gap
            while i >= 0:
                if key(iteration[i + gap]) > key(iteration[i]):

                    break
                else:
                    iteration[i + gap], iteration[i] = iteration[i], iteration[i + gap]

                i = i - gap
            j += 1
        gap = gap // 2
    if reverse==True:
        iteration.reverse()
    return iteration

