# O mais próximo que existe de um array em Python são Tuplas, que ainda assim 
# tem suas diferenças que comentarei quando chegar a hora

def isEmpty(tupla):
    if size(tupla) == 0:
        raise AttributeError("A lista esta vazia") 
    return 0

def outOfBounds(tupla, index):
    if index < 0 or index >= size(tupla):    
        raise IndexError("Index fora dos limites")
    return 0

def addLast(tupla, elemento):
    nova_tupla = tupla + (elemento,)
    return nova_tupla

def addFirst(tupla, elemento):
    nova_tupla = (elemento,) + tupla
    return nova_tupla

def addIndex(tupla, elemento, index): 
    outOfBounds(tupla,index)
    nova_tupla = tupla[:index] + (elemento,) + tupla[index:] 
    return nova_tupla

def rmvLast(tupla):
    isEmpty(tupla)
    nova_tupla = tupla[:size(tupla)-1]
    return nova_tupla

def rmvFirst(tupla):
    isEmpty(tupla)
    nova_tupla = tupla[1:]
    return nova_tupla

def rmvIndex(tupla, index):
    isEmpty(tupla)
    outOfBounds(tupla, index)
    nova_tupla = tupla[:index] + tupla[index+1:]
    return nova_tupla

def contains(tupla, elemento):
    isEmpty(tupla)
    for valor in tupla:
        if valor == elemento:
            return True
    return False


def size(tupla):
    return len(tupla)

tupla = () 
