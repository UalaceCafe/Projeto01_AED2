# "API" dos dados

1) Deve-se criar um vetor do tipo certo e com tamanho suficiente para acomodar o número de dados necessários
- ```c
  info contacts[DATA1_SIZE] = {};
  ```
  - `info` é o tipo do vetor, definido em `include\csv.h` como uma estrutura capaz de armazenar duas string: `name` para o nome do contato e `phone` para o telefone do mesmo.

  - `DATA1_SIZE` foi definido no arquivo `main.c` como sendo o valor 100. `DATA2_SIZE` e `DATA3_SIZE` são 500 e 1000, respectivamente.

  - a parte ` = {}` é opcional, serve apenas para zerar o vetor (i.e. "remover" o lixo e deixar todos os campos "vazios").

2) Popula-se o vetor de estruturas com os dados de um arquivo usando a função `populate_array()`
- ```c
  populate_array("data/data_100.csv", contacts, DATA1_SIZE);
  ```
  - o primeiro argumento é o caminho para o arquivo + seu nome.
  - o segundo argumento é o vetor onde deseja-se salvar os dados do arquivo.
  - o terceiro argumento é o tamanho deste mesmo vetor.

3) Depois de populado, pode-se acessar facilmente os elementos do vetor com `nome_do_vetor[índice].atributo`, onde, como mencionado anteriomente, `atributo` pode ser tanto `name` ou `phone`. Por exemplo:
- ```c
  contacts[i].name
  ```
  ou
  ```c
  contacts[i].phone
  ```

# Como executar

* Compile no terminal com o comando `gcc lib/sort.c lib/csv.c main.c -o main`
* Execute com `.\main` ou `main.exe`