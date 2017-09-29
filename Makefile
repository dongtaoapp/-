#############################################################################
# Makefile for building: PhysicalCheckStudent
# Generated by qmake (3.0) (Qt 5.7.1)
# Project:  PhysicalCheckTrainStudent.pro
# Template: app
# Command: F:\qt_32\5.7\msvc2015\bin\qmake.exe -spec win32-msvc2015 -o Makefile PhysicalCheckTrainStudent.pro
#############################################################################

MAKEFILE      = Makefile

first: release
install: release-install
uninstall: release-uninstall
QMAKE         = F:\qt_32\5.7\msvc2015\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		release \
		debug


release: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: PhysicalCheckTrainStudent.pro F:\qt_32\5.7\msvc2015\mkspecs\win32-msvc2015\qmake.conf F:\qt_32\5.7\msvc2015\mkspecs\features\spec_pre.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\common\angle.conf \
		F:\qt_32\5.7\msvc2015\mkspecs\common\msvc-base.conf \
		F:\qt_32\5.7\msvc2015\mkspecs\common\msvc-desktop.conf \
		F:\qt_32\5.7\msvc2015\mkspecs\qconfig.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dcore.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dcore_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dextras.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dextras_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dinput.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dinput_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dlogic.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dlogic_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquick.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquick_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquickextras.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquickextras_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquickinput.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquickinput_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquickrender.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquickrender_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3drender.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3drender_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_axbase.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_axbase_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_axcontainer.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_axcontainer_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_axserver.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_axserver_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_bluetooth.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_bluetooth_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_bootstrap_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_clucene_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_concurrent.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_concurrent_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_core.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_core_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_dbus.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_dbus_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_designer.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_designer_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_designercomponents_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_gamepad.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_gamepad_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_gui.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_gui_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_help.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_help_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_location.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_location_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_multimedia.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_multimedia_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_multimediawidgets.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_multimediawidgets_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_network.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_network_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_nfc.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_nfc_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_opengl.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_opengl_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_openglextensions.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_openglextensions_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_packetprotocol_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_platformsupport_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_positioning.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_positioning_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_printsupport.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_printsupport_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_purchasing.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_purchasing_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qml.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qml_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qmldebug_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qmldevtools_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qmltest.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qmltest_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quick.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quick_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quickcontrols2.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quickcontrols2_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quickparticles_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quicktemplates2_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quickwidgets.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quickwidgets_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_script.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_script_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_scripttools.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_scripttools_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_scxml.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_scxml_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_sensors.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_sensors_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_serialbus.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_serialbus_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_serialport.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_serialport_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_sql.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_sql_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_svg.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_svg_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_testlib.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_testlib_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_uiplugin.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_uitools.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_uitools_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webchannel.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webchannel_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webengine.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webengine_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webenginecore.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webenginecore_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webenginewidgets.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webenginewidgets_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_websockets.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_websockets_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webview.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webview_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_widgets.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_widgets_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_winextras.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_winextras_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_xml.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_xml_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_xmlpatterns.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_xmlpatterns_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_zlib_private.pri \
		F:\qt_32\5.7\msvc2015\mkspecs\features\qt_functions.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\qt_config.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\win32\qt_config.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\win32-msvc2015\qmake.conf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\spec_post.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\exclusive_builds.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\toolchain.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\default_pre.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\win32\default_pre.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\resolve_config.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\exclusive_builds_post.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\default_post.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\win32\rtti.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\precompile_header.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\warn_on.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\qt.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\resources.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\moc.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\win32\opengl.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\uic.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\win32\dumpcpp.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\file_copies.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\win32\windows.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\testcase_targets.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\exceptions.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\yacc.prf \
		F:\qt_32\5.7\msvc2015\mkspecs\features\lex.prf \
		PhysicalCheckTrainStudent.pro \
		F:\qt_32\5.7\msvc2015\lib\qtmain.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5Multimedia.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5AxContainer.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5AxBase.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5WebEngineWidgets.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5Widgets.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5WebEngineCore.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5Quick.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5Gui.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5WebChannel.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5Qml.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5Network.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5SerialPort.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5Positioning.prl \
		F:\qt_32\5.7\msvc2015\lib\Qt5Core.prl
	$(QMAKE) -spec win32-msvc2015 -o Makefile PhysicalCheckTrainStudent.pro
F:\qt_32\5.7\msvc2015\mkspecs\features\spec_pre.prf:
F:\qt_32\5.7\msvc2015\mkspecs\common\angle.conf:
F:\qt_32\5.7\msvc2015\mkspecs\common\msvc-base.conf:
F:\qt_32\5.7\msvc2015\mkspecs\common\msvc-desktop.conf:
F:\qt_32\5.7\msvc2015\mkspecs\qconfig.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dcore.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dcore_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dextras.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dextras_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dinput.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dinput_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dlogic.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dlogic_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquick.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquick_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquickextras.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquickextras_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquickinput.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquickinput_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquickrender.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3dquickrender_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3drender.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_3drender_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_axbase.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_axbase_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_axcontainer.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_axcontainer_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_axserver.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_axserver_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_bluetooth.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_bluetooth_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_bootstrap_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_clucene_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_concurrent.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_concurrent_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_core.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_core_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_dbus.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_dbus_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_designer.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_designer_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_designercomponents_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_gamepad.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_gamepad_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_gui.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_gui_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_help.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_help_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_location.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_location_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_multimedia.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_multimedia_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_multimediawidgets.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_multimediawidgets_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_network.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_network_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_nfc.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_nfc_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_opengl.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_opengl_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_openglextensions.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_openglextensions_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_packetprotocol_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_platformsupport_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_positioning.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_positioning_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_printsupport.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_printsupport_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_purchasing.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_purchasing_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qml.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qml_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qmldebug_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qmldevtools_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qmltest.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qmltest_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_qtmultimediaquicktools_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quick.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quick_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quickcontrols2.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quickcontrols2_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quickparticles_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quicktemplates2_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quickwidgets.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_quickwidgets_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_script.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_script_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_scripttools.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_scripttools_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_scxml.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_scxml_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_sensors.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_sensors_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_serialbus.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_serialbus_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_serialport.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_serialport_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_sql.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_sql_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_svg.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_svg_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_testlib.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_testlib_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_uiplugin.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_uitools.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_uitools_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webchannel.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webchannel_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webengine.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webengine_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webenginecore.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webenginecore_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webenginecoreheaders_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webenginewidgets.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webenginewidgets_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_websockets.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_websockets_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webview.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_webview_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_widgets.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_widgets_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_winextras.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_winextras_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_xml.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_xml_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_xmlpatterns.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_xmlpatterns_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\modules\qt_lib_zlib_private.pri:
F:\qt_32\5.7\msvc2015\mkspecs\features\qt_functions.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\qt_config.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\win32\qt_config.prf:
F:\qt_32\5.7\msvc2015\mkspecs\win32-msvc2015\qmake.conf:
F:\qt_32\5.7\msvc2015\mkspecs\features\spec_post.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\exclusive_builds.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\toolchain.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\default_pre.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\win32\default_pre.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\resolve_config.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\exclusive_builds_post.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\default_post.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\win32\rtti.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\precompile_header.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\warn_on.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\qt.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\resources.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\moc.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\win32\opengl.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\uic.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\win32\dumpcpp.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\file_copies.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\win32\windows.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\testcase_targets.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\exceptions.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\yacc.prf:
F:\qt_32\5.7\msvc2015\mkspecs\features\lex.prf:
PhysicalCheckTrainStudent.pro:
F:\qt_32\5.7\msvc2015\lib\qtmain.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5Multimedia.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5AxContainer.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5AxBase.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5WebEngineWidgets.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5Widgets.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5WebEngineCore.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5Quick.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5Gui.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5WebChannel.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5Qml.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5Network.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5SerialPort.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5Positioning.prl:
F:\qt_32\5.7\msvc2015\lib\Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -spec win32-msvc2015 -o Makefile PhysicalCheckTrainStudent.pro

qmake_all: FORCE

make_first: release-make_first debug-make_first  FORCE
all: release-all debug-all  FORCE
clean: release-clean debug-clean  FORCE
	-$(DEL_FILE) PhysicalCheckStudent.exp
distclean: release-distclean debug-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) PhysicalCheckStudent.lib

release-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables:
	@set MAKEFLAGS=$(MAKEFLAGS)
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
