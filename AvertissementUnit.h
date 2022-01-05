//---------------------------------------------------------------------------

#ifndef AvertissementUnitH
#define AvertissementUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TAvertissement_Form : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TBitBtn *BitBtn1;
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAvertissement_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAvertissement_Form *Avertissement_Form;
//---------------------------------------------------------------------------
#endif
