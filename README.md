# CoreMod

This mod provides some miscellaneous functionality for modding BDS, such as:
- the ability to use `modloader_on_server_start()`
- altering the server version to include list of loaded mods
- making the log format a bit less noisy and more useful

## Compiling from source
1. Get the SDK for the modloader from [`minecraft-linux/server-modloader` releases](https://github.com/minecraft-linux/server-modloader/releases).
2. Unzip it somewhere (let's say `~/bds-mod-workspace/sdk`)
3. In this repository, `mkdir build && cd build`
4. `cmake -DCMAKE_PREFIX_PATH=~/bds-mod-workspace/sdk ..`
5. `make`

Once done, you have a `libCoreMod.so` ready to go.
Read the instructions for [`server-modloader` README](https://github.com/minecraft-linux/server-modloader) for instructions how to use it.
