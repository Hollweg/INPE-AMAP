# INPE Sattelite Data Manipulation

## A proposta

Software desenvolvido para o **INPE** (Instituto Nacional de Pesquisas Espaciais), a fim de manipular dados de **estações de GPS e satélites**, e facilitar a inserção em softwares que tenham como entrada arquivos .txt. 

Tendo em vista que os arquivos raw provenientes de observações muitas vezes contém uma **grande quantidade de dados (100 MB+) é inviável a manipulação desses dados manualmente**, tornando-os apropriados para o uso em certos softwares de análise. </br> 

Portanto, para isso, foi desenvolvido esse algoritmo que facilita a inserção de arquivos .txt e filtra elementos indesejados, bem como dados indisponíveis ou erros de aquisição e leitura. </br> 

## Utilização

O algoritmo permite ao usuário escolher a fonte de dados utilizada (estações de GPS ou satélites) e como deseja que o arquivo output.txt seja criado. </br>
Para utilização do algoritmo é necessário que na mesma pasta onde esteja o arquivo .c haja uma pasta de nome _InFiles/_ contendo os arquivos brutosa serem filtrados. 

O código apresenta uma interface gráfica simples, permitindo ao usuário selecionar a opção que seja mais adequada, através do teclado e uma simples interface gráfica. 

O algoritmo facilita a inserção de dados em 2 softwares bastante comuns no INPE: 

1. SGEMS (http://sgems.sourceforge.net/?q=node/77) </br>
2. Octave (https://www.gnu.org/software/octave/)

## Direitos

**Software Livre** para utilização; </br>
Entretanto, caso isso seja feito, **referenciar o autor**.


Enjoy!

Hollweg

