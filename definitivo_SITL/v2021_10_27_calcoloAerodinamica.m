%% Coordinate del Baricentro (questa parte aandrà modificata in seguito)
%il punto utilizzato come polo della terna vento rispetto a cui sono calcolati
%forze e momenti nella simulazione aerodinamica sia il centro del bordo
%d'attacco; con questo comando si individua il baricentro sul piano del
%bordo d'attacco abbassato di 15 cm. In realtà, per come viene calcolato il
%momento aerodinamico in assi corpo, le coordinate da individuare in questa
%sezione del codice sono le coordinate del polo della simulazione
%aerodinamica rispetto al sistema di assi corpo centrato nel baricentro.
%Per il polo posto sul bordo di attacco si assume la posizione del
%baricentro posta 15 cm piu in basso del BDA ed allineato con esso, il
%vettore dunque ha coordinate: OGb=[0 0 -0.15]

% In questa sezione vengono inoltre individuati i vettori caratteristici
% dell'aereo risetto ad un sistema di riferimento con origine nel motore;
% per avere un chiarimento visivo cfr. manuale. La lettera P indica appunto
% l'espressione del vettore rispetto a quel punto.
xG=input('inserire la distanza del baricentro da O (base è 0.5): ' );
rGP=[-xG, 0, 0.1075]'; %posizione del baricentro ====>la xG di riferimento è 0.5 m
% rGP=[-xG, 0, 0]'; %test per trovare puntoneutro
rAHRSP=[-0.50, 0, 0.215]'; %posizione del sensore inerziale
rmgrP=[-0.7319, 0.20, 0.50]'; %posizione del carrello principale destro
rmglP=[-0.7319, -0.20, 0.50]'; %posizione del carrello principale sinistro
rngP=[-0.2031, 0, 0.50]'; %posizione del carrello frontale
rLEP=[-0.4789, 0, -0.057]'; %posizione del Leading Edge (polo delle simulazioni aerodinamiche)
% rLEP=[-0.4789, 0, 0]'; % test per trovare il punto neutro
rACwP=[-0.5589, 0, -0.057]'; %posizione del centro aerodinamico dell'ala
rNPP=[-0.7442, 0, -0.057]'; %posizione del punto neutro
rACtP=[-1.834, 0, -0.1028]'; %posizione del centro aerodinamico del piano di coda


%Per centrare le equazioni nel baricentro, vengono espresse le posizioni
%dei punti caratteristici di cui sopra rispetto a un sistema destro
%ortonormale centrato nel baricentro la cui lettera indicativa è G,
%spiegazioni più dettagliate a riguardo si trovano nel manuale sezione
%caricamento dati. La relazione semplice è rG=rP-rGP con rGP vettore del
%baricentro rispetto all'origine designata.

%vettori rispetto al baricentro

rPG=-rGP; %posizione dell'origine== posizione del motore
rAHRSG=rAHRSP-rGP; %posizione del sensore inerziale
rmgrG=rmgrP-rGP; %posizione del carrello principale destro
rmglG=rmglP-rGP; %posizione del carrello principale sinistro
rngG=rngP-rGP; %posizione del carrello frontale
rLEG=rLEP-rGP; %posizione del Leading Edge (polo delle simulazioni aerodinamiche)
rACwG=rACwP-rGP; %posizione del centro aerodinamico dell'ala
rNPG=rNPP-rGP; %posizione del punto neutro
rACtG=rACtP-rGP; %posizione del centro aerodinamico del piano di coda



%questa sezione andrà eventualmente sostituita quando saranno disponibili i
%dati di simulazione nuovi.

%posizione del polo delle simulazini aerodinamiche rispetto al baricentro,
%viene riniminata per essere data come input alle funzioni che calcolano i
%coefficienti di momento che la utilizzano nel prodotto vettoriale delle
%forze per ottenere i momenti rispetto al baricentro

%OGb=rLEG;

XG=rLEG(1);
YG=rLEG(2);
ZG=rLEG(3);

%viene ora espresso il vettore di posizione del motore RISPETTO al
%baricentro (in metri)
Xeng=rPG(1);
Yeng=rPG(2);
Zeng=rPG(3);

Vett_engB=rPG;


%% Dati aero-termodinamici e geometrici e costanti di adimensionalizzazione
P=100129;%Pa
T=287.15;%K
rho=1.21330;%kg/(m^3)
v=15;%m/s
cbar=.32;
c=.32;
b=2.62; %span
S=b*cbar;
CD0=0.024; %0.2 % costante che stava dentro il modello nel calcolo di CD
A=0.5*rho*v^2*S;%Coefficiente per adimensionalizzare le forze
B=0.5*rho*v^2*S*b;%Coefficiente per adimensionalizzare i momenti lat-dir
K=0.5*rho*v^2*S*cbar;%%Coefficiente per adimensionalizzare il mom di becchegg.
Rprop=0.2667; %[m]
Dprop=2*Rprop;
mprop=0.178; %[Kg]
Jprop=mprop*(Dprop^2)/12; %J=m/12*l^2 [Kg/m^2]
Jeng=0; %[Kg/m^2]
m=9.4; %[kg]
g=[0 0 9.81]'; %[m/s^2]
W=m*g; %[N]
Ix=1.4070; %[kg*m^2]
Iy=1.7596; %[kg*m^2]
Iz=3.0127; %[kg*m^2]
Ixz=0.2095;%[kg*m^2]
Kn=(rGP(1)-rNPP(1))/cbar; %margine statico Kn=hn-h


I=[Ix 0 -Ixz;0 Iy 0;-Ixz 0 Iz];


%% Dati Aerodinamici e Geometrici con Rover e Fotocamera

RF_m = 10.30; %[kg]
RF_rGP=[-0.505, 0, 0.1165]'; %posizione del baricentro 
RF_W = RF_m*g; %[N]
RF_Ix = 0.6909; %[kg*m^2]
RF_Iy = 3.1671; %[kg*m^2]
RF_Iz = 3.3103; %[kg*m^2]
RF_Ixz = 0.4568; %[kg*m^2]
RF_Kn = (RF_rGP(1) - rNPP(1))/cbar; 

RF_I = [RF_Ix 0 -RF_Ixz; 0 RF_Iy 0; -RF_Ixz 0 RF_Iz];








alphavec=[-6:6];
betavec=[-12:4:12];

alphavec_rad=deg2rad(alphavec);
betavec_rad=deg2rad(betavec);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%caricamento della funzione di calcolo delle polari
[CD,CY,CL,CMxw,CMyw,CMzw,Cl,Cm,Cn,CFxb,CFyb,CFzb]=calcoloPolari(rLEG,A,B,K);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Calcolo delle derivate di stabilità
% calcolo CL_alpha
%in assi vento
CL_alpha=CL(9,5)-CL(8,5); % CL_alfa [1/deg]
CL_alpharad=CL_alpha*180/pi; %[1/rad]
CL0=CL(8,5);
alpha_portanzanulla=CL0/CL_alpha;
%alpha_portanza_nulla=-KCL(2)/KCL(1);

%calcolo CY_beta
CY_beta=CY(8,6)/4; %[1/deg]
CY_betarad=CY_beta*180/pi; %[1/rad]

%Cl_beta
Cl_beta=Cl(8,6)/4; %[1/deg]
Cl_betarad=Cl_beta*180/pi; %[1/rad]

%Cm_alpha in assi corpo
Cm_alpha=Cm(9,5)-Cm(8,5); % Cmalpha [1/deg]
Cm_alpharad=Cm_alpha*180/pi; %[1/rad]
Cm0=Cm(8,5); % Cm di alfa uguale a 0

%Cn_beta
Cn_beta=Cn(8,6)/4; %[1/deg]
Cn_betarad=Cn_beta*180/pi; %[1/rad]

%% Calcolo delle derivate di controllo dell'equilibratore

[KCmdE,KCLdE,CmdE,CLdE]=Equilibratore(rLEG,A,B,K);

%% Calcolo delle derivate di controllo degli alettoni

[CYdA,CldA,CndA,KCYdA,KCldA,KCndA]=Alettoni(rLEG,A,B,K);

%% Calcolo delle derivate di controllo del timone

[CYdR,CldR,CndR,KCYdR,KCldR,KCndR]=Timone(rLEG,A,B,K);

%% Derivate p q r Andia   FUNZIONANO!!!
CLp =   0;              
CLq =   8.13;%19.166;      
CLr =  0;
CYp =   0.050728;       
CYq =    0;         
CYr =  0.358925;
Clp =  -0.4318;%-0.5058;        
Clq =    0;         
Clr =  0.1459;
Cmp =   0;              
Cmq =  -23.24;%-81.796;     
Cmr =  0;
Cnp =   0.007507;%2.94*10^-4 ;    
Cnq =    0;         
Cnr = -0.4872;%-1.2593;

%%  Caricamento dei dati dell'elica tramite file mat
% i dati sono stati calcolati nella cartella ELICA dove si possono trovare
% i dati prestazionali dell'elica [APC-prop 21x13E] presi dal sito ufficiale 
% di apc prop e manipolati adeguatamente per generare le tabelle Ct e Cp
% contenenti i coefficienti di spinta e potenza al variare del rapporto di
% avanzamento e dei giri al minuto RPM

load('PropLUT.mat')
%% ATTUATORI------------------------------------------------------

%Attuatori
attuatore_delay=0.02;                        %ritardo (si prende pari alla frequenza di funzionamento del pc di bordo)
attuatore_pulsazione=100;                     %dinamica: pulsazione naturale 
attuatore_smorzamento=0.85;                  %dinamica: smorzamento 
attuatore_maxrate_manetta=300*pi/180;               %massima velocità di attuazione della manetta 
                                             %DA SPECIFICA 300°/s%  
attuatore_maxrate=300*(pi/180);             %massima velocità di attuazione delle superfici aerodinamiche 
                                             %DA SPECIFICA 300°/s%  

attuatore_Amax=20*(pi/180);                 %saturazione Eq. ed Alett.
attuatore_Emax=25*(pi/180);                 %saturazione timone
attuatore_Rmax=25*(pi/180);                 %saturazione Eq. ed Alett.
