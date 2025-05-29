def trova_relazione (insieme, relazione):

    def isReflexive ():
        for x in insieme:
            if (x,x) not in relazione:
                return False
        return True

    def isSymmetric ():
        for (x,y) in relazione:
            if (y,x) not in relazione:
                return False
        return True
        
        
    def isAntisymmetric ():
        for (x,y) in relazione:
            if(y,x) in relazione:
                if (x!=y):
                    return False
        return True

    def isTransitive ():
        for x in insieme:
            for y in insieme:
                for z in insieme:
                    if(x,y) in relazione and (y,z) in relazione and (x,z) not in relazione:
                        return False
        return True

    def isTotal ():
        for x in insieme:
            for y in insieme:
                if(x!=y):
                    if(x,y) not in relazione and  (y,x) not in relazione:
                        return False
        return True
    
    def isFunction():
        for x in insieme:
            x_occurance=0
            for (y,z) in relazione:
                if (y==x):
                    x_occurance+=1
            if x_occurance!=1:
                return False
        return True

    riflessiva = isReflexive()
    simmetrica = isSymmetric()
    antisimmetrica = isAntisymmetric()
    transitiva = isTransitive()
    totale = isTotal()
    funzione = isFunction()

    if funzione:
        print("La relazione è una FUNZIONE.")
    elif riflessiva and simmetrica and transitiva:
        print("La relazione è una una RELAZIONE DI EQUIVALENZA.")
    elif riflessiva and antisimmetrica and transitiva:
        if totale:
            print("La relazione è di ORDINE TOTALE.")
        else:
            print("La relazione è di ORDINE PARZIALE.")
    else:
        print("La relazione non rientra in nessuno dei casi studiati.")

insieme={1,2,3}
relazione1={(1,1),(1,2),(2,2),(3,3)}
relazione2={(1,2),(2,3),(3,2)}
trova_relazione(insieme,relazione1)
