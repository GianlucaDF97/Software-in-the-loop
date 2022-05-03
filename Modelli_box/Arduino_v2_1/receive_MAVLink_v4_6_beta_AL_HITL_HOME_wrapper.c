
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <stdlib.h>
#include "include\mavlink_types.h"
#include "include\ardupilotmega\mavlink.h"
#include "include\protocol.h"
#include "include\checksum.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void receive_MAVLink_v4_6_beta_AL_HITL_HOME_Outputs_wrapper(const uint8_T *bytes_in,
			const int32_T *len_in,
			const uint16_T *count,
			const uint8_T *AP_SI,
			const uint16_T *mem_in,
			const uint8_T *H_mav,
			const uint8_T *H_data_to_AIR_RX,
			const uint8_T *Base_mode_to_SF,
			uint8_T *Heartbeat_data,
			uint32_T *Heartbeat_custom,
			uint8_T *Mav_state,
			uint8_T *int_sw_safe_interv,
			uint8_T *Cal_home,
			uint8_T *Base_mode,
			uint16_T *GC_request,
			real32_T *P_value_change,
			uint16_T *WP_info,
			real32_T *WP_param,
			uint16_T *mem_out,
			uint8_T *T_number,
			real32_T *T_ref,
			uint8_T *Cal_alt,
			uint8_T *T_int,
			uint8_T *P_int,
			real32_T *P_ref,
			const int_T u_width)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/*** MAVLINK STRUTTURA*************
 * [STX LEN SEQ SI CI MI payload CKS1 CKS2]
 * STX= header 254 (0xFE );
 * LEN= lunghezza payload
 * SEQ= counter del messaggio spedito;
 * SI= System ID
 * CI= Component ID
 * MI= tipo di messaggio
 * payload= informazioni da prelevare
 * CKS#= parità
 *
 *********************************/

/*variabili necessarie per l'estrazione*/
uint8_T i;
mavlink_message_t msg;          //messaggio in arrivo
mavlink_status_t status_copy;   //status del messaggio
/* si deve esser sicuri che si azzeri il valore */
GC_request[0]=0;
GC_request[1]=0;

Cal_alt[0]  = 0; // inizilizzazione del parametro per la calibrazione dell'altimetro
Cal_home[0] = 0; // inizilizzazione del parametro per la calibrazione della home (H_LAT)
Cal_home[1] = 0; // inizilizzazione del parametro per la calibrazione della home (H_LONG)
Cal_home[2] = 0; // inizilizzazione del parametro per la calibrazione della home (H_ALT)

T_number[0] = 0; //è riferito alla componente del vettore riferimenti della successiva Matlab Function
T_ref[0]    = 0; //è associato al valore della T di riferimento
T_int[0]    = 0; //è una variabile interruttore che inizializiamo a zero

P_int[0] =0;
P_ref[0] = 101325;

Base_mode[0] = Base_mode_to_SF[0];

// --- Parte relativa all'ingaggio della modalità SAFE e INTERVENTO PILOTA --- //

if ((H_data_to_AIR_RX[2] == 220) && (H_data_to_AIR_RX[3] == 5)) { // è la condizione che si verifica quando si attiva la modalità SAFE
    
    Mav_state[0] = 5; // nella successiva Matlab Function permette si settare H_mav(1) = 220 (MAV_MODE_AUTO_ARMED), H_mav(2) = 5 (MAV_STATE_CRITICAL) e H_mav(3) = 128 (MAV_MODE_FLAG_SAFETY_ARMED)
                      // in questo modo si mantengono il MAV_MODE, il MAV_MODE_FLAG e il MAV_STATE che l'autopilota imposta automaticamente quando scatta l'allarme del SAFE
}
    
else if ((H_data_to_AIR_RX[2] == 216) && (H_data_to_AIR_RX[3] == 4)) { // è la condizione che si verifica quando si attiva la modalità INTERVENTO PILOTA
                                                                            
    Base_mode[0] = 192; // nella successiva Matlab Function permette si settare H_mav(1) = 192 (MAV_MODE_MANUAL_ARMED), H_mav(2) = 4 (MAV_STATE_ACTIVE) e H_mav(3) = 64 (MAV_MODE_FLAG_MANUAL_INPUT_ENABLED)
                        // in questo modo dalla modalità INTERVENTO POILOTA si passa automaticamente alla modalità manuale
}

// --- fine parte aggiunta --- //

if (count[0] == 0) //inizializzazione
{
    mavlink_status_t* status = mavlink_get_channel_status(MAVLINK_COMM_0);
    memset(status, 0, sizeof(mavlink_status_t));
}

if (mem_in[7]!=count[0]) //controllo che è arrivato un messaggio nuovo
    
{
    int len = len_in[0]; //lunghezza buffer
    // Inserisce i bytes, uno alla volta, nel buffer
    for (i=0; i<len; i++)
    {
        uint8_T c = (uint8_T)bytes_in[i];
        uint8_t msg_received = mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status_copy);
        
        if (msg_received) // se ho un msessaggio intero
        {
            // mem_out e mem_in contengono le informazioni della tipologia di messaggio
            mem_out[0]=msg.sysid;    // chi interroga
            mem_out[1]=msg.compid;   // chi interroga
            mem_out[2]=msg.msgid;    // tipo messaggio
            mem_out[3]=msg.len;      // lunghezza del tipo di messaggio
            mem_out[4]=msg.seq;     // messaggio numero # spedito dalla stazione di terra
            mem_out[6]=0;             // led per verifiche
            // per calcolare messaggi persi
            if (mem_out[4]>mem_in[4]) // poi deve per forza essere mem_out[4]>mem_in[4]
            {
                if (mem_out[4]!=(mem_in[4]+1))
                    mem_out[5]=mem_in[5]+(mem_out[4]-mem_in[4]); // numero messaggi persi
                    //mem_out[5]=0;
            }
            else // altrimenti il count si è resettato e quindi resetto anche il conteggio dei messaggi persi
                mem_out[5]=0;

            switch (msg.msgid)      // controllo che tipo di messaggio sta arrivando
            {
                case 0: // HEARTBEAT
                {
                    mavlink_heartbeat_t heart255;  // struttura heartbeat
                    mavlink_msg_heartbeat_decode(&msg, &heart255); // preleva i valori in arrivo e li mette nella struttura
                    Heartbeat_data[0]=heart255.type;
                    Heartbeat_data[1]=heart255.autopilot;
                    Heartbeat_data[2]=heart255.base_mode;
                    Heartbeat_data[3]=heart255.system_status;
                    Heartbeat_custom[0]=heart255.custom_mode;
                    break;
                }
                
                case 76:  // COMMAND_LONG
                {       // mavlink_set_mode_t setmode255;  // struttura setmode
//                         mavlink_msg_set_mode_decode  (&msg, &setmode255);  //preleva i valori in arrivo e li mette nella struttura
//                         if   (setmode255.target_system==AP_SI[0])//pari al SI del UAV !!ATTENZIONE!!
//                         {
//                             Base_mode[0]=setmode255.base_mode;
//                         }
                        mavlink_command_long_t cmd_long255;
                        mavlink_msg_command_long_decode(&msg, &cmd_long255);
                        
                        if (cmd_long255.command == 176) // 176 è l'id di CMD_DO_SET_MODE
                        {
                            Base_mode[0] = cmd_long255.param1; // Base_mode è utilizzato nella successiva Matlab Function e rappresenta il MAV_MODE 
                            Mav_state[0] = cmd_long255.param3; // serve per specificare il MAV_STATE
                            
                            int_sw_safe_interv[0] = 0; // ogni qual volta si setta una modalità di volo l'interruttore del safety switch è posto a zero
                            int_sw_safe_interv[1] = 0; // ogni qual volta si setta una modalità di volo l'interruttore dell'intervento pilota è posto a zero
                        }
                        
                        // Parte aggiunta da sensolini per l'invio della pressione pista prima dell'atterraggio
                        
                        if (cmd_long255.command == 113) // 113 è l'id del messaggio usato
                        {
                            int P_param[7] = {0};
                            P_param[0] = cmd_long255.param1; 
                            P_param[1] = cmd_long255.param2;
                            P_param[2] = cmd_long255.param3;
                            P_param[3] = cmd_long255.param4;
                            P_param[4] = cmd_long255.param5;
                            P_param[5] = cmd_long255.param6;
                            
                            P_ref[0] = (float)(P_param[0])*100000+(float)(P_param[1])*10000+(float)(P_param[2])*1000+(float)(P_param[3])*100+(float)(P_param[4])*10+(float)(P_param[5]);
                            
                            if (P_ref[0] != 101325)
                            {      
                             P_int[0] = 1;
                            }
                          
                        }
                       
                        // Parte aggiunta per l'operazione di calibrazione dell'altimetro e test del safe e dell'intervento pilota durante la fase di pre-flight
                       
                        if (H_mav[1] == 2) { // se è inviato un system_status = 2 che imposta il MAV_STATE come MAV_STATE_CALIBRATING
                            
                            if (cmd_long255.command == 241) { // 241 è l'id di MAV_CMD_PREFLIGHT_CALIBRATION
                        
                                Cal_alt[0] = cmd_long255.param3; // param3 sarà pari a 1 per la calibrazione dell'altimetro (ground pressure)                              
                            }
                                               
                            if (cmd_long255.command == 180) { // 180 è l'id di MAV_CMD_DO_SET_PARAMETER
                        
                                T_number[0] = 13; // è la componente riferita alla temperatura di riferimento dell'altimetro del vettore riferimenti presente nella successiva Matlab Function
                                T_int[0]    = cmd_long255.param1; // funge da interruttore e sarà pari a 1
                                T_ref[0]    = cmd_long255.param2; // param2 è il valore della T di riferimento da impostare da QGC
                            }
							
							if (cmd_long255.command == 179){ // 179 è l'id di MAV_CMD_DO_SET_HOME
                        
                                Cal_home[0] = cmd_long255.param1;
								Cal_home[1] = cmd_long255.param2;
                                Cal_home[2] = cmd_long255.param3;
                            }
                        }
                        
                        if (H_mav[1] == 1) { // se è inviato un system_status = 1 che imposta il MAV_STATE come MAV_STATE_BOOT
                            
                            if (cmd_long255.command == 180) { // 180 è l'id di MAV_CMD_DO_SET_PARAMETER
                                
                                int_sw_safe_interv[0] = cmd_long255.param1; // se voglio testare il safe imposto param1 = 1 e param2 = 0
                                int_sw_safe_interv[1] = cmd_long255.param2; // se voglio testare il safe imposto param1 = 0 e param2 = 1
                            }
                        }
                        
                        // Fine parte aggiunta
                        
                        break;
                }
                
                case 21:  // PARAM_REQUEST_LIST
                {
                    mavlink_param_request_list_t paramrequest255; // struttura param_request_list
                    mavlink_msg_param_request_list_decode(&msg, &paramrequest255); // preleva i valori in arrivo e li mette nella struttura
                    if   (paramrequest255.target_system==AP_SI[0]) // pari al SI del UAV !!ATTENZIONE!!
                    {
                        GC_request[0]=1; // 1 per i parametri 
                        GC_request[1]=255; // tutti i parametri
                    }
                    break;
                }
                
                case 23:  // PARAM_SET
                {
                    mavlink_param_set_t paramset255; // struttura di param_set
                    mavlink_msg_param_set_decode(&msg,&paramset255);
                    if   (paramset255.target_system==AP_SI[0]) // pari al SI del UAV !!ATTENZIONE!!
                    {
                        GC_request[0]=1; // richiesta parametro
                        // dipende dal tipo in questo lavoro sempre con float
                        P_value_change[0]=paramset255.param_value; // nuovo valore da cambiare
                        
                        // gli id che possono arrivare sono:
                        // {"I_HDG", "I_IAS", "I_ALT","I_RC","V_HDG","V_IAS","V_ALT","V_RC"};
                        // visto che arriva come char=uint8 faccio l'if sul decimale corrispondete al carattere
                        // (ho avuto problemi a trattare l'id come stringa)
                        if (paramset255.param_id[0]==73  && paramset255.param_id[1]==95 && paramset255.param_id[2]==72 && paramset255.param_id[3]==68 && paramset255.param_id[4]==71)
                            GC_request[1]=1; // I_HDG
                        else if (paramset255.param_id[0]==73  && paramset255.param_id[1]==95 &&paramset255.param_id[2]==73 && paramset255.param_id[3]==65 && paramset255.param_id[4]==83)
                            GC_request[1]=2; // I_IAS
                        else if (paramset255.param_id[0]==73  && paramset255.param_id[1]==95 &&paramset255.param_id[2]==65 && paramset255.param_id[3]==76 && paramset255.param_id[4]==84)
                            GC_request[1]=3; // I_ALT
                        else if (paramset255.param_id[0]==73  && paramset255.param_id[1]==95 &&paramset255.param_id[2]==82 && paramset255.param_id[3]==67)
                            GC_request[1]=4; // I_RC
                        else if (paramset255.param_id[0]==73  && paramset255.param_id[1]==95 &&paramset255.param_id[2]==87 && paramset255.param_id[3]==80)
                            GC_request[1]=5; // I_WP
                        else if (paramset255.param_id[0]==73  && paramset255.param_id[1]==95 &&paramset255.param_id[2]==65 && paramset255.param_id[3]==84 && paramset255.param_id[4]==79)
                            GC_request[1]=6; // I_ATO
                         else if (paramset255.param_id[0]==73  && paramset255.param_id[1]==95 &&paramset255.param_id[2]==65 && paramset255.param_id[3]==76)
                            GC_request[1]=7; // I_AL
                        
                        else if (paramset255.param_id[0]==86  && paramset255.param_id[1]==95 && paramset255.param_id[2]==72 && paramset255.param_id[3]==68 && paramset255.param_id[4]==71)
                            GC_request[1]=8; // V_HDG
                        else if (paramset255.param_id[0]==86  && paramset255.param_id[1]==95 &&paramset255.param_id[2]==73 && paramset255.param_id[3]==65 && paramset255.param_id[4]==83)
                            GC_request[1]=9; // V_IAS
                        else if (paramset255.param_id[0]==86  && paramset255.param_id[1]==95 &&paramset255.param_id[2]==65 && paramset255.param_id[3]==76 && paramset255.param_id[4]==84)
                            GC_request[1]=10; // V_ALT
                        else if (paramset255.param_id[0]==86  && paramset255.param_id[1]==95 &&paramset255.param_id[2]==82 && paramset255.param_id[3]==67)
                            GC_request[1]=11; // V_RC
                        
                        else
                            GC_request[1]=255; // arriva una richiesta ma non la riconosco e quindi permetto l'invio di tutti i parametri
                    }
                    break;
                }
                
                  case 39:  // MISSION_ITEM
                {
                    mavlink_mission_item_t WP_item255; // struttura mavlink_mission_item
                    mavlink_msg_mission_item_decode(&msg, &WP_item255);
                    if   (WP_item255.target_system==AP_SI[0]) // pari al SI del UAV !!ATTENZIONE!!
                    {
                        GC_request[0]=3; // invio dei WP dalla QGC
                        GC_request[1]=WP_item255.seq;
                        
                        WP_info[1]=WP_item255.seq;
                        WP_info[2]=WP_item255.command;
                        WP_info[3]=WP_item255.frame;
                        WP_info[4]=WP_item255.current;
                        WP_info[5]=WP_item255.autocontinue;
                        
                        WP_param[0]=WP_item255.param2;
                        WP_param[1]=WP_item255.param1;
                        WP_param[2]=WP_item255.param3;
                        WP_param[3]=WP_item255.param4;
                        WP_param[4]=WP_item255.x;
                        WP_param[5]=WP_item255.y;
                        WP_param[6]=WP_item255.z;
                        
                    }
                    break;
                }
                  
                case 40:  // MISSION_REQUEST (richiede un particolare waypoint)
                {
                    mavlink_mission_request_t WP_request255; // struttura mavlink_mission_request
                    mavlink_msg_mission_request_decode(&msg, &WP_request255);
                    if   (WP_request255.target_system==AP_SI[0]) // pari al SI del UAV !!ATTENZIONE!!
                    {
                        GC_request[0]=2; // richiesta WP
                        GC_request[1]=WP_request255.seq; // richiesta del WP numero seq
                    }
                    break;
                }
                
                case 43:  // MISSION_REQUEST_LIST
                {
                    mavlink_mission_request_list_t WP_list255; // struttura  mavlink_mission_request_list
                    mavlink_msg_mission_request_list_decode(&msg, &WP_list255);
                    if   (WP_list255.target_system==AP_SI[0])// pari al SI del UAV !!ATTENZIONE!!
                    {
                        GC_request[0]=2; // richiesta dei WP
                        GC_request[1]=255;
                    }
                    break;
                }
                
                case 44:  // MISSION_COUNT
                {
                    mavlink_mission_count_t WP_cnt255; // struttura mavlink_mission_count
                    mavlink_msg_mission_count_decode(&msg, &WP_cnt255);
                    if   (WP_cnt255.target_system==AP_SI[0])// pari al SI del UAV !!ATTENZIONE!!
                    {
                        GC_request[0]=3; // invio dei WP dalla QGC
                        GC_request[1]=200;
                        WP_info[0]= WP_cnt255.count;
                        WP_info[1]=255; // lo metto 255 evitare conflitti quando arriva il MISSION_ITEM.seq
                    }
                    break;
                }
                
                case 45:  // MISSION_CLEAR
                {
                    mavlink_mission_clear_all_t WP_clear255; //struttura mavlink_clear_all
                    mavlink_msg_mission_clear_all_decode(&msg, &WP_clear255);
                    if   (WP_clear255.target_system==AP_SI[0])//pari al SI del UAV !!ATTENZIONE!!
                    {
                        GC_request[0]=3;   // invio ordine dalla QGC
                        GC_request[1]=250; // cancellare lista

                        memset (WP_info,0,6);
                        memset (WP_param,0,7);
                    }
                    break;
                }
                default:
                {
                    mem_out[6]=255;
                }
            } // fine switch
        } // chiusra msg_received
        else
        {
            mem_out[6]=1;
        }
    } // chiusura for
    
} // fine count

// output
mem_out[7]=count[0];
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


