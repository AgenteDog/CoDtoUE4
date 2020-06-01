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


#ifndef SBK_QTDATAVISUALIZATION_PYTHON_H
#define SBK_QTDATAVISUALIZATION_PYTHON_H

#include <sbkpython.h>
#include <sbkconverter.h>
#include <sbkenum.h>
#include <basewrapper.h>
#include <bindingmanager.h>
#include <memory>

#include <pysidesignal.h>
// Module Includes
#include <pyside2_qtgui_python.h>
#include <pyside2_qtcore_python.h>

// Binded library includes
#include <q3dinputhandler.h>
#include <qcustom3ditem.h>
#include <qcustom3dvolume.h>
#include <qheightmapsurfacedataproxy.h>
#include <qscatterdataproxy.h>
#include <qcategory3daxis.h>
#include <qbar3dseries.h>
#include <qabstract3dgraph.h>
#include <qcustom3dlabel.h>
#include <qsurface3dseries.h>
#include <qabstract3dinputhandler.h>
#include <qtouch3dinputhandler.h>
#include <qscatter3dseries.h>
#include <q3dtheme.h>
#include <q3dlight.h>
#include <q3dscene.h>
#include <q3dbars.h>
#include <qitemmodelsurfacedataproxy.h>
#include <q3dcamera.h>
#include <q3dscatter.h>
#include <q3dobject.h>
#include <qabstract3dseries.h>
#include <qvalue3daxis.h>
#include <q3dsurface.h>
#include <qitemmodelscatterdataproxy.h>
#include <qbardataitem.h>
#include <qabstractdataproxy.h>
#include <qbardataproxy.h>
#include <qsurfacedataitem.h>
#include <qscatterdataitem.h>
#include <qsurfacedataproxy.h>
#include <qvalue3daxisformatter.h>
#include <qlogvalue3daxisformatter.h>
#include <qabstract3daxis.h>
#include <qitemmodelbardataproxy.h>
// Conversion Includes - Primitive Types
#include <wtypes.h>
#include <qbardataproxy.h>
#include <qsurfacedataproxy.h>
#include <qabstractitemmodel.h>
#include <QString>
#include <signalmanager.h>
#include <QStringList>

// Conversion Includes - Container Types
#include <QMultiMap>
#include <QSet>
#include <QMap>
#include <QVector>
#include <pysideqflags.h>
#include <QQueue>
#include <QLinkedList>
#include <QPair>
#include <QList>
#include <QStack>

// Type indices
#define SBK_QTDATAVISUALIZATION_IDX                                  3
#define SBK_QTDATAVISUALIZATION_QSURFACEDATAITEM_IDX                 50
#define SBK_QTDATAVISUALIZATION_QSCATTERDATAITEM_IDX                 46
#define SBK_QTDATAVISUALIZATION_QBARDATAITEM_IDX                     32
#define SBK_QTDATAVISUALIZATION_Q3DOBJECT_IDX                        9
#define SBK_QTDATAVISUALIZATION_Q3DLIGHT_IDX                         8
#define SBK_QTDATAVISUALIZATION_Q3DCAMERA_IDX                        5
#define SBK_QTDATAVISUALIZATION_Q3DCAMERA_CAMERAPRESET_IDX           6
#define SBK_QTDATAVISUALIZATION_Q3DTHEME_IDX                         13
#define SBK_QTDATAVISUALIZATION_Q3DTHEME_COLORSTYLE_IDX              14
#define SBK_QTDATAVISUALIZATION_Q3DTHEME_THEME_IDX                   15
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DINPUTHANDLER_IDX          24
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DINPUTHANDLER_INPUTVIEW_IDX 25
#define SBK_QTDATAVISUALIZATION_Q3DINPUTHANDLER_IDX                  7
#define SBK_QTDATAVISUALIZATION_QTOUCH3DINPUTHANDLER_IDX             52
#define SBK_QTDATAVISUALIZATION_Q3DSCENE_IDX                         11
#define SBK_QTDATAVISUALIZATION_QCUSTOM3DITEM_IDX                    35
#define SBK_QTDATAVISUALIZATION_QCUSTOM3DVOLUME_IDX                  37
#define SBK_QTDATAVISUALIZATION_QCUSTOM3DLABEL_IDX                   36
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_IDX                 19
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_SELECTIONFLAG_IDX   22
#define SBK_QFLAGS_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_SELECTIONFLAG__IDX 1
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_SHADOWQUALITY_IDX   23
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_ELEMENTTYPE_IDX     20
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_OPTIMIZATIONHINT_IDX 21
#define SBK_QFLAGS_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_OPTIMIZATIONHINT__IDX 0
#define SBK_QTDATAVISUALIZATION_Q3DSURFACE_IDX                       12
#define SBK_QTDATAVISUALIZATION_Q3DBARS_IDX                          4
#define SBK_QTDATAVISUALIZATION_Q3DSCATTER_IDX                       10
#define SBK_QTDATAVISUALIZATION_QVALUE3DAXISFORMATTER_IDX            54
#define SBK_QTDATAVISUALIZATION_QLOGVALUE3DAXISFORMATTER_IDX         44
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DAXIS_IDX                  16
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DAXIS_AXISORIENTATION_IDX  17
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DAXIS_AXISTYPE_IDX         18
#define SBK_QTDATAVISUALIZATION_QVALUE3DAXIS_IDX                     53
#define SBK_QTDATAVISUALIZATION_QCATEGORY3DAXIS_IDX                  34
#define SBK_QTDATAVISUALIZATION_QABSTRACTDATAPROXY_IDX               29
#define SBK_QTDATAVISUALIZATION_QABSTRACTDATAPROXY_DATATYPE_IDX      30
#define SBK_QTDATAVISUALIZATION_QSURFACEDATAPROXY_IDX                51
#define SBK_QTDATAVISUALIZATION_QHEIGHTMAPSURFACEDATAPROXY_IDX       38
#define SBK_QTDATAVISUALIZATION_QITEMMODELSURFACEDATAPROXY_IDX       42
#define SBK_QTDATAVISUALIZATION_QITEMMODELSURFACEDATAPROXY_MULTIMATCHBEHAVIOR_IDX 43
#define SBK_QTDATAVISUALIZATION_QBARDATAPROXY_IDX                    33
#define SBK_QTDATAVISUALIZATION_QITEMMODELBARDATAPROXY_IDX           39
#define SBK_QTDATAVISUALIZATION_QITEMMODELBARDATAPROXY_MULTIMATCHBEHAVIOR_IDX 40
#define SBK_QTDATAVISUALIZATION_QSCATTERDATAPROXY_IDX                47
#define SBK_QTDATAVISUALIZATION_QITEMMODELSCATTERDATAPROXY_IDX       41
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DSERIES_IDX                26
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DSERIES_SERIESTYPE_IDX     28
#define SBK_QTDATAVISUALIZATION_QABSTRACT3DSERIES_MESH_IDX           27
#define SBK_QTDATAVISUALIZATION_QSURFACE3DSERIES_IDX                 48
#define SBK_QTDATAVISUALIZATION_QSURFACE3DSERIES_DRAWFLAG_IDX        49
#define SBK_QFLAGS_QTDATAVISUALIZATION_QSURFACE3DSERIES_DRAWFLAG__IDX 2
#define SBK_QTDATAVISUALIZATION_QBAR3DSERIES_IDX                     31
#define SBK_QTDATAVISUALIZATION_QSCATTER3DSERIES_IDX                 45
#define SBK_QtDataVisualization_IDX_COUNT                            55

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_QtDataVisualizationTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_QtDataVisualizationTypeConverters;

// Converter indices
#define SBK_QTDATAVISUALIZATION_QBARDATAARRAY_IDX                    0
#define SBK_QTDATAVISUALIZATION_QSURFACEDATAARRAY_IDX                1
#define SBK_QTDATAVISUALIZATION_QLIST_QOBJECTPTR_IDX                 2 // const QList<QObject* > &
#define SBK_QTDATAVISUALIZATION_QLIST_QBYTEARRAY_IDX                 3 // QList<QByteArray >
#define SBK_QTDATAVISUALIZATION_QVECTOR_UCHAR_IDX                    4 // QVector<uchar > *
#define SBK_QTDATAVISUALIZATION_QVECTOR_UNSIGNEDINT_IDX              5 // const QVector<unsigned int > &
#define SBK_QTDATAVISUALIZATION_QVECTOR_QIMAGEPTR_IDX                6 // const QVector<QImage* > &
#define SBK_QTDATAVISUALIZATION_QVECTOR_QTDATAVISUALIZATION_QSCATTERDATAITEM_IDX 7 // const QVector<QtDataVisualization::QScatterDataItem > &
#define SBK_QTDATAVISUALIZATION_QVECTOR_QTDATAVISUALIZATION_QBARDATAITEM_IDX 8 // const QVector<QtDataVisualization::QBarDataItem > *
#define SBK_QTDATAVISUALIZATION_QVECTOR_FLOAT_IDX                    9 // QVector<float > &
#define SBK_QTDATAVISUALIZATION_QLIST_QTDATAVISUALIZATION_QCUSTOM3DITEMPTR_IDX 10 // QList<QtDataVisualization::QCustom3DItem* >
#define SBK_QTDATAVISUALIZATION_QLIST_QTDATAVISUALIZATION_QABSTRACT3DINPUTHANDLERPTR_IDX 11 // QList<QtDataVisualization::QAbstract3DInputHandler* >
#define SBK_QTDATAVISUALIZATION_QLIST_QTDATAVISUALIZATION_Q3DTHEMEPTR_IDX 12 // QList<QtDataVisualization::Q3DTheme* >
#define SBK_QTDATAVISUALIZATION_QLIST_QTDATAVISUALIZATION_QABSTRACT3DAXISPTR_IDX 13 // QList<QtDataVisualization::QAbstract3DAxis* >
#define SBK_QTDATAVISUALIZATION_QLIST_QTDATAVISUALIZATION_QBAR3DSERIESPTR_IDX 14 // QList<QtDataVisualization::QBar3DSeries* >
#define SBK_QTDATAVISUALIZATION_QLIST_QTDATAVISUALIZATION_QVALUE3DAXISPTR_IDX 15 // QList<QtDataVisualization::QValue3DAxis* >
#define SBK_QTDATAVISUALIZATION_QLIST_QTDATAVISUALIZATION_QSCATTER3DSERIESPTR_IDX 16 // QList<QtDataVisualization::QScatter3DSeries* >
#define SBK_QTDATAVISUALIZATION_QLIST_QTDATAVISUALIZATION_QSURFACE3DSERIESPTR_IDX 17 // QList<QtDataVisualization::QSurface3DSeries* >
#define SBK_QTDATAVISUALIZATION_QLIST_QCOLOR_IDX                     18 // QList<QColor >
#define SBK_QTDATAVISUALIZATION_QLIST_QLINEARGRADIENT_IDX            19 // QList<QLinearGradient >
#define SBK_QTDATAVISUALIZATION_QLIST_QVARIANT_IDX                   20 // QList<QVariant >
#define SBK_QTDATAVISUALIZATION_QLIST_QSTRING_IDX                    21 // QList<QString >
#define SBK_QTDATAVISUALIZATION_QMAP_QSTRING_QVARIANT_IDX            22 // QMap<QString,QVariant >
#define SBK_QtDataVisualization_CONVERTERS_IDX_COUNT                 23

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QSurfaceDataItem >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QSURFACEDATAITEM_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QScatterDataItem >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QSCATTERDATAITEM_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QBarDataItem >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QBARDATAITEM_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::Q3DObject >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_Q3DOBJECT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::Q3DLight >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_Q3DLIGHT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::Q3DCamera::CameraPreset >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_Q3DCAMERA_CAMERAPRESET_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::Q3DCamera >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_Q3DCAMERA_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::Q3DTheme::ColorStyle >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_Q3DTHEME_COLORSTYLE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::Q3DTheme::Theme >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_Q3DTHEME_THEME_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::Q3DTheme >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_Q3DTHEME_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DInputHandler::InputView >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DINPUTHANDLER_INPUTVIEW_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DInputHandler >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DINPUTHANDLER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::Q3DInputHandler >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_Q3DINPUTHANDLER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QTouch3DInputHandler >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QTOUCH3DINPUTHANDLER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::Q3DScene >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_Q3DSCENE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QCustom3DItem >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QCUSTOM3DITEM_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QCustom3DVolume >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QCUSTOM3DVOLUME_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QCustom3DLabel >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QCUSTOM3DLABEL_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DGraph::SelectionFlag >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_SELECTIONFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QtDataVisualization::QAbstract3DGraph::SelectionFlag> >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QFLAGS_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_SELECTIONFLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DGraph::ShadowQuality >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_SHADOWQUALITY_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DGraph::ElementType >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_ELEMENTTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DGraph::OptimizationHint >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_OPTIMIZATIONHINT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QtDataVisualization::QAbstract3DGraph::OptimizationHint> >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QFLAGS_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_OPTIMIZATIONHINT__IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DGraph >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DGRAPH_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::Q3DSurface >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_Q3DSURFACE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::Q3DBars >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_Q3DBARS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::Q3DScatter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_Q3DSCATTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QValue3DAxisFormatter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QVALUE3DAXISFORMATTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QLogValue3DAxisFormatter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QLOGVALUE3DAXISFORMATTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DAxis::AxisOrientation >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DAXIS_AXISORIENTATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DAxis::AxisType >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DAXIS_AXISTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DAxis >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DAXIS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QValue3DAxis >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QVALUE3DAXIS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QCategory3DAxis >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QCATEGORY3DAXIS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstractDataProxy::DataType >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACTDATAPROXY_DATATYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstractDataProxy >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACTDATAPROXY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QSurfaceDataProxy >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QSURFACEDATAPROXY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QHeightMapSurfaceDataProxy >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QHEIGHTMAPSURFACEDATAPROXY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QItemModelSurfaceDataProxy::MultiMatchBehavior >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QITEMMODELSURFACEDATAPROXY_MULTIMATCHBEHAVIOR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QItemModelSurfaceDataProxy >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QITEMMODELSURFACEDATAPROXY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QBarDataProxy >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QBARDATAPROXY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QItemModelBarDataProxy::MultiMatchBehavior >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QITEMMODELBARDATAPROXY_MULTIMATCHBEHAVIOR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QItemModelBarDataProxy >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QITEMMODELBARDATAPROXY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QScatterDataProxy >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QSCATTERDATAPROXY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QItemModelScatterDataProxy >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QITEMMODELSCATTERDATAPROXY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DSeries::SeriesType >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DSERIES_SERIESTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DSeries::Mesh >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DSERIES_MESH_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QAbstract3DSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QABSTRACT3DSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QSurface3DSeries::DrawFlag >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QSURFACE3DSERIES_DRAWFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QtDataVisualization::QSurface3DSeries::DrawFlag> >() { return SbkPySide2_QtDataVisualizationTypes[SBK_QFLAGS_QTDATAVISUALIZATION_QSURFACE3DSERIES_DRAWFLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QSurface3DSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QSURFACE3DSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QBar3DSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QBAR3DSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtDataVisualization::QScatter3DSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtDataVisualizationTypes[SBK_QTDATAVISUALIZATION_QSCATTER3DSERIES_IDX]); }

} // namespace Shiboken

#endif // SBK_QTDATAVISUALIZATION_PYTHON_H

