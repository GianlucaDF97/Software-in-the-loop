function [X0,U0,Y0,iX,iU,iY,dX0,idX,omega0_eng,State0]=calcoloDatiIniziali(m,S,rho,V_cruise,CL0,CL_alpharad,Cm0,Cm_alpharad,CmdE,h0) 
%Dati iniziali per calcolo trim%
%STATI DA ASSEGNARE 
%sono gli stati che possono variare e che la funzione trim assegna:
%posizione e angolo di rotta
%iX=[9, 10, 11, 12]';
iX=[6, 10, 11, 12]'; %facendo questa assunzione si stabilisce che può mantenere un angolo di rollio diverso da zero per mantenere una derapata nulla


%STATO
X0=zeros(12,1);
%Le componenti del vettore stato sono
%X=[ub, vb, wb, Phi, Theta, Psi, p, q, r, Xe, Ye, Ze]
  

CLtrim=2*m*9.81/(S*rho*V_cruise^2);
alpha_trim =(CLtrim-CL0)/CL_alpharad; 
deltaEtrim=(Cm0*CL_alpharad+Cm_alpharad*CLtrim)/(CL_alpharad*CmdE); %angolo equilibratore al trim 
manetta=0.38;

%Posizione e velocità in m
X0(10:12) = [0 0 -h0];
State0.Pos0=[0 0 -h0]; %Il punto tra due variabili crea un campo chiamato con il secondo nome all'interno di una struttura chiamata con il primo

% alpha_trim = 0;
% Angoli di eulero ( radianti)
phi0=0;
theta0=alpha_trim; %volo orizzontale 
psi0=0;
X0(4:6) = [phi0 theta0 psi0 ];
State0.PHI0=[phi0 theta0 psi0 ];


%Velocità  assi corpo in m/s
u0=V_cruise*cos(theta0);
v0=0;
w0=V_cruise*sin(theta0);
X0(1:3) = [u0 v0 w0];
State0.Vb0=[u0 v0 w0];

% Velocità angolari  
p0 = 0 ;
q0 = 0 ;
r0 = 0 ;
X0(7:9) = [p0 q0 r0] ;
State0.Omega0=[p0 q0 r0] ;

%DERIVATE DELLO STATO
%indici: sono gli indici delle derivate che vengono assegnate nelle
%iterazioni e sono lasciate libere solo le derivate della posizione

idX=[1,2,3,4,5,6,7,8,9]';

%CONDIZIONE INIZIALE PER LE DERIVATE DEGLI STATI
%viene data la derivata di Xe dunque Vxe
dX0=zeros(12,1);
dX0(10)=V_cruise;

%QUALI CONTROLLI ASSEGNARE
%nessun controllo viene assegnato quindi vengono tutti calcolati
%vettore_controlli=[deltaE, deltaA, deltaR, deltaT]
iU=[];

%CONDIZIONE INIZIALE PER I CONTROLLI
%vengono inseriti valori ragionevolmente vicini al trim
U0=zeros(4,1);
U0(1)=deltaEtrim;
U0(2)=0;
U0(3)=0;
U0(4)=manetta;

%CONDIZIONE INIZIALE PER LE USCITE
%Le comonenti del vettore stato sono
%Y=[alpha, beta, abs(V), gamma, Cm, CL]
Y0=zeros(4,1);
Y0(1)=theta0;
Y0(2)=0;
Y0(3)=V_cruise;
Y0(4)=0;
Y0(5)=0;
Y0(6)=CLtrim;

%USCITE DA ASSEGNARE
%vengono assegnate a priori 3 uscite mentre alpha verrà calcolato
iY=[2,3,4]';



%Velocità dirotazione iniziale del motore
omega0_eng=0;
end