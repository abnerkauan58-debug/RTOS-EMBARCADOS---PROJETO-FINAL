# Estação IoT Interativa com FreeRTOS e MQTT

## 📌 Visão Geral

Este projeto implementa uma **Estação IoT Interativa** utilizando a plataforma **Franzininho WiFi LAB01 / ESP32 com ESP-IDF**, integrando sensores ambientais, atuadores, interface local com usuário e comunicação em nuvem via **MQTT + Adafruit IO**.

O sistema realiza monitoramento contínuo de:

* 🌡️ Temperatura (DHT11)
* 💧 Umidade (DHT11)
* ☀️ Luminosidade (LDR)

Além disso:

* Publica dados em nuvem via MQTT
* Permite controle remoto de LED RGB
* Configura alarmes locais por teclado
* Exibe informações em display OLED
* Aciona buzzer automaticamente em condições críticas
* Registra logs de alarmes na memória flash (NVS)
* Disponibiliza consulta de logs via terminal serial

---

# 🎯 Objetivos do Projeto

Este projeto foi desenvolvido para consolidar conhecimentos em:

## Hardware:

* Sensores analógicos e digitais
* Display OLED (I2C)
* Teclado matricial
* LED RGB (PWM)
* Buzzer

## Firmware:

* ESP-IDF
* Modularização em componentes
* Drivers reutilizáveis
* Persistência com NVS

## FreeRTOS:

* Tasks
* Queues
* Semáforos
* Event Groups
* Timers

## IoT:

* WiFi STA
* MQTT
* Adafruit IO
* Publicação e assinatura de feeds
* Cloud monitoring

---

# 🧠 Arquitetura do Sistema

```text
Sensores (DHT11 + LDR)
        ↓
 Sensor Task (FreeRTOS)
        ↓ Queue
 Alarm Manager Task
   ↓      ↓      ↓
 OLED   Buzzer   NVS Logs
   ↓
 MQTT Publish Task
   ↓
 WiFi Manager
   ↓
 Adafruit IO Cloud
```

---

# ⚙️ Funcionalidades Implementadas

## 📡 Monitoramento de Sensores

* Leitura periódica de temperatura, umidade e luminosidade
* Processamento local dos dados
* Publicação automática no Adafruit IO

### Feeds MQTT sugeridos:

* `temperatura`
* `umidade`
* `luminosidade`
* `alarmes`

---

## 🎨 Controle de Atuadores

### LED RGB:

Controlado remotamente por comandos MQTT:

* `led_red`
* `led_green`
* `led_blue`

### Buzzer:

Acionado automaticamente quando:

* Temperatura excede limites
* Umidade excede limites
* Luminosidade excede limites

### Desligamento manual:

* Via teclado local

---

## 🖥️ Interface Local

### Display OLED:

Exibe:

* Status WiFi
* Status MQTT
* Temperatura
* Umidade
* Luminosidade
* Alarmes ativos
* Menus de configuração

### Exemplo:

```text
Temp: 28.4°C
Umid: 65%
Luz : 720
WiFi: OK
MQTT: OK
```

---

## ⌨️ Configuração por Teclado

Permite ajustar:

### Temperatura:

* Mínima
* Máxima

### Luminosidade:

* Mínima
* Máxima

### Umidade:

* Mínima
* Máxima

### Exemplo:

```text
Temp Max: 30°C
Temp Min: 20°C
Luz Max : 900
Luz Min : 100
Umid Max: 80%
Umid Min: 30%
```

---

# 🚨 Sistema de Alarmes

Quando qualquer parâmetro ultrapassa limites definidos:

### Ações:

* Buzzer ativado
* OLED exibe alerta
* Evento salvo em NVS
* Alarme enviado via MQTT

### Exemplo de log:

```text
2026-04-29 14:30:22 - TEMP_HIGH - 35.2°C
2026-04-29 14:32:10 - LIGHT_HIGH - 1050
```

---

# 💾 Armazenamento em NVS

## Utilizado para:

### Configurações persistentes:

* Limites de sensores
* Credenciais WiFi
* Estado do sistema

### Logs:

* Histórico de alarmes

---

# 🌐 Configuração WiFi

## Modo:

* Station (STA)

## Recursos:

* Conexão automática
* Reconexão automática
* Event Groups para status
* Semáforo para sincronização MQTT

---

# ☁️ Integração com Adafruit IO

## Utilizado para:

### Monitoramento:

* Dashboards gráficos
* Histórico remoto

### Controle:

* LED RGB remoto
* Recebimento de comandos

---

## Exemplo de feeds:

| Feed         | Função     |
| ------------ | ---------- |
| temperatura  | Publicação |
| umidade      | Publicação |
| luminosidade | Publicação |
| led_red      | Subscrição |
| led_green    | Subscrição |
| led_blue     | Subscrição |
| alarmes      | Publicação |

---

# 🗂️ Estrutura do Projeto

```text
/project_root
│
├── main/
│   └── main.c
│
├── components/
│   ├── wifi_manager/
│   ├── mqtt_manager/
│   ├── sensor_manager/
│   ├── oled_display/
│   ├── keypad_manager/
│   ├── alarm_manager/
│   ├── storage_manager/
│   ├── rgb_led/
│   └── buzzer/
│
├── README.md
└── docs/
    ├── hardware_diagram.png
    └── screenshots/
```

---

# 🛠️ Requisitos

## Hardware:

* Franzininho WiFi LAB01 / ESP32
* DHT11
* LDR
* OLED SSD1306
* Teclado matricial
* LED RGB
* Buzzer
* Resistores e jumpers

---

## Software:

* ESP-IDF
* FreeRTOS
* Adafruit IO Account
* MQTT Broker (Adafruit IO)
* Git

---

# 🔧 Instalação e Configuração

## 1. Clone o repositório

```bash
git clone <repositorio>
cd projeto_iot
```

---

## 2. Configure ESP-IDF

```bash
idf.py menuconfig
```

### Configure:

* SSID WiFi
* Senha WiFi
* Usuário Adafruit IO
* API Key
* Feeds MQTT

---

## 3. Compile

```bash
idf.py build
```

---

## 4. Grave na placa

```bash
idf.py flash monitor
```

---

# 📷 Demonstração Esperada

## Dashboard Adafruit IO:

* Temperatura em gráfico
* Umidade em gráfico
* Luminosidade em gráfico
* Controle remoto RGB

## OLED:

* Dados locais
* Alarmes
* Configuração

## Serial:

* Logs históricos
* Diagnóstico

---

# 📚 Conceitos Aplicados

## FreeRTOS:

* Multitarefa
* Sincronização
* Comunicação entre módulos

## Redes:

* WiFi STA
* MQTT
* Broker Cloud

## Sistemas Embarcados:

* Drivers
* Persistência
* Modularização
* Interface homem-máquina

---

# 🚀 Possíveis Melhorias Futuras

* HTTPS/TLS
* OTA Update
* App mobile
* BLE provisioning
* ESP-NOW
* Sensores adicionais
* Dashboard próprio

---

# 👨‍💻 Autor

**[Seu Nome]**
Projeto desenvolvido como parte da formação em:

* Hardware
* Firmware
* FreeRTOS
* IoT com ESP-IDF

---

# 📄 Licença

Este projeto é destinado a fins educacionais e de portfólio.

---

# ⭐ Destaque Profissional

Este projeto demonstra experiência prática em:

* Desenvolvimento embarcado
* Sistemas IoT
* Arquitetura modular
* Integração cloud
* FreeRTOS avançado
* Automação e monitoramento remoto
