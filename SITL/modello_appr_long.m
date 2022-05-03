% run('v2021_10_27_avvioSITL.m')

rho=1.164;
AR=b^2/S;
Cle=(2*m*9.81/S)/(rho*V_cruise^2);
Cda=2*(1/(pi*AR*0.8))*Cle*CL_alpharad;
Cmu=0;
Clu=0;
Cdu=0;
Cde=CD0+Cle^2/(pi*AR*0.8);

%Derivate di stabilità

X_u=(0.5*rho*V_cruise*S*(-3*Cde))/m;
Z_u=-(0.5*rho*V_cruise*S*(Clu+2*Cle))/m;
M_u=(0.5*rho*V_cruise*S*cbar*Cmu)/Iy;
X_w=(0.5*rho*S*V_cruise*(Cle-Cda))/m;
Z_w=-(0.5*rho*S*V_cruise*(CL_alpharad+Cde))/m;
Z_alfa=Z_w*V_cruise;
M_w=(0.5*rho*V_cruise*S*cbar*Cm_alpharad)/Iy;
M_alfa=M_w*V_cruise;
M_q=(0.25*rho*V_cruise*S*cbar^2*Cmq)/Iy;

Alon_ddv=[X_u,X_w,0,-9.81;Z_u,Z_w,V_cruise,0;M_u,M_w,M_q,0;0,0,1,0]

%Calcolo 2°modello approssimato del FUGOIDE

omega_ph=sqrt(9.81*(Z_w*M_u-M_w*Z_u)/(M_w*V_cruise-M_q*Z_w));
zeta_ph=(-1/(2*omega_ph))*(X_u+X_w*((M_q*Z_u-M_u*V_cruise)/(M_w*V_cruise-M_q*Z_w)));

%Calcolo modello approssimato CORTO PERIODO

omega_sp_1=sqrt(-M_alfa+Z_w*M_q);
zeta_sp_1=-(1/(2*omega_sp_1))*(M_q+Z_w);

n_appr_sp=-zeta_sp_1*omega_sp_1;
o_appr_sp=omega_sp_1*sqrt(1-zeta_sp_1^2);

%Come dovrebbero venire gli autovalori secondo il modello approssimato
n_appr_ph=-zeta_ph*omega_ph;
o_appr_ph=omega_ph*sqrt(1-zeta_ph^2);
E=Cle/Cde;

