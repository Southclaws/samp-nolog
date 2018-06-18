#include <iostream>
#include <stdarg.h>
#include <cstdio>

#include <plugincommon.h>
#include <subhook.h>

subhook_t logprintf_hook;
extern void* pAMXFunctions;

void logprintf(char* format, ...) {
    va_list args;
    va_start(args, format);

    char buffer[512];
    vsprintf(buffer, format, args);

    va_end(args);

    std::cout << buffer << std::endl;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
    void* ptr = ppData[PLUGIN_DATA_LOGPRINTF];
    logprintf_hook = subhook_new(ptr, (void *)logprintf, (subhook_options_t)0);
    subhook_install(logprintf_hook);

    ::remove("server_log.txt");

    return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
    subhook_remove(logprintf_hook);
    subhook_free(logprintf_hook);
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}
