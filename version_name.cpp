#include <modloader/statichook.h>
#include <modloader/loader.h>
#include <string>
#include <cstring>
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
      const char* name = basename(ent->l_name);
      size_t namelen = strlen(name);
      if (namelen >= 3 && memcmp(&name[namelen - 3], ".so", 3) == 0) {
        namelen -= 3;
        if (namelen >= 3 && memcmp(name, "lib", 3) == 0) {
          name = &name[3];
          namelen -= 3;
        }
      }
      ret.append(name, namelen);
    }
  });
  ret += ")";
  return ret;
}
