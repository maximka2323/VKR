//---------------------------------------------------------------------------

#ifndef UInDataH
#define UInDataH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Grid.hpp>
#include <FMX.Grid.Style.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.Rtti.hpp>
//---------------------------------------------------------------------------
class TfmIn : public TForm
{
__published:	// IDE-managed Components
	TGridPanelLayout *GridPanelLayout3;
	TStringGrid *StringGrid4;
	TFloatColumn *FloatColumn19;
	TFloatColumn *FloatColumn20;
	TStringGrid *StringGrid5;
	TFloatColumn *FloatColumn21;
	TFloatColumn *FloatColumn22;
	TFloatColumn *FloatColumn25;
	TFloatColumn *FloatColumn26;
	TFloatColumn *FloatColumn27;
	TFloatColumn *FloatColumn28;
	TFloatColumn *FloatColumn29;
	TFloatColumn *FloatColumn30;
	TFloatColumn *FloatColumn31;
	TStringGrid *StringGrid6;
	TFloatColumn *FloatColumn23;
	TFloatColumn *FloatColumn24;
	TFloatColumn *FloatColumn32;
	TFloatColumn *FloatColumn33;
	TFloatColumn *FloatColumn34;
	TFloatColumn *FloatColumn35;
	TFloatColumn *FloatColumn173;
	TFloatColumn *FloatColumn174;
	TFloatColumn *FloatColumn36;
	TFloatColumn *FloatColumn37;
	TFloatColumn *FloatColumn38;
	TFloatColumn *FloatColumn39;
	TToolBar *ToolBar1;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfmIn(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmIn *fmIn;
//---------------------------------------------------------------------------
#endif
