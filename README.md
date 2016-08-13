# INPE Sattelite Data Manipulation
Software desenvolvido para o INPE (Instituto Nacional de Pesquisas Espaciais), a fim de manipular dados de estações de GPS e satélites, e facilitar a inserção em softwares que tenham como entrada arquivos .txt. Tendo em vista que os arquivos raw provenientes de observações muitas vezes são enormes (100 MB+) é inviável a manipulação desses dados manualmente. Portanto, para isso, desenvolvi esse algoritmo que facilita a inserção de arquivos .txt e filtra elementos indesejados, bem como dados indisponíveis ou erros de leitura.

O algoritmo permite ao usuário escolher a fonte de dados utilizada (estações de GPS) e como deseja que o arquivo output.txt seja criado.
Para utilização do algoritmo é necessário que na mesma pasta onde esteja o arquivo .c haja uma pasta de nome InFiles/ contendo os arquivos brutosa serem filtrados.

O código apresenta uma interface gráfica simples, permitindo ao usuário selecionar a opção que seja mais adequada, através do teclado.
O algoritmo facilita a inserção de dados em 2 softwares utilizados no INPE:

1. SGEMS (http://sgems.sourceforge.net/?q=node/77)
2. Octave (https://www.gnu.org/software/octave/)

Enjoy!

Hollweg

