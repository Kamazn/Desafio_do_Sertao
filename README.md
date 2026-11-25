# Desafio do Sertão

Jogo de perguntas e respostas em C, no terminal, com o Nordeste como tema. O jogador responde cinco perguntas sobre cultura e geografia da região. Cada acerto vale dez pontos, e a pontuação máxima é cinquenta. Ao terminar, o jogo mostra o resultado e o salva em um arquivo de texto.

## Arquivos

- `desafiosertao.c`: código-fonte do jogo.
- `historia.txt`: introdução e instruções, lidas quando uma partida começa.
- `ranking.txt`: criado pelo jogo para guardar nome, acertos e pontos de cada partida. Os resultados são acrescentados sem apagar os anteriores.

## Como compilar

É necessário ter um compilador C, como o GCC. Abra o terminal na pasta do projeto e execute:

```bash
gcc -std=c99 desafiosertao.c -o desafiosertao
```

No Windows:

```powershell
.\desafiosertao.exe
```

No Linux ou macOS:

```bash
./desafiosertao
```

Execute o jogo a partir da pasta que contém `historia.txt`. O arquivo `ranking.txt` será criado nessa mesma pasta.

As pausas e a limpeza da tela usam `pause` e `cls`, comandos do Windows. No Linux e no macOS, esses comandos não estão disponíveis por padrão; essa parte precisa de adaptação para funcionar como no Windows.

### Code::Blocks

1. Crie um projeto **Console application** em **C** e cole o conteúdo de `desafiosertao.c` no arquivo principal.
2. Coloque `historia.txt` na pasta do projeto.
3. Pressione **F9** para compilar e jogar.

## Como jogar

1. Escolha `1` no menu para jogar ou `0` para sair.
2. Digite o nome do jogador. O nome pode conter espaços.
3. Leia a introdução e pressione uma tecla para começar.
4. Digite `1`, `2` ou `3` para responder cada pergunta. Digite somente números nas opções do jogo.
5. Veja se acertou ou errou e pressione uma tecla para continuar. Números fora de 1 a 3 fazem a mesma pergunta ser repetida.
6. Depois das cinco perguntas, veja o total de acertos e a pontuação. O resultado é salvo automaticamente.

Cada acerto vale dez pontos; erros não somam pontos. Depois da partida, o menu aparece novamente, permitindo jogar outra vez.

Para consultar o histórico, abra `ranking.txt` no Code::Blocks ou no Bloco de Notas. Cada partida fica em um bloco com nome, acertos e pontos. Os registros seguem a ordem das partidas; não são ordenados por pontuação.

## Organização do código

A estrutura `Resultado` guarda acertos e pontos. A estrutura `Jogador` guarda o nome e um campo do tipo `Resultado`, formando uma struct aninhada.

As matrizes de caracteres `perguntas`, `alternativa1`, `alternativa2` e `alternativa3` guardam os textos. O vetor `respostas` guarda o número da alternativa correta de cada pergunta. As posições começam em zero.

As funções dividem as tarefas:

- `main()`: mostra o menu, recebe o nome e chama a partida.
- `iniciarPartida()`: zera o resultado, chama as cinco perguntas, soma os acertos e os pontos, mostra o resumo e chama o salvamento.
- `perguntar(int numero)`: recebe a posição de uma pergunta, mostra as alternativas e devolve `1` para acerto ou `0` para erro.
- `mostrarHistoria()`: abre `historia.txt`, lê o texto com `fgets` e o mostra na tela.
- `salvarResultado()`: acrescenta o resultado em `ranking.txt` com `fprintf`, no modo de abertura `"a"`.

## Conceitos de C utilizados

- Variáveis inteiras e textos.
- Matrizes bidimensionais de caracteres e vetor de inteiros.
- Estruturas (`struct`) e estruturas aninhadas.
- Funções com parâmetros e valores de retorno para separar as tarefas.
- Estruturas de decisão com `if` e `else`.
- Laços de repetição com `for`, `do/while` e `while`.
- Leitura de arquivo com `fopen`, `fgets` e `fclose`.
- Gravação de resultados com `fopen`, `fprintf` e `fclose`.
As duas funções de arquivo verificam se a abertura retornou `NULL`. Se houver falha, mostram uma mensagem e encerram a função antes de usar o arquivo.
