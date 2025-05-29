from anytree import Node, RenderTree

class Proposition:
    atoms = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o']
    operators = ['imp', 'or', 'and', 'not']
    precedence = ['I', 'O', 'A', 'N']
    symbols = ['(', ')']

    def __init__(self, expression):
        self.string = expression
        self.tokens = self.tokenize(expression)
        self.tree = self.make_tree(self.tokens)
        self.atoms_in_proposition, self.number_of_atoms = self.find_atoms_in_proposition()

    def tokenize(self, expression):
        tokens = ""
        i = 0

        while i < len(expression):
            char = expression[i]

            if char == ' ':
                i += 1
                continue

            found = False
            for operator in self.operators:
                if expression.startswith(operator, i):
                    tokens += char.upper()
                    i += len(operator)
                    found = True
                    break
            
            else:
                if char in self.symbols:
                    tokens += char
                    i += 1

                elif char in self.atoms:
                    tokens += char
                    i += 1

                else:
                    raise ValueError(f"Carattere non riconosciuto: '{expression[i]}'")
            
        return tokens
    
    def make_tree(self, tokens):
        
        if len(tokens) == 1:    # caso base, l'atomo sarà una foglia
            return Node(tokens[0])
        
        if len(tokens) >= 2 and tokens[0] == '(' and tokens[-1] == ')':  # togliamo le parentesi più esterne bilanciate
            depth = 0
            for index, token in enumerate(tokens):
                if token == '(':
                    depth += 1
                elif token == ')':
                    depth -= 1
                if depth == 0 and index < len(tokens) - 1:  # se il bilanciamento torna a zero prima della fine, non strippo
                    break
            else:
                return self.make_tree(tokens[1:-1])

        
        for op in self.precedence:          # la ricerca dell'operatore avviene in ordine di precedenza
            depth = 0
            for i, token in enumerate(tokens):
                if token == '(':
                    depth += 1
                elif token == ')':
                    depth -= 1
                elif depth == 0 and token == op:
                    node = Node(op)
                    if op == 'N':           # NOT avrà un solo figlio, lo trattiamo come caso a parte
                        child = self.make_tree(tokens[i+1:])
                        node.children = [child]
                    else:
                        left = self.make_tree(tokens[:i])
                        right = self.make_tree(tokens[i+1:])
                        node.children = [left, right]
                    return node

    def evaluate_proposition(self, valuation):
        def evaluate_node(node):
            if node.name in self.atoms:
                return valuation[node.name]
            elif node.name == 'N':
                return not evaluate_node(node.children[0])
            elif node.name == 'O':
                return evaluate_node(node.children[0]) or evaluate_node(node.children[1])
            elif node.name == 'A':
                return evaluate_node(node.children[0]) and evaluate_node(node.children[1])
            elif node.name == 'I':
                return (not evaluate_node(node.children[0])) or evaluate_node(node.children[1])
        return evaluate_node(self.tree)
    
    def find_atoms_in_proposition(self):
        atoms_in_proposition = []

        for token in self.tokens:
            if token in self.atoms:
                atoms_in_proposition.append(token)
        atoms_number = len(atoms_in_proposition)

        return atoms_in_proposition, atoms_number





    def __str__(self):
        lines = [f"Proposizione: {self.string}", f"Proposizione tokenizzata: {self.tokens}", "Albero di derivazione:"]
        for pre, fill, node in RenderTree(self.tree):
            lines.append(f"{pre}{node.name}")
        return "\n".join(lines)

  

p = Proposition('(a) imp (b)')
v = {
    'a':True, 
    'b':True, 
    'c':False, 
    'd':True, 
    'e':False
    }
print(p)    # stampa proposizione originale, proposizione tokenizzata e albero di derivazione
print(p.evaluate_proposition(v))