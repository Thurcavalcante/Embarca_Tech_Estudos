O comando **picotool reboot -f -u** reinicia um dispositivo Raspberry Pi Pico em modo de programação USB.

- **picotool:** Ferramenta para interagir com o Pico.
- **reboot:** Indica que o dispositivo deve ser reiniciado.
- **-f:** Força o reinício, mesmo se o dispositivo estiver travado.
- **-u:** Prepara o dispositivo para comunicação via USB após o reinício.

Esse comando é útil para carregar novos programas ou atualizar o firmware.

```c
// Comando no terminal para BOOTSEL
picotool reboot -f -u
```