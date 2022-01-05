//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AvertissementUnit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAvertissement_Form *Avertissement_Form;
//---------------------------------------------------------------------------
__fastcall TAvertissement_Form::TAvertissement_Form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAvertissement_Form::BitBtn1Click(TObject *Sender)
{
             MainForm->Timer1->Enabled=false;
             MainForm->Timer2->Enabled=false;
             MainForm->Informations_Panel->Visible=false;
             MainForm->deja_regler=false;
             Close();
             MainForm->Show();        
}
//---------------------------------------------------------------------------

