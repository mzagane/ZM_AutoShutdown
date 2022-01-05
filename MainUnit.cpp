//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "AvertissementUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormActivate(TObject *Sender)
{

         MainForm->Height=85;
         Operation_RadioGroup->ItemIndex = 0; // initialisation
         Temps_RadioGroup->ItemIndex =0;      // initialisation
         Informations_Panel->Visible=false;
         deja_regler=false;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Reglage_SpeedButtonClick(TObject *Sender)
{
         if(deja_regler==false)
         {
                  MainForm->Height=266;
                  Informations_Label->Caption="ZM AutoShutDown v1";
                  //duree=0;
         }

         if(deja_regler==true)
         {
                  if(MessageDlg("Le réglage est déja fit, voulez vous refaites le ?",mtWarning,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
                  {
                              MainForm->Height=244;
                              Informations_Panel->Visible=false;
                              deja_regler=false;
                              Timer1->Enabled=false;
                              Timer2->Enabled=false;
                              Informations_Label->Caption="ZM AutoShutDown v1";
                  }
         }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Fermer_SpeedButtonClick(TObject *Sender)
{
         if(MessageDlg("Si vous fermer l'application le réglage ne fonctione pas ! Voulez vous vraiment quiter ?\nCliquez sur 'oui' pour quiter ou sur 'non' pour réduit",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
         {
                  Application->Terminate();// quiter l'application
         }
         else
         {

                 MainForm->Hide();
                 NI_Data.cbSize = sizeof( NOTIFYICONDATA );
                 // Cela permet à Windows de savoir avec quelle version de la structure
                 // on souhaite travailler
                 NI_Data.hWnd = this->Handle;
                 // C'est à ce handle que windows va envoyer les messages provenant de
                 // l'icône : permet de gérer les cliks, etc.
                 NI_Data.uID = 0;
                 // C'est l'identifiant de l'icône dans l'application. Cela permet à
                 // Windows de faire la distinction entre différents icônes de notification
                 // que l'application a crée.
                 NI_Data.hIcon = Application->Icon->Handle;
                 // Par défaut notre icone de notification aura le même icone que
                 // l'application.
                 NI_Data.uCallbackMessage = AM_CALLBACK_MESSAGE;
                 //Permet d'intercepter les messages venant du systray (cliks...)
                 NI_Data.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
                 strcpy(NI_Data.szTip, Informations_Label->Caption.c_str());
                 //Permet de définir le texte de l'infobulle...
                 Shell_NotifyIcon(NIM_ADD,&NI_Data);
         }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Ok_SpeedButtonClick(TObject *Sender)
{

         switch(Operation_RadioGroup->ItemIndex) // l'opération a exécutée
         {
                 case 0 :
                 {
                         operation="ZM AutoShutdown éteindra votre Ordinateur\n";
                         break;
                 }
                 case 1 :
                 {
                         operation="ZM AutoShutdown redémarrera votre Ordinateur\n";
                         break;
                 }
                 case 2 :
                 {
                         operation="ZM AutoShutdown mettra votre Ordinateur en veille\n";
                         break;
                 }
                 case 3 :
                 {
                         operation="ZM AutoShutdown fermera la session\n";
                         break;
                 }
         }


         switch(Temps_RadioGroup->ItemIndex) // le temps de l'execution
         {
                 case 0 :
                 {
                         if(Heur_Minute_ComboBox->Text=="Minutes")
                         {
                                    temps=" à : "+TimeToStr(Time()+StrToTime("00:"+nbr_heur_minute_Edit->Text+":00"));
                         }

                         if(Heur_Minute_ComboBox->Text=="Heurs")
                         {
                                    temps=" à : "+TimeToStr(Time()+StrToTime(nbr_heur_minute_Edit->Text+":00:"+"00"));
                         }

                         if(Heur_Minute_ComboBox->Text=="Secondes")
                         {
                                    temps=" à : "+TimeToStr(Time()+StrToTime("00:00:"+nbr_heur_minute_Edit->Text));
                         }
                         break;
                 }
                 case 1 :
                 {
                         temps=" à : "+Heur_Edit->Text;
                         break;
                 }
         }

         if(Temps_RadioGroup->ItemIndex==0)// aprés un temps
         {
                 if((nbr_heur_minute_Edit->Text!="" && Heur_Minute_ComboBox->Text!=""))
                 {
                         Informations_Label->Caption=operation+temps; // affichage du réglage.
                         Informations_Panel->Visible=true;

                         if(Heur_Minute_ComboBox->Text=="Minutes")
                         {
                                  duree=StrToInt(nbr_heur_minute_Edit->Text)*60;
                                  Timer1->Enabled=true;
                                  deja_regler=true;
                         }
                         if(Heur_Minute_ComboBox->Text=="Heurs")
                         {
                                  duree=StrToInt(nbr_heur_minute_Edit->Text)*60*60;
                                  Timer1->Enabled=true;
                                  deja_regler=true;
                         }
                         if(Heur_Minute_ComboBox->Text=="Secondes")
                         {
                                  duree=StrToInt(nbr_heur_minute_Edit->Text);
                                  Timer1->Enabled=true;
                                  deja_regler=true;
                         }

                 }
                 else
                 {
                         ShowMessage("Veillez choisir un temps complet et correct!");
                 }
         }

         if(Temps_RadioGroup->ItemIndex==1) // à un temps défini
         {

                 if(Heur_Edit->Text!="")
                 {

                         if(StrToTime(Heur_Edit->Text)<Time())// si l'heur de réglage est déja passée
                         {
                                   if(MessageDlg("Cette heur a déjà passé aujourd'hui.  voulez vous  continuer et faire placer pour le demain ?",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
                                   {
                                               Informations_Label->Caption=operation+temps;
                                               Informations_Panel->Visible=true;
                                               deja_regler=true;
                                               date_de_demin=Date()+1;
                                               Timer2->Enabled=true;

                                   }
                                   else
                                   {
                                                deja_regler=false;
                                                MainForm->Height=85;
                                                Operation_RadioGroup->ItemIndex = 0; // initialisation
                                                Temps_RadioGroup->ItemIndex =0;      // initialisation
                                                Informations_Panel->Visible=false;
                                   }
                         }
                         else
                         {
                                   Informations_Label->Caption=operation+temps;
                                   Informations_Panel->Visible=true;
                                   deja_regler=true;
                                   date_de_demin=Date();
                                   Timer2->Enabled=true;

                         }
                 }
                 else
                 {
                         ShowMessage("Veillez choisir un temps complet et correct (exemple: 10:14:00 )");
                 }
         }

         MainForm->Height=85;

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Temps_RadioGroupClick(TObject *Sender)
{
         if(Temps_RadioGroup->ItemIndex==0)
         {
                   Apres_Panel->Enabled=true;
                   a_Panel->Enabled=false;
         }

         else
         {
                   a_Panel->Enabled=true;
                   Apres_Panel->Enabled=false;
                   Heur_Edit->Text=Time()+StrToTime("00:30:00");

         }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Annuler_SpeedButtonClick(TObject *Sender)
{
         MainForm->Height=85;
         Operation_RadioGroup->ItemIndex = 0; // initialisation
         Temps_RadioGroup->ItemIndex =0;      // initialisation
         Informations_Panel->Visible=false;
         Informations_Label->Caption="ZM AutoShutDown v1";
         deja_regler=false;
}
//---------------------------------------------------------------------------

//------------------donner un privilege à une application ---------

/*  Le but de cette fonction est de donner un privilage a notre application pour
que notre application peut arrete tous les applications en cours pour eteidre l'ordinateur.

le parametre name : c'est le nom du privilage .
le parametre grant : si = true pour donner le privilage sinon pour le retirer.

remarque: j'ai trouvé cette fonction dans le FAQ du c++ builder de developez.com */

bool __fastcall TMainForm::SetPrivilege(AnsiString name, bool grant)
{
         TOKEN_PRIVILEGES wTokenIn, wTokenOut;
         DWORD wLength;
         HANDLE wCurrentProcess, wToken;
         _LUID wLuid;
         bool ret;

         wCurrentProcess = GetCurrentProcess();
         OpenProcessToken(wCurrentProcess, TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &wToken);
         LookupPrivilegeValue(NULL, name.c_str(), &wLuid);
         wTokenIn.PrivilegeCount = 1;
         wTokenIn.Privileges[0].Luid = wLuid;
         wTokenIn.Privileges[0].Attributes = (grant?SE_PRIVILEGE_ENABLED:0);
         ret = AdjustTokenPrivileges(wToken, FALSE, &wTokenIn, sizeof(TOKEN_PRIVILEGES), &wTokenOut,&wLength);
         CloseHandle(wToken);

         return ret;
}
//--------------------------------------------------------------------------------


void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{

         if(duree<=60)
         {
                 Application->Restore();
                 Avertissement_Form->Show();
                 Avertissement_Form->Label1->Caption=operation+" aprés "+IntToStr(duree)+ " Secondes";

         }

         if(duree<=0)
         {
                 //*------------------------------- Execution de l'operation ---------------------

                 SetPrivilege("SeShutdownPrivilege",true);// donner le privilage 'SeShutdownPrivilege'

                 switch(Operation_RadioGroup->ItemIndex) // l'opération a exécutée
                 {
                         case 0 :
                         {
                                  ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE,0);// EWX_FORCE :pour forcer les applications à se terminer
                                  break;
                         }
                         case 1 :
                         {
                                  ExitWindowsEx(EWX_REBOOT | EWX_FORCE,0);
                                  break;
                         }
                         case 2 :
                         {
                                  SetSystemPowerState(False,True);
                                  break;
                         }
                         case 3 :
                         {
                                  ExitWindowsEx(EWX_LOGOFF | EWX_FORCE,0);
                                  break;
                         }
                 }
                 SetPrivilege("SeShutdownPrivilege",false);//retirer le privilage 'SeShutdownPrivilege'
                 Timer1->Enabled=false;
          }
         //*-----------------------------------------------------------------------------
          duree=duree-1;


}
//---------------------------------------------------------------------------



void __fastcall TMainForm::Timer2Timer(TObject *Sender)
{
          AnsiString temp="00:00:59";

          if(((StrToTime(Heur_Edit->Text)-Time())<= StrToTime(temp))&&Date()==date_de_demin)
          {
                 Application->Restore();
                 Avertissement_Form->Show();
                 Avertissement_Form->Label1->Caption=operation+" aprés "+TimeToStr((StrToTime(Heur_Edit->Text)-Time()));
          }
          if((StrToTime(Heur_Edit->Text)<=Time())&&Date()==date_de_demin)
          {

                 //*------------------------------- Execution de l'operation ---------------------
                 SetPrivilege("SeShutdownPrivilege",true);// donner le privilage 'SeShutdownPrivilege'

                 switch(Operation_RadioGroup->ItemIndex) // l'opération a exécutée
                 {
                         case 0 :
                         {
                                  ExitWindowsEx(EWX_SHUTDOWN | EWX_FORCE,0);// EWX_FORCE :pour forcer les applications à se terminer
                                  break;
                         }
                         case 1 :
                         {
                                  ExitWindowsEx(EWX_REBOOT | EWX_FORCE,0);
                                  break;
                         }
                         case 2 :
                         {
                                  SetSystemPowerState(False,True);
                                  break;
                         }
                         case 3 :
                         {
                                  ExitWindowsEx(EWX_LOGOFF | EWX_FORCE,0);
                                  break;
                         }
                 }
                 SetPrivilege("SeShutdownPrivilege",false);//retirer le privilage 'SeShutdownPrivilege'
                 Timer2->Enabled=false;
          }
         //*-----------------------------------------------------------------------------

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Label2Click(TObject *Sender)
{
          ShowMessage("ZM AutoShutdown v1\n\ndéveloppé par : ZAAGANE Mohammed\n\nzagmoh2005@yahoo.fr");
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::NotifyCallback(TMessage &message)
{
          if ( message.WParam == 0 )
          // WParam contient l'indice de l'icone de l'appication.
          // En effet une application peut avoir plusieurs icones de notification
          // c'est l'indice que nous avison mis dans uID de la structure de type
          // NOTIFYICONDATA
          {
                 //------------------- double click ----------------------------
                  if ( message.LParam == WM_LBUTTONDBLCLK ) //WM_RBUTTONUP, WM_LBUTTONDOWN...
                  {
                            MainForm->Show();
                            //Sleep(100); //pas indispensable mais si vous avez comme moi l'icône de MSN
		                              //juste à côté de "la votre" vous comprendrez l'utilité :)
                            NI_Data.uFlags = 0;
                            Shell_NotifyIcon(NIM_DELETE,&NI_Data);
                  }
                  //------------------------------------------------------------

                  //-------------------  click boutton droit de la sourri----------------
                  if ( message.LParam == WM_RBUTTONUP ) //réagit quand on relâche le clik droit
                  {
                            PopupMenu->Popup( Mouse->CursorPos.x, Mouse->CursorPos.y );
                            //ouvre un menu popup là où se trouve la souris ;)
                  }
                  //---------------------------------------------------------------------------
          }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Montrer1Click(TObject *Sender)
{
         MainForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Rglage1Click(TObject *Sender)
{
         MainForm->Show();
         Reglage_SpeedButtonClick(this);
}
//---------------------------------------------------------------------------

