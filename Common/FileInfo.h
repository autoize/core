#ifndef FILEINFO_H_DEFINE
#define FILEINFO_H_DEFINE

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef COMPONENT_NAME 
#error Uninitialized COMPONENT_NAME define! It should be like as #define COMPONENT_NAME "ComponentName"
#endif

#ifndef ASCBUILD

#define COMPANY_NAME				"Online Media Technologies Ltd."
#define LEGAL_COPYRIGHT				"Online Media Technologies Ltd. Copyright (c) 2005-2012"
#define COMPONENT_PREFIX			"AVS"

#else

#define COMPANY_NAME				"Ascensio System SIA"
#define LEGAL_COPYRIGHT				"Ascensio System SIA Copyright (c) 2011-2012"
#define COMPONENT_PREFIX			"ASC"

#endif

#define FILE_DESCRIPTION_ACTIVEX	COMPONENT_PREFIX COMPONENT_NAME " ActiveX DLL"
#define	COMPONENT_FILE_NAME_DLL		COMPONENT_PREFIX COMPONENT_NAME ".dll"

#define FILE_DESCRIPTION_DSFILTER	COMPONENT_PREFIX COMPONENT_NAME " DirectShow Filter"
#define	COMPONENT_FILE_NAME_AX		COMPONENT_PREFIX COMPONENT_NAME ".ax"

#define FILE_DESCRIPTION_SERVER		COMPONENT_PREFIX COMPONENT_NAME " Server"
#define	COMPONENT_FILE_NAME_EXE		COMPONENT_PREFIX COMPONENT_NAME ".exe"

#endif //FILEINFO_H_DEFINE
