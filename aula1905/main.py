import random
import matplotlib.pyplot as plt
import numpy as np

def inserir_n_aleatorios(m, aleatorios):
  th = [ [] for i in range(m) ]
  
  for rn in aleatorios:
    h = rn % m
    if rn not in th[h]:
      th[h].append(rn)

  #print(th)
  return(th)

def tam_medio(th):
  tam = list(map(len,th))
  return np.mean(tam), np.std(tam)

t = inserir_n_aleatorios(7, [20, 7, 14, 15])

ms = [500, 499]
ns = [1000000]

random.seed(1)

for n in ns:
  aleatorios = []
  for i in range(n):
    aleatorios.append(random.randint(0, 10*n))

  for m in ms:
    plt.figure()
    th = inserir_n_aleatorios(m, aleatorios)

    media, desvio = tam_medio(th)

    titulo = "m = %d, tamanho médio = %.2f +- %.2f" % (m, media, desvio)
    plt.title(titulo)

    # plt.bar(range(m), list(map(len, th)))
    # plt.axhline(media, color='red')
    p10, p90 = np.quantile(list(map(len, th)), [0.1, 0.9])
    
    plt.hist(list(map(len, th)), 20)
    plt.axvline(p10, color='purple')
    plt.axvline(p90, color='purple')
    plt.ylabel("Número da lista")
    plt.xlabel("Tamanho da lista")