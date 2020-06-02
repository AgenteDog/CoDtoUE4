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


#ifndef SBK_QTGUI_PYTHON_H
#define SBK_QTGUI_PYTHON_H

#include <sbkpython.h>
#include <sbkconverter.h>
#include <sbkenum.h>
#include <basewrapper.h>
#include <bindingmanager.h>
#include <memory>

#include <pysidesignal.h>
// Module Includes
#include <pyside2_qtcore_python.h>

// Binded library includes
#include <qimage.h>
#include <qvector2d.h>
#include <qopenglbuffer.h>
#include <qopenglframebufferobject.h>
#include <qevent.h>
#include <qfontinfo.h>
#include <qfontdatabase.h>
#include <qbrush.h>
#include <qquaternion.h>
#include <qsessionmanager.h>
#include <qoffscreensurface.h>
#include <qopenglshaderprogram.h>
#include <qregion.h>
#include <qpytextobject.h>
#include <qtransform.h>
#include <QTextBlock>
#include <qkeysequence.h>
#include <qgenericmatrix.h>
#include <qfontmetrics.h>
#include <qimageiohandler.h>
#include <qpaintdevice.h>
#include <qvalidator.h>
#include <qicon.h>
#include <qabstracttextdocumentlayout.h>
#include <qtextcursor.h>
#include <qvector4d.h>
#include <qtextdocument.h>
#include <qopenglversionfunctions.h>
#include <qcolor.h>
#include <qopenglpixeltransferoptions.h>
#include <qopenglfunctions.h>
#include <qvector3d.h>
#include <qaccessible.h>
#include <qpixmapcache.h>
#include <qscreen.h>
#include <qopenglvertexarrayobject.h>
#include <qguiapplication.h>
#include <qstylehints.h>
#include <qpaintdevicewindow.h>
#include <qbitmap.h>
#include <qtexttable.h>
#include <qrasterwindow.h>
#include <qtextlist.h>
#include <QTextLayout>
#include <qpagelayout.h>
#include <qopenglwindow.h>
#include <qstatictext.h>
#include <qmatrix.h>
#include <qstandarditemmodel.h>
#include <qpicture.h>
#include <QPainter>
#include <qtextobject.h>
#include <qpdfwriter.h>
#include <qtouchdevice.h>
#include <qdrag.h>
#include <qpagedpaintdevice.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <qclipboard.h>
#include <QTextFrame>
#include <QAbstractTextDocumentLayout>
#include <qbackingstore.h>
#include <qdesktopservices.h>
#include <qtextdocumentwriter.h>
#include <qsurfaceformat.h>
#include <qiconengine.h>
#include <qpen.h>
#include <qopengldebug.h>
#include <QPainterPath>
#include <qcursor.h>
#include <qpalette.h>
#include <qtextlayout.h>
#include <qopengltimerquery.h>
#include <qrawfont.h>
#include <qmovie.h>
#include <qimagewriter.h>
#include <qtextformat.h>
#include <qmatrix4x4.h>
#include <qopenglcontext.h>
#include <qstringlistmodel.h>
#include <qimagereader.h>
#include <qwindow.h>
#include <qpolygon.h>
#include <qsurface.h>
#include <qopengltexture.h>
#include <qpixelformat.h>
#include <qsyntaxhighlighter.h>
#include <qtextoption.h>
#include <qpagesize.h>
#include <qfont.h>
#include <qopenglextrafunctions.h>
#include <qpainterpath.h>
#include <QInputMethodEvent>
#include <qtextdocumentfragment.h>
#include <qpaintengine.h>
// Conversion Includes - Primitive Types
#include <signalmanager.h>
#include <qabstractitemmodel.h>
#include <QString>
#include <wtypes.h>
#include <QStringList>

// Conversion Includes - Container Types
#include <QStack>
#include <QLinkedList>
#include <QSet>
#include <QVector>
#include <pysideqflags.h>
#include <QQueue>
#include <QMultiMap>
#include <QPair>
#include <QList>
#include <QMap>

// Type indices
#define SBK_QMATRIX4X3_IDX                                           119
#define SBK_QMATRIX4X2_IDX                                           118
#define SBK_QMATRIX3X4_IDX                                           117
#define SBK_QMATRIX3X3_IDX                                           116
#define SBK_QMATRIX3X2_IDX                                           115
#define SBK_QMATRIX2X4_IDX                                           114
#define SBK_QMATRIX2X3_IDX                                           113
#define SBK_QMATRIX2X2_IDX                                           112
#define SBK_QTEXTTABLECELL_IDX                                       318
#define SBK_QTEXTFRAGMENT_IDX                                        289
#define SBK_QTEXTBLOCK_IDX                                           264
#define SBK_QTEXTBLOCK_ITERATOR_IDX                                  265
#define SBK_QTEXTBLOCKUSERDATA_IDX                                   268
#define SBK_QSTANDARDITEM_IDX                                        244
#define SBK_QSTANDARDITEM_ITEMTYPE_IDX                               245
#define SBK_QPIXMAPCACHE_IDX                                         224
#define SBK_QPIXMAPCACHE_KEY_IDX                                     225
#define SBK_QPICTUREIO_IDX                                           214
#define SBK_QPAINTENGINESTATE_IDX                                    197
#define SBK_QPAINTENGINE_IDX                                         192
#define SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX                      194
#define SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX              48
#define SBK_QPAINTENGINE_DIRTYFLAG_IDX                               193
#define SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX                       47
#define SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX                         195
#define SBK_QPAINTENGINE_TYPE_IDX                                    196
#define SBK_QTEXTITEM_IDX                                            297
#define SBK_QTEXTITEM_RENDERFLAG_IDX                                 298
#define SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX                         55
#define SBK_QPAGESIZE_IDX                                            182
#define SBK_QPAGESIZE_PAGESIZEID_IDX                                 183
#define SBK_QPAGESIZE_UNIT_IDX                                       185
#define SBK_QPAGESIZE_SIZEMATCHPOLICY_IDX                            184
#define SBK_QOPENGLTEXTURE_IDX                                       152
#define SBK_QOPENGLTEXTURE_TARGET_IDX                                166
#define SBK_QOPENGLTEXTURE_BINDINGTARGET_IDX                         153
#define SBK_QOPENGLTEXTURE_MIPMAPGENERATION_IDX                      161
#define SBK_QOPENGLTEXTURE_TEXTUREUNITRESET_IDX                      169
#define SBK_QOPENGLTEXTURE_TEXTUREFORMAT_IDX                         167
#define SBK_QOPENGLTEXTURE_TEXTUREFORMATCLASS_IDX                    168
#define SBK_QOPENGLTEXTURE_CUBEMAPFACE_IDX                           157
#define SBK_QOPENGLTEXTURE_PIXELFORMAT_IDX                           162
#define SBK_QOPENGLTEXTURE_PIXELTYPE_IDX                             163
#define SBK_QOPENGLTEXTURE_SWIZZLECOMPONENT_IDX                      164
#define SBK_QOPENGLTEXTURE_SWIZZLEVALUE_IDX                          165
#define SBK_QOPENGLTEXTURE_WRAPMODE_IDX                              170
#define SBK_QOPENGLTEXTURE_COORDINATEDIRECTION_IDX                   156
#define SBK_QOPENGLTEXTURE_FEATURE_IDX                               159
#define SBK_QFLAGS_QOPENGLTEXTURE_FEATURE__IDX                       46
#define SBK_QOPENGLTEXTURE_DEPTHSTENCILMODE_IDX                      158
#define SBK_QOPENGLTEXTURE_COMPARISONFUNCTION_IDX                    154
#define SBK_QOPENGLTEXTURE_COMPARISONMODE_IDX                        155
#define SBK_QOPENGLTEXTURE_FILTER_IDX                                160
#define SBK_QOPENGLPIXELTRANSFEROPTIONS_IDX                          148
#define SBK_QOPENGLFRAMEBUFFEROBJECTFORMAT_IDX                       145
#define SBK_QOPENGLFRAMEBUFFEROBJECT_IDX                             142
#define SBK_QOPENGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX                  143
#define SBK_QOPENGLFRAMEBUFFEROBJECT_FRAMEBUFFERRESTOREPOLICY_IDX    144
#define SBK_QOPENGLFUNCTIONS_IDX                                     146
#define SBK_QOPENGLFUNCTIONS_OPENGLFEATURE_IDX                       147
#define SBK_QFLAGS_QOPENGLFUNCTIONS_OPENGLFEATURE__IDX               44
#define SBK_QOPENGLEXTRAFUNCTIONS_IDX                                141
#define SBK_QOPENGLDEBUGMESSAGE_IDX                                  137
#define SBK_QOPENGLDEBUGMESSAGE_SOURCE_IDX                           139
#define SBK_QFLAGS_QOPENGLDEBUGMESSAGE_SOURCE__IDX                   42
#define SBK_QOPENGLDEBUGMESSAGE_TYPE_IDX                             140
#define SBK_QFLAGS_QOPENGLDEBUGMESSAGE_TYPE__IDX                     43
#define SBK_QOPENGLDEBUGMESSAGE_SEVERITY_IDX                         138
#define SBK_QFLAGS_QOPENGLDEBUGMESSAGE_SEVERITY__IDX                 41
#define SBK_QOPENGLVERSIONPROFILE_IDX                                173
#define SBK_QABSTRACTOPENGLFUNCTIONS_IDX                             0
#define SBK_QOPENGLBUFFER_IDX                                        127
#define SBK_QOPENGLBUFFER_TYPE_IDX                                   130
#define SBK_QOPENGLBUFFER_USAGEPATTERN_IDX                           131
#define SBK_QOPENGLBUFFER_ACCESS_IDX                                 128
#define SBK_QOPENGLBUFFER_RANGEACCESSFLAG_IDX                        129
#define SBK_QFLAGS_QOPENGLBUFFER_RANGEACCESSFLAG__IDX                40
#define SBK_QMATRIX4X4_IDX                                           120
#define SBK_QQUATERNION_IDX                                          229
#define SBK_QVECTOR4D_IDX                                            334
#define SBK_QVECTOR3D_IDX                                            333
#define SBK_QIMAGEIOHANDLER_IDX                                      93
#define SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX                          94
#define SBK_QIMAGEIOHANDLER_TRANSFORMATION_IDX                       95
#define SBK_QFLAGS_QIMAGEIOHANDLER_TRANSFORMATION__IDX               39
#define SBK_QFONTMETRICSF_IDX                                        73
#define SBK_QFONTMETRICS_IDX                                         72
#define SBK_QFONTINFO_IDX                                            71
#define SBK_QDESKTOPSERVICES_IDX                                     28
#define SBK_QCURSOR_IDX                                              27
#define SBK_QSURFACE_IDX                                             252
#define SBK_QSURFACE_SURFACECLASS_IDX                                253
#define SBK_QSURFACE_SURFACETYPE_IDX                                 254
#define SBK_QSURFACEFORMAT_IDX                                       255
#define SBK_QSURFACEFORMAT_FORMATOPTION_IDX                          256
#define SBK_QFLAGS_QSURFACEFORMAT_FORMATOPTION__IDX                  52
#define SBK_QSURFACEFORMAT_SWAPBEHAVIOR_IDX                          259
#define SBK_QSURFACEFORMAT_RENDERABLETYPE_IDX                        258
#define SBK_QSURFACEFORMAT_OPENGLCONTEXTPROFILE_IDX                  257
#define SBK_QACCESSIBLEEVENT_IDX                                     12
#define SBK_QACCESSIBLEINTERFACE_IDX                                 13
#define SBK_QACCESSIBLE_IDX                                          4
#define SBK_QACCESSIBLE_EVENT_IDX                                    5
#define SBK_QACCESSIBLE_ROLE_IDX                                     8
#define SBK_QACCESSIBLE_TEXT_IDX                                     10
#define SBK_QACCESSIBLE_RELATIONFLAG_IDX                             7
#define SBK_QACCESSIBLE_INTERFACETYPE_IDX                            6
#define SBK_QACCESSIBLE_TEXTBOUNDARYTYPE_IDX                         11
#define SBK_QACCESSIBLE_STATE_IDX                                    9
#define SBK_QTEXTOBJECTINTERFACE_IDX                                 311
#define SBK_QPALETTE_IDX                                             208
#define SBK_QPALETTE_COLORGROUP_IDX                                  209
#define SBK_QPALETTE_COLORROLE_IDX                                   210
#define SBK_QTEXTLINE_IDX                                            304
#define SBK_QTEXTLINE_EDGE_IDX                                       306
#define SBK_QTEXTLINE_CURSORPOSITION_IDX                             305
#define SBK_QTEXTINLINEOBJECT_IDX                                    296
#define SBK_QTEXTCURSOR_IDX                                          273
#define SBK_QTEXTCURSOR_MOVEMODE_IDX                                 274
#define SBK_QTEXTCURSOR_MOVEOPERATION_IDX                            275
#define SBK_QTEXTCURSOR_SELECTIONTYPE_IDX                            276
#define SBK_QFONTDATABASE_IDX                                        68
#define SBK_QFONTDATABASE_WRITINGSYSTEM_IDX                          70
#define SBK_QFONTDATABASE_SYSTEMFONT_IDX                             69
#define SBK_QTEXTFORMAT_IDX                                          284
#define SBK_QTEXTFORMAT_FORMATTYPE_IDX                               285
#define SBK_QTEXTFORMAT_PROPERTY_IDX                                 288
#define SBK_QTEXTFORMAT_OBJECTTYPES_IDX                              286
#define SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX                            287
#define SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX                    54
#define SBK_QTEXTLISTFORMAT_IDX                                      308
#define SBK_QTEXTLISTFORMAT_STYLE_IDX                                309
#define SBK_QTEXTFRAMEFORMAT_IDX                                     292
#define SBK_QTEXTFRAMEFORMAT_POSITION_IDX                            294
#define SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX                         293
#define SBK_QTEXTTABLEFORMAT_IDX                                     320
#define SBK_QTEXTBLOCKFORMAT_IDX                                     266
#define SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX                     342
#define SBK_QTEXTLENGTH_IDX                                          302
#define SBK_QTEXTLENGTH_TYPE_IDX                                     303
#define SBK_QTEXTOPTION_IDX                                          312
#define SBK_QTEXTOPTION_TABTYPE_IDX                                  315
#define SBK_QTEXTOPTION_WRAPMODE_IDX                                 316
#define SBK_QTEXTOPTION_FLAG_IDX                                     313
#define SBK_QFLAGS_QTEXTOPTION_FLAG__IDX                             56
#define SBK_QTEXTOPTION_TAB_IDX                                      314
#define SBK_QPEN_IDX                                                 212
#define SBK_QGRADIENT_IDX                                            74
#define SBK_QGRADIENT_TYPE_IDX                                       78
#define SBK_QGRADIENT_SPREAD_IDX                                     77
#define SBK_QGRADIENT_COORDINATEMODE_IDX                             75
#define SBK_QGRADIENT_INTERPOLATIONMODE_IDX                          76
#define SBK_QLINEARGRADIENT_IDX                                      110
#define SBK_QRADIALGRADIENT_IDX                                      230
#define SBK_QCONICALGRADIENT_IDX                                     24
#define SBK_QBRUSH_IDX                                               17
#define SBK_QPIXELFORMAT_IDX                                         215
#define SBK_QPIXELFORMAT_COLORMODEL_IDX                              220
#define SBK_QPIXELFORMAT_ALPHAUSAGE_IDX                              218
#define SBK_QPIXELFORMAT_ALPHAPOSITION_IDX                           216
#define SBK_QPIXELFORMAT_ALPHAPREMULTIPLIED_IDX                      217
#define SBK_QPIXELFORMAT_TYPEINTERPRETATION_IDX                      221
#define SBK_QPIXELFORMAT_YUVLAYOUT_IDX                               222
#define SBK_QPIXELFORMAT_BYTEORDER_IDX                               219
#define SBK_QPAINTDEVICE_IDX                                         189
#define SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX                       190
#define SBK_QPICTURE_IDX                                             213
#define SBK_QPAGEDPAINTDEVICE_IDX                                    186
#define SBK_QPAGEDPAINTDEVICE_PAGESIZE_IDX                           188
#define SBK_QPAGEDPAINTDEVICE_MARGINS_IDX                            187
#define SBK_QTRANSFORM_IDX                                           328
#define SBK_QTRANSFORM_TRANSFORMATIONTYPE_IDX                        329
#define SBK_QPAINTERPATHSTROKER_IDX                                  207
#define SBK_QMATRIX_IDX                                              111
#define SBK_QPAINTERPATH_IDX                                         204
#define SBK_QPAINTERPATH_ELEMENTTYPE_IDX                             206
#define SBK_QPAINTERPATH_ELEMENT_IDX                                 205
#define SBK_QPOLYGONF_IDX                                            227
#define SBK_QVECTOR_QPOINTF_IDX                                      227
#define SBK_QPOLYGON_IDX                                             226
#define SBK_QVECTOR_QPOINT_IDX                                       226
#define SBK_QFONT_IDX                                                60
#define SBK_QFONT_STYLEHINT_IDX                                      65
#define SBK_QFONT_STYLESTRATEGY_IDX                                  66
#define SBK_QFONT_HINTINGPREFERENCE_IDX                              341
#define SBK_QFONT_WEIGHT_IDX                                         67
#define SBK_QFONT_STYLE_IDX                                          64
#define SBK_QFONT_STRETCH_IDX                                        63
#define SBK_QFONT_CAPITALIZATION_IDX                                 61
#define SBK_QFONT_SPACINGTYPE_IDX                                    62
#define SBK_QRAWFONT_IDX                                             232
#define SBK_QRAWFONT_ANTIALIASINGTYPE_IDX                            233
#define SBK_QRAWFONT_LAYOUTFLAG_IDX                                  234
#define SBK_QFLAGS_QRAWFONT_LAYOUTFLAG__IDX                          51
#define SBK_QSTATICTEXT_IDX                                          247
#define SBK_QSTATICTEXT_PERFORMANCEHINT_IDX                          248
#define SBK_QTEXTCHARFORMAT_IDX                                      269
#define SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX                    272
#define SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX                       271
#define SBK_QTEXTCHARFORMAT_FONTPROPERTIESINHERITANCEBEHAVIOR_IDX    270
#define SBK_QTEXTIMAGEFORMAT_IDX                                     295
#define SBK_QTEXTTABLECELLFORMAT_IDX                                 319
#define SBK_QTOUCHDEVICE_IDX                                         322
#define SBK_QTOUCHDEVICE_DEVICETYPE_IDX                              324
#define SBK_QTOUCHDEVICE_CAPABILITYFLAG_IDX                          323
#define SBK_QFLAGS_QTOUCHDEVICE_CAPABILITYFLAG__IDX                  57
#define SBK_QVECTOR2D_IDX                                            332
#define SBK_QKEYSEQUENCE_IDX                                         106
#define SBK_QKEYSEQUENCE_STANDARDKEY_IDX                             109
#define SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX                          107
#define SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX                           108
#define SBK_QCOLOR_IDX                                               21
#define SBK_QCOLOR_SPEC_IDX                                          23
#define SBK_QCOLOR_NAMEFORMAT_IDX                                    22
#define SBK_QTEXTLAYOUT_IDX                                          299
#define SBK_QTEXTLAYOUT_CURSORMODE_IDX                               300
#define SBK_QTEXTLAYOUT_FORMATRANGE_IDX                              301
#define SBK_QIMAGE_IDX                                               90
#define SBK_QIMAGE_INVERTMODE_IDX                                    92
#define SBK_QIMAGE_FORMAT_IDX                                        91
#define SBK_QPIXMAP_IDX                                              223
#define SBK_QBITMAP_IDX                                              16
#define SBK_QICON_IDX                                                83
#define SBK_QICON_MODE_IDX                                           84
#define SBK_QICON_STATE_IDX                                          85
#define SBK_QICONENGINE_IDX                                          87
#define SBK_QICONENGINE_ICONENGINEHOOK_IDX                           89
#define SBK_QICONENGINE_AVAILABLESIZESARGUMENT_IDX                   88
#define SBK_QPAGELAYOUT_IDX                                          178
#define SBK_QPAGELAYOUT_UNIT_IDX                                     181
#define SBK_QPAGELAYOUT_ORIENTATION_IDX                              180
#define SBK_QPAGELAYOUT_MODE_IDX                                     179
#define SBK_QREGION_IDX                                              236
#define SBK_QREGION_REGIONTYPE_IDX                                   237
#define SBK_QDROPEVENT_IDX                                           35
#define SBK_QDRAGMOVEEVENT_IDX                                       34
#define SBK_QDRAGENTEREVENT_IDX                                      32
#define SBK_QINPUTEVENT_IDX                                          100
#define SBK_QCONTEXTMENUEVENT_IDX                                    25
#define SBK_QCONTEXTMENUEVENT_REASON_IDX                             26
#define SBK_QTOUCHEVENT_IDX                                          325
#define SBK_QTOUCHEVENT_TOUCHPOINT_IDX                               326
#define SBK_QTOUCHEVENT_TOUCHPOINT_INFOFLAG_IDX                      327
#define SBK_QFLAGS_QTOUCHEVENT_TOUCHPOINT_INFOFLAG__IDX              58
#define SBK_QMOUSEEVENT_IDX                                          121
#define SBK_QHOVEREVENT_IDX                                          82
#define SBK_QWHEELEVENT_IDX                                          336
#define SBK_QTABLETEVENT_IDX                                         261
#define SBK_QTABLETEVENT_TABLETDEVICE_IDX                            263
#define SBK_QTABLETEVENT_POINTERTYPE_IDX                             262
#define SBK_QKEYEVENT_IDX                                            105
#define SBK_QDRAGLEAVEEVENT_IDX                                      33
#define SBK_QENTEREVENT_IDX                                          36
#define SBK_QHELPEVENT_IDX                                           80
#define SBK_QSTATUSTIPEVENT_IDX                                      249
#define SBK_QWHATSTHISCLICKEDEVENT_IDX                               335
#define SBK_QACTIONEVENT_IDX                                         14
#define SBK_QRESIZEEVENT_IDX                                         238
#define SBK_QCLOSEEVENT_IDX                                          20
#define SBK_QICONDRAGEVENT_IDX                                       86
#define SBK_QSHOWEVENT_IDX                                           243
#define SBK_QHIDEEVENT_IDX                                           81
#define SBK_QINPUTMETHODEVENT_IDX                                    101
#define SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX                      103
#define SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX                          102
#define SBK_QFILEOPENEVENT_IDX                                       38
#define SBK_QTOOLBARCHANGEEVENT_IDX                                  321
#define SBK_QFOCUSEVENT_IDX                                          59
#define SBK_QSHORTCUTEVENT_IDX                                       242
#define SBK_QPAINTEVENT_IDX                                          198
#define SBK_QWINDOWSTATECHANGEEVENT_IDX                              340
#define SBK_QMOVEEVENT_IDX                                           122
#define SBK_QEXPOSEEVENT_IDX                                         37
#define SBK_QBACKINGSTORE_IDX                                        15
#define SBK_QPAINTER_IDX                                             199
#define SBK_QPAINTER_RENDERHINT_IDX                                  203
#define SBK_QFLAGS_QPAINTER_RENDERHINT__IDX                          50
#define SBK_QPAINTER_PIXMAPFRAGMENTHINT_IDX                          202
#define SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX                  49
#define SBK_QPAINTER_COMPOSITIONMODE_IDX                             200
#define SBK_QPAINTER_PIXMAPFRAGMENT_IDX                              201
#define SBK_QVALIDATOR_IDX                                           330
#define SBK_QVALIDATOR_STATE_IDX                                     331
#define SBK_QINTVALIDATOR_IDX                                        104
#define SBK_QDOUBLEVALIDATOR_IDX                                     29
#define SBK_QDOUBLEVALIDATOR_NOTATION_IDX                            30
#define SBK_QREGEXPVALIDATOR_IDX                                     235
#define SBK_QWINDOW_IDX                                              337
#define SBK_QWINDOW_VISIBILITY_IDX                                   339
#define SBK_QWINDOW_ANCESTORMODE_IDX                                 338
#define SBK_QPAINTDEVICEWINDOW_IDX                                   191
#define SBK_QRASTERWINDOW_IDX                                        231
#define SBK_QOPENGLWINDOW_IDX                                        176
#define SBK_QOPENGLWINDOW_UPDATEBEHAVIOR_IDX                         177
#define SBK_QCLIPBOARD_IDX                                           18
#define SBK_QCLIPBOARD_MODE_IDX                                      19
#define SBK_QDRAG_IDX                                                31
#define SBK_QSYNTAXHIGHLIGHTER_IDX                                   260
#define SBK_QSCREEN_IDX                                              239
#define SBK_QSESSIONMANAGER_IDX                                      240
#define SBK_QSESSIONMANAGER_RESTARTHINT_IDX                          241
#define SBK_QSTYLEHINTS_IDX                                          251
#define SBK_QTEXTOBJECT_IDX                                          310
#define SBK_QTEXTBLOCKGROUP_IDX                                      267
#define SBK_QTEXTLIST_IDX                                            307
#define SBK_QTEXTFRAME_IDX                                           290
#define SBK_QTEXTTABLE_IDX                                           317
#define SBK_QTEXTFRAME_ITERATOR_IDX                                  291
#define SBK_QSTANDARDITEMMODEL_IDX                                   246
#define SBK_QSTRINGLISTMODEL_IDX                                     250
#define SBK_QPDFWRITER_IDX                                           211
#define SBK_QABSTRACTTEXTDOCUMENTLAYOUT_IDX                          1
#define SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX             2
#define SBK_QABSTRACTTEXTDOCUMENTLAYOUT_SELECTION_IDX                3
#define SBK_QOPENGLSHADER_IDX                                        149
#define SBK_QOPENGLSHADER_SHADERTYPEBIT_IDX                          150
#define SBK_QFLAGS_QOPENGLSHADER_SHADERTYPEBIT__IDX                  45
#define SBK_QOPENGLSHADERPROGRAM_IDX                                 151
#define SBK_QOPENGLTIMERQUERY_IDX                                    172
#define SBK_QOPENGLTIMEMONITOR_IDX                                   171
#define SBK_QOPENGLVERTEXARRAYOBJECT_IDX                             174
#define SBK_QOPENGLVERTEXARRAYOBJECT_BINDER_IDX                      175
#define SBK_QOPENGLCONTEXTGROUP_IDX                                  134
#define SBK_QOPENGLCONTEXT_IDX                                       132
#define SBK_QOPENGLCONTEXT_OPENGLMODULETYPE_IDX                      133
#define SBK_QOPENGLDEBUGLOGGER_IDX                                   135
#define SBK_QOPENGLDEBUGLOGGER_LOGGINGMODE_IDX                       136
#define SBK_QPYTEXTOBJECT_IDX                                        228
#define SBK_QOFFSCREENSURFACE_IDX                                    126
#define SBK_QGUIAPPLICATION_IDX                                      79
#define SBK_QTEXTDOCUMENTFRAGMENT_IDX                                282
#define SBK_QTEXTDOCUMENTWRITER_IDX                                  283
#define SBK_QIMAGEREADER_IDX                                         96
#define SBK_QIMAGEREADER_IMAGEREADERERROR_IDX                        97
#define SBK_QIMAGEWRITER_IDX                                         98
#define SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX                        99
#define SBK_QMOVIE_IDX                                               123
#define SBK_QMOVIE_MOVIESTATE_IDX                                    125
#define SBK_QMOVIE_CACHEMODE_IDX                                     124
#define SBK_QTEXTDOCUMENT_IDX                                        277
#define SBK_QTEXTDOCUMENT_METAINFORMATION_IDX                        279
#define SBK_QTEXTDOCUMENT_FINDFLAG_IDX                               278
#define SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX                       53
#define SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX                           280
#define SBK_QTEXTDOCUMENT_STACKS_IDX                                 281
#define SBK_QtGui_IDX_COUNT                                          343

// This variable stores all Python types exported by this module.
extern PyTypeObject** SbkPySide2_QtGuiTypes;

// This variable stores all type converters exported by this module.
extern SbkConverter** SbkPySide2_QtGuiTypeConverters;

// Converter indices
#define SBK_WID_IDX                                                  0
#define SBK_QTGUI_QVECTOR_QTEXTLAYOUT_FORMATRANGE_IDX                1 // QVector<QTextLayout::FormatRange >
#define SBK_QTGUI_QLIST_QSTANDARDITEMPTR_IDX                         2 // const QList<QStandardItem* > &
#define SBK_QTGUI_QLIST_QBYTEARRAY_IDX                               3 // QList<QByteArray >
#define SBK_QTGUI_QPAIR_FLOAT_FLOAT_IDX                              4 // QPair<float,float >
#define SBK_QTGUI_QPAIR_QOPENGLTEXTURE_FILTER_QOPENGLTEXTURE_FILTER_IDX 5 // QPair<QOpenGLTexture::Filter,QOpenGLTexture::Filter >
#define SBK_QTGUI_QPAIR_INT_INT_IDX                                  6 // QPair<int,int >
#define SBK_QTGUI_QVECTOR_QSIZE_IDX                                  7 // QVector<QSize >
#define SBK_QTGUI_QVECTOR_UNSIGNEDINT_IDX                            8 // QVector<unsigned int >
#define SBK_QTGUI_QLIST_FLOAT_IDX                                    9 // QList<float >
#define SBK_QTGUI_QLIST_INT_IDX                                      10 // QList<int >
#define SBK_QTGUI_QLIST_QFONTDATABASE_WRITINGSYSTEM_IDX              11 // QList<QFontDatabase::WritingSystem >
#define SBK_QTGUI_QVECTOR_QTEXTLENGTH_IDX                            12 // QVector<QTextLength >
#define SBK_QTGUI_QMAP_INT_QVARIANT_IDX                              13 // QMap<int,QVariant >
#define SBK_QTGUI_QLIST_QTEXTOPTION_TAB_IDX                          14 // const QList<QTextOption::Tab > &
#define SBK_QTGUI_QLIST_QREAL_IDX                                    15 // const QList<qreal > &
#define SBK_QTGUI_QVECTOR_QREAL_IDX                                  16 // QVector<qreal >
#define SBK_QTGUI_QPAIR_QREAL_QCOLOR_IDX                             17 // QPair<qreal,QColor >
#define SBK_QTGUI_QVECTOR_QPAIR_QREAL_QCOLOR_IDX                     18 // const QVector<QPair< qreal,QColor > > &
#define SBK_QTGUI_QLIST_QPOLYGONF_IDX                                19 // QList<QPolygonF >
#define SBK_QTGUI_QVECTOR_QPOINTF_IDX                                20 // QVector<QPointF > &&
#define SBK_QTGUI_QLIST_QPOINTF_IDX                                  21 // const QList<QPointF > &
#define SBK_QTGUI_QVECTOR_QPOINT_IDX                                 22 // QVector<QPoint > &&
#define SBK_QTGUI_QLIST_QPOINT_IDX                                   23 // const QList<QPoint > &
#define SBK_QTGUI_QVECTOR_QUINT32_IDX                                24 // const QVector<quint32 > &
#define SBK_QTGUI_QLIST_CONSTQTOUCHDEVICEPTR_IDX                     25 // QList<const QTouchDevice* >
#define SBK_QTGUI_QLIST_QKEYSEQUENCE_IDX                             26 // QList<QKeySequence >
#define SBK_QTGUI_QLIST_QTEXTLAYOUT_FORMATRANGE_IDX                  27 // QList<QTextLayout::FormatRange >
#define SBK_QTGUI_QLIST_QSIZE_IDX                                    28 // QList<QSize >
#define SBK_QTGUI_QVECTOR_QRECT_IDX                                  29 // QVector<QRect >
#define SBK_QTGUI_QLIST_QTOUCHEVENT_TOUCHPOINT_IDX                   30 // const QList<QTouchEvent::TouchPoint > &
#define SBK_QTGUI_QLIST_QINPUTMETHODEVENT_ATTRIBUTE_IDX              31 // const QList<QInputMethodEvent::Attribute > &
#define SBK_QTGUI_QVECTOR_QLINE_IDX                                  32 // const QVector<QLine > &
#define SBK_QTGUI_QVECTOR_QLINEF_IDX                                 33 // const QVector<QLineF > &
#define SBK_QTGUI_QVECTOR_QRECTF_IDX                                 34 // const QVector<QRectF > &
#define SBK_QTGUI_QLIST_QOBJECTPTR_IDX                               35 // const QList<QObject* > &
#define SBK_QTGUI_QLIST_QSCREENPTR_IDX                               36 // QList<QScreen* >
#define SBK_QTGUI_QLIST_QTEXTBLOCK_IDX                               37 // QList<QTextBlock >
#define SBK_QTGUI_QLIST_QTEXTFRAMEPTR_IDX                            38 // QList<QTextFrame* >
#define SBK_QTGUI_QVECTOR_INT_IDX                                    39 // const QVector<int > &
#define SBK_QTGUI_QHASH_INT_QBYTEARRAY_IDX                           40 // const QHash<int,QByteArray > &
#define SBK_QTGUI_QLIST_QPERSISTENTMODELINDEX_IDX                    41 // const QList<QPersistentModelIndex > &
#define SBK_QTGUI_QVECTOR_FLOAT_IDX                                  42 // QVector<float >
#define SBK_QTGUI_QLIST_QOPENGLSHADERPTR_IDX                         43 // QList<QOpenGLShader* >
#define SBK_QTGUI_QVECTOR_UNSIGNEDLONGLONG_IDX                       44 // QVector<unsigned long long >
#define SBK_QTGUI_QLIST_QOPENGLCONTEXTPTR_IDX                        45 // QList<QOpenGLContext* >
#define SBK_QTGUI_QSET_QBYTEARRAY_IDX                                46 // QSet<QByteArray >
#define SBK_QTGUI_QLIST_QOPENGLDEBUGMESSAGE_IDX                      47 // QList<QOpenGLDebugMessage >
#define SBK_QTGUI_QLIST_QWINDOWPTR_IDX                               48 // QList<QWindow* >
#define SBK_QTGUI_QVECTOR_QTEXTFORMAT_IDX                            49 // QVector<QTextFormat >
#define SBK_QTGUI_QLIST_QVARIANT_IDX                                 50 // QList<QVariant >
#define SBK_QTGUI_QLIST_QSTRING_IDX                                  51 // QList<QString >
#define SBK_QTGUI_QMAP_QSTRING_QVARIANT_IDX                          52 // QMap<QString,QVariant >
#define SBK_QtGui_CONVERTERS_IDX_COUNT                               53

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::QMatrix4x3 >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMATRIX4X3_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMatrix4x2 >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMATRIX4X2_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMatrix3x4 >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMATRIX3X4_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMatrix3x3 >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMATRIX3X3_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMatrix3x2 >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMATRIX3X2_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMatrix2x4 >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMATRIX2X4_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMatrix2x3 >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMATRIX2X3_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMatrix2x2 >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMATRIX2X2_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextTableCell >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTTABLECELL_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextFragment >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTFRAGMENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextBlock >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTBLOCK_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextBlock::iterator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTBLOCK_ITERATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextBlockUserData >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTBLOCKUSERDATA_IDX]); }
template<> inline PyTypeObject* SbkType< ::QStandardItem::ItemType >() { return SbkPySide2_QtGuiTypes[SBK_QSTANDARDITEM_ITEMTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QStandardItem >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSTANDARDITEM_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPixmapCache >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPIXMAPCACHE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPixmapCache::Key >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPIXMAPCACHE_KEY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPictureIO >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPICTUREIO_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPaintEngineState >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAINTENGINESTATE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPaintEngine::PaintEngineFeature >() { return SbkPySide2_QtGuiTypes[SBK_QPAINTENGINE_PAINTENGINEFEATURE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QPaintEngine::PaintEngineFeature> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_PAINTENGINEFEATURE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QPaintEngine::DirtyFlag >() { return SbkPySide2_QtGuiTypes[SBK_QPAINTENGINE_DIRTYFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QPaintEngine::DirtyFlag> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QPAINTENGINE_DIRTYFLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::QPaintEngine::PolygonDrawMode >() { return SbkPySide2_QtGuiTypes[SBK_QPAINTENGINE_POLYGONDRAWMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPaintEngine::Type >() { return SbkPySide2_QtGuiTypes[SBK_QPAINTENGINE_TYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPaintEngine >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAINTENGINE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextItem::RenderFlag >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTITEM_RENDERFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QTextItem::RenderFlag> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QTEXTITEM_RENDERFLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextItem >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTITEM_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPageSize::PageSizeId >() { return SbkPySide2_QtGuiTypes[SBK_QPAGESIZE_PAGESIZEID_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPageSize::Unit >() { return SbkPySide2_QtGuiTypes[SBK_QPAGESIZE_UNIT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPageSize::SizeMatchPolicy >() { return SbkPySide2_QtGuiTypes[SBK_QPAGESIZE_SIZEMATCHPOLICY_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPageSize >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAGESIZE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::Target >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_TARGET_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::BindingTarget >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_BINDINGTARGET_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::MipMapGeneration >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_MIPMAPGENERATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::TextureUnitReset >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_TEXTUREUNITRESET_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::TextureFormat >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_TEXTUREFORMAT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::TextureFormatClass >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_TEXTUREFORMATCLASS_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::CubeMapFace >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_CUBEMAPFACE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::PixelFormat >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_PIXELFORMAT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::PixelType >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_PIXELTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::SwizzleComponent >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_SWIZZLECOMPONENT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::SwizzleValue >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_SWIZZLEVALUE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::WrapMode >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_WRAPMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::CoordinateDirection >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_COORDINATEDIRECTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::Feature >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_FEATURE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QOpenGLTexture::Feature> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QOPENGLTEXTURE_FEATURE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::DepthStencilMode >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_DEPTHSTENCILMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::ComparisonFunction >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_COMPARISONFUNCTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::ComparisonMode >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_COMPARISONMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture::Filter >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_FILTER_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLTexture >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLTEXTURE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLPixelTransferOptions >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLPIXELTRANSFEROPTIONS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLFramebufferObjectFormat >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLFRAMEBUFFEROBJECTFORMAT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLFramebufferObject::Attachment >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLFRAMEBUFFEROBJECT_ATTACHMENT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLFramebufferObject::FramebufferRestorePolicy >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLFRAMEBUFFEROBJECT_FRAMEBUFFERRESTOREPOLICY_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLFramebufferObject >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLFRAMEBUFFEROBJECT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLFunctions::OpenGLFeature >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLFUNCTIONS_OPENGLFEATURE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QOpenGLFunctions::OpenGLFeature> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QOPENGLFUNCTIONS_OPENGLFEATURE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLFunctions >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLFUNCTIONS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLExtraFunctions >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLEXTRAFUNCTIONS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLDebugMessage::Source >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLDEBUGMESSAGE_SOURCE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QOpenGLDebugMessage::Source> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QOPENGLDEBUGMESSAGE_SOURCE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLDebugMessage::Type >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLDEBUGMESSAGE_TYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QOpenGLDebugMessage::Type> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QOPENGLDEBUGMESSAGE_TYPE__IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLDebugMessage::Severity >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLDEBUGMESSAGE_SEVERITY_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QOpenGLDebugMessage::Severity> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QOPENGLDEBUGMESSAGE_SEVERITY__IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLDebugMessage >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLDEBUGMESSAGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLVersionProfile >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLVERSIONPROFILE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAbstractOpenGLFunctions >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QABSTRACTOPENGLFUNCTIONS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLBuffer::Type >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLBUFFER_TYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLBuffer::UsagePattern >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLBUFFER_USAGEPATTERN_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLBuffer::Access >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLBUFFER_ACCESS_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLBuffer::RangeAccessFlag >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLBUFFER_RANGEACCESSFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QOpenGLBuffer::RangeAccessFlag> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QOPENGLBUFFER_RANGEACCESSFLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLBuffer >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLBUFFER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMatrix4x4 >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMATRIX4X4_IDX]); }
template<> inline PyTypeObject* SbkType< ::QQuaternion >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QQUATERNION_IDX]); }
template<> inline PyTypeObject* SbkType< ::QVector4D >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QVECTOR4D_IDX]); }
template<> inline PyTypeObject* SbkType< ::QVector3D >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QVECTOR3D_IDX]); }
template<> inline PyTypeObject* SbkType< ::QImageIOHandler::ImageOption >() { return SbkPySide2_QtGuiTypes[SBK_QIMAGEIOHANDLER_IMAGEOPTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QImageIOHandler::Transformation >() { return SbkPySide2_QtGuiTypes[SBK_QIMAGEIOHANDLER_TRANSFORMATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QImageIOHandler::Transformation> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QIMAGEIOHANDLER_TRANSFORMATION__IDX]; }
template<> inline PyTypeObject* SbkType< ::QImageIOHandler >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QIMAGEIOHANDLER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QFontMetricsF >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QFONTMETRICSF_IDX]); }
template<> inline PyTypeObject* SbkType< ::QFontMetrics >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QFONTMETRICS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QFontInfo >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QFONTINFO_IDX]); }
template<> inline PyTypeObject* SbkType< ::QDesktopServices >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QDESKTOPSERVICES_IDX]); }
template<> inline PyTypeObject* SbkType< ::QCursor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QCURSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSurface::SurfaceClass >() { return SbkPySide2_QtGuiTypes[SBK_QSURFACE_SURFACECLASS_IDX]; }
template<> inline PyTypeObject* SbkType< ::QSurface::SurfaceType >() { return SbkPySide2_QtGuiTypes[SBK_QSURFACE_SURFACETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QSurface >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSURFACE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSurfaceFormat::FormatOption >() { return SbkPySide2_QtGuiTypes[SBK_QSURFACEFORMAT_FORMATOPTION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QSurfaceFormat::FormatOption> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QSURFACEFORMAT_FORMATOPTION__IDX]; }
template<> inline PyTypeObject* SbkType< ::QSurfaceFormat::SwapBehavior >() { return SbkPySide2_QtGuiTypes[SBK_QSURFACEFORMAT_SWAPBEHAVIOR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QSurfaceFormat::RenderableType >() { return SbkPySide2_QtGuiTypes[SBK_QSURFACEFORMAT_RENDERABLETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QSurfaceFormat::OpenGLContextProfile >() { return SbkPySide2_QtGuiTypes[SBK_QSURFACEFORMAT_OPENGLCONTEXTPROFILE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QSurfaceFormat >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSURFACEFORMAT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAccessibleEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QACCESSIBLEEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAccessibleInterface >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QACCESSIBLEINTERFACE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAccessible::Event >() { return SbkPySide2_QtGuiTypes[SBK_QACCESSIBLE_EVENT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QAccessible::Role >() { return SbkPySide2_QtGuiTypes[SBK_QACCESSIBLE_ROLE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QAccessible::Text >() { return SbkPySide2_QtGuiTypes[SBK_QACCESSIBLE_TEXT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QAccessible::RelationFlag >() { return SbkPySide2_QtGuiTypes[SBK_QACCESSIBLE_RELATIONFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QAccessible::InterfaceType >() { return SbkPySide2_QtGuiTypes[SBK_QACCESSIBLE_INTERFACETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QAccessible::TextBoundaryType >() { return SbkPySide2_QtGuiTypes[SBK_QACCESSIBLE_TEXTBOUNDARYTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QAccessible >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QACCESSIBLE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAccessible::State >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QACCESSIBLE_STATE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextObjectInterface >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTOBJECTINTERFACE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPalette::ColorGroup >() { return SbkPySide2_QtGuiTypes[SBK_QPALETTE_COLORGROUP_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPalette::ColorRole >() { return SbkPySide2_QtGuiTypes[SBK_QPALETTE_COLORROLE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPalette >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPALETTE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextLine::Edge >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTLINE_EDGE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextLine::CursorPosition >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTLINE_CURSORPOSITION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextLine >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTLINE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextInlineObject >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTINLINEOBJECT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextCursor::MoveMode >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTCURSOR_MOVEMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextCursor::MoveOperation >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTCURSOR_MOVEOPERATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextCursor::SelectionType >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTCURSOR_SELECTIONTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextCursor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTCURSOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QFontDatabase::WritingSystem >() { return SbkPySide2_QtGuiTypes[SBK_QFONTDATABASE_WRITINGSYSTEM_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFontDatabase::SystemFont >() { return SbkPySide2_QtGuiTypes[SBK_QFONTDATABASE_SYSTEMFONT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFontDatabase >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QFONTDATABASE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextFormat::FormatType >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTFORMAT_FORMATTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextFormat::Property >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTFORMAT_PROPERTY_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextFormat::ObjectTypes >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTFORMAT_OBJECTTYPES_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextFormat::PageBreakFlag >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTFORMAT_PAGEBREAKFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QTextFormat::PageBreakFlag> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QTEXTFORMAT_PAGEBREAKFLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextFormat >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTFORMAT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextListFormat::Style >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTLISTFORMAT_STYLE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextListFormat >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTLISTFORMAT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextFrameFormat::Position >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_POSITION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextFrameFormat::BorderStyle >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_BORDERSTYLE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextFrameFormat >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTFRAMEFORMAT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextTableFormat >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTTABLEFORMAT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextBlockFormat::LineHeightTypes >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_LINEHEIGHTTYPES_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextBlockFormat >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTBLOCKFORMAT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextLength::Type >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTLENGTH_TYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextLength >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTLENGTH_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextOption::TabType >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTOPTION_TABTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextOption::WrapMode >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTOPTION_WRAPMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextOption::Flag >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTOPTION_FLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QTextOption::Flag> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QTEXTOPTION_FLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextOption >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTOPTION_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextOption::Tab >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTOPTION_TAB_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPen >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPEN_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGradient::Type >() { return SbkPySide2_QtGuiTypes[SBK_QGRADIENT_TYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGradient::Spread >() { return SbkPySide2_QtGuiTypes[SBK_QGRADIENT_SPREAD_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGradient::CoordinateMode >() { return SbkPySide2_QtGuiTypes[SBK_QGRADIENT_COORDINATEMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGradient::InterpolationMode >() { return SbkPySide2_QtGuiTypes[SBK_QGRADIENT_INTERPOLATIONMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QGradient >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QGRADIENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QLinearGradient >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QLINEARGRADIENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QRadialGradient >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QRADIALGRADIENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QConicalGradient >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QCONICALGRADIENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QBrush >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QBRUSH_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPixelFormat::ColorModel >() { return SbkPySide2_QtGuiTypes[SBK_QPIXELFORMAT_COLORMODEL_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPixelFormat::AlphaUsage >() { return SbkPySide2_QtGuiTypes[SBK_QPIXELFORMAT_ALPHAUSAGE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPixelFormat::AlphaPosition >() { return SbkPySide2_QtGuiTypes[SBK_QPIXELFORMAT_ALPHAPOSITION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPixelFormat::AlphaPremultiplied >() { return SbkPySide2_QtGuiTypes[SBK_QPIXELFORMAT_ALPHAPREMULTIPLIED_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPixelFormat::TypeInterpretation >() { return SbkPySide2_QtGuiTypes[SBK_QPIXELFORMAT_TYPEINTERPRETATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPixelFormat::YUVLayout >() { return SbkPySide2_QtGuiTypes[SBK_QPIXELFORMAT_YUVLAYOUT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPixelFormat::ByteOrder >() { return SbkPySide2_QtGuiTypes[SBK_QPIXELFORMAT_BYTEORDER_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPixelFormat >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPIXELFORMAT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPaintDevice::PaintDeviceMetric >() { return SbkPySide2_QtGuiTypes[SBK_QPAINTDEVICE_PAINTDEVICEMETRIC_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPaintDevice >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAINTDEVICE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPicture >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPICTURE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPagedPaintDevice::PageSize >() { return SbkPySide2_QtGuiTypes[SBK_QPAGEDPAINTDEVICE_PAGESIZE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPagedPaintDevice >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAGEDPAINTDEVICE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPagedPaintDevice::Margins >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAGEDPAINTDEVICE_MARGINS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTransform::TransformationType >() { return SbkPySide2_QtGuiTypes[SBK_QTRANSFORM_TRANSFORMATIONTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTransform >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTRANSFORM_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPainterPathStroker >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAINTERPATHSTROKER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMatrix >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMATRIX_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPainterPath::ElementType >() { return SbkPySide2_QtGuiTypes[SBK_QPAINTERPATH_ELEMENTTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPainterPath >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAINTERPATH_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPainterPath::Element >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAINTERPATH_ELEMENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPolygonF >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPOLYGONF_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPolygon >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPOLYGON_IDX]); }
template<> inline PyTypeObject* SbkType< ::QFont::StyleHint >() { return SbkPySide2_QtGuiTypes[SBK_QFONT_STYLEHINT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFont::StyleStrategy >() { return SbkPySide2_QtGuiTypes[SBK_QFONT_STYLESTRATEGY_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFont::HintingPreference >() { return SbkPySide2_QtGuiTypes[SBK_QFONT_HINTINGPREFERENCE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFont::Weight >() { return SbkPySide2_QtGuiTypes[SBK_QFONT_WEIGHT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFont::Style >() { return SbkPySide2_QtGuiTypes[SBK_QFONT_STYLE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFont::Stretch >() { return SbkPySide2_QtGuiTypes[SBK_QFONT_STRETCH_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFont::Capitalization >() { return SbkPySide2_QtGuiTypes[SBK_QFONT_CAPITALIZATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFont::SpacingType >() { return SbkPySide2_QtGuiTypes[SBK_QFONT_SPACINGTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFont >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QFONT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QRawFont::AntialiasingType >() { return SbkPySide2_QtGuiTypes[SBK_QRAWFONT_ANTIALIASINGTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QRawFont::LayoutFlag >() { return SbkPySide2_QtGuiTypes[SBK_QRAWFONT_LAYOUTFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QRawFont::LayoutFlag> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QRAWFONT_LAYOUTFLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::QRawFont >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QRAWFONT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QStaticText::PerformanceHint >() { return SbkPySide2_QtGuiTypes[SBK_QSTATICTEXT_PERFORMANCEHINT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QStaticText >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSTATICTEXT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextCharFormat::VerticalAlignment >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTCHARFORMAT_VERTICALALIGNMENT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextCharFormat::UnderlineStyle >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTCHARFORMAT_UNDERLINESTYLE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextCharFormat::FontPropertiesInheritanceBehavior >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTCHARFORMAT_FONTPROPERTIESINHERITANCEBEHAVIOR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextCharFormat >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTCHARFORMAT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextImageFormat >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTIMAGEFORMAT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextTableCellFormat >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTTABLECELLFORMAT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTouchDevice::DeviceType >() { return SbkPySide2_QtGuiTypes[SBK_QTOUCHDEVICE_DEVICETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTouchDevice::CapabilityFlag >() { return SbkPySide2_QtGuiTypes[SBK_QTOUCHDEVICE_CAPABILITYFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QTouchDevice::CapabilityFlag> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QTOUCHDEVICE_CAPABILITYFLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::QTouchDevice >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTOUCHDEVICE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QVector2D >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QVECTOR2D_IDX]); }
template<> inline PyTypeObject* SbkType< ::QKeySequence::StandardKey >() { return SbkPySide2_QtGuiTypes[SBK_QKEYSEQUENCE_STANDARDKEY_IDX]; }
template<> inline PyTypeObject* SbkType< ::QKeySequence::SequenceFormat >() { return SbkPySide2_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEFORMAT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QKeySequence::SequenceMatch >() { return SbkPySide2_QtGuiTypes[SBK_QKEYSEQUENCE_SEQUENCEMATCH_IDX]; }
template<> inline PyTypeObject* SbkType< ::QKeySequence >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QKEYSEQUENCE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QColor::Spec >() { return SbkPySide2_QtGuiTypes[SBK_QCOLOR_SPEC_IDX]; }
template<> inline PyTypeObject* SbkType< ::QColor::NameFormat >() { return SbkPySide2_QtGuiTypes[SBK_QCOLOR_NAMEFORMAT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QColor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QCOLOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextLayout::CursorMode >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTLAYOUT_CURSORMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextLayout >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTLAYOUT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextLayout::FormatRange >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTLAYOUT_FORMATRANGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QImage::InvertMode >() { return SbkPySide2_QtGuiTypes[SBK_QIMAGE_INVERTMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QImage::Format >() { return SbkPySide2_QtGuiTypes[SBK_QIMAGE_FORMAT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QImage >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QIMAGE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPixmap >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPIXMAP_IDX]); }
template<> inline PyTypeObject* SbkType< ::QBitmap >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QBITMAP_IDX]); }
template<> inline PyTypeObject* SbkType< ::QIcon::Mode >() { return SbkPySide2_QtGuiTypes[SBK_QICON_MODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QIcon::State >() { return SbkPySide2_QtGuiTypes[SBK_QICON_STATE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QIcon >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QICON_IDX]); }
template<> inline PyTypeObject* SbkType< ::QIconEngine::IconEngineHook >() { return SbkPySide2_QtGuiTypes[SBK_QICONENGINE_ICONENGINEHOOK_IDX]; }
template<> inline PyTypeObject* SbkType< ::QIconEngine >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QICONENGINE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QIconEngine::AvailableSizesArgument >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QICONENGINE_AVAILABLESIZESARGUMENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPageLayout::Unit >() { return SbkPySide2_QtGuiTypes[SBK_QPAGELAYOUT_UNIT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPageLayout::Orientation >() { return SbkPySide2_QtGuiTypes[SBK_QPAGELAYOUT_ORIENTATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPageLayout::Mode >() { return SbkPySide2_QtGuiTypes[SBK_QPAGELAYOUT_MODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPageLayout >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAGELAYOUT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QRegion::RegionType >() { return SbkPySide2_QtGuiTypes[SBK_QREGION_REGIONTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QRegion >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QREGION_IDX]); }
template<> inline PyTypeObject* SbkType< ::QDropEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QDROPEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QDragMoveEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QDRAGMOVEEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QDragEnterEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QDRAGENTEREVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QInputEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QINPUTEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QContextMenuEvent::Reason >() { return SbkPySide2_QtGuiTypes[SBK_QCONTEXTMENUEVENT_REASON_IDX]; }
template<> inline PyTypeObject* SbkType< ::QContextMenuEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QCONTEXTMENUEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTouchEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTOUCHEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTouchEvent::TouchPoint::InfoFlag >() { return SbkPySide2_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_INFOFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QTouchEvent::TouchPoint::InfoFlag> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QTOUCHEVENT_TOUCHPOINT_INFOFLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::QTouchEvent::TouchPoint >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTOUCHEVENT_TOUCHPOINT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMouseEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMOUSEEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QHoverEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QHOVEREVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QWheelEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QWHEELEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTabletEvent::TabletDevice >() { return SbkPySide2_QtGuiTypes[SBK_QTABLETEVENT_TABLETDEVICE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTabletEvent::PointerType >() { return SbkPySide2_QtGuiTypes[SBK_QTABLETEVENT_POINTERTYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTabletEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTABLETEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QKeyEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QKEYEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QDragLeaveEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QDRAGLEAVEEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QEnterEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QENTEREVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QHelpEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QHELPEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QStatusTipEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSTATUSTIPEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QWhatsThisClickedEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QWHATSTHISCLICKEDEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QActionEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QACTIONEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QResizeEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QRESIZEEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QCloseEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QCLOSEEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QIconDragEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QICONDRAGEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QShowEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSHOWEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QHideEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QHIDEEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QInputMethodEvent::AttributeType >() { return SbkPySide2_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QInputMethodEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QINPUTMETHODEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QInputMethodEvent::Attribute >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QINPUTMETHODEVENT_ATTRIBUTE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QFileOpenEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QFILEOPENEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QToolBarChangeEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTOOLBARCHANGEEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QFocusEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QFOCUSEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QShortcutEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSHORTCUTEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPaintEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAINTEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QWindowStateChangeEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QWINDOWSTATECHANGEEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMoveEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMOVEEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QExposeEvent >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QEXPOSEEVENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QBackingStore >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QBACKINGSTORE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPainter::RenderHint >() { return SbkPySide2_QtGuiTypes[SBK_QPAINTER_RENDERHINT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QPainter::RenderHint> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QPAINTER_RENDERHINT__IDX]; }
template<> inline PyTypeObject* SbkType< ::QPainter::PixmapFragmentHint >() { return SbkPySide2_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENTHINT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QPainter::PixmapFragmentHint> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QPAINTER_PIXMAPFRAGMENTHINT__IDX]; }
template<> inline PyTypeObject* SbkType< ::QPainter::CompositionMode >() { return SbkPySide2_QtGuiTypes[SBK_QPAINTER_COMPOSITIONMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QPainter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAINTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPainter::PixmapFragment >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAINTER_PIXMAPFRAGMENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QValidator::State >() { return SbkPySide2_QtGuiTypes[SBK_QVALIDATOR_STATE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QValidator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QVALIDATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QIntValidator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QINTVALIDATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QDoubleValidator::Notation >() { return SbkPySide2_QtGuiTypes[SBK_QDOUBLEVALIDATOR_NOTATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QDoubleValidator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QDOUBLEVALIDATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QRegExpValidator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QREGEXPVALIDATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QWindow::Visibility >() { return SbkPySide2_QtGuiTypes[SBK_QWINDOW_VISIBILITY_IDX]; }
template<> inline PyTypeObject* SbkType< ::QWindow::AncestorMode >() { return SbkPySide2_QtGuiTypes[SBK_QWINDOW_ANCESTORMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QWindow >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QWINDOW_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPaintDeviceWindow >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPAINTDEVICEWINDOW_IDX]); }
template<> inline PyTypeObject* SbkType< ::QRasterWindow >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QRASTERWINDOW_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLWindow::UpdateBehavior >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLWINDOW_UPDATEBEHAVIOR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLWindow >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLWINDOW_IDX]); }
template<> inline PyTypeObject* SbkType< ::QClipboard::Mode >() { return SbkPySide2_QtGuiTypes[SBK_QCLIPBOARD_MODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QClipboard >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QCLIPBOARD_IDX]); }
template<> inline PyTypeObject* SbkType< ::QDrag >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QDRAG_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSyntaxHighlighter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSYNTAXHIGHLIGHTER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QScreen >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSCREEN_IDX]); }
template<> inline PyTypeObject* SbkType< ::QSessionManager::RestartHint >() { return SbkPySide2_QtGuiTypes[SBK_QSESSIONMANAGER_RESTARTHINT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QSessionManager >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSESSIONMANAGER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QStyleHints >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSTYLEHINTS_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextObject >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTOBJECT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextBlockGroup >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTBLOCKGROUP_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextList >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTLIST_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextFrame >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTFRAME_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextTable >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTTABLE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextFrame::iterator >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTFRAME_ITERATOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QStandardItemModel >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSTANDARDITEMMODEL_IDX]); }
template<> inline PyTypeObject* SbkType< ::QStringListModel >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QSTRINGLISTMODEL_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPdfWriter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPDFWRITER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAbstractTextDocumentLayout >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAbstractTextDocumentLayout::PaintContext >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_PAINTCONTEXT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QAbstractTextDocumentLayout::Selection >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QABSTRACTTEXTDOCUMENTLAYOUT_SELECTION_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLShader::ShaderTypeBit >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLSHADER_SHADERTYPEBIT_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QOpenGLShader::ShaderTypeBit> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QOPENGLSHADER_SHADERTYPEBIT__IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLShader >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLSHADER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLShaderProgram >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLSHADERPROGRAM_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLTimerQuery >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLTIMERQUERY_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLTimeMonitor >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLTIMEMONITOR_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLVertexArrayObject >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLVERTEXARRAYOBJECT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLVertexArrayObject::Binder >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLVERTEXARRAYOBJECT_BINDER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLContextGroup >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLCONTEXTGROUP_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLContext::OpenGLModuleType >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLCONTEXT_OPENGLMODULETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLContext >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLCONTEXT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOpenGLDebugLogger::LoggingMode >() { return SbkPySide2_QtGuiTypes[SBK_QOPENGLDEBUGLOGGER_LOGGINGMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QOpenGLDebugLogger >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOPENGLDEBUGLOGGER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QPyTextObject >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QPYTEXTOBJECT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QOffscreenSurface >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QOFFSCREENSURFACE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QGuiApplication >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QGUIAPPLICATION_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextDocumentFragment >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTDOCUMENTFRAGMENT_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextDocumentWriter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTDOCUMENTWRITER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QImageReader::ImageReaderError >() { return SbkPySide2_QtGuiTypes[SBK_QIMAGEREADER_IMAGEREADERERROR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QImageReader >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QIMAGEREADER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QImageWriter::ImageWriterError >() { return SbkPySide2_QtGuiTypes[SBK_QIMAGEWRITER_IMAGEWRITERERROR_IDX]; }
template<> inline PyTypeObject* SbkType< ::QImageWriter >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QIMAGEWRITER_IDX]); }
template<> inline PyTypeObject* SbkType< ::QMovie::MovieState >() { return SbkPySide2_QtGuiTypes[SBK_QMOVIE_MOVIESTATE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QMovie::CacheMode >() { return SbkPySide2_QtGuiTypes[SBK_QMOVIE_CACHEMODE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QMovie >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QMOVIE_IDX]); }
template<> inline PyTypeObject* SbkType< ::QTextDocument::MetaInformation >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTDOCUMENT_METAINFORMATION_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextDocument::FindFlag >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTDOCUMENT_FINDFLAG_IDX]; }
template<> inline PyTypeObject* SbkType< ::QFlags<QTextDocument::FindFlag> >() { return SbkPySide2_QtGuiTypes[SBK_QFLAGS_QTEXTDOCUMENT_FINDFLAG__IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextDocument::ResourceType >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTDOCUMENT_RESOURCETYPE_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextDocument::Stacks >() { return SbkPySide2_QtGuiTypes[SBK_QTEXTDOCUMENT_STACKS_IDX]; }
template<> inline PyTypeObject* SbkType< ::QTextDocument >() { return reinterpret_cast<PyTypeObject*>(SbkPySide2_QtGuiTypes[SBK_QTEXTDOCUMENT_IDX]); }

} // namespace Shiboken

#endif // SBK_QTGUI_PYTHON_H

