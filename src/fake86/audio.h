/*
  Fake86: A portable, open-source 8086 PC emulator.
  Copyright (C)2010-2012 Mike Chambers

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#pragma once
#include "types.h"

struct wav_hdr_s {
	uint8_t	RIFF[4];	/* RIFF Header	  */ //Magic header
	uint32_t ChunkSize;	  /* RIFF Chunk Size  */
	uint8_t	WAVE[4];	/* WAVE Header	  */
	uint8_t	fmt[4];	 /* FMT header	   */
	uint32_t Subchunk1Size;  /* Size of the fmt chunk				*/
	uint16_t AudioFormat;	/* Audio format 1=PCM,6=mulaw,7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM */
	uint16_t NumOfChan;	  /* Number of channels 1=Mono 2=Sterio		   */
	uint32_t SamplesPerSec;  /* Sampling Frequency in Hz				 */
	uint32_t bytesPerSec;	/* bytes per second */
	uint16_t blockAlign;	 /* 2=16-bit mono, 4=16-bit stereo */
	uint16_t bitsPerSample;  /* Number of bits per sample	  */
	uint8_t	Subchunk2ID[4]; /* "data"  string   */
	uint32_t Subchunk2Size;  /* Sampled data length	*/
};

extern uint8_t speakerenabled;
