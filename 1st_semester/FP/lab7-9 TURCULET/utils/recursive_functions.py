def length(list):
    '''
    Returns the length of a list, recursively
    :param list:
    :return:
    '''
    if len(list) == 0:
        return 0
    else:
        return 1+length(list[1:])
def average_mark(marks,student,sum=0,number=0):
    '''
    does the average mark for a student given a list of marks,recursively
    :param marks: LIST
    :param student: student
    :param sum: int
    :param number: int
    :return:
    '''
    if len(marks) == 0:
        return sum,number
    elif marks[0].getStudent() == student.getId():
        sum=sum*number
        sum+=marks[0].getMark()
        number+=1
        sum=sum/number
    return average_mark(marks[1:],student,sum,number)


