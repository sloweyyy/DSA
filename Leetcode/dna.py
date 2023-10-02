from itertools import permutations

def find_infected_chickens(virus_dna, chicken_dnas):
    infected_chickens = []
    for chicken_dna in chicken_dnas:
        if is_infected(virus_dna, chicken_dna):
            infected_chickens.append(chicken_dna)
    return infected_chickens

def is_infected(virus_dna, chicken_dna):
    virus_dna_permutations = permutations(virus_dna)
    for virus_dna_permutation in virus_dna_permutations:
        virus_dna_permutation = ''.join(virus_dna_permutation)
        if virus_dna_permutation in chicken_dna:
            return True
    return False

num_chickens = int(input())
chicken_dnas = []
virus_dna = input()
for i in range(num_chickens):
  chicken_dnas.append(input())

infected_chickens = find_infected_chickens(virus_dna, chicken_dnas)
print(len(infected_chickens))