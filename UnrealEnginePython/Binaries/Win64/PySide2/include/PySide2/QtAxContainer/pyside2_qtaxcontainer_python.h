/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of PySide2.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/


#ifndef SBK_QTAXCONTAINER_PYTHON_H
#define SBK_QTAXCONTAINER_PYTHON_H

#include <sbkpython.h>
#include <sbkconverter.h>
#include <sbkenum.h>
#include <basewrapper.h>
#include <bindingmanager.h>
#include <memory>

#include <pysidesignal.h>
// Module Includes
#include <pyside2_qtwidgets_python.h>
#include <pyside2_qtgui_python.h>
#include <pyside2_qtcore_python.h>

// Binded library includes
#include <qaxobject.h>
#include <qaxbase.h>
#include <qaxselect.h>
#include <qaxwidget.h>
#include <qaxscript.h>
// Conversion Includes - Primitive Types
#include <QString>
#include <QStringList>
#include <qabstractitemmodel.h>
#include <signalmanager.h>
#include <wtypes.h>

// Conversion Includes - Container Types
#include <QMultiMap>
#include <QList>
#include <QQueue>
#include <QMap>
#include <pysideqflags.h>
#include <QSet>
#include <QLinkedList>
#include <QVector>
#include <QStack>
#include <QPair>

// Type indices
#define SBK_QAXBASE_IDX                                              0
#define SBK_QAXOBJECT_IDX                                            1
#define SBK_QAXSCRIPTENGINE_IDX                                      4
#define SBK_QAXWIDGET_IDX                                            7
#define SBK_QAXSELECT_IDX                                            6
#define SBK_QAXSCRIPT_IDX                                            2
#define SBK_QAXSCRIPT_FUNCTIONFLAGS_IDX                              3
#define SBK_QAXSCRIPTMANAGER_IDX                                     5
#define SBK_QtAxContainer_IDX_COUNT                                  8

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_QtAxContainerTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_QtAxContainerTypeConverters;

// Converter indices
#define SBK_QTAXCONTAINER_QLIST_QVARIANT_IDX                         0 // QList<QVariant >
#define SBK_QTAXCONTAINER_QMAP_QSTRING_QVARIANT_IDX                  1 // QMap<QString,QVariant >
#define SBK_QTAXCONTAINER_QLIST_QOBJECTPTR_IDX                       2 // const QList<QObject* > &
#define SBK_QTAXCONTAINER_QLIST_QBYTEARRAY_IDX                       3 // QList<QByteArray >
#define SBK_QTAXCONTAINER_QLIST_QACTIONPTR_IDX                       4 // QList<QAction* >
#define SBK_QTAXCONTAINER_QLIST_QSTRING_IDX                          5 // QList<QString >
#define SBK_QtAxContainer_CONVERTERS_IDX_COUNT                       6

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::QAxBase >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtAxContainerTypes[SBK_QAXBASE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAxObject >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtAxContainerTypes[SBK_QAXOBJECT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAxScriptEngine >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtAxContainerTypes[SBK_QAXSCRIPTENGINE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAxWidget >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtAxContainerTypes[SBK_QAXWIDGET_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAxSelect >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtAxContainerTypes[SBK_QAXSELECT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAxScript::FunctionFlags >() { return SbkPySide2_QtAxContainerTypes[SBK_QAXSCRIPT_FUNCTIONFLAGS_IDX]; }
template<> inline PyTypeObject* SbkType< ::QAxScript >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtAxContainerTypes[SBK_QAXSCRIPT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAxScriptManager >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtAxContainerTypes[SBK_QAXSCRIPTMANAGER_IDX]); }

} // namespace Shiboken

#endif // SBK_QTAXCONTAINER_PYTHON_H

