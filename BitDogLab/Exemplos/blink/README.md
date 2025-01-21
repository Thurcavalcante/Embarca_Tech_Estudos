# Configurações do projeto

1. Ir na extensão CMake > Configure > Pico e selecionar a opção **Pico using compile**
![alt text](./img/image.png)

2. Compilação do projeto: Clique na extenssão do **Raspbarry Pi Pico**
- Selecione **Compile Project**, feito isso, ira compilar seu projeto e sera mostrado no terminal, após a compilação clique em qualquer tecla no terinal para fechalo.
![alt text](image.png)

- Voltando em explore (file), varios arquivos foram criados na pasta **build**, usaremos o que tem extensão `.uf2`, nesse caso do projeto blink, `blink.uf2`

- com o botão direito do mouse, encima do do arquivo `blink.uf2`, selecione a opção: `Reveal in File Explore`.

- Agora no explorador de arquivos, iremos enviar o arquivo do nosso projeto para a placa **BitDogLab**.

- Ative o modo `BOOTSET` da placa para carregar e gravar o código. 

- - Na parte de trás da placa, encima do `Raspbarry`, tem um botão, paperte ele por 3 segundos, e logo em seguinda, na parte da frontal da placa, aperte e segure o botão `Reset`. Com os os botões precionados, aguarde um pouco e solte o botão `Reset` e depois o `Bootsel`.

![alt text](./img/image03.png)

![alt text](./img/image04.png)

- - Após isso, aparecera um dispositivo novo no seu computado/notebook, parecido com um PenDrive, essa é a placa `BitDogLab`.

- - Arraste o arquivo com extensão `.uf2` para a placa para copiar e gravar nela.

- - Feito isso, o LED do raspbarry ira piscar, mostrando que o código foi gravado na placa.

![alt text](./img/image05.png)

3. Para editar o código:
- Mude o valor da velocidade do LED em `#define LED_DELAY_MS 100` de 250 para 100

- Clique em `Compile Project` para compilar mais uma vez o código 

- Feito a complilação, repita novamente o passo de gravação do arquivo para à placa.
- - `blink.uf2` > `Reveal in File Explore`, `Modo Bootsel`, Copie o arquivo para a 

- - Seu LED ira piscar mais rápido agora.