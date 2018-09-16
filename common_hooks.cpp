#include <modloader/statichook.h>
#include <modloader/loader.h>
#include <dlfcn.h>

using namespace modloader;

class ServerInstance;

// ServerInstance::startServerThread() => modloader_on_server_start(ServerInstance*)

TClasslessInstanceHook(void, _ZN14ServerInstance17startServerThreadEv) {
  ModLoader::forEachMod([this](void *v) {
    void* func = dlsym(v, "modloader_on_server_start");
    if (func != nullptr)
      ((void (*)(void*)) func)(this);
  });
  original(this);
}
