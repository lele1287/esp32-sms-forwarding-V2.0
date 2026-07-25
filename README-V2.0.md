# ESP32 SMS Forwarding V2.0

修改内容:
- SIM号码查询不再阻塞短信转发
- 增加后台SIM号码管理
- 增加API /api/sim/write
- 支持 AT+CPBS="ON" 和 AT+CPBW=1,"号码" 手动写入
- 无本机号码时短信仍正常转发
