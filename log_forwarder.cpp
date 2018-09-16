#include <modloader/statichook.h>
#include <modloader/log.h>
#include <string>
#include <cstdarg>

using namespace modloader;

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
