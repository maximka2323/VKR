//---------------------------------------------------------------------------

#ifndef UDrawH
#define UDrawH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TfmDraw : public TForm
{
__published:	// IDE-managed Components
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TfmDraw(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmDraw *fmDraw;
//---------------------------------------------------------------------------
#endif
