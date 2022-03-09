%calcolo derivate di stabilita'  clq cmq clp cnp clr cnr
clc
clear all
close all

S= 2.62*0.32;
St= S/3.11;
lt_bar=1.291;
cg=0.06;
c=0.32;
h=cg/c;
h_nw=0.25;
h_nwb=0.285;
ct=0.3; %corda coda
cf=113e-3; %corda timone
lt= lt_bar-(h-h_nwb)*c; %distanza tra centro aerodinamico piano di coda e c.g;
bt=St/ct;
Vh=St/S*(lt/c);
Xw= -c*(h-h_nw);        %distanza c.g-c.a "positive rearward" pag.47 roskam >> da verificare il segno
b=2.62;
bv=464.78 * 10^-3; %apertura alare piano verticale
Sv=S/7.81;  %superficie piano verticale
AR= b/c;
AR_t=bt/ct;
AR_v=bv^2/Sv;
cv=mean([54.75+113,174.06+113])*10^-3; %corda media impennaggio verticale compreso timone
freccia_coda=pi/2-acos(100/(bv*10^3)); %angolo freccia impennaggio verticale
K=0.82;                    %pag.51 roskam, funzione di AR
k_piccolo= 5.5/2/pi;       %rapporto tra clalpha PROFILO alare e 2pi. il nostro clalpha è 5.5, calcolato con script clwing.m
cL_alphaw= 2*pi*AR/(2+sqrt((AR^2)/(k_piccolo^2)+4)); %pag.29 del roskam
betaclpk_piccolo= -0.56;    %pag.81 del roskam
k_piccolo_tail=6.36/(2*pi); %rapporto tra clalpha PROFILO alare tail e 2pi. il nostro clalpha tail è 6.36, calcolato con script cltail.m
k_piccolo_v=k_piccolo_tail; %perché è lo stesso NACA 0010
cL_alphat = 2*pi*AR_t/(2+sqrt((AR_t^2)/(k_piccolo_tail^2)+4));
cL_alphav = 2*pi*AR_v/(2+sqrt((AR_v^2)*(1+(tan(freccia_coda))^2)/(k_piccolo_v^2)+4));
eta_t=0.95; %pag.29 roskam
betaclpk_piccolo_tail=-0.27; %pag.75 roskam
Clp_tail=betaclpk_piccolo_tail * k_piccolo_tail * 0.5 * (St/S) * (bt/b)^2; %pag.75 roskam
Zv=0.47;     %coordinata z del c.a.del piano verticale pag.72; va trovata la mean aerodynamic chord e al 25% di essa ho il centro aerodinamico di tutta l'ala
Zw= 0.234;     %distanza verticale from the wing root quarter chord to the fuselage centerline
d= 0.24;      %diametro fusoliera;
lv= 1.379;       %distanza del c.a del vertical tail dal c.g pag.72
uno_desigmadebeta=0.724+3.06*(Sv/S)+0.4*(Zw/d)+0.009*AR; %pag.55
clp_w=betaclpk_piccolo*k_piccolo;
cy_betav=-cL_alphaw*uno_desigmadebeta*(Sv/S); %ipotizzando coefficiente k=1, pag.54
alpha=(1/180)*pi;          %angolo di attacco ala. messo 1 gradi come riferimento per il trim
x= (h_nw-h);               %distanza c.g-c.a dell'ala adimensionale pag.90, sarebbe xbar/cbar sul roskam
Cnr_Clquadro=-0.02; %pag.90
rho=100000/(300*287.05);
v=15; %velocita volo, per il trim
W= 11.5*9.81;
cl=2*W/(rho*S*v^2);
cnr_cd0=-0.3 ; %pag.91
cd0=0.0256;
cnp_cl=-1/6 * AR/(AR+4); %pag. 77 roskam
clr_cl=0.28; %pag.87 roskam





Clq=(0.5+(2*Xw)/c)*cL_alphaw+2*cL_alphat*eta_t*Vh
Cmq= -K*cL_alphaw*((AR*(2*(Xw/c)^2+0.5*(Xw/c))/(AR+2))+1/8)-2*cL_alphat*Vh*(lt/c)*eta_t
Clp=clp_w+2*(Zv/b)^2*cy_betav+Clp_tail
Cnp=-clp_w*tan(alpha)+Clp*tan(alpha)-(2/b)*(lv*cos(alpha)+Zv*sin(alpha))*((Zv*cos(alpha)-lv*sin(alpha))/b)*cy_betav + cnp_cl * cl
Clr=cl*clr_cl-(2/b^2)*(lv*cos(alpha)+Zv*sin(alpha))*(Zv*cos(alpha)-lv*sin(alpha))*cy_betav
Cnr=(Cnr_Clquadro)*cl^2+(cnr_cd0)*cd0+(2/b^2)*(lv*cos(alpha)+Zv*sin(alpha))^2*cy_betav


%control derivatives
%alphadeltaCL_alphadeltacl=1.06; %pag.96 roskam
%alphadeltacl=-0.8; %pag.96
%K_primo=0.68; %pag.99
%K_b=1; %pag.97 il timone sta lungo tutta la coda
%cy_deltar= cL_alphav*alphadeltaCL_alphadeltacl*alphadeltacl*K_primo*K_b*Sv/S;
%Cl_deltar=cy_deltar*(Zv*cos(alpha)-lv*sin(alpha))/b








