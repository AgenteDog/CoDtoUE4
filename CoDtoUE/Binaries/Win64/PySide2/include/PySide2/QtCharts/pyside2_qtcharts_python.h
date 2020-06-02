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


#ifndef SBK_QTCHARTS_PYTHON_H
#define SBK_QTCHARTS_PYTHON_H

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
#include <qbarcategoryaxis.h>
#include <qdatetimeaxis.h>
#include <qhorizontalstackedbarseries.h>
#include <qcandlestickseries.h>
#include <qcandlestickset.h>
#include <qboxplotseries.h>
#include <qpercentbarseries.h>
#include <qhpiemodelmapper.h>
#include <qxymodelmapper.h>
#include <qvxymodelmapper.h>
#include <qpolarchart.h>
#include <qhorizontalbarseries.h>
#include <qhcandlestickmodelmapper.h>
#include <qvalueaxis.h>
#include <qpieseries.h>
#include <qlegend.h>
#include <qboxplotmodelmapper.h>
#include <qareaseries.h>
#include <qlineseries.h>
#include <qvbarmodelmapper.h>
#include <qvpiemodelmapper.h>
#include <qpielegendmarker.h>
#include <qbarset.h>
#include <qpiemodelmapper.h>
#include <qxyseries.h>
#include <qchartglobal.h>
#include <qabstractaxis.h>
#include <qcandlestickmodelmapper.h>
#include <qbarmodelmapper.h>
#include <qchartview.h>
#include <qvcandlestickmodelmapper.h>
#include <qboxset.h>
#include <qbarseries.h>
#include <qboxplotlegendmarker.h>
#include <qcategoryaxis.h>
#include <qxylegendmarker.h>
#include <qbarlegendmarker.h>
#include <qhorizontalpercentbarseries.h>
#include <qsplineseries.h>
#include <qlegendmarker.h>
#include <qhbarmodelmapper.h>
#include <qstackedbarseries.h>
#include <qvboxplotmodelmapper.h>
#include <qpieslice.h>
#include <qabstractseries.h>
#include <qhxymodelmapper.h>
#include <qscatterseries.h>
#include <qlogvalueaxis.h>
#include <qcandlesticklegendmarker.h>
#include <qarealegendmarker.h>
#include <qchart.h>
#include <qhboxplotmodelmapper.h>
#include <qabstractbarseries.h>
// Conversion Includes - Primitive Types
#include <signalmanager.h>
#include <wtypes.h>
#include <qabstractitemmodel.h>
#include <QStringList>
#include <QString>

// Conversion Includes - Container Types
#include <QList>
#include <QPair>
#include <QStack>
#include <QMap>
#include <QSet>
#include <pysideqflags.h>
#include <QQueue>
#include <QMultiMap>
#include <QLinkedList>
#include <QVector>

// Type indices
#define SBK_QTCHARTS_IDX                                             1
#define SBK_QTCHARTS_QCHARTVIEW_IDX                                  29
#define SBK_QTCHARTS_QCHARTVIEW_RUBBERBAND_IDX                       30
#define SBK_QTCHARTS_QPIESLICE_IDX                                   50
#define SBK_QTCHARTS_QPIESLICE_LABELPOSITION_IDX                     51
#define SBK_QTCHARTS_QXYMODELMAPPER_IDX                              65
#define SBK_QTCHARTS_QHXYMODELMAPPER_IDX                             36
#define SBK_QTCHARTS_QVXYMODELMAPPER_IDX                             62
#define SBK_QTCHARTS_QCHART_IDX                                      25
#define SBK_QTCHARTS_QCHART_CHARTTYPE_IDX                            28
#define SBK_QTCHARTS_QCHART_CHARTTHEME_IDX                           27
#define SBK_QTCHARTS_QCHART_ANIMATIONOPTION_IDX                      26
#define SBK_QTCHARTS_QPOLARCHART_IDX                                 52
#define SBK_QTCHARTS_QPOLARCHART_POLARORIENTATION_IDX                53
#define SBK_QFLAGS_QTCHARTS_QPOLARCHART_POLARORIENTATION__IDX        0
#define SBK_QTCHARTS_QLEGEND_IDX                                     40
#define SBK_QTCHARTS_QLEGEND_MARKERSHAPE_IDX                         41
#define SBK_QTCHARTS_QPIEMODELMAPPER_IDX                             48
#define SBK_QTCHARTS_QVPIEMODELMAPPER_IDX                            61
#define SBK_QTCHARTS_QHPIEMODELMAPPER_IDX                            35
#define SBK_QTCHARTS_QCANDLESTICKSET_IDX                             23
#define SBK_QTCHARTS_QBOXSET_IDX                                     18
#define SBK_QTCHARTS_QBOXSET_VALUEPOSITIONS_IDX                      19
#define SBK_QTCHARTS_QCANDLESTICKMODELMAPPER_IDX                     21
#define SBK_QTCHARTS_QHCANDLESTICKMODELMAPPER_IDX                    34
#define SBK_QTCHARTS_QVCANDLESTICKMODELMAPPER_IDX                    60
#define SBK_QTCHARTS_QBOXPLOTMODELMAPPER_IDX                         16
#define SBK_QTCHARTS_QVBOXPLOTMODELMAPPER_IDX                        59
#define SBK_QTCHARTS_QHBOXPLOTMODELMAPPER_IDX                        33
#define SBK_QTCHARTS_QLEGENDMARKER_IDX                               42
#define SBK_QTCHARTS_QLEGENDMARKER_LEGENDMARKERTYPE_IDX              43
#define SBK_QTCHARTS_QBOXPLOTLEGENDMARKER_IDX                        15
#define SBK_QTCHARTS_QCANDLESTICKLEGENDMARKER_IDX                    20
#define SBK_QTCHARTS_QAREALEGENDMARKER_IDX                           8
#define SBK_QTCHARTS_QBARLEGENDMARKER_IDX                            11
#define SBK_QTCHARTS_QXYLEGENDMARKER_IDX                             64
#define SBK_QTCHARTS_QPIELEGENDMARKER_IDX                            47
#define SBK_QTCHARTS_QBARMODELMAPPER_IDX                             12
#define SBK_QTCHARTS_QVBARMODELMAPPER_IDX                            58
#define SBK_QTCHARTS_QHBARMODELMAPPER_IDX                            32
#define SBK_QTCHARTS_QABSTRACTSERIES_IDX                             6
#define SBK_QTCHARTS_QABSTRACTSERIES_SERIESTYPE_IDX                  7
#define SBK_QTCHARTS_QPIESERIES_IDX                                  49
#define SBK_QTCHARTS_QBOXPLOTSERIES_IDX                              17
#define SBK_QTCHARTS_QCANDLESTICKSERIES_IDX                          22
#define SBK_QTCHARTS_QAREASERIES_IDX                                 9
#define SBK_QTCHARTS_QXYSERIES_IDX                                   66
#define SBK_QTCHARTS_QSCATTERSERIES_IDX                              54
#define SBK_QTCHARTS_QSCATTERSERIES_MARKERSHAPE_IDX                  55
#define SBK_QTCHARTS_QLINESERIES_IDX                                 44
#define SBK_QTCHARTS_QSPLINESERIES_IDX                               56
#define SBK_QTCHARTS_QABSTRACTBARSERIES_IDX                          4
#define SBK_QTCHARTS_QABSTRACTBARSERIES_LABELSPOSITION_IDX           5
#define SBK_QTCHARTS_QHORIZONTALSTACKEDBARSERIES_IDX                 39
#define SBK_QTCHARTS_QHORIZONTALPERCENTBARSERIES_IDX                 38
#define SBK_QTCHARTS_QSTACKEDBARSERIES_IDX                           57
#define SBK_QTCHARTS_QHORIZONTALBARSERIES_IDX                        37
#define SBK_QTCHARTS_QBARSERIES_IDX                                  13
#define SBK_QTCHARTS_QPERCENTBARSERIES_IDX                           46
#define SBK_QTCHARTS_QABSTRACTAXIS_IDX                               2
#define SBK_QTCHARTS_QABSTRACTAXIS_AXISTYPE_IDX                      3
#define SBK_QTCHARTS_QLOGVALUEAXIS_IDX                               45
#define SBK_QTCHARTS_QVALUEAXIS_IDX                                  63
#define SBK_QTCHARTS_QCATEGORYAXIS_IDX                               24
#define SBK_QTCHARTS_QDATETIMEAXIS_IDX                               31
#define SBK_QTCHARTS_QBARCATEGORYAXIS_IDX                            10
#define SBK_QTCHARTS_QBARSET_IDX                                     14
#define SBK_QtCharts_IDX_COUNT                                       67

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_QtChartsTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_QtChartsTypeConverters;

// Converter indices
#define SBK_QTCHARTS_QLIST_QOBJECTPTR_IDX                            0 // const QList<QObject* > &
#define SBK_QTCHARTS_QLIST_QBYTEARRAY_IDX                            1 // QList<QByteArray >
#define SBK_QTCHARTS_QLIST_QACTIONPTR_IDX                            2 // QList<QAction* >
#define SBK_QTCHARTS_QLIST_QGRAPHICSITEMPTR_IDX                      3 // QList<QGraphicsItem* >
#define SBK_QTCHARTS_QLIST_QWIDGETPTR_IDX                            4 // QList<QWidget* >
#define SBK_QTCHARTS_QLIST_QRECTF_IDX                                5 // const QList<QRectF > &
#define SBK_QTCHARTS_QLIST_QTCHARTS_QABSTRACTAXISPTR_IDX             6 // QList<QtCharts::QAbstractAxis* >
#define SBK_QTCHARTS_QLIST_QTCHARTS_QABSTRACTSERIESPTR_IDX           7 // QList<QtCharts::QAbstractSeries* >
#define SBK_QTCHARTS_QLIST_QREAL_IDX                                 8 // const QList<qreal > &
#define SBK_QTCHARTS_QLIST_QTCHARTS_QLEGENDMARKERPTR_IDX             9 // QList<QtCharts::QLegendMarker* >
#define SBK_QTCHARTS_QLIST_QTCHARTS_QPIESLICEPTR_IDX                 10 // QList<QtCharts::QPieSlice* >
#define SBK_QTCHARTS_QLIST_QTCHARTS_QBOXSETPTR_IDX                   11 // QList<QtCharts::QBoxSet* >
#define SBK_QTCHARTS_QLIST_QTCHARTS_QBARSETPTR_IDX                   12 // QList<QtCharts::QBarSet* >
#define SBK_QTCHARTS_QLIST_QPOINTF_IDX                               13 // const QList<QPointF > &
#define SBK_QTCHARTS_QVECTOR_QPOINTF_IDX                             14 // QVector<QPointF >
#define SBK_QTCHARTS_QLIST_QTCHARTS_QCANDLESTICKSETPTR_IDX           15 // const QList<QtCharts::QCandlestickSet* > &
#define SBK_QTCHARTS_QLIST_QVARIANT_IDX                              16 // QList<QVariant >
#define SBK_QTCHARTS_QLIST_QSTRING_IDX                               17 // QList<QString >
#define SBK_QTCHARTS_QMAP_QSTRING_QVARIANT_IDX                       18 // QMap<QString,QVariant >
#define SBK_QtCharts_CONVERTERS_IDX_COUNT                            19

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::QtCharts::QChartView::RubberBand >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QCHARTVIEW_RUBBERBAND_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QChartView >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QCHARTVIEW_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QPieSlice::LabelPosition >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QPIESLICE_LABELPOSITION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QPieSlice >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QPIESLICE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QXYModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QXYMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QHXYModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QHXYMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QVXYModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QVXYMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QChart::ChartType >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QCHART_CHARTTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QChart::ChartTheme >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QCHART_CHARTTHEME_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QChart::AnimationOption >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QCHART_ANIMATIONOPTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QChart >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QCHART_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QPolarChart::PolarOrientation >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QPOLARCHART_POLARORIENTATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QtCharts::QPolarChart::PolarOrientation> >() { return SbkPySide2_QtChartsTypes[SBK_QFLAGS_QTCHARTS_QPOLARCHART_POLARORIENTATION__IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QPolarChart >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QPOLARCHART_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QLegend::MarkerShape >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QLEGEND_MARKERSHAPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QLegend >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QLEGEND_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QPieModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QPIEMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QVPieModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QVPIEMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QHPieModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QHPIEMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QCandlestickSet >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QCANDLESTICKSET_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QBoxSet::ValuePositions >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QBOXSET_VALUEPOSITIONS_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QBoxSet >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QBOXSET_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QCandlestickModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QCANDLESTICKMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QHCandlestickModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QHCANDLESTICKMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QVCandlestickModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QVCANDLESTICKMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QBoxPlotModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QBOXPLOTMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QVBoxPlotModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QVBOXPLOTMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QHBoxPlotModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QHBOXPLOTMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QLegendMarker::LegendMarkerType >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QLEGENDMARKER_LEGENDMARKERTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QLegendMarker >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QLEGENDMARKER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QBoxPlotLegendMarker >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QBOXPLOTLEGENDMARKER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QCandlestickLegendMarker >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QCANDLESTICKLEGENDMARKER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QAreaLegendMarker >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QAREALEGENDMARKER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QBarLegendMarker >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QBARLEGENDMARKER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QXYLegendMarker >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QXYLEGENDMARKER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QPieLegendMarker >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QPIELEGENDMARKER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QBarModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QBARMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QVBarModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QVBARMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QHBarModelMapper >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QHBARMODELMAPPER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QAbstractSeries::SeriesType >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QABSTRACTSERIES_SERIESTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QAbstractSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QABSTRACTSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QPieSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QPIESERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QBoxPlotSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QBOXPLOTSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QCandlestickSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QCANDLESTICKSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QAreaSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QAREASERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QXYSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QXYSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QScatterSeries::MarkerShape >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QSCATTERSERIES_MARKERSHAPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QScatterSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QSCATTERSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QLineSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QLINESERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QSplineSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QSPLINESERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QAbstractBarSeries::LabelsPosition >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QABSTRACTBARSERIES_LABELSPOSITION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QAbstractBarSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QABSTRACTBARSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QHorizontalStackedBarSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QHORIZONTALSTACKEDBARSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QHorizontalPercentBarSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QHORIZONTALPERCENTBARSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QStackedBarSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QSTACKEDBARSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QHorizontalBarSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QHORIZONTALBARSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QBarSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QBARSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QPercentBarSeries >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QPERCENTBARSERIES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QAbstractAxis::AxisType >() { return SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QABSTRACTAXIS_AXISTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QtCharts::QAbstractAxis >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QABSTRACTAXIS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QLogValueAxis >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QLOGVALUEAXIS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QValueAxis >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QVALUEAXIS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QCategoryAxis >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QCATEGORYAXIS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QDateTimeAxis >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QDATETIMEAXIS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QBarCategoryAxis >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QBARCATEGORYAXIS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QtCharts::QBarSet >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtChartsTypes[SBK_QTCHARTS_QBARSET_IDX]); }

} // namespace Shiboken

#endif // SBK_QTCHARTS_PYTHON_H

