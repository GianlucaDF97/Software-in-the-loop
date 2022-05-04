%% Spiegazione notazione
% questo script realizza la scrittura delle tabelle di forze e momenti
% aerodinamici e coefficienti di forza e momento aerodinamici in assi
% vento ed assi terra.
% Le tabelle risultanti hanno nella prima colonna gli angoli di attacco e
% nella prima riga gli angoli di derapata.
% Nella cartella POLARI ci sono i risultati in termini di forze e momenti
% non adimensionalizzati ricavati tramite simulazioni CFD.
% Le simulazioni CFD calcolano forze e momenti aerodinamici in assi vento
% usando come polo il bordo d'accacco dell'ala.
% In una seconda fase sarà quindi necessario spostare i risultati nel 
% baricentro e ruotare (tramite matrici di rotazione) i risultati per 
% scriverli nella terna body.
% Si noti che nella sezione "Coordinate del Baricentro" è possibile
% inserire le coordinate del baricentro (posizione relativa rispetto al
% bordo d'attacco).
% Il sistema di riferimento vede l'asse x positivo perso prua, l'asse y
% verso la destra del pilota e l'asse z verso il basso.
% I principali output di questo script sono:
% !!ATTENZIONE!! se si parla di forza Fxw (forza lungo xwind) 
% questa sarà l'opposto della resistenza aerodinamica!!!! e così per tutte
% le tabelle delle forze in assi vento!!!!!!!!
% Per le tabelle dei momenti invece, il momento Mxb coincide di fatto con
% il momento di rollio e così per tutte le derivate di momento!!!!!
% I principali output di questo script sono:
% CFxb/CFxw-> coefficiente di forza lungo x in assi body/wind
% CFyb/CFyw-> coefficiente di forza lungo y in assi body/wind
% CFzb/CFzw-> coefficiente di forza lungo z in assi body/wind
% CMxb/CMxw-> coefficiente di momento attorno a x body/wind
% CMyb/CMyw-> coefficiente di momento attorno a y body/wind
% CMzb/CMzw-> coefficiente di momento attorno a x body/wind

% CD-> coefficiente di resistenza(tabella uguale a CFxw ma con segno opposto)
% CL-> coefficiente di portanza(tabella uguale a CFzw ma con segno opposto)
% CY-> coefficiente di forza lungo y (tabella uguale a CFyw)
% per CY non si ha l'inversione di segno perché la convenzione della
% dinamica del volo è di considerare la forza lungo y e non la devianza
% se si volesse ottenere il coefficiente di devianza CC bisognerebbe
%semplicemente cambiare il segno delle entrate della tabella CY

% Cm-> tabella coeff. di mom. di beccheggio (tabella uguale a CMyb)
% Cl-> tabella coeff. di mom. di rollio (tabella uguale a CMxb)
% Cn-> tabella coeff. di mom. di imbardata (tabella uguale a CMzb)

% La notazione per le tabelle di Forza e Momento in assi sia corpo che
% vento è identica. Ma nel caso di forze e momenti non adimensionalizzati
% le tabelle non hanno nella prima colonna e nella prima riga gli angoli di
% attacco e di derapata. Infatti si noti che le tabelle di coefficienti di
% forza e momento hanno dimensioni 14x8 mentre le tabelle di forza e
% momento hanno dimensione 13x8


% Per il calcolo delle derivate aerodinamiche e di controllo il processo è
% svolto facendo un interpolazione lineare delle curve tramite la funzione
% polyfit di matlab andando a 
% prendere il coefficiente angolare delle rette interpolanti, i risultati
% così trovati sono poi moltiplicati per 180 e divisi per pigreco per
% ottenere rad^-1 come unità di misura.

% Chi utilizza questo codice si ricordi che qualiasi risultato contenuto
% nelle cartelle ALETTONI EQUILIBRATORE POLARI e TIMONE è frutto
% dell'analisi CFD basata su un sistema di assi vento centrato nel bordo di
% attacco dell'ala e perciò qualsiasi risultato di momento sarà prima
% spostato nel baricentro (con la formula per spostare i momenti) e poi
% sarà eventualmente ruotato con una matrice di rotazione per ottenere lo
% stesso momento nella terna body.
% Le simulazioni per le superfici di controllo, tuttavia, sono state fatte
% ad angolo di attacco ed angolo di derapata nulla (variando solo le
% rotazioni delle superfici di controllo), quindi nel caso di ALETTONI
% EQUILIBRATORE e TIMONE la terna wind e la terna body coincidono ed in
% fase di post-processing dei risultati è solo necessario spostare i
% risultati nel baricentro e non è necessaria una matrice di rotazione per
% passare dalla terna wind alla terna body.

% Le derivate di stabilità sono:

% Cm0 (coeff. di momento di beccheggio in corrispondenza dell'angolo di
% attacco tale che la portanza è nulla)
% CLa = derivata del coeff. di portanza rispetto all'angolo di attacco
% CYb = derivata del coeff. di forza parallela all'asse Y rispetto
% all'angolo di derapata
% Cma = derivata del coeff di momento di beccheggio rispetto all'angolo di
% attacco
% Clb = derivata del coeff di momento di rollio rispetto all'angolo di
% derapata
% Cnb = derivata del coefficiente di momento di imbardata rispetto
% all'angolo di derapata
% CLdE = efficacia di controllo dell'equilibratore
% CmdE = potenza di controllo dell'equilibratore
% CldR = derivata del coeff di momento di rollio rispetto alla rotazione
% della superficie del timone
% CndR = derivata del coeff di momento di imbardata rispetto alla rotazione
% della superficie del timone
% CldA = derivata del coeff di momento di rollio rispetto alla rotazione
% della superficie degli alettoni (antisimmetrica, ovviamente)
% CndA = derivata del coeff di momento di imbardata rispetto alla rotazione
% della superficie degli alettoni.

% dE = angoli dell'equilibratore
% dA = angoli degli alettoni
% dR = angolo del timone
%% Inizializzazione
clear all
clc
close all

%% Coordinate del Baricentro
XG=-0.128;
YG=0.;
ZG=0.;

%% Dati aero-termodinamici e geometrici e costanti di adimensionalizzazione
P=100000;%Pa
T=300;%K
rho=P/(287.05*T);
v=15;%m/s
c=.32;
b=2.62;
S=b*c;
A=1/2*rho*v^2*S;%Coefficiente per adimensionalizzare le forze
B=1/2*rho*v^2*S*b;%Coefficiente per adimensionalizzare le grandezze lat-dir
K=1/2*rho*v^2*S*c;%%Coefficiente per adimensionalizzare il mom di becchegg.
alpha=-6:6;
beta=-12:4:12;

%% Importazione dei CFD e creazione delle tabelle di in assi wind
% Le forze aerodinamiche in assi vento avranno i nomi convenzionalmente 
% utilizzati mentre i momenti hanno il pedice w per indicare assi wind
% (vento)

cd POLARI
cd BETA=0

cd ALPHA=-6
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(1,1)=-minfo1_e1(end,3);
C(1,1)=-minfo1_e2(end,3);
L(1,1)=-minfo1_e3(end,3);
Mxw(1,1)=minfo1_e4(end,3);
Myw(1,1)=minfo1_e5(end,3);
Mzw(1,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-5
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(2,1)=-minfo1_e1(end,3);
C(2,1)=-minfo1_e2(end,3);
L(2,1)=-minfo1_e3(end,3);
Mxw(2,1)=minfo1_e4(end,3);
Myw(2,1)=minfo1_e5(end,3);
Mzw(2,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-4
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(3,1)=-minfo1_e1(end,3);
C(3,1)=-minfo1_e2(end,3);
L(3,1)=-minfo1_e3(end,3);
Mxw(3,1)=minfo1_e4(end,3);
Myw(3,1)=minfo1_e5(end,3);
Mzw(3,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-3
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(4,1)=-minfo1_e1(end,3);
C(4,1)=-minfo1_e2(end,3);
L(4,1)=-minfo1_e3(end,3);
Mxw(4,1)=minfo1_e4(end,3);
Myw(4,1)=minfo1_e5(end,3);
Mzw(4,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-2
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(5,1)=-minfo1_e1(end,3);
C(5,1)=-minfo1_e2(end,3);
L(5,1)=-minfo1_e3(end,3);
Mxw(5,1)=minfo1_e4(end,3);
Myw(5,1)=minfo1_e5(end,3);
Mzw(5,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-1
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(6,1)=-minfo1_e1(end,3);
C(6,1)=-minfo1_e2(end,3);
L(6,1)=-minfo1_e3(end,3);
Mxw(6,1)=minfo1_e4(end,3);
Myw(6,1)=minfo1_e5(end,3);
Mzw(6,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=0
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(7,1)=-minfo1_e1(end,3);
C(7,1)=-minfo1_e2(end,3);
L(7,1)=-minfo1_e3(end,3);
Mxw(7,1)=minfo1_e4(end,3);
Myw(7,1)=minfo1_e5(end,3);
Mzw(7,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=1
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(8,1)=-minfo1_e1(end,3);
C(8,1)=-minfo1_e2(end,3);
L(8,1)=-minfo1_e3(end,3);
Mxw(8,1)=minfo1_e4(end,3);
Myw(8,1)=minfo1_e5(end,3);
Mzw(8,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=2
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(9,1)=-minfo1_e1(end,3);
C(9,1)=-minfo1_e2(end,3);
L(9,1)=-minfo1_e3(end,3);
Mxw(9,1)=minfo1_e4(end,3);
Myw(9,1)=minfo1_e5(end,3);
Mzw(9,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=3
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(10,1)=-minfo1_e1(end,3);
C(10,1)=-minfo1_e2(end,3);
L(10,1)=-minfo1_e3(end,3);
Mxw(10,1)=minfo1_e4(end,3);
Myw(10,1)=minfo1_e5(end,3);
Mzw(10,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=4
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(11,1)=-minfo1_e1(end,3);
C(11,1)=-minfo1_e2(end,3);
L(11,1)=-minfo1_e3(end,3);
Mxw(11,1)=minfo1_e4(end,3);
Myw(11,1)=minfo1_e5(end,3);
Mzw(11,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=5
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(12,1)=-minfo1_e1(end,3);
C(12,1)=-minfo1_e2(end,3);
L(12,1)=-minfo1_e3(end,3);
Mxw(12,1)=minfo1_e4(end,3);
Myw(12,1)=minfo1_e5(end,3);
Mzw(12,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=6
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(13,1)=-minfo1_e1(end,3);
C(13,1)=-minfo1_e2(end,3);
L(13,1)=-minfo1_e3(end,3);
Mxw(13,1)=minfo1_e4(end,3);
Myw(13,1)=minfo1_e5(end,3);
Mzw(13,1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..
cd ..

cd BETA=4

cd ALPHA=-6
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(1,2)=-minfo1_e1(end,3);
C(1,2)=-minfo1_e2(end,3);
L(1,2)=-minfo1_e3(end,3);
Mxw(1,2)=minfo1_e4(end,3);
Myw(1,2)=minfo1_e5(end,3);
Mzw(1,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-5
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(2,2)=-minfo1_e1(end,3);
C(2,2)=-minfo1_e2(end,3);
L(2,2)=-minfo1_e3(end,3);
Mxw(2,2)=minfo1_e4(end,3);
Myw(2,2)=minfo1_e5(end,3);
Mzw(2,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-4
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(3,2)=-minfo1_e1(end,3);
C(3,2)=-minfo1_e2(end,3);
L(3,2)=-minfo1_e3(end,3);
Mxw(3,2)=minfo1_e4(end,3);
Myw(3,2)=minfo1_e5(end,3);
Mzw(3,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-3
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(4,2)=-minfo1_e1(end,3);
C(4,2)=-minfo1_e2(end,3);
L(4,2)=-minfo1_e3(end,3);
Mxw(4,2)=minfo1_e4(end,3);
Myw(4,2)=minfo1_e5(end,3);
Mzw(4,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-2
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(5,2)=-minfo1_e1(end,3);
C(5,2)=-minfo1_e2(end,3);
L(5,2)=-minfo1_e3(end,3);
Mxw(5,2)=minfo1_e4(end,3);
Myw(5,2)=minfo1_e5(end,3);
Mzw(5,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-1
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(6,2)=-minfo1_e1(end,3);
C(6,2)=-minfo1_e2(end,3);
L(6,2)=-minfo1_e3(end,3);
Mxw(6,2)=minfo1_e4(end,3);
Myw(6,2)=minfo1_e5(end,3);
Mzw(6,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=0
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(7,2)=-minfo1_e1(end,3);
C(7,2)=-minfo1_e2(end,3);
L(7,2)=-minfo1_e3(end,3);
Mxw(7,2)=minfo1_e4(end,3);
Myw(7,2)=minfo1_e5(end,3);
Mzw(7,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=1
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(8,2)=-minfo1_e1(end,3);
C(8,2)=-minfo1_e2(end,3);
L(8,2)=-minfo1_e3(end,3);
Mxw(8,2)=minfo1_e4(end,3);
Myw(8,2)=minfo1_e5(end,3);
Mzw(8,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=2
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(9,2)=-minfo1_e1(end,3);
C(9,2)=-minfo1_e2(end,3);
L(9,2)=-minfo1_e3(end,3);
Mxw(9,2)=minfo1_e4(end,3);
Myw(9,2)=minfo1_e5(end,3);
Mzw(9,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=3
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(10,2)=-minfo1_e1(end,3);
C(10,2)=-minfo1_e2(end,3);
L(10,2)=-minfo1_e3(end,3);
Mxw(10,2)=minfo1_e4(end,3);
Myw(10,2)=minfo1_e5(end,3);
Mzw(10,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=4
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(11,2)=-minfo1_e1(end,3);
C(11,2)=-minfo1_e2(end,3);
L(11,2)=-minfo1_e3(end,3);
Mxw(11,2)=minfo1_e4(end,3);
Myw(11,2)=minfo1_e5(end,3);
Mzw(11,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=5
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(12,2)=-minfo1_e1(end,3);
C(12,2)=-minfo1_e2(end,3);
L(12,2)=-minfo1_e3(end,3);
Mxw(12,2)=minfo1_e4(end,3);
Myw(12,2)=minfo1_e5(end,3);
Mzw(12,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=6
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(13,2)=-minfo1_e1(end,3);
C(13,2)=-minfo1_e2(end,3);
L(13,2)=-minfo1_e3(end,3);
Mxw(13,2)=minfo1_e4(end,3);
Myw(13,2)=minfo1_e5(end,3);
Mzw(13,2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..
cd ..

cd BETA=8

cd ALPHA=-6
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(1,3)=-minfo1_e1(end,3);
C(1,3)=-minfo1_e2(end,3);
L(1,3)=-minfo1_e3(end,3);
Mxw(1,3)=minfo1_e4(end,3);
Myw(1,3)=minfo1_e5(end,3);
Mzw(1,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-5
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(2,3)=-minfo1_e1(end,3);
C(2,3)=-minfo1_e2(end,3);
L(2,3)=-minfo1_e3(end,3);
Mxw(2,3)=minfo1_e4(end,3);
Myw(2,3)=minfo1_e5(end,3);
Mzw(2,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-4
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(3,3)=-minfo1_e1(end,3);
C(3,3)=-minfo1_e2(end,3);
L(3,3)=-minfo1_e3(end,3);
Mxw(3,3)=minfo1_e4(end,3);
Myw(3,3)=minfo1_e5(end,3);
Mzw(3,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-3
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(4,3)=-minfo1_e1(end,3);
C(4,3)=-minfo1_e2(end,3);
L(4,3)=-minfo1_e3(end,3);
Mxw(4,3)=minfo1_e4(end,3);
Myw(4,3)=minfo1_e5(end,3);
Mzw(4,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-2
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(5,3)=-minfo1_e1(end,3);
C(5,3)=-minfo1_e2(end,3);
L(5,3)=-minfo1_e3(end,3);
Mxw(5,3)=minfo1_e4(end,3);
Myw(5,3)=minfo1_e5(end,3);
Mzw(5,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-1
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(6,3)=-minfo1_e1(end,3);
C(6,3)=-minfo1_e2(end,3);
L(6,3)=-minfo1_e3(end,3);
Mxw(6,3)=minfo1_e4(end,3);
Myw(6,3)=minfo1_e5(end,3);
Mzw(6,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=0
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(7,3)=-minfo1_e1(end,3);
C(7,3)=-minfo1_e2(end,3);
L(7,3)=-minfo1_e3(end,3);
Mxw(7,3)=minfo1_e4(end,3);
Myw(7,3)=minfo1_e5(end,3);
Mzw(7,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=1
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(8,3)=-minfo1_e1(end,3);
C(8,3)=-minfo1_e2(end,3);
L(8,3)=-minfo1_e3(end,3);
Mxw(8,3)=minfo1_e4(end,3);
Myw(8,3)=minfo1_e5(end,3);
Mzw(8,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=2
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(9,3)=-minfo1_e1(end,3);
C(9,3)=-minfo1_e2(end,3);
L(9,3)=-minfo1_e3(end,3);
Mxw(9,3)=minfo1_e4(end,3);
Myw(9,3)=minfo1_e5(end,3);
Mzw(9,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=3
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(10,3)=-minfo1_e1(end,3);
C(10,3)=-minfo1_e2(end,3);
L(10,3)=-minfo1_e3(end,3);
Mxw(10,3)=minfo1_e4(end,3);
Myw(10,3)=minfo1_e5(end,3);
Mzw(10,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=4
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(11,3)=-minfo1_e1(end,3);
C(11,3)=-minfo1_e2(end,3);
L(11,3)=-minfo1_e3(end,3);
Mxw(11,3)=minfo1_e4(end,3);
Myw(11,3)=minfo1_e5(end,3);
Mzw(11,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=5
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(12,3)=-minfo1_e1(end,3);
C(12,3)=-minfo1_e2(end,3);
L(12,3)=-minfo1_e3(end,3);
Mxw(12,3)=minfo1_e4(end,3);
Myw(12,3)=minfo1_e5(end,3);
Mzw(12,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=6
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(13,3)=-minfo1_e1(end,3);
C(13,3)=-minfo1_e2(end,3);
L(13,3)=-minfo1_e3(end,3);
Mxw(13,3)=minfo1_e4(end,3);
Myw(13,3)=minfo1_e5(end,3);
Mzw(13,3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..
cd ..

cd BETA=12

cd ALPHA=-6
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(1,4)=-minfo1_e1(end,3);
C(1,4)=-minfo1_e2(end,3);
L(1,4)=-minfo1_e3(end,3);
Mxw(1,4)=minfo1_e4(end,3);
Myw(1,4)=minfo1_e5(end,3);
Mzw(1,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-5
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(2,4)=-minfo1_e1(end,3);
C(2,4)=-minfo1_e2(end,3);
L(2,4)=-minfo1_e3(end,3);
Mxw(2,4)=minfo1_e4(end,3);
Myw(2,4)=minfo1_e5(end,3);
Mzw(2,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-4
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(3,4)=-minfo1_e1(end,3);
C(3,4)=-minfo1_e2(end,3);
L(3,4)=-minfo1_e3(end,3);
Mxw(3,4)=minfo1_e4(end,3);
Myw(3,4)=minfo1_e5(end,3);
Mzw(3,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-3
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(4,4)=-minfo1_e1(end,3);
C(4,4)=-minfo1_e2(end,3);
L(4,4)=-minfo1_e3(end,3);
Mxw(4,4)=minfo1_e4(end,3);
Myw(4,4)=minfo1_e5(end,3);
Mzw(4,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-2
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(5,4)=-minfo1_e1(end,3);
C(5,4)=-minfo1_e2(end,3);
L(5,4)=-minfo1_e3(end,3);
Mxw(5,4)=minfo1_e4(end,3);
Myw(5,4)=minfo1_e5(end,3);
Mzw(5,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=-1
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(6,4)=-minfo1_e1(end,3);
C(6,4)=-minfo1_e2(end,3);
L(6,4)=-minfo1_e3(end,3);
Mxw(6,4)=minfo1_e4(end,3);
Myw(6,4)=minfo1_e5(end,3);
Mzw(6,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=0
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(7,4)=-minfo1_e1(end,3);
C(7,4)=-minfo1_e2(end,3);
L(7,4)=-minfo1_e3(end,3);
Mxw(7,4)=minfo1_e4(end,3);
Myw(7,4)=minfo1_e5(end,3);
Mzw(7,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=1
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(8,4)=-minfo1_e1(end,3);
C(8,4)=-minfo1_e2(end,3);
L(8,4)=-minfo1_e3(end,3);
Mxw(8,4)=minfo1_e4(end,3);
Myw(8,4)=minfo1_e5(end,3);
Mzw(8,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=2
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(9,4)=-minfo1_e1(end,3);
C(9,4)=-minfo1_e2(end,3);
L(9,4)=-minfo1_e3(end,3);
Mxw(9,4)=minfo1_e4(end,3);
Myw(9,4)=minfo1_e5(end,3);
Mzw(9,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=3
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(10,4)=-minfo1_e1(end,3);
C(10,4)=-minfo1_e2(end,3);
L(10,4)=-minfo1_e3(end,3);
Mxw(10,4)=minfo1_e4(end,3);
Myw(10,4)=minfo1_e5(end,3);
Mzw(10,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=4
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(11,4)=-minfo1_e1(end,3);
C(11,4)=-minfo1_e2(end,3);
L(11,4)=-minfo1_e3(end,3);
Mxw(11,4)=minfo1_e4(end,3);
Myw(11,4)=minfo1_e5(end,3);
Mzw(11,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=5
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(12,4)=-minfo1_e1(end,3);
C(12,4)=-minfo1_e2(end,3);
L(12,4)=-minfo1_e3(end,3);
Mxw(12,4)=minfo1_e4(end,3);
Myw(12,4)=minfo1_e5(end,3);
Mzw(12,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ALPHA=6
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
D(13,4)=-minfo1_e1(end,3);
C(13,4)=-minfo1_e2(end,3);
L(13,4)=-minfo1_e3(end,3);
Mxw(13,4)=minfo1_e4(end,3);
Myw(13,4)=minfo1_e5(end,3);
Mzw(13,4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..
cd ..
cd ..

% Le forze parallele agli assi vento sono quindi:
Fxw=-D;
Fyw=-C;
Fzw=-L;

% Completo le matrici per angoli di derapata negativi ed impongo nulle le
% variabili laterodirezionali per BETA=0
Fxw=[zeros(13,1) zeros(13,1) zeros(13,1) Fxw];
Fyw=[zeros(13,1) zeros(13,1) zeros(13,1) Fyw];
Fzw=[zeros(13,1) zeros(13,1) zeros(13,1) Fzw];
Mxw=[zeros(13,1) zeros(13,1) zeros(13,1) Mxw];
Myw=[zeros(13,1) zeros(13,1) zeros(13,1) Myw];
Mzw=[zeros(13,1) zeros(13,1) zeros(13,1) Mzw];
D=[zeros(13,1) zeros(13,1) zeros(13,1) D];
C=[zeros(13,1) zeros(13,1) zeros(13,1) C];
L=[zeros(13,1) zeros(13,1) zeros(13,1) L];

for i=1:3
Fxw(:,i)=Fxw(:,8-i);
Fyw(:,i)=-Fyw(:,8-i);
Fzw(:,i)=Fzw(:,8-i);
Mxw(:,i)=-Mxw(:,8-i);
Myw(:,i)=Myw(:,8-i);
Mzw(:,i)=-Mzw(:,8-i);
D(:,i)=D(:,8-i);
C(:,i)=-C(:,8-i);
L(:,i)=L(:,8-i);
end

C(:,4)=0; Fyw(:,4)=0; Mxw(:,4)=0; Mzw(:,4)=0;

% Creo le tabelle di coefficienti di forza in assi vento
%Coefficiente di Resistenza
CD=zeros(14,8);
CD(:,1)=[0 alpha]';
CD(1,:)=[0 beta];
CD(2:end,2:end)=D./A;
%CY= inverso del coefficiente di devianza
CY=zeros(14,8);
CY(:,1)=[0 alpha]';
CY(1,:)=[0 beta];
CY(2:end,2:end)=Fyw./A;
%Coefficiente di Portanza
CL=zeros(14,8);
CL(:,1)=[0 alpha]';
CL(1,:)=[0 beta];
CL(2:end,2:end)=L./A;
%Coefficiente di forza lungo l'asse x wind
CFxw=zeros(14,8);
CFxw(:,1)=[0 alpha]';
CFxw(1,:)=[0 beta];
CFxw(2:end,2:end)=Fxw./A;
%Coefficiente di forza lungo l'asse y wind
CFyw=zeros(14,8);
CFyw(:,1)=[0 alpha]';
CFyw(1,:)=[0 beta];
CFyw(2:end,2:end)=Fyw./A;
%Coefficiente di forza lungo l'asse z wind
CFzw=zeros(14,8);
CFzw(:,1)=[0 alpha]';
CFzw(1,:)=[0 beta];
CFzw(2:end,2:end)=Fzw./A;
%Coefficiente di momento lungo l'asse x wind
CMxw=zeros(14,8);
CMxw(:,1)=[0 alpha]';
CMxw(1,:)=[0 beta];
CMxw(2:end,2:end)=Mxw./B;
%Coefficiente di momento lungo l'asse y wind
CMyw=zeros(14,8);
CMyw(:,1)=[0 alpha]';
CMyw(1,:)=[0 beta];
CMyw(2:end,2:end)=Myw./K;
%Coefficiente di momento lungo l'asse z wind
CMzw=zeros(14,8);
CMzw(:,1)=[0 alpha]';
CMzw(1,:)=[0 beta];
CMzw(2:end,2:end)=Mzw./B;

%% Spostamento dei momenti nel baricentro e creazione tabelle in assi body
OGb=[XG YG ZG]';

LBW=@(x,y)[cosd(x)*cosd(y) -cosd(x)*sind(y) -sind(x);
    sind(y) cosd(y) 0;
    sind(x)*cosd(y) -sind(x)*sind(y) cosd(x)];

for i=1:13
    for j=1:7
        Rw{i,j}=[Fxw(i,j) Fyw(i,j) Fzw(i,j)]';
        Mow{i,j}=[Mxw(i,j) Myw(i,j) Mzw(i,j)]';
        Mob{i,j}=LBW(-7+i,(j-1)*4-12)*Mow{i,j};
        Rb{i,j}=LBW(-7+i,(j-1)*4-12)*Rw{i,j};
        Mg{i,j}=Mob{i,j}+cross(Rb{i,j},OGb);
        Mxb(i,j)=Mg{i,j}(1);
        Myb(i,j)=Mg{i,j}(2);
        Mzb(i,j)=Mg{i,j}(3);
        Fxb(i,j)=Rb{i,j}(1);
        Fyb(i,j)=Rb{i,j}(2);
        Fzb(i,j)=Rb{i,j}(3);
    end
end

% Creo le tabelle dei momenti in assi corpo
%coeff di momento di rollio
Cl=zeros(14,8);
Cl(:,1)=[0 alpha]';
Cl(1,:)=[0 beta];
Cl(2:end,2:end)=Mxb./B;
%coeff di momento di beccheggio
Cm=zeros(14,8);
Cm(:,1)=[0 alpha]';
Cm(1,:)=[0 beta];
Cm(2:end,2:end)=Myb./K;
%coeff di momento di imbardata
Cn=zeros(14,8);
Cn(:,1)=[0 alpha]';
Cn(1,:)=[0 beta];
Cn(2:end,2:end)=Mzb./B;
%coeff di forza lungo l'asse x body
CFxb=zeros(14,8);
CFxb(:,1)=[0 alpha]';
CFxb(1,:)=[0 beta];
CFxb(2:end,2:end)=Fxb./A;
%coeff di forza lungo l'asse y body
CFyb=zeros(14,8);
CFyb(:,1)=[0 alpha]';
CFyb(1,:)=[0 beta];
CFyb(2:end,2:end)=Fyb./A;
%coeff di forza lungo l'asse z body
CFzb=zeros(14,8);
CFzb(:,1)=[0 alpha]';
CFzb(1,:)=[0 beta];
CFzb(2:end,2:end)=Fzb./A;
%coeff di momento lungo l'asse x body (identico alla variabile Cl)
CMxb=zeros(14,8);
CMxb(:,1)=[0 alpha]';
CMxb(1,:)=[0 beta];
CMxb(2:end,2:end)=Mxb./B;
%coeff di momento lungo l'asse y body (identico alla variabile Cm)
CMyb=zeros(14,8);
CMyb(:,1)=[0 alpha]';
CMyb(1,:)=[0 beta];
CMyb(2:end,2:end)=Myb./K;
%coeff di momento lungo l'asse z body (identico alla variabile Cn)
CMzb=zeros(14,8);
CMzb(:,1)=[0 alpha]';
CMzb(1,:)=[0 beta];
CMzb(2:end,2:end)=Mzb./B;

%% Calcolo delle derivate di stabilita' aerodinamiche di forza e momento
%interpolazione lineare delle grandezze per alpha=0 (caso delle variabili
%longitudinali) e beta=0 (caso delle variabili laterodirezionali)
KCL=polyfit(alpha,CL(2:end,5)',1);
KCY=polyfit(beta,CY(8,2:end),1);
KCm=polyfit(alpha,Cm(2:end,5)',1);
KCl=polyfit(beta,Cl(8,2:end),1);
KCn=polyfit(beta,Cn(8,2:end),1);

alpha_portanza_nulla=-KCL(2)/KCL(1);

Cm0=KCm(1)*alpha_portanza_nulla+KCm(2);
CLa=KCL(1)*180/pi;
Cyb=KCY(1)*180/pi;
Cma=KCm(1)*180/pi;
Clb=KCl(1)*180/pi;
Cnb=KCn(1)*180/pi;

%% Calcolo delle derivate di controllo dell'equilibratore

dE=0:2:6;

% Importo risultati
cd EQUILIBRATORE

cd dE=0
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
FxdE(1)=minfo1_e1(end,3);
FydE(1)=minfo1_e2(end,3);
FzdE(1)=minfo1_e3(end,3);
MxdE(1)=minfo1_e4(end,3);
MydE(1)=minfo1_e5(end,3);
MzdE(1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd dE=2
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
FxdE(2)=minfo1_e1(end,3);
FydE(2)=minfo1_e2(end,3);
FzdE(2)=minfo1_e3(end,3);
MxdE(2)=minfo1_e4(end,3);
MydE(2)=minfo1_e5(end,3);
MzdE(2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd dE=4
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
FxdE(3)=minfo1_e1(end,3);
FydE(3)=minfo1_e2(end,3);
FzdE(3)=minfo1_e3(end,3);
MxdE(3)=minfo1_e4(end,3);
MydE(3)=minfo1_e5(end,3);
MzdE(3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd dE=6
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
FxdE(4)=minfo1_e1(end,3);
FydE(4)=minfo1_e2(end,3);
FzdE(4)=minfo1_e3(end,3);
MxdE(4)=minfo1_e4(end,3);
MydE(4)=minfo1_e5(end,3);
MzdE(4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..
cd ..

%sposto i momenti e nel baricentro

for i=1:4
        RwdE{i}=[FxdE(i) 0 FzdE(i)]';
        MowdE{i}=[0 MydE(i) 0]';
        MobdE{i}=MowdE{i};
        RbdE{i}=RwdE{i};
        MgdE{i}=MobdE{i}+cross(RbdE{i},OGb);
        MxbdE(i)=MgdE{i}(1);
        MybdE(i)=MgdE{i}(2);
        MzbdE(i)=MgdE{i}(3);
        FxbdE(i)=RbdE{i}(1);
        FybdE(i)=RbdE{i}(2);
        FzbdE(i)=RbdE{i}(3);
end

CMybdE=MybdE./K;
CFzwdE=FzdE./A;

KCmdE=polyfit(dE,CMybdE,1);
KCLdE=polyfit(dE,-CFzwdE,1);

CmdE=KCmdE(1)*180/pi;
CLdE=KCLdE(1)*180/pi;

%% Calcolo delle derivate di controllo del timone

dR=2:2:6;

% Importo i risultati
cd TIMONE

cd dR=2
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
FxdR(1)=minfo1_e1(end,3);
FydR(1)=minfo1_e2(end,3);
FzdR(1)=minfo1_e3(end,3);
MxdR(1)=minfo1_e4(end,3);
MydR(1)=minfo1_e5(end,3);
MzdR(1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd dR=4
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
FxdR(2)=minfo1_e1(end,3);
FydR(2)=minfo1_e2(end,3);
FzdR(2)=minfo1_e3(end,3);
MxdR(2)=minfo1_e4(end,3);
MydR(2)=minfo1_e5(end,3);
MzdR(2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd dR=6
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
FxdR(3)=minfo1_e1(end,3);
FydR(3)=minfo1_e2(end,3);
FzdR(3)=minfo1_e3(end,3);
MxdR(3)=minfo1_e4(end,3);
MydR(3)=minfo1_e5(end,3);
MzdR(3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd ..

% sposto nel baricentro le forze e i momenti di controllo
for i=1:3
        RwdR{i}=[FxdR(i) FydR(i) FzdR(i)]';
        MowdR{i}=[MxdR(i) MydR(i) MzdR(i)]';
        MobdR{i}=MowdR{i};
        RbdR{i}=RwdR{i};
        MgdR{i}=MobdR{i}+cross(RbdR{i},OGb);
        MxbdR(i)=MgdR{i}(1);
        MybdR(i)=MgdR{i}(2);
        MzbdR(i)=MgdR{i}(3);
        FxbdR(i)=RbdR{i}(1);
        FybdR(i)=RbdR{i}(2);
        FzbdR(i)=RbdR{i}(3);
end


CMxbdR=MxbdR./(1/2*rho*v^2*S*b);
CMzbdR=MzbdR./(1/2*rho*v^2*S*b);

KCldR=polyfit(dR,CMxbdR,1);
KCndR=polyfit(dR,CMzbdR,1);

CldR=KCldR(1)*180/pi;
CndR=KCndR(1)*180/pi;

%% Calcolo delle derivate di controllo degli alettoni

dA=2:2:8;

%Importo i risultati ottenuti
cd ALETTONI

cd dA=2
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
FxdA(1)=minfo1_e1(end,3);
FydA(1)=minfo1_e2(end,3);
FzdA(1)=minfo1_e3(end,3);
MxdA(1)=minfo1_e4(end,3);
MydA(1)=minfo1_e5(end,3);
MzdA(1)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd dA=4
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
FxdA(2)=minfo1_e1(end,3);
FydA(2)=minfo1_e2(end,3);
FzdA(2)=minfo1_e3(end,3);
MxdA(2)=minfo1_e4(end,3);
MydA(2)=minfo1_e5(end,3);
MzdA(2)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd dA=6
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
FxdA(3)=minfo1_e1(end,3);
FydA(3)=minfo1_e2(end,3);
FzdA(3)=minfo1_e3(end,3);
MxdA(3)=minfo1_e4(end,3);
MydA(3)=minfo1_e5(end,3);
MzdA(3)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..

cd dA=8
load minfo1_e1.csv
load minfo1_e2.csv
load minfo1_e3.csv
load minfo1_e4.csv
load minfo1_e5.csv
load minfo1_e6.csv
FxdA(4)=minfo1_e1(end,3);
FydA(4)=minfo1_e2(end,3);
FzdA(4)=minfo1_e3(end,3);
MxdA(4)=minfo1_e4(end,3);
MydA(4)=minfo1_e5(end,3);
MzdA(4)=minfo1_e6(end,3);
clear minfo1_e1
clear minfo1_e2
clear minfo1_e3
clear minfo1_e4
clear minfo1_e5
clear minfo1_e6
cd ..
cd ..

% Sposto nel baricentro forze e momenti di controllo
for i=1:4
        RwdA{i}=[FxdA(i) FydA(i) FzdA(i)]';
        MowdA{i}=[MxdA(i) MydA(i) MzdA(i)]';
        MobdA{i}=MowdA{i};
        RbdA{i}=RwdA{i};
        MgdA{i}=MobdA{i}+cross(RbdA{i},OGb);
        MxbdA(i)=MgdA{i}(1);
        MybdA(i)=MgdA{i}(2);
        MzbdA(i)=MgdA{i}(3);
        FxbdA(i)=RbdA{i}(1);
        FybdA(i)=RbdA{i}(2);
        FzbdA(i)=RbdA{i}(3);
end

CMxbdA=MxbdA./B;
CMzbdA=MzbdA./B;

KCldA=polyfit(dA,CMxbdA,1);
KCndA=polyfit(dA,CMzbdA,1);


CldA=KCldA(1)*180/pi;
CndA=KCndA(1)*180/pi;
