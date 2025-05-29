# Calcolo della formula chiusa di una di una relazione di ricorrenza di qualsiasi ordine

import sympy as sp

def findClosedFormula(coefficients, conditions):
    k = len(coefficients) # ordine della relazione
    r = sp.symbols('r')
    eq = r**k - sum(coeff * r**(k - 1 - i) for i, coeff in enumerate(coefficients)) # polinomio caratteristico
    roots = sp.roots(eq, r) # radici con loro molteplicità
    n = sp.symbols('n')
    constants = []
    for i in range (0, sum(roots.values())): # somma delle molteplicità = numero delle costanti
        constants.append(sp.symbols(f'a_{i}')) 
    print("Radici trovate")
    equations = [] # equazioni che metteremo a sistema
    for i, condition in enumerate(conditions):
        equation = 0
        constant_index = 0
        for root, multiplicity in roots.items():
            for j in range(0, multiplicity):
                equation += constants[constant_index] * i**j * root**i
                constant_index += 1
        equations.append(equation - condition) # a_i = condition
    print("Equazioni trovate")
    solution = sp.solve(equations, constants) # valore delle costanti
    print("Equazioni risolte")
    closed_formula = 0
    constant_index = 0
    for root, multiplicity in roots.items():
        for j in range(multiplicity):
            closed_formula += solution[constants[constant_index]] * n**j * root**n
            constant_index += 1
    return closed_formula

#test
coefficients = [1,1,3]
conditions = [0,1,2]  
print("Formula chiusa:")
print(findClosedFormula(coefficients, conditions))