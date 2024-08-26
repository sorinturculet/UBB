from Utilities.Cheltuiala import *
from Utilities.ListUtils import *
def getDay(cheltuiala):
    return cheltuiala['day']
def getSum(cheltuiala):
    return cheltuiala['sum']
def getType(cheltuiala):
    return cheltuiala['type']
def getName(cheltuiala):
    return cheltuiala['name']
def getCurrentList(TaskManager):
    return TaskManager['current_task_list']
def getUndoList(TaskManager):
    return TaskManager['undo_list']
def undo(TaskManager):

    UndoList=getUndoList(TaskManager)
    if len(UndoList)>0:
        LastOperation=UndoList[-1]
        UndoList.pop()
        setUndoList(TaskManager,UndoList)
        setCurrentList(TaskManager,LastOperation)
    else:
        print('Nu se mai poate face UNDO.')
def updateUndoList(TaskManager,newUndoElement):
    undoList=getUndoList(TaskManager)
    undoList.append(newUndoElement)
    setUndoList(TaskManager,undoList)

def setUndoList(TaskManager,newUndoList):
    TaskManager['undo_list']=newUndoList
def setCurrentList(TaskManager,newCurrentList):
    TaskManager['current_task_list']=newCurrentList