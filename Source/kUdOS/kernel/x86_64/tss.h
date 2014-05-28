/*
 * The task switch segment descriptor.
 *
 * Copyright (C) 2003-2014 Juha Aatrokoski, Timo Lilja,
 *   Leena Salmela, Teemu Takanen, Aleksi Virtanen,
 *   Philip Meulengracht.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 * 3. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id: tss.h,v 1.0 2003/07/22 19:51:28 philip Exp $
 *
 */

#ifndef __TSS_H__
#define __TSS_H__

/* Includes */
#include "lib/types.h"

/* Defines */
typedef struct tss
{
	/* Link to previous TSS */
	uint32_t prev_tss;

	/* Stacks and stack segments */
	uint64_t rsp_ring0;
	uint64_t rsp_ring1;
	uint64_t rsp_ring2;

	/* Reserved */
	uint64_t reserved0;

	/* IST */
	uint64_t ist[7];

	/* Reserved */
	uint64_t reserved1;
	uint16_t reserved2;

	/* IO Map */
	uint16_t io_map;

} tss_t;

/* Prototypes */
void tss_init(void);
void tss_install(int num_cpu, uint64_t cpu_stack);

/* Update stacks */
void tss_setstack(uint32_t cpu, uint64_t stack);
void tss_setuserstack(uint32_t cpu, uint64_t stack);


#endif