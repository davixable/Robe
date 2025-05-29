# Programma che, dato un grafo non orientato in forma di relazione di adiacenza, costruisce la sua matrice di 
# adiacenza e, se esiste, identifica un circuito di Eulero dato come sequenza di nodi.

def find_adj_matrix(rel_adj):
    nodes_set = set()
    for v, w in rel_adj:
        nodes_set.add(v)
        nodes_set.add(w)

    nodes = sorted(list(nodes_set))
    n = len(nodes) # numero di nodi
    adj_matrix = [[0]*n for row in range(n)] # matrice NxN 

    for v, w in rel_adj:
        i = nodes.index(v)
        j = nodes.index(w)
        adj_matrix[i][j] = 1
        adj_matrix[j][i] = 1 # grafo non orientato, matrice di adiacenza simmmetrica
    return nodes, adj_matrix

def find_euler_circuit(adj_matrix):
    n = len(adj_matrix)
    for row in adj_matrix:
        if sum(row) % 2 != 0 or sum(row) == 0:
            return None # ritorna None se ci sono nodi di grado 0 (isolati) o di grado dispari

    adj_matrix_copy = [row.copy() for row in adj_matrix]
    circuit = []

    def explore_matrix(v):
        for w in range(n):
            if adj_matrix_copy[v][w] == 1:
                adj_matrix_copy[v][w] = 0
                adj_matrix_copy[w][v] = 0
                explore_matrix(w)
        circuit.append(v)

    explore_matrix(0) # partiamo dalla riga 0
    circuit.reverse() # la ricorsione costruisce il percorso partendo dalla fine, dunque lo invertiamo

    return circuit



rel_adj = [(1,2),(2,3),(3,4),(4,1),(1,5),(5,6),(6,1)]
nodes, adj_matrix = find_adj_matrix(rel_adj)
circuit = find_euler_circuit(adj_matrix)

print("Nodi del grafo:", nodes)
print("Matrice di adiacenza:")
for i in range(len(adj_matrix)):
    print(adj_matrix[i])

if circuit is None:
    print("Non esiste un circuito di Eulero.")
else:
    percorso = " -> ".join(str(nodes[i]) for i in circuit)
    print("Circuito di Eulero:", percorso)



    