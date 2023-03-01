filepath = fileparts(mfilename('fullpath'));
% addpath(filepath,...
%         [filepath filesep 'teensy_ec'],...
%         [filepath filesep 'src'],...
%         [filepath filesep 'sfunctions'],...
%         [filepath filesep 'Utility']);
    
basePath = filepath;    

busdef();
% addpath(genpath('C:\Program Files (x86)\Arduino\hardware\teensy\avr'));

%  FILE PER CARICAMENTO VARIABILI SU AUTOPILOTA %

t_AP = 0.02;

%% SEZIONE CARATTERISTICHE VELIVOLO

V_stall = 11;
V_max = 30;

%% SEZIONE ROTAZIONE SUPERFICI MOBILI

attuatore_Amax = deg2rad(27);
attuatore_Amin = deg2rad(-23);
attuatore_Emax = deg2rad(18);
attuatore_Emin = deg2rad(-32);
attuatore_Rmax = deg2rad(30);
attuatore_Rmin = deg2rad(-30);
attuatore_Tmax = 1;
attuatore_Tmin = 0;

theta_max = deg2rad(15);
theta_min = deg2rad(-15);
phi_max = deg2rad(30);
phi_min = deg2rad(-30);
%% INVERSIONE COMANDI
inv_T = 1;            % inverti motore
inv_E = 1;            % inverti equilibratore
inv_A = -1;            % inverti alettoni
inv_R = 1;            % inverti timone
inv_comp_h = -1;        % inverti compensazione quota
%% SEZIONE SAFE

interventoA_05 = 6;
interventoA_1 = 2;
interventoE_05 = 7.5;
interventoE_1 = 3.2;
interventoT = 0.1;
safe_phi = 55;
safe_V = 40;
time_alarm_SAFE = 1;

%% SEZIONE TUNING GUADAGNI DEI CONTROLLORI 

% IN - PARAMETRI SISTEMA DI CONTROLLO -
Kp_becch = -0.1918*10;                      % Kp controllore beccheggio
Ki_becch = -0.064065*10;                    % Ki controllore beccheggio
Kp_q = -0.025*5;                           % Kp controllore velocita beccheggio
Kp_comp_h = 0.035*15;                       % Kp compensatore di quota

Kp_roll = 0.11*10;                          % Kp controllore rollio
Ki_roll = 0.025*10;                         % Ki controllore rollio
Kp_p = 0.025*5;                            % Kp controllore velocita rollio

Kp_imb = -0.04*10;                         % Kp controllore imbardata

Kp_AP_vel = 0.2692/8;                      % Kp controllore velocita
Ki_AP_vel = 0.001*8;                       % Kp controllore velocita

Kp_AP_quota_hold_h = 0.15;                  % Kp controllore quota ad alte velocita
Kp_AP_quota_hold_l = 1;                     % Kp controllore quota a basse velocita
Kp_AP_quota_select = 0.014;                 % Kp controllore di quota
Ki_AP_quota_select = 0.014;                 % Ki controllore di quota

Kp_AP_rotta = 0.7;  %0.5                    % Kp controllore di rotta
Ki_AP_rotta = 0.03;                         % Ki controllore di rotta
Kd_AP_rotta = 0.9; %0.35                    % Kd controllore di rotta

K_imb_inv = -1;                             % Kp imbardata inversa

K_AW_B_becc = -250;                         % Guadagno bumpless beccheggio
K_AW_B_roll =  500;                         % Guadagno bumpless rollio
K_AW_B_imb = 0;                             % Guadagno bumpless imbardata
K_AW_B_AP_quota = 1000;                     % Guadagno bumpless quota

% IN - GESTIONE CONTROLLORI DI QUOTA
Kp_h_cruise = 0.04;                         % Kp controllore quota in crociera
Ki_h_cruise = 0.008;                        % Ki controllore quota in crociera   

Kp_h_app_max = 0.086;                       % Kp controllore quota in fase di approach
Kp_h_app_min = 0.01;                        % Kp controllore quota in fase di approach
Ki_h_app = 0.055;                           % Ki controllore quota in fase di approach
Kd_h_app = 0.085;                           % Kd controllore quota in fase di approach

Kp_h_flare = 0.1;                          % Kp controllore quota in fase di flare
Ki_h_flare = 0.07;                          % Ki controllore quota in fase di flare
Kd_h_flare = 0.01; 



% IN - CONTROLLORE DI ROTTA -
Kp_Rotta_AL = 5;
Kp_Rotta_ATO = 4;
% IN - CONTROLLORE DI IMBARDATA -
Kp_Rotta_psi = -0.01;

%% PARAMETRI DECOLLO AUTOMATICO

final_h = 35;     %quota finale raggiunta
theta_rot = 10;   % angolo di beccheggio in fase di rotazione



%% SEZIONE WAYPOINT

vel_wp1_al = 25;
vel_wp2_al = 20;