#include <iostream>

#include <plugincommon.h>
#include <subhook.h>

extern void* pAMXFunctions;

void logprintf(char* fmt, ...) {
    // todo: format output
    std::cout << fmt << std::endl;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
    void* ptr = ppData[PLUGIN_DATA_LOGPRINTF];
    subhook_new(ptr, (void *)logprintf, (subhook_options_t)0);

    return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}
