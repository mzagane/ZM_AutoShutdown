//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>

#define AM_CALLBACK_MESSAGE   WM_APP + 408

//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TSpeedButton *Reglage_SpeedButton;
        TSpeedButton *Fermer_SpeedButton;
        TRadioGroup *Operation_RadioGroup;
        TRadioGroup *Temps_RadioGroup;
        TPanel *Apres_Panel;
        TEdit *nbr_heur_minute_Edit;
        TComboBox *Heur_Minute_ComboBox;
        TPanel *a_Panel;
        TPanel *Informations_Panel;
        TLabel *Informations_Label;
        TPanel *Panel3;
        TSpeedButton *Ok_SpeedButton;
        TSpeedButton *Annuler_SpeedButton;
        TEdit *Heur_Edit;
        TLabel *Label1;
        TTimer *Timer1;
        TTimer *Timer2;
        TLabel *Label2;
        TPopupMenu *PopupMenu;
        TMenuItem *Montrer1;
        TMenuItem *Rglage1;
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall Reglage_SpeedButtonClick(TObject *Sender);
        void __fastcall Fermer_SpeedButtonClick(TObject *Sender);
        void __fastcall Ok_SpeedButtonClick(TObject *Sender);
        void __fastcall Temps_RadioGroupClick(TObject *Sender);
        void __fastcall Annuler_SpeedButtonClick(TObject *Sender);
        bool __fastcall SetPrivilege(AnsiString name, bool grant);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall Label2Click(TObject *Sender);
        void __fastcall Montrer1Click(TObject *Sender);
        void __fastcall Rglage1Click(TObject *Sender);

       //--------

protected:
        void __fastcall NotifyCallback ( TMessage &message );

        BEGIN_MESSAGE_MAP
          VCL_MESSAGE_HANDLER( AM_CALLBACK_MESSAGE, TMessage, NotifyCallback);
        END_MESSAGE_MAP(TForm);
       
       //-------
private:	// User declarations
public:		// User declarations
        AnsiString operation,temps;
        bool deja_regler;//
        int duree;
        TDate date_de_demin;

        NOTIFYICONDATA    NI_Data;

        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
