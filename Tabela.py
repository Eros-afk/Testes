import ttg

# Exemplo com variáveis p, q e r
print(ttg.Truths(['p', 'q', 'r']))

# Exemplo com expressões lógicas
print(ttg.Truths(['p', 'q', 'r'], ['p and q and r', 'p or q or r', '(p or (~q)) => r']))
