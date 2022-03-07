
% il 07/03/22 D' alessio, Di micco, Viscione e Perfetti hanno modificato
% questo file seguendo le indicazioni del dottor D' antuono

%% Load Modello Sensori

Ts_base=0.02;

%% GPS


delay_gps=0;
Ts_gps=0.2;%[s]
% il 07/03/22 è stato cambiato seguendo le indicazioni del dottor d' antuono  prima i valori erano quelli commentati 
Std_vel=0.05; %0.71*0.1/5[m/s] 
Var_heading_static=0.1;%[rad]
Var_V_hor=0.5*0.01;%[m/s]
Var_V_hor_static=0.25;%[m/s]

Std_con_lat=2.7349e-07; %[rad]
% il 07/03/22 è stato cambiato seguendo le indicazioni del dottor d' antuono  prima i valori erano quelli commentati 
Std_con_long=1.3733e-06; %9.1555e-07[rad]

Ta_lat=10^2;%[s]
Ta_long=10^2;%[s]

seed_ahrs= randi([0 2000],1,1);
seed_gps= randi([0 2000],1,1);
seed_baro= randi([0 2000],1,1);


%% AHRS
delay_ahrs=0;
Ts_ahrs=0.02; %[s]

beta_phi=1/10.5600; %[1/s]
beta_theta=1/10.5000; %[1/s]
beta_psi=1/170; %[1/s]

White_gm_phi=3.2740e-05; %[rad^2]
White_gm_theta=2.4704e-05; %[rad^2]
White_gm_psi=2.9162e-04; %[rad^2]

% il 07/03/22 è stato cambiato seguendo le indicazioni del dottor d' antuono  prima i valori erano quelli commentati 
White_ax=1.486e-04; %1.9943e-04;%[(m/s^2)^2]
White_ay=9.403e-05;%7.3240e-05;%[(m/s^2)^2]
White_az=1.648e-04; %1.0650e-04;%[(m/s^2)^2]

% il 07/03/22 è stato cambiato seguendo le indicazioni del dottor d' antuono  prima i valori erano quelli moltiplicati per 0 
mean_ax=0*0.0392;%[(m/s^2)^2]
mean_ay=-0*0.0598;%[(m/s^2)^2]
mean_az=0*0.0384;%[(m/s^2)^2]

% il 07/03/22 è stato cambiato seguendo le indicazioni del dottor d' antuono  prima i valori erano quelli commentati
White_p=2.934e-05; %8.7674e-09;%[(rad/s)^2]
White_q=2.887e-05; %9.0090e-09;%[(rad/s)^2]
White_r=3.258e-05; %9.7714e-09;%[(rad/s)^2]

% il 07/03/22 è stato cambiato seguendo le indicazioni del dottor d' antuono  prima i valori erano quelli moltiplicati per 0 
mean_p=0*1.5184e-06;%[(rad/s)]
mean_q=0*2.9671e-05;%[(rad/s)]
mean_r=0*5.4105e-05;%[(rad/s)]

%% Bmp 280
delay_bmp=0;
Ts_bmp=0.02;

% il 07/03/22 è stato cambiato seguendo le indicazioni del dottor d' antuono  prima i valori erano quelli commentati
White_pressione=10.18; %14.2280;%[Pa^2]
P_ref = 1.0074e+05;
T0_ref=25;






