// � 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_COLOR_TRANSFORM_ARGS_H_
#define _W_COLOR_TRANSFORM_ARGS_H_

#include "WDefines.h"
#include "WEventArgs.h"
#include "WDX.h"

class WColorTransformArgs : public WEventArgs
{
public:
	WColorTransformArgs(W_COLOR col);
	W_COLOR Value(void) const;

private:
	W_COLOR	m_Value;
};

#endif // !_W_COLOR_TRANSFORM_ARGS_H_
