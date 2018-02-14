/* FAudio - XAudio Reimplementation for FNA
 * Copyright 2009-2018 Ethan Lee and the MonoGame Team
 *
 * Released under the Microsoft Public License.
 * See LICENSE for details.
 */

#ifndef FACT3D_H
#define FACT3D_H

#include "F3DAudio.h"
#include "FACT.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Constants */

#define LEFT_AZIMUTH			(3.0f * F3DAUDIO_PI / 2.0f)
#define RIGHT_AZIMUTH			(F3DAUDIO_PI / 2.0f)
#define FRONT_LEFT_AZIMUTH		(7.0f * F3DAUDIO_PI / 4.0f)
#define FRONT_RIGHT_AZIMUTH		(F3DAUDIO_PI / 4.0f)
#define FRONT_CENTER_AZIMUTH		0.0f
#define LOW_FREQUENCY_AZIMUTH		F3DAUDIO_2PI
#define BACK_LEFT_AZIMUTH		(5.0f * F3DAUDIO_PI / 4.0f)
#define BACK_RIGHT_AZIMUTH		(3.0f * F3DAUDIO_PI / 4.0f)
#define BACK_CENTER_AZIMUTH		F3DAUDIO_PI
#define FRONT_LEFT_OF_CENTER_AZIMUTH	(15.0f * F3DAUDIO_PI / 8.0f)
#define FRONT_RIGHT_OF_CENTER_AZIMUTH	(F3DAUDIO_PI / 8.0f)

static const float aStereoLayout[] =
{
	LEFT_AZIMUTH,
	RIGHT_AZIMUTH
};
static const float a2Point1Layout[] =
{
	LEFT_AZIMUTH,
	RIGHT_AZIMUTH,
	LOW_FREQUENCY_AZIMUTH
};
static const float aQuadLayout[] =
{
	FRONT_LEFT_AZIMUTH,
	FRONT_RIGHT_AZIMUTH,
	BACK_LEFT_AZIMUTH,
	BACK_RIGHT_AZIMUTH
};
static const float a4Point1Layout[] =
{
	FRONT_LEFT_AZIMUTH,
	FRONT_RIGHT_AZIMUTH,
	LOW_FREQUENCY_AZIMUTH,
	BACK_LEFT_AZIMUTH,
	BACK_RIGHT_AZIMUTH
};
static const float a5Point1Layout[] =
{
	FRONT_LEFT_AZIMUTH,
	FRONT_RIGHT_AZIMUTH,
	FRONT_CENTER_AZIMUTH,
	LOW_FREQUENCY_AZIMUTH,
	BACK_LEFT_AZIMUTH,
	BACK_RIGHT_AZIMUTH
};
static const float a7Point1Layout[] =
{
	FRONT_LEFT_AZIMUTH,
	FRONT_RIGHT_AZIMUTH,
	FRONT_CENTER_AZIMUTH,
	LOW_FREQUENCY_AZIMUTH,
	BACK_LEFT_AZIMUTH,
	BACK_RIGHT_AZIMUTH,
	LEFT_AZIMUTH,
	RIGHT_AZIMUTH
};

/* Functions */

FACTAPI uint32_t FACT3DInitialize(
	FACTAudioEngine *pEngine,
	F3DAUDIO_HANDLE F3DInstance
);

FACTAPI uint32_t FACT3DCalculate(
	F3DAUDIO_HANDLE F3DInstance,
	const F3DAUDIO_LISTENER *pListener,
	F3DAUDIO_EMITTER *pEmitter,
	F3DAUDIO_DSP_SETTINGS *pDSPSettings
);

FACTAPI uint32_t FACT3DApply(
	F3DAUDIO_DSP_SETTINGS *pDSPSettings,
	FACTCue *pCue
);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* FACT3D_H */
