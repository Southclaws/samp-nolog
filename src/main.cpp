/*==============================================================================


	SA:MP nolog

		Copyright (C) 2016 Barnaby "Southclaw" Keene

		This program is free software: you can redistribute it and/or modify it
		under the terms of the GNU General Public License as published by the
		Free Software Foundation, either version 3 of the License, or (at your
		option) any later version.

		This program is distributed in the hope that it will be useful, but
		WITHOUT ANY WARRANTY; without even the implied warranty of
		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
		See the GNU General Public License for more details.

		You should have received a copy of the GNU General Public License along
		with this program.  If not, see <http://www.gnu.org/licenses/>.


==============================================================================*/

#include <unistd.h> // pagesize
#include <sys/mman.h>
#include <sdk.hpp>
#include "main.hpp"

extern void *pAMXFunctions;
logprintf_t logprintf_fp;

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	void *plogprintf = ppData[PLUGIN_DATA_LOGPRINTF];
	mprotect((((uint32_t)plogprintf + 0x3B) / getpagesize()) * getpagesize(), 1, PROT_READ | PROT_WRITE | PROT_EXEC);
	*(unsigned char *)(plogprintf + 0x3B) = 0x75;

	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES | SUPPORTS_PROCESS_TICK;
}
