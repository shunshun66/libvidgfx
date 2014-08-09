//*****************************************************************************
// Libvidgfx: A graphics library for video compositing
//
// Copyright (C) 2014 Lucas Murray <lmurray@undefinedfire.com>
// All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//*****************************************************************************

#ifndef GFXLOG_H
#define GFXLOG_H

#include "libvidgfx.h"
#include <QtCore/QVector>

class GfxLogData;
class QPoint;
class QPointF;
class QRect;
class QRectF;
class QSize;
class QSizeF;

//=============================================================================
class GfxLog
{
public: // Datatypes ----------------------------------------------------------
	enum LogLevel {
		Notice = 0,
		Warning,
		Critical
	};

	typedef void CallbackFunc(
		const QString &cat, const QString &msg, LogLevel lvl);

protected: // Static members --------------------------------------------------
	static CallbackFunc *	s_callbackFunc;

public: // Members ------------------------------------------------------------
	GfxLogData *	d;

public: // Static methods -----------------------------------------------------
	LVG_EXPORT static void	setCallback(CallbackFunc *funcPtr);

public: // Constructor/destructor ---------------------------------------------
	GfxLog();
	GfxLog(const GfxLog &log);
	~GfxLog();
};
GfxLog operator<<(GfxLog log, const QString &msg);
GfxLog operator<<(GfxLog log, const QByteArray &msg);
GfxLog operator<<(GfxLog log, const char *msg);
GfxLog operator<<(GfxLog log, int msg);
GfxLog operator<<(GfxLog log, unsigned int msg);
GfxLog operator<<(GfxLog log, qint64 msg);
GfxLog operator<<(GfxLog log, quint64 msg);
GfxLog operator<<(GfxLog log, qreal msg);
GfxLog operator<<(GfxLog log, float msg);
GfxLog operator<<(GfxLog log, bool msg);
GfxLog operator<<(GfxLog log, const QPoint &msg);
GfxLog operator<<(GfxLog log, const QPointF &msg);
GfxLog operator<<(GfxLog log, const QRect &msg);
GfxLog operator<<(GfxLog log, const QRectF &msg);
GfxLog operator<<(GfxLog log, const QSize &msg);
GfxLog operator<<(GfxLog log, const QSizeF &msg);
GfxLog gfxLog(const QString &category, GfxLog::LogLevel lvl = GfxLog::Notice);
GfxLog gfxLog(GfxLog::LogLevel lvl = GfxLog::Notice);
//=============================================================================

inline void GfxLog::setCallback(CallbackFunc *funcPtr)
{
	s_callbackFunc = funcPtr;
}

#endif // GFXLOG_H
