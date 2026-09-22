# Source components (ESP8266-IDF pattern)

Each subfolder of `components/` is one source library:
- compiled with the project board flags (target + memory model must match — §3.3.7/§3.3.12);
- archived with `sdar -rc build/<name>.lib` (§3.2.5);
- linked after the application objects.

Component layout convention (optional):
   components/mylib/
     *.c            ← sources (auto-scanned as **/*.c)
     inc/           ← include dir (auto-added when present)

A component OUTSIDE `components/` (e.g. a vendor SDK) is declared as a
JSON object in the `components` array of sdcc-project.json:
   {"name":"stm8s_stdperiph","path":"vendor/STM8S_StdPeriph_Lib/...","pattern":"src/**/*.c","includes":["inc","../CMSIS/STM8S"]}
