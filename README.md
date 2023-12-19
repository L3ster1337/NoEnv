# NoEnv

Este programa em C, destinado a ser utilizado em ambientes UNIX-like, fornece uma funcionalidade especial para a execução de comandos com argumentos que podem incluir representações hexadecimais. Abaixo está um resumo detalhado das suas características e funcionalidades:

## Visão Geral

O programa permite executar comandos fornecidos via linha de comando, onde os argumentos do comando podem incluir caracteres especiais representados por sequências de escape hexadecimal. É especialmente útil em situações onde é necessário passar caracteres que não podem ser facilmente digitados ou incluídos diretamente na linha de comando.
Funcionalidades
1. Conversão de Hexadecimal para Caractere

    Função is_valid_hex: Verifica se um dado caractere é um dígito hexadecimal válido (0-9, a-f, A-F) e converte-o em seu valor numérico correspondente.
    Função hex2byte: Converte um par de caracteres hexadecimais em um único byte, utilizando a função is_valid_hex.

2. Manipulação de Argumentos

    Função argvdup: Cria uma cópia modificada de uma string de argumento. Esta função detecta sequências de escape hexadecimal (como "\x20") e as converte para o caractere correspondente, permitindo a inclusão de caracteres especiais nos argumentos.

3. Execução de Comandos

    Função main: Processa os argumentos da linha de comando, aplica as modificações necessárias nos argumentos (exceto no primeiro, que é o nome do programa), e executa o comando especificado no primeiro argumento. O ambiente de execução é simplificado, contendo nenhuma variável de ambiente adicional.

## Uso

Para usar este programa, compile-o em um ambiente UNIX-like e execute-o passando o comando desejado e os argumentos como parâmetros. Os argumentos podem incluir sequências de escape hexadecimal para representar caracteres especiais.
Exemplo

`$ ./noenv "comando" "\x61rg1" "arg2"`

Neste exemplo, "\x61" será convertido para 'a', resultando no argumento "arg1".
Compilação

## Para compilar este programa, use um compilador C padrão, como gcc. O comando de compilação pode ser algo como:
``$ gcc noenv.c -o noenv``

### Notas

    Este programa é útil para testes e situações específicas de desenvolvimento.
    Deve ser usado com cautela, pois a execução de comandos de forma programática pode ter implicações de segurança.
