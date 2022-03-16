%%codice di avvio della simulazione per Aenea, i dati aerodinamici sono
%%salvati in un file .mat che viene richiamato dalla funzione trimCalc per
%%in cui si inserisve anche il valore di velocità iniziale; lo stato
%%iniziale fornito al modello tramite il vettore X0 calcolato come lo stato
%%di uscita dal calcolo del trim
%prova
%%molti dati sono stati copiati dal file di avvio della simulazione di
%%Aenea elaborato lo scorso anno, sono i files che riguardano i dati
%%dell'autopilota
%%input = ('porre che tipo di simulazione voler fare
Ingaggio_AP = input("inserire 1 se si vuole ingaggiare l' AP, 0 altrimenti: ");
Zpista=0;
v2021_10_27_calcoloAerodinamica
costantiMagicFormula =[ 10 1.3 1 0.95 ];
massaRuotePosteriori = m;%[kg]
massaRuotaAnteriore = m;%[kg]
coeffAttritoStatico = 0.7;
limitPup = 500;%[N]
limitPinf = -500; %[N]
limitAup = 500;%[N]
limitAinf = -500; %[N] 
Xa = rmglG(1);
Xp = rngG(1);
precompressione_post_s= +(Xa*9.4*9.81)/(2*(Xa-Xp));
precompressione_post_d= +(Xa*9.4*9.81)/(2*(Xa-Xp));
precompressione_ant= +(-Xp*9.4*9.81)/(2*(Xa-Xp));
load('coefficienti_curve_renard.mat');
v2021_10_27_trimCalc %da questo codice escono i dati iniziali per l'integratore del modello X0 e i comandi iniziali come U0
deltaEtrim=U0(1);
deltaAtrim=U0(2);
deltaRtrim=U0(3);
deltaTtrim=U0(4);
decollo = input('inserire 1 se si vuole simulare il decollo, 0 altrimenti: ');


% %questa parte sostituisce trimCalc per il takeoff
if decollo==1
     U0=[0.001 0.001 0.001 0.001];
     State0.Pos0=[0 0 -0.3925]; %0.3925
     State0.Vb0=[0.01 0 0];
     State0.PHI0=[0 0 0];
     State0.Omega0=[0 0 0];
     State0.Ail0=0;
     State0.Rud0=0;
     State0.Ele0=0;
     dX0= [0 0 0 zeros(1,9)]';
     deltaEtrim=0;
     deltaAtrim=0;
     deltaRtrim=0;
     deltaTtrim=0.1;
end

%FUNDAMENTAL SAMPLE TIME--------------------------------------------------
tsamp=0.02;                             %tempo fondamentale di simulazione si inserisce nel pannello... 
t_AP=0.02;                                        %...di "Configuration parameters" e nella maschera del modello dello yak112



%% ATTUATORI------------------------------------------------------

%Attuatori
attuatore_delay=0.02;                        %ritardo (si prende pari alla frequenza di funzionamento del pc di bordo)
attuatore_pulsazione=100;                     %dinamica: pulsazione naturale 
attuatore_smorzamento=0.85;                  %dinamica: smorzamento 
attuatore_maxrate_manetta=300*pi/180;               %massima velocità di attuazione della manetta 
                                             %DA SPECIFICA 300°/s%  
attuatore_maxrate=300*(pi/180);             %massima velocità di attuazione delle superfici aerodinamiche 
                                             %DA SPECIFICA 300°/s%  
attuatore_Tmax=0.99;                         %saturazione superiore manetta
attuatore_Tmin=0;                           %saturazione inferiore manetta
attuatore_Amax=20*(pi/180);                 %saturazione Eq. ed Alett.
attuatore_Amin=-20*(pi/180);
attuatore_Emax=25*(pi/180);                 %saturazione timone
attuatore_Emin=-25*(pi/180);
attuatore_Rmax=25*(pi/180);                 %saturazione Eq. ed Alett.
attuatore_Rmin=-25*(pi/180);

%% PWM
PWM_Throttle = (deltaTtrim)*800+1100;
PWM_Elevator = rad2deg(deltaEtrim)*(447/50)+(3007/2);
PWM_Aileron = rad2deg(deltaAtrim)*9+1503;
PWM_Rudder = rad2deg(deltaRtrim)*(447/50)+(3007/2);

%% Varianza sensori--------------------------------------------------------

sensori_varianza=0.0000;                         %varianza del segnale dovuta al rumore
sensori_FreqCampionamento=0.02;                 %frequenza di campionamento dei sensori in secondi
sensori_RumoreSampleTime=0.02;                  % Sample Time di rumore dei sensori

sensori_FreqCampionamento_angoli=0.04;
sensori_FreqCampionamento_GPS=1;
sensori_FreqCampionamento_imu=0.04;
sensori_FreqCampionamento_pitot=0.02;
sensori_FreqCampionamento_RPM=0.02;
% 
% % Varianza_Lat = 6.1e-13; % (25 m2)
% % 
% % Varianza_Long = 6.1e-13; % (25 m2)
% % 
% % Varianza_h = 0.8241;
% % 
% % Varianza_v = 1.7e-4;
% % 
% % Varianza_assetto = 6e-5;
% % 
% % Varianza_p = 3.18e-5;
% % 
% % Varianza_q = 2.42e-5;
% % 
% % Varianza_r = 4.18e-5;
% % 
% % Varianza_accx = 4.13e-5;
% % 
% % Varianza_accy = 4.13e-5;
% % 
% % Varianza_accz = 8.29e-5;
% 
% 
% % %%%VARIANZA NULLA
% 
% Varianza_Lat = 0; % (25 m2)
% 
% Varianza_Long = 0; % (25 m2)
% 
% Varianza_h = 0;
% 
% Varianza_v = 0;
% 
% Varianza_assetto = 0;
% 
% Varianza_p = 0;
% 
% Varianza_q = 0;
% 
% Varianza_r = 0;
% 
% Varianza_accx = 0;
% 
% Varianza_accy =0;
% 
% Varianza_accz = 0;

%--------------------------------------------------------------------------

%% Bias sensori------------------------------------------------------------

% Bias_velang = 9.7e-5;
% 
% Bias_acc = 0.02;

Bias_velang = 0;

Bias_acc = 0;

%% INIZIALIZZAZIONE KALMAN

bias_acc_gyro_flag = input('Inserire 1 se si vuole simulare il bias di acc. e gyro, 0 altrimenti: ');

if bias_acc_gyro_flag == 1

    baccxINI =0.0392;%[(m/s^2)^2]
    baccyINI=-0.0598;%[(m/s^2)^2]
    bacczINI=0.0384;%[(m/s^2)^2]

    bpINI = 1.5184e-06;
    bqINI = 2.9671e-05;
    brINI = 5.4105e-05;
else 
    baccxINI = 0;%[(m/s^2)^2]
    baccyINI = 0;%[(m/s^2)^2]
    bacczINI = 0;%[(m/s^2)^2]

    bpINI = 0;
    bqINI = 0;
    brINI = 0;

end

T_cal=0.4;

bias = [baccxINI,baccyINI,bacczINI,bpINI,bqINI,brINI];

Sensor_Offsets=[0,0,0];
 vd_ini=0;
 update=[2,2,2];
run('COV_F1B.m')

run('Load_modello_sensori.m')
%--------------------------------------------------------------------------
%% Condizioni iniziali filtro di Kalman------------------------------------

%%Per partire più da vicino a Fiumicino:
latitudineINI =41.854432*pi/180; % posizione iniziale della simulazione

longitudineINI =12.306650*pi/180; %posizione iniziale della simulazione

HINI = -State0.Pos0(3);
% 
% velnordINI = 25;
% 
% velestINI = -0.05;
% 
% veldownINI = 0;
% 
% vINI = 25;
% 
% phiINI = 0;
% 
% thetaINI = -0.01;
% 
% psiINI = 0;
% 
% accnordINI = 0;
% 
% accestINI = 0;
% 
% accdownINI = 0;
% 
% pINI = 0;
% 
% qINI = 0;
% 
% rINI = 0;
% 
% biasaccxINI = 0.02;
% 
% biasaccyINI = 0.02;
% 
% biasacczINI = 0.02;
% 
% biaspINI = 9.7e-5;
% 
% biasqINI = 9.7e-5;
% 
% biasrINI = 9.7e-5;




%--------------------------------------------------------------------------
%% --- Soglie modalità SAFE --- %%

safe_phi = 55; % soglia sull'angolo di rollio impostata a 45 deg.
safe_V   = 40; % soglia sulla velocità impostata a 40 m/s.

time_alarm_SAFE = 300; % tempo necessario affinché scatti l'allarme del Safe. Se le soglie di sicurezza sono violate per un tempo inferiore a 1 sec l'allarme non scatta.

%% --- Soglie modalità INTERVENTO PILOTA --- %%

% interventoE = 25*0.3; % 30% (7.5 deg) del valore massimo assumibile dall'equilibratore pari a 25 deg.
% interventoA = 20*0.3; % 30% (6 deg) del valore massimo assumibile dall'alettone pari a 20 deg.
% interventoT = 1*0.1;  % 10% del valore massimo di manetta pari a 1; 0.1 sono circa tre scatti di comando della manetta

interventoE_1  = 10;
interventoE_05 = 25*0.8; % 30% (7.5 deg) del valore massimo assumibile dall'equilibratore pari a 25 deg.
interventoA_1  = 10;
interventoA_05 = 20*0.8; % 30% (6 deg) del valore massimo assumibile dall'alettone pari a 20 deg.
interventoT = 1*0.6;  % 10% del valore massimo di manetta pari a 1; 0.1 sono circa tre scatti di comando della manetta

%% Waypoints-----------------------------------------------------------

% WP_db_info= [WP_item255.count,WP_item255.seq,WP_item255.command,WP_item255.frame,
%               WP_item255.current,WP_info[5]=WP_item255.autocontinue]
% WP_db_param= parametri ultimo wp arrivato
%nel caso di NAV i parametri sono:
%waypoints((t_holding), error, traiettoria_di_raccordo, (psi_al_waypoint), x_comandato, y_comandato, h_comandato)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%% Piano di volo (1) %%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% WP_db_info=[0 0 0 0 1 1; ...
%            0 0 0 0 0 1; ...
%            0 0 0 0 0 1; ...
%            0 0 0 0 0 1; ...
%            0 0 0 0 0 1; ...
%            0 0 0 0 0 0];
%       
% WP_db_param=[...
% %            0 10 0 0 41.893013 12.492236 100;... iniziale: SPV
%             0 30 0 0 41.8961440000000 12.4824520000000 100;...
%             0 30 0 0 41.8961440000000 12.4824520000000 200;...
%             0 50 0 0 41.8961440000000 12.4722660000000 200;...
%             0 50 0 0 41.8901130000000 12.4652660000000 200;...
%             0 30 0 0 41.8881300000000 12.4824520000000 200;...
%             0 0 0 0 0 0 0];
         
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%% Piano di volo (2) %%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% WP_db_info=[0 0 0 0 1 1; ...
%            0 0 0 0 0 1; ...
%            0 0 0 0 0 1; ...
%            0 0 0 0 0 1; ...
%            0 0 0 0 0 0; ...
%            0 0 0 0 0 0];
%        
% WP_db_param=[...
% %            0 10 0 0 41.893013 12.492236 100;... iniziale: SPV
%             0 20 0 0 41.8928740000000 12.4935970000000 100;...
%             0 20 0 0 41.8813560000000 12.4945690000000 100;...
%             0 20 0 0 41.8774400000000 12.4958190000000 100;...
%             0 20 0 0 41.8729440000000 12.5040760000000 200;...
%             0 20 0 0 41.8725470000000 12.5147530000000 200;...
%             0 0 0 0 0 0 0];
%         
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%% Piano di volo (3) %%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% WP_db_info=[0 0 0 0 1 1; ...
%             0 0 0 0 0 1; ...
%             0 0 0 0 0 1; ...
%             0 0 0 0 0 1; ...
%             0 0 0 0 0 0; ...
%             0 0 0 0 0 0];
%        
% WP_db_param=[...
% %     0 10 0 0 41.893013 12.492236 100;... iniziale: SPV
%              0 20 0 0 41.8864210000000 12.4937900000000 100;...
%              0 20 0 0 41.8837370000000 12.5032940000000 200;...
%              0 20 0 0 41.8900940000000 12.5082440000000 200;...
%              0 20 0 0 41.8990960000000 12.5054370000000 300;...
%              0 20 0 0 41.9013840000000 12.4973520000000 250;...
%              0 0 0 0 0 0 0];
        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%% Piano di volo (4) %%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% WP_db_info=[0 0 0 0 1 1; ...
%            0 0 0 0 0 1; ...
%            0 0 0 0 0 1; ...
%            0 0 0 0 0 1; ...
%            0 0 0 0 0 0; ...
%            0 0 0 0 0 0];
%       
% WP_db_param=[...
% %            0 10 0 0 41.893013 12.492236 100;... iniziale: SPV
%             0 20 0 0 41.8961440000000 12.4824520000000 100;...
%             0 20 0 0 41.8961440000000 12.4824520000000 200;...
%             0 20 0 0 41.8961440000000 12.4824520000000 300;...
%             0 20 0 0 41.8961440000000 12.4824520000000 400;...
%             0 20 0 0 41.8881300000000 12.4973520000000 200;...
%             0 0 0 0 0 0 0];
         
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% WP_db_info=[4 1 0 0 1 1; ...
%              4 2 0 0 0 1; ...
%              4 3 0 0 0 1; ...
% %            0 0 0 0 0 1; ...
% %            0 0 0 0 0 1; ...
%              4 4 0 0 0 0];
%       
% WP_db_param=[...
% %            0 10 0 0 41.893013 12.492236 100;... iniziale: SPV
%             0 20 0 0 41.9201440000000 12.4824520000000 100;...
%             0 20 0 0 41.9000000000000 12.4624520000000 200;...
%             0 30 0 0 41.8961440000000 12.4722660000000 80;...
% %             0 50 0 0 41.8901130000000 12.4652660000000 200;...
% %             0 30 0 0 41.8881300000000 12.4824520000000 200;...
%             0 0 0 0 0 0 0];
%         
% WP_AL=[...
% %            0 10 0 0 41.893013 12.492236 100;... iniziale: FIUMICINO
%              0 20 0 0 41.782985053032796, 12.2399979829788208 0;...
%              0 20 0 0 41.7858190658835298, 12.2388151288032532 0;...
%              0 0 0 0 0 0 0;...
%              0 0 0 0 0 0 0];      
         
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 WP_db_info=[0 0 0 0 1 3; ...
            0 0 0 0 2 3; ...
            0 0 0 0 3 3; ...
            0 0 0 0 0 0];
       
WP_db_param=[...
%            0 10 0 0 41.893013 12.492236 100;... iniziale: FIUMICINO
             0 20 0 0 41.866171832447606 12.310405300968796 100;...
             0 20 0 0 41.82714927621341 12.309718655460983 150;...
             0 20 0 0 41.79741787696298 12.282601956242233 100;... 
             0 0 0 0 0 0 0];
%         

% WP_AL=[...
% %            0 10 0 0 41.893013 12.492236 100;... iniziale: FIUMICINO
%              0 20 0 0 41.782985053032796, 12.2399979829788208 2.5+0.295;...
%              0 20 0 0 41.7858190658835298, 12.2388151288032532 0];         
%-------------------------------------------------------------------------
%Per atterrare a CIAMPINO
WP_AL=[...
    0 20 0 0 41.807822 12.589274 3; %Posizione del punto di atterraggio
    
    0 20 0 0 41.802983 12.592298 0];%Posizione per determinare la direzione 
                                    %della pista. Se WP_AL(2,6)>WP_AL(1,6)
                                    %allora l'aereo atterra da sinistra
                                    %verso destra. Se WP_AL(2,5)<WP_AL(1,5)
                                    %allora atterra da nord verso sud

%% Dati del Rover 
targetrover = [42.1235406 12.3261368];

%% Caricamento dei data types per l'autopilota

% load('dataTypes.mat')  //caricare questi per avere uscita comandi double
load('SIL_HIL_Bus3.6_ADA_4.mat')  % caricare questi per usare i pwm e il modello nuovo
load('dataTypes.mat','slBus8_comandi') %caricare questo bus editor per usare i comandi senza pwm che danno problemi per ora
load('bus.mat');

%% Parametri decollo automatico--------------------------------------------

final_h = 35;     %quota finale raggiunta
theta_rot = 10;   % angolo di beccheggio in fase di rotazione

quota_gear = 0.295;

Zpista=0;

rotta_takeoff=342*pi/180;

manetta1_ato = 0.5;
manetta2_ato = 0.2;

Kp_Rotta_ATO = 4;  

%% MODIFICA BLOCCO PORPULSIVO
load('coefficienti_curve_renard.mat');

%% Parametri Carrello

costantiMagicFormula =[ 10 1.3 1 0.95 ];
massaRuotePosteriori = m;%[kg]
massaRuotaAnteriore = m;%[kg]
coeffAttritoStatico = 0.7;
limitPup = 500;%[N]
limitPinf = -500; %[N]
limitAup = 500;%[N]
limitAinf = -500; %[N] 
Xa = rmglG(1);
Xp = rngG(1);
precompressione_post_s= +(Xa*9.4*9.81)/(2*(Xa-Xp));
precompressione_post_d= +(Xa*9.4*9.81)/(2*(Xa-Xp));
precompressione_ant= +(-Xp*9.4*9.81)/(2*(Xa-Xp));
%--------------------------------------------------------------------------
%% Parametri atterraggio automatico

vel_landing=18;

rc_landing=-1;

quota_landing=0.295;      %0.295

rotta_landing=342*180/pi;

quota_wp_al = 50;        %quota wp di allineamento
d_wp1_al = -2000;        %distanza wp1-atterraggio
d_wp2_al = -500;         %distanza wp2-atterraggio

vel_wp1_al = 25;         %velocità primo wp
vel_wp2_al = 20;         %velocità secondo wp

Kp_Rotta_AL = 5;           %Giusti???? 
Kp_Rotta_psi = -0.01;   

%% SEZIONE TUNING GUADAGNI DEI CONTROLLORI 

% IN - PARAMETRI SISTEMA DI CONTROLLO -
Kp_becch = -0.30 ;     %-1.4815e-05;     $-0.1918 yak;        %-7.40959372255282;           % Kp controllore beccheggio
Ki_becch = -0.1963 ;   %-4.1591e-06;      %-0.064065 yak;       % -2.47244003255151;        % Ki controllore beccheggio
Kp_q =  -0.025;        %-0.025 yak;           %-1.97308634367886;                           % Kp controllore velocita beccheggio
Kp_comp_h =0.035;      % 0.035;        

Kp_roll =  0.0718;       %0.11;                                                            % Kp controllore rollio
Ki_roll = 0.004528 ;     %0.009451;  %0.025;                                               % Ki controllore rollio
Kp_p =  0.006913;        % 0.009451;   %0.025;                                             % Kp controllore velocita rollio

Kp_imb = 0.0019415;      %0.0180526070977191;   %-0.04;                                    % Kp controllore imbardata

Kp_AP_vel = 0.132175 ;   % 0.15001 %0.0364; % 0.02692;                                % Kp controllore velocita
Ki_AP_vel =  0.025175;   % 0.042175   %0.041588;                                      % Kp controllore velocita

Kp_AP_quota_hold_h = 0.5503;     %  0.1603   %0.7444;          %0.75;                     % Kp controllore quota ad alte velocita
Kp_AP_quota_hold_l = 0.5503;     %  0.09028 %0.7444;          % 0.75;                     % Kp controllore quota a basse velocita
Kp_AP_quota_select = 0.02647;    %  0.02647; % 0.05356;        % 0.03277;                 % Kp controllore di quota
Ki_AP_quota_select = 0.01936;    %  0.01936;  % 0.05743;       % 0.0041;                  % Ki controllore di quota

Kp_AP_rotta = 0.520;            %0.9;   %4.23;  %0.5                                       % Kp controllore di rotta
Ki_AP_rotta = 0.002;            %0.01;      %1;                                            % Ki controllore di rotta
Kd_AP_rotta = 0.995;            %1;   %6.337; %0.35                                        % Kd controllore di rotta

K_imb_inv =-0.001306;             %-1;                                                      % Kp imbardata inversa

K_AW_B_becc = -250;                         % Guadagno bumpless beccheggio
K_AW_B_roll =  500;                         % Guadagno bumpless rollio
K_AW_B_imb = 0;                             % Guadagno bumpless imbardata
K_AW_B_AP_quota = 1000;                     % Guadagno bumpless quota

% IN - GESTIONE CONTROLLORI DI QUOTA
% Kp_h_cruise = 0.04;                         % Kp controllore quota in crociera
% Ki_h_cruise = 0.008;                        % Ki controllore quota in crociera   
% 
% Kp_h_app = 0.046;                           % Kp controllore quota in fase di approach
% Ki_h_app = 0.012;                           % Ki controllore quota in fase di approach
% Kp_rc_app = 0.01;                           % Kp controllore rc in fase di approach
% 
% Kp_h_flare = 0.05;                          % Kp controllore quota in fase di flare
% Ki_h_flare = 0.04;                          % Ki controllore quota in fase di flare
% Kp_rc_flare = 0.07;                         % Kp controllore rc in fase di flare

Kp_h_cruise = 0.04;                         % Kp controllore quota in crociera
Ki_h_cruise = 0.008;                        % Ki controllore quota in crociera   

Kp_h_app_max = 0.086;                       % Kp controllore quota in fase di approach
Kp_h_app_min = 0.01;                        % Kp controllore quota in fase di approach
Ki_h_app = 0.055;                           % Ki controllore quota in fase di approach
Kd_h_app = 0.085;                           % Kd controllore quota in fase di approach

Kp_h_flare = 0.1;                           % Kp controllore quota in fase di flare
Ki_h_flare = 0.07;                          % Ki controllore quota in fase di flare
Kd_h_flare = 0.01;                          % Kp controllore rc in fase di flare



% IN - CONTROLLORE DI ROTTA -
Kp_Rotta_AL = 5;
Kp_Rotta_ATO = 4;
% IN - CONTROLLORE DI IMBARDATA -
Kp_Rotta_psi = -0.01;
%% SEZIONE CARATTERISTICHE VELIVOLO

V_stall = 15;
V_max = 35;

%% INVERSIONE COMANDI
inv_T = 1;            % inverti motore
inv_E = 1;            % inverti equilibratore
inv_A = 1;            % inverti alettoni
inv_R = 1;            % inverti timone
inv_comp_h = 1;        % inverti compensazione quota



