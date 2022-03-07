%%Lancio del calcolo del trim
%load('datiAerodinamiciAENEA.mat')
v2021_10_27_calcoloAerodinamica
%a_20210506_calcoloAerodinamica
V_cruise = input('inserire un valore desiderato per V_cruise [m/s]: ');

h0=input('inserire la quota desiderata [m]: ');   %calcolo della densità a partire da una quota impostata dall'utente
sim('v2021_10_27_Density_height_SITL.slx');

[X0,U0,Y0,iX,iU,iY,dX0,idX,omega0_eng,State0]=calcoloDatiIniziali(m,S,rho,V_cruise,CL0,CL_alpharad,Cm0,Cm_alpharad,CmdE,h0); %h0 va fornita positiva, verrà passata in assi down dalla funzione

%OPZIONI della funzione di calcolo del trim

TrimParam.Options(1)=1; %mostrare degli output
TrimParam.Options(2)=1e-7; %tolleranza sugli stati
TrimParam.Options(3)=1e-7; %tolleranza in F
TrimParam.Options(4)=1e-7;
TrimParam.Options(14)=8000; %numero massimo iterazioni

[X,U,Y,dX]=trim('modello_calcolo_trim_1',X0,U0,Y0,iX,iU,iY,dX0,idX,TrimParam.Options)
%[X,U,Y,dX]=trim('a_20210506_modello_calcolo_trim_1',X0,U0,Y0,iX,iU,iY,dX0,idX,TrimParam.Options)
U0=U;
State0.Pos0=X(10:12);
State0.Vb0=X(1:3);
State0.PHI0=X(4:6);
State0.Omega0=X(7:9);
State0.Ail0=U0(2)/12.54;
State0.Rud0=U0(3)/12.54;
State0.Ele0=U0(1)/12.54;
dX0=dX;
clear X U Y dX Y0 iU iX iY idX TrimParam
