## Graph Descritor
Proposta de iniciação científica com o título "Técnicas de Descrição de Imagens Baseadas em Grafo". Realizada na Universidade Tecnológica Federal do Paraná, Campus Cornélio Procópio, sob orientação do Prof. Dr. Pedro Henrique Bugatti.

Instruções de execução
-----------
O código executável tem como definição de entrada o exemplo a seguir.

```bash
./graph_descritor -r 20 -c 1 -f ../file.arff -l labels -p paths -cl classes
```

Paramêtros
---
* -r: este paramêtro define o tamanho da caixa de divisão da imagem. Os valores possíveis são: 4, 5, 8, 10, 20, 25, 40, 50, 100.
* -c: este paramêtro define o tipo de descrição utilizada. As escolhas são:
  * 1 - Média do caminho mínimo do algortimo de Dijkstra de 4 direções diferentes (0 graus, 45 graus, 90 graus, 135 graus)
  * 2 - Desvio padrão da mesma configuração do item 1
  * 3 - Item 1 concatenado com o item 2
  * 4 - Média da árvore geradora mínima do grafo
  * 5 - Desvio padrão da mesma configuração do item 4
  * 6 - Item 4 concatenado com o item 5
  * 7 - Item 1 concatenado com o item 4
  * 8 - Item 2 concatenado com o item 
  * 9 - Item 3 concatenado com o item 6
