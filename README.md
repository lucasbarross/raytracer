# Ray Tracer
Ray Tracer feito para a Disciplina de Processamento Gráfico, CIN UFPE 2018.2  
Grupo:  
- Lucas Barros (lbam)
- Lúcio Mota (lfmm2)
- Rafael Mota (rma7) 

## Features
O ray tracer consegue renderizar planos limitados (triângulos) e esferas.  
- Possui sombras.   
- Reflexão está incluida na branch reflection, mas não foi aperfeiçoada.   
- Refração não está incluída.  

## Arquivo de configuração

O ray tracer aceita arquivos de configuração em txt para manipular câmera, a imagem, a cena e seus objetos.
Para criar um arquivo de configuração, crie um .txt na pasta *tests* com o nome que quiser (esse nome será o nome do arquivo de imagem).

Um arquivo .txt de configuração aceita as tags:  
"#image"  
"#camera"  
"#light"  
"#scene"  
"#materials"  
"#objects"  

Em que a partir de cada tag, você especifica as configurações para tal elemento dessa tag utilizando pares de chaves e valores. Por exemplo, ao digitar a tag "#image" eu devo escrever, embaixo dessa tag, as configurações de width, height, e o R, G e B da cor do background.

#scene  
width=800  
height=600  
bgR=50  
bgG=50  
bgB=50  

Isso se repete para cada uma das outras tags, cujas chaves necessárias podem ser encontradas nos arquivos já existentes na pasta tests.

Cada material embaixo da tag #material possui uma chave "id", que identifica o material (cada id deve ser único para cada material).
Cada objeto embaixo da tag #objects possui uma tag "materialId", que possui como valor o id do material que o objeto irá utilizar e uma tag "type", que pode assumir o valor "2" ou "1". Caso o type seja "1", aquele objeto terá a geometria de esfera, enquanto se o type for "2", o objeto terá a geometria de triângulo. Para cada tipo desse, as chaves e valores necessárias para cada um, mudam.

Caso não tenha ficado claro como manipular o arquivo de configuração .txt, sugiro ver os exemplos contidos na pasta tests.

## Gerando a imagem

Para gerar a imagem, primeiro compile o código c++

> g++ src/main.cpp -o rt

e execute o executável gerado digitando o nome do arquivo .txt que irá configurar a imagem (que deve estar na pasta *tests*)

> ./rt configDefault

Quando o algoritmo terminar, sua imagem deve aparecer na pasta "images", onde estão todas as imagens para os .txt de exemplo.
