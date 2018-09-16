#include <modloader/statichook.h>
#include <modloader/log.h>
#include <modloader/loader.h>
#include <string>
#include <cstring>
#include <cstdarg>
#include <link.h>
#include <dlfcn.h>

using namespace modloader;

THook(std::string, _ZN6Common22getServerVersionStringB5cxx11Ev) {
  std::string ret = original();
  ret += " modded (ModLoader ";
  ret += ModLoader::getVersion();
  bool f = true;
  ModLoader::forEachMod([&ret, &f](void *v) {
    struct link_map *ent;
    if (dlinfo(v, RTLD_DI_LINKMAP, &ent) == 0 && ent != nullptr && ent->l_name != nullptr) {
      if (!f)
        ret += ", ";
      else
        ret += ", mods: ";
      f = false;
      ret += basename(ent->l_name);
    }
  });
  ret += ")";
  return ret;
}

class BedrockLog {
public:
  static const char* _areaFilterString(unsigned int);
};
TStaticHook(void, _ZN10BedrockLog7_log_vaEjjPKciS1_P13__va_list_tag, BedrockLog, unsigned int area, unsigned int level, char const* tag, int tid, char const* format, va_list args) {
  Log::LogLevel ourLevel = MODLOADER_LOG_ERROR;
  if (level == 1)
    ourLevel = MODLOADER_LOG_TRACE;
  if (level == 2)
    ourLevel = MODLOADER_LOG_INFO;
  if (level == 4)
    ourLevel = MODLOADER_LOG_WARN;
  if (level == 8)
    ourLevel = MODLOADER_LOG_ERROR;
  std::string ourTag = _areaFilterString(area);
  ourTag += '/';
  ourTag += tag;
  Log::vlog(ourLevel, ourTag.c_str(), format, args);
}
