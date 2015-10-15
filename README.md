# Desafio Griaule

O Desafio Griaule é uma competição realizada na Unicamp, na qual os alunos devem utilizar as ferramentas de computação forense da Griuale para solucionar um crime hipotético. Um de nossos estagiários desenvolveu este sample para ajudar nesta missão.

Infelizmente, ele ainda precisava estudar pra prova de MC202 dele - já era a segunda vez que ele cursava essa matéria - e, por falta de tempo, alguns defeitos no desenvolvimento passaram despercebidos, como leaks de memória e código redundante.

Se você encontrar algum desses erros, faça um fork do projeto e corrija-o!


## Compilando

### **Windows (Visual Studio 2010+)**

Apenas compile o projeto normalmente.

### **Linux (g++)**

> **:warning: Esse projeto só foi testado em CentOS 6.4.**

Para a compilação, é necessário a instalação da biblioteca `libpng-devel`:


```
apt-get install linpng-devel
```
ou
```
yum install libpng-devel
```

Depois basta executar a tarefa do `Makefile` apropriada:

```
make <arch>
```

Onde `<arch>` é `x86` ou `x64`, dependendo do arquitetura do seu sistema operacional.

## Executando

Para executar o sample, siga os seguintes passos:

1. Certifique-se de que as dependencias necessárias estejam devidamente visíveis.
	- **Windows**: O caminho para `GBSFingerprint.dll`, `opencv_core249.dll` e `opencv_ml249.dll` deve estar em `PATH`.
	- **Linux**: O caminho para `GBSFingerprint.so` deve estar em `LD_LIBRARY_PATH`. Também são necessárias outras dependências. Para obter uma lista completa e saber quais não estão presentes, execute o commando `ldd desafio-griaule`. Utilize seu gerenciador de pacotes predileto (`yum`, `apt-get`, etc.) para instalá-las.
2. Certifique-se de que tanto o banco de suspeitos quanto o de digitais encontradas na cena do crime estejam em uma pasta conhecida.
3. Execute o sample: `./desafio-griaule <databaseDir> <suspectsDir>`.