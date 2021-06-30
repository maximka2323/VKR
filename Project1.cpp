//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("UOutD.cpp", fmOutD);
USEFORM("UOutData.cpp", fmOut);
USEFORM("URef.cpp", fmRef);
USEFORM("UInData.cpp", fmIn);
USEFORM("UDraw.cpp", fmDraw);
USEFORM("UHead.cpp", Form1);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TfmDraw), &fmDraw);
		Application->CreateForm(__classid(TfmRef), &fmRef);
		Application->CreateForm(__classid(TfmIn), &fmIn);
		Application->CreateForm(__classid(TfmOut), &fmOut);
		Application->CreateForm(__classid(TfmOutD), &fmOutD);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
