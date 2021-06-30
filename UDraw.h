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
#include <FMX.Graphics.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Menus.hpp>
//---------------------------------------------------------------------------
class TfmDraw : public TForm
{
__published:	// IDE-managed Components
	TPopupMenu *PopupMenu1;
	TMenuItem *mItem1;
	TMenuItem *mItem2;
	TPaintBox *pb;
	TPaintBox *pb1;
	TPaintBox *pb2;
	TEllipse *Ellipse1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall mItem1Click(TObject *Sender);
	void __fastcall mItem2Click(TObject *Sender);
private:	// User declarations
public:
void activt1();
void activt2();	// User declarations

	__fastcall TfmDraw(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfmDraw *fmDraw;
//extern element EL[100];
//extern usel US[100];
//extern int NE, NU;
void drawLine();
void findMax();
void usDraw();
void sup1YDraw(int i);
void sup1XDraw(int i);
void sup2Draw(int i);
void sup3Draw(int i);
void strengthXDraw(int i);
void strengthYDraw(int i);
void momentDraw(int i);
void pDraw(int i);
void qDraw(int i);
void strengthX2Draw(int i);
void strengthY2Draw(int i);
void moment2Draw(int i);
void clearAll();
void cDraw();

//---------------------------------------------------------------------------
#endif
