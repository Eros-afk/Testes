from itertools import product

def gerar_tabela_verdade(expressao):
    # Identifica as variáveis únicas na expressão
    variaveis = sorted(set(filter(str.isalpha, expressao)))
    combinacoes = list(product([False, True], repeat=len(variaveis)))

    print(f"{' '.join(variaveis)} | Resultado")
    for combinacao in combinacoes:
        # Cria um dicionário com os valores das variáveis
        contexto = dict(zip(variaveis, combinacao))
        # Avalia a expressão com os valores atuais
        resultado = eval(expressao, {}, contexto)
        # Imprime a linha da tabela verdade
        print(' '.join(str(int(v)) for v in combinacao) + f" | {int(resultado)}")

# Solicita ao usuário que digite uma expressão lógica
expressao_usuario = input("Digite sua expressão lógica usando 'and', 'or', 'not': ")
gerar_tabela_verdade(expressao_usuario)
