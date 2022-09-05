# PSET 2: processamento de imagens
 Resultados dos meus testes [testes](https://github.com/danielsmar/UVV_Ling_Prog_CC3M/tree/main/PSET2/test_results/test_results_pset)


 ### QUESTÃO 01: Se você passar essa imagem pelo filtro de inversão, qual seria o output esperado? Justifique sua resposta.
#### O output esperado seria a inversão das cores (4, 1, [226, 166, 119, 55]), pois o filtro de inversão reflete os pixels sobre o valor de cinza médio, ou seja, preto se torna branco e vice-versa.

### QUESTÃO 02: Faça a depuração e, quando terminar, seu código deve conseguir passar em todos os testes do grupo de teste TestInvertido (incluindo especificamente o que você acabou de criar). Execute seu filtro de inversão na imagem imagens_teste/peixe.png, salve o resultado como uma imagem PNG e salve a imagem em seu repositório GitHub.
![bluegill](https://github.com/danielsmar/UVV_Ling_Prog_CC3M/blob/main/PSET2/test_results/test_results_pset/test_inverted/bluegill.png)
![bluegill_inverted](https://github.com/danielsmar/UVV_Ling_Prog_CC3M/blob/main/PSET2/test_results/test_results_pset/test_inverted/bluegill_inverted.png)

### QUESTÃO 03: considere uma etapa de correlacionar uma imagem com o seguinte kernel:
        kernel = [[ 0.00, -0.07,  0.00],
                  [-0.45,  1.20, -0.25],
                  [ 0.00, -0.12,  0.00]]
### Qual será o valor do pixel na imagem de saída no local indicado pelo destaque vermelho? Observe que neste ponto ainda não arredondamos ou recortamos o valor, informe exatamente como você calculou. Observação: demonstre passo a passo os cálculos realizados.
![imagem_Q3](https://github.com/danielsmar/UVV_Ling_Prog_CC3M/blob/main/PSET2/test_results/imagem_Q3.png)

O(x,y) = (0.00 * 80) + (-0.07 * 53) + (0.00 * 99) + (-0.45 * 129) + (1.20 * 127) + (-0.25 * 148) + (0.00 * 175) + (-0.12 * 174) + (0.00 * 193)

O(x,y) = 0 + (-3.71) + 0 + (-58.05) + 152.4 + (-37) + 0 + 0 + (-20.88) + 0

O(x,y) = 32.76
### QUESTÃO 04: quando você tiver implementado seu código, tente executá-lo em imagens_teste/porco.png com o seguinte kernel 9 × 9:
        kernel = [[0,0, 0, 0, 0, 0, 0, 0, 0],
                 [0, 0, 0, 0, 0, 0, 0, 0, 0],
                 [1, 0, 0, 0, 0, 0, 0, 0, 0],
                 [0, 0, 0, 0, 0, 0, 0, 0, 0],
                 [0, 0, 0, 0, 0, 0, 0, 0, 0],
                 [0, 0, 0, 0, 0, 0, 0, 0, 0],
                 [0, 0, 0, 0, 0, 0, 0, 0, 0],
                 [0, 0, 0, 0, 0, 0, 0, 0, 0],
                 [0, 0, 0, 0, 0, 0, 0, 0, 0]]
![pigbird](https://github.com/danielsmar/UVV_Ling_Prog_CC3M/blob/main/PSET2/test_results/test_results_pset/test_blurred/pigbird.png)
![pigbirg_correlated](https://github.com/danielsmar/UVV_Ling_Prog_CC3M/blob/main/PSET2/test_results/test_results_pset/test_blurred/pigbird_correlated.png)

### Quando você terminar e seu código passar em todos os testes relacionados ao desfoque, execute seu filtro na imagem imagens_teste/gato.png com um kernel de desfoque de  caixa de tamanho 5.
![cats](https://github.com/danielsmar/UVV_Ling_Prog_CC3M/blob/main/PSET2/test_results/test_results_pset/test_blurred/cat.png)
![cats_blurred](https://github.com/danielsmar/UVV_Ling_Prog_CC3M/blob/main/PSET2/test_results/test_results_pset/test_blurred/cat_blurred.png)

### QUESTÃO 05: se quisermos usar uma versão desfocada B que foi feita com um kernel de desfoque de caixa de 3 × 3, que kernel k poderíamos usar para calcular toda a imagem nítida com uma única correlação? Justifique sua resposta mostrando os cálculos.


![python](https://github.com/danielsmar/UVV_Ling_Prog_CC3M/blob/main/PSET2/test_results/test_results_pset/test_sharpened/python.png)
![python_sharpened](https://github.com/danielsmar/UVV_Ling_Prog_CC3M/blob/main/PSET2/test_results/test_results_pset/test_sharpened/python_sharpened.png)

         k1 = [[0, 0, 0],       k2 = [[1/9, 1/9, 1/9],          k_result = [[-1/9,-1/9, -1/9],
               [0, 2, 0],     -       [1/9, 1/9, 1/9],     =                [-1/9, 17/9,-1/9], 
               [0, 0, 0]]             [1/9, 1/9, 1/9]]                      [-1/9, -1/9,-1/9]
               
              

### QUESTÃO 06: explique o que cada um dos kernels acima, por si só, está fazendo. Tente executar mostrar nos resultados dessas correlações intermediárias para ter uma noção do que está acontecendo aqui.
Detecta as bordas no eixo X (Horizontal) da imagem
       
        kx = [[-1, 0, 1],
              [-2, 0, 2],
              [-1, 0, 1]]
Detecta as bordas no eixo Y (Vertical) da imagem         
     
       ky = [[-1, -2, -1],
             [ 0,  0,  0],
             [ 1,  2,  1]]
![construct](https://github.com/danielsmar/UVV_Ling_Prog_CC3M/blob/main/PSET2/test_results/test_results_pset/test_edges/construct.png)
![construct_edges](https://github.com/danielsmar/UVV_Ling_Prog_CC3M/blob/main/PSET2/test_results/test_results_pset/test_edges/construct_edge.png)
