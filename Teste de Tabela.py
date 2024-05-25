from itertools import product

def generate_truth_table(variables, expression):
    # Criar todas as combinações possíveis de valores verdadeiros e falsos
    combinations = list(product([False, True], repeat=len(variables)))
    
    # Cabeçalho da tabela
    header = variables + [expression]
    print(' | '.join(header))
    print('-' * len(' | '.join(header)))
    
    # Avaliar a expressão para cada combinação de valores
    for combination in combinations:
        env = dict(zip(variables, combination))
        result = eval(expression, {}, env)
        row = list(combination) + [result]
        print(' | '.join(map(str, row)))

# Função para converter a entrada do usuário para uma expressão Python
def parse_expression(user_input):
    return user_input.replace('AND', 'and').replace('OR', 'or').replace('NOT', 'not')

#Exemplo de uso
variables = ['A', 'B']
user_input = '(A AND B)'

expression = parse_expression(user_input)
generate_truth_table(variables, expression)
