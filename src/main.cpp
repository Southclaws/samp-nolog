#include <sys/mman.h>
#include <unistd.h>

#include "main.hpp"
#include <plugincommon.h>

extern void* pAMXFunctions;


PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
    void* plogprintf = ppData[PLUGIN_DATA_LOGPRINTF];
    uint32_t offset = ((uint32_t)plogprintf + 0x3B) / getpagesize();

    mprotect((void*)(offset * getpagesize()), 1, PROT_READ | PROT_WRITE | PROT_EXEC);

    *(unsigned char*)(plogprintf + 0x3B) = 0x75;

    return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES | SUPPORTS_PROCESS_TICK;
}
