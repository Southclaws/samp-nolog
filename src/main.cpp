#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

#include <plugincommon.h>
#include <subhook.h>

extern void* pAMXFunctions;

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
    uint32_t ptr = (uint32_t)ppData[PLUGIN_DATA_LOGPRINTF];
    subhook_new(ptr, nullptr, nullptr);
    // uint32_t offset = (ptr + 0x3B);

    // mprotect((void*)((offset / getpagesize()) * getpagesize()), 1, PROT_READ | PROT_WRITE | PROT_EXEC);

    // *(unsigned char*)offset = 0x75;

    return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES | SUPPORTS_PROCESS_TICK;
}
