# Controle de Servomotor por PWM - Raspberry Pi Pico W

## Descrição
Este projeto implementa o controle de um **servomotor** utilizando **PWM** na **Raspberry Pi Pico W**. O código configura o **GPIO 22** para gerar um sinal PWM com **50Hz**, permitindo movimentar o servomotor entre **0°, 90° e 180°**, além de um movimento contínuo suave entre os extremos.

## Como Executar
1. Configure o **Pico SDK** corretamente.
2. Compile e envie o código para a **Raspberry Pi Pico W**.
3. Conecte o servomotor ao **GPIO 22**.
4. Execute o código e observe a movimentação do servo.

## Observação com LED (Questão 6)
Quando o **GPIO 12** foi utilizado para controlar um **LED RGB**, o comportamento observado foi:
- O LED acendeu com **máxima intensidade** inicialmente e permaneceu assim por **5 segundos**.
- A intensidade foi **reduzida** para um nível intermediário por **5 segundos**.
- Em seguida, a luminosidade foi **diminuída ao mínimo**.
- Após isso, o LED passou a **oscilar continuamente**, aumentando e diminuindo sua intensidade de maneira suave.

Isso demonstra que a variação do **duty cycle do PWM** influencia diretamente a **intensidade luminosa do LED**, confirmando o uso do PWM tanto para **controle de motores** quanto para **ajuste de brilho** em LEDs.

## Autor
Por **Kalel Ezveither**.

## Video de teste
https://drive.google.com/file/d/17EWOPOg9eetnLfSVZZ-xQUgv1h0XDxSd/view?usp=sharing
https://drive.google.com/file/d/17EWOPOg9eetnLfSVZZ-xQUgv1h0XDxSd/view?usp=sharing
