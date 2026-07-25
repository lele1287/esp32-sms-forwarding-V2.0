
#include "sim_write.h"
#include "sim/sim.h"
#include <ArduinoJson.h>

void simWriteController(AsyncWebServerRequest* request, uint8_t* data, size_t len, size_t index, size_t total) {
  String body;
  for(size_t i=0;i<len;i++) body += (char)data[i];

  JsonDocument doc;
  deserializeJson(doc, body);
  String phone = doc["phone"] | "";

  bool ok = Sim::writePhoneNumber(phone);

  AsyncResponseStream *res = request->beginResponseStream("application/json");
  res->print(ok ? "{\"code\":0,\"msg\":\"SIM号码写入成功\"}" :
                  "{\"code\":1,\"msg\":\"SIM号码写入失败\"}");
  request->send(res);
}
