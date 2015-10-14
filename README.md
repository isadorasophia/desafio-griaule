Desafio Griaule
===============

O Desafio Griaule é uma competição realizada na Unicamp, na qual os alunos devem utilizar as ferramentas de computação forense da Griuale para solucionar um crime hipotético. Um de nossos estagiários desenvolveu este sample para ajudar nesta missão.

Infelizmente, ele ainda precisava estudar pra prova de MC202 dele - já era a segunda vez que ele cursava essa matéria - e, por falta de tempo, alguns defeitos no desenvolvimento passaram despercebidos, como leaks de memória e código redundante.

Se você encontrar algum desses erros, faça um fork do projeto e corrija-o!


Compilando
----------

Para compilar o projeto, utilize o projeto do Visual Studio 2010 (Windows) ou o Makefile.


Executando
----------

Para executar o sample, siga os seguintes passos:

1. Certifique-se de que as dependencias necessárias (`GBSFingerprint.dll`, `opencv_core249.dll` e `opencv_ml249.dll` ou `GBSFingerprint.so`) estejam no path.
2. Certifique-se de que tanto o banco de suspeitos quanto o de digitais encontradas na cena do crime estejam em uma pasta conhecida.
3. Execute o sample: `./desafio-griaule <databaseDir> <suspectsDir>`.