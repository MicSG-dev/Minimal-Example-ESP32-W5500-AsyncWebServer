#include <Arduino.h>
#include <SPI.h>
#include <ETH.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);

void handleRootRequest(AsyncWebServerRequest *request);
void onEvent(arduino_event_id_t event, arduino_event_info_t info);

void setup()
{
  Serial.begin(115200);
  Network.onEvent(onEvent);
  ETH.begin(ETH_PHY_TYPE, ETH_PHY_ADDR, ETH_PHY_CS, ETH_PHY_IRQ, ETH_PHY_RST, SPI2_HOST, ETH_PHY_SPI_SCK, ETH_PHY_SPI_MISO, ETH_PHY_SPI_MOSI);
  server.on("/", HTTP_GET, handleRootRequest);

  server.begin();
}

void loop()
{
}

void handleRootRequest(AsyncWebServerRequest *request)
{
  request->send(200, "text/plain", "Hello!");
}

void onEvent(arduino_event_id_t event, arduino_event_info_t info)
{
  switch (event)
  {
  case ARDUINO_EVENT_ETH_START:
  {
    Serial.println("ETH Started");
    const char *hostnameBoard = "ESP32 123";

    Serial.print("hostname: ");
    Serial.println(hostnameBoard);
    ETH.setHostname(hostnameBoard);

    Serial.print("mac: ");
    Serial.println(ETH.macAddress());

    break;
  }
  case ARDUINO_EVENT_ETH_CONNECTED:
  {
    Serial.println("ETH Connected");
    break;
  }
  case ARDUINO_EVENT_ETH_GOT_IP:

  {
    Serial.println("ETH got IP: " + ETH.localIP().toString());
    Serial.println("Web: http://" + ETH.localIP().toString());
    break;
  }
  case ARDUINO_EVENT_ETH_LOST_IP:
  {
    Serial.println("ETH Lost IP");
    break;
  }
  case ARDUINO_EVENT_ETH_DISCONNECTED:
  {
    Serial.println("ETH Disconnected");
    break;
  }
  case ARDUINO_EVENT_ETH_STOP:
  {
    Serial.println("ETH Stopped");
    break;
  }
  default:
  {
    break;
  }
  }
}