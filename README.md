# Desafio do Sertão

Jogo de perguntas e respostas em C, no terminal, com o Nordeste como tema. O jogador responde cinco perguntas sobre cultura e geografia da região. Cada acerto vale dez pontos, e a pontuação máxima é cinquenta. Ao terminar, o jogo mostra o resultado e o salva em um arquivo de texto.

## Arquivos

- `main.c`: código-fonte do jogo.
- `historia.txt`: introdução e instruções, lidas quando uma partida começa.
- `ranking.txt`: criado pelo jogo para guardar nome, acertos e pontos de cada partida. Os resultados são acrescentados sem apagar os anteriores.

## Como compilar

Esta versão foi feita para **Windows**, pois usa `system("cls")` para limpar a tela e `system("pause")` para esperar uma tecla. É necessário ter um compilador C instalado, como o GCC/MinGW.

### Pelo terminal

Abra o PowerShell ou o Prompt de Comando na pasta que contém `main.c` e `historia.txt` e compile:

```bash
gcc -std=c99 -Wall -Wextra main.c -o desafio.exe
```

No PowerShell, execute:

```powershell
.\desafio.exe
```

No Prompt de Comando:

```bat
desafio.exe
```

Execute a partir dessa pasta para que o jogo encontre `historia.txt` e grave `ranking.txt` nela. O GCC precisa estar disponível no terminal para usar o comando acima.

### Pelo Code::Blocks

1. Crie um projeto em **File > New > Project > Console application** e escolha **C** e o compilador **GNU GCC Compiler**.
2. Substitua o `main.c` do projeto pelo deste repositório.
3. Copie `historia.txt` para a pasta do projeto, junto do arquivo `.cbp`.
4. Em **Project > Build options > Compiler settings > Other compiler options**, adicione `-std=c99` para permitir a declaração de `int i` no `for`.
5. Confira em **Project > Properties > Build targets > Execution working dir** se a pasta de execução é a que contém `historia.txt`.
6. Pressione **F9 (Build and Run)** para compilar e executar.

O Code::Blocks precisa estar com o GCC instalado e configurado. O arquivo `historia.txt` deve existir na pasta de execução antes de começar a partida.

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
