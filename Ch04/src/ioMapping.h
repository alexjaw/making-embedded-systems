#ifndef _IO_MAPPING_H
#define _IO_MAPPING_H

#if COMPILING_FOR_XPLAINED_XMEGA32E5
#include "ioMappingXplainedXMEGA32E5.h"
#elif TEST
#include "ioMappingTest.h"
#else
#error "No I/O map selected for the board. What is your target?"
#endif /* COMPILING_FOR_XPLAINED_XMEGA32E5 */
#endif /* _IO_MAPPING_H */

