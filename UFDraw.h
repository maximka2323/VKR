//---------------------------------------------------------------------------

#ifndef UFDrawH
#define UFDrawH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
//#include "Unit2.h"
//---------------------------------------------------------------------------
class TfmFDraw : public TForm
{
__published:	// IDE-managed Components
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
void FdrawLine();
void FfindMax();
void usFDraw();
void sup1YFDraw(int i);
void sup1XFDraw(int i);
void sup2FDraw(int i);
void sup3FDraw(int i);
void strengthXFDraw(int i);
void strengthYFDraw(int i);
void momentFDraw(int i);
void pFDraw(int i);
void qFDraw(int i);
	__fastcall TfmFDraw(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmFDraw *fmFDraw;
//---------------------------------------------------------------------------

#endif
