# Minimal Example ESP32 W5500 AsyncWebServer
A basic example of an Asynchronous WebServer using Ethernet interface with W5500 module.

## Bibliotecas utilizadas:
- ESPAsyncWebServer, by mathieucarbou: [github.com/mathieucarbou/ESPAsyncWebServer](https://github.com/mathieucarbou/ESPAsyncWebServer)

## Instruções:
1. Faça o download deste exemplo (ou git clone);
2. Abra este exemplo no VS Code (necessário ter o [PlatformIO](https://platformio.org/install/ide?install=vscode) instalado);
3. Faça o uplaod para a placa ESP32;
4. Abra o monitor Serial e procure o IP da placa gerado servidor DHCP do roteador da sua rede;
5. No seu navegador de internet, acesse o IP da placa ESP32.

## Exemplo de saída da Serial
```
ETH Started
hostname: ESP32 123
mac: 00:00:00:00:00:00
ETH Connected
ETH got IP: 192.167.0.152
```

## Exemplo de acesso no navegador
![image](https://github.com/user-attachments/assets/2427c95e-8518-4bd4-9a3f-16b1a9b3c5a9)
