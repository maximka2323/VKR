//---------------------------------------------------------------------------

#ifndef UMasterH
#define UMasterH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TMasterIn : public TForm
{
__published:	// IDE-managed Components
	TGridPanelLayout *GridPanelLayout1;
	TPanel *Panel1;
	TPanel *Panel2;
	TPanel *Panel3;
	TGridPanelLayout *GridPanelLayout2;
	TLabel *Label1;
	TLabel *Label3;
	TEdit *Edit1;
	TButton *BuUSEL;
	TEdit *Edit2;
	TGridPanelLayout *GridPanelLayout3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TButton *BuUS;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TGridPanelLayout *GridPanelLayout4;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TLabel *Label17;
	TLabel *pLabel;
	TLabel *qLabel;
	TLabel *aLabel;
	TEdit *Edit11;
	TEdit *Edit12;
	TEdit *Edit13;
	TEdit *Edit14;
	TEdit *pEdit;
	TEdit *qEdit;
	TEdit *tEdit;
	TLabel *Label22;
	TLabel *Label23;
	TEdit *Edit19;
	TButton *BuEL;
	TEdit *aEdit;
	TStyleBook *StyleBook1;
	TImage *Image1;
	TLabel *Label2;
	TEdit *Edit15;
	TLabel *siLabel;
	TLabel *Label19;
	TEdit *siEdit;
	TGridPanelLayout *GridPanelLayout5;
	TLabel *Label27;
	TLabel *Label18;
	TLabel *Label20;
	void __fastcall BuUSELClick(TObject *Sender);
	void __fastcall BuUSClick(TObject *Sender);
	void __fastcall BuELClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMasterIn(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMasterIn *MasterIn;
//---------------------------------------------------------------------------
#endif
