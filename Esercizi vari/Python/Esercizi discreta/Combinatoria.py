# Programma che, dato un insieme di n elementi e un parametro k genera: 
# - Tutte le permutazioni dell'insieme (con ripetizioni o senza)
# - Se applicabili, le sue disposizioni e combinazioni di classe k, semplici e ripetute.

def find_permutations(items): # genera TUTTE le permutazioni dell'insieme
    if len(items) == 0: return [[]]
    return [[items[i]] + perm for i in range(len(items)) for perm in find_permutations([items[j] for j in range(len(items)) if j != i])]

def find_unique_permutations(permutations): # sottoinsieme delle permutazioni trovate in precedenza, basta filtrare i duplicati
    if len(permutations) == 0: return [[]]
    return [list(perm) for perm in set(tuple(perm) for perm in permutations)]


def find_arrangements(items, k): # k <= n, se k = n le disposizioni semplici coincidono con le permutazioni
    if k == 0: return [[]]
    if k > len(items): return []
    return [[items[i]] + arr for i in range(len(items)) for arr in find_arrangements([items[j] for j in range(len(items)) if j != i], k - 1)]


def find_repeated_arrangements(items, k): # qui possiamo avere k > n
    if k == 0:
        return [[]]
    return [[items[i]] + arr for i in range(len(items)) for arr in find_repeated_arrangements(items, k - 1)]


def find_combinations(arrangements): 
    return [list(t) for t in {tuple(sorted(arr)) for arr in arrangements}] # l'ordine è irrilevante


# test
items = [4,2,5,3]
k = 2

has_duplicates = True if len(items) != len(set(items)) else False  

print("Permutazioni dell'insieme:")
permutations = find_permutations(items)    #genera TUTTE le permutazioni possibili
for perm in permutations:
    print(perm)

if has_duplicates:    # se ci sono duplicati, eliminiamo le permutazioni che si ripetono
    print("Permutazioni dell'insieme (senza ripetizioni):")
    unique_permutations = find_unique_permutations(permutations)
    for perm in unique_permutations:
        print(perm)

else:                 # se non ci sono duplicati, possiamo considerare le disposizioni e le combinazioni
    print(f"Disposizioni di classe {k}:")
    arrangements = find_arrangements(items, k)
    for arr in arrangements:
        print(arr)

    print(f"Disposizioni di classe {k} con ripetizioni:") 
    repeated_arrangements = find_repeated_arrangements(items, k)
    for arr in repeated_arrangements:
        print(arr)

    print(f"Combinazioni di classe {k}:") 
    combinations = find_combinations(arrangements) # le combinazioni sono un sottoinsieme delle disposizioni
    for comb in combinations:
        print(comb)

    print(f"Combinazioni di classe {k} (con ripetizioni):")
    repeated_combinations = find_combinations(repeated_arrangements) # uso la stessa funzione, cambiando solamente l'input
    for comb in repeated_combinations:
        print(comb)