# Microsoft Developer Studio Project File - Name="SkinEdit_Console" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=SkinEdit_Console - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SkinEdit_Console.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SkinEdit_Console.mak" CFG="SkinEdit_Console - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SkinEdit_Console - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "SkinEdit_Console - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SkinEdit_Console - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W2 /GX /O2 /I "..\..\build\msvc" /I "C:\LPG\GTK\INCLUDE\GTK-2.0" /I "C:\LPG\GTK\LIB\GTK-2.0\INCLUDE" /I "C:\LPG\GTK\INCLUDE\GLIB-2.0" /I "C:\LPG\GTK\LIB\GLIB-2.0\INCLUDE" /I "C:\LPG\GTK\INCLUDE\PANGO-1.0" /I "C:\LPG\GTK\INCLUDE\ATK-1.0" /I "C:\LPG\GTK\include" /I "C:\LPG\GTK\include\libglade-2.0" /I "C:\LPG\GTK\include\cairo" /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "__WIN32__" /D "ENABLE_NLS" /YX /FD /c
# ADD BASE RSC /l 0x40c /d "NDEBUG"
# ADD RSC /l 0x40c /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386 /out:"SkinEdit.exe"

!ELSEIF  "$(CFG)" == "SkinEdit_Console - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MD /W2 /Gm /GX /ZI /Od /I "..\..\build\msvc" /I "C:\LPG\GTK\INCLUDE\GTK-2.0" /I "C:\LPG\GTK\LIB\GTK-2.0\INCLUDE" /I "C:\LPG\GTK\INCLUDE\GLIB-2.0" /I "C:\LPG\GTK\LIB\GLIB-2.0\INCLUDE" /I "C:\LPG\GTK\INCLUDE\PANGO-1.0" /I "C:\LPG\GTK\INCLUDE\ATK-1.0" /I "C:\LPG\GTK\include" /I "C:\LPG\GTK\include\libglade-2.0" /I "C:\LPG\GTK\include\cairo" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "__WIN32__" /D "ENABLE_NLS" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x40c /d "_DEBUG"
# ADD RSC /l 0x40c /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /out:"Debug\SkinEdit.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "SkinEdit_Console - Win32 Release"
# Name "SkinEdit_Console - Win32 Debug"
# Begin Group "External Libraries"

# PROP Default_Filter ""
# Begin Source File

SOURCE="C:\LPG\GTK\lib\glib-2.0.lib"
# End Source File
# Begin Source File

SOURCE="C:\LPG\GTK\lib\gdk-win32-2.0.lib"
# End Source File
# Begin Source File

SOURCE="C:\LPG\GTK\lib\gtk-win32-2.0.lib"
# End Source File
# Begin Source File

SOURCE="C:\LPG\GTK\lib\gobject-2.0.lib"
# End Source File
# Begin Source File

SOURCE="C:\LPG\GTK\lib\gdk_pixbuf-2.0.lib"
# End Source File
# Begin Source File

SOURCE="C:\LPG\GTK\lib\gthread-2.0.lib"
# End Source File
# Begin Source File

SOURCE="C:\LPG\GTK\lib\gmodule-2.0.lib"
# End Source File
# Begin Source File

SOURCE="C:\LPG\GTK\lib\pango-1.0.lib"
# End Source File
# Begin Source File

SOURCE="C:\LPG\GTK\lib\atk-1.0.lib"
# End Source File
# Begin Source File

SOURCE=C:\LPG\GTK\lib\intl.lib
# End Source File
# Begin Source File

SOURCE="C:\LPG\GTK\lib\glade-2.0.lib"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\skinedit.ico
# End Source File
# Begin Source File

SOURCE=.\skinedit.rc
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\boxes_cb.h
# End Source File
# Begin Source File

SOURCE=..\..\src\boxes_intf.h
# End Source File
# Begin Source File

SOURCE=..\..\src\defs.h
# End Source File
# Begin Source File

SOURCE=..\..\src\gtksdl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\intl.h
# End Source File
# Begin Source File

SOURCE=..\..\src\keymaps.h
# End Source File
# Begin Source File

SOURCE=..\..\src\main_cb.h
# End Source File
# Begin Source File

SOURCE=..\..\src\main_intf.h
# End Source File
# Begin Source File

SOURCE=..\..\src\prop_cb.h
# End Source File
# Begin Source File

SOURCE=..\..\src\prop_intf.h
# End Source File
# Begin Source File

SOURCE=..\..\src\rubberbox.h
# End Source File
# Begin Source File

SOURCE=..\..\src\skinops.h
# End Source File
# Begin Source File

SOURCE=..\..\src\struct.h
# End Source File
# Begin Source File

SOURCE=..\..\src\support.h
# End Source File
# Begin Source File

SOURCE=..\..\src\utils.h
# End Source File
# Begin Source File

SOURCE=..\..\src\vti_export.h
# End Source File
# End Group
# Begin Group "Source Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\src\boxes_cb.c
# End Source File
# Begin Source File

SOURCE=..\..\src\boxes_intf.c
# End Source File
# Begin Source File

SOURCE=..\..\src\main.c
# End Source File
# Begin Source File

SOURCE=..\..\src\main_cb.c
# End Source File
# Begin Source File

SOURCE=..\..\src\main_intf.c
# End Source File
# Begin Source File

SOURCE=..\..\src\prop_cb.c
# End Source File
# Begin Source File

SOURCE=..\..\src\prop_intf.c
# End Source File
# Begin Source File

SOURCE=..\..\src\rubberbox.c
# End Source File
# Begin Source File

SOURCE=..\..\src\skinops.c
# End Source File
# Begin Source File

SOURCE=..\..\src\support.c
# End Source File
# Begin Source File

SOURCE=..\..\src\utils.c
# End Source File
# Begin Source File

SOURCE=..\..\src\vti_export.c
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\ChangeLog
# End Source File
# End Target
# End Project
